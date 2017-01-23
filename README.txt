Building Zephyr Images via bitbake recipes
==========================================

Prerequisites:

Yocto distro "morty"

Modify local conf by adding:
    DISTRO="zephyr"

Add "meta-zephyr" to BBLAYERS


Building and Running Zephyr tests
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
        


Building and Running Zephyr Samples
===================================    
You can also build Zephyr samples. There is a sample recipe that builds
Zephyr "philosophers" sample:
    
    $ MACHINE=qemu-x86 bitbake zephyr-philosophers
    
You can run the created "philosophers" image in qemu (at this point
the various paths have to be entered manually):

    $ ./tmp/sysroots/x86_64-linux/usr/bin/qemu-system-i386 \
           -kernel ./tmp/deploy/images/qemu-x86/philosophers.elf \
           -nographic -machine type=pc-0.14 -display none -clock dynticks \
           -no-acpi -balloon none

The same sample, for ARM image:
    $ MACHINE=qemu-cortex-m3 bitbake zephyr-philosophers
    $ ./tmp/sysroots/x86_64-linux/usr/bin/qemu-system-arm  \
           -kernel ./tmp/deploy/images/qemu-cortex-m3/philosophers.elf \
           -cpu cortex-m3 -machine lm3s6965evb -nographic -vga none

The same sample, for Nios2 image:
    $ MACHINE=qemu-nios2 bitbake zephyr-philosophers
    $ ./tmp/sysroots/x86_64-linux/usr/bin/qemu-system-nios2  \
           -kernel ./tmp/deploy/images/qemu-nios2/philosophers.elf \
           -cpu nios2 -machine altera_10m50_zephyr -nographic

