加载lib/gjk4。
赋予~以调用‘得环境变量方法’、HOME。
赋予g-s-e以‘~’/.local/share/gnome-shell/extensions。
加载lib/defi。
显示‘g-s-e’换行。
加载lib/doscmd4。
如果调用‘existdir’、‘g-s-e’那么先
	赋予~/i@zs以‘g-s-e’/icons@zhscript。
	显示‘~/i@zs’换行。
	加载lib/file4。
	如果调用‘得符号链接’、‘~/i@zs’等于“”那么先
		赋予所在目录以调用‘得目录名’、‘参数0【主】’。
		赋予../i@zs以调用‘最终文件名’、先调用‘移除..’、‘所在目录’../gnome-shell-extensions/icons@zhscript了。
		显示‘../i@zs’换行。
		如果调用‘existdir’、‘../i@zs’那么先
			显示->换行。
			调用‘建符号链接’、‘../i@zs’、‘~/i@zs’、0。
			
			加载lib/redireconsoi4。
			赋予关键以“org.gnome.shell enabled-extensions”。
			赋予出以。
			调用‘重定向输出/行’、下代码
				赋予出【上】以‘参数1’。
			上代码、下代码
				显示‘参数’换行。
			上代码、“gsettings get ‘关键’”。
			显示‘出’换行。
			
			范围set先
				范围先
					如果调用‘尾匹配方法’、‘出’、[]那么先
						赋予入以['icons@zhscript']。
						遁出。
					了。
					如果调用‘尾匹配方法’、‘出’、]并且调用‘串位置方法’、‘出’、'icons@zhscript'小于0那么先
						赋予入以调用‘串替换方法’、‘出’、]、“, 'icons@zhscript']”。
						遁出。
					了。
					显示]?换行。
					遁出set。
				了。
				执行显示“gsettings set ‘关键’ "‘入’"”换行。
			了。
		了。
	了。
了。
