require recipes-browser/wpewebkit/wpewebkit.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:${THISDIR}/../../../meta-webkit/recipes-browser/wpewebkit/wpewebkit:"
SRC_URI = "https://wpewebkit.org/releases/${PN}-${PV}.tar.xz \
           file://0001-REGRESSION-r217927-WPE-2.22-GSTREAMER_GL-Video-appea.patch \
          "

SRC_URI[md5sum] = "7b768bfae1295ebbc9a9038bf8fb6e6c"
SRC_URI[sha256sum] = "d5e7b23e4f9e9f1b9d369faa4d527cdb59aef56b3e6a50a16dad243df5f699f3"

DEPENDS += " libwpe"
RCONFLICTS_${PN} = "wpebackend (< 1.0) wpebackend-fdo (< 1.0)"
