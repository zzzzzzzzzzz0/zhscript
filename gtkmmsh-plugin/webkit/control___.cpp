/*
 * control___.cpp
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */
#include"control___.h"
#include"download___.h"
#include"plugin_def.h"
#include"util.h"

//#ifdef ver_3_
void new_open__(const Glib::ustring& url,WebKitWebView* wwv){
	Glib::ustring js;
	js=
		"var a=document.createElement('a');"//_x
		"a.setAttribute('href','"+url+"');"
		"a.setAttribute('target','_blank');"
		//"a.innerHTML='a';"
		//"var body=document.getElementsByTagName('body')[0];"
		//"body.appendChild(a);"
		"var me=document.createEvent('MouseEvents');"
		"me.initEvent('click',true,false);"
		"a.dispatchEvent(me);"
		;
	webkit_web_view_execute_script (wwv, js.c_str());
}
//#endif

map<WebKitWebView*,control___*> names_;
control___*control__(const Glib::ustring&name){
	map<WebKitWebView*,control___*>::iterator mi;
	for(mi=names_.begin();mi!=names_.end();mi++){
		control___* c=mi->second;
		if(c->name__()==name)
			return c;
	}
	return NULL;
}
page___* page__(const Glib::ustring&name,int i){
	control___* c=control__(name);
	if(c)
		return c->page__(i);
	return NULL;
}
WebKitWebView* wwv__(const Glib::ustring&name,int i){
	page___* page=page__(name,i);
	if(!page)
		return NULL;
	return page->wwv__();
}
control___*control__(WebKitWebView*wwv){
	return names_[wwv];
}

WebKitWebView* create_web_view__(WebKitWebView* page, WebKitWebFrame* frame){
	names_[page]->suidao__(create_web_view_/*,webkit_web_frame_get_uri(frame)*/);
	return names_[page]->page__(page);
}

void hovering_over_link__(WebKitWebView* page, const gchar* title, const gchar* link, gpointer data){
	if (link){
		names_[page]->suidao__(hovering_over_link_,link,title);
    }
}

void title_changed__(WebKitWebView* page, WebKitWebFrame* frame, const gchar* title, gpointer data){
	names_[page]->suidao__(title_changed_,title);
}

void load_progress_changed__(WebKitWebView* page, gint progress, gpointer data){
	char s[16];
	l2s__(progress,s);
	names_[page]->suidao__(load_progress_changed_,s);
}

void load_committed__(WebKitWebView* page, WebKitWebFrame* frame, gpointer data){
	const gchar* uri = webkit_web_frame_get_uri(frame);
   	names_[page]->suidao__((long)data,uri);
}

WebKitNavigationResponse navigation_requested__(WebKitWebView *page, WebKitWebFrame *frame, WebKitNetworkRequest *request){
	const gchar* uri = webkit_network_request_get_uri(request);
	//gchar *uri = g_uri_unescape_string (webkit_network_request_get_uri (request), NULL);
	if(uri){
		const Glib::ustring& zs=s1_[zhscript_];
		Glib::ustring uri1=uri;
		size_t i1=uri1.find(zs);
		if(i1!=string::npos){
			names_[page]->suidao__(zhscript_,uri+i1+zs.size());
			return WEBKIT_NAVIGATION_RESPONSE_IGNORE;
		}
	}
	//g_free (uri);
	return WEBKIT_NAVIGATION_RESPONSE_ACCEPT;
}

gboolean console_message__(WebKitWebView*page,gchar*message,gint line,gchar*source_id,gpointer user_data){
	char s[16];
	l2s__(line,s);
	names_[page]->suidao__(console_message_,message,s,source_id);
	return false;
}

/*gboolean mime_type_policy_decision_requested__(WebKitWebView*page,WebKitWebFrame*frame,WebKitNetworkRequest*request,gchar*mimetype,WebKitWebPolicyDecision*policy_decision,gpointer user_data){
	cout<<"mimetype="<<mimetype<<";"<<endl;
	return false;
}*/

void resource_request_starting__(WebKitWebView*page,WebKitWebFrame*frame,WebKitWebResource*resource,WebKitNetworkRequest*request,WebKitNetworkResponse*response,gpointer user_data){
	const gchar* uri = webkit_network_request_get_uri(request);
	const char* ret=names_[page]->suidao__(resource_request_starting_,uri);
	//g_str_has_suffix(uri, ".png")
	if(ret[0]=='x'){
		if(!ret[1])
			webkit_network_request_set_uri (request, webkit_web_frame_get_uri (frame));
		else if(ret[1]=='-')
			webkit_network_request_set_uri (request, ret+2);
	}
}

gboolean script_alert__(WebKitWebView  *webView,
	WebKitWebFrame *frame,
	gchar          *message,
	gpointer        user_data)
{
	names_[webView]->suidao__(script_alert_,message);
	return false;
}

gboolean            script_confirm__                      (WebKitWebView  *webView,
                                                        WebKitWebFrame *frame,
                                                        gchar          *message,
                                                        gpointer        confirmed,
                                                        gpointer        user_data)
{
	names_[webView]->suidao__(script_confirm_,message);
	return false;
}

gboolean            script_prompt__                      (WebKitWebView  *webView,
                                                        WebKitWebFrame *frame,
                                                        gchar          *message,
                                                        gchar          *default1,
                                                        gpointer        text,
                                                        gpointer        user_data)
{
	names_[webView]->suidao__(script_prompt_,message,default1);
	return false;
}

void control___::zhenting__(WebKitWebView *wwv){
	//g_signal_connect(G_OBJECT(wwv), "mime-type-policy-decision-requested", G_CALLBACK (mime_type_policy_decision_requested__), NULL);
	switch(use_){
	case use_for_browse_:
		g_signal_connect(G_OBJECT(wwv), "navigation-requested", G_CALLBACK(navigation_requested__), NULL);
		g_signal_connect(G_OBJECT(wwv), "create-web-view", G_CALLBACK(create_web_view__), NULL);
		for(int i1=0;i1<s1_length_;i1++){
			if(zhenting_[i1]){
				switch(i1){
				case title_changed_:
					g_signal_connect (G_OBJECT (wwv), "title-changed", G_CALLBACK (title_changed__), NULL);
					break;
				case load_progress_changed_:
					g_signal_connect (G_OBJECT (wwv), "load-progress-changed", G_CALLBACK (load_progress_changed__), NULL);
					break;
				case load_committed_:
					g_signal_connect (G_OBJECT (wwv), "load-committed", G_CALLBACK (load_committed__), (gpointer)load_committed_);
					break;
				case load_finished_:
					g_signal_connect (G_OBJECT (wwv), "load-finished", G_CALLBACK (load_committed__), (gpointer)load_finished_);
					break;
				case hovering_over_link_:
					g_signal_connect (G_OBJECT (wwv), "hovering-over-link", G_CALLBACK (hovering_over_link__), NULL);
					break;
				case console_message_:
					g_signal_connect (G_OBJECT (wwv), "console-message", G_CALLBACK (console_message__), NULL);
					break;
				case resource_request_starting_:
					g_signal_connect(G_OBJECT(wwv), "resource-request-starting", G_CALLBACK (resource_request_starting__), NULL);
					break;
				case script_alert_:
					g_signal_connect (G_OBJECT (wwv), "script-alert", G_CALLBACK (script_alert__), NULL);
					break;
				case script_confirm_:
					g_signal_connect (G_OBJECT (wwv), "script-confirm", G_CALLBACK (script_confirm__), NULL);
					break;
				case script_prompt_:
					g_signal_connect (G_OBJECT (wwv), "script-prompt", G_CALLBACK (script_prompt__), NULL);
					break;
				}
			}
		}
		break;
//#ifdef ver_3_
	case use_for_download_:
		zhenting_download__(wwv);
		use_=use_for_browse_;
		break;
//#endif
	}
}

void control___::init__(std::deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao){
	use_=use_for_browse_;
	newmker_=NULL;

	sh_=sh;
	d_=d;
	zhao_=zhao;
	dong_=(*p)[1];
	for(int i=0;i<s1_length_;i++)
		zhenting_[i]=false;
	for(size_t i=3;i<p->size();i++){
		const Glib::ustring&pi=(*p)[i];
		char c;
		if(pi=="代码"){
			c='c';
		}else if(pi=="侦听"){
			c='l';
		}else if(pi=="user-agent"){
			c='u';
		}else if(pi.empty()){
			continue;
		}else{
			d_(sh_,err_show_buzhichi_,2,p,i);
			break;
		}
		if(++i>=p->size()){
			d_(sh_,err_show_buzu_,p);
			break;
		}
		switch(c){
		case'c':
			code_=(*p)[i];
			continue;
		case'l':
		{
			int i1=0;
			for(;i1<s1_length_;i1++){
				if((*p)[i]==s1_[i1]){
					zhenting_[i1]=true;
					if(++i<p->size())
						code2_[i1]=(*p)[i];
					break;
				}
			}
			if(i1==s1_length_)
				d_(sh_,err_show_buzhichi_,2,p,i);
			continue;
		}
		case'u':
			user_agent_=(*p)[i];
			continue;
		}
	}
}

WebKitWebView *control___::new_wwv__(Gtk::ScrolledWindow* sw){
	WebKitWebView *wwv = WEBKIT_WEB_VIEW(webkit_web_view_new());
	g_object_ref_sink(G_OBJECT(wwv));
	switch(use_){
	case use_for_browse_:
		names_[wwv]=this;
		if(!sw){
			sw=Gtk::manage(new Gtk::ScrolledWindow());
		}
		page_[sw]=new page___(page_.size(),n_,wwv,sw);
		break;
	}

	if(!user_agent_.empty()){
		WebKitWebSettings* wws=webkit_web_view_get_settings(wwv);
		WebKitWebSettings* wws2;
		//wws2=wws;
		wws2=webkit_web_settings_copy(wws);
		//wws2=(WebKitWebSettings*)webkit_web_settings_new();
		g_object_set((GObject*)wws2, "user-agent", user_agent_.c_str(), NULL);
		webkit_web_view_set_settings(wwv,wws2);
	}

	zhenting__(wwv);
	return wwv;
}

control___::control___(Gtk::ScrolledWindow* sw,std::deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao){
	n_=NULL;
	init__(p,sh,d,zhao);
	new_wwv__(sw);
	sw->show_all_children ();
}

control___::control___(Gtk::Notebook* n,std::deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao){
	n_=n;
	n_->signal_switch_page().connect(sigc::mem_fun(*this,&control___::switch_page__) );
	init__(p,sh,d,zhao);
	new_wwv__(NULL);
	n->set_data("ctl",this);
}

void control___::switch_page__(GtkNotebookPage* page, guint page_num){
	if(zhenting_[switch_page_]){
		char s[16];
		suidao__(switch_page_,l2s__(page_num+1,s));
	}
}

WebKitWebView* control___::page__(WebKitWebView*& wwv){
	if(newmker_){
		WebKitWebView* c=newmker_->page__(wwv);
		//newmker_=NULL;
		return c;
	}
	if(!n_)
		return wwv;
	return new_wwv__(NULL);
}

page___* control___::page__(int i){
	if(n_){
		switch(i){
		case control_page_cur_:
			i=n_->get_current_page();
			break;
		default:
			if(i<0)
				i+=n_->get_n_pages();
			if(i>=0&&i<n_->get_n_pages())
				break;
			return NULL;
		}
		Gtk::ScrolledWindow* sw=(Gtk::ScrolledWindow*)n_->get_nth_page(i);
		/*Glib::ListHandle<Gtk::Widget*> ls=sw->get_children();
		for(Glib::ListHandle<Gtk::Widget*>::const_iterator i=ls.begin();i!=ls.end();i++){
			Gtk::Widget*w=*i;
			cout<<w->get_name()<<endl;
		}*/
		return page_[sw];
	}
	return page_.begin()->second;
}

WebKitWebView* control___::wwv__(WebKitWebView* wwv,int i){
	if(!n_||i==0)
		return wwv;
	page___* page=page__(i);
	if(!page)
		return NULL;
	return page->wwv__();
}

const char* control___::suidao__(const char *code,const char*s1,const char*s2,const char*s3,const char*s4){
	if(!code[0]){
		code=code_.c_str();
		//if(s4)
			return d_(sh_,on_,code,NULL,6,zhao_,dong_.c_str(),s1,s2,s3,s4);
		/*if(s3)
			return d_(sh_,on_,code,NULL,5,zhao_,dong_.c_str(),s1,s2,s3);
		if(s2)
			return d_(sh_,on_,code,NULL,4,zhao_,dong_.c_str(),s1,s2);
		if(s1)
			return d_(sh_,on_,code,NULL,3,zhao_,dong_.c_str(),s1);*/
	}else{
		//if(s4)
			return d_(sh_,on_,code,NULL,5,dong_.c_str(),s1,s2,s3,s4);
		/*if(s3)
			return d_(sh_,on_,code,NULL,4,zhao_,dong_.c_str(),s2,s3);
		if(s2)
			return d_(sh_,on_,code,NULL,3,zhao_,dong_.c_str(),s2);*/
	}
	//return d_(sh_,on_,code,NULL,2,zhao_,dong_.c_str());
}

const char* control___::suidao__(int i1,const char*s2,const char*s3,const char*s4){
	return suidao__(code2_[i1].c_str(),s1_[i1].c_str(),s2,s3,s4);
}

const char* control___::suidao__(const char *code,void*shangji,const char *dong,
		const char *src2,
		int argc,const char**argv,int from){
	return d_(sh_,call4_,code,NULL,zhao_,dong,src2,argc,argv,from);
}

const char* control___::suidao__(int i1,void*shangji,int argc,char** argv){
	const char *code=code2_[i1].c_str();
	const char**argv1=(const char**)argv;
	const char *src2=s1_[i1].c_str();
	const char *dong=dong_.c_str();
	if(code[0])
		return suidao__(code,shangji,dong,src2,argc,argv1,1);
	code=code_.c_str();
	if(argv1){
		argv1[0]=src2;
		return suidao__(code,shangji,dong,src2,argc,argv1,0);
	}
	return d_(sh_,on_,code,shangji,3,zhao_,dong,src2);
}

#include <JavaScriptCore/JavaScript.h>

map<JSContextRef,WebKitWebView*> jscr2wwv_;

WebKitWebView* wwv__(JSContextRef     js_context){
	WebKitWebView* wwv2=jscr2wwv_[js_context];
	if(!wwv2){
		map<WebKitWebView*,control___*>::iterator mi;
		JSObjectRef or1 = JSContextGetGlobalObject(js_context);
		for(mi=names_.begin();mi!=names_.end();mi++){
			WebKitWebView* wwv=mi->first;
			WebKitWebFrame *wwf=webkit_web_view_get_main_frame(wwv);
			if(wwf){
				JSGlobalContextRef gcr=webkit_web_frame_get_global_context(wwf);
				if(gcr){
					JSObjectRef or2=JSContextGetGlobalObject(gcr);
					if(or1==or2){
						jscr2wwv_[js_context]=wwv2=wwv;
						break;
					}
				}
			}
		}
	}
	return wwv2;
}

static JSValueRef
zs__ (JSContextRef     js_context,
                     JSObjectRef      js_function,
                     JSObjectRef      js_this,
                     size_t           argument_count,
                     const JSValueRef js_arguments[],
                     JSValueRef*      js_exception)
{
	//JSValueGetType (js_context, js_arguments[0]) == kJSTypeBoolean

	WebKitWebView* wwv2=wwv__(js_context);
	if(!wwv2){
		//JSValueMakeUndefined
		return JSValueMakeNull (js_context);
	}

	const char*ret;
	void*shangji=NULL;
	if(argument_count>0){
		JSStringRef* jsr=new JSStringRef[argument_count];
		char** argv=new char*[1+argument_count];
		for(size_t i=0;i<argument_count;i++){
			jsr[i]=JSValueToStringCopy(js_context, js_arguments[i], js_exception);
			size_t jsSize = JSStringGetMaximumUTF8CStringSize(jsr[i]);
			argv[1+i]=new char[jsSize];
			JSStringGetUTF8CString(jsr[i], argv[1+i], jsSize);
		}
		ret=names_[wwv2]->suidao__(zs_,shangji,1+argument_count,argv);
		for(size_t i=0;i<argument_count;i++){
			delete argv[1+i];
			JSStringRelease(jsr[i]);
		}
		delete jsr;
		delete argv;
	}else{
		ret=names_[wwv2]->suidao__(zs_,shangji,0,NULL);
	}

	JSValueRef ret2;
	if(true_==ret||false_==ret){
		ret2=JSValueMakeBoolean(js_context,true_==ret);
	}else{
		JSStringRef ret1=JSStringCreateWithUTF8CString(ret);
		ret2=JSValueMakeString(js_context,ret1);
		JSStringRelease (ret1);
	}
	return ret2;
}

void mk_zs__(WebKitWebView* wwv){
	WebKitWebFrame* web_frame;
	JSGlobalContextRef js_context;
	JSObjectRef js_global;
	JSStringRef js_function_name;
	JSObjectRef js_function;
	web_frame = webkit_web_view_get_main_frame (WEBKIT_WEB_VIEW (wwv));
	js_context = webkit_web_frame_get_global_context (web_frame);
	js_global = JSContextGetGlobalObject (js_context);
	js_function_name = JSStringCreateWithUTF8CString (s1_[zs_].c_str());
	js_function = JSObjectMakeFunctionWithCallback (js_context,
			js_function_name, zs__);
	JSObjectSetProperty (js_context, js_global, js_function_name, js_function,
			kJSPropertyAttributeNone, NULL);
	JSStringRelease (js_function_name);
}
