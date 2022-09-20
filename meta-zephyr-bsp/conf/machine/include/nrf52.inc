#@TYPE: Machine
#@NAME: nrf52xxx

#@DESCRIPTION: Machine configuration for Nordic Semiconductor nRF52xxx (Cortex-M4) SoC.

require conf/machine/include/arm/armv7m/tune-cortexm4.inc

TUNE_FEATURES = "armv7em cortexm4"

# Target type for this machine used by Pyocd
PYOCD_TARGET = "nrf52"
