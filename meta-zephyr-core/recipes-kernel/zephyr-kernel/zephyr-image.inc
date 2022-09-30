require zephyr-kernel-src.inc
require zephyr-kernel-common.inc
inherit deploy

OECMAKE_SOURCEPATH = "${ZEPHYR_SRC_DIR}"

do_install[noexec] = "1"

do_deploy() {
    install -D ${B}/zephyr/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${PN}.elf

    if [ -f ${B}/zephyr/${ZEPHYR_MAKE_BIN_OUTPUT} ]
    then
      install -D ${B}/zephyr/${ZEPHYR_MAKE_BIN_OUTPUT} ${DEPLOYDIR}/${PN}.bin
    fi

    if [ -f ${B}/zephyr/${ZEPHYR_MAKE_EFI_OUTPUT} ]
    then
      install -D ${B}/zephyr/${ZEPHYR_MAKE_EFI_OUTPUT} ${DEPLOYDIR}/${PN}.efi
    fi
}
addtask deploy after do_compile
