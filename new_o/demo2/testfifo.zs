#!../gtkmmsh lib2/window1.glade --。
（#!/usr/lib/zhscript/gtkmmsh lib2/window1.glade --。）
隧道窗口宽高、600、300。
加载lib/defi。

隧道可见、new、1。
隧道侦听、点击、new、下代码
	隧道内容、text、。	
上代码。

赋予【顶】管道以/tmp/test.fifo。
执行“mkfifo -m 777 ‘管道’”。
隧道代码、下代码
	显示‘肇事者’--‘动作’--‘参数’↙。
	当‘肇事者’先
		等于窗口那么先
			当‘动作’先
				等于创建那么先
					加载lib/gjke4。
					
					赋予【顶】管道进程以同时解释下代码
						隧道错误提示到控制台。
						加载lib/stdc。
						加载lib/gjk4。
						循环先
							赋予柄以调用‘文件打开函数’、‘管道’、r。
							调用‘串复制函数’、‘共享内存2’、先算术先调用‘复制内存’、‘共享内存2’了+1了。
							调用‘串复制函数’、‘共享内存’（‘参数1’）、先调用‘文件得串函数’、‘柄’了。
						了。
					上代码、【顶】共享内存、128、【顶】共享内存2、16。
					显示管道进程‘管道进程’↙。
					赋予【顶】旧标志以调用‘复制内存’、‘共享内存2’。

					隧道定时器、读、100、下代码
						赋予标志以调用‘复制内存’、‘共享内存2’。
						如果‘旧标志’不等于‘标志’那么先
							赋予【顶】旧标志以‘标志’。
							赋予内容以调用‘复制内存’、‘共享内存’。
							加载lib/gjk4。
							赋予时间以调用‘串格时间方法’、%x%X。
							隧道插入、text、‘时间’(‘标志’)→‘内容’、头。
						了。
					上代码。
					
					（加载lib/thread4。
					另外解释下代码
						加载lib/stdc。
						加载lib/gjk4。
						循环先
							显示‘管道’↙。
							赋予柄以调用‘文件打开函数’、‘管道’、r。
							显示‘柄’↙。
							赋予内容以调用‘文件得串函数’、‘柄’。
							赋予时间以调用‘串格时间方法’、%x%X。
							隧道插入、text、‘时间’(‘标志’)→‘内容’、头。
						了。
					上代码。）

					隧道插入、text、“可以通过 echo test > ‘管道’ 的命令发向本程序”。
					
					退出。
				了。
				等于销毁那么先
					如果存在【顶】管道进程那么
						终止同时解释‘管道进程’、‘共享内存’、‘共享内存2’。
					
					执行“rm ‘管道’”。
					退出。
				了。
			了。
		了。
	了。
上代码。

隧道侦听、点击、exec、下代码
	（执行“echo test > ‘管道’”。）
	加载lib/stdc。
	赋予柄以调用‘文件打开函数’、‘管道’、w。
	如果‘柄’那么先
		调用‘文件送串函数’、test字符10、‘柄’。
		调用‘文件关闭函数’、‘柄’。
	了。
上代码。
