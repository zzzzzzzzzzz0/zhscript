#!/bin/bash
p=`dirname $0`
if [ -f "$p/l" ]
then
	l="$p/l"
	u="$p/ui ---"
else
	l="$p/../../new_o/l"
	u="$p/../../new_o/gtkmmsh --log-no-c $p/ui.glade"
fi
$l lib2/apt-get.zs libgtkmm-2.4-1c2a libglademm-2.4-1c2a
$u $@
