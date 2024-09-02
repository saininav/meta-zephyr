require zephyr-kernel-src.inc
require zephyr-kernel-common.inc
inherit deploy

OECMAKE_SOURCEPATH = "${ZEPHYR_SRC_DIR}"

do_install() {
    install -d ${D}/firmware

    for output in ${ZEPHYR_MAKE_OUTPUT}; do
        if [ -f ${B}/zephyr/${output} ];
        then
          install -D ${B}/zephyr/${output} ${D}/firmware/
        fi
    done
}
FILES:${PN} = "/firmware"
INSANE_SKIP += "ldflags buildpaths"
SYSROOT_DIRS += "/firmware"

do_deploy() {
    cp ${D}/firmware/* ${DEPLOYDIR}/
}
addtask deploy after do_install
