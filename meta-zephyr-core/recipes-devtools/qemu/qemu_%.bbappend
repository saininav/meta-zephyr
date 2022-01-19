FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

QEMU_TARGETS = ""

#SRC_URI += " \
#      file://nios2-add-support.patch \
#      "

EXTRA_OECONF:remove = "--target-list"

#QEMUS_BUILT = "arm-softmmu i386-softmmu nios2-softmmu"
QEMUS_BUILT = "arm-softmmu i386-softmmu"
EXTRA_OECONF:append = " --target-list="${QEMUS_BUILT}""
