赋予“库名”以“【库】‘参数0’”。
如果存在‘库名’那么退出。
赋予‘库名’以。

加载“lib/gjks4”。
加载“lib/magic4”。
加载“lib/regexpr4”。

赋予“图片标示【顶】”以调用‘新建列表’。
调用‘入列表’、‘图片标示【顶】’、“2”、
“jpg”、“JPEG image data,”、
“png”、“PNG image data,”、
“gif”、“GIF image data,”、
“bmp”、“PC bitmap,”。

定义“是图片【顶】”以下代码
	别名“路径”以“参数1”。
	赋予“类型”以调用‘得文件类型方法’、‘路径’。
	赋予“果”以。
	调用‘遍历列表’、‘图片标示【顶】’、下代码
		如果调用‘正则配’、‘类型’、‘参数2’、“l”那么先
			赋予“果【上】”以‘参数1’。
			跳出。
		了。
	上代码。
	‘果’
上代码。
