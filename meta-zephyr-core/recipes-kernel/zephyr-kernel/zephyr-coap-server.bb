include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/net/sockets/coap_server"

ZEPHYR_MODULES:append = "\;${S}/modules/lib/mbedtls"
