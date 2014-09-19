/*
 * window___.h
 *
 *  Created on: 2012-8-7
 *      Author: zzzzzzzzzzz
 */

#ifndef WINDOW____H_
#define WINDOW____H_
#include <map>
#include "view___.h"
#include "container___.h"

class window_flag___ {
public:
	GtkWindowType wt_;
	bool is_app_paintable_;

	window_flag___() {
		wt_ = GTK_WINDOW_TOPLEVEL;
		is_app_paintable_ = false;
	}

	void copy__(window_flag___* wf) {
		is_app_paintable_ = wf->is_app_paintable_;
	}
};

class window___ {
private:
	GtkWidget* window_;
	string name_;
	window_flag___ flag_;
	container___* c_;
	bool is_main_;
	GtkWidget* event_box_;
public:
	string code_;
	map<int, string> codes_;
	static bool has_event_box_;

	window___(const char* name, bool is_main = false);
	const string& name__(){return name_;}
	void name2__(string& name2, GtkWidget *sw);
	bool can_set__(){return window_!=NULL;}
	bool is_main__() {return is_main_;}
	container___* c__() {return c_;}
	GtkWidget* widget__(){return window_;}
	GtkWindow* window__(){return GTK_WINDOW (window_);}
	GtkWidget* event_box__(){return event_box_;}
	static window___* from__(GtkWidget* widget);
	GtkWidget* new__(window_flag___* flag, container___* c);
	void destroy__();
	void hide__();

	bool is_app_paintable__() {return flag_.is_app_paintable_;}

	view___* view__(int page_num) {return c__()->view__(page_num);}
};

#endif /* WINDOW____H_ */
