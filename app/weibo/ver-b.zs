隧道窗口宽高为（992）1030、+0。

赋予私信页【主】以‘首页’messages。
赋予评论页【主】以‘首页’comment/inbox。（后面不能有?）

赋予首【主】以feed_lists。
赋予信【主】以private_lists。
赋予评【主】以big_comment_list。

赋予得类代码【主】以“
for(;;){
	var s;
	s="‘信’";
	ul=cls__(s);
	if(ul&&ul.length>0){
		z$("赋予类【主】以信");
		break;
	}
	s="‘评’";
	ul=cls__(s);
	if(ul&&ul.length>0){
		z$("赋予类【主】以评");
		break;
	}
	s="‘首’";
	ul=cls__(s);
	z$("赋予类【主】以首");
	break;
}
”。

赋予得信类代码【主】以“
{
	var d=cls__("‘信’");
	if(d){
		for(i2=0;i2<d.length;i2++){
			var d2=d[i2].childNodes;
			for(i3=0;i3<d2.length;i3++){
				var d3=d2[i3];
				var a=attr__(d3,"node-type");
				if(a=="messageList"){
					ul=d3.childNodes;
					break;
				}
			}
			if(ul)
				break;
		}
	}
}
”。

赋予得mid代码【主】以id=attr__(e1,"mid");。
赋予得mid2代码【主】以“
{
	a=e__(e1,1,0);
	if(!a)
		continue;
	var par=par__(attr__(a,"usercard"));
	id=par.id;
}
”。
赋予得cid代码【主】以“
{
	var e2=e__(e1,3,5,1,1,1);
	if(!e2)
		continue;
	var par=par__(attr__(e2,"action-data"));
	id=par.cid;
}
”。

定义“获取新消息”【主】以下代码
	赋予网址以隧道webkit、网址、#1。
	当先
		存在我的首页并且‘网址’等于‘我的首页’那么赋予类以首，跳出。
		存在我的首页2并且‘网址’等于‘我的首页2’那么赋予类以首，跳出。
		调用‘头匹配方法’、‘网址’、‘私信页’那么赋予类以信，跳出。
		调用‘头匹配方法’、‘网址’、‘评论页’那么赋予类以评，跳出。
		那么显示不刷‘网址’↙，退出。
	了。
	显示‘类’‘网址’先如果存在参数0【上】那么‘参数0【上】’了↙。
	如果‘类’等于首那么先
		赋予类【主】以。
		循环先
			插一脚“var ul;‘得类代码’”。
			如果不‘类【主】’那么	再来。
			赋予类以‘类【主】’。
			跳出。
		了。
		显示‘类’↙。
	了。
	隧道webkit、加强、#1。
	当‘类’先
		等于信那么先
			赋予id名以mid2。
			如果‘显示提示’那么
			插一脚‘js函数集2’“
				var ul,i2,i3;‘得‘类’类代码’
				if(ul){
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length;i1++){
							var e1=li[i1];
							var id,a;‘得‘id名’代码’
							var txt=e__(e1,1).innerText;
							var idname="‘id名’";
							var b1=z$("a-e",idname,id),b2=false;
							if(b1)
								b2=(z$("a-g",idname,id)!=txt);
							if(!b1||b2){
								z$("a-s",idname,id,txt);
								z$("f","弹出提示",get_msg__(e1,1),id,idname);
							}
						}
					}
				}
			”。
			如果存在搞飞机那么
			插一脚‘js函数集2’“
				var ul,i2,i3;‘得‘类’类代码’
				if(ul){
					var z='zhscript:get_msg__(cls__("‘‘类’’")['+i2+'].childNodes['+i3+'].childNodes[';
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length;i1++){
							var e1=li[i1];
							var id,a;‘得‘id名’代码’
							if(a.href.charAt(0)=="z")
								continue;
							z$("",'‘飞机’',a.href);
							attr__(a,'href',z+i+'].childNodes['+i1+'],5),"'+id+'","‘id名’"');
							attr__(a,'title','‘飞机’');
							attr__(a,'action-type','');
							attr__(a,'action-data','');
						}
					}
				}
			”。
			退出。
		了。
		等于评那么先
			赋予id名以cid。
			如果‘显示提示’那么
			插一脚‘js函数集2’“
				var ul=cls__("‘‘类’’");
				if(ul){
					var b=true;
					for(var i=0;i<ul.length&&b;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length&&b;i1++){
							var e1=li[i1];
							if(e1.tagName!="DL")
								continue;
							var id;‘得‘id名’代码’
							var idname="‘id名’";
							if(!z$("e",idname)||z$("g",idname)!=id){
								z$("id",idname,id);
								z$("f","弹出提示",get_msg__(e1,2),id,idname);
							}
							b=false;
						}
					}
				}
			”。
			如果存在搞飞机那么
			插一脚‘js函数集2’“
				var ul=cls__("‘‘类’’");
				if(ul){
					var b=true;
					for(var i=0;i<ul.length&&b;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length&&b;i1++){
							var e1=li[i1];
							if(e1.tagName!="DL")
								continue;
							var a=e__(e1,3,1,1);
							if(!a)
								continue;
							if(a.href.charAt(0)=="z")
								continue;
							z$("",'‘飞机’',a.href);
							var id;‘得‘id名’代码’
							a.href='zhscript:get_msg__(cls__("‘‘类’’")['+i+'].childNodes['+i1+'],2),"'+id+'","‘id名’"';
							a.title='‘飞机’';
							attr__(a,'action-type','');
							attr__(a,'action-data','');
						}
					}
				}
			”。
			退出。
		了。
		那么先
			赋予id名以mid。
			如果‘显示提示’那么
			插一脚‘js函数集2’“
				var ul=cls__("‘‘类’’");
				if(ul){
					var b=true,id_0=undefined,idname_0,e1_0;
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length&&b;i1++){
							var e1=li[i1];
							if(e1.tagName!="DL")
								continue;
							var id;‘得‘id名’代码’
							var idname="‘id名’";
							var b1=z$("e",idname),b2=false;
							if(b1)
								b2=(z$("g",idname)==id);
							if(!b1||b2||(i==ul.length-1&&i1>=li.length-4)){
								if(b2){
									id=id_0;
									idname=idname_0;
									e1=e1_0;
								}
								if(id){
									z$("id",idname,id);
									z$("”下代码
										显示停‘参数’↙。
										如果‘参数1’大于1那么隧道一次定时器、“获取新消息”、3s、“获取新消息”。
									上代码“",i1);
									z$("f","弹出提示",get_msg__(e1,1),id,idname);
								}
								b=false;
							}
							id_0=id;
							idname_0=idname;
							e1_0=e1;
						}
					}
				}
			”。
			如果存在搞飞机那么
			插一脚‘js函数集2’“
				var ul=cls__("‘‘类’’");
				if(ul){
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length;i1++){
							var e1=li[i1];
							if(e1.tagName!="DL")
								continue;
							var a,p_max;
							var id;‘得‘id名’代码’
							a=e__(e1,3,1,1);
							if(a.href.charAt(0)=="z")
								continue;
							z$("",'‘飞机’',a.href);
							p_max=1;
							attr__(a,'href','zhscript:get_msg__(cls__("‘‘类’’")['+i+'].childNodes['+i1+'],'+p_max+'),"'+id+'","‘id名’"');
							attr__(a,'title','‘飞机’');
							attr__(a,'action-type','');
							attr__(a,'action-data','');
						}
					}
				}
			”。
			退出。
		了。
	了。
上代码。

定义“传击过程处理”【主】以下代码
	插一脚‘js函数集2’“
		var i_;
		function get_a__(e){
			var e1=e.childNodes;
			for(var i1=0;i1<e1.length;i1++){
				var e2=e1[i1];
				if(e2.tagName=='A'){
					if(i_++==‘号’)
						return e2;
				}
				e2=get_a__(e2);
				if(e2)
					return e2;
			}
		}
		var ul”先
		如果‘类’等于信那么
		,i2,i3;‘得信类代码’
		否则
		;‘得类代码’
		了“
		if(ul){
			var b=true;
			for(var i=0;i<ul.length&&b;i++){
				var li=ul[i].childNodes;
				for(var i1=0;i1<li.length&&b;i1++){
					var e1=li[i1];
					var id,a;‘得‘id名’代码’
					if(id!="‘id’")
						continue;
					i_=0;
					a=get_a__(e1);
					if(a){
						me__('click',a);
						z$('','‘参数0’ a=',a);
					}
					b=false;
				}
			}
		}
	”、‘页号’。
上代码。
