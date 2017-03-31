# resin-wpe

Example project running a fullscreen browser with hardware accelerated CSS,
WebGL, and HTML5 video for the RaspberryPi 3.

This project uses a container built by importing the Yocto rootfs produced by
building [meta-wpe](https://github.com/WebPlatformForEmbedded/meta-wpe)

## Fleet configuration

First you have to set a higher than default GPU memory, otherwise the renderer
will not be able to initialise. You can do this by setting a [fleet configuration variable](https://docs.resin.io/configuration/advanced/#modifying-config-txt-remotely-).

* `RESIN_HOST_CONFIG_gpu_mem=256`

## Setting the URL

To configure the URL displayed by webkit, set the URL environment variable. The
default value is `https://youtube.com/tv`

## Using PiTFT

If you want to display the output to PiTFT, make sure you enable the dtb
overlays for it and this project will automatically attempt to copy the
framebuffer there.

* `RESIN_HOST_CONFIG_dtoverlay`=`pitft28-capacitive,rotate=90,speed=80000000,fps=100`
