# Copyright (C) 2016-2017 Intel Corporation
# Released under the MIT license (see COPYING.MIT)

import os
import sys
import signal
import logging

from oeqa.core.target.__init__ import OETarget
from oeqa.utils.qemuzephyrrunner import QemuZephyrRunner
supported_fstypes = ['elf']

class QemuTargetZephyr(OETarget):
    def __init__(self, logger, ip, server_ip, target_modules_path,
            timeout=300, user='root',
            port=None, machine='', rootfs='', kernel='', kvm=False,
            dump_dir='', dump_host_cmds='', display='', bootlog='',
            tmpdir='', dir_image='', boottime=60):

        super(QemuTargetZephyr, self).__init__(logger, ip, server_ip, timeout,
                user, port)

        self.ip = ip
        self.server_ip = server_ip
        self.machine = machine
        self.rootfs = rootfs
        self.qemulog = bootlog
        self.kernel = kernel
        self.kvm = kvm

        # Log QemuRunner log output to a file
        import oe.path
        from oeqa.utils.qemuzephyrrunner import QemuZephyrRunner

        self.qemurunnerlog = bootlog
        logger = logging.getLogger('BitBake.QemuRunner')
        loggerhandler = logging.FileHandler(self.qemurunnerlog)
        loggerhandler.setFormatter(logging.Formatter("%(levelname)s: %(message)s"))
        logger.addHandler(loggerhandler)

        self.runner = QemuZephyrRunner(machine=machine, rootfs=rootfs, tmpdir=tmpdir,
                                 deploy_dir_image=dir_image, display=display,
                                 logfile=self.qemulog, boottime=boottime,
                                 use_kvm=kvm, dump_dir=dump_dir,
                                 dump_host_cmds=dump_host_cmds)


    def start(self, params=None, extra_bootparams=None):
        if self.runner.start(params, extra_bootparams=extra_bootparams):
            self.ip = self.runner.ip
            self.server_ip = self.runner.server_ip
        else:
            self.stop()
            raise RuntimeError("FAILED to start qemu - check the task log and the boot log")

    def stop(self):
        self.runner.stop()

    def serial_readline(self):
        return self.runner.serial_readline()
