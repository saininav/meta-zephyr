require zephyr-image.inc
require zephyr-kernel-test-nano.inc

BBCLASSEXTEND = '${@" ".join(["zephyrtest:" + x for x in d.getVar("ZEPHYRNANOTESTS", True).split()])}'
