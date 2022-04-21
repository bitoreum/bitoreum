FROM debian:stretch
LABEL maintainer="Bitoreum Developers <dev@bitoreum.org>"
LABEL description="Dockerised BitoreumCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
