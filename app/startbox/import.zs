加载lib/regexpr4。
加载lib/file4。

赋予内容以调用‘type’、‘参数1’。

定义读取键以“调用‘regexpr’、‘内容’、字符10‘参数1’=([^字符10]+)、%1”。

定义读取设置以“赋予1以读取键‘参数1’\[zh_CN\]。如果不‘1’那么赋予1以读取键‘参数1’。‘1’”。

定义搜图标以“
如果存在“隧道【主】”那么隧道不堵塞。
如果调用‘existdir’、‘参数1’等于0那么退出。
赋予目录以先调用‘dir.begin’、‘参数1’、^‘参数2’先如果存在参数3那么‘参数3’了$、s了。
赋予1以调用‘dir.next’、‘目录’。
调用‘dir.end’、‘目录’。
如果‘1’那么赋予1以‘参数1’/‘1’。
‘1’”。

定义读取图标以“
赋予1以读取设置‘参数1’。
如果调用‘exist’、‘1’等于0并且调用‘串位置方法’、‘1’、/小于0那么先
	赋予40以/usr/share/icons。
	赋予41以/usr/share/pixmaps。
	赋予42以/usr/local/share/icons。
	赋予43以/usr/local/share/pixmaps。
	赋予44以/usr/share/app-install/icons。
	赋予45以解释‘目录名’、‘参数2’。
	赋予3以0。
	循环先
		如果不存在4‘3’那么跳出。
		赋予2以搜图标‘4‘3’’、‘1’。
		如果调用‘exist’、‘2’那么‘2’，退出。
		赋予2以搜图标‘4‘3’’、‘1’、\.(png|xpm|svg)。
		如果调用‘exist’、‘2’那么‘2’，退出。
		赋予3以算术‘3’+1。
	了。
了。
‘1’”。

赋予【上】命令行以读取设置Exec。
赋予【上】标题以读取设置Name。
赋予【上】图标以读取图标Icon、‘【上】命令行’。

