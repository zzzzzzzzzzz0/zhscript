#!bin/zhscript/vtesh --。
加载lib/defi。
加载lib/gjk4。
加载lib/menu4。
加载lib/file4。
加载lib/doscmd4。
加载lib/dlg4。
加载lib/stdc。
加载lib/regexpr4。
加载lib/clpars4。
加载lib/gjks4。
加载lib2/msgbox。

加载lib2/config2.zs。
赋予应用标题【主】以(懒人终端)。
赋予首目录【主】以‘家目录’。
赋予多页样式【主】以-t。
调用‘命令行加回调’、
	-dir、指定首目录，默认‘首目录’、1、下代码
		赋予首目录【主】以‘参数1’。
	上代码、
	-t | -nb、“多页样式。表格、顶标签页”、0、下代码
		赋予多页样式【主】以‘参数0’。
	上代码、
	-h | --help、、0、下代码
		赋予-h【主】以。
	上代码、
	、、1、下代码
		赋予-h【主】以‘参数1’。
	上代码。
调用‘命令行解析’、‘参数栈【主】’。
如果存在-h【主】那么先
	使主窗、侦听、
		创建为下代码
			使主窗、标题为‘应用标题’。
			使主窗、大小为400、400。
			使主窗、居中。
			使主窗、提示、先如果‘-h’那么“错误参数：‘-h’”回车换行回车换行了
				“有效参数如下：”回车换行先调用‘命令行帮助二’、、制表符、回车换行、0了。
		上代码。
	退出。
了。
显示首目录‘首目录’换行。

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
	如果调用‘尾匹配方法’、‘命令’、“ ”否则
		赋予命令以‘命令’换行。
	使主窗、输入、‘命令’。
上代码，

赋予命令菜单文件【主】以‘配置目录’/cmd-menu.zs。
如果调用‘exist’、‘命令菜单文件’否则
	调用‘echo’、先调用‘type’、‘应用目录’/cmd-menu.zs了、‘命令菜单文件’。
定义刷新命令菜单【主】以下代码
	赋予命令菜单【主】以调用‘新建菜单’。
	加载‘命令菜单文件’。
	调用‘增至菜单’、‘命令菜单’、-、
	代码为下代码
		执行“gnome-text-editor "‘命令菜单文件’" &”。
	上代码、图标为gtk-edit、为编辑、
	代码为下代码
		刷新命令菜单。
	上代码、图标为gtk-refresh、为刷新。
上代码。
刷新命令菜单。

赋予序列目录【主】以‘配置目录’/xulie。
赋予序列标识名【主】以.xulie.txt。
赋予test以‘序列目录’/test‘序列标识名’。
显示‘test’换行。
如果调用‘exist’、‘test’否则
	调用‘echo’、下原样
提示为回车换行“--- ‘序列名’ 开始 ”先调用‘串格时间方法’、%x%X了“ ---”回车换行。

提示为“输入yes：”回车换行。

输入、“echo ”。
^yes$
提示为回车换行“--- ‘序列名’ 完毕 ---”回车换行。
上原样、‘test’。

定义选择序列【主】以下代码
	别名名以参数1。
	如果存在序列号【主】那么先
		调用‘提示框’、0、“序列“‘序列名’”正在执行，”换行
			“可选菜单“中断”项中断后再开始“‘名’”序列”、‘应用标题’。
		退出。
	了。
	如果不存在序列【主】那么
		赋予序列【主】以调用‘新建列表’。
	调用‘清空列表’、‘序列’。
	赋予序列名【主】以‘名’。
	调用‘入列表由切割’、‘序列’、1、先调用‘type’、‘序列目录’/‘名’‘序列标识名’了、换行。
	显示序列长度先调用‘列表长度’、‘序列’、0了换行。
	调用‘遍历列表带序号’、‘序列’、下代码
		显示‘参数’换行。
	上代码。
	赋予序列号【主】以1。
	运行序列。
上代码。
定义是序列完【主】以下代码
	如果‘序列号’大于调用‘列表长度’、‘序列’、0那么先
		显示序列完换行。
		删除序列号【主】。
		1。
		退出。
	了。
上代码。
定义得序列行【主】以下代码
	调用‘得列表单元’、‘序列’、‘序列号’,1
上代码。
定义运行序列【主】以下代码
	如果不存在序列号【主】那么退出。

	如果是序列完那么退出。
	赋予行以得序列行。
	赋予出以使主窗、输出。
	显示序列‘序列号’制表符‘行’换行出{‘出’}换行。
	如果‘行’那么先
		赋予果以调用‘正则配’、‘出’、‘行’、l。
		显示果‘果’换行。
		如果不‘果’那么退出。
		了。
	了。

	赋予序列号【主】以算术‘序列号’+1。
	如果是序列完那么退出。
	赋予行以得序列行。
	显示序列‘序列号’制表符‘行’换行。
	序列运行‘行’。
	赋予序列号【主】以算术‘序列号’+1。
上代码。
定义序列运行【主】以下代码
	解释“基于“使主窗、‘参数栈’”先”‘参数1’“了”
上代码。

定义刷新序列菜单【主】以下代码
	赋予序列菜单【主】以调用‘新建菜单’。
	赋予搜以调用‘dir.begin’、‘序列目录’、\‘序列标识名’$、o0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		调用‘增至菜单’、‘序列菜单’、
		代码为下代码
			选择序列‘参数0’。
		上代码、
		为先调用‘子串方法’、‘名’、0、-先调用‘串长函数’、‘序列标识名’了了。
	了。
	调用‘dir.end’、‘搜’。
	调用‘增至菜单’、‘序列菜单’、
	-、
	代码为下代码
		如果不存在序列号【主】那么先
			调用‘提示框’、0、“不存在正在执行的序列”、‘应用标题’。
			退出。
		了。
		如果调用‘提示框’、0、“‘参数0’序列“‘序列名’”的执行？”、‘应用标题’、‘询问’、‘是否按钮’等于‘是’那么先
			调用‘清空列表’、‘序列’。
			使主窗、输入、Ctrl+C。
		了。
	上代码、为中断、
	代码为‘输入代码二’、
	为下代码
		cd ‘序列目录’/
	上代码、
	代码为“刷新序列菜单”、图标为gtk-refresh、为刷新。
上代码。
刷新序列菜单。

定义设置颜色【主】以下代码
	当‘参数1’先
		等于白底黑字那么先
			使主窗、背景色、1、1、1、1。
			使主窗、前景色、0、0、0、1。
			跳出。
		了。
		等于黑底白字那么先
			使主窗、前景色、1、1、1、1。
			使主窗、背景色、0、0、0、1。
			跳出。
		了。
		等于最佳一那么先
			使主窗、前景色、算术131/255、算术148/255、算术150/255、1。
			使主窗、背景色、0、算术43/255、算术53/255、1。
			跳出。
		了。
	了。
上代码。

赋予更多菜单【主】以调用‘新建菜单’、
缺省代码为下代码
	设置颜色‘参数0’。
上代码、
单选、
为白底黑字、
为黑底白字、
为最佳一、
-、
普通、
缺省代码为‘简单代码’、
为reset、
代码为‘输入代码二’、
为下代码
	ls proc目录
上代码、
为z。

赋予菜单代码【主】以下代码
	调用‘弹出菜单’、‘‘参数0’’。
上代码。

定义proc目录【主】【无参】以下代码
	/proc/先使主窗、pid了
上代码。

定义Ctrl+【主】以下代码
	解释字符先调用‘整数方法’、‘参数1’、-1、.ABCDEFGHIJKLMNOPQRSTUVWXYZ了。
上代码。

定义进行选择【主】以下代码
	赋予选以调用‘文件选择框’、0、‘参数1’、‘参数0【上】’、预选为先调用‘最终文件名’、proc目录/cwd了/。
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

使主窗、侦听、
	创建为下代码
		使主窗、图标为/usr/share/icons/gnome/48x48/apps/terminal.png。
		使主窗、标题为‘应用标题’。
		使主窗、大小为800、500。
		使主窗、加钮、大小为5、
			缺省代码为‘简单代码’、
			名为复制到剪贴板、gtk-copy、
			名为从剪贴板粘贴、gtk-paste、
			缺省代码为‘输入代码’、
			-、
			名为“Ctrl + C”、gtk-stop、
			-、
			名为“Ctrl + U！Ctrl + K（清除）”、gtk-clear、
			名为“Ctrl + P（上一条命令）”、gtk-go-up、
			名为“Ctrl + N（下一条命令）”、gtk-go-down、
			名为“换行”、gtk-execute、
			名为“Ctrl + A（移到命令行首）”、gtk-goto-first、
			名为“Ctrl + E（移到命令行尾）”、gtk-goto-last、
			-、
			代码为下代码
				运行命令cd。
			上代码、名为家目录、gtk-home、
			代码为下代码
				运行命令“cd ..”。
			上代码、名为上一级目录、gtk-go-up、
			代码为下代码
				进行选择文件夹、“cd ”。
			上代码、名为进入目录…、gtk-directory、
			-、
			缺省代码为‘菜单代码’、
			名为命令菜单、gtk-justify-fill、
			代码为下代码
				进行选择打开、、“ ”。
			上代码、名为选择文件…、gtk-file、
			代码为下代码
				进行选择文件夹、、“ ”。
			上代码、名为选择目录…、gtk-directory、
			名为序列菜单、gtk-justify-fill、
			名为更多菜单、gtk-justify-fill、
			-、
			代码为下代码
				使主窗、新开。
			上代码、名为新建一页、gtk-add。
		使主窗、不可关闭。
		解释‘置【主】’、主窗。
	上代码、
	新开为下代码
		解释‘置【主】’、‘参数‘参数数目’’。
		设置颜色白底黑字。
	上代码、
	内容改变为下代码
		运行序列。
	上代码、
	图标标题改变为下代码
		使主窗、标题、先使主窗、图标标题了“ ‘应用标题’”。
	上代码、
	显现为下代码
		显示xid先使主窗、xid了换行。
		显示地址先使主窗、地址了换行。
		
		设置颜色白底黑字。
	上代码。
当‘多页样式’先
	等于-t那么先
		使主窗、创建、表格、行为4、列为1。
		跳出。
	了。
	等于-nb那么先
		使主窗、创建、顶标签页。
		跳出。
	了。
了。

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
	使‘窗’、命令、/bin/bash、‘环境变量’、‘首目录’。
	使‘窗’、字体、“Monospace 10”。
	使‘窗’、行数为-1。
	使‘窗’、焦点。
	使‘窗’、标签、“  ”。
上代码。

使代码为下代码
	显示‘参数0’--‘参数’换行。
上代码。
