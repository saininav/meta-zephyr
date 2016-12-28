require zephyr-kernel.inc

inherit testimage
inherit deploy

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc"

CROSS_COMPILE = "${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"
QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

OE_TERMINAL_EXPORTS += "CROSS_COMPILE"
OE_TERMINAL_EXPORTS += "BOARD"

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.
MAKE_COMMAND = "make -j V=1 BOARD=${BOARD} CROSS_COMPILE=${CROSS_COMPILE}"

do_configure[noexec] = "1"

# The makefiles are explicit about the flags they want, so don't unset
# them so zephyr flags actually get used.
# This is done here rather than in the task so that things still work
# in devshell.
python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

do_compile () {
    cd ${S}
    export ZEPHYR_BASE=${S}
    export ZEPHYR_GCC_VARIANT="yocto"
    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR} pristine
    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR}
}

do_deploy () {
    install -D ${ZEPHYR_IMAGE_SRCDIR}/outdir/${BOARD}/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${ZEPHYR_IMAGENAME}
}

addtask deploy after do_compile
