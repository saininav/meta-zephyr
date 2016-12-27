LICENSE = "CLOSED"
INHIBIT_DEFAULT_DEPS = "1"

require zephyr-kernel-test-micro.inc
require zephyr-kernel-test-nano.inc

addtask testimage
deltask configure
deltask compile
deltask install

do_testimage () {
	:
}

do_testimage[depends] = '${@" ".join(["zephyr-kernel-test-micro-" + x + ":do_testimage" for x in d.getVar("ZEPHYRMICROTESTS", True).split()])}'
do_testimage[depends] += '${@" ".join(["zephyr-kernel-test-nano-" + x + ":do_testimage" for x in d.getVar("ZEPHYRNANOTESTS", True).split()])}'

do_build[depends] = '${@" ".join(["zephyr-kernel-test-micro-" + x + ":do_build" for x in d.getVar("ZEPHYRMICROTESTS", True).split()])}'
do_build[depends] += '${@" ".join(["zephyr-kernel-test-nano-" + x + ":do_build" for x in d.getVar("ZEPHYRNANOTESTS", True).split()])}'
