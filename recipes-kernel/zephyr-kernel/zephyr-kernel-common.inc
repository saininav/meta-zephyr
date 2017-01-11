# Common settings for all Zephyr recipes

# There shouldn't be a manifest for zephyr kernels since there is no root
# filesystem.
IMAGE_NO_MANIFEST = "1"

# Zephyr BOARD is basically our MACHINE, except we must use "-" instead of "_"
BOARD="$(echo ${MACHINE} | tr - _)"

# oe_runmake isn't used because of the make -e causing issues with some
# make variables.
MAKE_COMMAND = "make -j V=1 BOARD=${BOARD} CROSS_COMPILE=${CROSS_COMPILE}"

# We always need a toolchain to cross-compile.
INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "gcc-cross-${TARGET_ARCH} libgcc"
CROSS_COMPILE = "${STAGING_BINDIR_TOOLCHAIN}/${TARGET_PREFIX}"

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
