include recipes-core/images/core-image-minimal.bb

IMAGE_FSTYPES = "tar.gz"

DISTRO_FEATURES_remove = "wayland"

IMAGE_INSTALL_append += " \
	fbcp \
	fontconfig \
	fontconfig-utils \
	tslib-calibrate \
	tslib-tests \
	ttf-bitstream-vera \
	wpebackend \
	wpebackend-rdk \
	wpelauncher \
	wpewebkit \
	"

VIRTUAL-RUNTIME_init_manager="busybox"
