加载lib/defi。
加载lib/gjk4。
如果不存在【主】~那么
	赋予【主】~以调用‘得环境变量方法’、HOME。
赋予应用名【主】以startbox。
赋予【主】配置目录以‘~’/.config/‘应用名’_zs。
赋予【主】配置文件以‘配置目录’/init2.zs。
加载lib/file4。
赋予【主】所在目录以调用‘得目录名’、先调用‘最终文件名’、‘【上】参数0’了。
赋予项目名【主】以启动盒。
赋予主窗标题【主】以“‘项目名’ (‘~’)”。

定义隧道【主】以下代码
	显示‘参数0’--‘参数’换行。
	赋予号以1。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数数目’那么跳出。
		赋予名以‘参数1’先如果‘号’大于2那么算术‘号’-1了【主】。
		显示‘名’换行。
		赋予‘名’以‘参数‘号’’。
	了。
上代码。

加载lib/doscmd4。
定义读所有配置文件【主】以下代码
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于3那么跳出。
		加载先如果调用‘exist’、‘配置文件’.‘号’那么‘配置文件’.‘号’否则init2.zs.‘号’了。
	了。
上代码。

赋予无图标【主】以‘所在目录’no.png。
赋予缺省图标【主】以‘所在目录’que.png。
赋予抽屉图标【主】以‘所在目录’dir.png。
定义置预图标【主】以下代码
	别名路径以参数1。
	别名加以参数2。
	当‘路径’先
		等于缺省那么先
			如果存在加并且‘加’那么‘抽屉图标’否则‘缺省图标’。
			跳出。
		了。
		等于抽屉那么先
			‘‘路径’图标’。
			跳出。
		了。
		‘路径’。
	了。
上代码。
定义【主】确定图标以下代码
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数数目’那么跳出。
		如果调用‘exist’、‘参数‘号’’那么‘参数‘号’’，退出。
	了。
	‘缺省图标’。
上代码。

加载lib/gjke4。
加载lib/regexpr4。
