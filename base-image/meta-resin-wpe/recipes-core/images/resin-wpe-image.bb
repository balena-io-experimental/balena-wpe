include recipes-core/images/core-image-minimal.bb

IMAGE_FSTYPES = "tar.gz"

IMAGE_INSTALL_append += " \
	fbcp \
	fontconfig \
	fontconfig-utils \
	tslib-calibrate \
	tslib-tests \
	ttf-bitstream-vera \
	gstreamer1.0-plugins-base-alsa \
	wpebackend-rdk \
	wpewebkit \
	cog \
	xkeyboard-config \
	tzdata tzdata-misc tzdata-posix tzdata-right tzdata-africa \
	tzdata-americas tzdata-antarctica tzdata-arctic tzdata-asia \
	tzdata-atlantic tzdata-australia tzdata-europe tzdata-pacific \
	"

VIRTUAL-RUNTIME_init_manager="busybox"
