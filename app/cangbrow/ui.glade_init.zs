隧道窗口最大化。
定义【顶】【锁】读文本以下代码
	加载lib/doscmd4。
	赋予1以调用‘type’、‘参数1’。
	加载lib/txtotxt4。
	赋予1以调用‘html2text’、‘1’、0、1。
	如果‘参数2’不等于default那么
		赋予1以调用‘iconv’、‘1’、‘参数2’。
	‘1’。
上代码。
如果存在参数1那么先
	如果‘参数1’等于-f那么先
		别名当前文件以参数2。
		别名编码以参数3。
		隧道webkit、浏览器、sw。
		隧道标题、‘当前文件’。
		如果存在编码那么
			隧道webkit、内容、先读文本‘当前文件’、‘编码’了、file:///、浏览器。
		否则
			隧道webkit、访问、file://‘当前文件’、浏览器。
		退出。
	了。
了。
加载lib/defi。
加载lib/regexpr4。
加载lib/file4。
加载lib/gjke4。
加载lib/stdc。
加载lib/doscmd4。
赋予【顶】【锁】家目录以调用‘得环境变量函数’、HOME。
赋予【顶】【锁】配置目录以‘家目录’/.config/cangbrow_zs。
执行“mkdir -p '‘配置目录’'”。
赋予【顶】【锁】配置文件以‘配置目录’/setting.zs。
赋予应用目录以调用‘最终文件名’、先调用‘得目录名’、‘保留字’了。
赋予gtkmmsh以‘应用目录’/gtkmmsh。
如果调用‘exist’、‘gtkmmsh’否则赋予gtkmmsh以‘应用目录’/ui。
赋予【顶】【锁】gtkmmsh以‘gtkmmsh’。
赋予【顶】【锁】应用文件以隧道界面文件名。

赋予【顶】【锁】设置	之图以“<img src='file:///usr/share/icons/gnome/32x32/actions/gtk-properties.png' title='设置'>”。
赋予【顶】【锁】删		之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/edit-delete.png' title='删'>”。
赋予【顶】【锁】辑		之图以“<img src='file:///usr/share/icons/gnome/16x16/apps/text-editor.png' title='编辑'>”。
赋予【顶】【锁】文		之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/format-text-underline.png' title='按文本打开'>”。
赋予【顶】【锁】文gb	之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/format-text-underline.png' title='按gb18030文本打开'>”。
赋予【顶】【锁】新开	之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/window-new.png' title='新开'>”。
赋予【顶】【锁】新文	之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/window-new.png' title='按文本新开'>”。
赋予【顶】【锁】新文gb	之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/window-new.png' title='按gb18030文本新开'>”。
赋予【顶】【锁】开		之图以“<img src='file:///usr/share/icons/gnome/16x16/actions/fileopen.png' title='用系统默认程序打开'>”。
赋予【顶】【锁】所有	之图以“<img src='file:///usr/share/icons/gnome/24x24/actions/help-about.png' width=12 height=12 title='所有'>”。
赋予【顶】【锁】上		之图以“<img src='file:///usr/share/icons/gnome/32x32/actions/go-up.png' title='上一张'>”。
赋予【顶】【锁】下		之图以“<img src='file:///usr/share/icons/gnome/32x32/actions/go-down.png' title='下一张'>”。
赋予【顶】【锁】刷		之图以“<img src='file:///usr/share/icons/gnome/32x32/actions/view-refresh.png' title='刷新'>”。
赋予【顶】【锁】索引	之图以“<img src='file:///usr/share/icons/gnome/32x32/actions/back.png' title='索引'>”。
赋予【顶】【锁】删1	之图以“<img src='file:///usr/share/icons/gnome/24x24/actions/edit-delete.png' title='删'>”。
赋予【顶】【锁】辑1	之图以“<img src='file:///usr/share/icons/gnome/24x24/apps/text-editor.png' title='编辑'>”。

如果‘参数数目’大于0那么先
	赋予【顶】不保存配置文件以。
	赋予【顶】文件夹及类型以。
	迭代数组下代码
		赋予【顶】文件夹及类型以‘文件夹及类型’‘参数1’←↙←↙。
	上代码、参数。
了否则先
	如果调用‘exist’、‘配置文件’那么加载‘配置文件’。
	否则先
		赋予【顶】文件夹及类型以
			‘家目录’/视频←↙←↙
			‘家目录’/图片←↙←↙
			‘家目录’/文档←↙←↙
			‘家目录’/音乐←↙←↙
			。
	了。
了。

定义【顶】【锁】读文件夹以下代码
	赋予目录控制以adlo3。
	当‘参数数目’先
		等于3那么先
			别名目录以参数1。
			别名通配以参数2。
			别名级以参数3。
			跳出。
		了。
		等于2那么先
			别名目录以参数1。
			别名通配以当前通配。
			别名级以参数2。
			跳出。
		了。
		那么先
			如果调用‘正则攫’、‘参数1’、\?([^\?]*)、参。
			当‘参数目’先
				等于2那么先
					赋予目录以调用‘urldecode’、‘参之1’。
					别名通配以当前通配。
					别名级以参之2。
					跳出。
				了。
				等于3或者等于4那么先
					赋予目录以调用‘urldecode’、‘参之1’。
					赋予通配以调用‘urldecode’、‘参之2’。
					如果‘参数目’等于3那么
						别名级以参之3。
					否则先
						赋予目录控制以‘参之3’。
						别名级以参之4。
					了。
					赋予【顶】当前通配以‘通配’。
					跳出。
				了。
			了。
		了。
	了。
	
	赋予【顶】当前级以‘级’。
	如果调用‘正则配’、‘目录’、/$、l否则
		赋予目录以‘目录’/。
	赋予通配以调用‘正则替’（‘串替换方法’）、‘通配’、(\?)、%3F。
	赋予串以“<tr><td colspan=9>”。
	如果不‘级’那么
		赋予串以‘串’“<a href='zhscript:?‘目录’?‘通配’?/'>”。
	赋予串以‘串’‘目录’。
	如果不‘级’那么
		赋予串以‘串’</a>。
	赋予串以‘串’“ <a href='zhscript:?‘目录’?‘通配’?slo1?”先如果不‘级’那么/否则‘级’了'>‘所有之图’</a></td></tr>。
	如果‘级’那么先
		赋予【顶】当前目录以‘目录’。
		赋予串以‘串’“<tr><td colspan=9><a href='zhscript:”。
		如果调用‘正则攫’、‘级’、([/]*)/、上等于0或者不‘上之1’那么
			赋予串以‘串’/。
		否则
			赋予串以‘串’/'>/</a></td></tr><tr>“<td colspan=9><a href='zhscript:?”先调用‘移除..’、‘目录’..了?‘上之1’。
		赋予串以‘串’'>..</a></td></tr>。
	了。
	加载lib/gjk4。
	赋予交错背景以0。
	赋予处理以下代码
		别名名以参数1。
		别名上以参数2。
		赋予是目录以调用‘正则配’、‘名’、/$、l。
		赋予【上】交错背景以如果‘交错背景’那么0否则1。
		赋予‘上’串以‘串’“<tr class=item‘交错背景’><td><a href='zhscript:”?‘目录’‘名’。
		如果‘是目录’那么先
			如果不‘级’那么
				赋予‘上’串以‘串’?‘通配’。
			赋予‘上’串以‘串’?‘级’/。
		了否则先
			赋予【顶】号以算术‘号’+1。
			赋予‘上’串以‘串’?‘号’。
			隧道webkit、附加、“list_[‘号’]='‘目录’‘名’';”、浏览器。
		了。
		赋予‘上’串以‘串’'>‘名’</a></td>。
		如果不‘是目录’那么先
			赋予‘上’串以‘串’“<td><a href='zhscript:text-default?‘目录’‘名’?‘号’'>‘文之图’</a></td>”。
			赋予‘上’串以‘串’“<td><a href='zhscript:text-gb18030?‘目录’‘名’?‘号’'>‘文gb之图’</a></td>”。
		了否则
			赋予‘上’串以‘串’<td></td><td></td>。
		赋予‘上’串以‘串’“<td><a href="zhscript:exec?xdg-open '‘目录’‘名’'&">‘开之图’</a></td>”。
		如果不‘是目录’那么先
			赋予‘上’串以‘串’“<td><a href='zhscript:new?‘目录’‘名’'>‘新开之图’</a></td>”。
			赋予‘上’串以‘串’“<td><a href='zhscript:new-text-default?‘目录’‘名’'>‘新文之图’</a></td>”。
			赋予‘上’串以‘串’“<td><a href='zhscript:new-text-gb18030?‘目录’‘名’'>‘新文gb之图’</a></td>”。
			赋予‘上’串以‘串’“<td><a href='zhscript:edit?‘目录’‘名’'>‘辑之图’</a></td>”。
		了否则
			赋予‘上’串以‘串’<td></td><td></td><td></td><td></td>。
		赋予‘上’串以‘串’“<td><a href='zhscript:del?‘目录’‘名’'>‘删之图’</a></td></tr>”。
	上代码。
	
	隧道标题、“扫描 ‘目录’”。
	隧道不堵塞。
	（解释‘dir’、下代码
		解释‘处理’、‘参数1’、【上】【上】。
	上代码）
	赋予搜以调用‘dir.begin’
	、‘目录’、‘通配’、‘目录控制’。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		解释‘处理’、‘名’、【上】。
	了。
	调用‘dir.end’、‘搜’。
	隧道标题、“ ”。
	
	调用‘加反斜杠’、‘串’、C。
上代码。

定义【顶】【锁】列根以下代码
	调用‘正则攫’、‘文件夹及类型’←↙、([^←↙]+)←↙([^←↙]*)←↙、根。
	赋予串以“<p class=box><a href='zhscript:set'>‘设置之图’</a></p><table align=center>”。
	赋予【顶】号以-1。
	隧道webkit、附加、“list_=new Array();”、浏览器。
	迭代数组下代码
		别名目录以参数1。
		别名通配以参数2。
		赋予【上】串以‘串’读文件夹‘目录’、‘通配’、。
	上代码、根。
	赋予串以‘串’</table>。
	隧道webkit、附加、
		__("set").style.display="none";
		__("ctrl").style.display="none";
		__("show").style.display="none";
		__("show2").style.display="none";
		__("list").innerHTML="‘串’";
		__("list").style.display="";
		、浏览器。
上代码。

定义【顶】【锁】列文件夹以下代码
	赋予【顶】号以-1。
	隧道webkit、附加、“list_=new Array();”、浏览器。
	隧道webkit、附加、
		__("list").innerHTML="“<table align=center>”先读文件夹‘参数1’了</table>";
		__("ctrl").style.display="none";
		__("show").style.display="none";
		__("show2").style.display="none";
		__("list").style.display="";
		、浏览器。
上代码。

定义【顶】【锁】是图片以下代码
	调用‘正则配’、‘参数1’、\.(jpg|jpeg|gif|png)$、eil。
上代码。

定义【顶】【锁】呈现以下代码
	赋予【顶】当前文件以‘参数1’。
	赋予【顶】当前序号以‘参数2’。
	隧道标题、‘当前文件’。
	赋予show以about:blank。
	赋予show2以。
	循环先
		别名编码以参数3。
		如果存在编码那么先
			赋予【顶】当前编码以‘编码’。
			赋予show2以调用‘加反斜杠’、先读文本‘当前文件’、‘编码’了、C。
			跳出。
		了。
		如果存在当前编码那么删除【顶】当前编码。
		（如果是图片‘当前文件’那么先
			赋予show2以“<img src='‘当前文件’'>”。
			跳出。
		了。）
		赋予show以file://‘当前文件’。
		跳出。
	了。
	隧道webkit、附加、“
		__("show").src="‘show’";
		__("show2").innerHTML="‘show2’";
		__("ctrl").innerHTML="
			<a href='zhscript:list'>‘索引之图’</a><br>
			<a href='zhscript:prev'>‘上之图’</a><br>
			<a href='zhscript:next'>‘下之图’</a><br>
			<a href='zhscript:reload'>‘刷之图’</a><br>
			<a href='zhscript:edit?'>‘辑1之图’</a><br>
			<a href='zhscript:del?'>‘删1之图’</a>";
		if(!ctrl_){
			__("ctrl").style.opacity=1;
			__("ctrl").style.display="";
			setTimeout("__('ctrl').style.opacity=0;",2000);
		}
		__("list").style.display="none";
		__("show").style.display="";
		__("show2").style.display="";
		”、浏览器。
上代码。

隧道webkit、浏览器、sw、
	侦听为zhscript:为下代码
		别名参以参数1。
		
		如果‘参’等于/那么列根，退出。
		
		如果‘参’等于set那么先
			隧道webkit、附加、
				__("list").style.display="none";
				__("set").style.display="";
				、浏览器。
			退出。
		了。
		
		如果‘参’等于list那么先
			隧道webkit、附加、
				__("show").src="about:blank";
				__("show2").innerHTML="";
				__("ctrl").style.display="none";
				__("show").style.display="none";
				__("show2").style.display="none";
				__("list").style.display="";
				、浏览器。
			退出。
		了。
		
		如果‘参’等于prev或者等于next那么先
			如果‘参’等于prev那么
				赋予【顶】当前序号以算术‘当前序号’-1。
			否则
				赋予【顶】当前序号以算术‘当前序号’+1。
			隧道webkit、附加、“var i=‘当前序号’;
				if(list_.length>0){
					if(i<0)
						i=list_.length-1;
					else if(i>=list_.length)
						i=0;
					window.location.href="zhscript:”先如果存在当前编码那么text-‘当前编码’了“?"+list_[i]+"?"+i;
				}
				”、浏览器。
			退出。
		了。
		
		如果‘参’等于reload那么先
			如果存在当前编码那么
				呈现‘当前文件’、‘当前序号’、‘当前编码’
			否则
				呈现‘当前文件’、‘当前序号’。
			退出。
		了。
		
		如果调用‘正则配’、‘参’、^set\?、l那么先
			调用‘正则攫’、‘参’、(\?|&){1,1}([^=]+)=([^&]+)。
			赋予【顶】文件夹及类型以调用‘urldecode’、‘之3’。
			如果不存在“不保存配置文件”那么
				调用‘echo’、“赋予【顶】文件夹及类型以下原样‘文件夹及类型’上原样。”、‘配置文件’。
			列根。
			退出。
		了。
		
		如果调用‘正则攫’、‘参’、^(del|edit|new)\?(.*)、、el那么先
			如果不‘之2’那么
				赋予文件以‘当前文件’。
			否则
				赋予文件以调用‘urldecode’、‘之2’。
			当‘之1’先
				等于del那么先
					赋予命令以“rm -rf '‘文件’'”。
					加载lib2/msgbox。
					如果隧道提示为‘命令’、、‘询问’、‘是否按钮’不等于‘是’那么退出。
					执行‘命令’。
					（隧道webkit、附加、list_[‘序号’]=undefined;、浏览器。）
					跳出。
				了。
				等于edit那么先
					当先
						是图片‘文件’那么赋予命令以gimp，跳出。
						那么赋予命令以gedit。
					了。
					执行“‘命令’ '‘文件’'&”。
					跳出。
				了。
				等于new那么先
					执行“'‘gtkmmsh’' '‘应用文件’' -f '‘文件’'&”。
					跳出。
				了。
			了。
			退出。
		了。
		
		如果调用‘正则攫’、‘参’、^text-([^\?]+)\?(.*)\?(.*)、、el那么先
			呈现先调用‘urldecode’、‘之2’了、‘之3’、‘之1’。
			退出。
		了。
		
		如果调用‘正则攫’、‘参’、^new-text-([^\?]+)\?(.*)、、el那么先
			执行“'‘gtkmmsh’' '‘应用文件’' -f '”先调用‘urldecode’、‘之2’了“' ‘之1’&”。
			退出。
		了。
		
		如果调用‘正则攫’、‘参’、^exec\?(.+)、、el那么
			执行调用‘urldecode’、‘之1’，退出。

		如果调用‘正则配’、‘参’、/$、l那么	列文件夹‘参’，退出。
		
		如果调用‘正则攫’、‘参’、\?([^\?]*)那么	
			呈现先调用‘urldecode’、‘之1’了、‘之2’，退出。
	上代码、
	侦听为消息为下代码
		隧道标题、‘参数’。
	上代码、
	侦听为标题改变为下代码
		隧道标题、‘参数1’。
	上代码、
	侦听为覆盖链接为下代码
		隧道标题、‘参数1’。
	上代码。
隧道webkit、内容、下原样<html>
<head>
<style>
body{
	margin:0px 0px 0px 0px;
}
#show{
	width:100%;height:100%;
	position:absolute;left:0px;top:0px;
	margin:0 0 0 0;
	border-top-width:0px;
	border-right-width:0px;
	border-bottom-width:0px;
	border-left-width:0px;
}
div{
	position:absolute;left:0px;top:0px;
	font-size:12px;
}
table{
	font-size:12px;
}
#list{
	overflow:auto;white-space:nowrap;
	width:100%;height:100%;
}
#set,#show2{width:100%;height:100%;}
.box{
	background-color:#FFF;
	border:1px dashed #000;
}
#ctrl{
	position:fixed;
	top:10px;
	z-index:1;
}
textarea{width:100%;height:50;}
.item0{
	background-color:#ded;
}
.item1{
	background-color:#dde;
}
</style>
<script>
function __(id){
	return document.getElementById(id);
}
window.onresize=function(){
	__("d").style.height=(document.body.clientHeight-60)+"px";
}
document.onkeypress=function(event){
	var c=String.fromCharCode(event.charCode);
	switch(c){
	case'q':
		if(__("show2").style.display=="")
			window.location.href="zhscript:list";
		else if(__("list").style.display=="")
			window.location.href="zhscript:set";
		return;
	}
	if(__("show2").style.display=="none")
		return;
	switch(c){
	case'b':
		window.location.href="zhscript:prev";
		break;
	case'n':
		window.location.href="zhscript:next";
		break;
	case'f':
		window.location.href="zhscript:reload";
		break;
	case'e':
		window.location.href="zhscript:edit?";
		break;
	case'x':
		window.location.href="zhscript:del?";
		break;
	}
}
var list_;
var ctrl_=false;
</script>
</head>
<body>
<div id=set>
<form  action="zhscript:set">
搜索的文件夹以及类型：<br>
<textarea name=d id=d>上原样‘文件夹及类型’下原样</textarea><br>
<input type=submit>
</form>
</div>
<div id=list></div>
<iframe id=show src="about:blank"></iframe>
<div id=show2></div>
<div id=ctrl class=box onmouseover="this.style.opacity=1;ctrl_=true;" onmouseout="this.style.opacity=0;ctrl_=false;"></div>
<script>
window.location.href="zhscript:/";
</script>
</body>
</html>上原样、file:///、浏览器。
