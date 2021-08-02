require recipes-devtools/binutils/binutils.inc
require binutils-2.26arc.inc
require recipes-devtools/binutils/binutils-cross.inc

SRC_URI:remove = "file://no-tooldirpaths.patch"
SRC_URI:remove = "file://0002-binutils-cross-Do-not-generate-linker-script-directo.patch"

#COMPATIBLE_MACHINE = "arc"
