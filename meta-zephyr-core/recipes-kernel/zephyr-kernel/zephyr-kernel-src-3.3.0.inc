# Auto-generated from zephyr-kernel-src.inc.jinja

SRCREV_FORMAT = "default"

SRCREV_default = "07c6af3b8c35c1e49186578ca61a25c76e2fb308"
SRCREV_canopennode = "dec12fa3f0d790cafa8414a4c2930ea71ab72ffd"
SRCREV_chre = "b7955c27e50485b7dafdc3888d7d6afdc2ac6d96"
SRCREV_cmsis = "74981bf893e8b10931464b9945e2143d99a3f0a3"
SRCREV_edtt = "000fb87261beaf33f80a8868e73857bd62edc668"
SRCREV_fatfs = "427159bf95ea49b7680facffaa29ad506b42709b"
SRCREV_hal_altera = "0d225ddd314379b32355a00fb669eacf911e750d"
SRCREV_hal_atmel = "d45adfb6897aba323cac29cdda8070ce4f23f014"
SRCREV_hal_espressif = "73e7af1e2ed64571ce49ff9f07dc02690b9f2df5"
SRCREV_hal_ethos_u = "90ada2ea5681b2a2722a10d2898eac34c2510791"
SRCREV_hal_gigadevice = "2994b7dde8b0b0fa9b9c0ccb13474b6a486cddc3"
SRCREV_hal_infineon = "5b0c7700a7be049e02835dfa0950d378aac39e67"
SRCREV_hal_microchip = "5d079f1683a00b801373bbbbf5d181d4e33b30d5"
SRCREV_hal_nordic = "3f7ae2320b6d348898c7b11e956a6e792d0b3724"
SRCREV_hal_nuvoton = "0a1f153c433f5f637a4490651bdda6d966de3b99"
SRCREV_hal_nxp = "d957472002a3758154f402e982d95ce90cf58e12"
SRCREV_hal_openisa = "40d049f69c50b58ea20473bee14cf93f518bf262"
SRCREV_hal_quicklogic = "b3a66fe6d04d87fd1533a5c8de51d0599fcd08d0"
SRCREV_hal_renesas = "468d3f2146d18c7f86a4640fc641cc1d20a4a100"
SRCREV_hal_rpi_pico = "a094c060e0c2d43c7f9d8f5c06cc0665117e0c18"
SRCREV_hal_silabs = "9dcaa761258cfdfecaacc5a9f0af92f6535d74a3"
SRCREV_hal_st = "cccbc24c14decfd3f93959f7b14514536af973c7"
SRCREV_hal_stm32 = "b916f9a01c665194fbbdd6a67a0f37b4e0a7e78c"
SRCREV_hal_telink = "38573af589173259801ae6c2b34b7d4c9e626746"
SRCREV_hal_ti = "5e7d5cd584047699c9fd279923120cb25ba3dda7"
SRCREV_hal_wurthelektronik = "24ca9873c3d608fad1fea0431836bc8f144c132e"
SRCREV_hal_xtensa = "63f655362423aa49507da7977a2d37142e8debeb"
SRCREV_libmetal = "efa2ace6028290ddee494a78ade772a0b112ab83"
SRCREV_liblc3 = "448f3de31f49a838988a162ef1e23a89ddf2d2ed"
SRCREV_littlefs = "ca583fd297ceb48bced3c2548600dc615d67af24"
SRCREV_loramac-node = "ce57712f3e426bbbb13acaec97b45369f716f43a"
SRCREV_lvgl = "5ab83099854719ed326b6ecb9b09b07b1eee4818"
SRCREV_lz4 = "8e303c264fc21c2116dc612658003a22e933124d"
SRCREV_mbedtls = "6e166050075688fd3cf3d0cb3fc34a1c52df2496"
SRCREV_mcuboot = "750678e33819b95756203e5db1ba827baee35708"
SRCREV_mipi-sys-t = "0d521d8055f3b2b4842f728b0365d3f0ece9c37f"
SRCREV_nanopb = "dc4deed54fd4c7e1935e3b6387eedf21bb45dc38"
SRCREV_net-tools = "e0828aa9629b533644dc96ff6d1295c939bd713c"
SRCREV_nrf_hw_models = "d8f125e1988221ebfea5944fc3118f1780787ccc"
SRCREV_open-amp = "aedcc262f93bbb1b0c2f58026911575729b7465c"
SRCREV_openthread = "a1979fdd8ed756468719cc4921b04a57efcf9f15"
SRCREV_picolibc = "98e59b70d6ef8eb18f7dccc3d39cecaa0658fa4f"
SRCREV_segger = "e2ff2200556e8a8f962921444275c04971a2bb3d"
SRCREV_sof = "6f5f7258ad2738df78e600568d38fc261e2a118d"
SRCREV_tflite-micro = "9156d050927012da87079064db59d07f03b8baf6"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"
SRCREV_TraceRecorderSource = "d92607521335eaaaedb01b241cdd26fda48a5ca6"
SRCREV_trusted-firmware-m = "f2a639c8d1842acb2964a27461f5c9cfdfaa4d16"
SRCREV_trusted-firmware-a = "28f5e137837f1c1a7a7b2af2dd8bb778c0a27532"
SRCREV_tf-m-tests = "0f80a65193ddbbe3f0ac38b33b07b26138c11fa7"
SRCREV_psa-arch-tests = "24ed42e34e03ebbc945a7204819c1471cce2bda8"
SRCREV_uoscore-uedhoc = "e8920192b66db4f909eb9cd3f155d5245c1ae825"
SRCREV_zcbor = "0556edac504d1f34699aa8a22fcd507c14756c9e"
SRCREV_zscilib = "0035be5e6a45e4ab89755b176d305d7a877fc79c"
SRCREV_thrift = "10023645a0e6cb7ce23fcd7fd3dbac9f18df6234"

SRC_URI_ZEPHYR ?= "git://github.com/zephyrproject-rtos/zephyr.git;protocol=https"
SRC_URI_ZEPHYR_CANOPENNODE ?= "git://github.com/zephyrproject-rtos/canopennode;protocol=https"
SRC_URI_ZEPHYR_CHRE ?= "git://github.com/zephyrproject-rtos/chre;protocol=https"
SRC_URI_ZEPHYR_CMSIS ?= "git://github.com/zephyrproject-rtos/cmsis;protocol=https"
SRC_URI_ZEPHYR_EDTT ?= "git://github.com/zephyrproject-rtos/edtt;protocol=https"
SRC_URI_ZEPHYR_FATFS ?= "git://github.com/zephyrproject-rtos/fatfs;protocol=https"
SRC_URI_ZEPHYR_HAL_ALTERA ?= "git://github.com/zephyrproject-rtos/hal_altera;protocol=https"
SRC_URI_ZEPHYR_HAL_ATMEL ?= "git://github.com/zephyrproject-rtos/hal_atmel;protocol=https"
SRC_URI_ZEPHYR_HAL_ESPRESSIF ?= "git://github.com/zephyrproject-rtos/hal_espressif;protocol=https"
SRC_URI_ZEPHYR_HAL_ETHOS_U ?= "git://github.com/zephyrproject-rtos/hal_ethos_u;protocol=https"
SRC_URI_ZEPHYR_HAL_GIGADEVICE ?= "git://github.com/zephyrproject-rtos/hal_gigadevice;protocol=https"
SRC_URI_ZEPHYR_HAL_INFINEON ?= "git://github.com/zephyrproject-rtos/hal_infineon;protocol=https"
SRC_URI_ZEPHYR_HAL_MICROCHIP ?= "git://github.com/zephyrproject-rtos/hal_microchip;protocol=https"
SRC_URI_ZEPHYR_HAL_NORDIC ?= "git://github.com/zephyrproject-rtos/hal_nordic;protocol=https"
SRC_URI_ZEPHYR_HAL_NUVOTON ?= "git://github.com/zephyrproject-rtos/hal_nuvoton;protocol=https"
SRC_URI_ZEPHYR_HAL_NXP ?= "git://github.com/zephyrproject-rtos/hal_nxp;protocol=https"
SRC_URI_ZEPHYR_HAL_OPENISA ?= "git://github.com/zephyrproject-rtos/hal_openisa;protocol=https"
SRC_URI_ZEPHYR_HAL_QUICKLOGIC ?= "git://github.com/zephyrproject-rtos/hal_quicklogic;protocol=https"
SRC_URI_ZEPHYR_HAL_RENESAS ?= "git://github.com/zephyrproject-rtos/hal_renesas;protocol=https"
SRC_URI_ZEPHYR_HAL_RPI_PICO ?= "git://github.com/zephyrproject-rtos/hal_rpi_pico;protocol=https"
SRC_URI_ZEPHYR_HAL_SILABS ?= "git://github.com/zephyrproject-rtos/hal_silabs;protocol=https"
SRC_URI_ZEPHYR_HAL_ST ?= "git://github.com/zephyrproject-rtos/hal_st;protocol=https"
SRC_URI_ZEPHYR_HAL_STM32 ?= "git://github.com/zephyrproject-rtos/hal_stm32;protocol=https"
SRC_URI_ZEPHYR_HAL_TELINK ?= "git://github.com/zephyrproject-rtos/hal_telink;protocol=https"
SRC_URI_ZEPHYR_HAL_TI ?= "git://github.com/zephyrproject-rtos/hal_ti;protocol=https"
SRC_URI_ZEPHYR_HAL_WURTHELEKTRONIK ?= "git://github.com/zephyrproject-rtos/hal_wurthelektronik;protocol=https"
SRC_URI_ZEPHYR_HAL_XTENSA ?= "git://github.com/zephyrproject-rtos/hal_xtensa;protocol=https"
SRC_URI_ZEPHYR_LIBMETAL ?= "git://github.com/zephyrproject-rtos/libmetal;protocol=https"
SRC_URI_ZEPHYR_LIBLC3 ?= "git://github.com/zephyrproject-rtos/liblc3;protocol=https"
SRC_URI_ZEPHYR_LITTLEFS ?= "git://github.com/zephyrproject-rtos/littlefs;protocol=https"
SRC_URI_ZEPHYR_LORAMAC_NODE ?= "git://github.com/zephyrproject-rtos/loramac-node;protocol=https"
SRC_URI_ZEPHYR_LVGL ?= "git://github.com/zephyrproject-rtos/lvgl;protocol=https"
SRC_URI_ZEPHYR_LZ4 ?= "git://github.com/zephyrproject-rtos/lz4;protocol=https"
SRC_URI_ZEPHYR_MBEDTLS ?= "git://github.com/zephyrproject-rtos/mbedtls;protocol=https"
SRC_URI_ZEPHYR_MCUBOOT ?= "git://github.com/zephyrproject-rtos/mcuboot;protocol=https"
SRC_URI_ZEPHYR_MIPI_SYS_T ?= "git://github.com/zephyrproject-rtos/mipi-sys-t;protocol=https"
SRC_URI_ZEPHYR_NANOPB ?= "git://github.com/zephyrproject-rtos/nanopb;protocol=https"
SRC_URI_ZEPHYR_NET_TOOLS ?= "git://github.com/zephyrproject-rtos/net-tools;protocol=https"
SRC_URI_ZEPHYR_NRF_HW_MODELS ?= "git://github.com/zephyrproject-rtos/nrf_hw_models;protocol=https"
SRC_URI_ZEPHYR_OPEN_AMP ?= "git://github.com/zephyrproject-rtos/open-amp;protocol=https"
SRC_URI_ZEPHYR_OPENTHREAD ?= "git://github.com/zephyrproject-rtos/openthread;protocol=https"
SRC_URI_ZEPHYR_PICOLIBC ?= "git://github.com/zephyrproject-rtos/picolibc;protocol=https"
SRC_URI_ZEPHYR_SEGGER ?= "git://github.com/zephyrproject-rtos/segger;protocol=https"
SRC_URI_ZEPHYR_SOF ?= "git://github.com/zephyrproject-rtos/sof;protocol=https"
SRC_URI_ZEPHYR_TFLITE_MICRO ?= "git://github.com/zephyrproject-rtos/tflite-micro;protocol=https"
SRC_URI_ZEPHYR_TINYCRYPT ?= "git://github.com/zephyrproject-rtos/tinycrypt;protocol=https"
SRC_URI_ZEPHYR_TRACERECORDERSOURCE ?= "git://github.com/zephyrproject-rtos/TraceRecorderSource;protocol=https"
SRC_URI_ZEPHYR_TRUSTED_FIRMWARE_M ?= "git://github.com/zephyrproject-rtos/trusted-firmware-m;protocol=https"
SRC_URI_ZEPHYR_TRUSTED_FIRMWARE_A ?= "git://github.com/zephyrproject-rtos/trusted-firmware-a;protocol=https"
SRC_URI_ZEPHYR_TF_M_TESTS ?= "git://github.com/zephyrproject-rtos/tf-m-tests;protocol=https"
SRC_URI_ZEPHYR_PSA_ARCH_TESTS ?= "git://github.com/zephyrproject-rtos/psa-arch-tests;protocol=https"
SRC_URI_ZEPHYR_UOSCORE_UEDHOC ?= "git://github.com/zephyrproject-rtos/uoscore-uedhoc;protocol=https"
SRC_URI_ZEPHYR_ZCBOR ?= "git://github.com/zephyrproject-rtos/zcbor;protocol=https"
SRC_URI_ZEPHYR_ZSCILIB ?= "git://github.com/zephyrproject-rtos/zscilib;protocol=https"
SRC_URI_ZEPHYR_THRIFT ?= "git://github.com/zephyrproject-rtos/thrift;protocol=https"

SRC_URI_PATCHES ?= "\
    file://0001-3.3-x86-fix-efi-binary-generation-issue-in-cross-compila.patch;patchdir=zephyr \
    file://0002-3.3-toolchain-gcc-Fix-separator-between-directives-on-sa.patch;patchdir=zephyr \
"

SRC_URI = "\
    ${SRC_URI_ZEPHYR};branch=${ZEPHYR_BRANCH};name=default;destsuffix=git/zephyr \
    ${SRC_URI_ZEPHYR_CANOPENNODE};name=canopennode;nobranch=1;destsuffix=git/modules/lib/canopennode \
    ${SRC_URI_ZEPHYR_CHRE};name=chre;nobranch=1;destsuffix=git/modules/lib/chre \
    ${SRC_URI_ZEPHYR_CMSIS};name=cmsis;nobranch=1;destsuffix=git/modules/hal/cmsis \
    ${SRC_URI_ZEPHYR_EDTT};name=edtt;nobranch=1;destsuffix=git/tools/edtt \
    ${SRC_URI_ZEPHYR_FATFS};name=fatfs;nobranch=1;destsuffix=git/modules/fs/fatfs \
    ${SRC_URI_ZEPHYR_HAL_ALTERA};name=hal_altera;nobranch=1;destsuffix=git/modules/hal/altera \
    ${SRC_URI_ZEPHYR_HAL_ATMEL};name=hal_atmel;nobranch=1;destsuffix=git/modules/hal/atmel \
    ${SRC_URI_ZEPHYR_HAL_ESPRESSIF};name=hal_espressif;nobranch=1;destsuffix=git/modules/hal/espressif \
    ${SRC_URI_ZEPHYR_HAL_ETHOS_U};name=hal_ethos_u;nobranch=1;destsuffix=git/modules/hal/ethos_u \
    ${SRC_URI_ZEPHYR_HAL_GIGADEVICE};name=hal_gigadevice;nobranch=1;destsuffix=git/modules/hal/gigadevice \
    ${SRC_URI_ZEPHYR_HAL_INFINEON};name=hal_infineon;nobranch=1;destsuffix=git/modules/hal/infineon \
    ${SRC_URI_ZEPHYR_HAL_MICROCHIP};name=hal_microchip;nobranch=1;destsuffix=git/modules/hal/microchip \
    ${SRC_URI_ZEPHYR_HAL_NORDIC};name=hal_nordic;nobranch=1;destsuffix=git/modules/hal/nordic \
    ${SRC_URI_ZEPHYR_HAL_NUVOTON};name=hal_nuvoton;nobranch=1;destsuffix=git/modules/hal/nuvoton \
    ${SRC_URI_ZEPHYR_HAL_NXP};name=hal_nxp;nobranch=1;destsuffix=git/modules/hal/nxp \
    ${SRC_URI_ZEPHYR_HAL_OPENISA};name=hal_openisa;nobranch=1;destsuffix=git/modules/hal/openisa \
    ${SRC_URI_ZEPHYR_HAL_QUICKLOGIC};name=hal_quicklogic;nobranch=1;destsuffix=git/modules/hal/quicklogic \
    ${SRC_URI_ZEPHYR_HAL_RENESAS};name=hal_renesas;nobranch=1;destsuffix=git/modules/hal/renesas \
    ${SRC_URI_ZEPHYR_HAL_RPI_PICO};name=hal_rpi_pico;nobranch=1;destsuffix=git/modules/hal/rpi_pico \
    ${SRC_URI_ZEPHYR_HAL_SILABS};name=hal_silabs;nobranch=1;destsuffix=git/modules/hal/silabs \
    ${SRC_URI_ZEPHYR_HAL_ST};name=hal_st;nobranch=1;destsuffix=git/modules/hal/st \
    ${SRC_URI_ZEPHYR_HAL_STM32};name=hal_stm32;nobranch=1;destsuffix=git/modules/hal/stm32 \
    ${SRC_URI_ZEPHYR_HAL_TELINK};name=hal_telink;nobranch=1;destsuffix=git/modules/hal/telink \
    ${SRC_URI_ZEPHYR_HAL_TI};name=hal_ti;nobranch=1;destsuffix=git/modules/hal/ti \
    ${SRC_URI_ZEPHYR_HAL_WURTHELEKTRONIK};name=hal_wurthelektronik;nobranch=1;destsuffix=git/modules/hal/wurthelektronik \
    ${SRC_URI_ZEPHYR_HAL_XTENSA};name=hal_xtensa;nobranch=1;destsuffix=git/modules/hal/xtensa \
    ${SRC_URI_ZEPHYR_LIBMETAL};name=libmetal;nobranch=1;destsuffix=git/modules/hal/libmetal \
    ${SRC_URI_ZEPHYR_LIBLC3};name=liblc3;nobranch=1;destsuffix=git/modules/lib/liblc3 \
    ${SRC_URI_ZEPHYR_LITTLEFS};name=littlefs;nobranch=1;destsuffix=git/modules/fs/littlefs \
    ${SRC_URI_ZEPHYR_LORAMAC_NODE};name=loramac-node;nobranch=1;destsuffix=git/modules/lib/loramac-node \
    ${SRC_URI_ZEPHYR_LVGL};name=lvgl;nobranch=1;destsuffix=git/modules/lib/gui/lvgl \
    ${SRC_URI_ZEPHYR_LZ4};name=lz4;nobranch=1;destsuffix=git/modules/lib/lz4 \
    ${SRC_URI_ZEPHYR_MBEDTLS};name=mbedtls;nobranch=1;destsuffix=git/modules/crypto/mbedtls \
    ${SRC_URI_ZEPHYR_MCUBOOT};name=mcuboot;nobranch=1;destsuffix=git/bootloader/mcuboot \
    ${SRC_URI_ZEPHYR_MIPI_SYS_T};name=mipi-sys-t;nobranch=1;destsuffix=git/modules/debug/mipi-sys-t \
    ${SRC_URI_ZEPHYR_NANOPB};name=nanopb;nobranch=1;destsuffix=git/modules/lib/nanopb \
    ${SRC_URI_ZEPHYR_NET_TOOLS};name=net-tools;nobranch=1;destsuffix=git/tools/net-tools \
    ${SRC_URI_ZEPHYR_NRF_HW_MODELS};name=nrf_hw_models;nobranch=1;destsuffix=git/modules/bsim_hw_models/nrf_hw_models \
    ${SRC_URI_ZEPHYR_OPEN_AMP};name=open-amp;nobranch=1;destsuffix=git/modules/lib/open-amp \
    ${SRC_URI_ZEPHYR_OPENTHREAD};name=openthread;nobranch=1;destsuffix=git/modules/lib/openthread \
    ${SRC_URI_ZEPHYR_PICOLIBC};name=picolibc;nobranch=1;destsuffix=git/modules/lib/picolibc \
    ${SRC_URI_ZEPHYR_SEGGER};name=segger;nobranch=1;destsuffix=git/modules/debug/segger \
    ${SRC_URI_ZEPHYR_SOF};name=sof;nobranch=1;destsuffix=git/modules/audio/sof \
    ${SRC_URI_ZEPHYR_TFLITE_MICRO};name=tflite-micro;nobranch=1;destsuffix=git/modules/lib/tflite-micro \
    ${SRC_URI_ZEPHYR_TINYCRYPT};name=tinycrypt;nobranch=1;destsuffix=git/modules/crypto/tinycrypt \
    ${SRC_URI_ZEPHYR_TRACERECORDERSOURCE};name=TraceRecorderSource;nobranch=1;destsuffix=git/modules/debug/TraceRecorder \
    ${SRC_URI_ZEPHYR_TRUSTED_FIRMWARE_M};name=trusted-firmware-m;nobranch=1;destsuffix=git/modules/tee/tf-m/trusted-firmware-m \
    ${SRC_URI_ZEPHYR_TRUSTED_FIRMWARE_A};name=trusted-firmware-a;nobranch=1;destsuffix=git/modules/tee/tf-a/trusted-firmware-a \
    ${SRC_URI_ZEPHYR_TF_M_TESTS};name=tf-m-tests;nobranch=1;destsuffix=git/modules/tee/tf-m/tf-m-tests \
    ${SRC_URI_ZEPHYR_PSA_ARCH_TESTS};name=psa-arch-tests;nobranch=1;destsuffix=git/modules/tee/tf-m/psa-arch-tests \
    ${SRC_URI_ZEPHYR_UOSCORE_UEDHOC};name=uoscore-uedhoc;nobranch=1;destsuffix=git/modules/lib/uoscore-uedhoc \
    ${SRC_URI_ZEPHYR_ZCBOR};name=zcbor;nobranch=1;destsuffix=git/modules/lib/zcbor \
    ${SRC_URI_ZEPHYR_ZSCILIB};name=zscilib;nobranch=1;destsuffix=git/modules/lib/zscilib \
    ${SRC_URI_ZEPHYR_THRIFT};name=thrift;nobranch=1;destsuffix=git/modules/lib/thrift \
    ${SRC_URI_PATCHES} \
"

ZEPHYR_MODULES = "\
${S}/modules/lib/canopennode\;\
${S}/modules/lib/chre\;\
${S}/modules/hal/cmsis\;\
${S}/tools/edtt\;\
${S}/modules/fs/fatfs\;\
${S}/modules/hal/altera\;\
${S}/modules/hal/atmel\;\
${S}/modules/hal/espressif\;\
${S}/modules/hal/ethos_u\;\
${S}/modules/hal/gigadevice\;\
${S}/modules/hal/infineon\;\
${S}/modules/hal/microchip\;\
${S}/modules/hal/nordic\;\
${S}/modules/hal/nuvoton\;\
${S}/modules/hal/nxp\;\
${S}/modules/hal/openisa\;\
${S}/modules/hal/quicklogic\;\
${S}/modules/hal/renesas\;\
${S}/modules/hal/rpi_pico\;\
${S}/modules/hal/silabs\;\
${S}/modules/hal/st\;\
${S}/modules/hal/stm32\;\
${S}/modules/hal/telink\;\
${S}/modules/hal/ti\;\
${S}/modules/hal/wurthelektronik\;\
${S}/modules/hal/xtensa\;\
${S}/modules/hal/libmetal\;\
${S}/modules/lib/liblc3\;\
${S}/modules/fs/littlefs\;\
${S}/modules/lib/loramac-node\;\
${S}/modules/lib/gui/lvgl\;\
${S}/modules/lib/lz4\;\
${S}/modules/crypto/mbedtls\;\
${S}/bootloader/mcuboot\;\
${S}/modules/debug/mipi-sys-t\;\
${S}/modules/lib/nanopb\;\
${S}/tools/net-tools\;\
${S}/modules/bsim_hw_models/nrf_hw_models\;\
${S}/modules/lib/open-amp\;\
${S}/modules/lib/openthread\;\
${S}/modules/lib/picolibc\;\
${S}/modules/debug/segger\;\
${S}/modules/audio/sof\;\
${S}/modules/lib/tflite-micro\;\
${S}/modules/crypto/tinycrypt\;\
${S}/modules/debug/TraceRecorder\;\
${S}/modules/tee/tf-m/trusted-firmware-m\;\
${S}/modules/tee/tf-a/trusted-firmware-a\;\
${S}/modules/tee/tf-m/tf-m-tests\;\
${S}/modules/tee/tf-m/psa-arch-tests\;\
${S}/modules/lib/uoscore-uedhoc\;\
${S}/modules/lib/zcbor\;\
${S}/modules/lib/zscilib\;\
${S}/modules/lib/thrift\;\
"

ZEPHYR_BRANCH = "v3.3-branch"
PV = "3.3.0+git${SRCPV}"
