# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Zephyr RTOS Project meta-tool"
HOMEPAGE = "https://github.com/zephyrproject-rtos/west"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=e3fc50a88d0a364313df4b21ef20c29e"

SRC_URI = "git://github.com/zephyrproject-rtos/west;protocol=https;branch=main"

PV = "0.12.99"
SRCREV = "38e656b05ea8f4c8d80b953f6d88b1ed604d11f8"
PROVIDES = "virtual/west"

S = "${WORKDIR}/git"

inherit setuptools3 python3native

DEPENDS_${PN} += "python3-pyyaml python3-core python3-packaging python3-colorama python3-pyparsing"
RDEPENDS_${PN} += "python3-pyyaml python3-core python3-packaging python3-colorama python3-pyparsing"
BBCLASSEXTEND = "native nativesdk"
TOOLCHAIN_HOST_TASK:append = " nativesdk-west"
