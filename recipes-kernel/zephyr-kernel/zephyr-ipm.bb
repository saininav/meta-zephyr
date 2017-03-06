require zephyr-kernel.inc
require zephyr-kernel-common.inc
inherit deploy

SRC_DIR_IPM_arduino-101-sss = "samples/ipm/ipm_demo_arc"
SRC_DIR_IPM_arduino-101     = "samples/ipm/ipm_demo_lmt"

COMPATIBLE_MACHINE = "(arduino-101-sss|arduino-101)"

ZEPHYR_SRC_DIR = "${S}/${SRC_DIR_IPM}/src"

ZEPHYR_BASE = "${S}"

do_compile () {
    cd ${SRC_DIR_IPM}
    oe_runmake ${ZEPHYR_MAKE_ARGS}
}

do_deploy () {
    install -D ${SRC_DIR_IPM}/outdir/${BOARD}/zephyr.elf ${DEPLOYDIR}/${PN}.elf
    install -D ${SRC_DIR_IPM}/outdir/${BOARD}/zephyr.bin ${DEPLOYDIR}/${PN}.bin
}

addtask deploy after do_compile
