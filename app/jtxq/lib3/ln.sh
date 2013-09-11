#!/bin/sh
z="/usr/lib/libwebkitgtk-1.0.so.0"
if [ -f "$z" ]
then
	cd `dirname $0`
	ln -sf $z libwebkit-1.0.so.2
	cd -
fi
