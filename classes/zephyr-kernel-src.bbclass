#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "2.4.0"

SRCREV_FORMAT = "default_cmsis"
SRCREV_default = "7a3b253ced7333f5c0269387a7f3ed1dee69739d"
SRCREV_cmsis = "542b2296e6d515b265e25c6b7208e8fea3014f90"
SRCREV_nordic = "d8a6ea9695ddf792bb18bb6035c13b1daac5d79c"

SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v2.4-branch;name=default \
           git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;destsuffix=git/modules/cmsis;name=cmsis \
           git://github.com/zephyrproject-rtos/hal_nordic.git;protocol=https;destsuffix=git/modules/hal/nordic;name=nordic \
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
