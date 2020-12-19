require wpewebkit.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI = "\
    https://wpewebkit.org/releases/${BPN}-${PV}.tar.xz \
"
SRC_URI[sha256sum] = "1e521d85cf8cf344b9fd08eabad7a1d18a330fb7862a77eaf78d7d7b10d5f6ef"

DEPENDS += " libwpe"
RCONFLICTS_${PN} = "libwpe (< 1.4) wpebackend-fdo (< 1.6)"

