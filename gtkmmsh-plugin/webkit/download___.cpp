/*
 * download___.cpp
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */
//#ifdef ver_3_
#include"download___.h"
#include"util.h"

map<Glib::ustring,download___*> dlnames_;

void notify_status__(GObject* object, GParamSpec* pspec, gpointer data){
    WebKitDownload* download = WEBKIT_DOWNLOAD(object);
    download___* dl=(download___*)data;
    int i=webkit_download_get_status(download);
    dl->status__(i);
    switch (i) {
    case WEBKIT_DOWNLOAD_STATUS_FINISHED:
    case WEBKIT_DOWNLOAD_STATUS_ERROR:
    case WEBKIT_DOWNLOAD_STATUS_CANCELLED:
    	delete dl;
        break;
    }
}

gboolean download_requested__(WebKitWebView* web_view,
                      WebKitDownload* download,
                      gpointer data)
{
	download___* dl=dlnames_[webkit_download_get_uri(download)];
    gchar *uri = g_filename_to_uri(dl->filename__(), NULL, NULL);
    if (uri)
        webkit_download_set_destination_uri(download, uri);
    g_free(uri);
    g_signal_connect(download, "notify::status",G_CALLBACK(notify_status__), dl);
    return TRUE;
}

gboolean navigation_policy_decision_requested__(WebKitWebView* web_view,
										WebKitWebFrame* web_frame,
										WebKitNetworkRequest* request,
										WebKitWebNavigationAction* action,
										WebKitWebPolicyDecision* decision,
										gpointer data)
{
	webkit_web_policy_decision_download(decision);
	return TRUE;
}

void zhenting_download__(WebKitWebView *wwv){
	g_signal_connect(wwv, "navigation-policy-decision-requested",G_CALLBACK(navigation_policy_decision_requested__),NULL);
	g_signal_connect(wwv, "download-requested",G_CALLBACK(download_requested__), NULL);
}

void new_download__(std::deque<Glib::ustring>* p,WebKitWebView *wwv){
	const Glib::ustring& url=(*p)[2];
	control___*c=control__(wwv);
	dlnames_[url]=new download___(p,c);
	c->use_for_download__();
	new_open__(url,wwv);
}

download___::download___(std::deque<Glib::ustring>* p,control___*c){
	c_=c;
	sdz_=(*p)[1];
	url_=(*p)[2];
	filename_=(*p)[3];
	if(p->size()>5)
		code_=(*p)[4];
	argc_=p->size()-6+2;
	argv_=new const char*[argc_];
	argv_[0]=arg0_;
	argv_[1]=filename_.c_str();
	for(int i=2;i<argc_;i++){
		const Glib::ustring& p5=(*p)[5+i-2];
		argv1_.push_back(p5);
		argv_[i]=argv1_[argv1_.size()-1].c_str();
	}
}

download___::~download___(){
	delete argv_;
}

const char* download___::status__(int i){
	l2s__(i,arg0_);
	int argc;
    switch (i) {
    case WEBKIT_DOWNLOAD_STATUS_FINISHED:
    case WEBKIT_DOWNLOAD_STATUS_ERROR:
    	argc=argc_;
    	break;
    default:
	    argc=1;
    }
	return c_->suidao__(code_.c_str(),NULL,sdz_.c_str(),sdz_.c_str(),argc,argv_,0);
}
//#endif
