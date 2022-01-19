# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python pyocd"
HOMEPAGE = "https://pypi.org/project/pyocd"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=421492e27872cb498685e9d7649f63a2"

inherit pypi setuptools3

PYPI_PACKAGE = "pyocd"
SRC_URI[md5sum] = "25153f563a629bb2be7560e2dc23c0a8"
SRC_URI[sha256sum] = "d5aa498130f251373ac50724be73dc2f8cf60b03c9547bddf3c140fa6555ead1"
BBCLASSEXTEND = "native nativesdk"
