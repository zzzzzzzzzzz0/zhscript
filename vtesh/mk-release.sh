#!/bin/bash
dir=`dirname $0`/Release
mkdir -p $dir
cd $dir
tag=../../new_o/vtesh
echo dir=$PWD
echo tag=$tag
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"

sudo apt-get install libgtk-3-dev libvte-2.90-dev
pkg="gtk+-3.0 vte-2.90"

g++ -I../../new_gg -O3 -Wall -Wno-deprecated-declarations -Wno-unused-variable -c -fmessage-length=0 `pkg-config --cflags $pkg` -MMD -MP ../*.cpp `find ../sh-base/ -name '*.cpp'`
g++ -o "$tag" *.o $p_lib3 -ldl `pkg-config --libs $pkg`

