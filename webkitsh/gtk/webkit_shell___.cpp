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

static s1___* navigation_requested_s1_ = new s1___("访问", "navigation-requested", 'w');
static s1___* create_web_view_s1_ = new s1___("新开", "create-web-view", 'w');
static s1___* title_changed_s1_  = new s1___("标题改变", "title-changed", 'w');
static s1___* hovering_over_link_s1_ = new s1___("覆盖链接", "hovering-over-link", 'w');
static s1___* load_progress_changed_s1_ = new s1___("装载进度", "load-progress-changed", 'w');
static s1___* load_committed_s1_ = new s1___("装载完", "load-committed", 'w');
static s1___* load_finished_s1_ = new s1___("装载完毕",	"load-finished",			'w');
static s1___* resource_request_starting_s1_ = new s1___("请求", "resource-request-starting", 'w');
static s1___* console_message_s1_ = new s1___("消息", "console-message", 'w');
static s1___* script_alert_s1_ = new s1___("警告", "script-alert", 'w');
static s1___* script_confirm_s1_ = new s1___("确认", "script-confirm", 'w');
static s1___* script_prompt_s1_ = new s1___("提问", "script-prompt", 'w');
static s1___* zhscript_s1_ = new s1___("zhscript:",	"", 0);

static string zhscript_ = zhscript_s1_->src2__();

static webkit_download___ down_;

static WebKitWebView* create_web_view__(WebKitWebView* page, WebKitWebFrame* frame){
	webkit_window___* w=webkit_window___::from__(page);
	WebKitWebView* wv;
	if(down_.is_add__(page)) {
		wv = w->tabpg_new__(NULL, true);
		down_.signal__(wv);
	} else {
		if(w->target_)
			wv=w->target_->webview__(notebook_current_page_);
		else
			wv=w->tabpg_new__(NULL, false);
		call4__(webkit_window___::scrolled_from__(page),w,create_web_view_s1_,0);
	}
	return wv;
}

static void hovering_over_link__(WebKitWebView* page, const gchar* title, const gchar* link, gpointer data){
	if (link){
		call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),hovering_over_link_s1_,2,link,title);
    }
}

static void title_changed__(WebKitWebView* page, WebKitWebFrame* frame, const gchar* title, gpointer data){
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),title_changed_s1_,1,title);
}

static void load_progress_changed__(WebKitWebView* page, gint progress, gpointer data){
	char s[16];
	l2s__(progress,s);
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),load_progress_changed_s1_,1,s);
}

static void load_committed__(WebKitWebView* page, WebKitWebFrame* frame, gpointer data){
	const gchar* uri = webkit_web_frame_get_uri(frame);
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),load_committed_s1_,1,uri);
}

static void load_finished__(WebKitWebView* page, WebKitWebFrame* frame, gpointer data){
	const gchar* uri = webkit_web_frame_get_uri(frame);
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),load_finished_s1_,1,uri);
}

static WebKitNavigationResponse navigation_requested__(WebKitWebView *page, WebKitWebFrame *frame, WebKitNetworkRequest *request){
	const gchar* uri = webkit_network_request_get_uri(request);
	if(uri){
		string uri1=uri;
		size_t i1=uri1.find(zhscript_);
		if(i1 != string::npos){
			call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page), zhscript_s1_, 1, uri + i1 + zhscript_.length());
			return WEBKIT_NAVIGATION_RESPONSE_IGNORE;
		}
	}
	return WEBKIT_NAVIGATION_RESPONSE_ACCEPT;
}

static gboolean console_message__(WebKitWebView* page,gchar*message,gint line,gchar*source_id,gpointer user_data){
	char s[16];
	l2s__(line,s);
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),console_message_s1_,3,message,s,source_id);
	return false;
}

static void resource_request_starting__(WebKitWebView*page,WebKitWebFrame*frame,WebKitWebResource*resource,WebKitNetworkRequest*request,WebKitNetworkResponse*response,gpointer user_data){
	const gchar* uri = webkit_network_request_get_uri(request);
	const char* ret=call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),resource_request_starting_s1_,1,uri);
	if(ret[0]=='x'){
		if(!ret[1])
			webkit_network_request_set_uri (request, webkit_web_frame_get_uri (frame));
		else if(ret[1]=='-')
			webkit_network_request_set_uri (request, ret+2);
	}
}

static gboolean script_alert__(
	WebKitWebView  *page,
	WebKitWebFrame *frame,
	gchar          *message,
	gpointer        user_data)
{
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),script_alert_s1_,1,message);
	return false;
}

static gboolean  script_confirm__                      (WebKitWebView  *page,
                                                        WebKitWebFrame *frame,
                                                        gchar          *message,
                                                        gpointer        confirmed,
                                                        gpointer        user_data)
{
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),script_confirm_s1_,1,message);
	return false;
}

static gboolean   script_prompt__                      (WebKitWebView  *page,
                                                        WebKitWebFrame *frame,
                                                        gchar          *message,
                                                        gchar          *default1,
                                                        gpointer        text,
                                                        gpointer        user_data)
{
	call4__(webkit_window___::scrolled_from__(page),webkit_window___::from__(page),script_prompt_s1_,2,message,default1);
	return false;
}

bool webkit_shell___::api__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	if(p->size()<1){
		err_buzu__();
		return true;
	}
	const string& p0=(*p)[0];
	if(p->size()<2){
		return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
	}
	const string& p1=(*p)[1];
	webkit_window___* w;
	int page_num;
	if(p1=="插脚"){
		if(p->size()<3){
			err_buzu__(p1.c_str());
			return true;
		}
		w=get_window__(p0,page_num,p1);if(!w)return true;
		webkit_web_view_execute_script (w->webview__(page_num), (*p)[2].c_str());
		return true;
	}
	if(p1=="内容"){
		if(p->size()<3){
			err_buzu__(p1.c_str());
			return true;
		}
		w=get_window__(p0,page_num,p1);if(!w)return true;
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
		webkit_web_view_load_string (w->webview__(page_num), (*p)[2].c_str(), mime_type, encoding, base_uri);
		return true;
	}
	if(p1=="访问"||p1==create_web_view_s1_->src2__()){
		string page_num2;
		w=get_window__(p0,page_num,p1, true, &page_num2);if(!w)return true;
		WebKitWebView* wv;
		if(p1==create_web_view_s1_->src2__()) {
			if(page_num2.empty() || w->page_check__(page_num) == notebook_page_no_){
				wv = w->tabpg_new__(page_num2.c_str(), false);
			}else
				wv = w->webview__(page_num);
		} else {
			if(page_num == notebook_page_no_)
				wv = NULL;
			else
				wv = w->webview__(page_num);
		}
		if(!wv) {
			err_wufa__(p1, p0.c_str());
			return true;
		}
		webkit_web_view_open (wv, p->size()>=3 ? (*p)[2].c_str() : "about:blank");
		return true;
	}
	if(p1=="下载"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		switch(down_.add__(w->webview__(page_num), p)) {
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
		w=get_window__(p0,page_num,p1);if(!w)return true;
		webkit_web_view_reload (w->webview__(page_num));
		return true;
	}
	if(p1=="前进"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		webkit_web_view_go_forward (w->webview__(page_num));
		return true;
	}
	if(p1=="后退"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		webkit_web_view_go_back (w->webview__(page_num));
		return true;
	}
	if(p1=="文件选择"){
		if(p->size() < 3) {
			err_buzu__(p1.c_str());
			return true;
		}
		w=get_window__(p0,page_num,p1);if(!w)return true;
		const string& type = (*p)[2];
		GtkFileChooserAction fca;
		const char* ok = GTK_STOCK_OPEN;
		if(type == "打开") {
			fca = GTK_FILE_CHOOSER_ACTION_OPEN;
		} else if(type == "保存") {
			fca = GTK_FILE_CHOOSER_ACTION_SAVE;
			ok = GTK_STOCK_SAVE;
		} else if(type == "文件夹") {
			fca = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
		} else if(type == "建立文件夹") {
			fca = GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
		} else {
			err_buzhichi__(type, p1.c_str());
			return true;
		}
		const string& title = (*p)[p->size() > 3 ? 3 : 2];
		GtkWidget *dialog = gtk_file_chooser_dialog_new (
				title.c_str(),
				w->window__(),
				fca,
				GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				ok,  GTK_RESPONSE_ACCEPT,
				NULL);
		GtkFileChooser* fc = GTK_FILE_CHOOSER (dialog);
		for(unsigned int i = 4; i < p->size(); i++) {
			const string& pi=(*p)[i];
			if(pi=="预选"){
				if(++i>=p->size()) {
					err_buzu__(p1.c_str());
					return true;
				}
				string& name=(*p)[i];
				if(name.length()>0){
					size_t i1=name.rfind('/');
					if(i1!=string::npos){
						gtk_file_chooser_set_current_folder(fc, name.substr(0,i1).c_str());
					}
					if(i1!=name.length()-1){
						gtk_file_chooser_set_filename(fc, name.c_str());
						gtk_file_chooser_select_filename(fc, name.c_str());
					}
				}
				continue;
			}
			if(pi=="类型"){
				if(++i>=p->size()) {
					err_buzu__(p1.c_str());
					return true;
				}
				GtkFileFilter* filter = gtk_file_filter_new();
				gtk_file_filter_set_name(filter, (*p)[i].c_str());
				if(++i>=p->size()) {
					err_buzu__(p1.c_str());
					return true;
				}
				gtk_file_filter_add_pattern(filter, (*p)[i].c_str());
				gtk_file_chooser_add_filter(fc, filter);
				continue;
			}
			if(pi == "覆盖确认") {
				gtk_file_chooser_set_do_overwrite_confirmation (fc, TRUE);
				continue;
			}
			err_buzhichi__(pi, p1.c_str());
			return true;
		}
		if (gtk_dialog_run (GTK_DIALOG (dialog)) ==  GTK_RESPONSE_ACCEPT)
		{
			char *filename = gtk_file_chooser_get_filename (fc);
			cpy__(buf, filename, siz);
			g_free (filename);
		}
		gtk_widget_destroy (dialog);
		return true;
	}
	if(p1=="目标"){
		if(p->size()<3){
			err_buzu__(p1.c_str());
			return true;
		}
		w=get_window__(p0,page_num,p1,false);if(!w)return true;
		webkit_window___* w2=get_window__((*p)[2],page_num,p1,false);if(!w2)return true;
		w->target_=w2;
		return true;
	}
	return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
}

window___* webkit_shell___::new_window__(const char*name, bool is_main) {
	return new webkit_window___(name, is_main);
}

webkit_window___* webkit_shell___::get_window__(const string& name,int& page_num,
		const string& help,bool chk_can, string* page_num2) {
	return (webkit_window___*)shell___::get_window__(name, page_num, help, chk_can, page_num2);
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
	console_message_s1_->cb_ = (G_CALLBACK(console_message__));
	script_alert_s1_->cb_ = (G_CALLBACK(script_alert__));
	script_confirm_s1_->cb_ = (G_CALLBACK(script_confirm__));
	script_prompt_s1_->cb_ = (G_CALLBACK(script_prompt__));
}
