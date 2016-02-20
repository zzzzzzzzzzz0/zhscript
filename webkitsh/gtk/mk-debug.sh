#!/bin/bash
d=`dirname $0`/Debug
mkdir -p $d
cd $d
tag=../../../new_o/webkitsh
echo dir=$PWD
echo tag=$tag
if [ "$1" == "t" ]
then
	$tag ../../../new_o/demo2/testwebkitsh.zs
	exit
fi
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"
f="-Wall -Wno-deprecated-declarations -c -fmessage-length=0 -MMD -MP -I ../../../new_gg $p_lib3"
#webkit-1.0
pkg="gtk+-3.0 webkitgtk-3.0"
g++ $f `pkg-config --cflags $pkg` -O0 -g3 ../*.cpp `find ../sh-base/ -name '*.cpp'`
g++ *.o `pkg-config --libs $pkg` -ldl -o"$tag"  

