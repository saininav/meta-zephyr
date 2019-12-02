#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "1.6.0"

SRCREV = "d4e799d77a36eaf6d678b357c207411ec32b2d62"

SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v1.6-branch \
          file://Makefile.toolchain.yocto "
PV = "1.6.0"

# FIXME: This points to 1.7.rc4
SRCREV_1.7 = "3d2893cf85d51ceca04aa3bec2dd5fc77625ff81"
SRC_URI_1.7 = "git://gerrit.zephyrproject.org/r/zephyr.git;protocol=https;branch=v1.7-branch\
          file://Makefile.toolchain.yocto "
PV_1.7 = "1.7.0"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

ZEPHYR_TEST_SRCDIR = "tests/legacy/kernel/"

python () {
    src_pn = d.getVar('PREFERRED_VERSION_zephyr-kernel', True)
    if src_pn == '1.6.0':
        return
    elif src_pn == '1.7.0':
        d.setVar('SRC_URI',d.getVar('SRC_URI_1.7', True))
        d.setVar('SRCREV',d.getVar('SRCREV_1.7', True))
        d.setVar('PV',d.getVar('PV_1.7', True))
    else:
        bb.error("Unsupported Zephyr kernel version requested")
}
