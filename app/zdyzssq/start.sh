#!/bin/bash
cd "`dirname $0`"
z1="$PWD/ui.glade"
for z in "./ui" "../../new_o/gtkmmsh" "/usr/lib/zhscript/gtkmmsh"
do
	if [ -f $z ]
	then
		$z "$z1" $@
		break
	fi
done
