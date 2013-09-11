/*
 * window___.cpp
 *
 *  Created on: 2012-8-7
 *      Author: zzzzzzzzzzz
 */

#include "window___.h"
#include "extern.h"
#include "extern2.h"

static s1___* clicked_s1_ = new s1___("点击", "", 0);

static void clicked_close__(GtkButton *button, gpointer user_data) {
	GtkWidget *sw = (GtkWidget *)user_data;
	window___* w=(window___*)gtk_object_get_data(GTK_OBJECT(sw),object_data_window_);
	GtkNotebook* nb=w->notebook__();
	int i=gtk_notebook_page_num(nb,sw);
	w->close__(i);
}
static void clicked__(GtkButton *button, gpointer user_data) {
	GtkWidget *sw = (GtkWidget *)user_data;
	window___* w=(window___*)gtk_object_get_data(GTK_OBJECT(sw),object_data_window_);
	const char* name=gtk_widget_get_name(GTK_WIDGET(button));
	call4__(sw,w,clicked_s1_,1,name);
}

window___* window___::from__(GtkWidget* widget){
	return (window___*)gtk_object_get_data(GTK_OBJECT(widget),object_data_window_);
}
window___* window___::from__(GtkNotebook *notebook, int page_num){
	return (window___*)get_data__(notebook,page_num,object_data_window_);
}

gpointer window___::get_data__(GtkNotebook *notebook, int page_num, const char *key){
	GtkWidget *sw = gtk_notebook_get_nth_page(notebook, page_num);
	return gtk_object_get_data(GTK_OBJECT(sw),key);
}

int window___::current_page__(){
	if(!notebook_)
		return notebook_page_no_;
	return gtk_notebook_get_current_page (notebook__());
}

int window___::n_pages__() {
	if(!notebook_)
		return 0;
	return gtk_notebook_get_n_pages(notebook__());
}

int window___::page_check__(int page_num){
	if(!notebook_)
		return notebook_page_no_;
	int n=gtk_notebook_get_n_pages(notebook__());
	if(page_num==notebook_current_page_)
		page_num=current_page__();
	else if(page_num==notebook_end_page_)
		page_num=n-1;
	if(page_num<0 || page_num>=n)
		return notebook_page_no_;
	return page_num;
}

void window___::set_page__(int page_num){
	if((page_num=page_check__(page_num))>=0)
		gtk_notebook_set_page (notebook__(),page_num);
}

const char* window___::page_name__(int page_num){
	if((page_num=page_check__(page_num)) < 0)
		return "";
	GtkWidget *sw = gtk_notebook_get_nth_page(notebook__(), page_num);
	return gtk_widget_get_name(sw);
}

int window___::page_num__(const char* name) {
	if(notebook_) {
		string name1 = name;
		int n=gtk_notebook_get_n_pages(notebook__());
		for(int i = 0; i < n; i++) {
			GtkWidget *sw = gtk_notebook_get_nth_page(notebook__(), i);
			const char* name2 = gtk_widget_get_name(sw);
			if(name2 && name1 == name2)
				return i;
		}
	}
	return notebook_page_no_;
}

GtkLabel* window___::label__(int page_num){
	if((page_num=page_check__(page_num))>=0)
		return GTK_LABEL(get_data__(notebook__(),page_num,object_data_label_));
	return NULL;
}
GtkWidget* window___::close_button__(int page_num){
	if((page_num=page_check__(page_num))>=0)
		return GTK_WIDGET(get_data__(notebook__(),page_num,GTK_STOCK_CLOSE));
	return NULL;
}

void window___::close__(int page_num){
	if(!notebook_){
		destroy__();
		return;
	}
	GtkNotebook* nb=notebook__();
	gtk_notebook_remove_page(nb, page_num);
	if(gtk_notebook_get_n_pages(nb) == 0) {
		if(flag_.has_1page_)
			destroy__();
		else
			hide__();
	}
}

void window___::hide__(){
	gtk_widget_hide(widget__());
}

bool window___::button_new__(int page_num,const char*name,const char*iconame,GtkIconSize size,char clicked){
	if(!notebook_)
		return false;
	if((page_num=page_check__(page_num))<0)
		return false;
	GtkWidget* scrolled2 = gtk_notebook_get_nth_page(notebook__(), page_num);
	GtkWidget* box = GTK_WIDGET(gtk_object_get_data(GTK_OBJECT(scrolled2),object_data_box_));

	GtkWidget *btn;
	if(iconame[0]=='-'){
		if(flag_.is_tabpg_vbox_)
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
			break;
		}
		g_signal_connect(btn, "clicked", cb, scrolled2);
		gtk_box_pack_start(GTK_BOX(box),btn,false,false,0);
		GtkWidget*img=gtk_image_new_from_stock(iconame,size);
		//g_object_ref_sink(img);
		gtk_button_set_image(GTK_BUTTON(btn),img);
	}
	gtk_widget_show (btn);
	return true;
}

void window___::destroy__() {
	g_signal_emit_by_name(widget__(),"destroy");
}

GtkWidget* window___::new__(window_flag___* flag){
	flag_.copy__(flag);

	window_ = gtk_window_new (flag->wt_);
	//g_object_ref_sink(window_);
	gtk_object_set_data(GTK_OBJECT(window_),object_data_window_,(gpointer)this);

	if(flag->is_app_paintable_) {
		gtk_widget_set_app_paintable(window_, TRUE);
#ifndef no_gtk_2_
		GdkScreen *screen = gtk_widget_get_screen(window_);
		GdkColormap *colormap = gdk_screen_get_rgba_colormap(screen);
		gtk_widget_set_colormap(window_, colormap);
#endif
	}

	GtkWidget* scrolled;
	scrolled = gtk_scrolled_window_new (NULL, NULL);
	//g_object_ref_sink(scrolled);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled),
								  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_container_add (GTK_CONTAINER (window_), scrolled);

	if(flag->is_tabpg_) {
	    notebook_ = gtk_notebook_new ();
	    //g_object_ref_sink(notebook_);
	    gtk_notebook_set_tab_pos (notebook__(), flag->pt_);
	    gtk_notebook_set_scrollable (notebook__(), true);
#ifdef no_gtk_2_
		GtkWidget *viewport = gtk_viewport_new (NULL,NULL);
		gtk_container_add (GTK_CONTAINER(scrolled), viewport);
		gtk_widget_show(viewport);
	    gtk_container_add (GTK_CONTAINER (viewport), notebook_);
#else
	    gtk_container_add (GTK_CONTAINER (scrolled), notebook_);
#endif
	    if(flag->has_1page_)
	    	return tabpg_new__(NULL);
	    return NULL;
	}
	return scrolled;
}

GtkWidget* window___::tabpg_new__(const char* name) {
	if(!notebook_)
		return NULL;
	GtkWidget* scrolled2;
	scrolled2 = gtk_scrolled_window_new (NULL, NULL);
	if(name && name[0])
		gtk_widget_set_name(scrolled2, name);
	else
		gtk_widget_set_name(scrolled2, "");
	//g_object_ref_sink(scrolled2);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled2),
								  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	GtkWidget *label=NULL;
	switch(flag_.label_style_){
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
		if(flag_.is_tabpg_vbox_)
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

	int i=current_page__()+1;
	gtk_notebook_insert_page (notebook__(), scrolled2, label,i);
	gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_window_,this);
	gtk_widget_show_all (scrolled2);
	gtk_widget_show_all (label);
	switch(flag_.label_style_){
	case label_style_can_close_:
		button_new__(i,NULL,GTK_STOCK_CLOSE,GTK_ICON_SIZE_MENU,0);
		break;
	}

	set_page__(i);
	return scrolled2;
}

void window___::name2__(string& name2, GtkWidget *sw) {
	name2 = name_;
	if(notebook_ && sw){
		char buf[32] = "#";
		const char* swname = gtk_widget_get_name(sw);
		if(swname && swname[0]) {
			name2 += buf;
			name2 += swname;
		} else {
			l2s__(gtk_notebook_page_num(notebook__(),sw)+1,buf+1);
			name2 += buf;
		}
	}
}

window___::window___(const char* name, bool is_main){
	is_main_ = is_main;
	name_ = name;
	window_ = NULL;
	notebook_ = NULL;
	//codes_ = new string[s1s_length__()];
}
