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

def arc_siteinfo_setfunc(archinfo, osinfo, targetinfo, d):
	archinfo['arc'] = "endian-little bit-32 "
	osinfo['linux'] = "common-linux common-glibc"
	targetinfo['arc-linux'] = "arc-linux"
	return archinfo, osinfo, targetinfo

SITEINFO_EXTRA_DATAFUNCS = "arc_siteinfo_setfunc"

def arc_machdata_setfunc(machdata, d):
    machdata["elf"] = { "arc" : (195,    0,    0,  True,  32), }
    return machdata

PACKAGEQA_EXTRA_MACHDEFFUNCS = "arc_machdata_setfunc"
