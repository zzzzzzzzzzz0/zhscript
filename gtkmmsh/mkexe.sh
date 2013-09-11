#!/bin/bash
cd "`dirname $0`/exe"
pwd
rm *.o

z1=/opt2/gtkmm-win32/lib/*.a
z1="$z1 /opt2/dlfcn-win32-static-r19/lib/libdl.a"

z2=`PKG_CONFIG_PATH=/opt2/gtkmm-win32/lib/pkgconfig pkg-config gtkmm-2.4 --cflags`
z2="$z2 -I /opt2/dlfcn-win32-static-r19/include -I../../new_gg -Dver_exe_"
z5="i586-mingw32msvc-g++ $z2 -O3 -Wall -c -fmessage-length=0 -MMD -MP"
echo $z5

$z5 -MF"main.d" -MT"main.d" -o"main.o" "../main.cc"
$z5 -MF"shell.d" -MT"shell.d" -o"shell.o" "../shell.cc"
for z6 in ../*.cpp
do
	$z5 $z6
done

z4="i586-mingw32msvc-g++ *.o --static $z1 -o../../new_o/gtkmmsh"
echo $z4
${z4}-c.exe
${z4}.exe -mwindows
