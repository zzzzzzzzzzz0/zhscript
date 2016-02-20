#!/bin/bash
z=".64"
if [ "$1" != "" ]
then
	z="$1"
fi
g++ src/*.cc src/*.cpp `pkg-config gtkmm-2.4 --libs --cflags` -shared -o"libgmchessengine.so$z" -fPIC -O3 -Wall -fmessage-length=0

