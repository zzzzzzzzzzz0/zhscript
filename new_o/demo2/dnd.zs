#!../gtkmmsh lib2/window1.glade --。
隧道窗口宽高、600、300。隧道窗口居中。隧道置顶。隧道标题为‘参数0’。

隧道可见、info、_2、line、exec2、1。

隧道提示文字、info、可拖至。
隧道拖放、目标、info、代码为下代码
	隧道提示为‘参数’。
上代码、复制、移动、链接、高亮、按钮。

隧道拖放、目标、line、代码为下代码
	隧道内容、line、‘参数1’。
上代码、复制、高亮。

隧道提示文字、exec、给文本域加拖放。
隧道侦听、点击、exec、下代码
	隧道拖放、目标、text、代码为下代码
		隧道插入、text、‘参数’字符10、头。
	上代码、复制。
上代码。

隧道提示文字、exec2、给文本域去拖放。
隧道侦听、点击、exec2、“隧道拖放、移除、text。”。
