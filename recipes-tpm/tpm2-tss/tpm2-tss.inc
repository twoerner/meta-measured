SUMMARY = "The TCG TPM2 Software Stack"
DESCRIPTION = "The TCG (Trusted Computing Group) Software Stack (TSS) \
provides a standard API for accessing the functions of the TPM. \
Application developers can use this software to develop interoperable \
client applications."
HOMEPAGE = "https://github.com/tpm2-software/tpm2-tss"
SECTION = "security/tpm"

LICENSE = "BSD-2-Clause"
LIC_FILES_CHKSUM = "file://${S}/LICENSE;md5=500b2e742befc3da00684d8a1d5fd9da"

SRC_URI = "https://github.com/tpm2-software/${BPN}/releases/download/${PV}/${BPN}-${PV}.tar.gz"

DEPENDS = "autoconf-archive-native"

S = "${WORKDIR}/${BPN}-${PV}"

PROVIDES = "${PACKAGES}"
PACKAGES = " \
    ${PN}-dbg \
    ${PN}-doc \
    libtss2 \
    libtss2-dev \
    libtss2-staticdev \
    libtctidevice \
    libtctidevice-dev \
    libtctidevice-staticdev \
    libtctisocket \
    libtctisocket-dev \
    libtctisocket-staticdev \
"

FILES_libtss2 = " \
    ${libdir}/libsapi.so.* \
    ${libdir}/libmarshal.so.* \
"
FILES_libtss2-dev = " \
    ${includedir}/sapi \
    ${includedir}/tcti/common.h \
    ${libdir}/libmarshal.so \
    ${libdir}/libsapi.so \
    ${libdir}/pkgconfig/sapi.pc \
    ${libdir}/pkgconfig/marshal.pc \
"
FILES_libtss2-staticdev = " \
    ${libdir}/libmarshal.a \
    ${libdir}/libmarshal.la \
    ${libdir}/libsapi.a \
    ${libdir}/libsapi.la \
"
FILES_libtctidevice = "${libdir}/libtcti-device.so.*"
FILES_libtctidevice-dev = " \
    ${includedir}/tcti/tcti_device.h \
    ${libdir}/libtcti-device.so \
    ${libdir}/pkgconfig/tcti-device.pc \
"
FILES_libtctidevice-staticdev = "${libdir}/libtcti-device.*a"
FILES_libtctisocket = "${libdir}/libtcti-socket.so.*"
FILES_libtctisocket-dev = " \
    ${includedir}/tcti/tcti_socket.h \
    ${libdir}/libtcti-socket.so \
    ${libdir}/pkgconfig/tcti-socket.pc \
"
FILES_libtctisocket-staticdev = "${libdir}/libtcti-socket.*a"

inherit autotools pkgconfig
