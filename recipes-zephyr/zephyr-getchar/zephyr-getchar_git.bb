
LICENSE="Apache-2.0"
LIC_FILES_CHKSUM = "file://src/zephyr_getchar.c;beginline=1;endline=15;md5=d78a817213b11b6bcd9fe41669a2fd4a"
inherit deploy

require recipes-kernel/zephyr-kernel/zephyr-kernel-common.inc

SRCREV="b8d511be4d2b9e05c6adb413a33d6ea510aa0c6a"
SRC_URI = "git://github.com/pfalcon/zephyr_console_helpers.git;protocol=https"
S = "${WORKDIR}/git/zephyr_getchar"

ZEPHYR_SRC_DIR = "${S}"
ZEPHYR_BASE="${STAGING_DIR_TARGET}/usr/src/zephyr"

DEPENDS += "zephyr-kernel-src"

do_compile () {
    cd ${ZEPHYR_SRC_DIR}
    oe_runmake ${ZEPHYR_MAKE_ARGS}
}

do_deploy () {
    install -D ${S}/outdir/${BOARD}/zephyr.elf ${DEPLOYDIR}/${PN}.elf
}

addtask deploy after do_compile
