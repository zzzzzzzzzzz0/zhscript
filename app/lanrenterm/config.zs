加载lib/clpars4。
加载lib2/config2.zs、_zs。

赋予应用标题【主】以(懒人终端)。
赋予首目录【主】以‘家目录’。
赋予多页样式【主】以-nb。
赋予-b-s【主】以5。
赋予-oor-p-nb【主】以44442。
赋予-oor-p-t【主】以44443。
赋予-oor-p【主】以‘-oor-p‘多页样式’’。
调用‘命令行加回调’、
	-home、指定首目录，默认‘首目录’、1、下代码
		赋予首目录【主】以‘参数1’。
	上代码、
	-add、新页目录、1、下代码
		赋予新页目录【主】以‘参数1’。
	上代码、
	-t | -nb、“多页样式。表格、顶标签页”、0、下代码
		赋予多页样式【主】以‘参数0’。
		赋予-oor-p【主】以‘-oor-p‘多页样式’’。
	上代码、
	-b-s、“按钮大小，默认‘-b-s’，可选1至6”、1、下代码
		赋予‘参数0’【主】以‘参数1’。
	上代码、
	-iv、、0、下代码
		赋予‘参数0’【主】以。
	上代码、
	-oor-p、“一端口，默认‘-oor-p’”、1、下代码
		赋予‘参数0’【主】以‘参数1’。
	上代码、
	-ins、、1、下代码
		赋予‘参数0’【主】以‘参数1’。
	上代码、
	-h | --help、、0、“赋予-h【主】以。”、
	、、1、下代码
		赋予-h【主】以“错误参数：‘参数1’”回车换行回车换行。
	上代码。
调用‘命令行解析’、‘参数栈【主】’。

如果存在-h【主】那么先
	使主窗、侦听、
		创建为下代码
			使主窗、标题为‘应用标题’。
			使主窗、大小为400、400。
			使主窗、居中。
			使主窗、提示、‘-h’“有效参数如下：”回车换行先调用‘命令行帮助二’、、制表符、回车换行、0了。
		上代码。
	x。
	退出。
了。

如果‘-oor-p’那么
加载lib2/onlyonerun.zs、‘-oor-p’、下代码
	使主窗、激活。
	如果存在新页目录【主】那么删除新页目录【主】。
	调用‘命令行解析’、‘参数栈’。
	如果存在新页目录【主】那么使主窗、新开。
上代码。

显示首目录‘首目录’换行。