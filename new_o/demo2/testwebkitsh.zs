#!../webkitsh --。
加载lib/defi。
加载lib2/js.zs。
加载lib/gjke4。

使主窗、侦听、
	创建为下代码
		使主窗、大小、1024、600。
		使主窗、居中。
		使主窗#1、加钮、-、（大小为6、）
			名为后退、gtk-go-back、
			名为前进、gtk-go-forward、
			名为刷新、gtk-refresh。
		使主窗、访问、http://baidu.com。
	上代码、
	显现为下代码
		使控制、创建（、弹出窗）。
		使控制、侦听、
			显现为下代码
				使控制、标题、控制。
				使控制、内容、<script>‘js函数集’下代码
					function go__(to) {
						z$('使主窗、' + to);
					}
					function msg__(s) {
						htm__(__("msg"), s);
					}
					function down__(){
						z$('使主窗#down、新开。
							使主窗、下载、
							https://www.google.com.hk/logos/2013/hong_xun_taos_85th_birthday-1437005.2-res.png、
							/tmp/1.png、
							下代码
								别名态以参数1。
								别名文件以参数2。
								使主窗#down、内容、‘参数’如果‘态’等于ok那么“<hr><img src=file://‘文件’>”、基址为file:///。
							上代码、by、down');
					}
					function go2__(to) {
						z$('显示先使主窗、' + to + '了换行');
					}
					</script>
					<style>body{font-size:10px;}</style>
					<a href="zhscript:back">后退</a>
					<input onclick="go__(this.value)" type=button value="前进">
					<input onclick="go__(this.value)" type=button value="刷新">
					<a href="javascript:go__('新开');">新开</a>
					
					<input onclick="go__(this.value)" type=button value="关闭">
					<a href="javascript:go__('不可关闭');">不可关闭</a>
					<input onclick="go__(this.value)" type=button value="销毁">
					<br>
					
					<a href="javascript:z$('',1,' b b ',false);">控制台输出信息</a>
					<br>
					
					youku：
					<a href="javascript:z$('使主窗#youku、新开');">新开</a> 
					<a href="javascript:z$('使主窗#youku、访问、http://youku.com。使主窗#youku、激活。');">访问</a> 
					<a href="javascript:z$('使主窗#youku、关闭');">关闭</a><br>
					
					<a href="javascript:down__()">下载</a><br>
					
					<input onclick="go2__(this.value)" type=button value="标签名">
					<input onclick="go__(this.value)" type=button value="标签名、a">
					<br>

					<hr><span id=msg></span><hr>
					
					链接：<span id=lian></span><br>
					进度：<span id=jindu></span><br>
					请求：<span id=qingqiu></span><br>
					类型请求：<span id=qingqiu2></span><br>
					消息：<span id=xiaoxi></span><br>
					装载完：<span id=zhuangwan></span><br>
					装载完毕：<span id=zhuangbi></span><br>
				上代码。
			上代码、
			zhscript:为下代码
				当‘参数1’先
					等于back那么使主窗、后退，跳出。
				了。
			上代码。
		使控制、不透明度、0.85。
		使控制、无修饰。
		使控制、大小、200、400。
		使控制、显现。
		使控制、移动、50、+-510。
	上代码、
	点击为下代码
		使主窗、‘参数1’。
	上代码、
	标题改变为下代码
		别名窗以参数2。
		使主窗、标题、‘参数’。
		使‘窗’、标签、“   ”。
	上代码、
	装载进度为下代码
		使控制、插脚、htm__("jindu","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	装载完为下代码
		使控制、插脚、htm__("zhuangwan","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	装载完毕为下代码
		使控制、插脚、htm__("zhuangbi","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	覆盖链接为下代码
		使控制、插脚、htm__("lian","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	请求为下代码
		使控制、插脚、htm__("qingqiu","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	类型请求为下代码
		使控制、插脚、htm__("qingqiu2","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	标签页切换为下代码
		使‘参数2’#‘参数1’、插脚、“z$("使主窗、标题、“"+document.title+"”")”。
	上代码、
	消息为下代码
		使控制、插脚、htm__("xiaoxi","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	警告为下代码
		使控制、插脚、htm__("xiaoxi","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	确认为下代码
		使控制、插脚、htm__("xiaoxi","先调用‘加反斜杠’、‘参数’、C了")。
	上代码、
	提问为下代码
		使控制、插脚、htm__("xiaoxi","先调用‘加反斜杠’、‘参数’、C了")。
	上代码。
使主窗、创建、顶标签页（、右标签页、标签竖向）（、文字标签）（、自动标签）（、可关闭标签）。
使代码为下代码
	显示‘参数0’--‘参数’换行。
上代码。
