Overview
--------

Build zephyr sample application, GRUB bootloader and pack them into *.img and boot.

Dependencies
------------

This layer depends on:

| meta layer        | git repository                                 |
|-------------------|------------------------------------------------|
| poky              | https://git.yoctoproject.org/git/poky          |
| meta-zephyr       | https://git.yoctoproject.org/git/meta-zephyr   |
| meta-openembedded | https://git.openembedded.org/meta-openembedded |

Add meta-openembedded/meta-oe and meta-openembedded/meta-python to bblayer.conf

Configuration
-------------

############################################################################################

Append below configuration to local.conf as follows:

```
# Multiconfig build configuration
BBMULTICONFIG = "x86 zephyr"

```
############################################################################################

Configure `conf/multiconfig/x86.conf` as follows:

```
MACHINE= "genericx86"
DISTRO="poky"
TMPDIR = "${TOPDIR}/master-zephyr-image"
CONTAINER_PACKAGE_DEPLOY_DIR = "${TMPDIR}/deploy/images/${MACHINE}"
CONTAINER_PACKAGE_MC = "x86"

# Below sould be in sync with conf/multiconfig/zepyr.conf
ZEPHYR_MACHINE = "minnowboard"
CONTAINER_PACKAGE_ZEPHYR_APP_DEPLOY_DIR = "${TOPDIR}/master-zephyr-app/deploy/images/${ZEPHYR_MACHINE}"
# Zephyr sample to be build
ZEPHYR_APP = "zephyr-helloworld"
```
############################################################################################

Configure `conf/multiconfig/zephyr.conf` as follows:

```
MACHINE= "minnowboard"
DISTRO = "zephyr"
TMPDIR="${TOPDIR}/master-zephyr-app"
```
############################################################################################

Note: Remember to keep TMPDIR in sync.


Build
-----


```
    $ bitbake mc:zephyr:zephyr-helloworld && bitbake mc:x86:zephyr-image-app
```
Replace zephyr-helloworld, with the sample which you want to build.

On success of build, zephyr-image-${ZEPHYR_APP}.img can be find at ${TOPDIR}/master-zephyr-image/deploy/images/${MACHINE}/

Prepare Boot device
-------------------

```
    $ sudo dd if=zephyr-image-${ZEPHYR_APP}.img of=/dev/xxx status=progress
    $ sync
    $ eject /dev/xxx

```


Boot
----

Insert the boot device into the MinnowBoard XM, and power on.  You should see the running sample on Serial Port.

To use the Serial port you need these cables:
http://www.ftdichip.com/Products/Cables/USBTTLSerial.htm

https://docs.zephyrproject.org/latest/boards/x86/minnowboard/doc/index.html#booting-zephyr-on-the-minnowboard
