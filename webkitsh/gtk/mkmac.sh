#!/bin/bash
tag=../../new_o/webkitsh
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"
f="-Wall -c -fmessage-length=0 -MMD -MP -I ../../new_gg -I. $p_lib3"
pkg="gtk+-3.0 webkitgtk-3.0"
sudo port install libgtk-3-dev libwebkitgtk-3.0-dev
z="g++ $f `pkg-config --cflags $pkg` -O3 *.cpp sh-base/*.cpp"
echo $z
$z
z="g++ *.o `pkg-config --libs $pkg` -o$tag"
echo $z
$z
rm *.o *.d
