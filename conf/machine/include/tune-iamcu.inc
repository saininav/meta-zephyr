DEFAULTTUNE ?= "iamcu"

TARGET_OS_iamcu = "elfiamcu"
TARGET_ARCH = "i586"

TUNE_FEATURES_tune-iamcu = "iamcu"
TUNE_CCARGS = "-miamcu -m32"
TUNE_ARCH = "i586"
TUNEVALID[iamcu] = "Intel MCU"

PACKAGE_EXTRA_ARCHS_tune-iamcu = "iamcu"

