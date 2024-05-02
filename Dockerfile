FROM ubuntu:latest

ENTRYPOINT ["top", "-b"]
ARG DEBIAN_FRONTEND=noninteractive
LABEL authors="FunkyPancake"

FROM ubuntu as toolchain
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install  build-essential gcc git make cmake \
gdb gcc-multilib wget
RUN apt-get autoclean -y
RUN apt-get autoremove -y
RUN apt-get clean

FROM toolchain as sdk
RUN wget -O gcc.zip https://github.com/FunkyPancake/mxd_mdg_ppc/releases/download/toolchain-r1.0.0/gcc-4.9.4-Ee200-eabivle-x86_64-linux-g2724867.zip
RUN tar -xf
