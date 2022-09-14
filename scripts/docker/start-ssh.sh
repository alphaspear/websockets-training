#!/usr/bin/env bash

docker build -t drogon-starter .
docker run -it --rm -v `pwd`:/training drogon-starter
