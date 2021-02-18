LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

# Default to a stable version
PREFERRED_VERSION_zephyr-kernel ??= "2.5.0"
include zephyr-kernel-src-${PREFERRED_VERSION_zephyr-kernel}.inc

inherit cmake

SRC_URI = "\
    git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=master;name=default \
    git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;destsuffix=git/modules/cmsis;name=cmsis \
    git://github.com/zephyrproject-rtos/hal_nordic.git;protocol=https;destsuffix=git/modules/hal/nordic;name=nordic \
    git://github.com/zephyrproject-rtos/hal_stm32.git;protocol=https;destsuffix=git/modules/hal/stm32;name=stm32 \
    git://github.com/zephyrproject-rtos/open-amp.git;protocol=https;destsuffix=git/modules/lib/open-amp;name=open-amp \
    git://github.com/zephyrproject-rtos/libmetal.git;protocol=https;destsuffix=git/modules/hal/libmetal;name=libmetal \
    git://github.com/zephyrproject-rtos/tinycrypt.git;protocol=https;destsuffix=git/modules/crypto/tinycrypt;name=tinycrypt \
    file://0001-cmake-add-yocto-toolchain.patch \
    "
S = "${WORKDIR}/git"
