require zephyr-kernel-src.inc
require zephyr-kernel-common.inc
inherit deploy

ZEPHYR_BASE = "${S}"
OECMAKE_SOURCEPATH = "${ZEPHYR_SRC_DIR}"

do_install[noexec] = "1"

do_deploy () {
    install -D ${B}/zephyr/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${PN}.elf
}
addtask deploy after do_compile
