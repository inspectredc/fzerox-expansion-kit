CC   = gcc
MAKE = make
N_THREADS ?= $(shell nproc)

UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	$(error Native Windows is currently unsupported for building this repository, use WSL instead)
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
	MIO0_FLAGS := --gc-sections
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := macos
	MIO0_FLAGS :=
endif

RECOMP_DIR := ido-recomp/$(DETECTED_OS)

default: all

all: recomp torch

clean:
	$(RM) -rf $(RECOMP_DIR)
	$(RM) -rf Torch/cmake-build-release

distclean: clean

recomp:
	@echo "Fetching Recomp..."
	wget https://github.com/decompals/ido-static-recomp/releases/download/v1.0/ido-5.3-recomp-${DETECTED_OS}.tar.gz
	mkdir -p $(RECOMP_DIR)/5.3
	tar xf ido-5.3-recomp-${DETECTED_OS}.tar.gz -C $(RECOMP_DIR)/5.3
	$(RM) ido-5.3-recomp-${DETECTED_OS}.tar.gz
	wget https://github.com/decompals/ido-static-recomp/releases/download/v1.0/ido-7.1-recomp-${DETECTED_OS}.tar.gz
	mkdir -p $(RECOMP_DIR)/7.1
	tar xf ido-7.1-recomp-${DETECTED_OS}.tar.gz -C $(RECOMP_DIR)/7.1
	$(RM) ido-7.1-recomp-${DETECTED_OS}.tar.gz

torch:
	@echo "Building torch..."
	$(MAKE) -C Torch type=release -j$(N_THREADS)

.PHONY: all clean distclean default torch
