# Common settings for all Zephyr recipes

ZEPHYR_INHERIT_CLASSES += "zephyr cmake"
inherit ${ZEPHYR_INHERIT_CLASSES}
inherit python3native

# There shouldn't be a manifest for zephyr kernels since there is no root
# filesystem.
IMAGE_NO_MANIFEST = "1"

ZEPHYR_GCC_VARIANT="yocto"
ZEPHYR_SYSROOT="${STAGING_DIR_TARGET}"

ZEPHYR_MAKE_OUTPUT = "zephyr.elf"


EXTRA_OECMAKE = " -DZEPHYR_BASE=${S} -DZEPHYR_GCC_VARIANT=yocto -DBOARD=${BOARD} -DARCH=${ARCH} -DCROSS_COMPILE=${CROSS_COMPILE} -DZEPHYR_SYSROOT=${ZEPHYR_SYSROOT} -DZEPHYR_TOOLCHAIN_VARIANT=yocto"

ZEPHYR_MODULES = ""
ZEPHYR_MODULES_append_arm = "\;${S}/modules/cmsis"
ZEPHYR_MODULES_append_nordic = "\;${S}/modules/hal/nordic"
ZEPHYR_MODULES_append_stm32 = "\;${S}/modules/hal/stm32"
ZEPHYR_MODULES_append_openamp = "\;${S}/modules/lib/open-amp\;${S}/modules/hal/libmetal"

EXTRA_OECMAKE_append = " -DZEPHYR_MODULES=${ZEPHYR_MODULES}"

export ZEPHYR_BASE="${S}"


DEPENDS += "gperf-native python3-pyelftools-native python3-pyyaml-native python3-pykwalify-native"
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
