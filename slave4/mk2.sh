#!/bin/sh
g++ *.cpp \
-I./ -I../new_gg -Dver_glibmmm_ \
`pkg-config glib-2.0 sigc++-2.0 --libs --cflags` -shared -o"../../bin/zhscript2/lib/slave4.so" \
-fPIC -O3 -Wall -fmessage-length=0
