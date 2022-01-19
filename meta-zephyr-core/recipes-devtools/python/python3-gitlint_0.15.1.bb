# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python gitlint"
HOMEPAGE = "https://pypi.org/project/gitlint"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=2ddf75221dde30f107af8595a43b4009"

inherit pypi setuptools3

PYPI_PACKAGE = "gitlint"
SRC_URI[md5sum] = "4835bedc50129934a47cf099d906d2ca"
SRC_URI[sha256sum] = "4b22916dcbdca381244aee6cb8d8743756cfd98f27e7d1f02e78733f07c3c21c"
BBCLASSEXTEND = "native nativesdk"
