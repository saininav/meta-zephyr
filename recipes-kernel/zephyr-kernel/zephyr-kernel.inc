LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

# tag v1.6.0
SRCREV="d4e799d77a36eaf6d678b357c207411ec32b2d62"
SRC_URI = "git://gerrit.zephyrproject.org/r/zephyr.git;protocol=https;branch=v1.6.0-branch"
SRC_URI += "file://0001-Makefile.toolchain.yocto-Don-t-error-out-if-CROSS_CO.patch"

PV = "1.6.0"

S = "${WORKDIR}/git"

# There shouldn't be a manifest for zephyr kernels since there is no root
# filesystem.
IMAGE_NO_MANIFEST = "1"

BOARD_arm ?= "qemu_cortex_m3"
BOARD_x86 ?= "qemu_x86"
