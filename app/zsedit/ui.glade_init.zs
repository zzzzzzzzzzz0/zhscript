隧道窗口最大化。
加载lib/defi。
加载lib/stdc。
加载lib2/msgbox。
加载lib/file4。
加载lib/gjk4。
加载lib/gjke4。
加载lib/doscmd4。
加载lib/regexpr4。
赋予【主】【锁】基目录以调用‘最终文件名’、先调用‘得目录名’、‘保留字’了。
赋予【主】【锁】配置目录以先调用‘得环境变量方法’、HOME了/.config/zsedit_zs。
执行“mkdir -p '‘配置目录’'”。
赋予【主】【锁】配置文件以‘配置目录’/setting.zs。
赋予【主】【锁】自定按钮文件以‘配置目录’/button.zs。

赋予号以0。
循环先
	赋予号以算术‘号’+1。
	如果隧道有、title‘号’否则跳出。
	隧道源码框、text‘号’、page‘号’。
	隧道源码框、已修改、text‘号’、侦听、下代码
		调用‘正则攫’、‘动作’、([0-9]+)。
		别名号以之1。
		赋予标题以隧道内容、title‘号’。
		如果调用‘正则配’、‘标题’、^\*、nl否则
			隧道内容、title‘号’、*‘标题’。
	上代码。
了。

定义【主】【锁】复位已修改以下代码
	别名号以参数1。
	隧道源码框、已修改、text‘号’、0。
	赋予标题以隧道内容、title‘号’。
	如果调用‘正则攫’、‘标题’、\*+(.+)大于0那么
		隧道内容、title‘号’、‘之1’。
上代码。

定义【主】【锁】打开文件以下代码
	别名文件以参数1。
	别名号以参数2。
	如果调用‘exist’、‘文件’否则先
		隧道提示文字、title‘号’、。
		隧道内容、title‘号’、。
		退出。
	了。
	赋予内容以调用‘type’、‘文件’。
	隧道源码框、撤销不记始、text‘号’。
	隧道源码框、内容、text‘号’、‘内容’。
	隧道源码框、撤销不记终、text‘号’。
	别名标题以参数3。
	如果存在标题那么先
		隧道提示文字、title‘号’、‘文件’。
		如果存在参数4那么先
		了否则
			赋予标题以调用‘子串方法’、‘标题’、0、6。
		隧道内容、title‘号’、‘标题’。
	了。
	复位已修改‘号’。
上代码。

如果调用‘exist’、‘配置文件’那么加载‘配置文件’否则加载setting.zs。
加载button.zs。
如果调用‘exist’、‘自定按钮文件’那么加载‘自定按钮文件’。

定义【主】【锁】【无参】⌘以“隧道内容、notebook1。”。

赋予文件图标以/usr/share/icons/gnome/16x16/mimetypes/gtk-file.png。
赋予目录图标以/usr/share/icons/gnome/16x16/status/gtk-directory.png。
赋予脚本图标以/usr/share/icons/gnome/16x16/mimetypes/gnome-mime-application-x-shellscript.png。
赋予树以隧道树、tree、代码为下代码
	解释【代码】“基于“赋予【主】‘参数1’以‘参数2’”先”‘参数2’“了”。
	当‘类’先
		等于条那么先
			如果是否需要保存文件⌘等于x那么退出。
			打开文件‘文件’、⌘、‘参数1’。
			隧道内容、rem⌘、‘注’。
			隧道内容、cmd⌘、。
			跳出。
		了。
	了。
上代码、图片缓存为隧道图片缓存。
赋予遍历以下代码
	别名目录名以参数1。
	赋予目录以‘基目录’/‘目录名’。
	如果存在参数2那么
		别名分支以参数2。
	否则
		赋予分支以隧道树、增加、‘目录名’、“类为目。”、‘目录图标’、‘树’。
	赋予类以如果调用‘正则配’、‘目录名’、^lib、nl那么库否则条。
	赋予搜以调用‘dir.begin’、‘目录’、、ad。
	调用‘dir.sort’、‘搜’、0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		如果‘名’等于ui或者等于gtkmmsh-plugin/那么再来。
		如果调用‘尾匹配方法’、‘名’、/那么先
			赋予名以调用‘子串方法’、‘名’、0、-1。
			赋予子分支以隧道树、增加、‘名’、“类为目。”、‘目录图标’、‘分支’、‘树’。
			解释‘遍历’、‘目录名’/‘名’、‘子分支’。
			再来。
		了。
		赋予副名以调用‘得扩展名’、‘名’。
		如果‘副名’等于.so那么再来。
		范围先
			如果‘副名’等于.sh那么别名图标以脚本图标，遁出。
			别名图标以文件图标。
		了。
		赋予注以。
		当‘类’先
			等于库那么先
				如果‘副名’等于.glade或者等于.sh
				或者调用‘尾匹配方法’、‘名’、.glade_init.zs
				那么跳出。
				赋予注以“加载‘目录名’/‘名’。”。
				跳出。
			了。
		了。
		赋予值以“文件为“‘目录’/‘名’”。类为条。注为“‘注’”。”。
		隧道树、增加、‘名’、‘值’、‘图标’、‘分支’、‘树’。
	了。
	调用‘dir.end’、‘搜’。
上代码。
（迭代解释‘遍历’、lib、lib2、demo、demo2。）
赋予搜以调用‘dir.begin’、‘基目录’、^(lib|demo)、af ad d。
调用‘dir.sort’、‘搜’、0。
循环先
	赋予名以调用‘dir.next’、‘搜’。
	如果不‘名’那么跳出。
	解释‘遍历’、‘名’。
了。
调用‘dir.end’、‘搜’。

赋予【主】【锁】图标夹以隧道图标夹、icon、代码为下代码
	隧道源码框、焦点、text⌘。
	（显示‘参数’↙。）
	隧道源码框、插入、text⌘、解释‘参数1’。
上代码。

定义【主】【锁】应用自定按钮以下代码
	隧道图标夹、清空、‘图标夹’。
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘保留字数目’那么跳出。
		赋予名以‘保留字‘号’’。
		赋予值以如果‘名’等于“下原样”或者等于“上原样”那么““‘名’””否则“下原样‘名’上原样”。
		隧道图标夹、增加、‘值’、‘名’、、、‘图标夹’。
	了。
	赋予【主】号以0。
	解释下代码
		迭代解释下代码
			赋予【主】号以算术‘【主】号’+1。
			（显示‘【主】号’)‘参数’↙。）
			如果算术‘【主】号’%2等于1那么赋予【上】名以‘参数1’，再来。
			隧道图标夹、增加、‘参数1’、‘名’、、、‘图标夹’。
		上代码、
	上代码先隧道内容、defbtn了。
上代码。
应用自定按钮。
隧道侦听、点击、applydefbtn、下代码
	赋予标记以“（以上不能修改）”。
	赋予长以调用‘串长函数’、‘标记’。
	赋予内容以隧道内容、defbtn。
	赋予位置以调用‘串位置方法’、‘内容’、‘标记’。
	如果‘位置’小于0那么先
		隧道提示、“请添加“‘标记’”标记”、隧道标题、‘停止’。
		退出。
	了。
	应用自定按钮。
	赋予内容以调用‘子串方法’、‘内容’、算术‘位置’+‘长’。
	赋予内容以“隧道插入、defbtn、下原样‘内容’上原样。”。
	调用‘echo’、‘内容’、‘自定按钮文件’。
上代码。

定义【主】【锁】保存文件以下代码
	别名号以参数1。
	别名返回值以参数2。
	赋予错以调用‘echo’、先隧道源码框、内容、text‘号’了、‘文件’。
	如果‘错’那么先
		如果存在返回值那么0，退出。
		赋予蔽以隧道提示、“文件 ‘文件’ 保存失败（‘错’）”、隧道标题、‘停止’。
		退出。
	了。
	复位已修改‘号’。
	1。
上代码。

定义【主】【锁】是否需要“保存文件”以下代码
	别名号以参数1。
	赋予文件以隧道提示文字、title‘号’。
	如果不‘文件’那么退出。
	如果隧道源码框、已修改、text‘号’那么先
		赋予果以隧道提示、“文件 ‘文件’ 已修改，是否保存”、隧道标题、‘询问’、‘是否按钮’。
		当‘果’先
			等于‘【msgbox】是’那么先
				如果不保存文件‘号’那么x。
				跳出。
			了。
			等于‘【msgbox】X’那么x。
		了。
	了。
上代码。

隧道代码、下代码
	（显示‘肇事者’‘动作’‘参数’↙。）
	如果‘肇事者’等于窗口并且‘动作’等于销毁那么先
		赋予内容以。
		赋予号以0。
		循环先
			赋予号以算术‘号’+1。
			如果隧道有、title‘号’否则跳出。
			赋予文件以隧道提示文字、title‘号’。
			如果‘文件’否则再来。

			赋予内容以‘内容’↙“打开文件“‘文件’”、‘号’、下原样”先隧道内容、title‘号’了“上原样、。”。

			赋予rem以隧道内容、rem‘号’。
			如果‘rem’不等于“”那么
				赋予内容以‘内容’↙“隧道内容、rem‘号’、下原样”‘rem’“上原样。”。

			赋予cmd以隧道内容、cmd‘号’。
			如果‘cmd’不等于“”那么
				赋予内容以‘内容’↙“隧道内容、cmd‘号’、下原样”‘cmd’“上原样。”。

			赋予内容以‘内容’↙“隧道源码框、光标位置、text‘号’、”先隧道源码框、光标位置、text‘号’了“。”。

			是否需要保存文件‘号’。
		了。
		赋予内容以‘内容’
			↙“隧道内容、notebook1、”先隧道内容、notebook1了“。”
			↙“隧道位置、hpaned1、”先隧道位置、hpaned1了“。”
			。
		调用‘echo’、‘内容’、‘配置文件’。
	了。
上代码。

定义【主】【锁】状态栏提示以下代码
	隧道内容、statusbar1、‘参数1’如果存在参数2那么“ - ‘参数2’”。
上代码。

隧道侦听、点击、cut、copy、paste、undo、redo、下代码
	别名操作以参数1。
	隧道源码框、‘操作’、text⌘。
上代码。

定义【主】【锁】新建文件以下代码
	别名号以参数1。
	如果是否需要保存文件‘号’等于x那么退出。
	隧道源码框、撤销不记始、text‘号’。
	隧道源码框、内容、text‘号’、。
	隧道源码框、撤销不记终、text‘号’。
	隧道源码框、已修改、text‘号’、0。
	隧道提示文字、title‘号’、。
	隧道内容、title‘号’、。
	隧道内容、rem‘号’、。
	隧道内容、cmd‘号’、。
上代码。

隧道侦听、点击、new、下代码
	新建文件⌘。
上代码。

隧道菜单、new_menu、toolbar1。

隧道侦听、点击、newall、下代码
	隧道遍历、notebook1、下代码
		新建文件‘参数1’。
	上代码。
上代码。

隧道侦听、点击、reload、下代码
	赋予文件以隧道提示文字、title⌘。
	别名辅以参数1。
	如果不‘文件’那么状态栏提示没有文件、‘辅’，退出。
	是否需要保存文件⌘。
	打开文件‘文件’、⌘。
上代码。

隧道侦听、点击、open、下代码
	赋予预选以隧道提示文字、title⌘。
	如果不‘预选’并且存在上一次文件【主】那么赋予预选以‘上一次文件’。
	赋予文件以隧道文件选择、‘参数1’、‘参数1’、预选为‘预选’。
	如果‘文件’那么先
		如果是否需要保存文件⌘等于x那么退出。
		赋予【主】上一次文件以‘文件’。
		打开文件‘文件’、⌘、先调用‘得文件主名’、‘文件’了先调用‘得扩展名’、‘文件’了。
		隧道内容、rem⌘、。
	了。
上代码。

隧道侦听、点击、save、下代码
	赋予文件以隧道提示文字、title⌘。
	如果不‘文件’那么先
		赋予文件以隧道文件选择、‘参数1’、‘参数1’。
		如果不‘文件’那么退出。
		隧道提示文字、title⌘、‘文件’。
		隧道内容、title⌘、先调用‘子串方法’、先调用‘得文件主名’、‘文件’了先调用‘得扩展名’、‘文件’了、0、6了。
	了。
	保存文件⌘。
上代码。

隧道侦听、点击、saveall、下代码
	赋予信以。
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果隧道有、title‘号’否则跳出。
		如果隧道源码框、已修改、text‘号’否则再来。
		赋予文件以隧道提示文字、title‘号’。
		如果不‘文件’那么赋予信以‘信’‘号’*,，再来。
		赋予信以‘信’‘号’先如果保存文件‘号’、成否则!了,。
	了。
	状态栏提示‘信’、‘参数1’。
上代码。

定义【主】【锁】“终端执行”以下代码
	赋予命令以调用‘加反斜杠’、‘参数1’、C。
	赋予停留以如果存在参数2那么‘参数2’否则2m。
	赋予参以如果存在参数3那么‘参数3’否则“--maximize --hide-menubar”。
	执行显示“gnome-terminal ‘参’ -t "‘命令’" -e 'sh -c "‘命令’;echo ———$?———停留‘停留’;sleep ‘停留’”"'&↙。
上代码。

定义【主】【锁】运行以下代码
	别名辅以参数1。
	赋予文件以隧道提示文字、title⌘。
	如果不‘文件’那么状态栏提示没有文件、‘辅’，退出。
	（如果隧道源码框、已修改、text⌘那么保存文件⌘。）
	隧道点击、saveall。
	赋予目录以调用‘得目录名’、‘文件’。
	赋予主名以调用‘得文件主名’、‘文件’。
	赋予名以‘主名’先调用‘得扩展名’、‘文件’了。
	如果调用‘尾匹配方法’、‘主名’、.glade_init那么
		赋予主名以调用‘子串方法’、‘主名’、0、-11。
	当‘辅’先
		等于“终端运行”那么先
			终端执行“cd ‘目录’;./‘名’”。
			退出。
		了。
		调用‘尾匹配方法’、‘辅’、“运行所在项目”那么先
			赋予自以隧道内容、cmd⌘。
			如果‘自’那么
				解释‘自’。
			否则先
				调用‘正则攫’、‘目录’、([^/]+)/$、名、el。
				赋予果以迭代解释下代码
					别名名以参数1。
					如果调用‘exist’、‘目录’‘名’否则再来。
					如果调用‘头匹配方法’、‘辅’、终端那么先
						终端执行“cd ‘目录’;./‘名’”、0。
					了否则
						执行“cd '‘目录’';./'‘名’'&”。
					1。跳出。（退出。）
				上代码、‘名之1’、_z.sh、z.sh、start.sh、start、‘主名’.sh、‘主名’、ui、ui.zs。
				如果不‘果’那么
					状态栏提示无项目启动文件、‘辅’。
			了。
			退出。
		了。
		那么
			执行“cd '‘目录’';./'‘名’'&”。
	了。
上代码。

隧道侦听、点击、run、termrun、runprj、termrunprj、下代码
	运行‘参数1’。
上代码。

隧道侦听、点击、memrun、下代码
	解释先隧道源码框、内容为text⌘了。
上代码。

隧道侦听、点击、opendir、gedit、find、term、glade、chmodx、下代码
	赋予文件以隧道提示文字、title⌘。
	别名动作以参数0。
	别名辅以参数1。
	别名键以参数2。
	如果不‘文件’那么状态栏提示没有文件、‘辅’，退出。
	（如果隧道源码框、已修改、text⌘那么保存文件⌘。）
	隧道点击、saveall。
	当先
		调用‘尾匹配方法’、‘辅’、所在文件夹那么
			赋予文件以调用‘得目录名’、‘文件’，跳出。
		调用‘尾匹配方法’、‘辅’、界面文件那么先
			如果调用‘正则攫’、‘文件’、(.+)_init\.zs$、名、el那么先
				赋予文件以‘名之1’。
				如果调用‘exist’、‘文件’那么跳出。
			了。
			
			赋予目录以调用‘得目录名’、‘文件’。
			赋予文件以‘目录’ui.glade。
			如果调用‘exist’、‘文件’那么跳出。
			
			如果调用‘正则攫’、‘目录’、([^/]+)/$、名、el那么先
				赋予文件以‘目录’‘名之1’.glade。
				如果调用‘exist’、‘文件’那么跳出。
				赋予文件以‘目录’‘名之1’.ui。
				如果调用‘exist’、‘文件’那么跳出。
			了。
			
			状态栏提示无界面文件、‘辅’。
			退出。
		了。
	了。
	当‘键’先
		等于chmodx那么
			终端执行‘动作’"‘文件’"、5s，跳出。
		那么执行显示‘动作’'‘文件’'&↙。
	了。
上代码。

隧道侦听、点击、title_get、下代码
	隧道内容、title_text、先隧道内容、title⌘了。
	隧道内容、title_tip、先隧道提示文字、title⌘了。
上代码。

隧道侦听、点击、title_set、下代码
	隧道内容、title⌘、先隧道内容、title_text了。
上代码。
