LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://zephyr/LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

CVE_PRODUCT = "zephyr"

inherit cmake

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI = "\
    git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=${ZEPHYR_BRANCH};name=default;destsuffix=git/zephyr \
    git://github.com/zephyrproject-rtos/canopennode.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/canopennode;name=canopennode \
    git://github.com/zephyrproject-rtos/civetweb.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/civetweb;name=civetweb \
    git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/cmsis;name=cmsis \
    git://github.com/zephyrproject-rtos/edtt.git;protocol=https;nobranch=1;destsuffix=git/tools/edtt;name=edtt \
    git://github.com/zephyrproject-rtos/fatfs.git;protocol=https;nobranch=1;destsuffix=git/modules/fs/fatfs;name=fatfs \
    git://github.com/zephyrproject-rtos/hal_altera.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/altera;name=altera \
    git://github.com/zephyrproject-rtos/hal_atmel.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/atmel;name=atmel \
    git://github.com/zephyrproject-rtos/hal_espressif.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/espressif;name=espressif \
    git://github.com/zephyrproject-rtos/hal_infineon.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/infineon;name=infineon \
    git://github.com/zephyrproject-rtos/hal_microchip.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/microchip;name=microchip \
    git://github.com/zephyrproject-rtos/hal_nordic.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/nordic;name=nordic \
    git://github.com/zephyrproject-rtos/hal_nuvoton.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/nuvoton;name=nuvoton \
    git://github.com/zephyrproject-rtos/hal_nxp.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/nxp;name=nxp \
    git://github.com/zephyrproject-rtos/hal_openisa.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/openisa;name=openisa \
    git://github.com/zephyrproject-rtos/hal_quicklogic.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/quicklogic;name=quicklogic \
    git://github.com/zephyrproject-rtos/hal_silabs.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/silabs;name=silabs \
    git://github.com/zephyrproject-rtos/hal_st.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/st;name=st \
    git://github.com/zephyrproject-rtos/hal_stm32.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/stm32;name=stm32 \
    git://github.com/zephyrproject-rtos/hal_ti.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/ti;name=ti \
    git://github.com/zephyrproject-rtos/hal_xtensa.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/xtensa;name=xtensa \
    git://github.com/zephyrproject-rtos/libmetal.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/libmetal;name=libmetal \
    git://github.com/zephyrproject-rtos/littlefs.git;protocol=https;nobranch=1;destsuffix=git/modules/fs/littlefs;name=littlefs \
    git://github.com/zephyrproject-rtos/loramac-node.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/loramac-node;name=loramac-node \
    git://github.com/zephyrproject-rtos/lvgl.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/gui/lvgl;name=lvgl \
    git://github.com/zephyrproject-rtos/mbedtls.git;protocol=https;nobranch=1;destsuffix=git/modules/crypto/mbedtls;name=mbedtls \
    git://github.com/zephyrproject-rtos/mcuboot.git;protocol=https;nobranch=1;destsuffix=git/bootloader/mcuboot;name=mcuboot \
    git://github.com/zephyrproject-rtos/mipi-sys-t.git;protocol=https;nobranch=1;destsuffix=git/modules/debug/mipi-sys-t;name=mipi-sys-t \
    git://github.com/zephyrproject-rtos/nanopb.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/nanopb;name=nanopb \
    git://github.com/zephyrproject-rtos/net-tools.git;protocol=https;nobranch=1;destsuffix=git/tools/net-tools;name=net-tools \
    git://github.com/zephyrproject-rtos/nrf_hw_models.git;protocol=https;nobranch=1;destsuffix=git/modules/bsim_hw_models/nrf_hw_models;name=nrf_hw_models \
    git://github.com/zephyrproject-rtos/open-amp.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/open-amp;name=open-amp \
    git://github.com/zephyrproject-rtos/openthread.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/openthread;name=openthread \
    git://github.com/zephyrproject-rtos/segger.git;protocol=https;nobranch=1;destsuffix=git/modules/debug/segger;name=segger \
    git://github.com/zephyrproject-rtos/sof.git;protocol=https;nobranch=1;destsuffix=git/modules/audio/sof;name=sof \
    git://github.com/zephyrproject-rtos/tinycbor.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/tinycbor;name=tinycbor \
    git://github.com/zephyrproject-rtos/tinycrypt.git;protocol=https;nobranch=1;destsuffix=git/modules/crypto/tinycrypt;name=tinycrypt \
    git://github.com/zephyrproject-rtos/hal_telink.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/telink;name=telink \
    git://github.com/zephyrproject-rtos/lz4.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/lz4;name=lz4 \
    git://github.com/zephyrproject-rtos/tflite-micro.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/tflite-micro;name=tflite-micro \
"
S = "${WORKDIR}/git"

# Default to a stable version
PREFERRED_VERSION_zephyr-kernel ??= "3.1.0"
include zephyr-kernel-src-${PREFERRED_VERSION_zephyr-kernel}.inc
