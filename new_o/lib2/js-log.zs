如果存在“日志队列【主】”那么退出。
加载“lib/gjks4”。
加载“lib2/js.zs”。
加载“lib/redireconsoi4”。

赋予“日志队列【主】”以调用‘新建队列’。

定义“日志输出【主】”以下代码
	调用‘入队列’、‘日志队列【主】’、‘参数1’。
上代码。
定义“日志出错输出【主】”以下代码
	日志输出“<span style="color:red">‘参数1’</span>”。
上代码。
定义“日志提示输出【主】”以下代码
	日志输出“<span style="color:green">‘参数1’</span>”。
上代码。

赋予“日志函数集【主】”以下代码
	if(__("log")) {
		window.setInterval(function() {
			var line = z$("调用‘出队列’、‘日志队列【主】’");
			if("" == line)
				return;
			var d = new__("span");
			htm__(d, line + "<br>");
			ins__(d, __("log"), 0);
			if(on_log__)
				on_log__(line);
		}, 20);
	} else {
		alert("缺少 id 为 log 的元素");
	}
上代码。

定义“外壳命令【主】”以下代码
	调用‘重定向输出\行’、下代码
		日志输出‘参数1’。
	上代码、、下代码
		日志出错输出‘参数1’。
	上代码、‘参数1’。
上代码。
