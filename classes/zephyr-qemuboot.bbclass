inherit qemuboot

KERNEL_IMAGETYPE = "${PN}.elf"
QB_DEFAULT_FSTYPE = "elf"
QB_NETWORK_DEVICE =" none"

IMAGE_LINK_NAME = "${PN}-image-${MACHINE}"

# Create a link with "-image-" in the name just to keep runqemu happy
QEMU_IMAGE_LINK = "${DEPLOY_DIR_IMAGE}/${PN}-image-${MACHINE}.elf"

# qemuboot writes into IMGDEPLOYDIR, force to write to DEPLOY_DIR_IMAGE
IMGDEPLOYDIR = "${DEPLOY_DIR_IMAGE}"

CLEANFUNCS += "bootconf_clean"

python bootconf_clean() {
    import glob
    files = glob.glob(d.getVar('IMGDEPLOYDIR', True)+'/'+ d.getVar('PN', True) + '*.qemuboot.conf')
    for f in files:
        os.remove(f)

    qemuimage_link = d.getVar('QEMU_IMAGE_LINK', True)
    if os.path.lexists(qemuimage_link):
        os.remove(qemuimage_link)
}

python do_bootconf_write() {
    bb.build.exec_func("do_write_qemuboot_conf", d)

    qemuimage = "%s/%s.elf" % (d.getVar('DEPLOY_DIR_IMAGE', True), d.getVar('PN', True))
    qemuimage_link = d.getVar('QEMU_IMAGE_LINK', True)
    if os.path.lexists(qemuimage_link):
        os.remove(qemuimage_link)
    os.symlink(os.path.basename(qemuimage), qemuimage_link)
}

addtask do_bootconf_write before do_build after do_deploy
