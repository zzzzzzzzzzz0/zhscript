#!/bin/bash
z0="`dirname $0`/.."

for z in "$z0/bin/gtkmmsh" "$z0/../../new_o/gtkmmsh --log-no-c" "/usr/lib/zhscript/gtkmmsh"
do
	if [ -f ${z%% *} ]
	then
		$z lib2/window1.glade "$z0/image/xqbase/ln.zs" $@
		break
	fi
done;
