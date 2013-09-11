赋予【主】首页网址式以^http://q\.weibo\.com/[0-9a-zA-Z]+$。
赋予【主】首页标题式以“.+ 新浪微群.+”。

定义【主】发布微博以下代码
	如果不‘在线’那么退出。
	赋予内容以调用‘加反斜杠’、‘参数1’、C。
	赋予点以下代码
		隧道一次定时器、延后click、1s、下代码
			显示‘参数0’↙。
			隧道webkit、插脚、“‘js函数集’
				var e=__("publisher_forward");
				if(e){
					var e3=e__(e.parentNode,1);
					e3.focus();
					z$("",e3.tagName);
					me__("click",e3);
				}
				”、www2。
		上代码。
	上代码。
	隧道webkit、插脚、“‘js函数集’
		var e=cls__("publish");
		if(e){
			var e2=e__(e[0],3,1);
			e2.focus();
			e2.innerText="‘内容’";
			z$('‘点’');
		}else{
			z$("提示","你还不是该群成员");
		}
		”、www2。
上代码。

赋予【主】空mid以0。
定义【主】获取最新以下代码
	隧道webkit、插脚、“‘js函数集’
		var ul=cls__("feed_lists");
		if(ul)
		for(var i=0;i<ul.length;i++){
			var li=ul[i].childNodes;
			for(var i1=0;i1<li.length;i1++){
				var e1=li[i1];
				if(e1.tagName!="DL")
					continue;
				var e2=e1.childNodes;
				var e3=e2[3].childNodes;
				var ming=e3[1].innerText;
				var msg=e3[3].innerHTML;
				var mid=attr__(e1,"mid");
				var re=/^‘消息头1’(.+)‘消息头2’.+‘消息中1’(.+)‘消息中2’(.+)$/g;
				var a=re.exec(msg);
				if(a)
					z$("添盘",a[1],ming,a[3],a[2],mid);
			}
		}
		”、www2。
上代码。

