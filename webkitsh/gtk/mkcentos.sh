#!/bin/bash
tag=../../new_o/webkitsh
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"
f="-Wall -c -fmessage-length=0 -MMD -MP -I ../../new_gg -I. $p_lib3"
pkg="webkit-1.0"
z="g++ $f `pkg-config --cflags $pkg` -O3 *.cpp sh-base/*.cpp"
echo $z
$z
z="g++ *.o `pkg-config --libs $pkg` -o$tag"
echo $z
$z
rm *.o *.d
