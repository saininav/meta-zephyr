include zephyr-sample.inc

ZEPHYR_SRC_DIR = "${S}/samples/subsys/display/lvgl"
ZEPHYR_MODULES:append = "\;${S}/modules/lib/gui/lvgl\;${S}/modules/debug/segger"

# TODO Once more machines and displays are supported, add a PACKAGECONFIG.
EXTRA_OECMAKE:append =" -DSHIELD=adafruit_2_8_tft_touch_v2"

SRC_URI:append = " \
    file://0001-cmake-added-missing-file-ext-to.patch;patchdir=modules/lib/gui/lvgl \
    git://github.com/zephyrproject-rtos/segger.git;protocol=https;nobranch=1;destsuffix=git/modules/debug/segger;name=segger \
    git://github.com/zephyrproject-rtos/TraceRecorderSource.git;branch=zephyr;protocol=https;destsuffix=git/modules/debug/TraceRecorder;name=TraceRecorderSource \
"

SRCREV_segger = "3a52ab222133193802d3c3b4d21730b9b1f1d2f6"
SRCREV_TraceRecorderSource = "36c577727642457b0db7274298a4b96558374832"

COMATIBLE_MACHINE = "(nrf52840dk-nrf52840)"
