加载init-1.zs。

加载lib/dlg4。
加载lib/regexpr4。

赋予配置文件2【主】以‘配置文件’.2。
如果调用‘exist’、‘配置文件2’那么
	别名配置文件2i【主】以配置文件2。
否则
	赋予配置文件2i【主】以‘所在目录’init2.zs.2。

定义import【主】以下代码
	别名活以参数1。
	赋予文件以调用‘文件选择框’、0、打开、“打开文件”、预选为先如果‘活’等于公
		那么/usr/share/applications
		否则‘~’/.local/share/applications了/、
		类型为启动器文件为*.desktop。
	如果不‘文件’那么退出。

	赋予内容以调用‘type’、‘文件’。
	显示‘内容’换行。
	赋予命令行以读取设置Exec。
	赋予标题以读取设置Name。
	赋予图标以读取图标。

	赋予位置以调用‘串位置方法’、‘命令行’、“ %”。
	如果‘位置’大于0那么
		赋予命令行以调用‘子串方法’、‘命令行’、0、‘位置’。

	“下原样‘命令行’上原样、下原样‘标题’上原样、“‘图标’”、下代码后退为1。脚本为0。上代码、”。
	赋予命令行【上】以‘命令行’。
	赋予标题【上】以‘标题’。
	赋予图标【上】以‘图标’。
上代码。

定义读取键【主】以下代码
	调用‘正则格’、‘内容’、换行‘参数1’=([^换行]+)、%1。
上代码。

定义读取设置【主】以下代码
	赋予1以读取键‘参数1’\[zh_CN\]。
	如果不‘1’那么赋予1以读取键‘参数1’。
	‘1’
上代码。

定义读取图标【主】以下代码
	赋予1以读取设置Icon。
	范围先
		迭代解释下代码
			别名2以参数1。
			如果调用‘exist’、‘2’那么先
				赋予1【上】以‘2’。
				遁出。
			了。
		上代码、
		‘1’、
		/usr/share/icons/hicolor/48x48/apps/‘1’.png、
		/usr/share/icons/hicolor/48x48/mimetypes/‘1’.png。
	了。
	‘1’
上代码。
