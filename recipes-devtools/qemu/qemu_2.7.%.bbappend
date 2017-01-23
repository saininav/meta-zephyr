FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

QEMU_TARGETS = ""

SRC_URI += " \
      file://nios2-add-support.patch \
      "

EXTRA_OECONF_remove = "--target-list"

QEMUS_BUILT = "arm-softmmu i386-softmmu nios2-softmmu"
EXTRA_OECONF_append = " --target-list="${QEMUS_BUILT}""
