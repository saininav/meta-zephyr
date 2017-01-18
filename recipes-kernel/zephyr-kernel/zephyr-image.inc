require zephyr-kernel.inc
require zephyr-kernel-common.inc

inherit testimage
inherit deploy

QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

ZEPHYR_BASE = "${S}"

do_compile () {
    cd ${S}
     oe_runmake ${ZEPHYR_MAKE_ARGS} -C ${ZEPHYR_IMAGE_SRCDIR}
}

do_deploy () {
    install -D ${ZEPHYR_IMAGE_SRCDIR}/outdir/${BOARD}/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${ZEPHYR_IMAGENAME}
}

addtask deploy after do_compile
