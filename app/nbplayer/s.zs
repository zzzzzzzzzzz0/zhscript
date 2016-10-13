
定义通过vlc播放【主】以下代码
	显示‘参数0’--‘参数’换行。
	别名号以参数1。
	得海报信息‘号’。
	使主窗、最小化。
	赋予链接以/tmp/‘应用名’_。
	执行显示
	“ln -sf "‘视频’" ‘链接’”换行
	（ --qt-minimal-view）
	“vlc --video-on-top --play-and-exit ‘链接’ &”换行。
上代码。

定义配同名图【主】以下代码
	显示‘参数0’--‘参数’换行。
	别名号以参数1。
	别名窗以参数2。
	得海报信息‘号’。

	如果存在参数3那么先
		赋予图以‘家目录’/.cache/movbrow_zs/‘标题’.png。
		赋予tmp以/tmp/。
	了否则先
		赋予图以‘主干’.png。
		赋予tmp以‘主干’-。
	了。
	赋予tmp以‘tmp’‘应用名’_shot。

	赋予果以用mplayer截图‘视频’、‘图’、‘tmp’。
	显示‘果’换行。
	如果‘果’那么先
		赋予图以‘图’‘果’。
		使‘窗’、插脚、__("img").src="‘图’"。
		使主窗#1、插脚、__("img‘号’").src="‘图’"。
	了。
上代码。

定义“文件删除”【主】以下代码
	显示‘参数0’--‘参数’换行。
	别名号以参数1。
	别名窗以参数2。
	得海报信息‘号’。
	赋予出以‘视频’。
	如果‘封面’不等于‘无图’那么
		赋予出以‘出’换行‘封面’。
	调用‘重定向输出\行’、下代码
		别名名以参数1。
		如果‘名’等于‘视频’或者等于‘封面’否则
			赋予出【上】以‘出’换行‘名’。
	上代码、“ls "‘主干’"*”。
	赋予出以‘出’换行|d换行先调用‘得目录名’、‘主干’了。
	使‘窗’、插脚、show__("del");htm__("delist","先调用‘加反斜杠’、‘出’、C了");。
上代码。

定义“确定文件删除”【主】以下代码
	赋予文件以调用‘串替换方法’、‘参数1’、换行、“" "”。
	赋予文件以调用‘串替换方法’、‘文件’、|d、“"&&rmdir -p --ignore-fail-on-non-empty"”。
	赋予文件以调用‘串替换方法’、"‘文件’"、""、。
	别名窗以参数2。
	赋予错以执行显示“rm ‘文件’”换行。
	显示‘错’换行。
	如果不‘错’那么
		使‘窗’、关闭。
上代码。

定义秀详情页【主】以下代码
	别名号以参数1。
	别名窗以参数2。
	得海报信息‘号’。
	用mplayer取信息‘视频’。
	使‘窗’、标签、‘标题’。
	赋予角宽以105。
	赋予窗宽以使主窗（屏幕）、宽度。
	赋予最大宽以算术‘窗宽’-‘角宽’*2-50。
	显示最大宽‘最大宽’--‘窗宽’换行。
	使‘窗’、内容、“<script>‘js函数集’
	function sou__() {
		var text = window.getSelection();
		if(text != "")
			z$('使主窗#gjc“' + text + '”、新开、about:/gjc?s=“' + text + '”');
	}
	</script>
	<style>
	table {border:0;border-collapse:collapse;margin-left:auto;margin-right:auto;}
	.shang {background-image:url('‘应用目录’/xiangkuang-shangbian.png');background-repeat:repeat-x;}
	#xia {-webkit-transform:rotate(180deg);}
	.you {background-image:url('‘应用目录’/xiangkuang-youbian.png');background-repeat:repeat-y;}
	#zuo {-webkit-transform:rotate(180deg);}
	.jiao {background-image:url('‘应用目录’/xiangkuang-jiao.png');width:‘角宽’px;height:110px;}
	#zuoshang {-webkit-transform:rotate(180deg) scaleY(-1);}
	#zuoxia {-webkit-transform:scaleY(-1) scaleX(-1);}
	#youxia {-webkit-transform:rotate(180deg) scaleX(-1);}
	img {
		border:0;
		max-width:‘最大宽’px;
	}
	</style>
	<div>
	<a href="javascript:" onclick="z$('进行播放‘号’')">播放</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('进行播放‘号’、50')">半音量播放</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('进行播放‘号’、0')">无声片</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('配同名图‘号’、‘窗’')">配同名图</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('配同名图‘号’、‘窗’、')">配图</a>
	”加入截图集“
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('秀详情页‘号’、‘窗’')">刷新</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('内容刷新‘窗’')">内容刷新</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('文件删除‘号’、‘窗’')">文件删除</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="z$('通过vlc播放‘号’')">vlc</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick="sou__()">Search</a>
	</div>
	<div id=del>
	<pre id=delist>
	</pre>
	<a href="javascript:" onclick="z$('确定文件删除下原样'+htm__('delist')+'上原样、‘窗’')">确定</a>
	&nbsp; &nbsp;
	<a href="javascript:" onclick='hide__("del")'>取消</a>
	</div>
	<pre>‘标题’</pre>
	<pre>‘‘视频’长度’ ‘‘视频’宽度’x‘‘视频’高度’</pre>
	”先
		如果存在‘视频’演员表【主】那么
			<pre>先替换关键词‘‘视频’演员表’了</pre>
	了“
	<table>
	<tr>
	<td class=jiao id=zuoshang></td>
	<td class=shang></td>
	<td class=jiao></td>
	</tr>
	<tr>
	<td class=you id=zuo></td>
	<td>
	<a href="javascript:" onclick="z$('进行播放‘号’')">
	<img src="‘封面’" id=img>
	</a>
	</td>
	<td class=you></td>
	</tr>
	<tr>
	<td class=jiao id=zuoxia></td>
	<td class=shang id=xia></td>
	<td class=jiao id=youxia></td>
	</tr>
	</table>
	<script>
	hide__("del");
	document.onkeydown = function(evt) {
		var key = String.fromCharCode(evt.keyCode);
		switch(key) {
		case "S":
			sou__();
			break;
		}
	};
	</script>”、基址为file:///。
上代码。
