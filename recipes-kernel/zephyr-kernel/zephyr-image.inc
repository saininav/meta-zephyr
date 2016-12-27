require zephyr-kernel.inc

inherit testimage
inherit deploy

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc"

export ZEPHYR_GCC_VARIANT="yocto"

LIB_INCLUDE_DIR = "-L`dirname \`$CC -print-libgcc-file-name\``"
CROSS_COMPILE = "${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"
QEMU_BIN_PATH = "${STAGING_BINDIR_NATIVE}"

PLATFORM_CONFIG_arm = "basic_cortex_m3"
ARCH_arm = "${TRANSLATED_TARGET_ARCH}"

OE_TERMINAL_EXPORTS += "CROSS_COMPILE"
OE_TERMINAL_EXPORTS += "PLATFORM_CONFIG"
OE_TERMINAL_EXPORTS += "ARCH"

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.
MAKE_COMMAND = "make -j V=1 ARCH=${ARCH} PLATFORM_CONFIG=${PLATFORM_CONFIG} CROSS_COMPILE=${CROSS_COMPILE} LIB_INCLUDE_DIR=${LIB_INCLUDE_DIR}"

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
    source ${S}/zephyr-env.sh

    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR} pristine
    ${MAKE_COMMAND} -C ${ZEPHYR_IMAGE_SRCDIR}
}

do_deploy () {
    install -D ${ZEPHYR_IMAGE_SRCDIR}/outdir/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${ZEPHYR_IMAGENAME}
}
addtask deploy after do_compile
