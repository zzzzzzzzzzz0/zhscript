#!../vtesh --。
加载lib/defi。

加载lib/menu4。
赋予命令菜单【主】以调用‘新建菜单’、
	缺省代码为下代码
		使主窗、输入、‘参数0’换行。
	上代码、
	为ls、
	为“echo $PS1”。

使主窗、侦听、
	创建为下代码
		（使主窗、不透明度、0.85。）
		使主窗、大小、600、600。
		使主窗、居中。
		使主窗#1、加钮、-、大小为5、
			缺省代码为下代码
				使主窗、‘参数0’。
			上代码、
			名为复制到剪贴板、gtk-copy、
			名为从剪贴板粘贴、gtk-paste、
			名为清除、代码为下代码
				使主窗、输入、字符21字符11
			上代码、gtk-clear、
			名为reset、gtk-refresh、
			-、
			代码为下代码
				调用‘弹出菜单’、‘‘参数0’’。
			上代码、
			名为命令菜单、gtk-justify-fill、
			-、
			代码为下代码
				使主窗、新开。
			上代码、名为新建一页、gtk-add。
		解释‘置【主】’、主窗。
	上代码、
	新开为下代码
		显示‘参数0’--‘参数’换行。
		解释‘置【主】’、‘参数‘参数数目’’。
	上代码、
	显现为下代码
		使主窗、背景色、1、1、1、1。
		使主窗、前景色、0、0、0、1。
	上代码。
使主窗、创建、（顶标签页）表格（、行为4、列为1）。

赋予置【主】以下代码
	别名窗以参数1。
	赋予pid以使‘窗’、命令、/bin/bash、、/。
	显示pid=‘pid’换行。
	使‘窗’、字体、“Monospace 10”。
上代码。

使代码为下代码
	显示‘参数0’--‘参数’换行。
上代码。