（隧道标题为‘动作’‘肇事者’。）
如果‘肇事者’不等于按钮那么退出。
赋予表达式以隧道内容为biaodashi。
如果‘动作’等于Enter或者等于E字符10n字符10t字符10er那么先
	赋予结果以调用‘计算表达式方法’为‘表达式’。
	隧道内容为jieguo为‘结果’。
	退出。
了。
如果等于Clr那么隧道内容为biaodashi为“”，退出。
如果等于Bksp那么先
	赋予表达式以调用‘子串方法’为‘表达式’为0为-1。
	隧道内容为biaodashi为‘表达式’。
	退出。
了。
如果等于Del那么退出。
如果等于copy那么
	隧道剪贴板为先隧道内容为先如果隧道内容为notebook1等于1那么jieguo否则out了了，
	退出。
如果等于paste那么
	隧道内容为先如果隧道内容为notebook1等于1那么biaodashi否则in了为隧道剪贴板，
	退出。
如果‘动作’等于web那么
	执行先如果‘窗口’等于-7那么firefox否则“start iexplore.exe”了“ http://code.google.com/p/zhscript/ ”先如果‘窗口’等于-7那么&了，
	退出。
如果等于about那么先
	隧道提示为下原样
这是 glade + zhscript 实现的第一个应用

tools2.ui是由glade绘制的界面
gtkmmsh装载并呈现该界面，同时也负责跟中文脚本交互
由此也可以看出gtkmmsh就是gtkmm的一个shell
跟ui相关联的tools2.ui_init.zs是由他在启动时解释
而tools2.ui.zs则是事件背后的处理逻辑

实现具体功能的库gjk4.so是通用意义上的库
上原样为
‘动作’先隧道标题了。
	退出。
了。
如果等于大写或者等于小写或者等于超大写或者等于超小写或者等于中文数字或者等于大写金额那么
	隧道内容为out为先调用‘‘动作’方法’为先隧道内容为in了了，
	退出。
隧道内容为biaodashi为‘表达式’‘动作’。
