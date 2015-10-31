/*
 * webkit_window___.h
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#ifndef WEBKIT_VIEW____H_
#define WEBKIT_VIEW____H_

#include <webkit/webkit.h>
#include <JavaScriptCore/JavaScript.h>
#include "sh-base/view___.h"

class webkit_view___: public view___ {
private:
	bool is_app_paintable_;
	GtkWidget* webview_new__(GtkWidget* scrolled);
public:
	webkit_view___* target_;
	static string user_agent_;

	webkit_view___(GtkWidget* scrolled2, void* window, bool is_app_paintable);

	WebKitWebView* handle__() {return WEBKIT_WEB_VIEW(widget_);}
};

#endif /* WEBKIT_VIEW____H_ */
