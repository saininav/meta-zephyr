DEFAULTTUNE ?= "corei7-64"
require conf/machine/${X86_TUNE_DIR}/tune-corei7.inc
require conf/machine/${X86_TUNE_DIR}/x86-base.inc

# Add x86 to MACHINEOVERRIDE
MACHINEOVERRIDES =. "x86:"
