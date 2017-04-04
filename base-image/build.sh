#!/bin/bash

set -o errexit

source poky/oe-init-build-env build

bitbake-layers add-layer ../meta-openembedded/meta-multimedia/
bitbake-layers add-layer ../meta-openembedded/meta-oe/
bitbake-layers add-layer ../meta-raspberrypi
bitbake-layers add-layer ../meta-resin-wpe
bitbake-layers add-layer ../meta-wpe

export MACHINE=${MACHINE:-raspberrypi3}

bitbake resin-wpe-image

VERSION=$(git describe --dirty --always)
IMAGE="resin-wpe:$MACHINE-$VERSION"

docker import - $IMAGE < tmp-glibc/deploy/images/$MACHINE/resin-wpe-image-$MACHINE.tar.gz

echo "Created docker image: $IMAGE"
