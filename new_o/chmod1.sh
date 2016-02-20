#!/bin/bash
#cd `dirname $0`
f__() {
	find $3 -type f $4 -name "$1" -a ! -perm $2 -printf "chmod $2 \"%p\" #%m\n"  
}
f1__() {
	f__ "$1" 775 '-maxdepth 1'
}
f1__ l
f1__ '*sh'
f__ '*.so' 664
f__ '*.zs' 775 demo
#f__ '*.zs' 644 demo '!'
