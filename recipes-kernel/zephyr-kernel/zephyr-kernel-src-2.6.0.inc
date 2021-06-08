SRCREV_FORMAT = "default_cmsis"
SRCREV_default = "79a6c07536bc14583198f8e3555df6134d8822cf"
SRCREV_cmsis = "c3bd2094f92d574377f7af2aec147ae181aa5f8e"
SRCREV_nordic = "574493fe29c79140df4827ab5d4a23df79d03681"
SRCREV_stm32 = "f8ff8d25aa0a9e65948040c7b47ec67f3fa300df"
SRCREV_open-amp = "6010f0523cbc75f551d9256cf782f173177acdef"
SRCREV_libmetal = "39d049d4ae68e6f6d595fce7de1dcfc1024fb4eb"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"

PV = "2.6.0+git${SRCPV}"

SRC_URI_append = " file://0001-x86-fix-efi-binary-generation-issue-in-cross-compila.patch \
            "
