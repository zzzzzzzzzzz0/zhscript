/*
 * webkit_download___.cpp
 *
 *  Created on: 2013-4-6
 *      Author: zzzzzzzzzzz
 */

#include "webkit_download___.h"
#include "arg___.cpp"

#include "sh-base/extern.h"
#include <map>

class data___ {
public:
	string url_, file_, code_;
	WebKitWebView* wv_;
	arg___ arg_;
};

typedef map<string, data___*> set___;
static set___ set_;

static data___* get_data__(const char* url) {
	set___::iterator it = set_.find(url);
	if(it == set_.end()) {
		return NULL;
	} else {
		return (*it).second;
	}
}

bool webkit_download___::is_add__(WebKitWebView* wv) {
	for(set___::iterator it = set_.begin(); it != set_.end(); it++) {
		data___* d = it->second;
		if(d->wv_ == wv) {
			const string& url = it->first;
			if(gtk_object_get_data(GTK_OBJECT(wv), url.c_str()))
				return true;
		}
	}
	return false;
}

static void notify_status__(GObject* object, GParamSpec* pspec, gpointer data){
    WebKitDownload* download = WEBKIT_DOWNLOAD(object);
    data___* d = (data___*)data;
    WebKitDownloadStatus ls = webkit_download_get_status(download);
    switch (ls) {
    case WEBKIT_DOWNLOAD_STATUS_FINISHED:
    case WEBKIT_DOWNLOAD_STATUS_ERROR:
    case WEBKIT_DOWNLOAD_STATUS_CANCELLED:
    	d->arg_.ins__(d->file_);
        switch (ls) {
        case WEBKIT_DOWNLOAD_STATUS_CANCELLED:
        	d->arg_.ins__("cancel");
        	break;
        case WEBKIT_DOWNLOAD_STATUS_ERROR:
        	d->arg_.ins__("err");
        	break;
        default:
        	d->arg_.ins__("ok");
        	break;
        }
    	call4__(d->code_.c_str(),NULL,d->arg_.c__(),d->arg_.v__(),0);
    	set_.erase(d->url_);
    	gtk_object_remove_data(GTK_OBJECT(d->wv_), d->url_.c_str());
    	delete d;
        break;
    case WEBKIT_DOWNLOAD_STATUS_CREATED:
    case WEBKIT_DOWNLOAD_STATUS_STARTED:
    	break;
    }
}

static void notify_load_status__(WebKitWebView* web_view, GParamSpec* pspec, gpointer data){
	WebKitLoadStatus ls = webkit_web_view_get_load_status(web_view);
	printf("notify_load_status %d\n", ls);
	switch(ls) {
	case WEBKIT_LOAD_FINISHED:
		break;
	case WEBKIT_LOAD_FAILED:
		break;
	case WEBKIT_LOAD_PROVISIONAL:
	case WEBKIT_LOAD_COMMITTED:
	case WEBKIT_LOAD_FIRST_VISUALLY_NON_EMPTY_LAYOUT:
		break;
	}
}

static gboolean download_requested__(WebKitWebView* web_view,
                      WebKitDownload* download,
                      gpointer data)
{
	const gchar* uri1 = webkit_download_get_uri(download);
	data___* d = get_data__(uri1);
	if(!d)
		return FALSE;
    gchar *uri2 = g_filename_to_uri(d->file_.c_str(), NULL, NULL);
    if (uri2) {
        webkit_download_set_destination_uri(download, uri2);
        g_free(uri2);
    }
    g_signal_connect(download, "notify::status",G_CALLBACK(notify_status__), d);
    return TRUE;
}

static gboolean navigation_policy_decision_requested__(
		WebKitWebView* web_view,
		WebKitWebFrame* web_frame,
		WebKitNetworkRequest* request,
		WebKitWebNavigationAction* action,
		WebKitWebPolicyDecision* decision,
		gpointer data)
{
	webkit_web_policy_decision_download(decision);
	return TRUE;
}

static gboolean mime_type_policy_decision_requested__(
		WebKitWebView* view, WebKitWebFrame* frame,
		WebKitNetworkRequest* request, const char* mime_type,
		WebKitWebPolicyDecision* decision, gpointer data)
{
    webkit_web_policy_decision_download(decision);
    return TRUE;
}

void webkit_download___::signal__(WebKitWebView* wv) {
	g_signal_connect(wv, "navigation-policy-decision-requested",G_CALLBACK(navigation_policy_decision_requested__),NULL);
	g_signal_connect(wv, "download-requested",G_CALLBACK(download_requested__), NULL);
	g_signal_connect(wv, "notify::load-status",G_CALLBACK(notify_load_status__), NULL);
    g_signal_connect(wv, "mime-type-policy-decision-requested", G_CALLBACK(mime_type_policy_decision_requested__),NULL);
}

int webkit_download___::add__(WebKitWebView* wv, deque<string>* p) {
	size_t from = 2;
	if(p->size() < from + 3)
		return 1;
	if(!wv)
		return 2;
	const string& url	= (*p)[from++];
	const string& file	= (*p)[from++];
	const string& code	= (*p)[from++];
	data___* d = get_data__(url.c_str());
	if(!d) {
		set_[url] = (d = new data___());
		d->url_ = url;
	}
	d->file_ = file;
	d->code_ = code;
	d->wv_ = wv;
	d->arg_.clear__();
	for(size_t i = from; i < p->size(); i++)
		d->arg_.add__((*p)[i]);
	gtk_object_set_data(GTK_OBJECT(wv), url.c_str(), d);
	string js =
		"var a=document.createElement('a');"
		"a.setAttribute('href','" + url + "');"
		"a.setAttribute('target','_blank');"
		"var me=document.createEvent('MouseEvents');"
		"me.initEvent('click',true,false);"
		"a.dispatchEvent(me);";
	webkit_web_view_execute_script (wv, js.c_str());
	return 0;
}

webkit_download___::webkit_download___() {
}

webkit_download___::~webkit_download___() {
}
