/*
 * webkit_shell___.cpp
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#include "webkit_shell___.h"
#include "sh-base/s1___.h"
#include "sh-base/extern.h"
#include "sh-base/extern2.h"
#include "webkit_download___.h"

static s1___* navigation_requested_s1_ = new s1___("访问", "navigation-requested", 'v');
static s1___* create_web_view_s1_ = new s1___("新开", "create-web-view", 'v');
static s1___* title_changed_s1_  = new s1___("标题改变", "title-changed", 'v');
static s1___* hovering_over_link_s1_ = new s1___("覆盖链接", "hovering-over-link", 'v');
static s1___* load_progress_changed_s1_ = new s1___("装载进度", "load-progress-changed", 'v');
static s1___* load_committed_s1_ = new s1___("装载完", "load-committed", 'v');
static s1___* load_finished_s1_ = new s1___("装载完毕",	"load-finished",			'v');
static s1___* resource_request_starting_s1_ = new s1___("请求", "resource-request-starting", 'v');
static s1___* mime_type_policy_decision_requested_s1_ = new s1___("类型请求", "mime-type-policy-decision-requested", 'v');
//static s1___* run_file_chooser_s1_ = new s1___("上传请求", "run-file-chooser", 'v');
static s1___* console_message_s1_ = new s1___("消息", "console-message", 'v');
static s1___* script_alert_s1_ = new s1___("警告", "script-alert", 'v');
static s1___* script_confirm_s1_ = new s1___("确认", "script-confirm", 'v');
static s1___* script_prompt_s1_ = new s1___("提问", "script-prompt", 'v');
static s1___* zhscript_s1_ = new s1___("zhscript:",	"", ' ');

static string zhscript_ = zhscript_s1_->src2__();

static webkit_download___ down_;

static GtkWidget* widget__(WebKitWebView* page) {
	return webkit_view___::scrolled_from__(page);
}
static window___* window__(view___* v) {
	return (window___*)v->window__();
}
static window___* window__(WebKitWebView* page) {
	return window__(webkit_view___::from__(page));
}

static WebKitWebView* create_web_view__(WebKitWebView* page, WebKitWebFrame* frame){
	webkit_view___* v=(webkit_view___*)webkit_view___::from__(page);
	WebKitWebView* wv;
	if(down_.is_add__(page)) {
		wv = (WebKitWebView*)webkit_web_view_new ();
		down_.signal__(wv);
	} else {
		webkit_view___* v2;
		if(v->target_)
			v2=(webkit_view___*)v->target_;
		else {
			window___* w = window__(v);
			v2=(webkit_view___*)shell___::new_page__(NULL, w);
			if(!v2)
				v2 = (webkit_view___*)w->view__(0);
		}
		wv=v2->webview__();
		string name2;
		window___* w2 = window__(wv);
		w2->name2__(name2, widget__(wv));
		const char* ret=call4__(widget__(page),window__(page),create_web_view_s1_,1,name2.c_str());
		if(ret[0]=='x' && !ret[1]) {
			if(!v->target_) {
				w2->c__()->close__(wv);
			}
			wv = NULL;
		}
	}
	return wv;
}

static void hovering_over_link__(WebKitWebView* page, const gchar* title, const gchar* link, gpointer data){
	if (link){
		call4__(widget__(page),window__(page),hovering_over_link_s1_,2,link,title);
    }
}

static void title_changed__(WebKitWebView* page, WebKitWebFrame* frame, const gchar* title, gpointer data){
	call4__(widget__(page),window__(page),title_changed_s1_,1,title);
}

static void load_progress_changed__(WebKitWebView* page, gint progress, gpointer data){
	char s[16];
	l2s__(progress,s);
	call4__(widget__(page),window__(page),load_progress_changed_s1_,1,s);
}

static void load_committed__(WebKitWebView* page, WebKitWebFrame* frame, gpointer data){
	const gchar* uri = webkit_web_frame_get_uri(frame);
	call4__(widget__(page),window__(page),load_committed_s1_,1,uri);
}

static void load_finished__(WebKitWebView* page, WebKitWebFrame* frame, gpointer data){
	const gchar* uri = webkit_web_frame_get_uri(frame);
	call4__(widget__(page),window__(page),load_finished_s1_,1,uri);
}

static WebKitNavigationResponse navigation_requested__(WebKitWebView *page, WebKitWebFrame *frame, WebKitNetworkRequest *request){
	const gchar* uri = webkit_network_request_get_uri(request);
	if(uri){
		string uri1=uri;
		size_t i1=uri1.find(zhscript_);
		if(i1 != string::npos){
			call4__(widget__(page),window__(page), zhscript_s1_, 1, uri + i1 + zhscript_.length());
			return WEBKIT_NAVIGATION_RESPONSE_IGNORE;
		}
	}
	return WEBKIT_NAVIGATION_RESPONSE_ACCEPT;
}

static gboolean console_message__(WebKitWebView* page,gchar*message,gint line,gchar*source_id,gpointer user_data){
	char s[16];
	l2s__(line,s);
	call4__(widget__(page),window__(page),console_message_s1_,3,message,s,source_id);
	return false;
}

static void resource_request_starting__(WebKitWebView*page,WebKitWebFrame*frame,WebKitWebResource*resource,WebKitNetworkRequest*request,WebKitNetworkResponse*response,gpointer user_data){
	const gchar* uri = webkit_network_request_get_uri(request);
	const char* ret=call4__(widget__(page),window__(page),resource_request_starting_s1_,1,uri);
	if(ret[0]=='x'){
		if(!ret[1])
			webkit_network_request_set_uri (request, webkit_web_frame_get_uri (frame));
		else if(ret[1]=='-')
			webkit_network_request_set_uri (request, ret+2);
	}
}

static gboolean mime_type_policy_decision_requested__(
		WebKitWebView* page, WebKitWebFrame* frame,
		WebKitNetworkRequest* request, const char* mime_type,
		WebKitWebPolicyDecision* decision, gpointer data)
{
	const gchar* uri = webkit_network_request_get_uri(request);
	const char* ret = call4__(widget__(page), window__(page),
			mime_type_policy_decision_requested_s1_, 3, mime_type, uri,
			webkit_web_view_can_show_mime_type(page, mime_type) ? "1" : "0");
	if(ret[0] == 'x' && !ret[1]) {
		webkit_web_policy_decision_ignore(decision);
		return true;
	}
    return false;
}

/*static gboolean run_file_chooser__(WebKitWebView*, WebKitFileChooserRequest* request, gpointer data)
	return false;
}*/

static gboolean script_alert__(
	WebKitWebView  *page,
	WebKitWebFrame *frame,
	gchar          *message,
	gpointer        user_data)
{
	call4__(widget__(page),window__(page),script_alert_s1_,1,message);
	return false;
}

static gboolean  script_confirm__                      (WebKitWebView  *page,
                                                        WebKitWebFrame *frame,
                                                        gchar          *message,
                                                        gpointer        confirmed,
                                                        gpointer        user_data)
{
	call4__(widget__(page),window__(page),script_confirm_s1_,1,message);
	return false;
}

static gboolean   script_prompt__                      (WebKitWebView  *page,
                                                        WebKitWebFrame *frame,
                                                        gchar          *message,
                                                        gchar          *default1,
                                                        gpointer        text,
                                                        gpointer        user_data)
{
	call4__(widget__(page),window__(page),script_prompt_s1_,2,message,default1);
	return false;
}

bool webkit_shell___::api__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	if(p->size() >= 2){
		const string& p0=(*p)[0];
		const string& p1=(*p)[1];
		webkit_view___* v;
		int page_num;
		if(p1=="插脚"){
			if(err_buzu2__(p, 3))
				return true;
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			webkit_web_view_execute_script (v->webview__(), (*p)[2].c_str());
			return true;
		}
		if(p1=="网址"){
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			*addr_ret=dup__(webkit_web_view_get_uri(v->webview__()));
			return true;
		}
		if(p1=="内容"){
			if(err_buzu2__(p, 3))
				return true;
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			const char*base_uri=NULL;
			const char*mime_type=NULL;//"text/html";
			const char*encoding=NULL;//"utf-8";
			for(size_t i=3;i<p->size();){
				const string& p3=(*p)[i++];
				if(i<p->size()){
					const string& p4=(*p)[i++];
					if(p3=="基址"){
						base_uri=p4.c_str();
						continue;
					}
					if(p3=="编码"){
						encoding=p4.c_str();
						continue;
					}
					if(p3=="类型"){
						mime_type=p4.c_str();
						continue;
					}
				}
				err_buzhichi__(p3,p1.c_str());
				return true;
			}
			webkit_web_view_load_string (v->webview__(), (*p)[2].c_str(), mime_type, encoding, base_uri);
			return true;
		}
		if(p1=="访问"||p1==create_web_view_s1_->src2__()){
			string page_num2;
			WebKitWebView* wv;
			if(p1==create_web_view_s1_->src2__()) {
				window___* w=get_window__(p0,page_num,p1, true, &page_num2);if(!w)return true;
				v=(webkit_view___*)w->view__(page_num);
				if(page_num2.empty() || !v){
					v=(webkit_view___*)new_page__(page_num2.c_str(), w);
					if(!v)
						wv = NULL;
					else
						wv = v->webview__();
				}else{
					w->c__()->set_page__(page_num);
					wv = v->webview__();
				}
			} else {
				v=(webkit_view___*)get_view__(p0,page_num,p1, true, &page_num2);if(!v)return true;
				if(page_num == notebook_page_no_)
					wv = NULL;
				else
					wv = v->webview__();
			}
			if(!wv) {
				err_wufa__(p1, p0.c_str());
				return true;
			}
			webkit_web_view_open (wv, p->size()>=3 ? (*p)[2].c_str() : "about:blank");
			return true;
		}
		if(p1=="下载"){
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			switch(down_.add__(v->webview__(), p)) {
			case 1:
				err_buzu__(p1.c_str());
				return true;
			case 2:
				err_wufa__(p1, p0.c_str());
				return true;
			}
			return true;
		}
		if(p1=="刷新"){
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			webkit_web_view_reload (v->webview__());
			return true;
		}
		if(p1=="前进"){
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			webkit_web_view_go_forward (v->webview__());
			return true;
		}
		if(p1=="后退"){
			v=(webkit_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			webkit_web_view_go_back (v->webview__());
			return true;
		}
		if(p1=="目标"){
			if(err_buzu2__(p, 3))
				return true;
			v=(webkit_view___*)get_view__(p0,page_num,p1,false);if(!v)return true;
			webkit_view___* v2=(webkit_view___*)get_view__((*p)[2],page_num,p1,false);if(!v2)return true;
			v->target_=v2;
			return true;
		}
		if(p1=="user-agent"){
			webkit_view___::user_agent_ = p0;
			return true;
		}
		if(p1=="代理") {
			SoupURI *proxyUri = soup_uri_new(p0.c_str());
			g_object_set(webkit_get_default_session(), SOUP_SESSION_PROXY_URI, proxyUri, NULL);
			soup_uri_free(proxyUri);
			return true;
		}
	}
	return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
}

view___* webkit_shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	return new webkit_view___(scrolled2, window, window->is_app_paintable__());
}

webkit_shell___::webkit_shell___() {
	navigation_requested_s1_->cb_ = (G_CALLBACK(navigation_requested__));
	create_web_view_s1_->cb_ = (G_CALLBACK(create_web_view__));
	title_changed_s1_->cb_ = (G_CALLBACK(title_changed__));
	hovering_over_link_s1_->cb_ = (G_CALLBACK(hovering_over_link__));
	load_progress_changed_s1_->cb_ = (G_CALLBACK(load_progress_changed__));
	load_committed_s1_->cb_ = (G_CALLBACK(load_committed__));
	load_finished_s1_->cb_ = (G_CALLBACK(load_finished__));
	resource_request_starting_s1_->cb_ = (G_CALLBACK(resource_request_starting__));
	mime_type_policy_decision_requested_s1_->cb_ = (G_CALLBACK(mime_type_policy_decision_requested__));
	//run_file_chooser_s1_->cb_ = (G_CALLBACK(run_file_chooser__));
	console_message_s1_->cb_ = (G_CALLBACK(console_message__));
	script_alert_s1_->cb_ = (G_CALLBACK(script_alert__));
	script_confirm_s1_->cb_ = (G_CALLBACK(script_confirm__));
	script_prompt_s1_->cb_ = (G_CALLBACK(script_prompt__));
}
