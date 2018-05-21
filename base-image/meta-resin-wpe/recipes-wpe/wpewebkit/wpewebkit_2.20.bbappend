FILESEXTRAPATHS_append := ":${THISDIR}/files"

SRC_URI_append = " \
    file://0001-platform-make-gstreamer-audio-sink-configurable.patch \
"

PACKAGECONFIG_append += " touch"
