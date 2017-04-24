#!/bin/csh -fe

make
./tsst | tee tsst.res | diff - tsst.golden
