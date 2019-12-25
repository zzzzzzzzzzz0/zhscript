#!/bin/sh
#gtkmm-2.4
g++ `ls *.cpp | grep -v glibmmm.cpp` \
-I./ -I../new_gg \
`pkg-config glib-2.0 glibmm-2.4 --libs --cflags` -shared -o"../../bin/zhscript2/lib/slave4.so" \
-fPIC \
-O3 -Wall -fmessage-length=0
