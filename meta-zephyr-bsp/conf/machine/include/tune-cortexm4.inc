DEFAULTTUNE ?= "cortexm4"

require conf/machine/include/arm/arch-armv7a.inc

TUNEVALID[cortexm4] = "Enable Cortex-M4 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexm4', ' -mcpu=cortex-m4', '', d)}"
AVAILTUNES += "cortexm4"

TUNEVALID[armv7m] = "Enable Cortex-M4 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'armv7m', ' -march=armv7e-m', '', d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'armv7m', 'armv7m:', '' ,d)}"

TUNE_PKGARCH:tune-cortexm4 = "cortexm4"

ARMPKGARCH:tune-cortexm4 = "armv7m"
PACKAGE_EXTRA_ARCHS:tune-cortexm4 ="cortexm4"

TUNE_FEATURES:tune-cortexm4 = "armv7m vfp cortexm4"
PACKAGE_EXTRA_ARCHS:tune-cortexm4 = "${PACKAGE_EXTRA_ARCHS:tune-armv7at} armv7m-vfp armv7m"
