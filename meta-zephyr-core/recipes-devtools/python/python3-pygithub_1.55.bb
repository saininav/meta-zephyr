# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python PyGithub"
HOMEPAGE = "https://pypi.org/project/PyGithub"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://MANIFEST.in;md5=c5e8b6057f82b73046c24a30809903bd"

inherit pypi setuptools3

PYPI_PACKAGE = "PyGithub"
SRC_URI[md5sum] = "03e5883a8d4358b0786a0db84ad56a22"
SRC_URI[sha256sum] = "1bbfff9372047ff3f21d5cd8e07720f3dbfdaf6462fcaed9d815f528f1ba7283"
BBCLASSEXTEND = "native nativesdk"
