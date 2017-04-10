DEFAULTTUNE ?= "arc"

TUNE_ARCH = "arc"
TUNE_PKGARCH = "arc"
TUNE_FEATURES_tune-arc = "littleendian"
TUNE_CCARGS = ""

TUNEVALID[littleendian] = "Little endian mode"

TUNEVALID[quark-se] = "Intel Quark SE support (ARC core)"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'quark-se', ' -mcpu=quarkse_em', '', d)}"
AVAILTUNES += "quark-se"

TUNEVALID[nodata] = "ARC mo-sdata"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'no-sdata', ' -mno-sdata', '', d)}"
AVAILTUNES += "no-sdata"

TUNEVALID[nodata] = "ARC no-delete-null-pointer-checks"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'no-delete-null-pointer-checks', ' -fno-delete-null-pointer-checks', '', d)}"
AVAILTUNES += "no-delete-null-pointer-checks"

