隧道窗口宽高、200、200。
隧道无边框。
隧道置顶。
加载lib/file4。
赋予【顶】【锁】程序目录以解释‘目录名’。
隧道错误提示到控制台。

隧道菜单、menu1、drawingarea1。
隧道侦听、点击、exit、“隧道终止”。
隧道侦听、点击、w2、h2、w_2、h_2、下代码
	赋予宽以隧道窗口宽。
	赋予高以隧道窗口高。
	加载lib/gjk4。
	当‘动作’先
		等于w2那么赋予宽以算术‘宽’*2，跳出。
		等于h2那么赋予高以算术‘高’*2，跳出。
		等于w_2那么赋予宽以算术‘宽’/2，跳出。
		等于h_2那么赋予高以算术‘高’/2，跳出。
	了。
	显示‘宽’、‘高’字符10。
	隧道窗口宽高、‘宽’、‘高’。
上代码。

赋予【顶】【锁】画架以隧道绘图、画架、drawingarea1。
定义【顶】【锁】【无参】π以3.14159。
隧道绘图、代码、“加载draw.zs。”、‘画架’。

隧道定时器、刷新、1000、“隧道绘图、刷新、‘画架’。”。

隧道代码、下代码
	显示‘肇事者’-‘动作’-‘参数’字符10。
	如果‘肇事者’等于窗口并且‘动作’等于创建或者等于大小改变那么
		隧道窗口背景、‘程序目录’bg.png。
上代码。

