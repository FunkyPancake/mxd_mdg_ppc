FROM ubuntu:latest

ENTRYPOINT ["top", "-b"]
ARG DEBIAN_FRONTEND=noninteractive
LABEL authors="FunkyPancake"

FROM ubuntu as toolchain
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y build-essential gcc git make cmake \
gdb gcc-multilib wget unzip gdb
RUN apt-get autoclean -y
RUN apt-get autoremove -y
RUN apt-get clean

FROM toolchain as ppc_sdk
RUN wget -O gcc.zip https://github.com/FunkyPancake/mxd_mdg_ppc/releases/download/toolchain-r1.0.0/gcc-4.9.4-Ee200-eabivle-x86_64-linux-g2724867.zip
RUN mkdir -p /opt/ppc/sdk
RUN unzip ./gcc.zip -d /opt/ppc/sdk
RUN ls /opt/ppc/sdk
ENV SDK_SYSROOT="/opt/ppc/sdk/powerpc-eabivle-4_9"
ENV PATH="${PATH}:${SDK_SYSROOT}/bin/"
ENV CC="powerpc-eabivle-gcc"
ENV CXX="powerpc-eabivle-g++"
ENV CPP="powerpc-eabivle-gcc"
ENV AS="powerpc-eabivle-as"
ENV LD="powerpc-eabivle-ld --sysroot=${SDK_SYSROOT}"
ENV CROSS_COMPILE="powerpc-eabivle-"

