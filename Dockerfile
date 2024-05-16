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

FROM toolchain as sdk
RUN wget -O build_tools.tar.xz https://github.com/FunkyPancake/mxd_mdg_ppc/releases/download/buildtools-v1.0.0/build_tools.tar.xz
RUN mkdir -p /opt/ppc/sdk
RUN tar -xJf build_tools.tar.xz -C /opt/ppc/sdk && rm ./build_tools.tar.xz
RUN ls /opt/ppc/sdk
ENV SDK_SYSROOT="/opt/ppc/sdk/build_tools"
ENV PATH="${PATH}:${SDK_SYSROOT}/powerpc-eabivle-4_9/bin/"
ENV CC="powerpc-eabivle-gcc"
ENV CXX="powerpc-eabivle-g++"
ENV CPP="powerpc-eabivle-gcc"
ENV AS="powerpc-eabivle-as"
ENV LD="powerpc-eabivle-ld"
ENV CROSS_COMPILE="powerpc-eabivle-"