#!/bin/sh
sudo apt-get install libpng++-dev
g++ *.cpp \
-I./ -I../new_gg \
`libpng-config --cflags --ldflags` -shared -o"png4.so" \
-fPIC \
-O3 -Wall -fmessage-length=0
