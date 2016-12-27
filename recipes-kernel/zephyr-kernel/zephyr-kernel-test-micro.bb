require zephyr-image.inc
require zephyr-kernel-test-micro.inc

BBCLASSEXTEND = '${@" ".join(["zephyrtest:" + x for x in d.getVar("ZEPHYRMICROTESTS", True).split()])}'




