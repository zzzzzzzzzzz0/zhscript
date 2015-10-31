#!/bin/bash

dir="`pwd`/.."

f3="$ver_ -Wall -fmessage-length=0 -MMD -MP"
f2="-O0 -g3 $f3"
case "$1" in
d)
	f1=$f2;;
r)
	f1="-O3 $f3";;
*)
	echo "d? r?"
	exit 1;;
esac
p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"

s2="-fPIC"
s1="-shared $s2"
i1="-I ../new_gg -I ../../new_gg"

gxx_(){
	z="g++ $@"
	echo
	echo "#pwd $PWD"
	echo $z
	$z
}
gcc_(){
	z="gcc $@"
	echo
	echo "#pwd $PWD"
	echo $z
	$z
}
gxx_lib_(){
	cd "$dir/$1"
	gxx_ *.cpp $2 -o ../new_o/lib/$1.so $s1 $f1 $i1
}
gxx_lib_old_(){
	cd "$dir/$1"
	gxx_ -o ../new_o/lib/$1.so $s1 $f1 $i1 $2 *.cpp
}
gcc_lib_(){
	cd "$dir/$1"
	gcc_ *.c $2 -o ../new_o/lib/$1.so $s1 $f1 $i1
}
gcc_lib_old_(){
	cd "$dir/$1"
	gcc_ -o ../new_o/lib/$1.so $s1 $f1 $i1 $2 *.c
}
gxx_gtkmm2_(){
	gxx_ $@ `pkg-config gtkmm-2.4 libglademm-2.4 --cflags --libs` -ldl
}
gxx_gtkmm_(){
	cd "$dir/gtkmmsh"
	gxx_gtkmm2_ -o ../new_o/gtkmmsh $f1 $i1 *.cc *.cpp
}
gxx_gtkmmsh_plugin_(){
	cd "$dir/gtkmmsh-plugin/$1"
	gxx_gtkmm2_ -o ../../new_o/gtkmmsh-plugin/$1$3.so $s1 $f1 $i1 -I ../../gtkmmsh $2 *.cpp
}
gxx_l4_(){
	cd "$dir/new_l4/l432_so"
	gxx_ $1 $f1 $s2 -c `echo *.cpp|sed 's/call_func\.cpp//g'`
	gxx_ $1 $f2 $s2 -c call_func.cpp
	gxx_ -o ../../new_o/l4$2.so $s1 $f1 $3 *.o
}
gxx_l_(){
	cd "$dir/new_l/l32"
	gxx_ -o ../../new_o/l $f1 $i1 l.cpp -ldl
}

$2 "$3" "$4" "$5"

