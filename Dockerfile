FROM debian:trixie
RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential cmake ninja-build gdb valgrind clang clangd clang-format clang-tidy \
      libomp-dev libtbb-dev libopenmpi-dev openmpi-bin ca-certificates \
    && rm -rf /var/lib/apt/lists/*
# OpenMPI от root в контейнере
ENV OMPI_ALLOW_RUN_AS_ROOT=1 OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1 OMPI_MCA_rmaps_base_oversubscribe=1
WORKDIR /work
CMD ["bash"]
