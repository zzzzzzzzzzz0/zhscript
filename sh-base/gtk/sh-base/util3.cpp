/*
 * util3.cpp
 *
 *  Created on: 2016年2月29日
 *      Author: zzzzzzzzzzz
 */
#include "util3.h"
#include "callbackitem.h"
#include "extern.h"

static void cb__(GtkWidget *widget, gpointer data) {
	callback_item___* cbi = (callback_item___*)data;
	cbi->i_++;
	if(cbi->tooltip_ == "get") {
		if((void*)cbi->i_ == cbi->data_) {
			cbi->data2_ = widget;
		}
		return;
	}
	char buf[8];
	sprintf(buf, "%d", cbi->i_);
	const char* argv[2] = {gtk_widget_get_name(widget), buf};
	call4__(cbi->data_, cbi->code_, cbi->data2_, 2, argv);
}

GtkWidget* get__(GtkWidget* w, int i) {
	callback_item___* cbi = new callback_item___();
	cbi->tooltip_ = "get";
	cbi->data_ = (void*)i;
	gtk_container_foreach (GTK_CONTAINER (w), cb__, (gpointer)cbi);
	GtkWidget* ret = (GtkWidget*)cbi->data2_;
	delete cbi;
	return ret;
}

void foreach__(GtkWidget* w, const char* code, void* ce, void* shangji) {
	callback_item___* cbi = new callback_item___();
	cbi->code_ = code;
	cbi->data_ = ce;
	cbi->data2_ = shangji;
	gtk_container_foreach (GTK_CONTAINER (w), cb__, (gpointer)cbi);
	delete cbi;
}

#ifdef ver_thread_
static int thread_i_ = 0;
static pthread_mutex_t mutex_ = PTHREAD_MUTEX_INITIALIZER;
void thread_begin__() {
	if(++thread_i_ == 1) {
		//gdk_threads_enter();
		pthread_mutex_lock(&mutex_);
	}
}
void thread_end__() {
	if(thread_i_-- == 1) {
		pthread_mutex_unlock(&mutex_);
		//gdk_threads_leave();
	}
}
#endif
