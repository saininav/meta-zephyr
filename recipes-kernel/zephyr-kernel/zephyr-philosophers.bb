require zephyr-kernel.inc
require zephyr-kernel-common.inc
inherit deploy

do_compile () {
    cd ${S}
    export ZEPHYR_BASE=${S}
    export ZEPHYR_GCC_VARIANT="yocto"
    ${MAKE_COMMAND} -C samples/philosophers pristine
    ${MAKE_COMMAND} -C samples/philosophers
}

do_deploy () {
    install -D samples/philosophers/outdir/${BOARD}/zephyr.elf ${DEPLOYDIR}/philosophers.elf
    export DEPLOY_DIR_IMAGE=${DEPLOYDIR}/philosophers.elf
}

addtask deploy after do_compile
