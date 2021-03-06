/*
 * view___.cpp
 *
 *  Created on: 2013年12月15日
 *      Author: zzzzzzzzzzz
 */

#include "view___.h"
#include "s1___.h"

view___* view___::from__(void* v) {
	return (view___*)gtk_object_get_data(GTK_OBJECT(v), object_data_view_);
}
GtkWidget* view___::scrolled_from__(void* v) {
	return (GtkWidget*)gtk_object_get_data(GTK_OBJECT(v), object_data_scrolled_);
}

view___::view___(GtkWidget* scrolled2, void* window) {
	widget_ = NULL;
	scrolled_ = scrolled2;
	outer_scrolled_ = NULL;
	window_ = window;
	gtk_object_set_data(GTK_OBJECT(scrolled2), object_data_view_, this);
}

void view___::signal_connect__(GtkWidget* v) {
	for(size_t i = 0; i < s1s_length__(); i++) {
		s1___* s1 = s1s__(i);
		if(s1->type__() == 'v' && s1->cb_) {
			g_signal_connect(v, s1->signal__(), s1->cb_, s1);
		}
	}
}
