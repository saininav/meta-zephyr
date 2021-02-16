include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/bluetooth/peripheral_hr"

ZEPHYR_MODULES_append = "\;${S}/modules/crypto/tinycrypt"
