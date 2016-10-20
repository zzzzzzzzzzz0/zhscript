#!../webkitsh --。
加载set.zs。

使主窗、侦听、
	创建为下代码
		使主窗、大小、500、500。
		使主窗、居中。
		使主窗、内容、
		“<style>
		iframe {
			width:495px; height:155px;
			position:absolute; left:0px; top:340px;
			display:none;
		}
		</style>
		<iframe></iframe>
		<table border=1 width=100% height=100%>
		<tr><td align=center><img src="‘图标’"></td><td>‘大标题’</td></tr>
		<tr><td>作者</td><td>zzzzzzzzzzz</td></tr>
		<tr><td>感谢</td><td id=n>互联网<br><br>开源项目</td></tr>
		</table>
		<script>
		var e = document.getElementsByTagName("td");
		for(var i = 0; i < e.length; i++) {
			var ei = e[i];
			if(ei.id == "n") {
				ei.title = "点击将搜索 zhscript";
				ei.onclick = function() {
					var if0 = document.getElementsByTagName("iframe")[0];
					if0.style.display = "inline";
					if0.src = 'https://www.baidu.com/s?wd="zhscript"';
				};
			} else {
				ei.onclick = function() {z$("结束")};
			}
		}
		</script>”。
	上代码。
使主窗、创建、弹出窗。

（使代码为下代码
	显示‘参数0’--‘参数’ 字符10。
上代码。）
