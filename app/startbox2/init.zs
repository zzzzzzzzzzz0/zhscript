加载lib/defi。
加载lib/gjk4。
赋予【主】~以调用‘得环境变量方法’、HOME。
赋予【主】配置目录以‘~’/.config/startbox_zs。
赋予【主】配置文件以‘配置目录’/init2.zs。
加载lib/file4。
赋予【主】所在目录以调用‘得目录名’、先调用‘最终文件名’、‘【上】参数0’了。
赋予项目名【主】以启动盒。

加载lib2/js.zs。
加载lib/timeout4。
加载lib/gjke4。
加载lib/doscmd4。

定义隧道【主】以下代码
	显示‘参数0’--‘参数’换行。
	赋予号以1。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数数目’那么跳出。
		赋予名以‘参数1’先如果‘号’大于2那么算术‘号’-1了【主】。
		显示‘名’换行。
		赋予‘名’以‘参数‘号’’。
	了。
上代码。

定义【主】确定图标以下代码
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数数目’那么跳出。
		如果调用‘exist’、‘参数‘号’’那么‘参数‘号’’，退出。
	了。
	赋予1以/usr/share/icons/hicolor/scalable/apps/gnome-panel-launcher.svg。
	如果调用‘exist’、‘1’那么‘1’，退出。
	/usr/share/icons/Humanity/apps/48/application-default-icon.svg。
上代码。

定义【主】刷新图标夹以下代码
	使主窗、插脚、htm__("icons", "")。
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		别名标题以项目之‘号’之2【顶】。
		如果不存在标题那么跳出。
		别名封面以项目之‘号’之3。
		如果‘封面’等于缺省那么
			赋予封面以确定图标。
		当先
			调用‘头匹配方法’、‘标题’、“* ” 或者
			调用‘头匹配方法’、‘标题’、“| ”那么先
				赋予加以调用‘子串方法’、‘标题’、0、1。
				赋予项目之‘号’之夹态【顶】以‘加’。
				赋予项目之‘号’之夹名【顶】以调用‘子串方法’、‘标题’、1。
				跳出。
			了。
			赋予加以。
		了。
		如果‘加’等于*那么先
			进行折叠‘号’、hide。
			赋予加以kai。
		了。
		赋予内容以“
<a href="javascript:" onclick="click‘加’__(‘号’)" title="”先如果不‘加’那么‘标题’否则‘项目之‘号’之夹名’了“">
<div class="img baibantou_bg" id=bg‘号’><img ”。
		如果调用‘exist’、‘封面’否则先
			赋予封面以‘所在目录’no1.png。
		了。
		赋予内容以‘内容’“
src="file://‘封面’"></div><div class=title><span class=title2 id=title‘号’>‘标题’</span></div></a>”。
		增加图标‘号’、‘内容’。
	了。
上代码。

定义增加图标【主】以下代码
	别名号以参数1。
	别名内容以参数2。
	赋予内容以调用‘加反斜杠’、‘内容’、C。
	使主窗、插脚、“
	var d = new__("div");
	d.className = "fengmian";
	d.id = "fengmian‘号’";
	htm__(d, "‘内容’");
	add__(d, __("icons"));”。
	（使不堵塞。）
上代码。

定义【主】初始图标夹以下代码
	别名图宽以读图片限制。
	赋予宽以算术‘图宽’+20。

	赋予和谐前景色【主】以#e3d08e。
	赋予和谐背景色【主】以#25414d。

	使主窗、内容、“
<script>‘js函数集’</script>
<style>
img{
	max-width:‘图宽’px;
	max-height:‘图宽’px;
}
.img{
	width:‘宽’px;
	height:‘宽’px;
	vertical-align:middle;  
	display:table-cell;
}
.baibantou_bg {
	background-color:rgba(255, 255, 255, 0.5);
}
.heibantou_bg {
	background-color:rgba(0, 0, 0, 0.5);
}
body{
	background-image:url(‘所在目录’/bg1.jpg); background-repeat:repeat;
	font-size:12px;
	color:#fff;
	/*-webkit-text-stroke: 1px #000;*/
	-webkit-user-select: none;
	margin:0px;
	padding:6 0 0 6;
}
a {
	text-decoration:none;
}
.fengmian{
	float:left;
	padding:6;
	text-align:center;
	width:‘宽’px;
}
.title{
	white-space:nowrap;
	overflow:hidden;
	text-overflow:ellipsis;
	color:‘和谐前景色’;
	padding:7 0 3 0;
}
.title2{
	background-color:‘和谐背景色’;
	border:1px dashed ‘和谐前景色’;
	padding:1 3 1 3;
}
</style>
<script>
function click__(i) {
	z$("点击" + i);
}
function clickkai__(i) {
	z$("夹点击" + i);
}
</script>
<div id=icons>正在装入…</div>”、基址为file:///。
	使主窗、图标、‘所在目录’/icon.png。
上代码。

定义【主】分析选项参数以“
赋予【上】后退以‘参数1’。
赋予【上】脚本以0。
解释【代码】“基于“
	如果不存在参数2那么退出。
	赋予【上】【上】【上】‘参数1’以‘参数2’。
”先”‘参数1’“了。”。
”。

定义弹出提示【主】以下代码
	使主窗、插脚、alert("先调用‘加反斜杠’、‘参数1’、C了")。
上代码。

定义【主】系统命令以“
分析选项参数‘参数2’。
如果存在命令写入文件【主】那么先
	调用‘echo’、#!先
			如果‘脚本’那么先
				赋予l以‘所在目录’l。
				如果调用‘exist’、‘l’否则
					赋予l以‘所在目录’../../new_o/l。
				。
				“‘l’ ---- ‘【主】参数’ ---- --。”
				↙
				“赋予0以‘【主】参数0’。”
			了否则/bin/sh
		了↙‘参数1’↙、‘命令写入文件’。
	执行“chmod +x '‘命令写入文件’'”。
了否则先
	如果‘脚本’那么解释‘参数1’。
	否则先
		赋予返回码以执行‘参数1’&。
		如果‘返回码’不等于0那么弹出提示‘参数1’↙返回码是‘返回码’，退出。
	了。
了。
如果存在参数3并且‘参数3’那么退出。
如果‘后退’那么结束。
”。

赋予号以0。
循环先
	赋予号以算术‘号’+1。
	如果‘号’大于3那么跳出。
	加载先如果调用‘exist’、‘配置文件’.‘号’那么‘配置文件’.‘号’否则init2.zs.‘号’了。
了。

