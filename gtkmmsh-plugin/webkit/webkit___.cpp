/*
 * webkit___.cpp
 *
 *  Created on: 2010-12-30
 *      Author: zzzzzzzzzzz
 */

#include "webkit___.h"
#include"plugin_def.h"
#include"control___.h"
#include"download___.h"
#include"util.cpp"

void false__(char*buf){
	cpy__(buf,false_.c_str(),16);
}

#ifdef ver_3_
void webkit___::element__(WebKitWebView* wwv,std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji){
	size_t i2=p->size()-2;
	size_t start=2;
	Glib::ustring p1=(*p)[start];
	WebKitDOMDocument* dd = webkit_web_view_get_dom_document(wwv);
	WebKitDOMElement* e;
	if(p1=="内嵌页"){
		if(++start>=i2){
			d_(sh_,err_show_buzu_,1,p);
			return;
		}
		e= webkit_dom_document_get_element_by_id(dd, ((*p)[start++]).c_str());
		if(!e){
			false__(buf);
			return;
		}
		dd=webkit_dom_html_iframe_element_get_content_document(WEBKIT_DOM_HTML_IFRAME_ELEMENT(e));
		if(start>=i2){
			d_(sh_,err_show_buzu_,1,p);
			return;
		}
		p1=(*p)[start];
	}
	e=NULL;
	WebKitDOMNodeList* nl=NULL;
	if(p1.size()>2&&(p1[0]=='-'&&(p1[1]=='e'||p1[1]=='l'))){
		switch(p1[1]){
		case'e':
			e=(WebKitDOMElement*)s2l__(p1.substr(2));
			if(!e){
				d_(sh_,err_show_wufa_,2,p,start);
				return;
			}
			break;
		case'l':
			nl=(WebKitDOMNodeList*)s2l__(p1.substr(2));
			if(!nl){
				d_(sh_,err_show_wufa_,2,p,start);
				return;
			}
			break;
		}
	}else{
		e = webkit_dom_document_get_element_by_id(dd, p1.c_str());
		if(!e){
			for(;;){
				nl = webkit_dom_document_get_elements_by_name(dd, p1.c_str());
				if(nl&&webkit_dom_node_list_get_length(nl)>0)
					break;
				nl = webkit_dom_document_get_elements_by_class_name(dd, p1.c_str());
				if(nl&&webkit_dom_node_list_get_length(nl)>0)
					break;
				nl = webkit_dom_document_get_elements_by_tag_name(dd, p1.c_str());
				if(nl&&webkit_dom_node_list_get_length(nl)>0)
					break;
				const Glib::ustring& p2=(*p)[i2];
				if(p2=="有"){
					l2s__(0,buf);
				}else{
					false__(buf);
				}
				return;
			}
		}
	}
	size_t i=start+1;
	char sdz=0;
	for(;i<=i2;i++){
		const Glib::ustring& p2=(*p)[i];
		if(p2=="有"){
			l2s__(1,buf);
			return;
		}
		if(p2=="数目"){
			if(nl){
				cpy__(buf,webkit_dom_node_list_get_length(nl),siz);
				return;
			}
			if(e){
				WebKitDOMHTMLCollection*hc=webkit_dom_html_element_get_children((WebKitDOMHTMLElement*)e);
				cpy__(buf,webkit_dom_html_collection_get_length(hc),siz);
				return;
			}
			return;
		}
		if(p2=="得"){
			buf[0]='-';
			buf[1]=0;
			if(e){
				buf[1]='e';
				l2s__((long)e,buf+2);
				return;
			}
			if(nl){
				buf[1]='l';
				l2s__((long)nl,buf+2);
				return;
			}
			return;
		}
		if(p2=="内容")
			sdz='h';
		else if(p2=="文本")
			sdz='t';
		else if(p2=="属性")
			sdz='a';
		else if(p2=="签名")
			sdz='n';
		else if(p2=="传送")
			sdz='e';
		else if(p2=="样式")
			sdz='s';
		else if(p2=="焦点")
			sdz='f';
		else
			sdz=0;
		if(sdz){
			if(nl){
				WebKitDOMNode* dn= webkit_dom_node_list_item(nl, 0);
				e = (WebKitDOMElement*)dn;
			}
			break;
		}
		gulong idx=s2l__(p2)-1;
		if(nl){
			if(idx>=webkit_dom_node_list_get_length(nl)){
				false__(buf);
				return;
			}
			WebKitDOMNode* dn= webkit_dom_node_list_item(nl, idx);
			e = (WebKitDOMElement*)dn;
			nl=NULL;
			continue;
		}
		if(e){
			WebKitDOMHTMLCollection*hc=webkit_dom_html_element_get_children((WebKitDOMHTMLElement*)e);
			if(idx>=webkit_dom_html_collection_get_length(hc)){
				false__(buf);
				return;
			}
			WebKitDOMNode *dn = webkit_dom_html_collection_item(hc, idx);
			e=(WebKitDOMElement*)dn;
		}
	}
	if(!sdz){
		d_(sh_,err_show_wufa_,2,p,i2);
		return;
	}
	if(e){
		GError*error=NULL;
		switch(sdz){
		case'e':
		{
			if(i2-i<2){
				d_(sh_,err_show_buzu_,1,p);
				return;
			}
			WebKitDOMEvent*evt=webkit_dom_document_create_event(dd, (*p)[i2-1].c_str(), &error);
			if(!error){
				webkit_dom_event_init_event(evt, (*p)[i2].c_str(), true,false);
				webkit_dom_node_dispatch_event((WebKitDOMNode*)e, evt, &error);
			}
			break;
		}
		case'a':
			if(i2-i<1){
				d_(sh_,err_show_buzu_,1,p);
				return;
			}
			if(i<i2-1){
				webkit_dom_element_set_attribute(e, (*p)[i2-1].c_str(), (*p)[i2].c_str(), &error);
			}else{
				*addr_ret=dup__(webkit_dom_element_get_attribute(e, (*p)[i2].c_str()));
				/*WebKitDOMAttr* a=webkit_dom_element_get_attribute_node(e, (*p)[i2].c_str());
				*addr_ret=dup__(webkit_dom_attr_get_value(a));*/
			}
			break;
		case's':
		{
			if(i2-i<1){
				d_(sh_,err_show_buzu_,1,p);
				return;
			}
			WebKitDOMCSSStyleDeclaration *style = webkit_dom_element_get_style(e);
			for(;;){
				const gchar* property_name=NULL;
				const gchar* value=NULL;
				const gchar* priority=NULL;
				if(++i>i2)break;
				property_name=(*p)[i].c_str();
				if(++i<=i2)
					value=(*p)[i].c_str();
				if(++i<=i2)
					priority=(*p)[i].c_str();
				if(priority)
					webkit_dom_css_style_declaration_set_property(style, property_name, value, priority, &error);
				else{
					WebKitDOMCSSValue*cssv=webkit_dom_css_style_declaration_get_property_css_value(style, property_name);
					cpy__(buf,webkit_dom_css_value_get_css_text(cssv),siz);
				}
			}
			break;
		}
		case'f':
			webkit_dom_element_focus(e);
			break;
		default:
		{
			WebKitDOMHTMLElement*he=(WebKitDOMHTMLElement*)e;
			if(i<i2){
				const gchar*s=(*p)[i2].c_str();
				switch(sdz){
				case'h':
					webkit_dom_html_element_set_inner_html(he,s,&error);
					break;
				case't':
					webkit_dom_html_element_set_inner_text(he,s,&error);
					break;
				}
			}else{
				switch(sdz){
				case'h':
					*addr_ret=dup__(webkit_dom_html_element_get_inner_html(he));
					break;
				case't':
					*addr_ret=dup__(webkit_dom_html_element_get_inner_text(he));
					break;
				case'n':
					cpy__(buf,webkit_dom_element_get_tag_name(e),siz);
					break;
				}
			}
		}
		}
	    if (error != NULL) {
	    	std::cerr << error->message << std::endl;
	        g_clear_error(&error);
	    }
		return;
	}
}
#endif

int webkit___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		/*{for(size_t i=0;i<p->size();i++)
			cout<<"("<<i<<")"<<(*p)[i];
		cout<<endl;}*/
		if(p->size()<=2){
			d_(sh_,err_show_buzu_,p);
			return 1;
		}
		try{
			WebKitWebView *wwv;
			char sdz;
			const Glib::ustring&p1=(*p)[1];
			if(p1=="访问"){
				sdz='u';
			}else if(p1=="网址"){
				sdz='U';
			}else if(p1=="前进"){
				sdz='f';
			}else if(p1=="后退"){
				sdz='b';
			}else if(p1=="可前进"){
				sdz='F';
			}else if(p1=="可后退"){
				sdz='B';
			}else if(p1=="刷新"){
				sdz='r';
			}else if(p1=="插脚"||p1=="附加"){
				sdz='e';
			}else if(p1=="内容"){
				sdz=' ';
			}else if(p1=="标签提示"||p1=="标题提示"){
				sdz='T';
			}else if(p1=="标签"){
				sdz='l';
#ifdef ver_3_
			}else if(p1=="标题"){
				sdz='t';
			}else if(p1=="元素"){
				sdz='E';
#endif
			}else if(p1=="下载"){
				sdz='d';
			}else if(p1==s1_[create_web_view_]){
				sdz='n';
			}else if(p1=="粘贴"){
				sdz='p';
			}else if(p1=="加强"){
				sdz='z';
			}else if(p1=="目标"){
				sdz='@';
			}else if(p1=="焦点"){
				sdz='.';
			}else if(p1=="关闭"){
				sdz='X';
			}else{
				Gtk::ScrolledWindow* sw;
				sh_->builder_->get_widget((*p)[2], sw);
				if(sw){
					new control___(sw,p,sh_,d_,name__());
					return 1;
				}
				Gtk::Notebook* n;
				sh_->builder_->get_widget((*p)[2], n);
				if(n){
					new control___(n,p,sh_,d_,name__());
					return 1;
				}
				d_(sh_,err_show_wufa_,2,p,1);
				return 1;
			}
			size_t size_1=p->size()-1;
			{
				const Glib::ustring&p_1=(*p)[size_1];
				size_t i1=p_1.find('#');
				Glib::ustring name;
				int i;
				if(i1==string::npos){
					name=p_1;
					i=control_page_cur_;
				}else{
					name=p_1.substr(0,i1);
					i=s2i__(p_1.substr(i1+1),control_page_cur_);
					if(i>0)
						i--;
				}

				switch(sdz){
				case'T':
				case'l':
				case'X':
				{
					page___* page=page__(name,i);
					if(!page){
						false__(buf);
						return 1;
					}
					if(sdz=='X'){
						page->close__();
						return 1;
					}
					if(p->size()>3){
						const Glib::ustring &str=(*p)[2];
						switch(sdz){
						case'T':
							page->titletip__(str);
							break;
						case'l':
							page->title__(str);
							break;
						}
					}else{
						//const char*str;
						switch(sdz){
						case'T':
							//str=page->titletip__();
							page->titletip__(addr_ret);
							break;
						case'l':
							//str=page->title__();
							page->title__(addr_ret);
							break;
						}
						//*addr_ret=dup__(str);
					}
					return 1;
				}
				case'@':
					if(size_1<=2){
						d_(sh_,err_show_buzu_,p);
					}else{
						control___*c=control__(name);
						if(c){
							const Glib::ustring&p2=(*p)[2];
							if(p2=="")
								c->newmker__(NULL);
							else
								c->newmker__(control__(p2));
						}else{
							false__(buf);
						}
					}
					return 1;
				}

				wwv=(WebKitWebView*)wwv__(name,i);
			}
			if(!wwv){
				false__(buf);
				return 1;
			}
			switch(sdz){
			case'f':
				webkit_web_view_go_forward (wwv);
				return 1;
			case'b':
				webkit_web_view_go_back (wwv);
				return 1;
			case'F':
				l2s__(webkit_web_view_can_go_forward (wwv),buf);
				return 1;
			case'B':
				l2s__(webkit_web_view_can_go_back (wwv),buf);
				return 1;
			case'r':
				webkit_web_view_reload(wwv);
				return 1;
			case'U':
				*addr_ret=dup__(webkit_web_view_get_uri(wwv));
				return 1;
#ifdef ver_3_
			case't':
			{
				WebKitDOMDocument* dd = webkit_web_view_get_dom_document(wwv);
				if(p->size()>3){
					webkit_dom_document_set_title(dd, (*p)[2].c_str());
				}else{
					*addr_ret=dup__(webkit_dom_document_get_title(dd));
				}
				return 1;
			}
#endif
			case'n':
			{
				Glib::ustring url1;
				Glib::ustring& url=url1;
				if(p->size()<=3){
					url1="about:blank";
				}else
					url=(*p)[2];
				new_open__(url,wwv);
				return 1;
			}
			case'p':
				webkit_web_view_paste_clipboard(wwv);
				return 1;
			case'z':
				mk_zs__(wwv);
				return 1;
			case'.':
				gtk_widget_grab_focus((GtkWidget*)wwv);
				return 1;
			}
			if(p->size()<=3){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			switch(sdz){
			case'u':
				webkit_web_view_open (wwv, (*p)[2].c_str());
				return 1;
			case'e':
			{
				WebKitWebView *wwv2=wwv;
				for(size_t i=3;i<size_1;i++){
					const char* name=(*p)[i].c_str();
					WebKitWebFrame *wwf=webkit_web_view_get_main_frame(wwv2);
					WebKitWebFrame *wwf2=webkit_web_frame_find_frame(wwf,name);
					if(!wwf2){
#ifdef ver_3_
						WebKitDOMDocument* dd = webkit_web_view_get_dom_document(wwv2);
						WebKitDOMElement* e= webkit_dom_document_get_element_by_id(dd, name);
						if(!e){
							false__(buf);
							return 1;
						}
						webkit_dom_element_set_attribute(e, "name", name, NULL);
						wwf2=webkit_web_frame_find_frame(wwf,name);
#endif
						if(!wwf2){
							false__(buf);
							return 1;
						}
					}
					wwv2=webkit_web_frame_get_web_view(wwf2);
					if(!wwv2){
						false__(buf);
						return 1;
					}
				}
				webkit_web_view_execute_script (wwv2, (*p)[2].c_str());
				return 1;
			}
			case' ':
			{
				const gchar *base_uri=NULL;
                const gchar          *mime_type=NULL;//"text/html";
                const gchar          *encoding=NULL;//"UTF-8";
                const gchar          *s=(*p)[2].c_str();
				switch(p->size()){
				case 7:
					mime_type=(*p)[5].c_str();
				case 6:
					encoding=(*p)[4].c_str();
				case 5:
					base_uri=(*p)[3].c_str();
				}
				webkit_web_view_load_string(wwv,s,mime_type,encoding,base_uri);
				return 1;
			}
#ifdef ver_3_
			case'E':
				element__(wwv,p,buf,siz,addr_ret,shangji);
				return 1;
#endif
			}
			if(p->size()<=4){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			switch(sdz){
//#ifdef ver_3_
			case'd':
				new_download__(p,wwv);
				return 1;
//#endif
			}
		}catch(...){
			d_(sh_,err_show_wufa_,3,p,0,1);
			return 1;
		}
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new webkit___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
