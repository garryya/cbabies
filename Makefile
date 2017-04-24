# EXE	:= words tsst stocks list
EXE	:= rvrlist
WORKDIR	:= /home/garryya/rd/cbabies

GCCVER	    = /grid/common/pkgs/gcc/v4.8.3
#GCCVER	    = /grid/common/pkgs/gcc/v4.4.5
GCC	    = $(GCCVER)/bin/g++
CFLAGS	    = -Wall -Wno-unused-variable -std=c++11
CXX_DEBUG   := -g

BUILD_CMD = $(GCC) $(CFLAGS) $(CXX_DEBUG) $(LDFLAGS) $(WORKDIR)/$(EXE).cpp -o $(WORKDIR)/$(EXE)

$(EXE) : $(EXE).cpp
	@echo ===> Building $(WORKDIR)/$(EXE) ...
	$(BUILD_CMD)

default: build

build: $(EXE)

clean:
	rm -f *.o $(WORKDIR)/$(EXE) *~

all: clean build

