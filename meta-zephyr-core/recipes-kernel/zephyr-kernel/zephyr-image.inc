require zephyr-sample.inc
inherit testimage

QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

OECMAKE_SOURCEPATH = "${S}/${ZEPHYR_SRC_DIR}"

addtask deploy after do_compile
do_install[noexec] = "1"
