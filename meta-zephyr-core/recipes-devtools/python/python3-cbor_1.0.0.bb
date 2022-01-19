# SPDX-FileCopyrightText: Huawei Inc.
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Python cbor"
DESCRIPTION = "An implementation of RFC 7049 - Concise Binary Object \
               Representation (CBOR). \
               CBOR is comparable to JSON, has a superset of JSON’s ability, \
               but serializes to a binary format which is smaller and faster \
               to generate and parse."
HOMEPAGE = "https://pypi.org/project/cbor"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://setup.cfg;md5=d86758afb08a60bc589dc67bfea670b2"

inherit pypi setuptools3

PYPI_PACKAGE = "cbor"
SRC_URI[md5sum] = "22b03b59784fd78cb6c27aa498af0db6"
SRC_URI[sha256sum] = "13225a262ddf5615cbd9fd55a76a0d53069d18b07d2e9f19c39e6acb8609bbb6"
BBCLASSEXTEND = "native nativesdk"
