加载lib/defi。
加载lib/gjk4。
加载lib/file4。
赋予上一次文件【主】以。

赋予号以1。
循环先
	如果不隧道有、scrolledwindow‘号’那么跳出。
	隧道源码框、‘号’、scrolledwindow‘号’。
	隧道提示文字、save‘号’、保存。
	隧道侦听、点击、save‘号’、下代码
		赋予文件以隧道窗口标题、window上代码‘号’下代码。
		如果‘文件’等于-那么退出。
		隧道源码框、保存文件、上代码‘号’下代码、‘文件’。
	上代码。
	隧道窗口标题、window‘号’、-。
	赋予号以算术‘号’+1。
了。

隧道提示文字、open、打开。
隧道侦听、点击、open、下代码
	赋予文件以隧道文件选择为打开、‘参数1’、预选为‘上一次文件’。
	如果不‘文件’那么
		退出。
	打开文件‘文件’。
上代码。

定义打开文件【主】以下代码
	别名文件以参数1。

	赋予号以1。
	范围先
		循环先
			如果不隧道有、window‘号’那么跳出。
			如果隧道窗口标题、window‘号’等于-或者不隧道可见、window‘号’那么遁出。
			赋予号以算术‘号’+1。
		了。
		隧道提示、已无窗口可用建议保存关闭一个。
		退出。
	了。
	
	隧道可见、window‘号’、1。
	隧道窗口标题、window‘号’、‘文件’。
	赋予上一次文件【主】以‘文件’。
	赋予语言以调用‘小写方法’、先调用‘子串方法’、先调用‘得扩展名’、‘文件’了、1了。
	当‘语言’先
		等于py那么赋予语言以python，跳出。
		等于glade那么赋予语言以xml，跳出。
		等于“”那么赋予语言以sh，跳出。
	了。
	隧道源码框、语法高亮、‘号’、‘语言’。
	隧道源码框、“打开文件”、‘号’、‘文件’。
上代码。
（
ada awk 
boo 
c c-sharp changelog chdr cpp css 
d def desktop diff docbook dot dpatch dtd 
eiffel erlang 
forth fortran 
gap gettext-translation gtk-doc gtkrc 
haddock haskell haskell-literate html 
idl ini 
java js 
latex libtool lua 
m4 makefile msil 
nemerle 
objc objective-caml ocl octave 
pascal perl php pkgconfig python 
r rpmspec ruby 
scheme sh sql 
tcl texinfo 
vala vbnet verilog vhdl 
xml xslt 
yacc）

隧道提示文字、clear、清除。
隧道侦听、点击、clear、下代码
	隧道源码框、内容、1、。
	隧道标题为-。
上代码。

如果存在参数1那么
	隧道一次定时器、、100、下代码
		打开文件‘参数1’
	上代码、‘参数1’。