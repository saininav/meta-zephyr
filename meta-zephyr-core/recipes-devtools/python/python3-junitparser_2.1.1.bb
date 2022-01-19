# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python junitparser"
HOMEPAGE = "https://pypi.org/project/junitparser"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=2d00702cde917dd61c41041bc30136dd"

inherit pypi setuptools3

PYPI_PACKAGE = "junitparser"
SRC_URI[md5sum] = "f8704c2b18e6f4d482c62b33e141a0cb"
SRC_URI[sha256sum] = "d54d0eaa2b15ee2efab0220ce0ab31448d26dcb78170d5667453d7755b9f1480"
BBCLASSEXTEND = "native nativesdk"
