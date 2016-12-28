require zephyr-kernel.inc

inherit deploy

INHIBIT_DEFAULT_DEPS = "1"

DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc"

# The makefiles are explicit about the flags they want, so don't unset
# them so zephyr flags actually get used.
# This is done here rather than in the task so that things still work
# in devshell.
python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

do_configure[noexec] = "1"

CROSS_COMPILE="${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.

MAKE_COMMAND = "make -j V=1 BOARD=${BOARD} CROSS_COMPILE=${CROSS_COMPILE}"

do_compile () {
    cd ${S}
    export ZEPHYR_BASE=${S}
    export ZEPHYR_GCC_VARIANT="yocto"
    ${MAKE_COMMAND} -C samples/philosophers pristine
    ${MAKE_COMMAND} -C samples/philosophers
}

do_deploy () {
    install -D samples/philosophers/outdir/${BOARD}/zephyr.elf ${DEPLOYDIR}/philosophers.elf
    export DEPLOY_DIR_IMAGE=${DEPLOYDIR}/philosophers.elf
}

addtask deploy after do_compile
