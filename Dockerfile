FROM ubuntu:24.04

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    software-properties-common \
    build-essential \
    wget \
    curl \
    gdb \
    vim \
    lsb-release \
    ca-certificates \
    cmake \
    make


# Set GCC 13 as the default compiler
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 50 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 50

# Verify installed versions
RUN gcc --version && g++ --version && cmake --version
