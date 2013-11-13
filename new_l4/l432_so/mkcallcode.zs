#!/usr/bin/zhscript --。
赋予个数以如果存在参数1那么‘参数1’否则4。
加载lib/defi。
加载lib/gjk4。

显示下原样
if(argc <= 0) {
	if(!ret) {
		typedef void (*func___)();
		((func___)func)();
		return 0;
	}
	typedef unsigned long int (*func___)();
	return ((func___)func)();
}
上原样。
定义进行以下代码
	别名控以参数1。
	当‘控’先
		等于那么显示“if(!ret) {”换行，跳出。
	了。
	显示“typedef ”。
	当‘控’先
		等于那么显示void，跳出。
		等于r那么显示“unsigned long int”，跳出。
	了。
	显示“ (*func___)(...);”换行“switch(argc) {”换行。
	赋予号以1。
	循环先
		如果‘号’大于‘个数’那么跳出。
		显示“case ‘号’:”换行制表符。
		当‘控’先
			等于r那么显示“return ”，跳出。
		了。
		显示“((func___)func)(”。
		赋予号2以0。
		循环先
			如果‘号2’大于等于‘号’那么跳出。
			如果‘号2’大于0那么显示“, ”。
			显示argv[‘号2’]。
			赋予号2以算术‘号2’+1。
		了。
		显示);换行。
		当‘控’先
			等于那么显示制表符break;换行，跳出。
		了。
		赋予号以算术‘号’+1。
	了。
	显示}换行。
	当‘控’先
		等于那么显示}换行，跳出。
	了。
上代码。
进行。
进行r。
