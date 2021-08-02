# Nios2 Architecture Definition

DEFAULTTUNE ?= "nios2"

TUNE_ARCH = "nios2"
TUNE_PKGARCH = "nios2"
TUNE_FEATURES:tune-nios2 = "nios2"
TUNE_CCARGS = ""

TUNEVALID[nios2] = "Altera Nios2"

PACKAGE_EXTRA_ARCHS:tune-nios2 = "nios2"
