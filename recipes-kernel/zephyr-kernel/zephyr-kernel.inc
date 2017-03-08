
inherit zephyr-kernel-src

S = "${WORKDIR}/git"

do_compile_prepend() {
    cp ${WORKDIR}/Makefile.toolchain.yocto ${S}/scripts
}
