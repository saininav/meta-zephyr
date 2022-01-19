include zephyr-sample.inc


ZEPHYR_MAKE_OUTPUT = "zephyr_openamp_rsc_table.elf"
ZEPHYR_MAKE_BIN_OUTPUT = "zephyr_openamp_rsc_table.bin"
ZEPHYR_MAKE_EFI_OUTPUT = "zephyr_openamp_rsc_table.efi"

ZEPHYR_SRC_DIR = "${S}/samples/subsys/ipc/openamp_rsc_table"

COMPATIBLE_MACHINE = "(stm32mp157c-dk2)"
