#!/bin/sh
cd `dirname $0`
#/zzzzzzzzzzz/sh/tb.zs "$PWD" "$PWD"/../webkitsh/gtk/ :autocomp :忽略目录 :忽略目标不存在的根文件 :忽略隐藏的文件 :线程安全 :-
meld . ../webkitsh/gtk
