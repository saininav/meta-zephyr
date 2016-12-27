import unittest
from oeqa.oetest import oeRuntimeTest

class ZephyrTest(oeRuntimeTest):

    def test_boot_tiny(self):
        success = False
        logfile = self.target.wait_for_serial(300, 30)

        with open(logfile) as f:
            for line in f:
                if "PROJECT EXECUTION SUCCESSFUL" in line:
                    success = True
                    break

        self.assertTrue(success, msg='"PROJECT EXECUTION SUCCESSFUL" not in %s' % logfile)
