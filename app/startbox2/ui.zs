加载lib/clpars4。
赋予后不退【主】以。
调用‘命令行加回调’、
	w、、1、下代码
		赋予【主】命令写入文件以‘参数1’。
	上代码、
	ne、、0、下代码
		赋予后不退【主】以checked。
	上代码。
调用‘命令行解析’、‘参数栈’。

定义点中效果【主】以下代码
	赋予历以““var e=__("fengmian‘号’")/*.parentNode*/.getElementsByTagName("*");
		for(var i=0;i<e.length;i++){
			var s=e[i].style;””
			s.backgroundColor=下代码‘参数1’上代码;
			s.borderColor=s.color=下代码‘参数2’上代码;
		}。
	使主窗、插脚、先解释‘历’、"white"、"#000"了。
	调用‘新建一次定时器’、点‘号’后、0.4s、“使主窗、敏感、1。
		使主窗、插脚、下代码”先解释‘历’、null、null了“上代码”。
上代码。

定义得后不退【主】以下代码
	使主窗、插脚、“var e=__("no_exit");if(e)”
		z$("“赋予后不退【主】以”" + (e.checked ? "checked" : ""))。
上代码。

定义点击【主】以下代码
	别名号以参数1。
	别名行以项目之‘号’之1。
	如果不‘行’那么退出。
	别名控以项目之‘号’之4。
	得后不退。
	使主窗、敏感、0。
	点中效果。
	系统命令‘行’、‘控’、‘后不退’。
上代码。

赋予夹数【主】以0。
定义标夹成员【主】以下代码
	别名号以参数1。
	（‘和谐前景色’）
	赋予色以#当算术‘夹数’ % 6先
		等于4那么f00，跳出。
		等于0那么0f0，跳出。
		等于6那么00f，跳出。
		等于1那么ff0，跳出。
		等于2那么0ff，跳出。
		等于3那么f0f，跳出。
		fff。
	了。
	赋予夹数【主】以算术‘夹数’+1。
	别名数以项目之‘号’之1。
	循环先
		如果‘数’小于0那么跳出。
		使主窗、插脚、“__("fengmian‘号’").style.borderTop="2px solid ‘色’"”。
		赋予号以算术‘号’-1。
		赋予数以算术‘数’-1。
	了。
上代码。

定义进行折叠【主】以下代码
	别名号以参数1。
	别名动作以参数2。
	别名数以项目之‘号’之1。
	循环先
		如果‘数’小于1那么跳出。
		赋予号以算术‘号’-1。
		使主窗、插脚、‘动作’__("fengmian‘号’")。
		赋予数以算术‘数’-1。
	了。
上代码。
定义“夹点击”【主】以下代码
	别名号以参数1。
	别名夹态以项目之‘号’之夹态。
	别名夹名以项目之‘号’之夹名。
	赋予夹态以如果‘夹态’等于*那么|否则*。
	进行折叠‘号’、如果‘夹态’等于*那么hide否则show。
	点中效果。
	使主窗、插脚、htm__("title‘号’", "‘夹态’‘夹名’")。
	赋予项目之‘号’之夹态【顶】以‘夹态’。
上代码。

加载init.zs。

使代码为下代码
	当‘参数0’先
		等于请求
		或者等于覆盖链接
		或者等于装载进度
		那么退出。
	了。
	显示‘参数0’--‘参数’换行。
上代码。

定义“大刷新图标夹”【主】以下代码
	得后不退。
	清空图标夹。
	（“gedit ‘配置文件’.*”）
	增至顶数组项目、4、“执行“cd '‘所在目录’';./edit.zs&””、‘项目名’编辑、‘所在目录’icon.png、无。
	增至顶数组项目、4、“执行“cd '‘所在目录’';./edit2.zs&””、‘项目名’编辑2、‘所在目录’icon.png、无。
	刷新图标夹。
	赋予样1以“color:‘和谐前景色’;background-color:‘和谐背景色’;
	border:1px dashed ‘和谐前景色’”。
	增加图标opt2、“<div class=img>
	<a style="‘样1’" href="javascript:z$('大刷新图标夹啊')">刷新</a></div>”。
	增加图标opt、“<div style="‘样1’;text-align:left;">
	<input id=no_exit type=checkbox ‘后不退’> 启动后盒不按设定退出</div>”。
上代码。

使主窗、侦听、
	创建为下代码
		使主窗、类名、‘应用名’、‘应用名’2。
		使主窗、大小、900、600。
		使主窗、最大化。
		使主窗、标题、‘项目名’。
		初始图标夹。
	上代码、
	装载完毕为下代码
		调用‘新建一次定时器’、创建、0.5s、“大刷新图标夹”。
	上代码。
