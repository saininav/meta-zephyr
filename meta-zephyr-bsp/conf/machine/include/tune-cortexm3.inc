DEFAULTTUNE ?= "cortexm3"

require conf/machine/include/arm/arch-armv7a.inc

TUNEVALID[cortexm3] = "Enable Cortex-M3 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexm3', ' -mcpu=cortex-m3', '', d)}"
AVAILTUNES += "cortexm3"

TUNEVALID[armv7m] = "Enable Cortex-M3 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'armv7m', ' -march=armv7-m', '', d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'armv7m', 'armv7m:', '' ,d)}"

TUNE_PKGARCH:tune-cortexm3 = "cortexm3"

ARMPKGARCH:tune-cortexm3 = "armv7m"
PACKAGE_EXTRA_ARCHS:tune-cortexm3 ="cortexm3"

TUNE_FEATURES:tune-cortexm3 = "armv7m vfp cortexm3"
PACKAGE_EXTRA_ARCHS:tune-cortexm3 = "${PACKAGE_EXTRA_ARCHS:tune-armv7at} armv7m-vfp"

TUNE_CCARGS_MFLOAT = "soft"
