#!../../bin/gtkmmsh lib2/window1.glade --。
隧道窗口宽高、600、400。
隧道窗口居中。
隧道内容、text、下原样这是zhanfeng样式棋子、棋盘设置程序。
提供有：
方案1
随机方案——随机从已有棋子、棋盘素材目录里抽取来组成样式
几种样式按钮，点击设置，
然后点击“看下”便能启动程序来看效果上原样。

加载../../start.zs。
加载lib/file4。
加载lib/defi。
加载lib/stdc。
加载lib/doscmd4。
加载lib/gjke4。
加载lib/gjk4。

赋予目录【主】以调用‘得目录名’、先调用‘最终文件名’、‘参数0’了。
隧道标题为‘目录’。
赋予1目录以调用‘移除..’、‘目录’../xqbase/。
显示‘1目录’↙。
赋予子目录1【主】以1-/。
赋予目录1以调用‘移除..’、‘目录’‘子目录1’。
显示‘目录1’↙。

赋予搜以调用‘dir.begin’、‘1目录’、^..\.gif$、o0。
循环先
	赋予1以调用‘dir.next’、‘搜’。
	如果‘1’等于“”那么跳出。
	显示‘1’,。
	增至数组棋子【主】、1、‘1’。
了。
调用‘dir.end’、‘搜’。
显示↙‘棋子数目’↙。
遍历目录下代码
	显示‘参数1’,。
	增至数组资源【主】、1、‘参数1’。
上代码、‘目录1’。
显示↙‘资源数目’↙。
遍历目录下代码
	显示‘参数1’,。
	增至数组盘【主】、1、‘参数1’。
上代码、‘目录’canvas、\.png$。
显示↙‘盘数目’↙。

定义“执行选定方案”【主】以下代码
	隧道内容、text、。

	定义“显示一”以“隧道插入、text、‘参数1’”。
	当‘方案’先
		等于0那么先
			调用‘随机数种’、-1。
			调用‘随机数组’、随机、1、‘资源数目’。
			遍历数组下代码
				显示一‘参数’,。
			上代码、随机。
			显示一↙‘随机数目’↙。
			赋予号以0。
			循环先
				赋予号以算术‘号’+1。
				如果‘号’大于‘棋子数目’那么跳出。
				增至数组号、1、‘资源之‘随机之‘号’’’。
			了。

			赋予号以调用‘随机数方法’、‘盘数目’、1。
			显示一‘号’/‘盘数目’↙。
			赋予盘子以‘盘之‘号’’。

			跳出。
		了。
		等于1那么先
			（士象炮将马卒车）
			增至数组号、1、
				（5-17-FAD18d01）D-1E-E977Cd01、7-35-20B1Fd01、A-7E-B15EBd01、8-DB-DB9F9d01、3-75-7CBC3d01、1-14-8CEBBd01、9-6A-6C0C1d01、
				（0-87-EE38Cd01）4-CA-A7390d01、4-76-31B32d01、4-F9-EA72Dd01、E-59-3CFA5d01、7-3B-C9659d01、1-8F-F9235d01、6-95-F4A96d01、
				。
			赋予盘子以3c.png。
			跳出。
		了。
	了。

	定义“执行一”以“隧道插入、text、‘参数1’↙。执行‘参数1’”。
	调用‘改变目录函数’、‘配置目录’。
	序遍历数组下代码
		执行一“ln -sf '‘目录’‘子目录1’‘号之‘参数1’’' ‘参数2’”。
	上代码、棋子。
	执行一“ln -sf '‘目录’canvas/‘盘子’' canvas.png”。
	执行一“ln -sf -t . \”↙
		“'‘目录’defiii.zs' \”↙
		“'‘目录’ui.glade'”。
上代码。

隧道提示文字、exec、方案1。
隧道侦听、点击、exec、下代码
	赋予方案【主】以1。
	执行选定方案。
上代码。

隧道可见、exec2、1。
隧道提示文字、exec2、随机方案。
隧道侦听、点击、exec2、下代码
	赋予方案【主】以0。
	执行选定方案。
上代码。

隧道可见、exec3、1。
隧道提示文字、exec3、看下效果。
隧道侦听、点击、exec3、下代码
	调用‘改变目录函数’、‘目录’../..。
	执行./start.sh&。
上代码。

如果存在参数1那么先
	隧道一次定时器、、1s、下代码
		隧道点击、exec。
		隧道一次定时器、、1s、“隧道终止”。
	上代码。
了。