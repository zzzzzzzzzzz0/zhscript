加载common.zs。

（加载lib/gtkmain4。

赋予成以调用‘gtk-init-check’。
如果不‘成’那么先
	<<<<gtk-init-check失败。
	退出。
了。）

定义隧道【主】【锁】以下代码
	<<<<‘参数’。
	当‘参数1’先
		等于终止那么（调用‘gtk-main-quit’），跳出。
	了。
上代码。

赋予成以调用‘启动【mongoose4】’、‘端口号’、
	document_root	为‘root’、
	index_files		为index.wzs,index.html,index.cgi。
如果不‘成’那么先
	<<<<启动失败。
	退出。
了。

（调用‘gtk-main’。）
调用‘循环【mongoose4】’。
调用‘停止【mongoose4】’。
加载lib/mongoose4-。