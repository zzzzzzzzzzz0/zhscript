赋予扩展目录【主】以‘配置目录’/ext。

赋予1以‘扩展目录’/test.zs。
如果调用‘exist’、‘1’否则先
	调用‘echo’、下原样
使主窗、提示为回车换行test回车换行。
使1s、等待。
赋予旧以使主窗、标签。
使主窗、标签、test。
使1s、等待。
使主窗、标签、‘旧’。
赋予旧以使主窗、标题。
使主窗、标题、test。
使1s、等待。
使主窗、标题、‘旧’。
上原样、‘1’。

	赋予1以‘扩展目录’/reboot.zs。
	如果调用‘exist’、‘1’否则
		调用‘echo’、下原样
销毁时保存。执行“sudo reboot”。
上原样、‘1’。

	赋予1以‘扩展目录’/poweroff.zs。
	如果调用‘exist’、‘1’否则
		调用‘echo’、下原样
销毁时保存。执行“sudo poweroff”。
上原样、‘1’。
了。

定义刷新扩展菜单【主】以下代码
	赋予列表以调用‘新建列表’。
	赋予搜以调用‘dir.begin’、‘扩展目录’、\.zs$、o0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		调用‘入列表’、‘列表’、2、先调用‘子串方法’、‘名’、0、-3了、‘名’。
	了。
	调用‘dir.end’、‘搜’。

	新建菜单--扩展。
	调用‘遍历列表’、‘列表’、下代码
		调用‘增至菜单’、‘扩展菜单’、代码为“加载“‘扩展目录’/‘参数2’””、为‘参数1’。
	上代码。

	赋予子菜单以调用‘增至菜单’、‘扩展菜单’、-、子菜单为编辑。
	调用‘遍历列表’、‘列表’、下代码
		调用‘增至菜单’、‘子菜单’、
		代码为“文字编辑器打开‘扩展目录’/‘参数2’”、图标为gtk-edit、为‘参数1’。
	上代码。

	调用‘增至菜单’、‘扩展菜单’、
	代码为‘简单代码二’、为下代码
		目录打开‘扩展目录’
	上代码、
	代码为“刷新扩展菜单”、图标为gtk-refresh、为刷新。

	调用‘释放列表’、‘列表’。
上代码。
刷新扩展菜单。
