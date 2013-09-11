赋予【主】管道以/tmp/mplayer-slave-。
执行“mkfifo ‘管道’”。
定义【主】给我以下代码
	显示‘参数’字符10。
	如果不存在【主】已经打开那么退出。
	执行显示“echo ‘参数’ > ‘管道’ &”字符10。
上代码。
隧道侦听为点击为toolbutton1为下代码
	赋予wid以隧道xid为drawingarea1。
	显示wid=‘wid’字符10。
	如果‘wid’那么先
		执行显示“mplayer -wid ‘wid’ -slave -quiet -input file=‘管道’ media/test.flv &”字符10。
		赋予【主】已经打开以1。
	了。
上代码。
隧道侦听为点击为toolbutton2为下代码
	给我pause。
上代码。
隧道侦听为点击为toolbutton6为下代码
	给我stop。
上代码。
隧道内容为源码为下代码
	如果‘肇事者’等于窗口并且‘动作’等于销毁那么先
		给我stop。
		给我exit。
		执行“rm ‘管道’”。
		退出。
	了。
上代码。

