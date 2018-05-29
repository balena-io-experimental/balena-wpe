FILESEXTRAPATHS_append := ":${THISDIR}/files"

SRC_URI_append = " \
    file://0001-platform-make-gstreamer-audio-sink-configurable.patch \
    file://0001-Add-required-parseLocationQueryParameters-function-b.patch \
    file://0001-Workaround-to-use-correct-WebInspector-resource-path.patch \
"

PACKAGECONFIG_append += " touch"
