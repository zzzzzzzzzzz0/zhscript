（使用浏览器#0是为了在浏览其他页面也能正常处理）

定义【主】收取w.qq消息以下代码
	别名网址以参数1。
	如果调用‘正则配’、‘网址’、\.qq\.com/conn_s$、l那么先
		设置在线1。
		
		赋予【主】有新以false。
		隧道webkit、插脚、‘js函数集’‘js函数集2’下代码
			var cw=__("chatWin");
			if(cw&&cw.style.display=="block"){
				var cwc=__("chatWinContent").childNodes;
				if(cwc.length>0){
					/*z$("隧道点击、add_a。");*/
					var who=toline__(txt__("chatWinHeader"));
					var old_msg_name="【主】旧条之"+who;
					if(!z$("e",old_msg_name)){
						z$("s",old_msg_name,told__(cwc[cwc.length-1].innerText));
						for(var i=0;i<cwc.length;i++){
							z$("f","保存聊天记录",cwc[i].innerText);
						}
					}else{
						var h=htm__("chatWinHeader");
						if(!z$("f","应该忽略",h)){
							var img=z$("f","调用‘正则格’、",h,'<img src="([^"]+)');
							
							var old_msg=z$("g",old_msg_name);
							var i=cwc.length-1;
							for(;i>=0;i--){
								var msg=told__(cwc[i].innerText);
								if(msg==old_msg)
									break;
							}
							for(;++i<cwc.length;){
								var msg=cwc[i].innerText;
								z$("s",old_msg_name,told__(msg));
								z$("f","保存聊天记录",msg);
								z$("f","进行通知",msg,img,who);
								z$("s","【主】有新",true);
							}
						}
					}
				}
			}
		上代码、浏览器#0。
		如果‘【主】有新’那么退出。

		隧道webkit、插脚、‘js函数集’‘js函数集2’下代码
			var cbul=__("chatBoxUnreadList").childNodes;
			var u="",img;
			for(var i=0;i<cbul.length;i++){
				var h=cbul[i].innerHTML;
				if(z$("f","应该忽略",h))
					continue;
				img=z$("f","调用‘正则格’、",h,'<img src="([^"]+)" class="messageBoxHead">');
				u+=toline__(cbul[i].innerText)+"<br>";
			}
			if(u!=""){
				z$("
					别名未读以参数1。
					如果不存在旧未读或者‘旧未读’不等于‘未读’那么先
						赋予【主】旧未读以‘未读’。
						进行通知‘参数2’、‘参数3’。
					了
				",told__(u),u,img);
			}
		上代码、浏览器#0。
	了。
上代码。

定义【主】收取web.qq消息以下代码
	别名网址以参数1。
	如果调用‘正则配’、‘网址’、\.qq\.com/channel/poll2那么先
		设置在线1。

		隧道webkit、加强、浏览器#0。
		隧道webkit、插脚、‘js函数集’‘js函数集2’下代码
			var mb=__("qqweb_app_messageBubble");
			if(mb&&mb.style.display=="block"){
				var name=z$("f","调用‘正则格’、",htm__("messageBubble_bubblePanel_message"),'<span class="nick">([^<]+)</span>');
				var t=txt__("messageBubble_bubblePanel_message");
				z$("
					别名条以参数1。
					如果不存在旧未读或者‘旧未读’不等于‘条’那么先
						赋予【主】旧未读以‘条’。
						别名名以参数2。
						如果不应该忽略‘名’那么
							进行通知‘条’。
					了。
				",t,name);
			}
			var wc=cls__("window_content");
			function msg__(e){
				var e1=e.childNodes;
				var e2=e1[0].childNodes;
				var msg=new Object();
				msg.txt_=e1[2].innerText;
				msg.htm_=e1[2].innerHTML;
				msg.name_=e2[0].innerText;
				if(!msg.name_)
					msg.name_=e1[0].title;
				msg.time_=e2[1].innerText;
				msg.cls_=e.className;
				return msg;
			}
			function save_chat__(e,old_msg_name,who,img){
				var msg=msg__(e);
				z$("f","保存聊天记录",msg.name_,msg.time_,msg.htm_);
				if(old_msg_name!=undefined)
					z$("s",old_msg_name,msg.txt_);
				if(who!=undefined){
					if(msg.cls_!="chatBox_myMsg"&&!z$("f","应该忽略",who))
						z$("f","进行通知",msg.txt_,img,who);
				}
			}
			for(var i_wc=0;i_wc<wc.length;i_wc++){
				var e=wc[i_wc].childNodes;
				var e1=e[3].childNodes;
				var e2=e1[5].childNodes;
				if(e2.length==4)
					continue;
				var e3=e2[5].childNodes;
				var e4=e3[1].childNodes;
				var ml=e4[3];
				if(ml.className!="chatBox_msgList")
					continue;
				var list=ml.childNodes;
				e1=e[1].childNodes;
				e2=e1[3].childNodes;
				e3=e2[2].childNodes;
				var antt=e3[0];
				e4=antt.childNodes;
				var id=antt.id;
				var old_msg_name="【主】旧条之"+id;
				z$("","旧条名---"+old_msg_name+"--"+list.length);
				if(list.length<1)
					continue;
				if(!z$("e",old_msg_name)){
					for(var i=0;i<list.length;i++){
						if(i==list.length-1)
							save_chat__(list[i],old_msg_name);
						else{
							save_chat__(list[i]);
						}
					}
					continue;
				}
				var old_msg=z$("g",old_msg_name);
				var i=list.length-1;
				for(;i>=0;i--){
					var msg=msg__(list[i]);
					if(msg.txt_==old_msg)
						break;
				}
				z$("","行号"+i);
				if(++i<list.length){
					var who=e4[1].innerText;
					var img=z$("f","调用‘正则格’、",e2[0].innerHTML,' src="([^"]+)"');
					for(;i<list.length;i++)
						save_chat__(list[i],old_msg_name,who,img);
				}
			}
		上代码、浏览器#0。
	了。
上代码。
