#!/bin/bash
cd `dirname $0`/Release
tag=../../../new_o/webkitsh
echo dir=$PWD
echo tag=$tag
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"
f="-Wall -c -fmessage-length=0 -MMD -MP -I ../../../new_gg -I. $p_lib3"
pkg="gtk+-3.0 webkitgtk-3.0"
sudo apt-get install libgtk-3-dev libwebkitgtk-3.0-dev
g++ $f `pkg-config --cflags $pkg` -O3 ../*.cpp ../sh-base/*.cpp &&\
g++ *.o `pkg-config --libs $pkg` -o"$tag"  

