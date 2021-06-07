SRCREV_FORMAT = "default_cmsis"
SRCREV_default = "fe7c2efca800a0cf1bccf23aefe08b3c4beb88bf"
SRCREV_cmsis = "c3bd2094f92d574377f7af2aec147ae181aa5f8e"
SRCREV_nordic = "f3434da6446380fcdd426dbe2866af21d0d549b6"
SRCREV_stm32 = "cc8731dba4fd9c57d7fe8ea6149828b89c2bd635"
SRCREV_open-amp = "de1b85a13032a2de1d8b6695ae5f800b613e739d"
SRCREV_libmetal = "9d4ee2c3cfd5f49861939447990f3b7d7bf9bf94"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"
SRCREV_mbedtls = "24d84ecff195fb15c889d9046e44e4804d626c67"

PV = "2.5.0+git${SRCPV}"

SRC_URI_append = " file://0001-x86-fix-efi-binary-generation-issue-in-cross-compila.patch \
            "
