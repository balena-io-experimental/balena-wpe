#!/bin/bash

set -o errexit

export MACHINE=${MACHINE:-raspberrypi3}

export TEMPLATECONF="../meta-balena-wpe/conf/samples"
source poky/oe-init-build-env build

bitbake balena-wpe-image

VERSION=$(git describe --dirty --always)
IMAGE="balena-wpe:$MACHINE-$VERSION"

docker import - $IMAGE < tmp/deploy/images/$MACHINE/balena-wpe-image-$MACHINE.tar.gz

echo
echo "#####################################"
echo "Created docker image: $IMAGE"
echo "#####################################"
