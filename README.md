# resin-wpe

![pitft](https://github.com/resin-io-playground/resin-wpe/raw/master/pitft.gif)

Example project running a fullscreen browser with hardware accelerated CSS,
WebGL, and HTML5 video for the RaspberryPi 3.

This project uses a container built by importing the Yocto rootfs produced by
building [meta-wpe](https://github.com/WebPlatformForEmbedded/meta-wpe)

## Fleet configuration

First you have to set a higher than default GPU memory, otherwise the renderer
will not be able to initialise. You can do this by setting a [fleet configuration variable](https://docs.resin.io/configuration/advanced/#modifying-config-txt-remotely-).

* `RESIN_HOST_CONFIG_gpu_mem=256`

We also need to set the HDMI resolution because the WPE project is currently hardcoded to display at 720p.

* `RESIN_HOST_CONFIG_force_hotplug=1`
* `RESIN_HOST_CONFIG_hdmi_group=1`
* `RESIN_HOST_CONFIG_hdmi_mode=4`

## Setting the URL

To configure the URL displayed by webkit, set the URL environment variable. The
default value is [http://www.nyan.cat/original](http://www.nyan.cat/original)

## Using PiTFT

If you want to display the output to PiTFT, make sure you enable the dtb
overlays for it and this project will automatically attempt to copy the
framebuffer there.

* `RESIN_HOST_CONFIG_dtoverlay`=`pitft28-capacitive,rotate=90,speed=62000000,fps=60`

![PiTFT picture](http://i.imgur.com/VaIPJ0L.jpg)
