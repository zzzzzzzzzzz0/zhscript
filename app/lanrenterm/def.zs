加载lib/gjk4。
加载lib/menu4。
加载lib/file4。
加载lib/doscmd4。
加载lib/dlg4。
加载lib/stdc。
加载lib/regexpr4。
加载lib/gjks4。
加载lib2/msgbox。
加载lib/gnomeu4。
加载lib/timeout4。

赋予简单代码【主】以下代码
	使主窗、‘参数0’。
上代码。
赋予输入代码【主】以下代码
	使主窗、输入、解释‘参数0’。
上代码。
赋予输入代码二【主】以下代码
	使主窗、输入、先解释先调用‘串替换方法’、‘参数0’、“ ”、““ ””了了。
上代码。

定义运行命令【主】以下代码
	别名命令以参数1。
	如果调用‘头匹配方法’、‘命令’、“ ”否则
		赋予命令以先Ctrl+U了先Ctrl+K了‘命令’。
	如果调用‘尾匹配方法’、‘命令’、“ ”否则
		赋予命令以‘命令’换行。
	使主窗、输入、‘命令’。
上代码。
赋予运行代码【主】以下代码
	运行命令‘参数0’。
上代码。

定义刷新命令菜单【主】以下代码
	赋予命令菜单【主】以调用‘新建菜单’。
	加载‘命令菜单文件’。
	调用‘增至菜单’、‘命令菜单’、
	-、
	代码为“执行“gnome-text-editor "‘命令菜单文件’" &””、图标为gtk-edit、为编辑、
	代码为“刷新命令菜单”、图标为gtk-refresh、为刷新。
上代码。

赋予菜单代码【主】以下代码
	调用‘弹出菜单’、‘‘参数0’’。
上代码。

定义proc目录【主】【无参】以“/proc/先使主窗、pid了”。
定义眼前页眼前目录【主】【无参】以“先调用‘最终文件名’、proc目录/cwd了/”。

定义Ctrl+【主】以下代码
	解释字符先调用‘整数方法’、‘参数1’、-1、.ABCDEFGHIJKLMNOPQRSTUVWXYZ了。
上代码。

定义进行选择【主】以下代码
	赋予选以调用‘文件选择框’、0、‘参数1’、‘参数0【上】’、预选为眼前页眼前目录。
	如果‘选’那么先
		如果存在参数2那么
			别名前以参数2。
		否则
			赋予前以。
		如果存在参数3那么
			别名后以参数3。
		否则
			赋予后以。
		运行命令‘前’"‘选’"‘后’。
	了。
上代码。

定义销毁时保存【主】以下代码
	这保存上一次文件。
	这保存位置文件。
上代码。

赋予置【主】以下代码
	别名窗以参数1。
	赋予环境变量以。
	赋予z/s以/zzzzzzzzzzz/sh。
	如果调用‘existdir’、‘z/s’那么先
		赋予PATH以调用‘得环境变量方法’、PATH。
		如果调用‘串位置方法’、‘PATH’、‘z/s’小于0那么
			赋予环境变量以PATH=‘PATH’:‘z/s’。
	了。
	显示环境变量‘环境变量’换行。
	加载‘颜色文件’。
	范围先
		如果‘窗’不等于主窗那么先
			这上一次文件。
			如果存在新页目录【主】那么先
				赋予目录以‘新页目录’。
				删除新页目录【主】。
				遁出。
			了。
		了。
		赋予目录以‘首目录’。
	了。
	使‘窗’、命令、/bin/bash、‘环境变量’、‘目录’。
	（Ubuntu Mono）（文泉驿等宽微米黑）
	（AR PL UMing CN）（宋体）
	（Monospace）
	使‘窗’、字体、“宋体 10”。
	使‘窗’、行数为-1。
	使‘窗’、焦点。
	使‘窗’、标签、“      ”。
上代码。