赋予“库名”以“【库】‘参数0’”。
如果存在‘库名’那么退出。
赋予‘库名’以。
赋予“js函数集【库】【‘库名’】”以“
if(!window.cls__)
	window.cls__=
	function(id){
		return document.getElementsByClassName(id);
	};
if(!window.tag__)
	window.tag__=
	function(id){
		return document.getElementsByTagName(id);
	};
if(!window.__)
	window.__=
	function(id){
		if(typeof(id)!="string")
			return id;
		var e=document.getElementById(id);
		if(!e){
			var e1=cls__(id);
			if(e1)
				e=e1[0];
		}
		return e;
	};
if(!window.e__)
	window.e__=
	function(e){
		if(e){
			var e1;
			var a=arguments;
			for(var i=1;i<a.length;i++){
				var i1=a[i];
				e1=e.childNodes;
				if(i1>=e1.length)
					return undefined;
				e=e1[i1];
			}
		}
		return e;
	};
if(!window.test_e__)
	window.test_e__=
	function(e,i){
		if(i==undefined)
			i="";
		if(e){
			var e1=e.childNodes;
			if(e1){
				for(var i1=0;i1<e1.length;i1++){
					var e2=e1[i1];
					var s=i+","+i1;
					var t1=e2.id;
					if(t1)
						t1="(id="+t1+")";
					else{
						t1="";
					}
					var t2=e2.className;
					if(t2)
						t2="(class="+t2+")";
					else{
						t2="";
					}
					var t=e2.innerText;
					if(!t)
						t="";
					var t3=e2.tagName;
					if(t3){
						t3="("+t3+")";
						z$("",s,t3+t1+t2+t);
					}
					test_e__(e2,s);
				}
			}
		}
	};
if(!window.val__)
	window.val__=
	function(id,val){
		var e=__(id);
		if(e){
			if(val==undefined)
				return e.value;
			e.value=val;
		}
	};
if(!window.htm__)
	window.htm__=
	function(id,val){
		var e=__(id);
		if(e){
			if(val==undefined)
				return e.innerHTML;
			e.innerHTML=val;
		}
	};
if(!window.txt__)
	window.txt__=
	function(id,val){
		var e=__(id);
		if(e){
			if(val==undefined)
				return e.innerText;
			e.innerText=val;
		}
	};
if(!window.show__)
	window.show__=
	function(id,s){
		var e=__(id);
		if(e){
			if(!s){
				if(e.tagName=='DIV')
					s='block';
				else s='inline';
			}
			e.style.display=s;
		}
	};
if(!window.hide__)
	window.hide__=
	function(id){
		var e=__(id);
		if(e)
			e.style.display='none';
	};
if(!window.is_hide__)
	window.is_hide__=
	function(id){
		var e=__(id);
		if(e)
			return e.style.display=='none';
	};
if(!window.me__)
	window.me__=
	function(t,e){
		if(e){
			var evt=document.createEvent('MouseEvents'); 
			evt.initEvent(t,true,false); 
			e.dispatchEvent(evt);
		}
	};
if(!window.click__)
	window.click__=
	function(id){
		me__('click',__(id));
	};
if(!window.ke__)
	window.ke__=
	function(t,c,e){
		if(c&&e){
			var evt=document.createEvent("KeyboardEvent");
			var i=c.toString(16).toUpperCase();
			while(i.length<4)
				i='0'+i;
			i='U+'+i;
			evt.initKeyboardEvent(t,true,true,window,i,0,false,false,false,false);
			evt.charCode=c;
			if(t=='keypress')
				evt.keyCode=c;
			evt.synthetic=true;
			e.dispatchEvent(evt);
		}
	};
if(!window.press__)
	window.press__=
	function(id,c){
		if(c==undefined)
			c=13;
		ke__('keypress',c,__(id));
	};

if(!window.new__)
	window.new__=
	function(tag){
		return document.createElement(tag);
	};
if(!window.new_txt__)
	window.new_txt__=
	function(txt){
		return document.createTextNode(txt);
	};
if(!window.add__)
	window.add__=
	function(e,e2){
		if(e2)
			e2.appendChild(e); 
	};
if(!window.ins__)
	window.ins__=
	function(e,e2,i){
		if(e2){
			if(i==undefined)
				e2.parentNode.insertBefore(e,e2); 
			else{
				e2.insertBefore(e,e2.childNodes[i]); 
			}
		}
	};
if(!window.attr__)
	window.attr__=
	function(e,name,val){
		if(e){
			var attrs=e.attributes;
			if(attrs){
				var attr=attrs[name];
				if(attr){
					if(val==undefined)
						return attr.nodeValue;
					attr.nodeValue=val;
				}
			}
		}
	};
”。