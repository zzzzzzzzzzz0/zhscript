#!/bin/sh
g++ `pkg-config gtkmm-2.4 --libs --cflags` -shared -o"libgmchessengine.so.64" -fPIC -O3 -Wall -fmessage-length=0 src/*.cc src/*.cpp

