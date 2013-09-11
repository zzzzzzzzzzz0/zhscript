#!/bin/bash
cd `dirname $0`
z=$(basename $(pwd))
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
if [ -z "$1" ]
then
	z3=wk.zs
else
	z3="$@"
fi
../../new_o/gtkmmsh $z2 --e-x-d-- `pwd`/$z3
