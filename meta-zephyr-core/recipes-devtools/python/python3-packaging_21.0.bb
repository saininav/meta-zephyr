# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python packaging"
HOMEPAGE = "https://pypi.org/project/packaging"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=faadaedca9251a90b205c9167578ce91"

inherit pypi setuptools3

PYPI_PACKAGE = "packaging"
SRC_URI[md5sum] = "240ba5823ed31051a1254e74c9d18d55"
SRC_URI[sha256sum] = "7dc96269f53a4ccec5c0670940a4281106dd0bb343f47b7471f779df49c2fbe7"
BBCLASSEXTEND = "native nativesdk"
