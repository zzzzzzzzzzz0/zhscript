加载lib/defi。
加载lib2/iconview.zs。
加载lib/gjk4。
赋予【主】~以调用‘得环境变量方法’、HOME。
赋予【主】配置目录以‘~’/.config/startbox_zs。
赋予【主】配置文件以‘配置目录’/init2.zs。
加载lib/file4。
赋予【主】所在目录以调用‘得目录名’、‘【上】参数0’。

加载lib/doscmd4。
定义【主】刷新图标夹以下代码
	别名夹以参数1。
	别名控以参数2。

	隧道图标夹为清空为‘夹’。
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		别名标题以项目之‘号’之2【顶】。
		如果不存在标题那么跳出。
		别名图标以项目之‘号’之3。
		赋予图标以置换图标‘图标’。
		如果存在控并且调用‘exist’、‘图标’等于0那么
			赋予图标以‘所在目录’no.png。
		图标夹增加‘夹’为‘项目之‘号’之1’、‘标题’、‘图标’、‘项目之‘号’之4’。
	了。
上代码。

定义【主】确定图标以下代码
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数数目’那么跳出。
		如果调用‘exist’、‘参数‘号’’那么‘参数‘号’’，退出。
	了。
	赋予1以/usr/share/icons/hicolor/scalable/apps/gnome-panel-launcher.svg。
	如果调用‘exist’、‘1’那么‘1’，退出。
	/usr/share/icons/Humanity/apps/48/application-default-icon.svg。
上代码。
赋予缺省图标【主】以确定图标。
定义反置换图标【主】以下代码
	别名标以参数1。
	如果‘标’等于‘缺省图标’那么
		赋予标以缺省。
	‘标’。
上代码。
定义置换图标【主】以下代码
	别名标以参数1。
	如果‘标’等于缺省那么
		赋予标以‘缺省图标’。
	‘标’。
上代码。

定义【主】分析选项参数以下代码
	赋予【上】后退以‘参数1’。
	赋予【上】脚本以0。
	解释【代码】“基于“
		如果不存在参数2那么退出。
		赋予【上】【上】【上】‘参数1’以‘参数2’。
	”先”‘参数1’“了。”。
上代码。

定义【主】系统命令以“
分析选项参数‘参数2’。
如果存在命令写入文件【主】那么先
	调用‘echo’、#!先
			如果‘脚本’那么先
				赋予l以‘所在目录’l。
				如果调用‘exist’、‘l’否则
					赋予l以‘所在目录’../../new_o/l。
				。
				“‘l’ ---- ‘【主】参数’ ---- --。”
				↙
				“赋予0以‘【主】参数0’。”
			了否则/bin/sh
		了↙‘参数1’↙、‘命令写入文件’。
	执行“chmod +x '‘命令写入文件’'”。
了否则先
	如果‘脚本’那么解释‘参数1’。
	否则先
		赋予返回码以执行‘参数1’&。
		如果‘返回码’不等于0那么隧道提示为‘参数1’↙返回码是‘返回码’，退出。
	了。
了。
如果存在参数3并且‘参数3’那么退出。
如果隧道勾选、no_exit并且‘后退’小于等于1那么退出。
如果‘后退’那么隧道终止。
”。

加载lib/gjke4。
如果调用‘exist’、‘配置文件’.2那么
	加载updatesetting4kw.zs
否则
	加载updatesetting4kw.zs、0。
赋予号以0。
循环先
	赋予号以算术‘号’+1。
	如果‘号’大于3那么跳出。
	加载先如果调用‘exist’、‘配置文件’.‘号’那么‘配置文件’.‘号’否则init2.zs.‘号’了。
了。

