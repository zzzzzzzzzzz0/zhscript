加载lib/gjke4。

赋予【主】安装目录以/usr/lib/zhscript。
赋予【主】源目录以‘目录’../../../new_o。

（新建数组【主】宾文件、2、
。）

赋予【主】另外以下原样
mkdir -p usr/bin
cd usr/bin
ln -s /usr/lib/zhscript/l zhscript
cd ..
mkdir -p local/lib
cd local/lib
ln -s /usr/lib/zhscript .
cd ../..
cd lib/zhscript

mkdir lib3
#cp /opt2/src/WebKit-r75891/.libs/libwebkitgtk-1.0.so.0.5.2 lib3/libwebkitgtk-1.0.so.0
rm gtkmmsh-plugin/webkit3.so

find \( -name 'mk*.sh' -o -name 'tb*.sh' -o -name '*.exe' -o -name '*.dll' \) -printf 'rm -rf %p\n' | sh
chmod 755 l gtkmmsh
find demo* \( -name '*.zs' -o -name '*.cgi' \) -printf "chmod 755 '%p'\n" | sh
上原样。
