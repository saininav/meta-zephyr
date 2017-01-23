
# Nios2 Architecture Definition

DEFAULTTUNE ?= "nios2"

TUNE_ARCH = "nios2"
TUNE_PKGARCH = "nios2"
TUNE_FEATURES_tune-nios2 = "nios2"
TUNE_CCARGS = ""

TUNEVALID[nios2] = "Altera Nios2"

def nios2_machdata_setfunc(machdata, d):
    machdata["elf"] = {"nios2":  (113, 0, 0, True, 32), }
    return machdata

PACKAGEQA_EXTRA_MACHDEFFUNCS = "nios2_machdata_setfunc"

PACKAGE_EXTRA_ARCHS_tune-nios2 = "nios2"
