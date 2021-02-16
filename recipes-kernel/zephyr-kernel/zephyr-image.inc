require zephyr-kernel-src.inc
require zephyr-kernel-common.inc

inherit testimage
inherit deploy

QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

ZEPHYR_BASE = "${S}"
OECMAKE_SOURCEPATH = "${S}/${ZEPHYR_SRC_DIR}"

do_deploy () {
    install -D ${B}/zephyr/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${ZEPHYR_IMAGENAME}
}

addtask deploy after do_compile
do_install[noexec] = "1"
