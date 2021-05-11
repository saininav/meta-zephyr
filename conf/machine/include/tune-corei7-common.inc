DEFAULTTUNE ?= "corei7-64"
require conf/machine/include/tune-corei7.inc
require conf/machine/include/x86-base.inc

# Add x86 to MACHINEOVERRIDE
MACHINEOVERRIDES =. "x86:"
