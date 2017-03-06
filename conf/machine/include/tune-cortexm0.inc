DEFAULTTUNE ?= "cortexm0"

require conf/machine/include/arm/arch-armv6.inc

TUNEVALID[cortexm0] = "Enable Cortex-M0 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexm0', ' -mcpu=cortex-m0', '', d)}"
AVAILTUNES += "cortexm0"

TUNEVALID[no-thumb-interwork] = "Enable thumb mode"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'no-thumb-interwork', ' -mno-thumb-interwork', '', d)}"
AVAILTUNES += "no-thumb-interwork"

TUNEVALID[no-ffast-math] = "Enable thumb mode"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'no-ffast-math', ' -fno-fast-math', '', d)}"
AVAILTUNES += "no-ffast-math"

TUNEVALID[soft] = "Enable thumb mode"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'soft', ' -mfloat-abi=soft', '', d)}"
AVAILTUNES += "soft"

TUNEVALID[armv6m] = "Enable Cortex-M0 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'armv6m', ' -march=armv6-m', '', d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'armv6m', 'armv6m:', '' ,d)}"

ARMPKGARCH_tune-cortexm0 = "cortexm0"
TUNE_FEATURES_tune-cortexm0 = "${TUNE_FEATURES_tune-armv6} cortexm0"

PACKAGE_EXTRA_ARCHS_tune-cortexm0 = "${PACKAGE_EXTRA_ARCHS_tune-armv6m} cortexm0-vfp"

TUNE_FEATURES_tune-cortexm0 = "armv6m vfp cortexm0 thumb no-thumb-interwork soft"

