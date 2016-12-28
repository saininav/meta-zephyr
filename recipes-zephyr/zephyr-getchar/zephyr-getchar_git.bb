
LICENSE="Apache-2.0"
LIC_FILES_CHKSUM = "file://src/zephyr_getchar.c;beginline=1;endline=15;md5=d78a817213b11b6bcd9fe41669a2fd4a"
inherit deploy

SRCREV="b8d511be4d2b9e05c6adb413a33d6ea510aa0c6a"
SRC_URI = "git://github.com/pfalcon/zephyr_console_helpers.git;protocol=https"
S = "${WORKDIR}/git/zephyr_getchar"

INHIBIT_DEFAULT_DEPS = "1"

DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc zephyr-kernel-src"

python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

do_configure[noexec] = "1"

CROSS_COMPILE="${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"

do_compile () {
    cd ${S}
    export ZEPHYR_GCC_VARIANT="yocto"
    export CROSS_COMPILE=${CROSS_COMPILE}
    export ZEPHYR_BASE=${STAGING_DIR_TARGET}/usr/src/zephyr
    make -j V=1 BOARD=${BOARD} 
}

do_deploy () {
    install -D ${S}/outdir/${BOARD}/zephyr.elf ${DEPLOYDIR}/${PN}.elf
    export DEPLOY_DIR_IMAGE=${DEPLOYDIR}/${PN}.elf
}

addtask deploy after do_compile
