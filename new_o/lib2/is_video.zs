赋予“库名”以“【库】‘参数0’”。
如果存在‘库名’那么退出。
赋予‘库名’以。

加载“lib/gjke4”。
加载“lib/gjk4”。
加载“lib/magic4”。
加载“lib/regexpr4”。

新建数组“视频标示【顶】”为“2”、
“mpg”、“MPEG ”、
“riff”、“RIFF \(little-endian\) data”、
“asf”、“Microsoft ASF”、
“rm”、“RealMedia file”、
“ogg”、“Ogg-Vorbis compressed sound file”、
“ogg”、“Ogg data,”、
“flv”、“Macromedia Flash Video”、
“mkv”、“Matroska data”、
“mkv”、“EBML file, creator matroska”、
“webm”、“WebM$”、
“mp4”、“ISO Media,”、
“mp4”、“^ISO Media$”。

定义“是视频【顶】”以下代码
	别名“路径”以“参数1”。
	赋予“类型”以调用‘得文件类型方法’、‘路径’。
	赋予“号”以“0”。
	循环先
		赋予“号”以算术“‘号’+1”。
		如果‘号’大于‘视频标示数目【顶】’那么跳出。
		如果调用‘正则配’、‘类型’、‘视频标示之‘号’之2【顶】’、“l”那么‘视频标示之‘号’之1【顶】’，退出。
	了。
上代码。
