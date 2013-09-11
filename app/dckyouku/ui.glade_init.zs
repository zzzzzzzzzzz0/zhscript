赋予【主】纵变比以1。
赋予【主】橫变比以1。

赋予【主】webkit以webkit。
赋予id【主】以。
赋予主页以youku.com。
加载lib/defi。
加载lib/regexpr4。
加载lib/gjk4。

如果存在参数1那么赋予主页以‘参数1’。
如果调用‘头匹配方法’、‘主页’、http://否则
	赋予主页以http://‘主页’。
显示‘主页’↙。

定义捕获播放器【主】以下代码
	隧道‘webkit’、加强、浏览器。
	隧道‘webkit’、插脚、“
		var e=document.embeds;
		var max,max1=0,maxp,maxi;
		var ad = /ad/i;
		if(e.length==0){
			e=document.getElementsByTagName("embed");
			if(e.length==0){
				e=document.getElementsByTagName("object");
			}
		}
		z$("","数目"+e.length);
		for(var i=0;i<e.length;i++){
			var p2=e[i];
			var p=p2.parentNode;
			if(p.tagName=='OBJECT'){
				p2=p;
				p=p.parentNode;
			}
			
			var w=p2.offsetWidth,h=p2.offsetHeight;
			if(!w)
				w=p.offsetWidth;
			if(!h)
				h=p.offsetHeight;
			
			var id=p2.id;
			z$("",i+")"
				+" "+p2.tagName
				+" "+w+"x"+h+" "+p2.offsetLeft+","+p2.offsetTop
				+" "+id
				+" "+p.tagName
				+" "+p.offsetWidth+"x"+p.offsetHeight+" "+p.offsetLeft+","+p.offsetTop
				+" "+p.id
				);
			if(id){
				var is_id=(id=="‘id’");
				if(!ad.test(id)&&w<h*3||is_id){
					var wh=w*h;
					if(wh>max1||is_id){
						p2.width=p.offsetWidth*‘橫变比’;
						p2.height=p.offsetHeight*‘纵变比’;
						max1=wh;
						max=p2;
						maxp=p;
						maxi=i;
					}
				}
			}
		}
		if(max1>0){
			for(var i=0;i<e.length;i++){
				var p2=e[i];
				var p=p2.parentNode;
				if(p.tagName=='OBJECT'){
					p2=p;
					p=p.parentNode;
				}
				if(p2!=max)
					p.innerHTML="";
			}

			var p2=max;
			var w=p2.offsetWidth,h=p2.offsetHeight;
			var h1=20;
			var x=maxp.offsetLeft,y=maxp.offsetTop-h1;
			if(x<0)
				x=0;
			if(y<0)
				y=0;
			z$("","中"+maxi);

			var n='ctlbar_';
			var d=document.getElementById(n);
			if (!d) {
				d = document.createElement('div');
				d.id = n;
				d.align = 'left';
				with (d.style) {
					position = 'absolute';
					left = x + 'px';
					top = y + 'px';
					backgroundColor='#fff';
					whiteSpace="nowrap";
					zIndex="10000";
				}
				var p3 = document.getElementsByTagName('body')[0];
				p3.appendChild(d);
			}
			var a=["1:1","3/4","2/3","1/2","1/3","1/4"];
			var s='';
			for(var i=0;i<a.length;i++){
				if(i>0)
					s+=' ';
				var ai=i==0?'1':a[i];
				var b=ai=='‘纵变比’';
				if(b)
					s+='[';
				s+='<a href="zhscript:'+ai+'"><span style="color:#000;font-size:12px;">'+a[i]+'</span></a>';
				if(b)
					s+=']';
			}
			d.innerHTML = s;

			z$("中",x,y,w,h+h1,max.id,maxp.id);
		}
		document.title=t;
	”、浏览器。
上代码。

隧道‘webkit’、浏览器、scrolledwindow1、
	代码为下代码
		显示‘肇事者’--‘动作’--‘参数’↙。
	上代码、
	侦听为标题改变为下代码
		隧道标题、‘参数1’。
	上代码、
	侦听为zhscript:为下代码
		显示‘参数0’‘参数’↙。
		别名数据以参数1。
		如果‘数据’等于1或者调用‘正则配’、‘数据’、^[0-9]+/[0-9]+$、el那么先
			赋予【主】纵变比以
			赋予【主】橫变比以‘数据’。
			隧道‘webkit’、刷新、浏览器。
			退出。
		了。
	上代码、
	侦听为z$为下代码
		当‘参数1’先
			等于中那么先
				显示‘参数’↙。
				隧道窗口取消最大化。
				隧道窗口宽高、100、100。
				赋予橫条宽以隧道高、scrolledwindow1、横滚动条。
				赋予竖条宽以隧道宽、scrolledwindow1、竖滚动条。
				别名x以参数2。
				别名y以参数3。
				别名宽以参数4。
				别名高以参数5。
				赋予id【主】以‘参数6’。
				赋予上id【主】以‘参数7’。
				赋予宽以算术‘宽’+‘竖条宽’。
				赋予高以算术‘高’+‘橫条宽’。
				隧道窗口宽高、‘宽’、‘高’。
				隧道移动、scrolledwindow1、‘x’、‘y’。
				退出。
			了。
		了。
		显示‘参数栈2’↙。
	上代码、
	侦听为装载完毕为下代码
		显示‘参数0’--‘参数’↙。
		隧道一次定时器、“捕获播放器”、1s、“捕获播放器”。
	上代码。
隧道‘webkit’、访问、‘主页’、浏览器。

隧道代码为下代码
	显示‘肇事者’--‘动作’--‘参数’↙。
	如果‘肇事者’等于窗口并且‘动作’等于状态改变那么先
		当‘参数1’先
			等于4那么隧道取消置顶，跳出。
			等于0那么隧道置顶，跳出。
		了。
	了。
上代码。
隧道窗口最大化。
