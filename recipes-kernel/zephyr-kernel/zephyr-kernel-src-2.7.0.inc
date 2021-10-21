SRCREV_FORMAT = "default_cmsis"
SRCREV_default = "3f826560aaf81a444018293bd6acce3c339fe150"
SRCREV_cmsis = "b0612c97c1401feeb4160add6462c3627fe90fc7"
SRCREV_nordic = "a6e5299041f152da5ae0ab17b2e44e088bb96d6d"
SRCREV_stm32 = "5c8275071ec1cf160bfe8c18bbd9330a7d714dc8"
SRCREV_open-amp = "6010f0523cbc75f551d9256cf782f173177acdef"
SRCREV_openthread = "5d706547ebcb0a85e11412bcd88e80e2af98c74d"
SRCREV_libmetal = "39d049d4ae68e6f6d595fce7de1dcfc1024fb4eb"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"
SRCREV_mbedtls = "5765cb7f75a9973ae9232d438e361a9d7bbc49e7"

ZEPHYR_BRANCH = "v2.7-branch"
PV = "2.7.0+git${SRCPV}"

SRC_URI:append = " file://0001-cmake-add-yocto-toolchain.patch \
                    file://0001-x86-fix-efi-binary-generation-issue-in-cross-compila.patch \
                    "
