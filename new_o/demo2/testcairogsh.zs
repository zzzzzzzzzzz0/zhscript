#!../cairogsh --。
加载lib/defi。

使主窗、侦听、
	创建为下代码
		显示‘参数0’--‘参数’换行。
		使主窗、大小、300、100。
		使主窗、居中。
		使主窗#1、加钮、-、gtk-ok。
		
		使icon窗、创建、自绘。
		使icon窗、无修饰。
		使icon窗、大小、200、200。
		赋予image【主】以使../edit/icon.png、源。
		使icon窗、绘图为下代码
			别名口以参数1。
			基于“调用‘口’、‘参数栈’”先
				OPERATOR_SOURCE。
				源、‘image’、0、0。
				绘制。
			了。
		上代码。
		使icon窗、移动、0、0。
		
		使字幕窗、创建、弹出窗、自绘。
		使字幕窗、大小、500、120。
		使字幕窗、侦听、
			显现为下代码
				使字幕窗、鼠标穿透。
			上代码。
		使字幕窗、绘图为下代码
			别名口以参数1。
			基于“调用‘口’、‘参数栈’”先
				OPERATOR_SOURCE。
				文字字体、“宋体”。
				文字大小、100。
				移为0、100。
				文字为中文脚本。
			了。
		上代码。
		使字幕窗、移动、200、20。
	上代码、
	显现为下代码
		使icon窗、显现。
		使字幕窗、显现。
	上代码。
	
使主窗、创建、标签页。

使代码为下代码
	显示‘参数0’--‘参数’换行。
上代码。
