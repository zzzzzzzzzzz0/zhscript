#!/bin/bash
cd "`dirname $0`"
if [ -f l ]
then
	l=./l
	m="./movbrow ---"
else
	l="../../new_o/l"
	m="../../new_o/gtkmmsh --log-no-c `pwd`/movbrow.glade"
fi
$l lib2/apt-get.zs libgtkmm-2.4-1c2a libglademm-2.4-1c2a
$m $@