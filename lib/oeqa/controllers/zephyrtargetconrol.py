# Copyright (C) 2013-2016 Intel Corporation
#
# Released under the MIT license (see COPYING.MIT)

# This module is used by testimage.bbclass for setting up and controlling a target machine.

import os
import shutil
import bb
import logging
from oeqa.targetcontrol import QemuTarget
from oeqa.utils.dump import TargetDumper
from oeqa.utils.qemuzephyrrunner import QemuZephyrRunner

class QemuTargetZephyr(QemuTarget):

    def __init__(self, d):

        super(QemuTarget, self).__init__(d)
        self.qemulog = os.path.join(self.testdir, "qemu_boot_log.%s" % self.datetime)
        dump_target_cmds = d.getVar("testimage_dump_target", True)
        dump_host_cmds = d.getVar("testimage_dump_host", True)
        dump_dir = d.getVar("TESTIMAGE_DUMP_DIR", True)

        self.kernel = os.path.join(d.getVar("DEPLOY_DIR_IMAGE", True), d.getVar("ZEPHYR_IMAGENAME", True))
        self.rootfs = ""

        # Log QemuRunner log output to a file
        import oe.path
        from oeqa.utils.qemuzephyrrunner import QemuZephyrRunner
        bb.utils.mkdirhier(self.testdir)
        self.qemurunnerlog = os.path.join(self.testdir, 'qemurunner_log.%s' % self.datetime)
        logger = logging.getLogger('BitBake.QemuRunner')
        loggerhandler = logging.FileHandler(self.qemurunnerlog)
        loggerhandler.setFormatter(logging.Formatter("%(levelname)s: %(message)s"))
        logger.addHandler(loggerhandler)
        oe.path.symlink(os.path.basename(self.qemurunnerlog), os.path.join(self.testdir, 'qemurunner_log'), force=True)
        self.runner = QemuZephyrRunner(machine=d.getVar("MACHINE", True),
                        rootfs=self.rootfs,
                        tmpdir = d.getVar("TMPDIR", True),
                        deploy_dir_image = d.getVar("DEPLOY_DIR_IMAGE", True),
                        display = d.getVar("BB_ORIGENV", False).getVar("DISPLAY", True),
                        logfile = self.qemulog,
                        kernel = self.kernel,
                        boottime = int(d.getVar("TEST_QEMUBOOT_TIMEOUT", True)))

        self.target_dumper = TargetDumper(dump_target_cmds, dump_dir, self.runner)

    def deploy(self):
        try:
            bb.utils.mkdirhier(self.testdir)
            if self.rootfs:
                shutil.copyfile(self.origrootfs, self.rootfs)
        except Exception as e:
            bb.fatal("Error copying rootfs: %s" % e)

        qemuloglink = os.path.join(self.testdir, "qemu_boot_log")
        if os.path.islink(qemuloglink):
            os.unlink(qemuloglink)
        os.symlink(self.qemulog, qemuloglink)

        bb.note("Qemu log file: %s" % self.qemulog)
        super(QemuTarget, self).deploy()

    def wait_for_serial(self, func_timeout, data_timeout):
        return self.runner.wait_for_serial(func_timeout, data_timeout)
