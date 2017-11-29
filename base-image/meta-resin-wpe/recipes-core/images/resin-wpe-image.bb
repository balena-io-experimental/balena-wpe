include recipes-core/images/core-image-minimal.bb

IMAGE_FSTYPES = "tar.gz"

IMAGE_INSTALL_append += " \
	fbcp \
	fontconfig \
	fontconfig-utils \
	sthttpd \
	tslib-calibrate \
	tslib-tests \
	ttf-bitstream-vera \
	wpebackend \
	wpebackend-rdk \
	wpelauncher \
	wpewebkit \
	"

VIRTUAL-RUNTIME_init_manager="busybox"
