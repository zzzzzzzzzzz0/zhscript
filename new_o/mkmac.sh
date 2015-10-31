#!/bin/bash

cd "`dirname $0`"

export ver_="-D ver_mac_mini_"

./mk_.sh r gxx_l4_ "" "" "-install_name libzhscript.so"
./mk_.sh r gxx_l4_ "-D debug_liucheng_" -d "-install_name libzhscript-d.so"

./mk_.sh r gxx_lib_ test4
./mk_.sh r gcc_lib_ gjk4
./mk_.sh r gxx_lib_ file4 "-D f0zai4_lstat"
./mk_.sh r gxx_lib_ doscmd4
./mk_.sh r gxx_lib_ regexpr4
./mk_.sh r gxx_lib_ gjke4
./mk_.sh r gxx_lib_ gjks4
./mk_.sh r gxx_lib_ redireconsoi4
./mk_.sh r gxx_lib_ base64
./mk_.sh r gxx_lib_ socket4
./mk_.sh r gxx_lib_ vartable4
./mk_.sh r gxx_lib_ xml4 "-I /usr/include/libxml2/ -lxml2"
./mk_.sh r gxx_lib_ txtotxt4 "-liconv"
./mk_.sh r gxx_lib_ curle4 "-lcurl"
./mk_.sh r gxx_lib_ sqlite4 "-lsqlite3"
./mk_.sh r gcc_lib_ md4
./mk_.sh r gxx_lib_ thread4 -lpthread
./mk_.sh r gxx_lib_ clpars4
./mk_.sh r gxx_lib_ mongoose4 "-ldl -pthread -DINT64_MAX=9223372036854775807 mongoose.c"
./mk_.sh r gcc_lib_ gtkmain4 "`pkg-config gtk+-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ menu4 "`pkg-config gtk+-3.0 --cflags --libs`"
./mk_.sh r gxx_lib_ dlg4 "`pkg-config gtk+-3.0 --cflags --libs`"

./mk_.sh r gxx_l_

