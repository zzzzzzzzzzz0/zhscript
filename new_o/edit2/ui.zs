#!../srcvwsh --。
加载lib2/onlyonerun.zs、44441、下代码
	使主窗、激活。
	调用‘命令行解析’、‘参数栈’。
上代码。

加载set.zs。
加载def.zs。

加载lib/clpars4。
调用‘命令行加回调’、
	、文件……、1、下代码
		别名文件以参数1。
		如果调用‘头匹配方法’、‘文件’、/否则
			赋予文件以调用‘移除..’、‘当前目录’/‘文件’。
		赋予主窗#‘新开’文件【主】以‘文件’。
		赋予激活【主】以‘新开’。
		赋予新开【主】以算术‘新开’+1。
	上代码、
	-cd、下代码
		赋予“当前目录”【主】以‘参数1’。
	上代码、1、、
	-h|--help、、0、下代码
		显示调用‘命令行帮助’。
		结束1。
	上代码、
	-、、b、下代码
		显示‘参数1’？换行换行。
		调用‘命令行解析’、-h。
	上代码。
调用‘命令行暂停’、1、。
调用‘命令行解析’、‘参数栈’。

使主窗、侦听、
	创建为下代码
		加载lib/doscmd4。
		如果调用‘exist’、‘配置文件’那么加载‘配置文件’。
		调用‘命令行暂停’、1。
		调用‘命令行暂停’、0、。
		调用‘命令行解析’、‘参数栈【主】’。

		使主窗、不可关闭。
		使主窗、标签名、rem。
		使主窗、标签、参考。
		使主窗、大小、800、600。
		使主窗、居中。
		使主窗、最大化。
		使主窗、图标、‘图标’。
		使主窗、标题、‘大标题’。
		窗初始化主窗#rem。
		
		使主窗、图标夹、高为（74）50、无标题、加钮、大小为（6）3、缺省代码为下代码
			别名动作以参数2。
			使主窗、‘动作’。
			一般处理。
		上代码、
		提示为新开、gtk-add、
		提示为“打开文件”、代码为“按打开文件”、gtk-open、
		提示为刷新、代码为下代码
			一般处理rem窗、无标题。
			文件类型‘文件’。
			刷新文件‘文件’。
		上代码、gtk-refresh、
		提示为“保存文件”、代码为下代码
			一般处理rem窗。
			赋予文件以一般无标题得路径主窗。
			保存文件‘文件’。
		上代码、gtk-save、
		提示为另存文件、代码为下代码
			一般处理。
			赋予文件以选另存文件。如果不‘文件’那么退出。
			如果保存文件‘文件’并且不是rem窗那么
				设路径‘文件’、主窗。
		上代码、gtk-save-as、
		提示为“保存所有文件”、代码为“一般处理。保存所有文件”、gtk-save、
		提示为撤销、edit-undo、
		提示为重做、edit-redo、
		提示为剪切、edit-cut、
		提示为复制、edit-copy、
		提示为粘贴、edit-paste、
		提示为“在终端运行”、代码为“按在终端运行”、gtk-execute（gtk-media-play）、
		提示为“在终端运行所在项目”、代码为“按在终端运行项目”、gtk-execute、
		提示为“在终端运行调试”、代码为“按在终端运行调试”、gtk-execute、
		提示为打开所在目录、代码为下代码
			一般处理目录。
			执行“./fm.zs '‘目录’'&”。
		上代码、gtk-directory、
		提示为终端进入所在目录、代码为下代码
			一般处理目录。
			执行“./term.zs -d '‘目录’' -init '使主窗、大小、+-200、400' -t1 '‘目录’'&”。
		上代码、/usr/share/icons/gnome/24x24/apps/terminal.png、
		提示为关于…、代码为“一般处理。执行./about.zs&。”、gtk-about。

		使主窗、左图标夹、宽为300、名为保留字等。
		使主窗、左图标夹、加钮、缺省代码为下代码
			使主窗、插入、‘参数0’。
		上代码。
		赋予号以0。
		循环先
			赋予号以算术‘号’+1。
			如果‘号’大于‘保留字数目’那么跳出。
			使主窗、左图标夹、加钮、名为‘保留字‘号’’、。
		了。
		使主窗、左图标夹、加钮、缺省代码为下代码
			使主窗、插入、‘参数1’、头。
		上代码、
		附为“#!/usr/bin/zhscript --。”换行、名为#!zs头、、
		附为“#!/usr/lib/zhscript/webkitsh --。”换行、名为#!wk头、、
		附为“#!/usr/lib/zhscript/vtesh --。”换行、名为#!vte头、、
		附为“#!/usr/lib/zhscript/cairogsh --。”换行、名为#!cr头、、
		附为“#!/usr/lib/zhscript/srcvwsh --。”换行、名为#!src头、。
		使主窗、左图标夹、加钮、名为列可语法高亮、代码为下代码
			加载lib/gjks4。
			赋予表以调用‘新建列表’。
			使主窗、‘参数0’、下代码
				调用‘入列表’、‘表’、4、‘参数1’、‘参数2’、‘参数3’、‘参数4’。
			上代码。
			参考内容先调用‘整张列表’、‘表’、有、id、名称了。
			调用‘释放列表’、‘表’。
		上代码、。

		赋予文件图标以/usr/share/icons/gnome/16x16/mimetypes/gtk-file.png。
		赋予目录图标以/usr/share/icons/gnome/16x16/status/gtk-directory.png。
		赋予脚本图标以/usr/share/icons/gnome/16x16/mimetypes/gnome-mime-application-x-shellscript.png。
		赋予链接图标以/usr/share/icons/gnome/16x16/emblems/emblem-symbolic-link.png。
		使主窗、树、名为参考、列头为“双击将尝试执行选中项”、加钮、缺省代码为下代码
			别名名以参数0。
			别名目录以参数1。
			赋予文件以‘目录’/‘名’。
			文件类型‘文件’。
			如果‘是文本文件’那么
				打开文件‘文件’、主窗#rem。
			否则
				参考内容‘类型’。
		上代码、缺省双击代码为下代码
			在终端运行‘参数0’、‘参数1’。
		上代码。
		定义遍历以下代码
			别名目录以参数1。
			赋予搜以调用‘dir.begin’、‘目录’、、ad o0 f。
			循环先
				赋予名以调用‘dir.next’、‘搜’。
				如果‘名’等于那么跳出。
				赋予类型以调用‘dir.filetype’、‘搜’。
				赋予是子目录以如果‘类型’等于d或者等于dl那么1。
				如果‘是子目录’那么
					树加枝‘名’。
				否则
					使主窗、树、加钮、名为‘名’、附为‘目录’、双击附为‘目录’、先当‘类型’先
						等于-l那么‘链接图标’，跳出。
						调用‘尾匹配方法’、‘名’、.sh那么‘脚本图标’，跳出。
						‘文件图标’
					了了。
				如果‘是子目录’那么先
					遍历‘目录’/‘名’。
					树毕加枝。
				了。
			了。
			调用‘dir.end’、‘搜’。
		上代码。
		定义树加枝以下代码
			使主窗、树、加钮、名为‘参数1’、代码为-、双击代码为-、设置上为下代码
				赋予上【上】【上】以‘参数1’。
			上代码、‘目录图标’。
		上代码。
		定义树毕加枝以下代码
			使主窗、树、加钮、恢复上为下代码
				‘上’。
			上代码。
		上代码。
		
		遍历‘基目录’。
		
		树加枝zsp-go/test-cl。
		遍历/zzzzzzzzzzz/github/zsp-go/test-cl。
		树毕加枝。
	上代码、
	新开为下代码
		别名窗以参数‘参数数目’。
		窗初始化‘窗’。
		别名文件以‘窗’文件【主】。
		如果存在文件那么先
			文件类型‘文件’。
			打开文件‘文件’、‘窗’。
			删除‘窗’文件【主】。
		了。
	上代码、
	显现为下代码
		如果存在激活【主】那么先
			赋予号以2。
			循环先
				如果‘号’大于等于‘新开’那么跳出。
				使主窗、新开。
				赋予号以算术‘号’+1。
			了。
			使主窗#‘激活’、激活。
			使主窗#‘激活’、焦点。
			删除激活【主】。
		了。
	上代码、
	点击为下代码
		显示‘参数0’--‘参数’换行。
		别名钮以参数1。
		别名窗以参数2。
		如果‘钮’等于x那么
			关闭时保存‘窗’。
	上代码、
	销毁为下代码
		赋予内容以。
		赋予号以1。
		使主窗、遍历、下代码
			显示‘参数’换行。
			如果‘参数2’那么
				赋予眼前【上】以‘号’。
			别名名以参数1。
			如果‘名’不等于#rem那么先
				赋予窗以主窗‘名’。
				关闭时保存‘窗’、“再来”。
				显示‘文件’换行。
				赋予内容【上】以‘内容’
				“赋予“‘文件’位置”【主】以”先使‘窗’、光标位置了“。”换行
				“赋予主窗#‘号’文件【主】以“‘文件’”。”换行。
			了。
			赋予号【上】以算术‘号’+1。
		上代码。
		调用‘echo’、‘内容’
		“赋予新开【主】以‘号’。”换行
		“赋予激活【主】以‘眼前’。”、‘配置文件’。
	上代码。
使主窗、创建、标签页。

使代码为下代码
	显示‘参数0’--‘参数’换行。
上代码。