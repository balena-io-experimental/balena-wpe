#!/bin/bash

set -o errexit

export MACHINE=${MACHINE:-raspberrypi3}

export TEMPLATECONF="../meta-resin-wpe/conf/samples"
source poky/oe-init-build-env build

bitbake resin-wpe-image

VERSION=$(git describe --dirty --always)
IMAGE="resin-wpe:$MACHINE-$VERSION"

docker import - $IMAGE < tmp-glibc/deploy/images/$MACHINE/resin-wpe-image-$MACHINE.tar.gz

echo
echo "#####################################"
echo "Created docker image: $IMAGE"
echo "#####################################"
