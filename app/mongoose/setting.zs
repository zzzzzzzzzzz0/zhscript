加载lib/sqlite4。

赋予设置库【主】【锁】以调用‘打开【sqlite4】’、‘应用目录’setting.sqlite。
调用‘执行【sqlite4】’、‘设置库’、“CREATE TABLE IF NOT EXISTS setting__(
	id_ INTEGER PRIMARY KEY AUTOINCREMENT,
	name_ TEXT,
	value_ TEXT,
	use_ INTEGER
)”。

调用‘得表格’、下代码
	赋予数目【上】以‘参数1’。
上代码、‘设置库’、“SELECT count(*) FROM setting__”。
如果‘数目’等于0那么先
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('端口号','8083',1)”。
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('sudo密码','',3)”。

	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('关机','管理员命令poweroff',4)”。
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('重启','管理员命令reboot',4)”。
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('iptables -L','管理员命令“iptables -L”',4)”。
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('屏幕保护（黑屏）','命令“gnome-screensaver-command -a &”。',2)”。
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('启动x时钟','命令“xclock &”、不回。',2)”。
	调用‘执行【sqlite4】’、‘设置库’、“INSERT INTO setting__(name_,value_,use_)VALUES('问好','”下原样
赋予时以调用‘串格时间方法’、%H。
当‘时’先
	大于等于6并且小于13那么显示早，跳出。
	大于等于13并且小于20那么显示午，跳出。
	那么显示晚。
了。
显示安。
上原样“',2)”。
了。

调用‘得表格’、下代码
	别名名以参数1。
	别名值以参数2。
	别名用以参数3。
	<<<<‘名’→‘值’。
	如果‘用’等于3那么
		赋予值以解密‘值’。
	赋予‘名’【主】以‘值’。
上代码、‘设置库’、“SELECT name_,value_,use_ FROM setting__ WHERE use_=1 or use_=3”。
