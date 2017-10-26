#!/bin/sh
#u1704 '' -Dver_6_9_7_4_
#sudo apt-get install libmagick++-dev
g++ \
`pkg-config Magick++ --cflags` \
*.cpp \
-I../new_gg \
-shared -o"imagemagick4.so$1" \
`pkg-config Magick++ --libs` \
-fPIC \
-O3 -Wall -fmessage-length=0 \
$2
