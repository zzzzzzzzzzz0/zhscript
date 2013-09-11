#!/bin/bash
cd `dirname $0`
z1=$PWD
z=$(basename $z1)
while true
do
	z2="$z.glade"
	if [ -f "$z2" ]
	then
		break
	fi
	z2="$z.ui"
	if [ -f "$z2" ]
	then
		break
	fi
	z2="ui.glade"
	if [ -f "$z2" ]
	then
		break
	fi
	exit
done
../../new_o/gtkmmsh "$z1/$z2" $@
