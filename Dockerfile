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
    make \
    git \
    linux-tools-common \
    linux-tools-generic \
    linux-tools-$(uname -r) \
    && apt-get clean

# Set GCC 13 as the default compiler
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 50 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 50

RUN mkdir -p /home/ubuntu/.config/gdb && \
    echo "add-auto-load-safe-path /tmp/aoc24/.gdbinit" > /home/ubuntu/.config/gdb/gdbinit

RUN sh -c 'echo kernel.perf_event_paranoid=1 >> /etc/sysctl.d/99-perf.conf'
RUN sh -c 'echo kernel.kptr_restrict=0 >> /etc/sysctl.d/99-perf.conf'
RUN sh -c 'sysctl --system'
