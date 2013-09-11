赋予库名以‘参数0’。
如果存在‘库名’【主】那么退出。
赋予‘库名’【主】以调用‘最终文件名’、eleeye_engine。
显示‘‘库名’’↙。
如果不‘‘库名’’那么先
	赋予错以执行显示“apturl-gtk apt:eleeye”↙。
	如果‘错’那么先
		显示消息eleeye安装失败(‘错’)。
		删除‘库名’【主】。
		退出。
	了。
了。

赋予eleeye级别【主】以1。
定义eleeye走【主】以下代码
	调用‘电脑命令’、“position fen ”调用‘fens’。
	调用‘电脑命令’、“go depth ‘eleeye级别’”。
上代码。

赋予eleeye未初始化【主】以1。
定义eleeye初始化【主】以下代码
	如果‘eleeye未初始化’那么先
		调用‘电脑初始化’、‘回调1【主】’、下代码
			显示‘参数1’↙。
			（draw同意和棋）
			（resign ROBOT_LOSE）
			如果调用‘正则配’、‘参数1’、(^|↙)nobestmove↙、el那么先
				隧道窗口标题、qipan、“‘当前局’ eleeye 认输”。
				退出。
			了。
			如果遍历正则‘参数1’、(^|↙)“bestmove (....)”、下代码
				显示{‘参数’}↙。
				调用‘走串’、‘参数2’。
				同步显示。
				记入棋谱eleeye、调用‘这步叫法’。
				退出。
			上代码、el。
		上代码。
		如果调用‘电脑启动’等于0那么显示eleeye未能启动↙，退出。
		赋予eleeye未初始化【主】以0。
		调用‘电脑命令’、下原样setoption newgame
setoption idle large
setoption style risky
setoption knowledge none
setoption pruning  large
setoption randomness large
setoption usebook false上原样。
	了。
上代码。

隧道代码为下代码
	如果‘肇事者’等于窗口并且‘动作’等于销毁那么
		调用‘电脑停止’。
上代码。
