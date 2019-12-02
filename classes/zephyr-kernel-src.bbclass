#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "1.6.0"

SRCREV = "d4e799d77a36eaf6d678b357c207411ec32b2d62"

SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v1.6-branch \
          file://Makefile.toolchain.yocto "
PV = "1.6.0"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

ZEPHYR_TEST_SRCDIR = "tests/legacy/kernel/"

python () {
    src_pn = d.getVar('PREFERRED_VERSION_zephyr-kernel', True)
    if src_pn == '1.6.0':
        return
    else:
        bb.error("Unsupported Zephyr kernel version requested")
}
