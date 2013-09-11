加载lib/defi。
加载lib2/js.zs。
加载lib/regexpr4。
加载lib/gjk4。
加载lib/gjke4。
加载lib/file4。
加载lib/doscmd4。

赋予首页【主】以http://weibo.com/。

赋予配置文件【主】以先调用‘得环境变量方法’、HOME了/.config/weibo2_zs/setting.zs。
如果调用‘exist’、‘配置文件’那么
	加载‘配置文件’。
如果存在参数1那么
	赋予帐号【主】以‘参数1’。
赋予应用目录【主】以调用‘得目录名’、先调用‘最终文件名’、‘参数0’了。

使主窗为创建为标签页。
使主窗为侦听为
	创建为下代码
		使主窗为标题为weibo桌面端。
		使主窗为大小为990、640。
		使主窗为居中。
		使主窗为图标为‘应用目录’/weibo.png。
		使主窗为访问为‘首页’。
	上代码、
	标题改变为下代码
		别名标题以参数1。
		使主窗为标题为‘标题’。
	上代码、
	标签页切换为下代码
		使主窗#‘参数1’为插脚为下代码
			z$("使主窗为标题为‘参数1’",document.title);
		上代码。
	上代码、
	装载完毕为下代码
		别名网址以参数1。
		当‘网址’先
			等于‘首页’那么先
				如果存在帐号那么
					插一脚	val__("name","‘帐号’")。
				如果存在‘帐号’那么
					插一脚	val__("pass","先调用‘urldecode’、‘‘帐号’’、weibo了");
							click__("W_btn_d")。
				退出。
			了。
			等于about:blank那么先
				插一脚下代码
					if(__("pass")){
						z$("
							别名帐号以参数1。
							别名密码以参数2。
							赋予密码以调用‘urlencode’、‘密码’、weibo。
							如果
							不存在帐号【主】
							或者
							‘帐号【主】’不等于‘帐号’
							或者
							不存在‘帐号【主】’
							或者
							‘‘帐号【主】’’不等于‘密码’
							那么先
								赋予帐号【主】以‘帐号’。赋予‘帐号’【主】以‘密码’。
								调用‘echo’、“赋予帐号【主】以‘帐号’。”、‘配置文件’。
								遍历变量名下代码
									别名名以参数1。
									别名注以参数2。
									如果调用‘正则配’、‘名’、^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$那么先
										赋予帐号以‘名’‘注’。
										显示‘帐号’换行。
										调用‘echo’、-ma、换行“赋予‘帐号’以‘‘帐号’’。”、‘配置文件’。
									了。
								上代码、‘回调1【主】’、1。
							了。
						",val__("name"),val__("pass"));
					}
				上代码。
				退出。
			了。
		了。
	上代码、
	请求为下代码
		显示‘参数0’--‘参数’换行。
		别名网址以参数1。
		如果调用‘正则配’为‘网址’、/remind/unread_count\.json\?
		或者调用‘正则配’为‘网址’、/remind/push_count\.json\?
		那么先
			如果使主窗为活动并且使主窗为标签号等于1那么退出。
	
			插一脚‘js函数集2’‘js公共变量’下代码
				for(;;){
					var b=false;
					var a=new Array('notes','layer_message_box','feed_msg_new','small_Yellow');
					for(var i=0;i<a.length;i++){
						var ai=a[i];
						var e1=__(ai);
						if(e1 && e1.style.display!='none'){
							z$("",ai);
							if(i<=0)
								z$("使主窗#1为刷新");
							else{
								z$("弹出提示‘参数栈’",get_lnk__()+e1.outerHTML);
							}
							b=true;
							break;
						}
					}
					if(b)
						break;
					b=false;
					for(var clsname_i=0;clsname_i<listclsname_.length && !b;clsname_i++){
						var clsname=listclsname_[clsname_i];
						var ul=cls__(clsname);
						if(ul && ul.length>0){
							z$("",clsname,"=",ul.length);
							for(var i=0;i<ul.length && !b;i++){
								var li=ul[i].childNodes;
								for(var i1=0;i1<li.length && !b;i1++){
									var e1=li[i1];
									var htm;
									switch(clsname_i){
									case 0:
									case 2:
										if(e1.tagName!="DL")
											continue;
										htm=e__(e1,3).innerText;
										break;
									case 1:
										if(e1.tagName!="DIV")
											continue;
										e1=e__(e1,1);
										if(e1.tagName!="DL")
											continue;
										htm=e1.innerText;
										break;
									}
									htm=htm.replace(/ /g,"").replace(/\n/g,"").replace(/\t/g,"")
										.replace(/收起\|查看大图\|向左转\|向右转/g,"")
										.replace(/[0-9]+(分钟|秒)前来自/g,"")
										;
									if(!z$("如果存在“"+clsname+"”【主】那么true否则false") || z$("‘"+clsname+"【主】’")!=htm){
										z$("赋予“"+clsname+"”【主】以‘参数1’",htm);
										z$("",htm,"(EOL)");
										z$("弹出提示‘参数栈’",get_lnk__()+get_p_html__(e1,2,e1.outerHTML),clsname_i);
									}
									b=true;
								}
							}
							break;
						}
					}
					if(b)
						break;
					
					break;
				}
			上代码。
			退出。
		了。
	上代码、
	显现为下代码
		使主窗#1为不可关闭。
		使主窗#1为标签为“  ”。
		使主窗#1为加钮、
			名为首页、gtk-home、
			名为关于、gtk-about、
			-、
			名为后退、gtk-go-back、
			名为前进、gtk-go-forward、
			名为刷新、gtk-refresh。

		使提示窗为创建为弹出窗。
		使提示窗为侦听为
			新开为下代码
				使提示窗为隐藏。
				使主窗为激活。
			上代码。
		使提示窗为目标为主窗。
		使提示窗为大小为400、400。
		使提示窗为移动为-450、50。
		使提示窗为不透明度为0.85。
	上代码、
	点击为下代码
		别名参以参数1。
		别名标签以参数2。
		当‘参’先
			等于首页那么先
				使‘标签’为访问为‘‘参’’。
				使‘标签’为激活。
				退出。
			了。
			等于关于那么先
				使‘标签’为新开为‘应用目录’/ad.html。
				退出。
			了。
		了。
		使主窗为‘参’。
	上代码、
	（新开为下代码
		使主窗#-2为标签为...。
	上代码、）
	消息为下代码
		如果‘参数1’等于“event.layerX and event.layerY are broken and deprecated in WebKit. They will be removed from the engine in the near future.”那么退出。
		显示‘参数0’--‘参数’换行。
	上代码。

定义插一脚【主】以下代码
	使主窗#1为插脚为‘js函数集’‘参数1’。
上代码。

定义弹出提示【主】以下代码
	别名提示以参数1。
	别名clsname以参数2。
	赋予+以先如果存在延时关闭提示那么window.clearTimeout(‘延时关闭提示’);了“
		z$("赋予延时关闭提示【主】以"+window.setTimeout("z$('隐藏提示。删除延时关闭提示【主】')",30000));
		document.onclick=function(ev){
			var x=ev.pageX,y=ev.pageY;
			z$("","点(",x,",",y,")");
			if(x>50)
				z$('使主窗#1为激活');
			z$('隐藏提示');
		};
	”。
	如果存在clsname那么先
		赋予号以0。
		赋予提示以调用‘正则迭’、‘提示’、“(<)(a|img)( )”、下代码
			‘参数1’‘参数2’‘参数3’。
			当‘参数2’先
				等于a那么
					“onclick="" href="javascript:”，跳出。
				等于img那么
					“onclick="”，跳出。
			了。
			“z$('传击‘号’、‘clsname’')" ”。
			赋予号【上】以算术‘号’+1。
		上代码。
	了。
	使提示窗为内容为“<script>‘+’</script><base target="_blank">‘提示’”、基址为‘首页’。
	使提示窗为显现。
上代码。

定义隐藏提示【主】以下代码
	使提示窗为内容为、基址为‘首页’。
	使提示窗为隐藏。
上代码。

定义传击【主】以下代码
	显示‘参数0’--‘参数’换行。
	别名号以参数1。
	别名clsname_i以参数2。
	隐藏提示。
	使主窗#1为激活。
	插一脚‘js公共变量’“
		var i_;
		function get_a__(e){
			var e1=e.childNodes;
			for(var i1=0;i1<e1.length;i1++){
				var e2=e1[i1];
				if(e2.tagName=='A'||e2.tagName=='IMG'){
					if(i_++==‘号’)
						return e2;
				}
				e2=get_a__(e2);
				if(e2)
					return e2;
			}
		}
		var ul=cls__(listclsname_[‘clsname_i’]);
		if(ul){
			var b=false;
			for(var i=0;i<ul.length && !b;i++){
				var li=ul[i].childNodes;
				for(var i1=0;i1<li.length && !b;i1++){
					var e1=li[i1];
					switch(‘clsname_i’){
					case 0:
					case 2:
						if(e1.tagName!="DL")
							continue;
						break;
					case 1:
						if(e1.tagName!="DIV")
							continue;
						e1=e__(e1,1);
						if(e1.tagName!="DL")
							continue;
						break;
					}
					i_=0;
					var a=get_a__(e1);
					if(a){
						window.scrollTo(e1.offsetLeft,e1.offsetTop);
						me__('click',a);
						z$('','\t',a);
					}
					b=true;
				}
			}
		}
	”。
上代码。

赋予js公共变量【主】以“var listclsname_=new Array('feed_lists','private_lists','big_comment_list');”。

赋予js函数集2【主】以下代码
	function get_lnk__(){
		var htm="";
		var lnk=document.getElementsByTagName("link");
		for(var i=0;i<lnk.length;i++)
			htm+=lnk[i].outerHTML;
		return htm;
	}
	function get_p_html__(e1,p_max,htm){
		var p=e1;
		for(var i=0;i<p_max;i++){
			p=p.parentNode;
			if(!p)
				break;
			var att='';
			var att2=p.attributes;
			if(att2){
				for(var i2=0;i2<att2.length;i2++){
					var a=att2[i2];
					att+=' '+a.nodeName+'="'+a.nodeValue+'"';
				}
			}
			htm='<'+p.tagName+att+'>'+htm+'</'+p.tagName+'>';
		}
		return htm;
	}
上代码。
