# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python colorama"
HOMEPAGE = "https://pypi.org/project/colorama"
DESCRIPTION = "Makes ANSI escape character sequences (for producing colored \
               terminal text and cursor positioning) work under MS Windows."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=b4936429a56a652b84c5c01280dcaa26"

inherit pypi setuptools3

PYPI_PACKAGE = "colorama"
SRC_URI[md5sum] = "57b22f2597f63df051b69906fbf310cc"
SRC_URI[sha256sum] = "5941b2b48a20143d2267e95b1c2a7603ce057ee39fd88e7329b0c292aa16869b"
BBCLASSEXTEND = "native nativesdk"
