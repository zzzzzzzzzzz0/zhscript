#!./l --。
别名源以参数1。
别名目标以参数2。
别名pkg以参数3。

加载lib/defii。
赋予白底黑字以‘颜色’‘白底’‘黑字’‘毕’。
赋予蓝底白字以‘颜色’‘蓝底’‘白字’‘毕’。
赋予红底白字以‘颜色’‘红底’‘白字’‘毕’。
赋予色停以‘颜色’‘毕’。

加载lib/defi。
定义除错以下代码
	赋予错以解释‘参数1’下原样“上原样‘参数2’下原样”上原样。
	如果‘错’那么先
		显示“‘红底白字’错‘错’ ‘参数1’‘参数2’‘色停’”换行。
		结束1。
	了。
上代码。

加载lib/file4。
加载lib/stdc。
赋予目录以调用‘最终文件名’、先调用‘得目录名’、‘参数0’了‘源’。
除错“调用‘改变目录函数’、”、‘目录’。

赋予详细以。
定义运行以下代码
	别名命令以参数1。
	如果‘详细’那么
		显示‘蓝底白字’‘命令’‘色停’换行。
	除错“执行”、‘命令’。
上代码。

赋予它以。
加载lib/clpars4。
调用‘命令行加回调’、
	详细、、0、下代码
		赋予‘参数0’【上】以1。
	上代码、
	、、1、下代码
		赋予它【上】以‘它’"‘参数1’"“ ”。
	上代码。
调用‘命令行解析’、‘参数栈4’。

赋予头以tmp--。

定义主干提示以下代码
	显示‘颜色’‘绿底’‘黑字’‘毕’‘主干’‘色停’换行。
上代码。
赋予主干以“-I../new_gg -I../../new_gg -O3 -Wall -Wno-deprecated-declarations -Wno-unused-variable ‘它’
-c -fmessage-length=0 `pkg-config --cflags ‘pkg’` -MMD -MP”。
主干提示。

加载lib/doscmd4。
加载lib/gjk4。
赋予搜以调用‘dir.begin’、.、^.+\.cpp$、s。
循环先
	赋予名以调用‘dir.next’、‘搜’。
	如果不‘名’那么跳出。
	赋予名.以‘头’先调用‘串替换方法’、先调用‘子串方法’、‘名’、0、-3了、/、--了。
	显示“‘白底黑字’‘名’‘色停’ ‘蓝底白字’‘名.’‘色停’”换行。
	运行“g++ ‘主干’ -MF"‘名.’d" -MT"‘名.’d" -o "‘名.’o" "‘名’"”。
了。
调用‘dir.end’、‘搜’。
赋予主干以“-o "‘目标’" 
-Wl,-rpath=lib3,-rpath=zhscript/lib3,-rpath=/usr/lib/zhscript/lib3 
-ldl `pkg-config --libs ‘pkg’`”。
主干提示。
运行“g++ ‘头’*.o ‘主干’”。
运行“rm ‘头’*”。
