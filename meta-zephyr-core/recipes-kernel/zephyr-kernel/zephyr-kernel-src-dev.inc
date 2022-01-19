SRCREV_FORMAT = "default_cmsis"
SRCREV_default = "72bb75a360ce05bfc94ff0fbecda2e2d094e3d84"
SRCREV_cmsis = "c3bd2094f92d574377f7af2aec147ae181aa5f8e"
SRCREV_nordic = "00fd2aa97a22ea1052d9dabe1b18ab396daab93a"
SRCREV_stm32 = "4200321ef1cd27cacc37b0439389424156bb1267"
SRCREV_open-amp = "6010f0523cbc75f551d9256cf782f173177acdef"
SRCREV_openthread = "542b14a5bc5b38f29e2cab892c66da670a524b05"
SRCREV_libmetal = "39d049d4ae68e6f6d595fce7de1dcfc1024fb4eb"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"
SRCREV_mbedtls = "5765cb7f75a9973ae9232d438e361a9d7bbc49e7"

ZEPHYR_BRANCH = "main"
PV = "2.6.0+git${SRCPV}"

SRC_URI:append = " file://0001-cmake-add-yocto-toolchain.patch \
                    file://0001-x86-fix-efi-binary-generation-issue-in-cross-compila.patch \
                    "
