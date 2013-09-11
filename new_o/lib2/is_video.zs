赋予“库名”以“【库】‘参数0’”。
如果存在‘库名’那么退出。
赋予‘库名’以。

加载lib/gjke4。
加载lib/redireconsoi4。
加载lib/gjk4。
加载lib/regexpr4。

新建数组“视频标示【顶】”为“1”、
“MPEG ”、
“RIFF \(little-endian\) data”、
“Microsoft ASF”、
“RealMedia file”、
“Ogg-Vorbis compressed sound file”、“Ogg data,”、
“Macromedia Flash Video”、
“Matroska data”、“EBML file, creator matroska”、
“WebM$”、
“ISO Media,”、“^ISO Media$”。

定义“是视频【顶】”以下代码
	别名“路径”以“参数1”。
	赋予“类型”以调用‘重定向输出’、“file -L "‘路径’"”。
	赋予“类型”以调用‘子串方法’、‘类型’、“2”、“0”、‘路径’。
	赋予“号”以“0”。
	循环先
		赋予“号”以算术“‘号’+1”。
		别名“标示”以“视频标示之‘号’【顶】”。
		如果不存在“标示”那么跳出。
		如果调用‘正则配’、‘类型’、‘标示’、“l”那么“1”，退出。
	了。
上代码。
