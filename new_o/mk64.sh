#!/bin/bash
echo "可能需要输入 apt-get install 时所须密码"
sudo apt-get install g++ pkg-config \
libcurl4-gnutls-dev \
libsqlite3-dev \
libgtk-3-dev \
libwebkit-dev \
libwnck-3-dev \
libunique-dev \
libgnomeui-dev
sudo apt-get install libgtkmm-2.4-dev libglademm-2.4-dev
sudo apt-get install libgtksourceviewmm-2.0-dev

p_lib3="-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3"
export ver_="-D ver_64_"

cd "`dirname $0`"

./mk_.sh r gxx_l4_
./mk_.sh r gxx_l4_ "-D debug_liucheng_" -d

./mk_.sh r gxx_lib_ test4
./mk_.sh r gcc_lib_ gjk4
./mk_.sh r gxx_lib_ gjke4
./mk_.sh r gxx_lib_ gjks4
./mk_.sh r gxx_lib_ file4 "-D f0zai4_lstat"
./mk_.sh r gxx_lib_ doscmd4
./mk_.sh r gxx_lib_ regexpr4
./mk_.sh r gxx_lib_ redireconsoi4
./mk_.sh r gxx_lib_ base64
./mk_.sh r gxx_lib_ socket4
./mk_.sh r gxx_lib_ vartable4
./mk_.sh r gxx_lib_ xml4 "-I /usr/include/libxml2/ -lxml2"
./mk_.sh r gxx_lib_ txtotxt4
./mk_.sh r gxx_lib_ curle4 "-lcurl"
./mk_.sh r gxx_lib_ inotify4
./mk_.sh r gxx_lib_ sqlite4 "-lsqlite3"
./mk_.sh r gcc_lib_ md4
./mk_.sh r gxx_lib_ thread4 -lpthread
./mk_.sh r gxx_lib_ clpars4
./mk_.sh r gxx_lib_ timeout4 "`pkg-config glib-2.0 --cflags --libs`"
./mk_.sh r gxx_lib_ timer4
./mk_.sh r gcc_lib_ gtkmain4 "`pkg-config gtk+-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ menu4 "`pkg-config gtk+-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ clipboard4 "`pkg-config gtk+-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ dlg4 "`pkg-config gtk+-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ wnck4 "$p_lib3 -DWNCK_I_KNOW_THIS_IS_UNSTABLE `pkg-config libwnck-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ unique4 "$p_lib3 `pkg-config --cflags --libs gtk+-2.0 unique-1.0`"
./mk_.sh r gxx_lib_ gnomeu4 "`pkg-config libgnomeui-2.0 --cflags --libs`"
./mk_.sh r gxx_lib_ mongoose4 "-ldl -pthread -DINT64_MAX=9223372036854775807 mongoose.c"
./mk_.sh r gxx_lib_ slave4 "`pkg-config glib-2.0 glibmm-2.4 --libs --cflags`"
./mk_.sh r gxx_lib_ transform4

./mk_.sh r gxx_l_

./mk_.sh r gxx_gtkmm_

./mk_.sh r gxx_gtkmmsh_plugin_ statusicon
./mk_.sh r gxx_gtkmmsh_plugin_ iconview
./mk_.sh r gxx_gtkmmsh_plugin_ tmpl
./mk_.sh r gxx_gtkmmsh_plugin_ huitu
./mk_.sh r gxx_gtkmmsh_plugin_ dlg
./mk_.sh r gxx_gtkmmsh_plugin_ menu
./mk_.sh r gxx_gtkmmsh_plugin_ nostdw
./mk_.sh r gxx_gtkmmsh_plugin_ timeout
./mk_.sh r gxx_gtkmmsh_plugin_ buju
./mk_.sh r gxx_gtkmmsh_plugin_ common "-fpermissive"
./mk_.sh r gxx_gtkmmsh_plugin_ feiqi
./mk_.sh r gxx_gtkmmsh_plugin_ imagecache
./mk_.sh r gxx_gtkmmsh_plugin_ treeview
./mk_.sh r gxx_gtkmmsh_plugin_ textview
./mk_.sh r gxx_gtkmmsh_plugin_ sourceview "$p_lib3 `pkg-config gtksourceviewmm-2.0 --cflags --libs`"
wk_f1="$p_lib3 `pkg-config webkit-1.0 --cflags --libs`"
./mk_.sh r gxx_gtkmmsh_plugin_ webkit "$wk_f1"
./mk_.sh r gxx_gtkmmsh_plugin_ dnd

wk=/opt2/src/WebKit-r75891
if [ -d $wk ]
then
	./mk_.sh r gxx_gtkmmsh_plugin_ webkit "-D ver_3_ -I $wk/WebKit/gtk/ -I $wk/Source/WebCore/platform/network/soup/cache/ -I $wk/DerivedSources/ -L$wk/.libs/ -lwebkitgtk-1.0 $wk_f1" 3
fi

dir="`pwd`/.."

$dir/webkitsh/gtk/mk-release.sh
$dir/cairogsh/mk-release.sh
$dir/vtesh/mk-release.sh

find "$dir" \( -name '*.o' -o -name '*.d' \) -exec rm "{}" \;
