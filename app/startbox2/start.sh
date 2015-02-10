#!/bin/bash
p=`dirname $0`
if [ -f "$p/l" ]
then
	l="$p/l"
	u="$p/webkitsh"
else
	l="$p/../../new_o/l"
	u="$p/../../new_o/webkitsh"
fi
$l lib2/apt-get.zs 
$u "$p/ui.zs" $@
