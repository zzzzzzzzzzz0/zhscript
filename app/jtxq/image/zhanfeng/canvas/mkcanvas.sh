#!/bin/bash
z0=`dirname $0`
z2=`basename $0`

for z in "$z0/../../../bin/gtkmmsh" "$z0/../../../../../new_o/gtkmmsh" "/usr/lib/zhscript/gtkmmsh"
do
	if [ -f $z ]
	then
		$z "$z0/${z2%.*}.glade" $@
		break
	fi
done;
