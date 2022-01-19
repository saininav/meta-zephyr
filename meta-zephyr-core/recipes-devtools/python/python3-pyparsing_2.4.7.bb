# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python pyparsing"
HOMEPAGE = "https://pypi.org/project/pyparsing"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=657a566233888513e1f07ba13e2f47f1"

inherit pypi setuptools3

PYPI_PACKAGE = "pyparsing"
SRC_URI[md5sum] = "f0953e47a0112f7a65aec2305ffdf7b4"
SRC_URI[sha256sum] = "c203ec8783bf771a155b207279b9bccb8dea02d8f0c9e5f8ead507bc3246ecc1"
BBCLASSEXTEND = "native nativesdk"
