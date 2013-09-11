/*
 * control___.h
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */

#ifndef CONTROL____H_
#define CONTROL____H_

#include <plugin_base___.h>
#include <webkit/webkit.h>
#include"page___.h"
#include"s1.h"

#define use_for_browse_ 0
#define use_for_download_ 1

#define control_page_cur_	-10000

class control___{
private:
	shell___*sh_;
	direct___ d_;
	Glib::ustring code_;
	Glib::ustring code2_[s1_length_];
	const char* zhao_;
	Glib::ustring dong_;
	Glib::ustring user_agent_;
	Gtk::Notebook* n_;
	WebKitWebView *new_wwv__(Gtk::ScrolledWindow* sw);
	void init__(std::deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao);
	bool zhenting_[s1_length_];
	void zhenting__(WebKitWebView *wwv);
	std::map<Gtk::ScrolledWindow*,page___*> page_;
	int use_;
	void switch_page__(GtkNotebookPage* page, guint page_num);
	control___* newmker_;
public:
	const Glib::ustring& name__(){return dong_;}
	control___(Gtk::ScrolledWindow* sw,std::deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao);
	control___(Gtk::Notebook* n,std::deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao);
	const char* suidao__(int i1,const char*s2=NULL,const char*s3=NULL,const char*s4=NULL);
	const char* suidao__(const char *code,const char*s1,const char*s2=NULL,const char*s3=NULL,const char*s4=NULL);
	const char* suidao__(int i1,void*shangji,int argc,char** argv);
	const char* suidao__(const char *code,void*shangji,const char *dong,const char *src2,int argc,const char**argv,int from);
	WebKitWebView* page__(WebKitWebView*& wwv);
	page___* page__(int i);
	WebKitWebView* wwv__(WebKitWebView* wwv,int i);
	void use_for_download__(){use_=use_for_download_;}
	void newmker__(control___* control){newmker_=control;}
};

control___*control__(const Glib::ustring&name);
page___* page__(const Glib::ustring&name,int i);
WebKitWebView* wwv__(const Glib::ustring&name,int i);
control___*control__(WebKitWebView*wwv);
//#ifdef ver_3_
void new_open__(const Glib::ustring& url,WebKitWebView* wwv);
//#endif
void mk_zs__(WebKitWebView* wwv);

#endif /* CONTROL____H_ */
