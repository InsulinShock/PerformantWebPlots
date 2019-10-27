FROM ubuntu:18.04

RUN apt-get install -y git-core

RUN git clone https://github.com/emscripten-core/emsdk.git

RUN ./emsdk/emsdk install latest





