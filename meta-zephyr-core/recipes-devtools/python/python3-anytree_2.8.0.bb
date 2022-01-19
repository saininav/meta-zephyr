# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python anytree"
DESCRIPTION = "Powerful and Lightweight Python Tree Data Structure"
HOMEPAGE = "https://pypi.org/project/anytree"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=e3fc50a88d0a364313df4b21ef20c29e"

inherit pypi setuptools3

PYPI_PACKAGE = "anytree"
SRC_URI[md5sum] = "25ef3e656ad16a2a6b6c187807da7e5f"
BBCLASSEXTEND = "native nativesdk"
