赋予【主】应用名以隧道标题。
加载lib/defi。
加载lib/defii。
加载lib/regexpr4。
加载lib/stdc。
加载lib/gjk4。
加载lib/file4。
加载lib/doscmd4。
加载lib/gjke4。
加载lib/txtotxt4。
加载lib2/js.zs。
加载lib/clpars4。

加载config.zs。
加载notify.zs。
加载login.zs。
加载msg.zs。
加载chat.zs。
加载mini.zs。
加载quno.zs。
（加载add_a.zs。）
加载tp.zs。
加载test.zs。
调用‘命令行解析’、‘参数栈’。

隧道移动、先算术先隧道屏幕宽了-先隧道窗口宽了了、先算术(先隧道屏幕高了-先隧道窗口高了)/2了。
隧道定时器、wnck、100、下代码
	加载lib/wnck4。
	如果不存在屏那么先
		赋予屏【主】以调用‘屏得’。
		显示屏‘屏’↙。
		如果不‘屏’那么删除屏【主】，退出。
		调用‘屏强更’、‘屏’。
	了。
	赋予窗以调用‘窗得’、隧道xid。
	显示窗‘窗’↙。
	如果不‘窗’那么退出。
	隧道定时器、‘参数0’、移除。
	调用‘总在可见工作区’、‘窗’。
上代码。

隧道webkit、浏览器、notebook1、
	侦听、标签页切换、下代码
		导航按钮显示如果‘参数1’等于1那么0否则1。
		如果隧道webkit、网址、浏览器等于false或者等于about:blank那么先
			设置标题。
			隧道敏感、back、0。
			隧道敏感、forward、0。
			退出。
		了。
		设置标题。
		导航按钮状态。
	上代码、
	侦听、请求、下代码
		别名网址以参数1。
		如果存在--test那么显示‘参数0’--‘网址’↙。
		
		解释‘收取‘登录目标’消息’、‘网址’。
	上代码、
	侦听、装载完毕、下代码
		隧道webkit、加强、浏览器。
		别名网址以参数1。
		
		如果进行登录‘网址’那么退出。
	上代码、
	侦听、装载完、“导航按钮状态”、
	侦听、z$、下代码
		（显示‘参数0’{‘参数’}↙。）
		当‘参数1’先
			等于g那么先
				‘‘参数2’’。
				退出。
			了。
			等于s那么先
				赋予‘参数2’以‘参数3’。
				退出。
			了。
			等于e那么先
				如果存在‘参数2’那么true否则false。
				退出。
			了。
			等于f那么先
				解释‘参数2’“‘参数栈’”、‘参数栈3’。
				退出。
			了。
			等于那么先
				显示‘参数栈2’↙。
				退出。
			了。
			等于选帐号那么先
				别名号以参数2。
				如果‘号’等于0那么
					赋予【顶】qq帐号以赋予【顶】qq密码以。
				否则先
					赋予【顶】qq帐号以‘qq帐号之‘号’之1’。
					赋予【顶】qq密码以解密密码‘qq帐号之‘号’之2’。
					赋予登设以登入设置之‘号’之。
					如果存在‘登设’1那么先
						定义布尔以“如果‘‘参数1’’那么true否则false”。
						隧道webkit、插脚、‘js函数集’
							__("tag先如果‘‘登设’1’等于w.qq那么1否则2了").checked=true;
							__("yin").checked=先布尔‘登设’2了;
							__("xiao").checked=先布尔‘登设’3了;
							__("tuo").checked=先布尔‘登设’4了;
							、浏览器#0。
					了。
				了。
				隧道webkit、插脚、‘js函数集’val__("u","‘qq帐号’");val__("p","‘qq密码’");、浏览器#0。
				退出。
			了。
		了。
		如果存在参数栈2那么先
			解释‘参数1’、‘参数栈2’。
			退出。
		了。
		解释‘参数1’。
	上代码、
	侦听、zhscript:、下代码
		别名数据以参数1。

		如果调用‘正则攫’、‘数据’、^chat\?q=(.*)&l=(.*)$、、el那么先
			得聊天记录‘之1’、‘之2’。
			退出。
		了。

		如果开始登录‘数据’那么退出。

		当‘数据’先
			等于about那么先
				新开页：关于、‘数据’、下代码
					隧道webkit、内容、‘css’先调用‘html2text’、‘应用目录’/ad.txt、1、1了、浏览器。
				上代码。
				退出。
			了。
			等于shortcut或者等于tp或者等于u11st-wl那么加载‘数据’.zs、1，退出。
			等于cache那么赋予数据以‘缓存目录’，跳出。
			等于noon那么隐藏左边栏1，退出。
			等于no那么隐藏左边栏0，退出。
		了。

		执行“xdg-open ‘数据’&”。
	上代码、
	侦听、确认、下代码
		进行通知‘参数1’。
	上代码、
	侦听、覆盖链接、下代码
		隧道标题、“‘参数1’ - ‘应用名’”。
		隧道一次定时器、清除状态栏、5000、【代码】“设置标题。”。
	上代码、
	侦听、标题改变、下代码
		隧道webkit、标题提示、‘参数1’、浏览器。
		设置标题。
	上代码。

赋予帐号列表以<option></option>。
序遍历数组下代码
	赋予【上】帐号列表以“‘帐号列表【上】’<option id=u‘参数1’>‘参数2’</option>”。
上代码、qq帐号。

隧道webkit、内容、“‘css’
<form action="zhscript:">
<table align=center>
	<tr><th></th><th></th></tr>
	<tr><td colspan=2><select onchange="z$('选帐号',this.selectedIndex);">
		‘帐号列表’
		</select></td>
	</tr>
	<tr><td>帐号</td>
		<td><input type=text name=u id=u value="‘qq帐号’"></td>
	</tr>
	<tr><td>密码</td>
		<td><input type=password name=p id=p value="‘qq密码’" maxlength=16></td>
	</tr>
	<tr><td>目标</td>
		<td>”先
			序迭代解释下代码
				别名号以参数1。
				别名标以参数2。
				“<input type=radio name=tag id=tag‘号’ ”如果‘标’等于‘登录目标’那么checked=on。
				如果‘号’等于1那么
					“ disabled><del>‘标’</del>”。
				否则
					“ value=‘标’>‘标’”。
			上代码、w.qq、web.qq。
		了“</td>
	</tr>
	<tr><td></td><td><input type=checkbox name=yin id=yin ”先如果存在隐身并且‘隐身’那么checked=on了“>隐身登入</td></tr>
	<tr><td></td><td><input type=submit value="登录"></td></tr>
	<tr><td></td><td>
	<input type=checkbox name=xiao id=xiao ”先如果存在窗口最小化并且‘窗口最小化’那么checked=on了“>起初不显示
	<br>
	<input type=checkbox name=tuo id=tuo ”先如果‘最小化到托盘’那么checked=on了“>最小化到托盘
	</td></tr>
</table>
</form>
”、浏览器#0。

隧道侦听、点击、qq、zhscript、下代码
	隧道webkit、新开、‘参数1’、浏览器#0。
	导航按钮显示1。
上代码。

隧道侦听、点击、refresh、back、forward、下代码
	如果隧道内容、notebook1等于1那么退出。
	如果隧道webkit、网址、浏览器等于false或者等于about:blank那么退出。
	隧道webkit、‘参数1’、浏览器。
上代码。

隧道侦听、点击、set、set1、下代码
	别名标题以参数1。
	新开页：‘标题’、‘动作’、下代码
		隧道webkit、内容、“‘css’
		<table align=center>
			<tr><td><a href="zhscript:shortcut"> 创建桌面快捷方式 </a></td></tr>
			<tr style="text-align:left;"><td>
				聊天记录文件：<br>
				<a href="zhscript:‘聊天记录文件’">‘聊天记录文件’</a><br>
				需要安装有 sqlite 管理工具（如 sqliteman ）方能打开
			</td></tr>
			<tr><td><a href="zhscript:cache"> 头像缓存文件夹 </a></td></tr>
			<tr><td><a href="zhscript:u11st-wl"> 使能显示在 ubuntu 11.04 系统托盘里 </a></td></tr>
			<tr><td><a href="zhscript:tp"> 注册用于 firefox / chrome 中的 tencent: 协议 </a></td></tr>
			<tr><td><a href="zhscript:about"> 关于 </a></td></tr>
		</table>
		”、浏览器。
	上代码。
上代码。

隧道代码、下代码
	如果‘肇事者’等于窗口并且‘动作’等于创建那么先
		如果存在左边栏隐藏并且‘左边栏隐藏’那么
			隧道勾选、mini、1，隧道侦听、点击、mini，退出。
	了。
上代码。
