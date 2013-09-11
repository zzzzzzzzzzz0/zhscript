#!/bin/bash
cd "`dirname $0`"
z="./ui"
if [ -f $z ]
then
	$z --- $@ &
	exit
fi
for z in "../../new_o/gtkmmsh --log-no-c" /usr/lib/zhscript/gtkmmsh
do
	if [ -f ${z%% *} ]
	then
		$z "$PWD/ui.glade" $@
		exit
	fi
done