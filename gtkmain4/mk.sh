#!/bin/sh
cd `dirname $0`
gcc *.c $(pkg-config --cflags --libs gtk+-3.0) -fPIC -shared -o ../new_o/lib/gtkmain4.so
