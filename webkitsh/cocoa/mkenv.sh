#!/bin/sh

cd `dirname $0`/../../new_o
pwd
no=$PWD

#cvtusoiishvhpsblaabvlhqspizf
#acbabdfhxuqksogygygtqhybmyjx
cd ~/Library/Developer/Xcode/DerivedData/webkitsh-*/Build/Products/Debug/webkitsh1.app/Contents/MacOS/
pwd

ln -sf $no/l4.so .
ln -sf $no/syn-zh .
ln -sf $no/err-zh .
ln -sfn $no/lib .
ln -sfn $no/lib2 .
ln -sfn $no/edit .

for i in $@
do
	echo $i
	ln -sf $i webkitsh1.zs
done