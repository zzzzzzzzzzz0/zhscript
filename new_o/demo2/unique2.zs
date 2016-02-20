#!../srcvwsh --。
加载lib/defi。

加载lib/unique4。
赋予app【主】以调用‘unique_app_new’、zhscript.demo2.unique2、NULL。
显示app=‘app’换行。
赋予在以调用‘unique_app_is_running’、‘app’。
显示running=‘在’换行。
如果‘在’那么先
	调用‘发消息’、‘参数’、‘UNIQUE_ACTIVATE’、‘app’。
	结束。
了。

使主窗、侦听、
	创建为下代码
		调用‘unique_app_watch_window’、‘app’、先使主窗、地址了。
		调用‘加回调’、下代码
			使主窗、内容、‘参数’。
		上代码、‘app’。

		使主窗、大小、200、200。
		使主窗、居中。
		使主窗、标题、‘参数0【主】’。
	上代码、
	销毁为下代码
		调用‘断开’、‘app’。
	上代码。

