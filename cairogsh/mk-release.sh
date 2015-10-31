#!/bin/bash
dir=`dirname $0`/Release
mkdir -p $dir
cd $dir
tag=../../new_o/cairogsh
echo dir=$PWD
echo tag=$tag
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"
f="-Wall -c -fmessage-length=0 -MMD -MP -I ../../new_gg -I. $p_lib3"

#pkg="gtk+-3.0"
#sudo apt-get install libgtk-3-dev
pkg="gtk+-2.0"

g++ $f `pkg-config --cflags $pkg` -O3 ../*.cpp `find ../sh-base/ -name '*.cpp'` &&\
g++ *.o `pkg-config --libs $pkg` -ldl -o"$tag"  

