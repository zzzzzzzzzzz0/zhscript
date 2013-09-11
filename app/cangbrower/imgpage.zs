加载lib/defi。
加载lib/clpars4。
加载lib/doscmd4。
加载lib2/js.zs。
加载lib/filetype。

赋予==以“ &nbsp; &nbsp; ”。
赋予img-onclick以。
赋予刷新按钮以。
赋予步以1。
赋予i2以0。
调用‘命令行加回调’、
	-i-c-r|-i-c-n|-i-c-s、、0、下代码
		如果‘步’等于1否则再来。
		赋予img-onclick【上】以onclick="javascript:先
			当‘参数0’先
				等于-i-c-s那么set_pic2，跳出。
				等于-i-c-n那么next，跳出。
				那么rand。
			了
		了__()"。
	上代码、
	-b-r、、0、下代码
		如果‘步’等于1否则再来。
		赋予刷新按钮【上】以“<a href='javascript:set_pic__()'>‘==’<img src='/icons/gnome/32x32/actions/view-refresh.png' title='刷新'>‘==’</a>”。
	上代码、
	、、1、下代码
		如果‘步’等于2否则再来。
		别名目录以参数1。
		赋予搜以调用‘dir.begin’、‘root’‘目录’、、so0。
		循环先
			赋予名以调用‘dir.next’、‘搜’。
			如果‘名’等于“”那么跳出。
			如果文件类型‘root’‘目录’/‘名’等于p/png或者等于p/gif或者等于p/jpg那么
				显示a_.push("‘目录’/‘名’");↙。
		了。
		调用‘dir.end’、‘搜’。
	上代码。
调用‘命令行解析’、‘参数栈2’。

（
div align='left' style="position:fixed;left:2px;top:10px;"
）
显示“
<img id=pic_ ‘img-onclick’>
<br>
<span id=ctlbar_>
‘刷新按钮’
<a href='javascript:first__()'>‘==’<img src='/icons/gnome/32x32/actions/go-first.png' title='第一张'>‘==’</a>
<a href='javascript:back__()'>‘==’<img src='/icons/gnome/32x32/actions/go-previous.png' title='上一张'>‘==’</a>
<a href='javascript:next__()'>‘==’<img src='/icons/gnome/32x32/actions/go-next.png' title='下一张'>‘==’</a>
<a href='javascript:rand__()'>‘==’<img src='/icons/gnome/32x32/actions/go-jump.png' title='随机一张'>‘==’</a>
<span><span id=num_></span>
<br>
<span id=nam_>等候……</span>
”↙。

显示“<script>‘js函数集’
var a_=new Array();
var i_=-1;
function set_pic__(){
	if(a_.length<1){
		return;
	}
	if(i_<0)
		i_=a_.length-1;
	if(i_>=a_.length)
		i_=0;
	__("pic_").src=a_[i_];
	htm__("num_",i_+"-"+a_.length);
	htm__("nam_",a_[i_]);
}
var i2_=‘i2’;
function set_pic2__(){
	if(i2_==0)
		i_=Math.floor(Math.random()*a_.length);
	else{
		i_+=i2_;
	}
	set_pic__();
}
function first__(){i_=0;set_pic__();}
function back__(){i2_=-1;set_pic2__();}
function next__(){i2_=1;set_pic2__();}
function rand__(){i2_=0;set_pic2__();}
”↙。

别名root以参数1。
赋予步以2。
调用‘命令行解析’、‘参数栈2’。

显示set_pic2__()</script>↙。
