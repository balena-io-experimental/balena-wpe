include recipes-core/images/core-image-minimal.bb

IMAGE_FSTYPES = "tar.gz"

DISTRO_FEATURES_remove = "wayland"

IMAGE_INSTALL_append += " \
	fbcp \
	fontconfig \
	fontconfig-utils \
	tslib-calibrate \
	ttf-bitstream-vera \
	wpebackend \
	wpebackend-rdk \
	wpelauncher \
	wpewebkit \
	"

PREFERRED_PROVIDER_virtual/kernel_forcevariable = "linux-dummy"

VIRTUAL-RUNTIME_init_manager="busybox"
