SRCREV_FORMAT = "default_cmsis"

# These repositories are specific to post-2.6 branches

SRC_URI += " \
    git://github.com/zephyrproject-rtos/mcumgr.git;protocol=https;nobranch=1;destsuffix=git/modules/lib/mcumgr;name=mcumgr \
    git://github.com/zephyrproject-rtos/TraceRecorderSource.git;protocol=https;nobranch=1;destsuffix=git/modules/debug/TraceRecorder;name=TraceRecorder \
    git://github.com/zephyrproject-rtos/trusted-firmware-m.git;protocol=https;nobranch=1;destsuffix=git/modules/tee/tfm;name=tfm \
"

#
# Generated from:
# west forall -c 'x=$(filename `pwd`); rev=$(git rev-parse HEAD); \
#      echo SRCREV_$x = \"$rev\"'
#

SRCREV_default = "6dd320f791c4da49190b30f9134f776d85bc5836"
SRCREV_canopennode = "f167efe85c8c7de886f1bc47f9173cfb8a346bb5"
SRCREV_civetweb = "094aeb41bb93e9199d24d665ee43e9e05d6d7b1c"
SRCREV_cmsis = "b0612c97c1401feeb4160add6462c3627fe90fc7"
SRCREV_edtt = "31badfbbd04f2948e3df6ebf329f930317550961"
SRCREV_fatfs = "94fcd6bfb3801ac0a5e12ea2f52187e0a688b90e"
SRCREV_altera = "23c1c1dd7a0c1cc9a399509d1819375847c95b97"
SRCREV_atmel = "9f78f520f6cbb997e5b44fe8ab17dd5bf2448095"
SRCREV_cypress = "81a059f21435bc7e315bccd720da5a9b615bbb50"
SRCREV_espressif = "3400257534944d3a6a4194d1dbf8f0cd1670d64e"
SRCREV_infineon = "f1fa8241f8786198ba41155413243de36ed878a5"
SRCREV_microchip = "870d05e6a64ea9548da6b907058b03c8c9420826"
SRCREV_nordic = "a6e5299041f152da5ae0ab17b2e44e088bb96d6d"
SRCREV_nuvoton = "b4d31f33238713a568e23618845702fadd67386f"
SRCREV_nxp = "78efc4ba7c1057c1cf2bf06e3e27ed7cc33e1da7"
SRCREV_openisa = "40d049f69c50b58ea20473bee14cf93f518bf262"
SRCREV_quicklogic = "b3a66fe6d04d87fd1533a5c8de51d0599fcd08d0"
SRCREV_silabs = "be39d4eebeddac6e18e9c0c3ba1b31ad1e82eaed"
SRCREV_st = "575de9d461aa6f430cf62c58a053675377e700f3"
SRCREV_stm32 = "5c8275071ec1cf160bfe8c18bbd9330a7d714dc8"
SRCREV_telink = "ffcfd6282aa213f1dc0848dbca6279b098f6b143"
SRCREV_ti = "1992a4c536554c4f409c36896eda6abdc414d277"
SRCREV_xtensa = "6e1cf3c483e87df4888e87c5396b4534570f01af"
SRCREV_libmetal = "39d049d4ae68e6f6d595fce7de1dcfc1024fb4eb"
SRCREV_littlefs = "9e4498d1c73009acd84bb36036ee5e2869112a6c"
SRCREV_loramac-node = "12019623bbad9eb54fe51066847a7cbd4b4eac57"
SRCREV_lvgl = "783c1f78c8e39751fe89d0883c8bce7336f55e94"
SRCREV_lz4 = "8e303c264fc21c2116dc612658003a22e933124d"
SRCREV_mbedtls = "5765cb7f75a9973ae9232d438e361a9d7bbc49e7"
SRCREV_mcuboot = "70bfbd21cdf5f6d1402bc8d0031e197222ed2ec0"
SRCREV_mcumgr = "9ffebd5e92d9d069667b9af2a3a028f4a033cfd3"
SRCREV_mipi-sys-t = "75e671550ac1acb502f315fe4952514dc73f7bfb"
SRCREV_nanopb = "d148bd26718e4c10414f07a7eb1bd24c62e56c5d"
SRCREV_net-tools = "f49bd1354616fae4093bf36e5eaee43c51a55127"
SRCREV_nrf_hw_models = "a47e326ca772ddd14cc3b9d4ca30a9ab44ecca16"
SRCREV_open-amp = "6010f0523cbc75f551d9256cf782f173177acdef"
SRCREV_openthread = "5d706547ebcb0a85e11412bcd88e80e2af98c74d"
SRCREV_segger = "3a52ab222133193802d3c3b4d21730b9b1f1d2f6"
SRCREV_sof = "76feb11d1b8f425021b5691668af2250fee444ac"
SRCREV_tflite-micro = "9156d050927012da87079064db59d07f03b8baf6"
SRCREV_tinycbor = "40daca97b478989884bffb5226e9ab73ca54b8c4"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"
SRCREV_TraceRecorder = "36c577727642457b0db7274298a4b96558374832"
SRCREV_tfm = "c74be3890c9d975976fde1b1a3b2f5742bec34c0"

ZEPHYR_BRANCH = "v2.7-branch"
PV = "2.7.2+git${SRCPV}"

SRC_URI:append = " \
    file://dtc.patch;patchdir=zephyr \
    file://0001-x86-fix-efi-binary-generation-issue-in-cross-compila.patch;patchdir=zephyr \
    file://0001-2.7-cmake-add-yocto-toolchain.patch;patchdir=zephyr \
    git://github.com/zephyrproject-rtos/hal_cypress.git;protocol=https;nobranch=1;destsuffix=git/modules/hal/cypress;name=cypress \
"
