# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python lpc_checksum"
HOMEPAGE = "https://pypi.org/project/lpc_checksum"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=85c86965b0249c221935f585c0313d60"

inherit pypi setuptools3

PYPI_PACKAGE = "lpc_checksum"
SRC_URI[md5sum] = "eef81888414a111e1fd5992b8614b6cb"
SRC_URI[sha256sum] = "1f2fb198483cc718141f1aa0ed4717fd188e29874d7db0409d1ed04358b64185"
BBCLASSEXTEND = "native nativesdk"
