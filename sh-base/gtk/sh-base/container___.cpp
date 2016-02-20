/*
 * container___.cpp
 *
 *  Created on: 2014年6月1日
 *      Author: zzzzzzzzzzz
 */

#include "container___.h"
#include "extern2.h"
#include <algorithm>
#include "extern.h"
#include"l4/keyword.h"
#include"def1.h"

void container_add__(GtkWidget* w, GtkWidget* scrolled) {
#ifdef ver_gtk3_
	GtkWidget *viewport = gtk_viewport_new (NULL,NULL);
	gtk_container_add (GTK_CONTAINER(scrolled), viewport);
	gtk_widget_show(viewport);
	gtk_container_add (GTK_CONTAINER (viewport), w);
#else
	gtk_container_add (GTK_CONTAINER (scrolled), w);
#endif
}

container___::container___(void* window) {
	window_ = window;
	is_vbox_ = false;
}

container___::~container___() {
}

view___* container___::view__(int page_num) {
	if((page_num = page_check__(page_num)) < 0)
		return NULL;
	return views_[page_num];
}

void container___::erase__(view___* v) {
	deque<view___*>::iterator i = find(views_.begin(), views_.end(), v);
	if(i != views_.end())
		views_.erase(i);
}

void container___::name2__(string& name2, GtkWidget *sw) {
	if(sw){
		char buf[32] = "#";
		const char* swname = gtk_widget_get_name(sw);
		if(swname && swname[0]) {
			name2 += buf;
			name2 += swname;
		} else {
			l2s__(page_num__(sw)+1,buf+1);
			name2 += buf;
		}
	}
}

GtkWidget* container___::page_new1__(const char* name) {
	GtkWidget* scrolled2;
	scrolled2 = gtk_scrolled_window_new (NULL, NULL);
	if(name && name[0])
		gtk_widget_set_name(scrolled2, name);
	else
		gtk_widget_set_name(scrolled2, "");
	//g_object_ref_sink(scrolled2);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled2),
								  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	return scrolled2;
}

GtkWidget* container___::box__(int page_num, GtkWidget** scrolled) {
	GtkWidget* scrolled2 = nth_page2__(page_num);
	if(scrolled)
		*scrolled = scrolled2;
	return GTK_WIDGET(gtk_object_get_data(GTK_OBJECT(scrolled2),object_data_box_));
}

GtkWidget* container___::button_new__(int page_num,
		const char*name, const char*iconame,GtkIconSize size,
		const char* code,char clicked){
	GtkWidget* scrolled2;
	GtkWidget* box = box__(page_num, &scrolled2);
	if(!box)
		return NULL;
	return button_new__(box, scrolled2, name, iconame, size, code, clicked);
}

GtkWidget* container___::button_new__(GtkWidget* box, GtkWidget* scrolled2,
		const char*name,const char*iconame,GtkIconSize size,
		const char* code,char clicked){
	GtkWidget *btn;
	if(iconame[0]=='-'){
		if(is_vbox_)
			btn=gtk_hseparator_new();
		else
			btn=gtk_vseparator_new();
		gtk_box_pack_start(GTK_BOX(box),btn,false,false,0);
	}else{
		btn = gtk_button_new();
		//g_object_ref_sink(btn);
		gtk_button_set_relief(GTK_BUTTON(btn),GTK_RELIEF_NONE);
		switch(clicked){
		case 'f':
			break;
		default:
			//gtk_button_set_focus_on_click(GTK_BUTTON(btn), false);
			gtk_widget_set_can_focus(btn, false);
			break;
		}
		GCallback cb;
		switch(clicked){
		case 0:
			gtk_object_set_data(GTK_OBJECT(scrolled2),iconame,(gpointer)btn);
			cb = G_CALLBACK(clicked_close__);
			break;
		default:
			gtk_widget_set_name(btn,name);
			cb = G_CALLBACK(clicked__);
			if(code) {
				button_code__(btn, code);
			}
			break;
		}
		gtk_widget_set_tooltip_markup(btn, name);
		g_signal_connect(btn, "clicked", cb, scrolled2);
		gtk_box_pack_start(GTK_BOX(box),btn,false,false,0);
		GtkWidget*img=gtk_image_new_from_stock(iconame,size);
		//g_object_ref_sink(img);
		gtk_button_set_image(GTK_BUTTON(btn),img);
	}
	gtk_widget_show (btn);
	return btn;
}

int container___::current_page__() {
	if(n_pages__() <= 0)
		return notebook_page_no_;
	return 0;
}

GtkWidget* container___::nth_page__(int page_num) {
	return views_[page_num]->scrolled__();
}

int container___::page_num__(const char* name) {
	string name1 = name;
	for(int i = 0; i < n_pages__(); i++) {
		const char* name2 = gtk_widget_get_name(nth_page__(i));
		if(name2 && name1 == name2)
			return i;
	}
	return notebook_page_no_;
}
int container___::page_num__(GtkWidget* sw) {
	for(int i = 0; i < n_pages__(); i++) {
		if(sw == nth_page__(i))
			return i;
	}
	return notebook_page_no_;
}

void container___::for__(const char* code, void*ce, void* shangji) {
	const char* a[2];
	int err;
	for(int i = 0; i < n_pages__(); i++) {
		string name2;
		name2__(name2, nth_page__(i));
		a[0] = name2.c_str();
		a[1] = i == current_page__() ? "1" : "";
		call4__(&err, ce, code, NULL, shangji, 2, a, 0);
		switch(err) {
		case 0:
			break;
		case jieshiqi_go_+keyword_continue_:
			continue;
		default:
			return;
		}
	}
}

int container___::page_check__(int page_num){
	int n=n_pages__();
	if(page_num==notebook_current_page_)
		page_num=current_page__();
	else if(page_num==notebook_end_page_)
		page_num=n-1;
	if(page_num<0 || page_num>=n)
		return notebook_page_no_;
	return page_num;
}

GtkWidget* container___::nth_page2__(int page_num) {
	if((page_num = page_check__(page_num)) < 0)
		return NULL;
	return nth_page__(page_num);
}

void container___::set_data__(int page_num, const char *key, gpointer data) {
	GtkWidget* w = nth_page2__(page_num);
	if(w)
		gtk_object_set_data(GTK_OBJECT(w), key, data);
}

gpointer container___::get_data__(int page_num, const char *key) {
	GtkWidget* w = nth_page2__(page_num);
	if(!w)
		return NULL;
	return gtk_object_get_data(GTK_OBJECT(w), key);
}

GtkLabel* container___::label__(int page_num) {
	void* v = get_data__(page_num, object_data_label_);
	if(!v)
		return NULL;
	return GTK_LABEL(v);
}
GtkLabel* container___::label2__(int page_num) {
	void* v = get_data__(page_num, object_data_label2_);
	if(!v)
		return NULL;
	return GTK_LABEL(v);
}
GtkWidget* container___::close_button__(int page_num) {
	void* v = get_data__(page_num, GTK_STOCK_CLOSE);
	if(!v)
		return NULL;
	return GTK_WIDGET(v);
}
