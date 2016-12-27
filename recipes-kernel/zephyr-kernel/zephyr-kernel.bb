require zephyr-kernel.inc

inherit deploy

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc"

#SRC_URI += "file://0001-defs.host-Allow-HOS_Bin-to-be-overridden.patch"

export ZEPHYR_GCC_VARIANT="yocto"

# The makefiles are explicit about the flags they want, so don't unset
# them so zephyr flags actually get used. Should we set EXTRA_CFLAGS so our
# additional flags get picked up?
# This is done here rather than in the task so that things still work
# in devshell.
python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

do_configure[noexec] = "1"

MACRO_SUPPORT = "1"
MACRO_SUPPORT_arc = "0"

LIB_INCLUDE_DIR="-L`dirname \`$CC -print-libgcc-file-name\``"
CROSS_COMPILE="${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.
MAKE_COMMAND = "make -j V=1 CROSS_COMPILE=${CROSS_COMPILE} LIB_INCLUDE_DIR=${LIB_INCLUDE_DIR}"

do_compile () {
    . ${S}/zephyr-env.sh

    if [ "${MACRO_SUPPORT}" -eq "1" ]; then
        ${MAKE_COMMAND} -C samples/microkernel/apps/hello_world pristine
        ${MAKE_COMMAND} -C samples/microkernel/apps/hello_world

        ${MAKE_COMMAND} -C samples/microkernel/apps/philosophers pristine
        ${MAKE_COMMAND} -C samples/microkernel/apps/philosophers
    fi

    ${MAKE_COMMAND} -C samples/nanokernel/apps/hello_world pristine
    ${MAKE_COMMAND} -C samples/nanokernel/apps/hello_world

    ${MAKE_COMMAND} -C samples/nanokernel/apps/philosophers pristine
    ${MAKE_COMMAND} -C samples/nanokernel/apps/philosophers
}

do_deploy () {
    if [ "${MACRO_SUPPORT}" -eq "1" ]; then
        install -D samples/microkernel/apps/hello_world/outdir/microkernel.elf ${DEPLOYDIR}/hello_world_micro.elf
        install -D samples/microkernel/apps/philosophers/outdir/microkernel.elf ${DEPLOYDIR}/philosophers_micro.elf
    fi

    install -D samples/nanokernel/apps/hello_world/outdir/nanokernel.elf ${DEPLOYDIR}/hello_world_nano.elf
    install -D samples/nanokernel/apps/philosophers/outdir/nanokernel.elf ${DEPLOYDIR}/philosophers_nano.elf
}
addtask deploy after do_compile
