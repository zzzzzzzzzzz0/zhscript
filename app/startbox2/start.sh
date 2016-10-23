#!/bin/bash
p=`dirname $0`
"$p/l" lib2/apt-get.zs 
"$p/webkitsh" "$p/ui.zs" $@
