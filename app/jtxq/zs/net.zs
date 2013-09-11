如果不存在帐号【主】那么
	赋予【主】帐号以。
如果不存在密码【主】那么
	赋予【主】密码以。
如果不存在【主】群网址那么
	赋予【主】群网址以。

赋予【主】在线以0。
定义【主】设成上线以下代码
	如果不‘在线’那么先
		赋予【主】在线以1。
		显示消息“你在大街上了（稍安勿躁，有局的话会列在下面）”。
		隧道webkit、插脚、‘js函数集’hide__("loginform");show__("panlist");、www1。
		如果‘群网址’那么隧道一次定时器、随后到群、1000、下代码
			显示‘参数0’↙。
			隧道webkit、访问、‘群网址’、www2。
		上代码。
		隧道定时器、检查最新、1000、下代码
			隧道webkit、插脚、“‘js函数集’
				var a=new Array("feed_msg_new","notes"/*,"small_Yellow"*/);
				for(var i=0;i<a.length;i++){
					var v=__(a[i]);
					if(v&&v.style.display!="none"){
						window.location.reload();
						break;
					}
				}
				”、www2。
		上代码。
		隧道敏感、www1、1。
	了。
上代码。

定义进行登入【主】以下代码
	如果迭代正则‘参数1’、(^\?|&)?([^=]+)=([^&]*)、下代码
		别名名以参数2。
		赋予值以调用‘urldecode’、‘参数3’。
		当‘名’先
			等于u那么
				赋予【主】帐号以‘值’，跳出。
			等于pw那么
				赋予【主】密码以‘值’，跳出。
			等于qun那么
				赋予【主】群网址以‘值’，跳出。
		了。
	上代码、el那么先
		配置文件保存-、【主】帐号、【主】密码、【主】群网址。
		设定定义集。
		隧道webkit、插脚、‘js函数集’
			val__("loginname","‘帐号’");
			val__("password","‘密码’");
			click__("login_submit_btn");
			、www2。
		显示消息：你在登登登登登……。
		（隧道敏感、www1、0。）
		隧道一次定时器、没登上、1m、下代码
			如果‘在线’那么退出。
			隧道webkit、访问、http://www.weibo.com、www2。
			显示消息：‘参数0’，再试。
			隧道敏感、www1、1。
		上代码。
		1。
	了。
上代码。

赋予添盘【主】以下代码
	隧道webkit、插脚、“‘js函数集’
		var v="‘参数1’";
		var ming="‘参数2’";
		var fens="‘参数3’";
		var bu="‘参数4’";
		var mid="‘参数5’";
		var pan=cls__("pan");
		var has=-1;
		if(pan)
		for(var i=0;i<pan.length;i++){
			var a=pan[i];
			if(a.text==v){
				has=a.title;
				break;
			}
		}
		var o;
		if(has<0){
			has=pan_.length;
			var t=new_txt__(v);
			var a=new__("a");
			a.className="pan";
			a.title=has;
			a.href="javascript:select__("+has+");";
			add__(t,a);
			var li=new__("li");
			add__(a,li);
			ins__(li,__("new"));
			o=new Object();
			o.t_=v;
			o.mid_="‘空mid’";
			pan_.push(o);
		}else{
			o=pan_[has];
		}
		if(mid>o.mid_){
			o.fens_=fens;
			o.mid_=mid;
			o.ming_=ming;
			o.bu_=bu;
			if(v=="‘当前局’")
				z$("落",fens,ming,bu);
		}
		”、www1。
上代码。