赋予【主】应用名以隧道标题。
加载lib/defi。
加载lib/defii。
加载lib/regexpr4。
加载lib/stdc。
加载lib/gjk4。
加载lib/file4。
加载lib/doscmd4。
加载lib/gjke4。

加载config.zs。
加载notify.zs。
加载login.zs。
加载msg.zs。
加载chat.zs。
加载mini.zs。
加载quno.zs。
加载add_a.zs。

隧道移动、先算术先隧道屏幕宽了-先隧道窗口宽了了、先算术(先隧道屏幕高了-先隧道窗口高了)/2了。

隧道webkit3、浏览器、notebook1、
	侦听、标签页切换、下代码
		导航按钮显示如果‘参数1’等于1那么0否则1。
		如果隧道webkit3、网址、浏览器等于false或者等于about:blank那么先
			赋予标题以隧道webkit3、标题提示、浏览器。
			隧道标题、先如果‘标题’那么“‘标题’ - ”了‘应用名’。
			隧道敏感、back、0。
			隧道敏感、forward、0。
			退出。
		了。
		赋予标题以隧道webkit3、标题、浏览器。
		如果‘标题’那么
			隧道标题、“‘标题’ - ‘应用名’”。
		导航按钮状态。
	上代码、
	侦听、请求、下代码
		别名网址以参数1。
		
		解释‘收取‘登录目标’消息’、‘网址’。
	上代码、
	侦听、装载完毕、下代码
		别名网址以参数1。
		
		如果进行登录‘网址’那么退出。
		
		（如果调用‘正则配’、‘网址’、^https://mail\.qq\.com/cgi-bin/loginpage\?、l那么先
			基于“隧道webkit3、元素、‘参数栈’、浏览器”先
				uin、焦点。
				uin、属性、value、‘qq帐号’。
				pp、焦点。
				pp、属性、value、‘qq密码’。
				（btlogin）
			了。
			退出。
		了。）
	上代码、
	侦听、装载完、下代码
		导航按钮状态。
	上代码、
	侦听、zhscript:、下代码
		别名数据以参数1。
		
		如果开始登录‘数据’那么退出。

		如果调用‘正则攫’、‘数据’、^chat\?q=(.*)、、el那么先
			得聊天记录‘之1’。
			退出。
		了。

		如果‘数据’等于about那么先
			新开页：关于、‘数据’、下代码
				加载lib/txtotxt4。
				隧道webkit3、内容、‘css’先调用‘html2text’、‘应用目录’/ad.txt、1、1了、浏览器。
			上代码。
			退出。
		了。

		如果‘数据’等于shortcut那么加载‘数据’.zs，退出。
		
		如果‘数据’等于noon那么隐藏左边栏1，退出。
		如果‘数据’等于no那么隐藏左边栏0，退出。

		执行“xdg-open ‘数据’&”。
	上代码、
	侦听、确认、下代码
		进行通知‘参数1’。
	上代码、
	侦听、覆盖链接、下代码
		隧道标题、“‘参数1’ - ‘应用名’”。
		隧道定时器、清除状态栏、5000、下代码
			隧道定时器、‘动作’、移除。
			赋予标题以隧道webkit3、标题、浏览器。
			如果‘标题’那么
				隧道标题、“‘标题’ - ‘应用名’”。
		上代码。
	上代码、
	侦听、标题改变、下代码
		隧道标题、“‘参数1’ - ‘应用名’”。
		隧道webkit3、标题提示、‘参数1’、浏览器。
	上代码。

赋予帐号列表以<option></option>。
迭代数组下代码
	赋予【上】帐号列表以‘帐号列表’“<option value="”先解密密码‘参数2’了">‘参数1’</option>。
上代码、qq帐号。

隧道webkit3、内容、“‘css’
<form action="zhscript:">
<table align=center>
	<tr><th></th><th></th></tr>
	<tr><td colspan=2><select onchange="u.value=this.options[this.selectedIndex].text;p.value=this.options[this.selectedIndex].value;">
		‘帐号列表’
		</select></td>
	</tr>
	<tr><td>帐号</td>
		<td><input type=text name=u value="‘qq帐号’"></td>
	</tr>
	<tr><td>密码</td>
		<td><input type=password name=p value="‘qq密码’" maxlength=16></td>
	</tr>
	<tr><td>目标</td>
		<td>”先
			迭代解释下代码
				“<input type=radio name=tag ”先如果‘参数1’等于‘登录目标’那么checked=on了“ value=‘参数1’>‘参数1’”。
			上代码、w.qq、web.qq。
		了“</td>
	</tr>
	<tr><td></td><td><input type=checkbox name=yin ”先如果存在隐身并且‘隐身’那么checked=on了“>隐身登入</td></tr>
	<tr><td></td><td><input type=submit value="登录"></td></tr>
	<tr><td></td><td>
	<input type=checkbox name=xiao ”先如果存在窗口最小化并且‘窗口最小化’那么checked=on了“>起初不显示
	<br>
	<input type=checkbox name=tuo ”先如果‘最小化到托盘’那么checked=on了“>最小化到托盘
	</td></tr>
</table>
</form>
”、浏览器#0。

隧道侦听、点击、qq、zhscript、下代码
	隧道webkit3、新开、‘参数1’、浏览器#0。
	导航按钮显示1。
上代码。

隧道侦听、点击、refresh、back、forward、下代码
	如果隧道内容、notebook1等于1那么退出。
	如果隧道webkit3、网址、浏览器等于false或者等于about:blank那么退出。
	隧道webkit3、‘参数1’、浏览器。
上代码。

隧道侦听、点击、set、set1、下代码
	别名标题以参数1。
	新开页：‘标题’、‘动作’、下代码
		隧道webkit3、内容、“
		<table align=center border=1>
			<tr><td></td><td></td></tr>
			<tr><td></td><td><a href="zhscript:shortcut">创建桌面快捷方式</a></td></tr>
			<tr><td></td><td></td></tr>
			<tr><td></td><td>
				聊天记录文件：<br>
				<a href="zhscript:‘聊天记录文件’">‘聊天记录文件’</a><br>
				<font size=1>需要安装有sqlite管理工具（如sqliteman）方能打开</font>
			</td></tr>
			<tr><td></td><td></td></tr>
			<tr><td></td><td><a href="zhscript:about">关于</a></td></tr>
		</table>
		”、浏览器。
	上代码。
上代码。

隧道代码、下代码
	如果‘肇事者’等于窗口那么先
		如果‘动作’等于创建那么先
			如果存在左边栏隐藏并且‘左边栏隐藏’那么
				隧道勾选、mini、1，隧道侦听、点击、mini，退出。
		了。
	了。
上代码。
