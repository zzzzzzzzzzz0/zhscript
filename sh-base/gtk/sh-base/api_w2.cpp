/*
 * api_w_e.cpp
 *
 *  Created on: 2016年2月13日
 *      Author: zzzzzzzzzzz
 */
#include "shell___.h"
#include "extern.h"
#include "extern2.h"

extern s1___* new_window_s1_;

class event___ {
public:
	string code_, name_;
	gboolean b_;
};
static gboolean event_mouse__(GtkWidget *widget, GdkEventButton *event, gpointer data) {
	event___* e = (event___*)data;
	char s1[32], s2[32], s3[32];
	sprintf(s1, "%d", event->button);
	sprintf(s2, "%.2f", event->x);
	sprintf(s3, "%.2f", event->y);
	const char* a[] = {s1, s2, s3};
	call4__(e->code_.c_str(), e->name_.c_str(), 3, a, 0);
	return e->b_;
}
static gboolean event_key__(GtkWidget *widget, GdkEventKey *event, gpointer data) {
	event___* e = (event___*)data;
	const char* a[] = {gdk_keyval_name(event->keyval)};
	call4__(e->code_.c_str(), e->name_.c_str(), 1, a, 0);
	return e->b_;
}
static gboolean event_other__(GtkWidget *widget, GdkEvent *event, gpointer data) {
	event___* e = (event___*)data;
	call4__(e->code_.c_str(), e->name_.c_str(), 0, NULL, 0);
	return e->b_;
}

bool shell___::api_w2__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	const string& p0=(*p)[0];
	const string& p1=(*p)[1];
	window___* w;
	int page_num;

	if(p1=="加钮"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		char clicked=' ';
		GtkIconSize size=GTK_ICON_SIZE_MENU;
		const char *name=NULL,*iconame, *code = NULL, *code1 = NULL;
		bool is_focus = false;
		for(size_t i=2;i<p->size();i++){
			const string& p2=(*p)[i];
			if(p2=="点有焦点"){
				clicked='f';
				continue;
			}
			if(p2=="点无焦点"){
				clicked=' ';
				continue;
			}
			if(p2=="焦点"){
				is_focus = true;
				continue;
			}
			if(p2=="大小"){
				if(err_buzu2__(p, ++i))
					return true;
				size=(GtkIconSize)s2i__((*p)[i]);
				continue;
			}
			if(p2=="名"){
				if(err_buzu2__(p, ++i))
					return true;
				name=(*p)[i].c_str();
				continue;
			}
			if(p2=="代码"){
				if(err_buzu2__(p, ++i))
					return true;
				code=(*p)[i].c_str();
				continue;
			}
			if(p2 == "缺省代码") {
				if(err_buzu2__(p, ++i))
					return true;
				code1 = (*p)[i].c_str();
				if(!code1[0])
					code1 = NULL;
				continue;
			}
			iconame=p2.c_str();
			if(!name)
				name=iconame;
			GtkWidget* btn = w->c__()->button_new__(page_num,name,iconame,size, code ? code : code1,clicked);
			if(!btn) {
				err_wufa__(p1,p0.c_str());
				return true;
			}
			if(is_focus) {
				gtk_widget_grab_focus(btn);
				is_focus = false;
			}
			code = name = NULL;
		}
		return true;
	}
	if(p1=="侦听" || p1=="加侦听"){
		w=get_window__(p0,page_num,p1,false);if(!w)return true;
		bool is_add = p1=="加侦听";
		for(size_t i2=2;i2<p->size();i2++){
			const string& p2=(*p)[i2];
			int i1;
			if(p2 == "代码") {
				i1 = -2;
			} else {
				i1 = -1;
				for(size_t i = 0; i < s1s_length__(); i++) {
					if(p2 == s1s__(i)->src2__()) {
						i1=i;
						break;
					}
				}
				if(i1<0 || (i1==new_window_s1_->i__() && !w->is_main__())){
					err_buzhichi__(p2,p1.c_str());
					return true;
				}
			}
			if(err_buzu2__(p, ++i2))
				return true;
			const string& p3=(*p)[i2];
			switch(i1) {
			case -2:
				if(is_add)
					w->code_ += p3;
				else
					w->code_ = p3;
				break;
			default:
				if(i1 >= 0){
					if(is_add)
						w->codes_[i1] += p3;
					else
						w->codes_[i1] = p3;
				}
			}
		}
		return true;
	}
	if(p1 == "事件") {
		w=get_window__(p0,page_num,p1,false);if(!w)return true;
		for(size_t i2 = 2; i2 < p->size();) {
			const string& p2 = (*p)[i2++];
			if(err_buzu2__(p, i2))
				return true;
			const string& p3 = (*p)[i2++];
			event___* e = new event___();
			e->code_ = p3;
			e->name_ = p2;
			e->b_ = TRUE;
			string head = "key";
			if(p2.compare(0, head.size(), head) == 0) {
				g_signal_connect(G_OBJECT(w->event_box__()), p2.c_str(), G_CALLBACK(event_key__), e);
				continue;
			}
			head = "button";
			if(p2.compare(0, head.size(), head) == 0 || p2 == "motion-notify-event") {
				g_signal_connect(G_OBJECT(w->event_box__()), p2.c_str(), G_CALLBACK(event_mouse__), e);
				continue;
			}
			if(p2 == "configure-event") {
				e->b_ = FALSE;
			}
			g_signal_connect(G_OBJECT(w->event_box__()), p2.c_str(), G_CALLBACK(event_other__), e);
		}
		return true;
	}
	return false;
}

