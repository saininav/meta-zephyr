#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "2.0.0"

SRCREV = "ca3eb0eb31d134be41aefc952f696f7d9c356b7a"

SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v2.0-branch \
          file://0001-cmake-add-yocto-toolchain.patch \
        "
PV = "2.0.0"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

ZEPHYR_TEST_SRCDIR = "tests/legacy/kernel/"

python () {
    src_pn = d.getVar('PREFERRED_VERSION_zephyr-kernel', True)
    if src_pn == '2.0.0':
        return
    else:
        bb.error("Unsupported Zephyr kernel version requested")
}
