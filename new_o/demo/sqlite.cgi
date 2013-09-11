#!/usr/bin/zhscript --。
加载lib/defi。
显示“content-type: text/html; charset=utf-8”←↙←↙。

加载lib/sqlite4。
赋予库以调用‘打开’、/tmp/post.sqlite。
调用‘执行’、‘库’、“CREATE TABLE IF NOT EXISTS post__(
	id_ INTEGER PRIMARY KEY AUTOINCREMENT,
	title_ TEXT,
	text_ TEXT,
	time_ DATETIME DEFAULT CURRENT_TIMESTAMP
);”。

加载lib/stdc。
赋予长以调用‘得环境变量函数’、CONTENT_LENGTH。
如果‘长’那么先
        加载lib/doscmd4。
        赋予入以调用‘type’、-e、‘长’、-。
        加载lib/regexpr4。
        加载lib/file4。
		迭代正则‘入’、&?([^=]+)=([^&]*)、下代码
			赋予‘参数1’【上】以调用‘正则替’、先调用‘urldecode’、‘参数2’了、(')、''。
		上代码。
		调用‘执行’、‘库’、“INSERT INTO post__(title_,text_)VALUES('‘title’','‘text’');”。
        调用‘关闭’、‘库’。
        显示<script>window.location.href="?"</script>。
        结束。
了。

显示“
<form method=post>
<textarea name=title></textarea><br>
<textarea name=text></textarea><br>
<input type=submit>
</form>
<pre>”↙。
调用‘得表’、下代码
	显示(‘参数1’)‘参数4’↙‘参数2’↙‘参数3’↙。
上代码、‘库’、“SELECT * FROM post__ ORDER BY id_ DESC”、0。
显示</pre>↙。
调用‘关闭’、‘库’。
