#!/bin/sh
#sudo apt-get install libmagick++-dev
g++ \
`pkg-config Magick++ --cflags` \
*.cpp \
-I../new_gg \
-shared -o"imagemagick4.so-7Q16" \
`pkg-config Magick++ --libs` \
-fPIC \
-O3 -Wall -fmessage-length=0
