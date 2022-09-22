include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/net/openthread/coprocessor"

EXTRA_OECMAKE += "-DCONF_FILE="prj.conf overlay-rcp.conf overlay-usb-nrf-br.conf" -DDTC_OVERLAY_FILE="usb.overlay" -DCONFIG_OPENTHREAD_THREAD_VERSION_1_2=y"

# The overlay config and OpenThread itself imposes some specific requirements
# towards the boards (e.g. flash layout and ieee802154 radio) so we need to
# limit to known working machines here.
COMPATIBLE_MACHINE = "(arduino-nano-33-ble|nrf52840dk-nrf52840)"
