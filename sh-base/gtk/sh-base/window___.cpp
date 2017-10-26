/*
 * window___.cpp
 *
 *  Created on: 2012-8-7
 *      Author: zzzzzzzzzzz
 */

#include "window___.h"
#include "extern.h"
#include "extern2.h"
#include <map>

static s1___* clicked_s1_ = new s1___("点击", "", 'w');

void clicked_close__(GtkButton *button, gpointer user_data) {
	GtkWidget *sw = (GtkWidget *)user_data;
	window___* w=(window___*)gtk_object_get_data(GTK_OBJECT(sw),object_data_window_);
	if(!w)
		return;
	call4__(sw,w,clicked_s1_,1,"x");
	w->c__()->close__(w->c__()->page_num__(sw));
}

typedef map<GtkButton*, string> button_code___;
static button_code___ button_code_;
void button_code__(GtkWidget* w, const char* c) {
	button_code_[GTK_BUTTON(w)] = c;
}

void clicked__(GtkButton *button, gpointer user_data) {
	button_code___::iterator it = button_code_.find(button);
	if(it != button_code_.end()) {
		call4__((*it).second.c_str(),gtk_widget_get_name(GTK_WIDGET(button)),0,NULL);
		return;
	}

	GtkWidget *sw = (GtkWidget *)user_data;
	window___* w=(window___*)gtk_object_get_data(GTK_OBJECT(sw),object_data_window_);
	const char* name=gtk_widget_get_name(GTK_WIDGET(button));
	call4__(sw,w,clicked_s1_,1,name);
}

window___* window___::from__(GtkWidget* widget){
	return (window___*)gtk_object_get_data(GTK_OBJECT(widget),object_data_window_);
}

void window___::hide__(){
	gtk_widget_hide(widget__());
}

void window___::destroy__() {
	g_signal_emit_by_name(widget__(),"destroy");
}

GtkWidget* window___::new__(window_flag___* flag, container___* c){
	flag_.copy__(flag);
	c_ = c;

	window_ = gtk_window_new (flag->wt_);
	//g_object_ref_sink(window_);
	gtk_object_set_data(GTK_OBJECT(window_),object_data_window_,(gpointer)this);

	if(flag->is_app_paintable_) {
		gtk_widget_set_app_paintable(window_, TRUE);
		GdkScreen *screen = gtk_widget_get_screen(window_);
#ifndef ver_gtk3_
		GdkColormap *colormap = gdk_screen_get_rgba_colormap(screen);
		gtk_widget_set_colormap(window_, colormap);
#else
		GdkVisual *visual = gdk_screen_get_rgba_visual(screen);
		if (!visual)
			visual = gdk_screen_get_system_visual(screen);
		gtk_widget_set_visual(window_, visual);
#endif
	}

	box_ = gtk_vbox_new(false,0);
	gtk_container_add(GTK_CONTAINER(window_),box_);
	box4_ = gtk_vbox_new(false,0);
	gtk_box_pack_end(GTK_BOX(box_),box4_,false,false,0);
	box2_ = gtk_hbox_new(false,0);
	gtk_box_pack_end(GTK_BOX(box_),box2_,true,true,0);
	box3_ = gtk_hbox_new(false,0);
	gtk_box_pack_end(GTK_BOX(box2_),box3_,false,false,0);

	scrolled_ = gtk_scrolled_window_new (NULL, NULL);
	//g_object_ref_sink(scrolled);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_),
								  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

	if(add_event_box_) {
		event_box_ = gtk_event_box_new ();
		gtk_event_box_set_above_child (GTK_EVENT_BOX (event_box_), FALSE);
		gtk_container_add (GTK_CONTAINER (event_box_), scrolled_);
		//gtk_container_add (GTK_CONTAINER (window_), event_box_);
		gtk_box_pack_end(GTK_BOX(box2_),event_box_,true,true,0);
		gtk_widget_realize (event_box_);
	} else {
		event_box_ = NULL;
		//gtk_container_add (GTK_CONTAINER (window_), scrolled);
		gtk_box_pack_end(GTK_BOX(box2_),scrolled_,true,true,0);
	}
	gtk_widget_set_events(window_, gtk_widget_get_events(window_)
			| GDK_KEY_PRESS_MASK | GDK_KEY_RELEASE_MASK
			| GDK_BUTTON_PRESS | GDK_BUTTON_RELEASE
			| GDK_ENTER_NOTIFY | GDK_LEAVE_NOTIFY);

	return c__()->new__(scrolled_);
}

bool window___::add_event_box_ = false;

void window___::name2__(string& name2, GtkWidget *sw) {
	name2 = name_;
	c__()->name2__(name2, sw);
}

window___::window___(const char* name, bool is_main){
	is_main_ = is_main;
	name_ = name;
	window_ = NULL;
	cursor_ = NULL;
	is_destroy_ = false;
}
