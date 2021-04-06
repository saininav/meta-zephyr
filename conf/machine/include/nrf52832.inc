#@TYPE: Machine
#@NAME: nrf52832

#@DESCRIPTION: Machine configuration for Nordic Semiconductor nRF52832 (Cortex-M4) SoC.

require conf/machine/include/tune-cortexm4.inc

MACHINEOVERRIDES =. "nordic:"

TUNE_FEATURES = "armv7m cortexm4"

# Target type for this machine used by Pyocd
PYOCD_TARGET = "nrf52"
