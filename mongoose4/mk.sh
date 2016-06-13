#!/bin/sh
#cc mongoose.c -shared -fPIC -fpic -o libmongoose.so -Wl,-soname,libmongoose.so -ldl -pthread -std=c99 -O2 -W -Wall -pedantic

g++ *.c *.cpp -o ../new_o/lib/mongoose4.so -I ../new_gg -DINT64_MAX=9223372036854775807 -shared -fPIC -O3 -Wall -fmessage-length=0 -MMD -MP -ldl -pthread
