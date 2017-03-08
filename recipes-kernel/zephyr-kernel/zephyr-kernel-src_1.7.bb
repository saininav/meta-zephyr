
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fa818a259cbed7ce8bc2a22d35a464fc"

SRCREV = "3d2893cf85d51ceca04aa3bec2dd5fc77625ff81"
SRC_URI = "git://gerrit.zephyrproject.org/r/zephyr.git;protocol=https;branch=v1.7-branch"
SRC_URI += "file://Makefile.toolchain.yocto"

PV = "1.7.0"

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

#WARNING: zephyr-kernel-src-1.7.0-r0 do_package_qa: QA Issue:
#   /usr/src/zephyr/scripts/checkpatch.pl contained in package zephyr-kernel-src
#   requires /usr/bin/perl, but no providers found in RDEPENDS_zephyr-kernel-src?
INSANE_SKIP_${PN} = "file-rdeps"
