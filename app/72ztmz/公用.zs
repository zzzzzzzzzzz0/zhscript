加载lib/defi。
加载lib/file4。
加载lib/regexpr4。
加载lib/gjk4。
加载lib/doscmd4。
加载lib/clpars4。

赋予根【主】以调用‘得目录名’、先调用‘最终文件名’、‘参数0【主】’了。
显示‘根’换行。
赋予阵图目录【主】以‘根’zhentu馆/。

赋予吕祖目录名【主】以吕祖营/。
赋予吕祖目录【主】以赋予预吕祖目录【主】以‘根’‘吕祖目录名’。
赋予女将目录名【主】以杨门女将营/。
赋予女将目录【主】以赋予预女将目录【主】以‘根’‘女将目录名’。
赋予策略目录名【主】以策略馆/。
赋予策略目录【主】以赋予预策略目录【主】以‘根’‘策略目录名’。

赋予工事文件名【主】以工事.png。
赋予工事文件【主】以赋予预工事文件【主】以‘阵图目录’‘工事文件名’。
赋予地表文件名【主】以地表.png。
赋予地表文件【主】以赋予预地表文件【主】以‘阵图目录’‘地表文件名’。

调用‘命令行追回调’、
	-ztml、、1、下代码
		别名1以参数1。
		如果调用‘尾匹配方法’、‘1’、/否则
			赋予1以‘1’/。
		赋予阵图目录【主】以‘1’。
		显示‘阵图目录’换行。
		调用‘参数处理’、、、1、下代码
			别名2以参数1。
			赋予3以如果调用‘尾匹配方法’、‘2’、目录那么‘existdir’否则‘exist’。
			赋予1以‘阵图目录’‘‘2’名’。
			如果调用‘3’、‘1’那么显示‘2’‘1’换行，
				赋予‘2’【主】以赋予预‘2’【主】以‘1’。
		上代码、----、工事文件、地表文件、吕祖目录。
	上代码、
	-zt | -zdjb、、1、下代码
		赋予‘参数0’【主】以‘参数1’。
	上代码。

赋予图宽【主】以赋予图高【主】以665。
赋予纵格数【主】以赋予横格数【主】以19。
赋予人宽【主】以赋予人高【主】以算术‘图宽’/‘横格数’。

赋予　【主】以0。
赋予乂【主】以1。
赋予卍【主】以-1。
赋予卐【主】以-2。
赋予十【主】以-3。

定义打开属性文件【主】以下代码
	别名文件以参数1。
	赋予上以【上】【上】【上】。
	如果存在参数2那么赋予上以‘上’‘参数2’。
	解释
	下代码
		基于“赋予‘参数1’
	上代码
	‘上’
	下代码
		以‘参数2’。”先
	上代码
	先调用‘type’、‘文件’了
	“了”。
上代码。

定义打开阵图【主】以下代码
	如果存在参数2那么
		赋予文件以‘参数1’.zhentu。
	否则
		赋予文件以隧道文件选择为打开、‘参数1’、预选为‘阵图目录’、类型为阵图文件为*.zhentu。
	如果‘文件’那么先
		赋予阵名【上】以调用‘得文件主名’、‘文件’。
		隧道标题为“‘应用名’ 之 ‘阵名’”。
		打开属性文件‘文件’、【上】。
	了。
	‘文件’。
上代码。
