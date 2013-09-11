#!/bin/sh
cd `dirname $0`
ls *.exe *.dll -l
i586-mingw32msvc-strip *.exe *.dll
ls *.exe *.dll -l
