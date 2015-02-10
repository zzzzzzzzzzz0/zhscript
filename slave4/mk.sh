#!/bin/sh
#glib-2.0 glibmm-2.4
g++ *.cpp \
-I./ -I/zzzzzzzzzzz/github/zhscript/new_gg \
`pkg-config gtkmm-2.4 --libs --cflags` -shared -o"slave4.so" \
-fPIC \
-O3 -Wall -fmessage-length=0
