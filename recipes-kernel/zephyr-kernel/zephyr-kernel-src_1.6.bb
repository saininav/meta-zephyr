
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

# tag v1.6.0
SRCREV="d4e799d77a36eaf6d678b357c207411ec32b2d62"
SRC_URI = "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https;branch=v1.6-branch"
SRC_URI += "file://Makefile.toolchain.yocto"

PV = "1.6.0"

S = "${WORKDIR}/git"

IMAGE_NO_MANIFEST = "1"
INHIBIT_DEFAULT_DEPS = "1"

do_compile[noexec] = "1"

do_configure() {
    cp ${WORKDIR}/Makefile.toolchain.yocto ${S}/scripts
}

do_compile () {
}


do_install () {
    kerneldir=${D}/usr/src/zephyr
    install -d $kerneldir
    cp -r ${S}/* $kerneldir
}

PACKAGES = "${PN}"
FILES_${PN} = "/usr/src/zephyr"

SYSROOT_DIRS += "/usr/src/zephyr"

