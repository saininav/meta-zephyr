# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python imgtool"
HOMEPAGE = "https://pypi.org/project/imgtool"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://setup.cfg;md5=3f78c6150b7d619a476c799812e31d5a"

inherit pypi setuptools3

PYPI_PACKAGE = "imgtool"
SRC_URI[md5sum] = "08fe63c644977aa8f9e6038e2067c3de"
SRC_URI[sha256sum] = "799484f3f61e398ac4157548f309b6baa4084e464176449694ba9de7909eed6e"
BBCLASSEXTEND = "native nativesdk"
