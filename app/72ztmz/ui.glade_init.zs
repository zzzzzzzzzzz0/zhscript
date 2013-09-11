赋予应用名【主】以隧道标题。
加载公用.zs。
加载test.zs。
调用‘命令行解析’、‘参数栈’。
隧道读图片限制、70、70。

隧道webkit、www、www、
	侦听为警告为、侦听为确认为、侦听为提问为、侦听为标签页切换为、
	侦听为请求为、侦听为覆盖链接为、
	代码为下代码
		显示‘参数0’--‘参数’↙。
	上代码、
	侦听为z$为下代码
		当‘参数1’先
			等于g那么‘‘参数2’’，退出。
			等于s那么赋予‘参数2’以‘参数3’，退出。
			等于e那么先
				如果存在‘参数2’那么true否则false。
				退出。
			了。
			等于f那么解释‘参数2’“‘参数栈’”、‘参数栈3’，退出。
			等于++那么赋予‘参数2’以算术‘‘参数2’’+1，退出。
			等于那么显示‘参数’↙，退出。
		了。
		解释‘参数1’、‘参数栈2’。
	上代码、
	侦听为消息为下代码
		显示‘参数0’--‘参数’↙。
		如果存在消息陷阱那么先
			删除消息陷阱【主】。
			显示阱↙。
			退出。
		了。
		横条提示‘参数’。
	上代码、
	侦听为标题改变为下代码
		隧道标题为‘参数1’。
	上代码、
	侦听为装载完为下代码
		隧道webkit、加强、www。
	上代码、
	侦听为装载完毕为下代码
		如果存在阵图那么装入阵图。
		装入吕祖。
		装入女将。
		如果存在-zdjb那么先
			横条提示“自动脚本 ‘-zdjb’ 即将加载”。
			隧道一次定时器、自动脚本、2s、“加载“‘阵图目录’‘-zdjb’.zidong””。
			删除-zdjb【主】。
		了。
	上代码。

定义倒计时提示【主】以下代码
	隧道内容、label1、‘参数1’。
	如果存在参数2那么
		别名标题以参数2。
	否则
		赋予标题以。
	赋予提示倒计时【主】以3。
	隧道窗口标题、dialog1、‘标题’。
	隧道可见、dialog1、1。
	隧道定时器、‘参数0’、1s、下代码
		如果‘提示倒计时’等于0那么先
			隧道定时器、‘参数0’、移除。
			隧道可见、dialog1、0。
			退出。
		了。
		别名标题以参数1。
		隧道窗口标题、dialog1、“‘标题’（‘提示倒计时’秒后关闭）”。
		赋予提示倒计时【主】以算术‘提示倒计时’-1。
	上代码、‘标题’。
上代码。

定义横条提示【主】以下代码
	隧道内容、hint、‘参数1’。
	隧道移动、hint-win、先隧道窗口x了、先算术先隧道窗口y了+先隧道窗口高了-40了。
	隧道窗口宽高、先隧道窗口宽了、+0、hint-win。
	（隧道窗口背景、#yellow、hint-win。）
	隧道可见、hint-win、1。
	隧道一次定时器、‘参数0’、3s、“隧道可见、hint-win、0”。
上代码。

定义得网页内容【主】以下代码
	（显示‘参数0’--‘参数’↙。）
	调用‘参数处理’、、、2、下代码
		赋予‘参数1’【上】【上】以‘参数2’。
	上代码、----、‘参数栈2’。
	赋予网页目录【上】以‘根’html/。
	赋予内容【上】以调用‘type’、‘网页目录’‘参数1’.html。
	赋予内容【上】以调用‘正则代’、‘内容’、\{\*([^\*]+)\*\}、下代码
		‘‘参数1’’。
	上代码。
上代码。

隧道webkit、www2、www2、
	侦听为标题改变为下代码
		隧道窗口标题、html-win、‘参数1’。
	上代码、
	侦听为zhscript:为下代码
		隧道可见、html-win、0。
		当‘参数1’先
			等于X那么退出。
		了。
	上代码。
定义打开网页【主】以下代码
	得网页内容‘参数栈’。
	隧道点击、pause。
	隧道可见、html-win、1。
	隧道webkit、内容、‘内容’、file://‘网页目录’、www2。
上代码。

隧道webkit、pref-www、pref-www、
	侦听为zhscript:为下代码
		（显示‘参数0’--‘参数’↙。）
		隧道可见、pref-win、0。
		当‘参数1’先
			等于X那么退出。
		了。
		如果迭代正则‘参数1’、pref\?(.+)、下代码
			赋予代码以。
			迭代正则‘参数1’、&?([^=]+)=([^&]*)、下代码
				别名名以参数1。
				别名值以参数2。
				如果‘名’等于i那么赋予‘名’【上】以‘值’，再来。
				赋予代码【上】以‘代码’lvzu___.o_[‘i’].‘名’="‘值’";。
			上代码。
			显示‘代码’↙。
			隧道webkit、插脚、‘代码’、www。
		上代码那么退出。
	上代码。
定义“显示属性页”【主】以下代码
	得网页内容：属性设置、‘参数栈’。
	赋予x以算术‘x’+200。
	赋予y以算术‘y’+50。
	赋予w2以隧道窗口宽、pref-win。
	赋予w以隧道窗口宽。
	赋予h2以隧道窗口高、pref-win。
	赋予h以隧道窗口高。
	如果算术‘x’+‘w2’大于等于‘w’那么赋予x以算术‘w’-‘w2’。
	如果算术‘y’+‘h2’大于等于‘h’那么赋予y以算术‘h’-‘h2’。
	赋予x以算术‘x’+先隧道窗口x了。
	赋予y以算术‘y’+先隧道窗口y了。
	隧道移动、pref-win、‘x’、‘y’。
	隧道可见、pref-win、1。
	隧道webkit、内容、‘内容’、file://‘网页目录’、pref-www。
上代码。

定义得属性文件名【主】以下代码
	别名名以参数1。
	别名目录以参数2。
	赋予主名【上】以调用‘子串方法’、先调用‘得文件主名’、‘名’了、如果存在参数3那么‘参数3’否则2。
	‘目录’‘主名’.zs。
上代码。

隧道webkit、tou-www、tou-www、
	侦听为zhscript:为下代码
		隧道可见、tou-win、0。
		当‘参数1’先
			等于X那么退出。
		了。
	上代码。
定义“显示头像页”【主】以下代码
	得网页内容：头像、‘参数栈’。
	赋予x以算术先隧道窗口x了+先隧道窗口宽了。
	赋予y以算术先隧道窗口y了。
	隧道移动、tou-win、‘x’、‘y’。
	隧道可见、tou-win、1。
	隧道webkit、内容、‘内容’、file://‘网页目录’、tou-www。
	隧道一次定时器、‘参数0’、10s、“隧道可见、tou-win、0”。
上代码。

赋予吕夹【主】以隧道图标夹为iconview1、代码为下代码
	（显示‘参数0’--‘参数’↙。）
	别名动作类型以参数3。
	如果存在动作类型并且‘动作类型’等于外那么先
		如果存在吕人选【主】那么删除吕人选【主】。
		退出。
	了。
	赋予吕人选【主】以‘参数1’。
上代码、图片缓存为隧道图片缓存。

定义装入吕祖【主】以下代码
	隧道图标夹为清空为‘吕夹’。
	赋予搜以调用‘dir.begin’、‘吕祖目录’、^[0-9]?-.+\.png$、o0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		赋予属性文件以得属性文件名‘名’、‘吕祖目录’。
		如果调用‘exist’、‘属性文件’那么再来。
		
		隧道内容、att-tag、‘名’。
		隧道内容、att-r、1。
		隧道内容、att-sudu、1。
		隧道内容、att-shangli、1。
		隧道内容、att-max、1。
		隧道内容、att-bingqi-max、1。
		隧道可见、att-dlg、1。
		跳出。
	了。
	调用‘dir.first’、‘搜’、0。
	赋予代码以。
	赋予号以0。
	赋予文件loading【主】以0。
	赋予文件loading量【主】以0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		赋予属性文件以得属性文件名‘名’、‘吕祖目录’。
		如果调用‘exist’、‘属性文件’否则再来。
		赋予代码以‘代码’先解释下代码
			打开属性文件‘属性文件’。
			隧道图标夹为增加为‘号’、‘主名’、‘吕祖目录’‘名’、为‘吕夹’。
			“
			var o={};
			o.img_=new Image();
			o.img_.onload=function(){
				z$("++","文件loading【主】");
			};
			o.img_.src="‘吕祖目录’‘名’";
			o.name_="‘主名’";
			o.max_=‘允许数’;
			o.cnt_=0;
			”。
			赋予文件loading量【主】以算术‘文件loading量【主】’+1。
			赋予兵器以‘吕祖目录’‘主名’的兵器.png。
			如果调用‘exist’、‘兵器’那么先
				“
				o.r_=‘攻击半径’;
				o.r1_=(o.r_+0.5)*‘人高’;
				o.sudu_=‘攻击速度’;
				o.shangli_=‘杀伤力’;
				o.bingqi_max_=‘兵器携带数’;
			
				o.bingqi_=new Image();
				o.bingqi_.onload=function(){
					z$("++","文件loading【主】");
				};
				o.bingqi_.src="‘兵器’";
				”。
				赋予文件loading量【主】以算术‘文件loading量【主】’+1。
			了。
		上代码了lvzu_png_.push(o);↙。
		赋予号以算术‘号’+1。
	了。
	调用‘dir.end’、‘搜’。
	隧道webkit、插脚、lvzu_png_.splice(0);‘代码’、www。
上代码。
隧道侦听、点击、att-y、下代码
	赋予文件以得属性文件名先隧道内容、att-tag了、‘吕祖目录’。
	调用‘echo’、
		“攻击半径为”先隧道内容、att-r了“。”↙
		“攻击速度为”先隧道内容、att-sudu了“。”↙
		“杀伤力为”先隧道内容、att-shangli了“。”↙
		“允许数为”先隧道内容、att-max了“。”↙
		“兵器携带数为”先隧道内容、att-bingqi-max了“。”↙
		、‘文件’。
	隧道可见、att-dlg、0。
	装入吕祖。
上代码。
隧道侦听、点击、att-x、下代码
	赋予文件以‘吕祖目录’先隧道内容、att-tag了。
	执行“mv '‘文件’' '‘文件’-'”。
	隧道可见、att-dlg、0。
	装入吕祖。
上代码。

定义装入女将【主】以下代码
	赋予搜以调用‘dir.begin’、‘女将目录’、\.png$、o0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		赋予属性文件以得属性文件名‘名’、‘女将目录’、0。
		如果调用‘exist’、‘属性文件’那么再来。
		
		隧道内容、att-nvjiang-tag、‘名’。
		隧道内容、att-nvjiang-xue、100。
		隧道内容、att-nvjiang-max、1。
		隧道可见、att-nvjiang-dlg、1。
		跳出。
	了。
	调用‘dir.first’、‘搜’、0。
	赋予代码以。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		赋予属性文件以得属性文件名‘名’、‘女将目录’、0。
		如果调用‘exist’、‘属性文件’否则再来。
		打开属性文件‘属性文件’。
		赋予代码以‘代码’“var o={};
						o.img_=new Image();
						o.img_.src="‘女将目录’‘名’";
						o.name_="‘主名’";
						o.xue_=‘血量’;
						o.max_=‘允许数’;
						o.cnt_=0;
						nvjiang_png_.push(o);”↙。
	了。
	调用‘dir.end’、‘搜’。
	隧道webkit、插脚、nvjiang_png_.splice(0);‘代码’mk_vars__();、www。
上代码。
隧道侦听、点击、att-nvjiang-y、下代码
	赋予文件以得属性文件名先隧道内容、att-nvjiang-tag了、‘女将目录’、0。
	调用‘echo’、
		“血量为”先隧道内容、att-nvjiang-xue了“。”↙
		“允许数为”先隧道内容、att-nvjiang-max了“。”↙
		、‘文件’。
	隧道可见、att-nvjiang-dlg、0。
	装入女将。
上代码。
隧道侦听、点击、att-nvjiang-x、下代码
	赋予文件以‘女将目录’先隧道内容、att-nvjiang-tag了。
	执行“mv '‘文件’' '‘文件’-'”。
	隧道可见、att-nvjiang-dlg、0。
	装入女将。
上代码。

定义预读文件【主】以下代码
	别名文件以参数1。
	如果‘文件’那么先
		赋予文件loading【主】以0。
		赋予文件loading量【主】以1。
		隧道webkit、插脚、“
			var img=new Image();
			img.onload=function(){
				z$("++","文件loading【主】");
			};
			img.src="‘文件’";
		”、www。
	了。
	循环先
		如果‘文件loading’等于‘文件loading量’那么跳出。
		隧道不堵塞。
	了。
上代码。

定义阵图错【主】以下代码
	横条提示该阵图‘参数1’。
	如果存在阵图【主】那么删除阵图【主】。
上代码。

定义装入阵图【主】以下代码
	赋予阵图以调用‘串替换方法’、‘阵图’、　、‘　’,。
	赋予阵图以调用‘串替换方法’、‘阵图’、乂、‘乂’,。
	赋予阵图以调用‘串替换方法’、‘阵图’、卍、‘卍’,。
	赋予阵图以调用‘串替换方法’、‘阵图’、卐、‘卐’,。
	赋予阵图以调用‘串替换方法’、‘阵图’、十、‘十’,。
	赋予阵图以调用‘串替换方法’、‘阵图’、|、],。
	赋予阵图以调用‘串替换方法’、‘阵图’、↙、↙[。
	赋予消息陷阱【主】以。
	隧道webkit、插脚、“map_=[‘阵图’];”、www。
	如果不存在消息陷阱那么先
		阵图错有误。
		退出。
	了。
	删除消息陷阱【主】。

	如果存在阵图文件那么先
		赋予目录以调用‘得目录名’、‘阵图文件’。

		赋予地表以‘目录’‘地表文件名’。
		如果调用‘exist’、‘地表’否则赋予地表以‘预地表文件’。
		如果‘地表’不等于‘地表文件’那么先
			赋予地表文件【主】以‘地表’。
			预读文件‘地表’。
			隧道webkit、插脚、map_ebi_.style.background="url(‘地表’) repeat";、www。
		了。
	
		赋予工事以‘目录’‘工事文件名’。
		如果调用‘exist’、‘工事’否则赋予工事以‘预工事文件’。
		如果‘工事’不等于‘工事文件’那么先
			赋予工事文件【主】以‘工事’。
			预读文件‘工事’。
			隧道webkit、插脚、gongshi_.src="‘工事’";、www。
		了。
		
		赋予吕祖以‘目录’‘吕祖目录名’。
		如果调用‘existdir’、‘吕祖’否则赋予吕祖以‘预吕祖目录’。
		如果‘吕祖’不等于‘吕祖目录’那么先
			赋予吕祖目录【主】以‘吕祖’。
			装入吕祖。
			预读文件。
		了。
		
		赋予女将以‘目录’‘女将目录名’。
		如果调用‘existdir’、‘女将’否则赋予女将以‘预女将目录’。
		如果‘女将’不等于‘女将目录’那么先
			赋予女将目录【主】以‘女将’。
			装入女将。
		了。
	了。

	隧道webkit、插脚、“
		var no_begin=true,no_end=true;
		for(var y=0;y<‘纵格数’;y++){
			for(var x=0;x<‘横格数’;x++){
				switch(map_[y][x]){
				case ‘卍’:
					no_begin=false;
					break;
				case ‘卐’:
					no_end=false;
					break;
				}
			}
		}
		var ok=true;
		if(no_begin){
			z$("阵图错没有起点。");
			ok=false;
		}
		if(no_end){
			z$("阵图错没有终点。");
			ok=false;
		}
		if(ok){
			clear_layer__(map_layer_);
			for(var y=0;y<‘纵格数’;y++){
				for(var x=0;x<‘横格数’;x++){
					if(map_[y][x]>=‘乂’){
						map_layer_.drawImage(gongshi_,x*‘人宽’,y*‘人高’,‘人宽’,‘人高’);
					}
				}
			}
		}
	”、www。
上代码。

定义非兵位提示【主】以下代码
	别名x以参数1。
	别名y以参数2。
	赋予x以调用‘中文数字方法’、算术‘x’+1。
	赋予y以调用‘中文数字方法’、算术‘y’+1。
	横条提示‘x’‘y’处非兵位。
上代码。

隧道侦听、点击、reload、下代码
	赋予攻击策略以“var celve_=[];{var o;”。
	赋予号以0。
	赋予搜以调用‘dir.begin’、‘策略目录’、\.zs$、s o0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		打开属性文件‘策略目录’‘名’。
		赋予攻击策略以‘攻击策略’o={};o.name_="‘名’";o.func_=function(nvjiangs,bingqi_cnt){‘代码’};celve_.push(o);。
		赋予号以算术‘号’+1。
	了。
	调用‘dir.end’、‘搜’。
	赋予攻击策略以‘攻击策略’}z$("","攻击策略",celve_.length);。

	赋予兵器时间片大小以10。
	赋予...以“width=‘图宽’ height=‘图高’ style="position:absolute;left:10;top:10;”。
	隧道webkit、内容、“
		<canvas id="map" ‘...’background:url(‘地表文件’) repeat;"></canvas>
		<canvas id="nvjiang" ‘...’"></canvas>
		<canvas id="lvzu" ‘...’"></canvas>
		<canvas id="nvjiang_name" ‘...’"></canvas>
		<canvas id="lvzu_name" ‘...’"></canvas>
		<canvas id="bingqi" ‘...’"></canvas>
		<canvas id="select" ‘...’"></canvas>
		<script>
		‘攻击策略’
		function clear_layer__(l){
			l.clearRect(0,0,‘图宽’,‘图高’);
		}
		function draw_o__(o,l,n_l){
			var x=o.x_*‘人宽’,y=o.y_*‘人高’;
			l.drawImage(o.png_.img_,x,y,‘人宽’,‘人高’);
			
			var w1,h1=7;
			n_l.font=h1+"px serif";
			h1+=2;
			w1=n_l.measureText(o.png_.name_).width+4;
			x+=‘人宽’-w1-1;
			y--;
			n_l.save();
			n_l.fillStyle="#fff";
			n_l.fillRect(x,y-h1,w1,h1);
			n_l.restore();
			n_l.strokeRect(x,y-h1,w1,h1);
			n_l.fillText(o.png_.name_,x+2,y-2);
		}
		function she__(img,x2,y2,jiao,zheng,l){
			l.save();
			l.translate(x2,y2);
			l.rotate(Math.PI/180.0*(jiao+zheng));
			l.drawImage(img,-0.5*img.width,-0.5*img.height,img.width,img.height);
			l.restore();
		}
		function jiao__(x1,y1,x2,y2){
			var r=(Math.atan2(y2-y1,x2-x1));
			r=r/Math.PI*180.0;
			return(r>=0&&r<=180)?r+=90:((r<0&&r>=-90)?r+=90:r+=450);
		}
		function juli__(x1,y1,x2,y2){
			var xdiff=x2-x1;
			var ydiff=y2-y1;
			return Math.pow((xdiff*xdiff+ydiff*ydiff),0.5);
		}
		var start_=false;
		
		var gongshi_=new Image();
		gongshi_.src="‘工事文件’";

		var map_;
		var map_ebi_=document.getElementById("map");
		var map_layer_=map_ebi_.getContext("2d");
		
		var nvjiang_layer_=document.getElementById("nvjiang").getContext("2d");
		var nvjiang_name_layer_=document.getElementById("nvjiang_name").getContext("2d");
		var nvjiang_png_=[];
		var nvjiang_time_size_=20,nvjiang_mk_int_=50,nvjiang_bat_num_=0;
		var nvjiang___={
			o_:[],
			add_:[],
			add__:function(){
				var i,png;
				var len=0;
				for(i=0;i<nvjiang_png_.length;i++){
					png=nvjiang_png_[i];
					len+=png.max_-png.cnt_;
				}
				if(len==0){
					return false;
				}
				var i1=Math.floor(Math.random()*len),i2=0;
				for(i=0;i<nvjiang_png_.length;i++){
					png=nvjiang_png_[i];
					i2+=png.max_-png.cnt_;
					if(i2>=i1&&png.cnt_<png.max_){
						png.cnt_++;
						break;
					}
				}
				var o={};
				o.i_=i;
				o.png_=png;
				o.xue_=png.xue_;
				o.old_x_=[];
				o.old_y_=[];
				o.old_i_=0;
				this.add_.push(o);
				return true;
			},
			has__:function(x,y){
				for(var i=0;i<this.o_.length;i++){
					var o1=this.o_[i];
					if(o1&&o1.x_==x&&o1.y_==y)
						return o1;
				}
				return false;
			},
			can_go__:function(x,y,o){
				if(x<0||y<0||x>=‘横格数’||y>=‘纵格数’)
					return false;
				for(var i=0;i<o.old_x_.length;i++){
					if(x==o.old_x_[i]&&y==o.old_y_[i])
						return false;
				}
				if(this.has__(x,y))
					return false;
				if(lvzu___.has__(x,y))
					return false;
				if(map_[y][x]<=‘　’){
					o.x_=x;
					o.y_=y;
					return true;
				}
				return false;
			},
			old__:function(o){
				for(var i=0;i<o.old_x_.length;i++){
					if(o.x_==o.old_x_[i]&&o.y_==o.old_y_[i]){
						return;
					}
				}
				o.old_x_[o.old_i_]=o.x_;
				o.old_y_[o.old_i_]=o.y_;
				if(++o.old_i_>3)
					o.old_i_=0;
			},
			draw_i__:function(i){
				var o=this.o_[i];
				if(!o){
					return;
				}
				if(o.x_==undefined){
					var b=false;
					for(var y=0;y<‘纵格数’&&!b;y++){
						for(var x=0;x<‘横格数’&&!b;x++){
							if(map_[y][x]==‘卍’){
								o.x_=x;
								o.y_=y;
								b=true;
							}
						}
					}
				}else{
					if(!this.can_go__(o.x_+1,o.y_,o))
					if(!this.can_go__(o.x_,o.y_+1,o))
					if(!this.can_go__(o.x_-1,o.y_,o))
					if(!this.can_go__(o.x_,o.y_-1,o));
				}
				
				this.old__(o);

				o.x2_=(o.x_+0.5)*‘人宽’;
				o.y2_=(o.y_+0.5)*‘人高’;
				draw_o__(o,nvjiang_layer_,nvjiang_name_layer_);
				
				if(map_[o.y_][o.x_]==‘卐’){
					z$("","到了",o.png_.name_);
					this.o_[i]=null;
					if(++this.esc_>=nvjiang_bat_num_){
						timer_cnt_=timer_max_+1;
						z$("f","打开网页","输","esc",this.esc_);
					}
				}
			},
			esc_:0,
			draw__:function(){
				clear_layer__(nvjiang_layer_);
				clear_layer__(nvjiang_name_layer_);
				for(var i=0;i<this.o_.length;i++)
					this.draw_i__(i);
			},
			mk__:function(){
				if(timer_cnt_%(nvjiang_time_size_*nvjiang_mk_int_)==0){
					for(;;){
						var add=this.add__();
						if(this.add_.length == nvjiang_bat_num_ || !add) {
							this.add_.sort(function(a, b){
								return a.xue_ - b.xue_;
							});
							break;
						}
					}
				}
				if(this.add_.length > 0){
					this.o_.push(this.add_.pop());
				}
			},
			shua__:function(){
				if(timer_cnt_%nvjiang_time_size_!=0)
					return;
				this.mk__();
				this.draw__();
			},
			reset__:function(){
				for(var i=0;i<nvjiang_png_.length;i++){
					nvjiang_png_[i].cnt_=0;
				}
				clear_layer__(nvjiang_layer_);
				clear_layer__(nvjiang_name_layer_);
				this.o_.splice(0);
				this.esc_=0;
			},
			kill__:function(i,shangli){
				var o=this.o_[i];
				if(!o)
					return;
				o.xue_-=shangli;
				if(o.xue_<=0){
					this.o_[i]=null;
				}
			},
		};

		var lvzu_layer_=document.getElementById("lvzu").getContext("2d");
		var lvzu_name_layer_=document.getElementById("lvzu_name").getContext("2d");
		var lvzu_png_=[];
		var lvzu___={
			o_:[],
			add__:function(i,x,y){
				return this.add2__(i,typeof(i)=="number"?"i":"s",x,y);
			},
			add2__:function(i,type,x,y){
				switch(map_[y][x]){
				case ‘乂’:case ‘十’:
					break;
				default:
					z$("非兵位提示"+x+"、"+y);
					return false;
				}
				switch(type){
				case "s":
					var name=i;
					i=-1;
					for(var lvzu_i=0;lvzu_i<lvzu_png_.length;lvzu_i++){
						if(name==lvzu_png_[lvzu_i].name_){
							i=lvzu_i;
							break;
						}
					}
					if(i<0){
						z$("横条提示"+name+"？");
						return false;
					}
					break;
				}
				var png=lvzu_png_[i];
				z$("",png.name_,png.cnt_+"-"+png.max_,x,y);
				if(png.cnt_>=png.max_){
					z$("横条提示"+png.name_+"“只允许有 "+png.max_+" 位”");
					return false;
				}
				png.cnt_++;
				var o={};
				o.i_=i;
				o.png_=png;
				o.x_=x;
				o.y_=y;
				o.x1_=(o.x_+0.5)*‘人宽’;
				o.y1_=(o.y_+0.5)*‘人高’;
				o.bingqi_cnt_=png.bingqi_max_;
				o.celve_i_=0;
				this.o_.push(o);
				return true;
			},
			i__:function(x,y){
				for(var i=0;i<this.o_.length;i++){
					var o1=this.o_[i];
					if(o1.x_==x&&o1.y_==y)
						return i;
				}
				return -1;
			},
			has__:function(x,y){
				var i=this.i__(x,y);
				if(i>=0)
					return this.o_[i];
				return null;
			},
			draw__:function(){
				clear_layer__(lvzu_layer_);
				clear_layer__(lvzu_name_layer_);
				for(var i=0;i<this.o_.length;i++)
					draw_o__(this.o_[i],lvzu_layer_,lvzu_name_layer_);
			},
			reset__:function(){
				for(var i=0;i<lvzu_png_.length;i++){
					lvzu_png_[i].cnt_=0;
				}
				clear_layer__(lvzu_layer_);
				clear_layer__(lvzu_name_layer_);
				clear_layer__(select_layer_);
				this.o_.splice(0);
			},
			sel__:function(i){
				if(i<0)
					i+=this.o_.length;
				var o=this.o_[i];
				clear_layer__(select_layer_);
				select_layer_.strokeStyle="#FF0000";
				select_layer_.beginPath();
				var x=o.x1_,y=o.y1_,r=o.png_.r1_;
				select_layer_.arc(x,y,r,0,Math.PI*2,true);
				select_layer_.closePath();  
				var jiao=45,du=Math.PI/180*jiao;
				var yadd=r*Math.sin(du);
				var xadd=r*Math.cos(du);
				var y2=y+yadd;
				var x2=x+xadd;
				select_layer_.moveTo(x-xadd,y-yadd);
				select_layer_.lineTo(x2,y2);
				select_layer_.stroke();
				if(o.png_.bingqi_){
					she__(o.png_.bingqi_,x2,y2,jiao,90,select_layer_);
				}
			},
		};
		var select=document.getElementById("select");
		var select_layer_=select.getContext("2d");
		select.onclick=function(e){
			if(!map_){
				z$("隧道点击、open-zhentu");
				return;
			}
			z$("隧道可见、pref-win、0");
			
			var x=e.offsetX||e.layerX,y=e.offsetY||e.layerY;
			x=Math.floor(x/‘人宽’);
			y=Math.floor(y/‘人高’);
			
			var o;
			o=nvjiang___.has__(x,y);
			if(o){
				z$("f","显示头像页",
				"name",			o.png_.name_,
				"qita",			"血量 "+o.xue_,
				"src",			o.png_.img_.src);
				return;
			}
			var i;
			i=lvzu___.i__(x,y);
			if(i>=0){
				o=lvzu___.o_[i];
				lvzu___.sel__(i);
				
				if(o.png_.bingqi_max_) {
					var celve="";
					for(var celve_i=0;celve_i<celve_.length;celve_i++){
						celve+="<option value="+celve_i;
						if(o.celve_i_==celve_i)
							celve+=" selected";
						celve+=">"+celve_[celve_i].name_+"</option>";
					}
					z$("f","显示属性页",
					"i",			i,
					"x",			o.x1_,
					"y",			o.y1_,
					"bingqi",		o.png_.bingqi_max_>2&&o.bingqi_cnt_!=o.png_.bingqi_max_?
									o.bingqi_cnt_+" 补足为 "+o.png_.bingqi_max_
									:
									o.png_.bingqi_max_,
					"bingqi_max",	o.png_.bingqi_max_,
					"celve",		celve);
				}
				z$("f","显示头像页",
				"name",			o.png_.name_,
				"qita",			"杀伤力 "+(o.png_.shangli_==undefined?"无":o.png_.shangli_)+"<br>"+
								"攻击速度 "+(o.png_.sudu_==undefined?"无":o.png_.sudu_)+"<br>"+
								"攻击半径 "+(o.png_.r_==undefined?"无":o.png_.r_)+"<br>",
				"src",			o.png_.img_.src);
				
				return;
			}

			if(!z$("e","吕人选")){
				z$("横条提示从列表里选择一位");
				return;
			}
			i=z$("g","吕人选");
			if(!lvzu___.add2__(i,"i",x,y))
				return;
			lvzu___.draw__();
			lvzu___.sel__(-1);
		};
		var bingqi_layer_=document.getElementById("bingqi").getContext("2d");
		var bingqi___={
			o_:[],
			add__:function(o1,x1,y1,x2,y2){
				if(o1.bingqi_cnt_<=0)
					return false;
				if(o1.bingqi_cnt_%10==0&&timer_cnt_%100!=0){
					return false;
				}
				o1.bingqi_cnt_--;
				var o={};
				o.fashezhe_=o1;
				o.sudu_=o1.png_.sudu_;
				o.shangli_=o1.png_.shangli_;
				o.bingqi_=o1.png_.bingqi_;
				
				o.r_=0;
				o.rmax_=o1.png_.r1_;
				
				o.x_=x1;
				o.y_=y1;
				o.xadd_=(x2-x1)*o1.png_.sudu_/o.rmax_;
				o.yadd_=(y2-y1)*o1.png_.sudu_/o.rmax_;
				o.jiao_=jiao__(x1,y1,x2,y2);
				
				this.o_.push(o);
				return true;
			},
			mk__:function(){
				for(var i=0;i<lvzu___.o_.length;i++){
					var o=lvzu___.o_[i];
					if(o&&o.bingqi_cnt_>0){
						var x1=o.x1_,y1=o.y1_,r1=o.png_.r1_;
						var nvjiangs=[];
						for(var i2=0;i2<nvjiang___.o_.length;i2++){
							var o2=nvjiang___.o_[i2];
							if(o2){
								var r2=juli__(x1,y1,o2.x2_,o2.y2_);
								if(r2<=r1){
									nvjiangs.push(o2);
								}
							}
						}
						nvjiangs=celve_[o.celve_i_].func_(nvjiangs,o.bingqi_cnt_);
						if(nvjiangs){
							for(var i2=0;i2<nvjiangs.length;i2++){
								var o2=nvjiangs[i2];
								if(o2){
									this.add__(o,x1,y1,o2.x2_,o2.y2_);
								}
							}
						}
					}
				}
			},
			draw__:function(){
				clear_layer__(bingqi_layer_);
				for(var i=0;i<this.o_.length;i++){
					var o=this.o_[i];
					if(!o||!o.bingqi_)
						continue;
					o.x_+=o.xadd_;
					o.y_+=o.yadd_;
					she__(o.bingqi_,o.x_,o.y_,o.jiao_,0,bingqi_layer_);
					for(var i2=0;i2<nvjiang___.o_.length;i2++){
						var o2=nvjiang___.o_[i2];
						if(o2){
							if(juli__(o.x_,o.y_,o2.x2_,o2.y2_)<‘人高’){
								nvjiang___.kill__(i2,o.shangli_);
								if(o.fashezhe_.png_.max_>1)
									this.del__(i);
							}
						}
					}
					if(!o)
						continue;
					if((o.r_+=o.sudu_)>o.rmax_)
						this.del__(i);
				}
			},
			del__:function(i){
				var o=this.o_[i];
				if(o){
					if(o.fashezhe_.png_.bingqi_max_<=2)
						o.fashezhe_.bingqi_cnt_++;
					this.o_[i]=null;
				}
			},
			shua__:function(){
				if(timer_cnt_%‘兵器时间片大小’!=0)
					return;
				this.mk__();
				this.draw__();
			},
			reset__:function(){
				clear_layer__(bingqi_layer_);
				this.o_.splice(0);
			},
		};
		
		var timer_cnt_=0,timer_max_=0;
		setInterval(function(){
			if(!start_)
				return;
			/*document.title=timer_cnt_;*/
			if(timer_cnt_>timer_max_){
				return;
			}
			if(timer_cnt_==timer_max_){
				timer_cnt_=timer_max_+1;
				z$("f","打开网页","赢");
				return;
			}
			timer_cnt_++;
			nvjiang___.shua__();
			bingqi___.shua__();
		},20);
		function mk_vars__(){
			var i1=0;
			for(var i=0;i<nvjiang_png_.length;i++){
				i1+=nvjiang_png_[i].max_;
			}
			nvjiang_bat_num_=Math.ceil(i1/10);
			if(nvjiang_bat_num_<1)
				nvjiang_bat_num_=1;
			if(nvjiang_bat_num_>20)
				nvjiang_bat_num_=20;
			timer_max_=(Math.ceil(i1/nvjiang_bat_num_)+4)*nvjiang_time_size_*nvjiang_mk_int_;
			z$("",i1,"timer_max_",timer_max_,"nvjiang_bat_num_",nvjiang_bat_num_,"nvjiang_time_size_",nvjiang_time_size_);
		}
		
		document.onkeypress=function(event){
			var cc=String.fromCharCode(event.charCode);
			var btn="test"+cc;
			var has=z$("隧道有、"+btn);
			if(has==1){
				z$("隧道点击、"+btn);
			}
		};
		</script>
	”、file:///、www。
	隧道可见、pause、0。
	隧道可见、play、1。
上代码。
隧道点击、reload。

定义open-zhentu-【主】以下代码
	隧道点击、pause。
	赋予阵图文件以打开阵图‘参数栈’。
	如果‘阵图文件’那么先
		赋予阵名【主】以‘阵名’。
		赋予阵图【主】以‘阵图’。
		隧道webkit、插脚、下代码
			timer_cnt_=0;
			nvjiang___.reset__();
			lvzu___.reset__();
			bingqi___.reset__();
		上代码、www。
		装入阵图。
	了。
上代码。
隧道侦听、点击、open-zhentu、下代码
	open-zhentu-‘参数1’。
上代码。

隧道侦听、点击、play、下代码
	如果不存在阵图那么隧道点击、open-zhentu，退出。
	隧道webkit、插脚、start_=true、www。
	隧道可见、play、0。
	隧道可见、pause、1。
上代码。

隧道侦听、点击、pause、下代码
	隧道webkit、插脚、start_=false、www。
	隧道可见、pause、0。
	隧道可见、play、1。
上代码。

隧道侦听、点击、jiansu、zengsu、下代码
	赋予+以如果‘参数0’等于jiansu那么++否则--。
	隧道webkit、插脚、nvjiang_time_size_‘+’;if(nvjiang_time_size_<1)nvjiang_time_size_=1;、www。
上代码。

隧道侦听、点击、clear、下代码
	隧道可见、pref-win、0。
	隧道webkit、插脚、clear_layer__(select_layer_)、www。
上代码。

隧道侦听、点击、help、下代码
	打开网页‘参数1’。
上代码。

隧道webkit、焦点、www。
