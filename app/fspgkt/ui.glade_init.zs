加载lib/defi。
加载lib2/js.zs。
加载lib2/config.zs。

配置文件加载。

赋予首页【主】以http://youxi.baidu.com/pgkt/index/。
赋予步骤【主】以.。
赋予bar高【主】以隧道窗口高、bar。

隧道webkit、浏览器、brow、
	侦听、装载完毕、下代码
		显示‘参数0’{‘参数’}↙。
		别名网址以参数1。
		如果‘网址’等于‘首页’那么先
			如果‘步骤’等于.那么先
				如果不存在帐号那么先
					隧道窗口最大化。
					隧道可见、brow、1。
					退出。
				了。
				赋予步骤【主】以‘步骤’.。
				隧道webkit、插脚、‘js函数集’
					val__("username","‘帐号’");
					val__("password","先调用‘urldecode’、‘密码’、‘应用实名’了");
					“var b=__("loginButton");”z$("",b.type);
					click__(b);
					、浏览器。
				退出。
			了。
			隧道webkit、插脚、“‘js函数集’
				var e=__("logined");
				if(e&&!is_hide__(e)){
					z$("”下代码
						赋予步骤【主】以‘步骤’.。
					上代码“");
					var a=e__(e,4,1);z$("",a.href);
					click__(a);
				}”、浏览器。
			退出。
		了。
		如果‘网址’等于http://youxi.baidu.com/pgkt/select/那么先
			赋予步骤【主】以‘步骤’.。
			隧道点击、fullscreen。
			隧道可见、brow、1。

			隧道定时器、鼠标位置、500、下代码
				迭代正则先隧道鼠标、brow了、([0-9]+),([0-9]+)、下代码
					如果‘参数1’小于10并且‘参数2’小于‘bar高’那么先
						隧道可见、bar、1。
						隧道定时器、鼠标位置、暂停。
					了否则
						隧道可见、bar、0。
				上代码。
			上代码。
			退出。
		了。
		如果调用‘正则配’、‘网址’、/game/main.php$、l那么先
			赋予步骤【主】以‘步骤’.。
			隧道点击、hide。
			退出。
		了。
	上代码、
	侦听、装载完、下代码
		隧道webkit、加强、浏览器。
	上代码、
	侦听、标题改变、下代码
		隧道标题、“已进入‘参数1’，稍候 ‘步骤’”。
	上代码、
	侦听、警告、下代码
		如果‘步骤’等于..那么先
			隧道窗口最大化。
			隧道可见、brow、1。
		了。
	上代码、
	侦听、z$、下代码
		显示‘参数0’{‘参数’}↙。
		当‘参数1’先
			等于s那么
				赋予‘参数2’以‘参数3’，退出。
			等于+那么先
				赋予1以调用‘正则格’、‘参数2’、([0-9]+)。
				赋予2以‘参数3’。
				算术‘1’+‘2’。
				退出。
			了。
			等于=那么
				隧道‘参数栈2’，退出。
			等于那么退出。
		了。
		解释‘参数栈’。
	上代码。
隧道webkit、访问、‘首页’、浏览器。
隧道标题、稍候。

隧道侦听、点击、quit、下代码
	结束。
上代码。
隧道侦听、点击、close、下代码
	隧道可见、bar、0。
	隧道定时器、鼠标位置、取消暂停。
上代码。
隧道侦听、点击、fullscreen、unfullscreen、下代码
	隧道‘参数1’。
	隧道可见、‘参数0’、0。
	隧道可见、先如果‘参数0’等于fullscreen那么un了fullscreen、1。
	隧道点击、close。
上代码。
隧道侦听、点击、hide、show、下代码
	如果‘参数0’等于hide那么先
		隧道webkit、插脚、“‘js函数集’
			var tt=__("top-toolbar");
			if(tt){
				z$("s","顶高【主】",tt.style.height);
			}”、浏览器。
	了。
	隧道webkit、插脚、‘js函数集’‘参数0’__("top-toolbar");、浏览器。
	隧道可见、‘参数0’、0。
	如果‘参数0’等于hide那么先
		隧道可见、show、1。
		隧道webkit、插脚、“‘js函数集’
			var gf=__("game_frame");
			if(gf){
				gf.style.height=z$("=","屏幕高")+"px";
			}”、浏览器。
	了否则
		隧道可见、hide、1。
上代码。
隧道侦听、点击、ind、uni、下代码
	隧道webkit、插脚、“‘js函数集’
		var gf=__("game_frame");
		if(gf){
			gf.style.height=z$("+",gf.style.height,”先如果‘参数0’等于uni那么-了“1)+"px";
		}”、浏览器。
上代码。
隧道侦听、点击、prop、下代码
	隧道窗口标题、pro、‘参数1’。
	如果存在帐号那么隧道内容、u、‘帐号’。
	如果存在密码那么隧道内容、pw、先调用‘urldecode’、‘密码’、‘应用实名’了。
	隧道可见、pro、1。
上代码。
隧道侦听、点击、save、下代码
	赋予帐号【主】以隧道内容、u。
	赋予密码【主】以调用‘urlencode’、先隧道内容、pw了、‘应用实名’。
	配置文件保存：-、密码【主】、帐号【主】。
	隧道可见、pro、0。
上代码。
隧道侦听、点击、save2、下代码
	隧道点击、save。
	赋予步骤【主】以.。
	隧道webkit、访问、‘首页’、浏览器。
上代码。
