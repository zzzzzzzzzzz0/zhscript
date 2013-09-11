赋予私信页【主】以‘首页’messages。
赋予评论页【主】以‘首页’comments。

定义“获取新消息”【主】以下代码
	赋予网址以隧道webkit、网址、#1。
	（如果存在我的首页并且‘网址’等于‘我的首页’那么赋予类以首
	否则如果调用‘头匹配方法’、‘网址’、‘私信页’那么赋予类以信
	否则如果调用‘头匹配方法’、‘网址’、‘评论页’那么赋予类以评
	否则显示不刷‘网址’↙，退出。）
	当先
		存在我的首页并且‘网址’等于‘我的首页’那么赋予类以首，跳出。
		调用‘头匹配方法’、‘网址’、‘私信页’那么赋予类以信，跳出。
		调用‘头匹配方法’、‘网址’、‘评论页’那么赋予类以评，跳出。
		那么显示不刷‘网址’↙，退出。
	了。

	隧道webkit、加强、#1。
	当‘类’先
		等于首那么先
			赋予id名以mid。
			如果‘显示提示’那么
			插一脚‘js函数集2’“
				var ul=cls__("MIB_feed");
				if(ul){
					var b=true,id_0=undefined,idname_0,e1_0;
					for(var i=0;i<ul.length&&b;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length&&b;i1++){
							var e1=li[i1];
							if(e1.tagName!="LI")
								continue;
							var id=e1.id;
							var idname="‘id名’";
							var b1=z$("e",idname),b2=false;
							if(b1)
								b2=(z$("g",idname)==id);
							if(!b1||b2||(i==ul.length-1&&i1>=li.length-2)){
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
				var ul=cls__("MIB_feed");
				if(ul){
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length;i1++){
							var e1=li[i1];
							if(e1.tagName!="LI")
								continue;
							var a,p_max;
							var id=e1.id;
							a=e__(e1,3,1,0);
							p_max=1;
							attr__(a,'href','zhscript:get_msg__(cls__("MIB_feed")['+i+'].childNodes['+i1+'],'+p_max+'),"'+id+'","‘id名’"');
							attr__(a,'title','‘飞机’');
							attr__(a,'action-type','');
							attr__(a,'action-data','');
						}
					}
				}
			”。
			退出。
		了。
		等于信那么先
			赋予id名以mid2。
			如果‘显示提示’那么
			插一脚‘js函数集2’“
				var ul=cls__("MIB_feed");
				if(ul){
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length;i1++){
							var e1=li[i1];
							if(e1.tagName!="LI")
								continue;
							var idname="‘id名’";
							var uid=attr__(e__(e1,1,1,0,0),'uid');
							var txt=e__(e1,3,3).innerText;
							var b1=z$("a-e",idname,uid),b2=false;
							if(b1)
								b2=(z$("a-g",idname,uid)!=txt);
							if(!b1||b2){
								z$("a-s",idname,uid,txt);
								z$("f","弹出提示",get_msg__(e1,1),uid,idname);
							}
						}
					}
				}
			”。
			如果存在搞飞机那么
			插一脚‘js函数集2’“
				var ul=cls__("MIB_feed");
				if(ul){
					for(var i=0;i<ul.length;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length;i1++){
							var e1=li[i1];
							if(e1.tagName!="LI")
								continue;
							var id=attr__(e__(e1,1,1,0,0),'uid');
							var a=e__(e1,3,3,1);
							attr__(a,'href','zhscript:get_msg__(cls__("MIB_feed")['+i+'].childNodes['+i1+'],5),"'+id+'","‘id名’"');
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
				var ul=cls__("commentsList");
				if(ul){
					var b=true;
					for(var i=0;i<ul.length&&b;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length&&b;i1++){
							var e1=li[i1];
							if(e1.tagName!="LI")
								continue;
							var e2=e__(e1,3,5,9,1);
							if(!e2)
								continue;
							var id=e2.id;
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
				var ul=cls__("commentsList");
				if(ul){
					var dt=new Date().getTime();
					var b=true;
					for(var i=0;i<ul.length&&b;i++){
						var li=ul[i].childNodes;
						for(var i1=0;i1<li.length&&b;i1++){
							var e1=li[i1];
							if(e1.tagName!="LI")
								continue;
							var a=e__(e1,3,5,1,0);
							if(!a)
								continue;
							var id;
							var e2=e__(e1,3,5,9,1);
							if(!e2)
								id=dt+'_'+i+'_'+i1;
							else{
								id=e2.id;
							}
							a.href='zhscript:get_msg__(cls__("commentsList")['+i+'].childNodes['+i1+'],2),"'+id+'","‘id名’"';
							a.title='‘飞机’';
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
	插一脚“
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
		var ul=cls__("MIB_feed");
		if(ul){
			var b=true;
			for(var i=0;i<ul.length&&b;i++){
				var li=ul[i].childNodes;
				for(var i1=0;i1<li.length&&b;i1++){
					var e1=li[i1];
					if(e1.tagName!="LI")
						continue;
					var id=”
					先如果‘id名’等于mid2
					那么attr__(e__(e1,1,1,0,0),'uid')
					否则e1.id了
					“;
					if(id!="‘id’")
						continue;
					i_=0;
					var a=get_a__(e1);
					if(a){
						me__('click',a);
						z$('','‘参数’/',a);
					}
					b=false;
				}
			}
		}
	”、‘页号’。
上代码。
