加载lib/gjks4。

赋予电影目录【主】以调用‘新建列表’。
赋予海报目录【主】以调用‘新建列表’。

定义遍历电影目录【主】以下代码
	加载lib/doscmd4。
	加载lib2/is_video.zs。
	加载lib/file4。
	调用‘入列表’、‘海报目录’、3、-、b、。
	调用‘遍历列表’、‘电影目录’、下代码
		别名目录以参数1。
		赋予搜以调用‘dir.begin’、‘目录’、、s。
		调用‘排序列表行’、先调用‘dir.list’、‘搜’了、0。
		循环先
			使不堵塞。
			赋予名以调用‘dir.next’、‘搜’。
			如果‘名’等于那么跳出。
			如果调用‘尾匹配方法’、‘名’、.m3u那么再来。
			如果调用‘尾匹配方法’、‘名’、.sub那么再来。
			赋予路径以‘目录’/‘名’。
			如果不是视频‘路径’那么再来。

			赋予目录2以调用‘得目录名’、‘路径’。
			赋予名2以先调用‘正则格’、先调用‘得文件主名’、‘名’了、([^.]*)了。
			赋予标题以调用‘省略名’、‘名’、x、/-、_。
			赋予子目录以调用‘得目录名’、‘名’。
			
			赋予图式以^先调用‘加反斜杠’、‘名2’、R了\..*(png|jpg|jpeg)$。
			赋予搜图以调用‘dir.begin’、‘目录2’、‘图式’、l。
			赋予缩略图以调用‘dir.next’、‘搜图’。
			调用‘dir.end’、‘搜图’。
			范围先
				如果‘缩略图’那么
					赋予缩略图以‘目录2’‘缩略图’，遁出。
				迭代解释下代码
					赋予文件以‘参数1’/.cache/movbrow_zs/‘标题’.png。
					如果调用‘exist’、‘文件’那么
						赋予缩略图【上】以‘文件’，遁出。
				上代码、‘参数栈【上】’。
				赋予缩略图以‘无图’。
			了。

			赋予主干以‘目录2’‘名2’。
			赋予zs以‘主干’.zs-note。
			如果调用‘exist’、‘zs’那么加载‘zs’。
			
			调用‘入列表’、‘海报目录’、4、‘路径’、‘标题’、‘缩略图’、‘主干’。
		了。
		调用‘dir.end’、‘搜’。
	上代码。
	调用‘入列表’、‘海报目录’、3、-、e、。
上代码。

定义得海报信息【主】以下代码
	别名号以参数1。
	赋予视频【上】以调用‘得列表单元’、‘海报目录’、‘号’,1。
	赋予标题【上】以调用‘得列表单元’、‘海报目录’、‘号’,2。
	赋予封面【上】以调用‘得列表单元’、‘海报目录’、‘号’,3。
	赋予主干【上】以调用‘得列表单元’、‘海报目录’、‘号’,4。
上代码。

定义形成内容【主】以下代码
	别名宽以参数1。
	别名窗宽以参数2。
	赋予最大以算术‘宽’+20。
	赋予最小以算术‘宽’-20。
	赋予列以5。
	循环先
		赋予封面宽【主】以算术(‘窗宽’-40-(‘列’-1)*20)/‘列’、0。
		如果‘封面宽’大于‘最大’那么先
			赋予列以算术‘列’+1。
			再来。
		了。
		如果‘封面宽’小于‘最小’那么先
			赋予列以算术‘列’-1。
			再来。
		了。
		跳出。
	了。
	
	赋予内容【上】以“
	<style>
	img{
		max-width:‘封面宽’px;
		max-height:‘封面宽’px;
	}
	.img{
		width:‘封面宽’px;
		height:‘封面宽’px;
		vertical-align:middle;
		display:table-cell;
		word-break:break-all;
	}
	body{
		font-size:12px;
	}
	.fengmian{
		float:left;
		padding:8px;
		text-align:center;
		border: 1px solid #DEDEDE;
	}
	.title{
		width:‘封面宽’px;
		white-space:nowrap;
		overflow:hidden;
		text-overflow:ellipsis;
	}
	</style>
	<script>
	function time__() {
		var d = new Date();
		return d.getMinutes() * 100 + d.getSeconds();
	}
	var over_ = 0;
	function over__() {
		over_ = time__();
	}
	</script>”。
上代码。

定义获取info【主】以下代码
	别名视频以参数1。
	如果存在‘视频’长度【主】那么退出。
	
	加载lib/redireconsoi4。
	加载lib/regexpr4。
	赋予‘视频’信息【主】以调用‘重定向输出’、“mplayer -identify "‘视频’" -nosound -vc dummy -vo null”。
	赋予‘视频’长度【主】以调用‘regexpr’、‘‘视频’信息’、ID_LENGTH=([0-9.]+)。
	赋予‘视频’宽度【主】以调用‘regexpr’、‘‘视频’信息’、ID_VIDEO_WIDTH=([0-9]+)。
	赋予‘视频’高度【主】以调用‘regexpr’、‘‘视频’信息’、ID_VIDEO_HEIGHT=([0-9]+)。
上代码。
