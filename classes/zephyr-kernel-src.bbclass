#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "2.2.0"

SRCREV = "d39cb42d0920d5658fad358ad5b91de75d747a20"

SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v2.2-branch \
          file://0001-cmake-add-yocto-toolchain.patch \
        "
PV = "2.2.0"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

ZEPHYR_TEST_SRCDIR = "tests/legacy/kernel/"

python () {
    src_pn = d.getVar('PREFERRED_VERSION_zephyr-kernel', True)
    if src_pn == '2.2.0':
        return
    else:
        bb.error("Unsupported Zephyr kernel version requested")
}
