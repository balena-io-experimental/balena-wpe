require wpewebkit.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI = "\
    https://wpewebkit.org/releases/${BPN}-${PV}.tar.xz \
"
SRC_URI[md5sum] = "c1f17d4b031e9462692443e3c089789c"
SRC_URI[sha256sum] = "6929d28744702ead3574484ca02645c457a6fdcd6b43ccc9766d98dc3664e8dc"

DEPENDS += " libwpe"
RCONFLICTS_${PN} = "libwpe (< 1.2) wpebackend-fdo (< 1.2)"

