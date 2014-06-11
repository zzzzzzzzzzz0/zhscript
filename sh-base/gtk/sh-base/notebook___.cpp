/*
 * notebook___.cpp
 *
 *  Created on: 2014年6月1日
 *      Author: zzzzzzzzzzz
 */

#include "notebook___.h"
#include "extern2.h"

gpointer notebook___::get_data__(GtkNotebook *notebook, int page_num, const char *key){
	GtkWidget *sw = gtk_notebook_get_nth_page(notebook, page_num);
	return gtk_object_get_data(GTK_OBJECT(sw),key);
}

void* notebook___::from__(GtkNotebook *notebook, int page_num){
	return get_data__(notebook,page_num,object_data_window_);
}

notebook___::~notebook___() {
}

notebook___* notebook___::new__(deque<string>* p, size_t from, void* w) {
	if(p->size() > from) {
		GtkPositionType pt = GTK_POS_TOP;
		notebook___* wf2 = NULL;
		for(;;) {
			const string& p2=(*p)[from];
			if(p2=="标签页"){
				break;
			}
			if(p2=="左标签页"){
				pt=GTK_POS_LEFT;
				break;
			}
			if(p2=="右标签页"){
				pt=GTK_POS_RIGHT;
				break;
			}
			if(p2=="顶标签页"){
				pt=GTK_POS_TOP;
				break;
			}
			if(p2=="底标签页"){
				pt=GTK_POS_BOTTOM;
				break;
			}
			return NULL;
		}
		wf2 = new notebook___(pt, w);
		for(size_t i2=from + 1;i2<p->size();i2++){
			const string& p2=(*p)[i2];
			if(p2=="自动标签"){
				wf2->label_style_=label_style_auto_;
				continue;
			}
			if(p2=="文字标签"){
				wf2->label_style_=label_style_text_;
				continue;
			}
			if(p2=="可关闭标签"){
				wf2->label_style_=label_style_can_close_;
				continue;
			}
			if(p2=="标签竖向"){
				wf2->is_vbox_=true;
				continue;
			}
			if(p2=="空") {
				wf2->has_1page_ = false;
				continue;
			}
			delete wf2;
			return NULL;
		}
		return wf2;
	}
	return NULL;
}

GtkWidget* notebook___::new__(GtkWidget* scrolled) {
	opener_ = NULL;
	notebook_ = gtk_notebook_new ();
	//g_object_ref_sink(notebook_);
	gtk_notebook_set_tab_pos (notebook__(), pt_);
	gtk_notebook_set_scrollable (notebook__(), true);
	container_add__(notebook_, scrolled);
	if(!has_1page_)
		return NULL;
	return page_new__(NULL);
}

void notebook___::signal_connect__() {
	for(size_t i = 0; i < s1s_length__(); i++) {
		s1___* s1 = s1s__(i);
		if(s1->type__() == 'n' && s1->cb_) {
			g_signal_connect(notebook_, s1->signal__(), s1->cb_, NULL);
		}
	}
}

view___* notebook___::view__(int page_num) {
	int num = page_check__(page_num);
	if(num < 0)
		return NULL;
	return (view___*)get_data__(notebook__(), num, object_data_view_);
}

GtkWidget* notebook___::page_new__(const char* name) {
	GtkWidget* scrolled2 = page_new1__(name);
	GtkWidget *label=NULL;
	switch(label_style_){
	case label_style_text_:
	{
		label = gtk_label_new ("");
		//g_object_ref_sink(label);
		gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_label_,(gpointer)label);
		break;
	}
	case label_style_can_close_:
	{
		GtkWidget *box;
		if(is_vbox_)
			box = gtk_vbox_new(false,0);
		else
			box = gtk_hbox_new(false,0);
		//g_object_ref_sink(box);
		gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_box_,(gpointer)box);
		GtkWidget *label2 = gtk_label_new ("");
		//g_object_ref_sink(label2);
		gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_label_,(gpointer)label2);
		gtk_box_pack_start(GTK_BOX(box),label2,false,false,0);
		label=box;
		break;
	}
	}

	int i=current_page__();
    opener_ = nth_page__(i);
    i++;
	gtk_notebook_insert_page (notebook__(), scrolled2, label,i);
	gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_window_,window_);
	gtk_widget_show_all (scrolled2);
	gtk_widget_show_all (label);
	switch(label_style_){
	case label_style_can_close_:
		button_new__(i,NULL,GTK_STOCK_CLOSE,GTK_ICON_SIZE_MENU, NULL, 0);
		break;
	}

	set_page__(i);
	return scrolled2;
}

void notebook___::set_page__(int page_num){
	if((page_num=page_check__(page_num))>=0)
		gtk_notebook_set_page (notebook__(),page_num);
}

#include "window___.h"

void notebook___::close__(int page_num){
	GtkNotebook* nb=notebook__();
	window___* w = (window___*)window_;
	erase__(view__(page_num));
	if(page_num == current_page__()) {
		for(int pn = 0; pn < n_pages__(); pn++) {
			if(opener_ == nth_page__(pn)){
				gtk_notebook_set_page(nb, pn);
				break;
			}
		}
	}
	gtk_notebook_remove_page(nb, page_num);
	if(gtk_notebook_get_n_pages(nb) == 0) {
		if(has_1page_)
			w->destroy__();
		else
			w->hide__();
	}
}
