require zephyr-kernel.inc
require zephyr-kernel-common.inc

inherit testimage
inherit deploy

QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

OE_TERMINAL_EXPORTS += "CROSS_COMPILE"
OE_TERMINAL_EXPORTS += "BOARD"

do_compile () {
    cd ${S}
    export ZEPHYR_BASE=${S}
    export ZEPHYR_GCC_VARIANT="yocto"
    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR} pristine
    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR}
}

do_deploy () {
    install -D ${ZEPHYR_IMAGE_SRCDIR}/outdir/${BOARD}/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${ZEPHYR_IMAGENAME}
}

addtask deploy after do_compile
