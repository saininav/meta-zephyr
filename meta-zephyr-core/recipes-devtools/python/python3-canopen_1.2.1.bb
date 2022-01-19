# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python canopen"
DESCRIPTION = "A Python implementation of the CANopen standard. The aim of \
               the project is to support the most common parts of the CiA \
               301 standard in a simple Pythonic interface."
HOMEPAGE = "https://pypi.org/project/canopen"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=97f135a6ee6f800c377b5512122c7a8d"

inherit pypi setuptools3

PYPI_PACKAGE = "canopen"
SRC_URI[md5sum] = "da37dcf725e774385f05f05e04ca54a0"
SRC_URI[sha256sum] = "18d01d56ff0023795cb336cafd4810a76cf402b98b42139b201fa8c5d4ba8c06"
BBCLASSEXTEND = "native nativesdk"
