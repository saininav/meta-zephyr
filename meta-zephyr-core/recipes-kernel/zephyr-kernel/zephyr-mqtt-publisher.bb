include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/net/mqtt_publisher"

ZEPHYR_MODULES:append = "\;${S}/modules/lib/mbedtls"
