Building Zephyr Images via bitbake recipes
==========================================

More detailed and up-to-date information can be found here:

https://wiki.yoctoproject.org/wiki/TipsAndTricks/BuildingZephyrImages

Prerequisites:
==============

This layer depends on:
    Yocto distro (master)
        git://git.yoctoproject.org/poky
    Python layer (meta-openembedded/meta-python)
        git://git.openembedded.org/meta-openembedded

Modify local conf by adding:
    DISTRO="zephyr"

Add "meta-openembedded/meta-oe" to BBLAYERS
Add "meta-openembedded/meta-python" to BBLAYERS
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

Flashing
=================================

You can flash Zephyr samples to boards. Currently, the following MACHINEs
are supported:
 * DFU:
  - arduino-101-sss
  - arduino-101
  - arduino-101-ble
 * pyocd:
  - 96b-nitrogen

To flash the example you built with command e.g.

    $ MACHINE=96b-nitrogen bitbake zephyr-philosophers

call similar command with explicit flash_usb command:

    $ MACHINE=96b-nitrogen bitbake zephyr-philosophers -c flash_usb

dfu-util and/or pyocd need to be installed in your system. If you observe
permission errors or the flashing process seem to hang, follow those instructions:
https://github.com/pyocd/pyOCD/tree/master/udev

Building and Running Zephyr Tests
=================================
Presently only toolchains for ARM, x86, IAMCU and Nios2 are supported.
(For ARM we use CortexM3 toolchain)

To run Zephyr Test using Yocto Image Tests, ensure following in local.conf:

    INHERIT += "testimage"

You can build and test an individual existing Zephyr test.
This is done by appending the actual test name to the "zephyr-kernel-test",
for example:

    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-sleep
    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-sleep -c testimage

You can also build and run all Zephyr existing tests (as listed in the file
zephyr-kernel-test.inc). For example:

    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-all
    $ MACHINE=qemu-x86 bitbake zephyr-kernel-test-all -c testimage
or 
    $ MACHINE=qemu-cortex-m3 bitbake zephyr-kernel-test-all
    $ MACHINE=qemu-cortex-m3 bitbake zephyr-kernel-test-all -c testimage
or 
    $ MACHINE=qemu-nios2 bitbake zephyr-kernel-test-all
    $ MACHINE=qemu-nios2 bitbake zephyr-kernel-test-all -c testimage
        

Contributing
============

Patches for meta-zephyr should be sent to the yocto@lists.yoctoproject.org
mailing list.  See https://lists.yoctoproject.org/g/yocto for subscription
details and the list archive.  Please add [meta-zephyr] to the subject so
the patches are identifable.

Git can be configured to send mails appropriately when using git send-email:

$ git config --local sendemail.to yocto@lists.yoctoproject.org
$ git config --local format.subjectPrefix meta-zephy][PATCH
