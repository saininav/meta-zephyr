require recipes-devtools-arc/gcc/gcc-6.x.arc.inc
require recipes-devtools/gcc/gcc-cross.inc

DEPENDS:remove:libc-baremetal := "virtual/${TARGET_PREFIX}libc-for-gcc"
EXTRA_OECONF:append:libc-baremetal = " --without-headers"
EXTRA_OECONF:remove:libc-baremetal = "--with-sysroot=/not/exist"
EXTRA_OECONF:remove:libc-baremetal = "--enable-threads=posix"

#COMPATIBLE_MACHINE = "arc"

BBCLASSEXTEND = "nativesdk"
