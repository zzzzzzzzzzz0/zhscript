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
		call4__((*it).second.c_str(),gtk_widget_get_name(GTK_WIDGET(button)),0,NULL,0);
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

	return c__()->new__(scrolled);
}

void window___::name2__(string& name2, GtkWidget *sw) {
	name2 = name_;
	c__()->name2__(name2, sw);
}

window___::window___(const char* name, bool is_main){
	is_main_ = is_main;
	name_ = name;
	window_ = NULL;
}
