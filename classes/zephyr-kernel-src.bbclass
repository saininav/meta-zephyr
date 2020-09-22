#Set relevant variables based on Zephyr kernel version

PREFERRED_VERSION_zephyr-kernel ??= "2.3.0"

SRCREV_FORMAT = "default_cmsis"
SRCREV_default  = "b8c78e254ff875680e99c9f131fbe285c4575927"
SRCREV_cmsis = "542b2296e6d515b265e25c6b7208e8fea3014f90"


SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v2.3-branch;name=default \
           git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;destsuffix=git/modules/cmsis;name=cmsis \
          file://0001-cmake-add-yocto-toolchain.patch \
        "

PV = "2.3.0+git${SRCPV}"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

ZEPHYR_TEST_SRCDIR = "tests/legacy/kernel/"

python () {
    src_pn = d.getVar('PREFERRED_VERSION_zephyr-kernel', True)
    if src_pn == '2.3.0':
        return
    else:
        bb.error("Unsupported Zephyr kernel version requested")
}
