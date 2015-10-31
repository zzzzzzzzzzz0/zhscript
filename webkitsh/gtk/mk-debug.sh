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
f="-Wall -c -fmessage-length=0 -MMD -MP -I ../../../new_gg $p_lib3"
if [ "$1" == "r" ]
then
	d=$PWD/../Release
	mkdir -p $d
	cd $d
	echo dir=$PWD
	g++ $f `pkg-config --cflags webkit-1.0` -O3 ../*.cpp
else
	g++ $f `pkg-config --cflags webkit-1.0` -O0 -g3 ../*.cpp
fi
g++ *.o `pkg-config --libs webkit-1.0` -o"$tag"  

