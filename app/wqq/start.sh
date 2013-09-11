#!/bin/bash
cd "`dirname $0`"
z="./ui"
if [ -f $z ]
then
	$z
	exit
fi
z="../../new_o/gtkmmsh"
if [ -f $z ]
then
	$z "$PWD/ui.glade" $@
	exit
fi
z="/usr/local/lib/zhscript/gtkmmsh"
if [ -f $z ]
then
	$z "$PWD/ui.glade" $@
	exit
fi

