DEFAULTTUNE ?= "core2-32"
require conf/machine/include/tune-core2.inc
require conf/machine/include/x86-base.inc

# Add x86 to MACHINEOVERRIDES
MACHINEOVERRIDES =. "x86:"
