SRCREV_FORMAT = "default_cmsis"

#
# Generated with:
#
# #!/usr/bin/python3
#
# import yaml
# import sys
#
# if __name__ == "__main__":
#     with open(sys.argv[1], "r") as fd:
#         data = yaml.safe_load(fd)
#
#         for project in data["manifest"]["projects"]:
#             print("SRCREV_{} = \"{}\"".format(project["name"], project["revision"]))
#

SRCREV_default = "2ddd73feafd3316af2c547c34d6969bea637d5c6"
SRCREV_canopennode = "53d3415c14d60f8f4bfca54bfbc5d5a667d7e724"
SRCREV_chre = "0edfe2c2ec656afb910cfab8ed59a5ffd59b87c8"
SRCREV_civetweb = "094aeb41bb93e9199d24d665ee43e9e05d6d7b1c"
SRCREV_cmsis = "5f86244bad4ad5a590e084f0e72ba7a1416c2edf"
SRCREV_edtt = "1ea61a390d2bfcf3b2ecdba8f8b0b98dfdffbd11"
SRCREV_fatfs = "a30531af3a95a9a3ea7d771ea8a578ebfed45514"
SRCREV_fff = "6ce5ba26486e93d5b7696a3e23f0585932c14b16"
SRCREV_altera = "0d225ddd314379b32355a00fb669eacf911e750d"
SRCREV_atmel = "78c5567c05b6b434dd7d98f49156319df4217bac"
SRCREV_espressif = "df85671c5d0405c0747c2939c8dfe808b7e4cf38"
SRCREV_gigadevice = "63a72ca90b7e0d7257211ddc5c79e8c0b940371b"
SRCREV_infineon = "4af06965f57ba1e7d170e6a97d24c33785543a8c"
SRCREV_microchip = "5d079f1683a00b801373bbbbf5d181d4e33b30d5"
SRCREV_nordic = "a85bb3676d61d1ae202088e0d3fec556056b2c9e"
SRCREV_nuvoton = "b4d31f33238713a568e23618845702fadd67386f"
SRCREV_nxp = "2302a1e94f5bc00ce59db4e249b688ad2e959f58"
SRCREV_openisa = "40d049f69c50b58ea20473bee14cf93f518bf262"
SRCREV_quicklogic = "b3a66fe6d04d87fd1533a5c8de51d0599fcd08d0"
SRCREV_rpi_pico = "191f5ba46fda49523cdaaef27583d1c875ba2c36"
SRCREV_silabs = "be39d4eebeddac6e18e9c0c3ba1b31ad1e82eaed"
SRCREV_st = "52a522ca4a8a9ec1e9bb5bb514e1ab6f102863fe"
SRCREV_stm32 = "51b373cd3455b8c2b9babbf6ff41918116a442ac"
SRCREV_telink = "ffcfd6282aa213f1dc0848dbca6279b098f6b143"
SRCREV_ti = "905a5d4134899630071f9383aadaaf266e8f8cd2"
SRCREV_xtensa = "0e577021bb66e644afd067cd9f7c71ab11b62b3d"
SRCREV_libmetal = "850a3c3fd5bc655987021dc9106d8e8cd0f7e061"
SRCREV_liblc3codec = "3951cf1b71ff3be086c9b9b595e473e12301337c"
SRCREV_littlefs = "652f2c5646e79b881e6f3099686ad3b7af9e216c"
SRCREV_loramac-node = "12019623bbad9eb54fe51066847a7cbd4b4eac57"
SRCREV_lvgl = "df717ac87a9fd80246cc8df24554475e59bda21f"
SRCREV_lz4 = "8e303c264fc21c2116dc612658003a22e933124d"
SRCREV_mbedtls = "7fed49c9b9f983ad6416986661ef637459723bcb"
SRCREV_mcuboot = "e58ea98aec6e5539c5f872a98059e461d0155bbb"
SRCREV_mipi-sys-t = "a5163c1800a5243f8b05d84c942da008df4cb666"
SRCREV_nanopb = "d148bd26718e4c10414f07a7eb1bd24c62e56c5d"
SRCREV_net-tools = "f49bd1354616fae4093bf36e5eaee43c51a55127"
SRCREV_nrf_hw_models = "b8cea37dbdc8fc58cc14b4e19fa850877a9da520"
SRCREV_open-amp = "8d53544871e1f300c478224faca6be8384ab0d04"
SRCREV_openthread = "e2a765599aa0379d0f72f0149a9cbafec070c12d"
SRCREV_segger = "3a52ab222133193802d3c3b4d21730b9b1f1d2f6"
SRCREV_sof = "2efc3ea41c0074c6dab5f376fafaa26f52c25c75"
SRCREV_tflite-micro = "9156d050927012da87079064db59d07f03b8baf6"
SRCREV_tinycbor = "9e1f34bc08123aaad7666d3652aaa839e8178b3b"
SRCREV_tinycrypt = "3e9a49d2672ec01435ffbf0d788db6d95ef28de0"
SRCREV_TraceRecorderSource = "e8ca3b6a83d19b2fc4738a0d9607190436e5e452"
SRCREV_trusted-firmware-m = "7c53a6e76130a85303f83b15d868a92fdcd5f5be"
SRCREV_tf-m-tests = "c99a86b295c4887520da9d8402566d7f225c974e"
SRCREV_psa-arch-tests = "a81f9da287569f169d60026916952641b233faa8"
SRCREV_zcbor = "882c489a7d9fdfff31d27666914a78a9eb6976d7"
SRCREV_zscilib = "fc979a8dcb74169c69b02835927bff8f070d6325"

ZEPHYR_BRANCH = "v3.1-branch"
PV = "3.1.0+git${SRCPV}"

SRC_URI += " \
    file://0001-3.1-cmake-add-yocto-toolchain.patch;patchdir=zephyr \
    file://0001-3.1-x86-fix-efi-binary-generation-issue-in-cross-compila.patch;patchdir=zephyr \
"
