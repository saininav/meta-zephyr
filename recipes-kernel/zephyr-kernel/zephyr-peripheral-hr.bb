include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/bluetooth/peripheral_hr"

ZEPHYR_MODULES:append = "\;${S}/modules/crypto/tinycrypt"
