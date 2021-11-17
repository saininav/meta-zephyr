SRCREV_FORMAT = "default_cmsis"
SRCREV_cmsis = "c3bd2094f92d574377f7af2aec147ae181aa5f8e"
SRCREV_default = "2d6322d74aaac838ead46bfcba0db619cff4b534"
SRCREV_libmetal = "39d049d4ae68e6f6d595fce7de1dcfc1024fb4eb"
SRCREV_mbedtls = "5765cb7f75a9973ae9232d438e361a9d7bbc49e7"
SRCREV_nordic = "574493fe29c79140df4827ab5d4a23df79d03681"
SRCREV_open-amp = "6010f0523cbc75f551d9256cf782f173177acdef"
SRCREV_openthread = "385e19da1ae15f27872c2543b97276a42f102ead"
SRCREV_stm32 = "f8ff8d25aa0a9e65948040c7b47ec67f3fa300df"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"

ZEPHYR_BRANCH = "v2.6-branch"
PV = "2.6.1+git${SRCPV}"

SRC_URI:append = " \
    file://0001-cmake-add-yocto-toolchain.patch \
    file://0001-x86-fix-efi-binary-generation-issue-in-cross-compila.patch \
    file://arduino-nano-33-ble-storage-partition.patch \
"
