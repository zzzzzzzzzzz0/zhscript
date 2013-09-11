赋予【主】首页网址式以^http://weibo\.com/[0-9a-zA-Z]+$。
赋予【主】首页标题式以“^我的首页 .+”。

定义【主】发布微博以下代码
	如果不‘在线’那么退出。
	隧道webkit、插脚、‘js函数集’__("publish_editor").focus();txt__("publish_editor","‘参数1’");、www2。
	隧道一次定时器、延后click、1s、下代码
		隧道webkit、插脚、‘js函数集’__("publisher_submit").focus();click__("publisher_submit");、www2。
	上代码。
上代码。

赋予【主】空mid以mid_0。
定义【主】获取最新以下代码
	隧道webkit、插脚、“‘js函数集’
		var ul=cls__("MIB_feed");
		if(ul)
		for(var i=0;i<ul.length;i++){
			var li=ul[i].childNodes;
			for(var i1=0;i1<li.length;i1++){
				var e1=li[i1];
				if(e1.tagName!="LI")
					continue;
				var e2=e1.childNodes;
				var e3=e2[3].childNodes;
				var e4=e3[1].childNodes;
				var ming=e4[0].innerHTML;
				var mid=e1.id;
				var re=/^：‘消息头1’(.+)‘消息头2’.+‘消息中1’(.+)‘消息中2’(.+)$/g;
				var a=re.exec(e4[1].nodeValue);
				if(a)
					z$("添盘",a[1],ming,a[3],a[2],mid);
			}
		}
		”、www2。
上代码。

