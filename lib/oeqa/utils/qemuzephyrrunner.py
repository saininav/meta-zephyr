# Copyright (C) 2015-2016 Intel Corporation
#
# Released under the MIT license (see COPYING.MIT)

# This module provides a class for starting qemu images of poky tiny.
# It's used by testimage.bbclass.

import subprocess
import os
import time
import signal
import socket
import select
import bb
import tempfile
from oeqa.utils.qemurunner import QemuRunner

class QemuZephyrRunner(QemuRunner):

    def __init__(self, machine, rootfs, display, tmpdir, deploy_dir_image, logfile, kernel, boottime):
        QemuRunner.__init__(self, machine, rootfs, display, tmpdir,
                            deploy_dir_image, logfile, boottime, None,
                            None, True)

        # Popen object for runqemu
        self.socketfile = tempfile.NamedTemporaryFile()
        self.runqemu = None
        self.socketname = self.socketfile.name
        self.server_socket = None
        self.kernel = kernel

    def create_socket(self):
        bb.note("waiting at most %s seconds for qemu pid" % self.runqemutime)
        tries = self.runqemutime
        while tries > 0:
            time.sleep(1)
            try:
                self.server_socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                self.server_socket.connect(self.socketname)
                bb.note("Created listening socket for qemu serial console.")
                break

            except socket.error:
                self.server_socket.close()
                tries -= 1

        if tries == 0:
            bb.error("Failed to create listening socket %s: " % (self.socketname))
            return False
        return True

    def start(self, qemuparams = None, get_ip = True, extra_bootparams = None):

        if not os.path.exists(self.tmpdir):
            bb.error("Invalid TMPDIR path %s" % self.tmpdir)
            return False
        else:
            os.environ["OE_TMPDIR"] = self.tmpdir
        if not os.path.exists(self.deploy_dir_image):
            bb.error("Invalid DEPLOY_DIR_IMAGE path %s" % self.deploy_dir_image)
            return False
        else:
            os.environ["DEPLOY_DIR_IMAGE"] = self.deploy_dir_image

        if not os.path.exists(self.kernel):
            bb.error("Invalid kernel path: %s" % self.deploy_dir_image)
            return False

        self.qemuparams = '-nographic -serial unix:%s,server' % (self.socketname)
        qemu_binary = ""
        if 'arm' in self.machine or 'cortex' in self.machine:
            qemu_binary = 'qemu-system-arm'
            qemu_machine_args = '-machine lm3s6965evb'
        elif 'x86' in self.machine:
            qemu_binary = 'qemu-system-i386'
            qemu_machine_args = '-machine type=pc-0.14'

        self.origchldhandler = signal.getsignal(signal.SIGCHLD)
        signal.signal(signal.SIGCHLD, self.handleSIGCHLD)

        launch_cmd = '%s -kernel %s %s %s' % (qemu_binary, self.kernel, self.qemuparams, qemu_machine_args)
        bb.note(launch_cmd)
        self.runqemu = subprocess.Popen(launch_cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,preexec_fn=os.setpgrp)

        #
        # We need the preexec_fn above so that all runqemu processes can easily be killed
        # (by killing their process group). This presents a problem if this controlling
        # process itself is killed however since those processes don't notice the death
        # of the parent and merrily continue on.
        #
        # Rather than hack runqemu to deal with this, we add something here instead.
        # Basically we fork off another process which holds an open pipe to the parent
        # and also is setpgrp. If/when the pipe sees EOF from the parent dieing, it kills
        # the process group. This is like pctrl's PDEATHSIG but for a process group
        # rather than a single process.
        #
        r, w = os.pipe()
        self.monitorpid = os.fork()
        if self.monitorpid:
            os.close(r)
            self.monitorpipe = os.fdopen(w, "w")
        else:
            # child process
            os.setpgrp()
            os.close(w)
            r = os.fdopen(r)
            x = r.read()
            os.killpg(os.getpgid(self.runqemu.pid), signal.SIGTERM)
            sys.exit(0)

        bb.note("qemu started, pid is %s" % self.runqemu.pid)
        return self.create_socket()

    def wait_for_serial(self, func_timeout, data_timeout):
        stopread = False
        check_endtime = False
        self.server_socket.setblocking(0)
        endtime = time.time() + func_timeout

        while time.time() < endtime:
            sread, _, _ = select.select([self.server_socket],[],[],data_timeout)
            if not sread:
                break
            answer = self.server_socket.recv(1024)
            if answer:
                self.log(answer)
            else:
                break

        return self.logfile
