require recipes-devtools/binutils/binutils.inc
require binutils-2.26arc.inc
require recipes-devtools/binutils/binutils-cross.inc

SRC_URI_remove = "file://no-tooldirpaths.patch"

#COMPATIBLE_MACHINE = "arc"
