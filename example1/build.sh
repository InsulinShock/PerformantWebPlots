#!/bin/bash

../emsdk/emsdk activate latest
source ../emsdk/emsdk_env.sh

# -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1
em++ ./main.cpp --bind -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1 -s USE_WEBGL2=1 -std=c++14 -o ./build/index.js -Wall -Werror




