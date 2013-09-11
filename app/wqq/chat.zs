
隧道侦听、点击、chat、chat1、下代码
	新开页‘参数1’、‘动作’、下代码
		得聊天记录。
	上代码。
上代码。

加载lib/sqlite4。
赋予【主】聊天记录文件以‘配置目录’/chat.sqlite。
赋予【主】聊天记录库以调用‘【sqlite4】打开’、‘聊天记录文件’。
调用‘【sqlite4】执行’、‘聊天记录库’、“CREATE TABLE IF NOT EXISTS 
chat__(
id_ INTEGER PRIMARY KEY,
name_ VARCHAR(12),
time_ VARCHAR(14),
text_ TEXT,
get_time_ VARCHAR(19),
qq_  INTEGER
);”。

定义【主】保存聊天记录以下代码
	别名条以参数1。
	当‘登录目标’先
		等于w.qq那么先
			如果调用‘正则攫’、‘条’、“([^字符10]+)[ ]+([0-9:-]+)字符10(.+)”那么先
				别名名以之1。
				别名qq时以之2。
				别名消息以之3。
				跳出。
			了。
			退出。
		了。
		等于web.qq那么先
			别名名以参数1。
			别名qq时以参数2。
			别名消息以参数3。
			跳出。
		了。
	了。
	赋予时间以调用‘串格时间方法’、%Y.%m.%d.%H.%M.%S。
	调用‘【sqlite4】执行’、‘聊天记录库’、“INSERT INTO chat__ VALUES(NULL,'‘名’','‘qq时’','‘消息’','‘时间’',‘qq帐号’);”。
上代码。

定义【主】得聊天记录以下代码
	赋予参以调用‘urldecode’、‘参数1’。
	赋予sql以“select * from chat__ ”先
		如果调用‘正则配’、‘参’、“^where ”、l那么‘参’
		否则先
			如果‘参’不等于“”那么“where text_ like '%‘参’%' ”。
			“order by get_time_ desc,time_ desc limit 100”
		了
	了;。
	显示‘sql’↙。
	
	赋予内容以“<table width=100%>
		<tr><td colspan=4>
		<form action="zhscript:chat">
		<input type=text name=q size=40 value="‘参’">
		<input type=submit value="搜">
		</form>
		</td></tr><tr>
		<td>时间（get_time_）</td>
		<td>帐号（qq_）</td>
		<td nowrap>昵称（name_）</td>
		<td>消息（text_）</td>
		</tr>”。
	赋予错以调用‘【sqlite4】得表’、下代码
		别名时间以参数5。
		别名帐号以参数6。
		别名昵称以参数2。
		别名带时间以参数3。
		别名消息以参数4。
		赋予消息以调用‘正则替’、‘消息’、(↙)、<br>。
		
		如果存在上帐号并且‘上帐号’等于‘帐号’那么
			赋予帐号以。
		否则
			赋予【上】上帐号以‘帐号’。
		如果存在上昵称并且‘上昵称’等于‘昵称’那么
			赋予昵称以。
		否则
			赋予【上】上昵称以‘昵称’。
		
		赋予【上】内容以‘内容’“<tr>
			<td valign=top>‘时间’</td>
			<td valign=top>‘帐号’</td>
			<td valign=top>‘昵称’</td>
			<td align=left>‘带时间’<br>‘消息’</td>
			</tr>”。
	上代码、‘聊天记录库’、‘sql’、0。
	如果‘错’那么
		赋予内容以‘内容’“<tr><td colspan=4>‘sql’<br>‘错’</td></tr>”。
	赋予内容以‘内容’</table>。
	隧道webkit3、内容、‘css’‘内容’、浏览器。
上代码。