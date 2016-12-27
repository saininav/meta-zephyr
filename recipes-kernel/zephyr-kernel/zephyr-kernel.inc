LICENSE = "CLOSED"

SRC_URI += "file://0001-Makefile.toolchain.yocto-Don-t-error-out-if-CROSS_CO.patch"
SRC_URI += "file://0002-zephyr-env.sh-Work-with-zsh.patch"
SRC_URI += "file://0003-zephyr-env.sh-Don-t-wait-to-test-for-error-condition.patch"

# Modify these as desired
PV = "1.0+git${SRCPV}"

S = "${WORKDIR}/git"

# There shouldn't be a manifest for zephyr kernels since there is no root
# filesystem.
IMAGE_NO_MANIFEST = "1"
