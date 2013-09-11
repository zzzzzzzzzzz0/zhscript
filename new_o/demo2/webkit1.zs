#!../gtkmmsh lib2/webkit1.glade --。
（#!/usr/lib/zhscript/gtkmmsh lib2/webkit1.glade --。）
隧道窗口宽高为750、500。

赋予webkit【主】以webkit。
赋予主页【主】以http://baidu.com。
赋予user-agent【主】以。
赋予页式【主】以window。
赋予标签标题【主】以0。

加载lib/clpars4。
调用‘命令行加回调’、
	max、“隧道窗口最大化”、0、、
	center、“隧道窗口居中”、0、、
	w,h、下代码
		隧道窗口宽高为‘参数1’、‘参数2’。
	上代码、2、、
	fs、全屏支持、0、下代码
		隧道可见为fullscreen、_2为1。
		隧道侦听、点击、fullscreen、unfullscreen、下代码
			隧道‘参数1’。
			隧道可见、‘参数0’、0。
			隧道可见、先如果‘参数0’等于fullscreen那么un了fullscreen、1。
		上代码。
	上代码、
	tray、“隧道最小化到托盘”、0、、
	tray2、“隧道最小化到托盘、驻留”、0、、
	tray3、“隧道托盘应用”、0、、
	title、下代码
		隧道标题为‘参数1’。
	上代码、1、、
	u-a、下代码
		赋予user-agent【主】以‘参数1’。
	上代码、1、、
	u-a-ie、、0、“赋予user-agent【主】以“Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0;)”。”、
	u-a-ff、、0、“赋予user-agent【主】以“Mozilla/5.0 (X11; Linux i686; rv:7.0.1) Gecko/20100101 Firefox/7.0.1”。”、
	u-a-ff-w、、0、“赋予user-agent【主】以“Mozilla/5.0 (Windows NT 5.1; rv:5.0) Gecko/20100101 Firefox/5.0”。”、
	u-a-o、、0、“赋予user-agent【主】以“Opera/9.80 (X11; Linux i686; U; zh-cn) Presto/2.10.229 Version/11.60”。”、
	u-a-o-w、、0、“赋予user-agent【主】以“Opera/9.80 (Windows NT 5.1; U; en) Presto/2.9.168 Version/11.52”。”、
	tt、“标签栏显示为网页标题，默认‘标签标题’”、0、下代码
		赋予标签标题【主】以1。
	上代码、
	window|notebook-left|notebook-top|notebook-right|notebook-bottom、“浏览器样式，默认‘页式’。第一个为单页，后均为多页而标签位置不同”、0、下代码
		赋予页式【主】以‘参数0’。
	上代码、
	webkit3、、0、下代码
		赋予webkit【主】以‘参数0’。
	上代码、
	help、、0、下代码
		隧道提示、调用‘命令行帮助’。
		隧道终止。
	上代码、
	、设置主页，默认‘主页’、1、下代码
		赋予主页【主】以‘参数1’。
	上代码。
调用‘命令行解析’、‘参数栈【主】’。
加载lib/clpars4-。

隧道可见、‘页式’、1。
隧道‘webkit’、浏览器、‘页式’、
	侦听、装载完、下代码
		隧道敏感、back、先隧道‘webkit’、可后退、浏览器了。
		隧道敏感、forward、先隧道‘webkit’、可前进、浏览器了。
	上代码、
	侦听、标题改变、下代码
		别名标题以参数1。
		隧道标题为‘标题’。
		如果‘页式’不等于window那么先
			隧道‘webkit’、标题提示、‘标题’、浏览器。
			如果‘标签标题’那么
				隧道‘webkit’、标签、‘标题’、浏览器。
		了。
	上代码、
	侦听、标签页切换、下代码
		隧道标题为先隧道‘webkit’、标题提示、浏览器了。
	上代码、
	user-agent为‘user-agent’。

隧道侦听、点击、refresh、back、forward、下代码
	隧道‘webkit’、‘参数1’、浏览器。
上代码。
隧道侦听、点击、home、下代码
	隧道‘webkit’、访问、‘主页’、浏览器。
上代码。
隧道提示文字、home、‘主页’。

隧道点击、home。