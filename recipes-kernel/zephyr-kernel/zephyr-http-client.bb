include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/net/sockets/http_client"

ZEPHYR_MODULES_append = "\;${S}/modules/lib/mbedtls"
