require zephyr-kernel.inc
require zephyr-kernel-common.inc
inherit cmake pkgconfig deploy

ZEPHYR_SRC_DIR = "${S}/samples/hello_world"
ZEPHYR_BASE = "${S}"
OECMAKE_SOURCEPATH = "${ZEPHYR_SRC_DIR}"

DEPENDS += "gperf-native"

EXTRA_OECMAKE = " -DZEPHYR_BASE=${S} -DZEPHYR_GCC_VARIANT=yocto -DBOARD=${BOARD} -DARCH=${ARCH} -DCROSS_COMPILE=${CROSS_COMPILE} -DZEPHYR_SYSROOT=${ZEPHYR_SYSROOT} -DZEPHYR_TOOLCHAIN_VARIANT=yocto"
export ZEPHYR_BASE="${S}"

do_deploy () {
    install -D ${B}/zephyr/zephyr.elf ${DEPLOYDIR}/${PN}.elf
}

addtask deploy after do_compile
do_install[noexec] = "1"
