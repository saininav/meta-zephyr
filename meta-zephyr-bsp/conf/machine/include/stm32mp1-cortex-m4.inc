#@TYPE: Machine
#@NAME: stm32mp1-cortex-m4

#@DESCRIPTION: Machine configuration for Cortex-M4 core of STMicroelectronics STM32MP1 SoC.

require conf/machine/include/tune-cortexm4.inc

TUNE_FEATURES = "armv7m cortexm4"
