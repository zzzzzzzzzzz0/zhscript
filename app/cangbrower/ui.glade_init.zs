加载lib/defi。

赋予目录以。
赋予rand以checked。
加载lib/clpars4。
赋予-tmp【主】以/tmp。
调用‘命令行加回调’、
	-s | --start、、0、下代码
		隧道一次定时器、‘参数0’、2s、下代码
			显示‘参数0’↙。
			隧道‘webkit’、插脚、click__('start');、浏览器#0。
		上代码。
	上代码、
	-1、、0、下代码
		赋予rand【上】以。
	上代码、
	-fm | --fibmenu、、2、下代码
		赋予fib-menu【主】以‘参数1’。
		赋予fib-menu-a2【主】以‘参数2’。
	上代码、
	-l、、6、下代码
		别名x以参数1。
		别名y以参数2。
		别名w以参数3。
		别名w+以参数4。
		别名h以参数5。
		别名h+以参数6。
		如果‘w’等于sh那么赋予w以隧道屏幕高。
		如果‘h’等于sh那么赋予h以隧道屏幕高。
		加载lib/gjk4。
		赋予w以算术‘w’+‘w+’。
		赋予h以算术‘h’+‘h+’。
		如果‘x’等于w那么赋予x以‘w’。
		赋予定制窗口代码【主】以“隧道移动、‘x’、‘y’。隧道窗口宽高、‘w’、‘h’。”。
	上代码、
	-tmp、、1、下代码
		赋予‘参数0’【主】以‘参数1’。
	上代码、
	、、1、下代码
		赋予【上】目录以‘目录’‘参数1’↙。
	上代码、
	-h | --help、、0、下代码
		显示调用‘命令行帮助’。
		隧道终止。
		结束。
	上代码。
调用‘命令行解析’、‘参数栈’。
加载lib/clpars4-。

如果存在定制窗口代码那么
	解释‘定制窗口代码’。
否则
	隧道窗口最大化。
加载lib/gjke4。
加载lib2/js.zs。
赋予【主】webkit以webkit3。

定义【主】“执行动作”以“隧道‘webkit’、插脚、window.location.href="zhscript:"+‘参数1’;、浏览器#0。”。

定义【主】“显示图片”以“
	显示‘图片号’/‘图片量’↙。
	执行动作"file://"+list_[‘图片号’]。
”。

定义【主】【无参】这里是图片名以“
	赋予文件以隧道‘webkit’、标签提示、浏览器。
	加载lib/gjk4。
	显示‘文件’→。
	如果调用‘头匹配方法’、‘文件’、file://那么
		赋予文件以调用‘urldecode’、先调用‘子串方法’、‘文件’、7了。
	显示‘文件’↙。
	‘文件’
”。

定义【主】加控制条以“
	隧道‘webkit’、插脚、“‘js函数集’
		var n='ctlbar_';
		var d=__(n);
		if (!d) {
			d = document.createElement('div');
			d.id = n;
			d.align = 'left';
			with (d.style) {
				position = 'fixed';
				right = '2px';
				/*bottom*/top = '10px';
				/*zIndex=1;
				backgroundColor='#FFF';
				border='1px dashed #000';*/
			}
			d.innerHTML = "
				<a href='zhscript:prev'><img src='file:///usr/share/icons/gnome/32x32/actions/go-previous.png' title='上一张(b)'></a><br>
				<a href='zhscript:next'><img src='file:///usr/share/icons/gnome/32x32/actions/go-next.png' title='下一张(n)'></a><br>
				<a href='zhscript:rand'><img src='file:///usr/share/icons/gnome/32x32/actions/go-jump.png' title='随机一张(r)'></a><br>
				<a href='zhscript:refresh'><img src='file:///usr/share/icons/gnome/32x32/actions/view-refresh.png' title='刷新(f)'></a><br>
				<a href='zhscript:gb18030'><img src='file:///usr/share/icons/gnome/32x32/actions/format-text-underline.png' title='gb18030'></a><br>
				<a href='zhscript:utf8'><img src='file:///usr/share/icons/gnome/32x32/actions/format-text-underline.png' title='utf8'></a><br>
				<a href='zhscript:edit'><img src='file:///usr/share/icons/gnome/32x32/actions/document-send.png' title='编辑(e)'></a><br>”
				先如果存在fib-menu那么
				“<a href='zhscript:fib-menu'><img src='file:///usr/share/icons/gnome/32x32/actions/document-send.png' title='fib-menu'></a><br>”
				了
				“<br>
				<a href='zhscript:del'><img src='file:///usr/share/icons/gnome/32x32/actions/edit-delete.png' title='删除(x)'></a><br>
				";
			var p3=tag__('body')[0];
			p3.appendChild(d);
			/*d.onmouseover="this.style.opacity=1;";
			d.onmouseout="this.style.opacity=0;";
			setTimeout("__('"+n+"').style.opacity=0;",500);*/
			document.onkeypress=function(event){
				var c=String.fromCharCode(event.charCode);
				switch(c){
				case'b':
					window.location.href="zhscript:prev";
					break;
				case'n':
					window.location.href="zhscript:next";
					break;
				case'r':
					window.location.href="zhscript:rand";
					break;
				case'f':
					window.location.href="zhscript:refresh";
					break;
				case'e':
					window.location.href="zhscript:edit";
					break;
				case'x':
					window.location.href="zhscript:del";
					break;
				case'q':
					window.location.href="zhscript:quit";
					break;
				}
			}
		}
	”、浏览器。
”。

定义图片被删【主】以下代码
	赋予【主】图片量以算术‘图片量’-1。
	隧道‘webkit’、插脚、list_.splice(‘图片号’,1);、浏览器#0。
上代码。

隧道‘webkit’、浏览器、notebook1、
	侦听为zhscript:为下代码
		显示‘参数0’‘参数’↙。
		别名参以参数1。
		加载lib/regexpr4。
		如果调用‘正则攫’、‘参’、^\?(.+)、、el那么先
			如果调用‘正则攫’、‘之1’、&?([^=]+)=([^&]+)、参那么先
				赋予【主】第一张方式以next。
				迭代数组下代码
					显示‘参数’↙。
					当‘参数1’先
						等于rand那么先
							赋予【主】第一张方式以‘参数1’。
							跳出。
						了。
						等于box_那么先
							赋予列表以调用‘正则替’、‘参数2’、(%0D%0A)、→。
							如果调用‘正则攫’、‘列表’、([^→]+)→?那么先
								隧道‘webkit’、插脚、list_.length=0;window.open("about:blank","_blank");、浏览器#0。
								隧道敏感、notebook1、0。
								隧道不堵塞。
								加载lib/file4。
								加载lib/doscmd4。
								序迭代数组下代码
									赋予目录以调用‘urldecode’、‘参数2’。
									显示‘参数’→‘目录’↙。
									如果调用‘existdir’、‘目录’那么先
										赋予搜以调用‘dir.begin’、‘目录’、、so0。
										循环先
											赋予名以调用‘dir.next’、‘搜’。
											如果‘名’等于“”那么跳出。
											隧道‘webkit’、插脚、list_.push("‘目录’/‘名’");、浏览器#0。
										了。
										调用‘dir.end’、‘搜’。
									了否则如果调用‘exist’、‘目录’那么
										隧道‘webkit’、插脚、list_.push("‘目录’");、浏览器#0。
								上代码、。
								执行动作"len="+list_.length。
							了。
							跳出。
						了。
					了。
				上代码、参。
			了。
			退出。
		了。
		如果调用‘正则攫’、‘参’、^len=(.+)、、el那么先
			赋予【主】图片量以‘之1’。
			如果‘图片量’小于等于0那么先
				隧道‘webkit’、插脚、document.write("无")、浏览器。
				隧道敏感、notebook1、1。
				退出。
			了。
			赋予【主】图片号以-1。
			执行动作"‘第一张方式’"。
			退出。
		了。
		
		如果隧道内容、notebook1等于1那么退出。
		当‘参’先
			等于next或者等于prev或者等于rand或者等于refresh那么先
				如果‘参’等于next或者等于prev或者等于rand那么
					赋予上一次动作【主】以‘参’。
				加载lib/gjk4。
				赋予【主】图片号以算术先
					当‘参’先
						等于rand那么先
							赋予1以调用‘随机数方法’、0。
							调用‘随机数方法’、‘图片量’。
							跳出。
						了。
						那么先
							‘图片号’。
							当‘参’先
								等于next那么+1，跳出。
								等于prev那么-1，跳出。
							了。
						了。
					了。
				了。
				如果‘图片号’大于等于‘图片量’那么
					赋予【主】图片号以0。
				如果‘图片号’小于0那么
					赋予【主】图片号以算术‘图片量’-1。
				显示图片。
				退出。
			了。
			等于del那么先
				如果‘图片量’大于0那么先
					执行显示“mv '”这里是图片名“' ‘-tmp’”↙。
					图片被删。
					执行动作"refresh"。
				了。
				退出。
			了。
			等于edit那么先
				赋予文件以这里是图片名。
				显示‘文件’↙。
				加载lib/filetype。
				赋予类型以文件类型‘文件’。
				赋予命令以先
					当‘类型’先
						等于p/jpg或者等于p/png或者等于p/gif那么
							gimp，跳出。
						等于p/flv那么
							mplayer，跳出。
						那么
							gedit，跳出。
					了
				了“ '‘文件’' &”。
				显示‘类型’↙。
				执行显示‘命令’↙。
				退出。
			了。
			等于fib-menu那么先
				赋予回以加载‘fib-menu’、这里是图片名、‘fib-menu-a2’。
				显示‘回’↙。
				如果‘回’等于0那么退出。
				如果‘回’等于1那么先
					图片被删。
					执行动作"refresh"。
					退出。
				了。
				如果调用‘头匹配方法’、‘回’、:那么先
					隧道提示、‘回’。
					退出。
				了。
				隧道‘webkit’、插脚、list_[‘图片号’]="‘回’";、浏览器#0。
				执行动作"‘上一次动作’"。
				退出。
			了。
			等于gb18030或者等于utf8那么先
				赋予文件以这里是图片名。
				加载lib/txtotxt4。
				隧道‘webkit’、内容、先调用‘iconv’、先调用‘html2text’、‘文件’、1、1了、‘参’了、file:///、浏览器。
				隧道标题、‘参’:。
				隧道一次定时器、“加控制条”、500、下代码
					隧道‘webkit’、标签提示、“上代码‘文件’下代码”、浏览器。
					加控制条。
				上代码。
				退出。
			了。
		了。
		如果调用‘正则攫’、‘参’、^(file:.+)、、el那么先
			隧道‘webkit’、访问、‘之1’、浏览器。
			退出。
		了。
		如果‘参’等于quit那么结束。
	上代码、
	侦听、装载完毕、下代码
		显示‘参数0’--‘参数’↙。
		别名网址以参数1。
		隧道‘webkit’、标签提示、‘网址’、浏览器。
		如果‘网址’等于file:///那么退出。
		
		如果隧道内容、notebook1等于1那么退出。
		如果‘网址’等于about:blank那么先
			隧道‘webkit’、插脚、document.write("请等候……")、浏览器。
			退出。
		了。
		加控制条。
		赋予标签以‘图片号’/‘图片量’。
		赋予标签以调用‘正则替’、‘标签’、(.)、$1↙。
		隧道‘webkit’、标签、“<span font_desc='6'>‘标签’</span>”、浏览器。
		隧道敏感、notebook1、1。
		隧道‘webkit’、焦点、浏览器。
	上代码、
	侦听、标签页切换、下代码
		赋予标题以隧道‘webkit’、标题提示、浏览器。
		如果‘标题’那么
			隧道标题、‘标题’。
	上代码、
	侦听为标题改变为下代码
		隧道标题、‘参数1’。
	上代码。

隧道‘webkit’、内容、“<html>
<head>
<title>首页</title>
<style>
#box_{width:100%;height:50%;}
#table1_{width:100%;height:100%;}
</style>
<script>
‘js函数集’
var list_=new Array();
</script>
</head>
<body>
<form  action="zhscript:">
<input type=submit value=开始 id=start>显示文件夹和文件（<input type=checkbox name=rand ‘rand’>第一张随机）<br>
<textarea name=box_ id=box_>‘目录’</textarea>
</form>
</body>
</html>”、file:///、浏览器。
