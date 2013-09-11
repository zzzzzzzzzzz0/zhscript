#!/bin/bash
cd "`dirname $0`"
z0=$PWD
z1=${PWD##*/}_zs

for z in "$z0/bin" "$z0/../../new_o" "/usr/lib/zhscript"
do
	gtkmmsh="$z/gtkmmsh"
	if [ -f $gtkmmsh ]
	then
		lib3/ln.sh
		"$z/l" "$z0/start.zs" "$z"
		$gtkmmsh "$HOME/.config/$z1/ui.glade" "$z0/start-ui.zs" $@
		break
	fi
done;
