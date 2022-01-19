# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python junit2html"
HOMEPAGE = "https://pypi.org/project/junit2html"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://MANIFEST.in;md5=899c50bccc6c8221c8ca0a9c7633b5b8"

inherit pypi setuptools3

PYPI_PACKAGE = "junit2html"
SRC_URI[md5sum] = "a816cf502da0a8905f24aefab0739206"
SRC_URI[sha256sum] = "9b3967c92142abd5fb94e2cbb938c51cc6c2689ec1c7fd348c6ba4ddab92da14"
BBCLASSEXTEND = "native nativesdk"
