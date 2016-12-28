require zephyr-image.inc
require zephyr-kernel-test.inc

BBCLASSEXTEND = '${@" ".join(["zephyrtest:" + x for x in d.getVar("ZEPHYRTESTS", True).split()])}'




