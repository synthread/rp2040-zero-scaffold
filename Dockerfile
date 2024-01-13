FROM ubuntu:jammy

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y build-essential python3 cmake gcc-arm-none-eabi libnewlib-arm-none-eabi
