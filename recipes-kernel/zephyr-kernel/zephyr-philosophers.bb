require zephyr-kernel.inc
require zephyr-kernel-common.inc
inherit deploy

ZEPHYR_SRC_DIR = "${S}/samples/philosophers"
ZEPHYR_BASE = "${S}"

do_compile () {
    cd ${ZEPHYR_SRC_DIR}
    oe_runmake ${ZEPHYR_MAKE_ARGS}
}

do_deploy () {
    install -D samples/philosophers/outdir/${BOARD}/zephyr.elf ${DEPLOYDIR}/philosophers.elf
    install -D samples/philosophers/outdir/${BOARD}/zephyr.bin ${DEPLOYDIR}/philosophers.bin
    export DEPLOY_DIR_IMAGE=${DEPLOYDIR}/philosophers.elf
}

addtask deploy after do_compile
