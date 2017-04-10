Building Zephyr Images via bitbake recipes
==========================================

More detailed and up-to-date information can be found here:

https://wiki.yoctoproject.org/wiki/TipsAndTricks/BuildingZephyrImages

Prerequisites:
==============

Yocto distro (master)"

Modify local conf by adding:
    DISTRO="zephyr"

Add "meta-zephyr" to BBLAYERS

Building and Running Zephyr Samples
===================================

You can build Zephyr samples. There are several sample recipes.
For example, to build the Zephyr "philosophers" sample:
    
    $ MACHINE=qemu-x86 bitbake zephyr-philosophers
    
You can then run the created "philosophers" image in qemu:

    $ runqemu qemu-x86
    
The same sample, for ARM image:

    $ MACHINE=qemu-cortex-m3 bitbake zephyr-philosophers
    $ runqemu qemu-cortex-m3
    
The same sample, for Nios2 image:

    $ MACHINE=qemu-nios2 bitbake zephyr-philosophers
    $ runqemu qemu-nios2


Building and Running Zephyr Tests
=================================
Presently only toolchains for ARM, x86, IAMCU and Nios2 are supported.
(For ARM we use CortexM3 toolchain)

You can build and test an individual existing Zephyr test.
This is done by appending the actual test name to the "zephyr-kernel-test",
for example:

    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-test_sleep
    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-test_sleep -ctestimage

You can also build and run all Zephyr existing tests (as listed in the file
zephyr-kernel-test.inc). For example:

    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-all
    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-all -ctestimage
or 
    $ MACHINE=qemu-cortex-m3 bitbake zephyr-kernel-test-all
    $ MACHINE=qemu-cortex-m3 bitbake zephyr-kernel-test-all -ctestimage
or 
    $ MACHINE=qemu-nios2 bitbake zephyr-kernel-test-all
    $ MACHINE=qemu-nios2 bitbake zephyr-kernel-test-all -ctestimage
        


