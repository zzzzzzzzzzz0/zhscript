#!/bin/bash
cd "`dirname $0`"
if [ -f ui ]
then
	u=./ui
	l=./l
else
	u="../../new_o/gtkmmsh --log-no-c $PWD/ui.glade"
	l="../../new_o/l"
fi
lib3/ln.sh
#flashplugin-downloader
#flashplugin-installer
$l lib2/apt-get.zs libgtkmm-2.4-1c2a libglademm-2.4-1c2a adobe-flashplugin / flashplugin-installer
$u
