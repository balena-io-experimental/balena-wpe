SUMMARY = "WPE WebKit port pairs the WebKit engine with OpenGL-ES (OpenGL for Embedded Systems), \
           allowing embedders to create simple and performant systems based on Web platform technologies. \
           It is designed with hardware acceleration in mind, relying on EGL, and OpenGL ES."
HOMEPAGE = "https://trac.webkit.org/wiki/WPE"
BUGTRACKER = "https://bugs.webkit.org/"
LICENSE = "BSD & LGPLv2+"
LIC_FILES_CHKSUM = "file://Source/WebCore/LICENSE-LGPL-2.1;md5=a778a33ef338abbaf8b8a7c36b6eec80 "

DEPENDS = " \
    bison-native gperf-native harfbuzz-native libxml2-native ccache-native ninja-native ruby-native cairo \
    fontconfig freetype glib-2.0 gnutls harfbuzz icu jpeg pcre sqlite3 zlib libpng \
    libsoup-2.4 libwebp libxml2 libxslt virtual/egl virtual/libgles2 libepoxy libgcrypt \
"

inherit cmake pkgconfig perlnative python3native
inherit ${@'cmake_qt5' if 'qt5-layer' in d.getVar('BBFILE_COLLECTIONS').split() else ''}

CCACHE_DISABLE[unexport] = "1"

PACKAGECONFIG ??= "fetchapi indexeddb mediasource video webaudio webcrypto woff2 gst_gl remote-inspector openjpeg unified-builds service-worker \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'systemd', '' ,d)} \
                  "

# WPE features
PACKAGECONFIG[accessibility] = "-DENABLE_ACCESSIBILITY=ON,-DENABLE_ACCESSIBILITY=OFF,atk at-spi2-atk"
PACKAGECONFIG[bubblewrap] = "-DENABLE_BUBBLEWRAP_SANDBOX=ON,-DENABLE_BUBBLEWRAP_SANDBOX=OFF,bubblewrap xdg-dbus-proxy bubblewrap-native xdg-dbus-proxy-native libseccomp"
PACKAGECONFIG[developer-mode] = "-DDEVELOPER_MODE=ON,-DDEVELOPER_MODE=OFF,wayland-native wayland-protocols wpebackend-fdo"
PACKAGECONFIG[deviceorientation] = "-DENABLE_DEVICE_ORIENTATION=ON,-DENABLE_DEVICE_ORIENTATION=OFF,"
PACKAGECONFIG[encryptedmedia] = "-DENABLE_ENCRYPTED_MEDIA=ON,-DENABLE_ENCRYPTED_MEDIA=OFF,libgcrypt"
PACKAGECONFIG[fetchapi] = "-DENABLE_FETCH_API=ON,-DENABLE_FETCH_API=OFF,"
PACKAGECONFIG[gamepad] = "-DENABLE_GAMEPAD=ON,-DENABLE_GAMEPAD=OFF,"
PACKAGECONFIG[geolocation] = "-DENABLE_GEOLOCATION=ON,-DENABLE_GEOLOCATION=OFF,geoclue"
PACKAGECONFIG[gst_gl] = "-DUSE_GSTREAMER_GL=ON,-DUSE_GSTREAMER_GL=OFF,gstreamer1.0-plugins-base"
PACKAGECONFIG[indexeddb] = "-DENABLE_INDEXED_DATABASE=ON,-DENABLE_INDEXED_DATABASE=OFF,"
PACKAGECONFIG[mediasource] = "-DENABLE_MEDIA_SOURCE=ON,-DENABLE_MEDIA_SOURCE=OFF,gstreamer1.0 gstreamer1.0-plugins-good"
PACKAGECONFIG[service-worker] = "-DENABLE_SERVICE_WORKER=ON,-DENABLE_SERVICE_WORKER=OFF,"
PACKAGECONFIG[video] = "-DENABLE_VIDEO=ON -DENABLE_VIDEO_TRACK=ON,-DENABLE_VIDEO=OFF -DENABLE_VIDEO_TRACK=OFF,gstreamer1.0 gstreamer1.0-plugins-base"
PACKAGECONFIG[webaudio] = "-DENABLE_WEB_AUDIO=ON,-DENABLE_WEB_AUDIO=OFF,gstreamer1.0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good"
PACKAGECONFIG[webcrypto] = "-DENABLE_WEB_CRYPTO=ON,-DENABLE_WEB_CRYPTO=OFF,libgcrypt libtasn1"
PACKAGECONFIG[webgl2] = "-DENABLE_WEBGL2=ON,-DENABLE_WEBGL2=OFF,"
PACKAGECONFIG[woff2] = "-DUSE_WOFF2=ON,-DUSE_WOFF2=OFF,woff2"
# 2dcanvas requires cairo with opengl support. Try by setting in local.conf: PACKAGECONFIG_append_pn-cairo = " glesv2"
PACKAGECONFIG[2dcanvas] = "-DENABLE_ACCELERATED_2D_CANVAS=ON,-DENABLE_ACCELERATED_2D_CANVAS=OFF,"
PACKAGECONFIG[remote-inspector] = "-DENABLE_REMOTE_INSPECTOR=ON,-DENABLE_REMOTE_INSPECTOR=OFF,"
PACKAGECONFIG[webrtc] = "-DENABLE_WEB_RTC=ON,-DENABLE_WEB_RTC=OFF,libvpx libevent libopus"
PACKAGECONFIG[qtwpe] = "-DENABLE_WPE_QT_API=ON,-DENABLE_WPE_QT_API=OFF,qtbase-native qtbase qtdeclarative qtquickcontrols2 libepoxy wpebackend-fdo"
PACKAGECONFIG[openjpeg] = "-DUSE_OPENJPEG=ON,-DUSE_OPENJPEG=OFF,openjpeg"
PACKAGECONFIG[unified-builds] = "-DENABLE_UNIFIED_BUILDS=ON,-DENABLE_UNIFIED_BUILDS=OFF,"
PACKAGECONFIG[systemd] = "-DUSE_SYSTEMD=ON,-DUSE_SYSTEMD=OFF,"


EXTRA_OECMAKE = " -DPORT=WPE -DCMAKE_BUILD_TYPE=Release -G Ninja"

# If SSE code compiles, assume it runs successfully (it can't actually run
# because of cross compiling)
EXTRA_OECMAKE_append_x86 = " -DHAVE_SSE2_EXTENSIONS_EXITCODE=0"
# mips/gold does not yet implement
# error: .gnu.hash is incompatible with the MIPS ABI
EXTRA_OECMAKE_append_mipsarch = " -DUSE_LD_GOLD=OFF "

LDFLAGS_append_riscv64 = " -pthread"

FULL_OPTIMIZATION_remove = "-g"

LEAD_SONAME = "libWPEWebKit.so"
PACKAGES =+ "${PN}-web-inspector-plugin ${PN}-qtwpe-qml-plugin"
FILES_${PN} += "${libdir}/wpe-webkit*/injected-bundle/libWPEInjectedBundle.so"
FILES_${PN}-web-inspector-plugin += "${libdir}/libWPEWebInspectorResources.so ${libdir}/wpe-webkit-*/libWPEWebInspectorResources.so"
INSANE_SKIP_${PN}-web-inspector-plugin = "dev-so"

FILES_${PN}-qtwpe-qml-plugin += "${libdir}/qt5/qml/org/wpewebkit/qtwpe/*"
INSANE_SKIP_${PN}-qtwpe-qml-plugin = "dev-so"

# JSC JIT on ARMv7 is better supported with Thumb2 instruction set.
ARM_INSTRUCTION_SET_armv7a = "thumb"
ARM_INSTRUCTION_SET_armv7r = "thumb"
ARM_INSTRUCTION_SET_armv7m = "thumb"
ARM_INSTRUCTION_SET_armv7ve = "thumb"

# Extra runtime depends
RDEPENDS_${PN} += " \
    virtual/wpebackend \
    ${@bb.utils.contains('PACKAGECONFIG', 'mediasource', 'gstreamer1.0-plugins-good-isomp4', '', d)} \
    ${@bb.utils.contains('PACKAGECONFIG', 'webaudio', 'gstreamer1.0-plugins-good-wavparse', '', d)} \
    ${@bb.utils.contains('PACKAGECONFIG', 'gst_gl', 'gstreamer1.0-plugins-base-opengl', '', d)} \
    ${@bb.utils.contains('PACKAGECONFIG', 'video', 'gstreamer1.0-plugins-base-app \
                                                    gstreamer1.0-plugins-base-playback \
                                                    gstreamer1.0-plugins-base-audioconvert \
                                                    gstreamer1.0-plugins-base-audioresample \
                                                    gstreamer1.0-plugins-base-gio \
                                                    gstreamer1.0-plugins-base-videoconvert \
                                                    gstreamer1.0-plugins-base-videoscale \
                                                    gstreamer1.0-plugins-base-volume \
                                                    gstreamer1.0-plugins-base-typefindfunctions \
                                                    gstreamer1.0-plugins-good-audiofx \
                                                    gstreamer1.0-plugins-good-audioparsers \
                                                    gstreamer1.0-plugins-good-autodetect \
                                                    gstreamer1.0-plugins-good-avi \
                                                    gstreamer1.0-plugins-good-deinterlace \
                                                    gstreamer1.0-plugins-good-interleave \
                                                    ', '', d)} \
"

# Extra runtime recommends
RRECOMMENDS_${PN} += " \
    ca-certificates \
    shared-mime-info \
    ttf-bitstream-vera \
    ${PN}-web-inspector-plugin \
    ${PN}-qtwpe-qml-plugin \
    ${@bb.utils.contains('PACKAGECONFIG', 'video', 'gstreamer1.0-plugins-base-meta gstreamer1.0-plugins-good-meta gstreamer1.0-plugins-bad-meta', '', d)} \
"
