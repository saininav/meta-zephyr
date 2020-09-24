SUMMARY = "Create zephyr.img having grub, application image and grub config"
LICENSE = "CLOSED"
inherit deploy
do_deploy[depends] += "dosfstools-native:do_populate_sysroot \
                        mtools-native:do_populate_sysroot \
                        "

SRC_URI = "file://grub.cfg"
DEPENDS += " zephyr-grub-efi"

COMPATIBLE_HOST = '(x86_64.*|i.86.*)-linux.*'
COMPATIBLE_MACHINE = "genericx86|genericx86-64"

EFI_BOOT_IMAGE_NAME_genericx86-64 = "bootx64.efi"
EFI_BOOT_IMAGE_NAME_genericx86 = "bootia32.efi"


#Below variables must be set in local.conf
CONTAINER_PACKAGE_DEPLOY_DIR ??=""
CONTAINER_PACKAGE_ZEPHYR_APP_DEPLOY_DIR ??=""
CONTAINER_PACKAGE_MC ?= "x86"
ZEPHYR_APP ??=""

do_deploy[mcdepends] += " multiconfig::${CONTAINER_PACKAGE_MC}:zephyr-grub-efi:do_deploy"

do_deploy () {
    if [ -d ${DEPLOYDIR}/efi ]; then
        rm -r ${DEPLOYDIR}/efi
    fi

    if [ -d ${DEPLOYDIR}/kernel ]; then
        rm -r ${DEPLOYDIR}/kernel
    fi
    if [ -e ${DEPLOYDIR}/zephyr-image-${ZEPHYR_APP}.img ]; then
        rm ${DEPLOYDIR}/zephyr-image-${ZEPHYR_APP}.img
    fi

    mkdir ${DEPLOYDIR}/efi
    mkdir ${DEPLOYDIR}/kernel
    mkdir ${DEPLOYDIR}/efi/boot
    cp ${CONTAINER_PACKAGE_DEPLOY_DIR}/grub-efi-${EFI_BOOT_IMAGE_NAME} ${DEPLOYDIR}/efi/boot/${EFI_BOOT_IMAGE_NAME}
    cp ${CONTAINER_PACKAGE_ZEPHYR_APP_DEPLOY_DIR}/${ZEPHYR_APP}.elf ${DEPLOYDIR}/kernel/zephyr.elf
    cp ${WORKDIR}/grub.cfg ${DEPLOYDIR}/efi/boot/
    mkdosfs -F 32 -C ${DEPLOYDIR}/zephyr-image-${ZEPHYR_APP}.img 35840
    mcopy -i ${DEPLOYDIR}/zephyr-image-${ZEPHYR_APP}.img -s ${DEPLOYDIR}/efi ${DEPLOYDIR}/kernel ::/
    chmod 644 ${DEPLOYDIR}/zephyr-image-${ZEPHYR_APP}.img
    rm -rf ${DEPLOYDIR}/kernel ${DEPLOYDIR}/efi
}

addtask deploy after do_compile
do_install[noexec] = "1"
