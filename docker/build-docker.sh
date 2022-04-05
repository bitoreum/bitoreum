#!/usr/bin/env bash

export LC_ALL=C

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/.. || exit

DOCKER_IMAGE=${DOCKER_IMAGE:-bitoreum/bitoreumd-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/bitoreumd docker/bin/
cp $BUILD_DIR/src/bitoreum-cli docker/bin/
cp $BUILD_DIR/src/bitoreum-tx docker/bin/
strip docker/bin/bitoreumd
strip docker/bin/bitoreum-cli
strip docker/bin/bitoreum-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
