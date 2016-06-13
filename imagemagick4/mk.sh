#!/bin/sh
sudo apt-get install libmagick++-dev
g++ \
`Magick++-config --cxxflags --cppflags` \
*.cpp \
-I../new_gg \
-shared -o"imagemagick4.so" \
`Magick++-config --ldflags --libs` \
-fPIC \
-O3 -Wall -fmessage-length=0
