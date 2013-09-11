#!/bin/bash
cd "`dirname $0`"
if [ -f "bin/l" ]
then
	l="bin/l"
	u="bin/gtkmmsh"
else
	l="../../new_o/l"
	u="../../new_o/gtkmmsh --log-no-c"
fi
$l lib2/apt-get.zs libgtkmm-2.4-1c2a x11-utils ffmpeg
$u lib2/window1.glade "$PWD/src.zs"
