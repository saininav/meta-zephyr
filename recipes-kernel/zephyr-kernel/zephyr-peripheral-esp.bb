require zephyr-kernel.inc
require zephyr-kernel-common.inc
inherit deploy

ZEPHYR_SAMPLE_NAME="samples/bluetooth/peripheral_esp"
ZEPHYR_SRC_DIR = "${S}/${ZEPHYR_SAMPLE_NAME}"
ZEPHYR_BASE = "${S}"
OECMAKE_SOURCEPATH = "${ZEPHYR_SRC_DIR}"
EXTRA_OECMAKE_append = "\;${S}/modules/crypto/tinycrypt"

do_deploy () {
    install -D ${B}/zephyr/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${PN}.elf
}

addtask deploy after do_compile
do_install[noexec] = "1"
