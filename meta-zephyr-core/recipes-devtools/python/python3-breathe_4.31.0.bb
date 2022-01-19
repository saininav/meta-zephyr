# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python breathe"
DESCRIPTION = "Breathe is an extension to reStructuredText and Sphinx to be \
               able to read and render Doxygen xml output."
HOMEPAGE = "https://pypi.org/project/breathe"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=9e49eecf36fc015de7c61a0247df75d6"

inherit pypi setuptools3
 
DEPENDS = "python3-sphinx-native python3-docutils-native python3-pygments-native python3-babel-native python3-jinja2-native python3-distro-native"
PYPI_PACKAGE = "breathe"
SRC_URI[md5sum] = "33a86368215dbcb59e5c71687f6b228b"
SRC_URI[sha256sum] = "925eeff96c6640cd857e4ddeae6f75464a1d5e2e08ee56dccce4043583ae2050"
BBCLASSEXTEND = "native nativesdk"
