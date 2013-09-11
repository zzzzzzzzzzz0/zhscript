/*
 * webkit_window___.h
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#ifndef WEBKIT_WINDOW____H_
#define WEBKIT_WINDOW____H_

#include <webkit/webkit.h>
#include <JavaScriptCore/JavaScript.h>
#include "sh-base/window___.h"

#define object_data_view_		"v"
#define object_data_scrolled_	"s"

class webkit_window___: public window___ {
private:
	GtkWidget* webview_;
	GtkWidget* webview_new__(GtkWidget* scrolled);
public:
	webkit_window___* target_;

	webkit_window___(const char* name, bool is_main);
	GtkWidget* new__(window_flag___* wf);
	WebKitWebView* webview__(int page_num);
	static webkit_window___* from__(WebKitWebView* page);
	static GtkWidget* scrolled_from__(WebKitWebView* page);
	static WebKitWebView* webview_from__(GtkNotebook *notebook, int page_num);
	WebKitWebView* tabpg_new__(const char* name, bool is_hide);
	void close__(int page_num);
};

#endif /* WEBKIT_WINDOW____H_ */
