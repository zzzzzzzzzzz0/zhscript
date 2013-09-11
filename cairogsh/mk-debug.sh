#!/bin/sh
cd `dirname $0`/Debug
pwd
rm *.o *.d ../../new_o/cairogsh

g++ -I../../new_gg/ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config gtk+-2.0 --cflags` -MMD -MP -MF"main.d" -MT"main.d" -o"main.o" "../main.cpp"
g++ -I../../new_gg/ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config gtk+-2.0 --cflags` -MMD -MP -MF"s1___.d" -MT"s1___.d" -o"s1___.o" "../s1___.cpp"
g++ -I../../new_gg/ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config gtk+-2.0 --cflags` -MMD -MP -MF"shell___.d" -MT"shell___.d" -o"shell___.o" "../shell___.cpp"
g++ -I../../new_gg/ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config gtk+-2.0 --cflags` -MMD -MP -MF"window___.d" -MT"window___.d" -o"window___.o" "../window___.cpp"
g++ -I../../new_gg/ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config gtk+-2.0 --cflags` -MMD -MP -MF"windows___.d" -MT"windows___.d" -o"windows___.o" "../windows___.cpp"
g++ -o"../../new_o/cairogsh" *.o `pkg-config gtk+-2.0 --libs`
#g++ `pkg-config gtk+-2.0 --libs` -o"../../new_o/cairogsh"  ./main.o ./s1___.o ./shell___.o ./window___.o ./windows___.o   

ls
../../new_o/cairogsh
