require zephyr-kernel.inc

inherit testimage
inherit deploy

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc"

export ZEPHYR_GCC_VARIANT="zephyr"

LIB_INCLUDE_DIR = "-L`dirname \`$CC -print-libgcc-file-name\``"
CROSS_COMPILE = "${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"
QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

ARCH_arm = "${TRANSLATED_TARGET_ARCH}"
ARCH_x86 = "x86"

OE_TERMINAL_EXPORTS += "CROSS_COMPILE"
OE_TERMINAL_EXPORTS += "BOARD"
OE_TERMINAL_EXPORTS += "ARCH"

BOARD_arm ?= "qemu_cortex_m3"
BOARD_x86 ?= "qemu_x86"

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.
MAKE_COMMAND = "make -j V=1 BOARD=${BOARD} ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} LIB_INCLUDE_DIR=${LIB_INCLUDE_DIR}"

do_configure[noexec] = "1"

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

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.
do_compile () {
    cd ${S}
    export ZEPHYR_BASE=${S}
    #source ${S}/zephyr-env.sh

    #${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR} pristine
    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR}
}

do_deploy () {
    install -D ${ZEPHYR_IMAGE_SRCDIR}/outdir/${BOARD}/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${ZEPHYR_IMAGENAME}
}
addtask deploy after do_compile
