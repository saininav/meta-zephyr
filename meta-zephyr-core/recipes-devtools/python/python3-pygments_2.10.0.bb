# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python pygments"
HOMEPAGE = "https://pypi.org/project/Pygments/"
DESCRIPTION = "Pygments is a syntax highlighting package written in Python."
LICENSE = "BSD-2-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=e3fc50a88d0a364313df4b21ef20c29e"
SRC_URI = "https://files.pythonhosted.org/packages/b7/b3/5cba26637fe43500d4568d0ee7b7362de1fb29c0e158d50b4b69e9a40422/Pygments-2.10.0.tar.gz"

inherit pypi setuptools3

PYPI_PACKAGE = "Pygments"
SRC_URI[md5sum] = "87369a4e15019caf9cf056ab2c5858b3"
BBCLASSEXTEND = "native nativesdk"
