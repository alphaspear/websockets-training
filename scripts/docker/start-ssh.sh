#!/usr/bin/env bash

docker build -t drogon-starter .
docker run -it --rm -p 3000:3000 -v `pwd`:/training drogon-starter
