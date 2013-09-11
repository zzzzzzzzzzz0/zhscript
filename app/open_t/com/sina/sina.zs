定义【顶】【锁】登陆sina以下代码
	如果存在“已登陆sina”那么退出。
	隧道webkit、附加、“‘js函数集’
		__("loginname").value="‘sina帐号’";
		__("password").value="‘sina密码’";
		click__(__("login_submit_btn"));
	”、sina。
上代码。

定义【顶】【锁】读取sina以下代码
	隧道webkit、附加、“‘js函数集’
		var ul=__("feed_list");
		if(ul){
			var li=ul.childNodes(1);
			var head_pic=li.childNodes(1);
			var MIB_feed_c=li.childNodes(3).childNodes;
			/*var s="";
			for(var i=0;i<MIB_feed_c.length;i++)
				s+=MIB_feed_c(i).innerText+"("+i+"\n";
			alert(s);*/
			window.location.href="zhscript:"
				+li.id+"‘华丽分割线1’"+
				MIB_feed_c(1).innerText+"<br>"+MIB_feed_c(MIB_feed_c.length-4).innerText+"‘华丽分割线2’"+
				head_pic.innerHTML
				;
		}
	”、sina#0。
上代码。

隧道webkit、sina、page_sina、
	侦听为zhscript:为下代码
		侦听zhscript:sina、‘参数栈’。
	上代码、
	侦听为标题改变为下代码
		侦听标题改变sina、‘参数栈’。
	上代码、
	侦听为请求为下代码
		别名网址以参数1。
		是否下载sina、‘网址’。
		如果调用‘正则配’、‘网址’、/public/aj_count_new\.php\?那么先
			隧道webkit、附加、“‘js函数集’
				if(__("feed_msg_new").style.display!="none")
					window.location.href="zhscript:（令）访问sina首页";
				”、sina。
			退出。
		了。
		如果调用‘正则配’、‘网址’、http://api\.t\.sina\.com\.cn/remind/unread_count\.json\?那么先
			隧道webkit、附加、“‘js函数集’
				var a=new Array("small_Yellow","feed_msg_new");
				for(var i=0;i<a.length;i++){
					var v=__(a[i]);
					if(v&&v.style.display!="none"){
						window.location.href="zhscript:（提示）"+v.innerText;
						break;
					}
				}
				”、sina。
			退出。
		了。
	上代码、
	侦听为装载完毕为下代码
		侦听装载完毕sina、‘参数栈’。
	上代码。

站初始化sina、新浪、
src="file://‘应用目录’/com/sina/logo.png"、
http://t.sina.com.cn/、
“我的首页 新浪微博-随时随地分享身边的新鲜事儿”、
3。

