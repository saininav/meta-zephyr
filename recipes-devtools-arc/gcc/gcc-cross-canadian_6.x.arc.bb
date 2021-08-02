require recipes-devtools-arc/gcc/gcc-${PV}.inc
require recipes-devtools/gcc/gcc-cross-canadian.inc

EXTRA_OECONF:append:libc-baremetal = " --without-headers"
EXTRA_OECONF:remove:libc-baremetal = "--with-sysroot=/not/exist"
EXTRA_OECONF:remove:libc-baremetal = "--with-build-sysroot=${STAGING_DIR_TARGET}"
EXTRA_OECONF:append:libc-baremetal = " --enable-plugin "

