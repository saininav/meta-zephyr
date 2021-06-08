LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

inherit cmake

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI = "\
    git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=main;name=default \
    git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;destsuffix=git/modules/cmsis;name=cmsis \
    git://github.com/zephyrproject-rtos/hal_nordic.git;protocol=https;destsuffix=git/modules/hal/nordic;name=nordic \
    git://github.com/zephyrproject-rtos/hal_stm32.git;protocol=https;destsuffix=git/modules/hal/stm32;name=stm32 \
    git://github.com/zephyrproject-rtos/mbedtls.git;protocol=https;destsuffix=git/modules/lib/mbedtls;name=mbedtls \
    git://github.com/zephyrproject-rtos/open-amp.git;protocol=https;destsuffix=git/modules/lib/open-amp;name=open-amp \
    git://github.com/zephyrproject-rtos/libmetal.git;protocol=https;destsuffix=git/modules/hal/libmetal;name=libmetal \
    git://github.com/zephyrproject-rtos/tinycrypt.git;protocol=https;destsuffix=git/modules/crypto/tinycrypt;name=tinycrypt \
    file://0001-cmake-add-yocto-toolchain.patch \
    "
S = "${WORKDIR}/git"

# Default to a stable version
PREFERRED_VERSION_zephyr-kernel ??= "2.6.0"
include zephyr-kernel-src-${PREFERRED_VERSION_zephyr-kernel}.inc
