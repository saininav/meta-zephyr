# Common settings for all Zephyr recipes

ZEPHYR_INHERIT_CLASSES += "zephyr"
inherit ${ZEPHYR_INHERIT_CLASSES}

# There shouldn't be a manifest for zephyr kernels since there is no root
# filesystem.
IMAGE_NO_MANIFEST = "1"

ZEPHYR_GCC_VARIANT="yocto"
ZEPHYR_SYSROOT="${STAGING_DIR_TARGET}"

ZEPHYR_MAKE_OUTPUT = "zephyr.elf"
ZEPHYR_MAKE_ARGS = " BOARD=${BOARD} ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} ZEPHYR_GCC_VARIANT=${ZEPHYR_GCC_VARIANT} ZEPHYR_BASE=${ZEPHYR_BASE} ZEPHYR_SYSROOT=${ZEPHYR_SYSROOT}"

# We always need a toolchain to cross-compile.
INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc ${TOOLCHAIN_TARGET_TASK}"
CROSS_COMPILE = "${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"

DEPENDS_append_qemuall = " qemu-native qemu-helper-native"

# The makefiles are explicit about the flags they want, so don't unset
# them so zephyr flags actually get used.
# This is done here rather than in the task so that things still work
# in devshell.

python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

OE_TERMINAL_EXPORTS += "CROSS_COMPILE"
OE_TERMINAL_EXPORTS += "BOARD"
OE_TERMINAL_EXPORTS += "ZEPHYR_SRC_DIR"
OE_TERMINAL_EXPORTS += "ZEPHYR_BASE"
OE_TERMINAL_EXPORTS += "ZEPHYR_SYSROOT"
OE_TERMINAL_EXPORTS += "ZEPHYR_GCC_VARIANT"

IMAGE_FSTYPES = "elf bin"
