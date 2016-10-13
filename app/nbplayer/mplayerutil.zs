如果存在mplayer【主】那么退出。
赋予mplayer【主】以mplayer。

定义安装mplayer【主】以下代码
	（加载lib/redireconsoi4。
	赋予果以调用‘重定向输出’、“which mplayer”。）
	加载lib/doscmd4。
	赋予果以调用‘exist’、/usr/bin/mplayer。
	如果不‘果’那么先
		赋予错以执行“apturl-gtk apt:mplayer”。
		如果‘错’那么先
			退出。
		了。
	了。
	1。
上代码。

定义用mplayer取信息【主】以下代码
	别名视频以参数1。
	如果存在‘视频’长度【主】那么退出。

	赋予命令以“mplayer -identify "‘视频’" -nosound -vc dummy -vo null”。
	（加载lib/redireconsoi4。
	赋予‘视频’信息【主】以调用‘重定向输出’、‘命令’。）
	加载lib/doscmd4。
	赋予tmp以/tmp/mplayer-identify.txt。
	赋予以执行“‘命令’ > ‘tmp’”。
	赋予‘视频’信息【主】以调用‘type’、‘tmp’。
	赋予以执行“rm ‘tmp’”。

	加载lib/regexpr4。
	赋予‘视频’长度【主】以调用‘正则格’、‘‘视频’信息’、ID_LENGTH=([0-9.]+)。
	赋予‘视频’宽度【主】以调用‘正则格’、‘‘视频’信息’、ID_VIDEO_WIDTH=([0-9]+)。
	赋予‘视频’高度【主】以调用‘正则格’、‘‘视频’信息’、ID_VIDEO_HEIGHT=([0-9]+)。
上代码。

定义用mplayer截图【主】以下代码
	别名视频以参数1。
	用mplayer取信息‘视频’。
	别名长度以‘视频’长度。
	如果‘长度’那么先
		加载lib/gjk4。
		赋予位置以调用‘随机数方法’、算术‘长度’*100、0。
		赋予位置以算术‘位置’/100、2。
	了否则
		赋予位置以1。

	别名图以参数2。
	别名tmp以参数3。
	如果执行显示“
	mkdir -p "‘tmp’" && cd "‘tmp’" && 
	mplayer -ss ‘位置’ -noframedrop -nosound -vo png -frames 1 "‘视频’"”换行等于0那么先
		赋予搜以调用‘dir.begin’、‘tmp’。
		循环先
			赋予名以调用‘dir.next’、‘搜’。
			如果不‘名’那么跳出。
			赋予以执行“mv "‘tmp’/‘名’" "‘图’"”。
		了。
		调用‘dir.end’、‘搜’。
		?‘位置’。
	了。
	赋予以执行“rmdir "‘tmp’"”。
上代码。
