#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "2.4.0"

SRCREV_FORMAT = "default_cmsis"
SRCREV_default = "7a3b253ced7333f5c0269387a7f3ed1dee69739d"
SRCREV_cmsis = "542b2296e6d515b265e25c6b7208e8fea3014f90"
SRCREV_nordic = "d8a6ea9695ddf792bb18bb6035c13b1daac5d79c"
SRCREV_stm32 = "f0e11398128ac9abdff713da5d3035e6c96e9b86"
SRCREV_open-amp = "de1b85a13032a2de1d8b6695ae5f800b613e739d"
SRCREV_libmetal = "9d4ee2c3cfd5f49861939447990f3b7d7bf9bf94"

SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v2.4-branch;name=default \
           git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;destsuffix=git/modules/cmsis;name=cmsis \
           git://github.com/zephyrproject-rtos/hal_nordic.git;protocol=https;destsuffix=git/modules/hal/nordic;name=nordic \
           git://github.com/zephyrproject-rtos/hal_stm32.git;protocol=https;destsuffix=git/modules/hal/stm32;name=stm32 \
           git://github.com/zephyrproject-rtos/open-amp.git;protocol=https;destsuffix=git/modules/lib/open-amp;name=open-amp \
           git://github.com/zephyrproject-rtos/libmetal.git;protocol=https;destsuffix=git/modules/hal/libmetal;name=libmetal \
           file://0001-cmake-add-yocto-toolchain.patch \
          "

PV = "2.4.0+git${SRCPV}"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

ZEPHYR_TEST_SRCDIR = "tests/legacy/kernel/"

python () {
    src_pn = d.getVar('PREFERRED_VERSION_zephyr-kernel', True)
    if src_pn == '2.4.0':
        return
    else:
        bb.error("Unsupported Zephyr kernel version requested")
}
