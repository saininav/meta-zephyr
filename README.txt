Building Zephyr Images via bitbake recipes
==========================================

Prerequisites:

Modify local conf by adding:
    DISTRO="zephyr"

Add "meta-zephyr" to BBLAYERS


Building and Running Zephyr tests
=================================
Presently only toolchains for ARM and x86 are supported.
(For ARM we use CortexM3 toolchain)
The toolchain is selected via the MACHINE variable:

MACHINE=qemux86 : selects x86 toolchain
MACHINE=qemuarm : selects ARM CortexM3 toolchain

Default Zephyr BOARD is selected as follows:

BOARD_arm ?= "qemu_cortex_m3"
BOARD_x86 ?= "qemu_x86"

You can build and test an individual existing Zephyr test.
This is done by appending the actual test name to the "zephyr-kernel-test",
for example:

    $ MACHINE=qemux86 bitbake zephyr-kernel-test-test_sleep
    $ MACHINE=qemux86 bitbake zephyr-kernel-test-test_sleep -ctestimage

You can also build and run all Zephyr existing tests (as slisted in the file
zephyr-kernel-test.inc). For example:
    $ MACHINE=qemux86 bitbake zephyr-kernel-test-all
    $ MACHINE=qemux86 bitbake zephyr-kernel-test-all -ctestimage
or 
    $ MACHINE=qemuarm bitbake zephyr-kernel-test-all
    $ MACHINE=qemuarm bitbake zephyr-kernel-test-all -ctestimage
    


Building and Running Zephyr Samples
===================================    
You can also build Zephyr samples. There is a sample recipe that builds
Zephyr "philosophers" sample:
    
    $ MACHINE=qemux86 bitbake zephyr-philosophers
    
You can run the created "philosophers" image in qemu (at this point
the various paths have to be entered manually):

    $ ./tmp/sysroots/x86_64-linux/usr/bin/qemu-system-i386 \
           -kernel ./tmp/deploy/images/qemux86/philosophers.elf \
           -nographic -machine type=pc-0.14 -display none -clock dynticks \
           -no-acpi -balloon none

The same sample, for ARM image:
    $ MACHINE=qemuarm bitbake zephyr-philosophers
    $ ./tmp/sysroots/x86_64-linux/usr/bin/qemu-system-arm  \
           -kernel ./tmp/deploy/images/qemuarm/philosophers.elf \
           -cpu cortex-m3 -machine lm3s6965evb -nographic -vga none

