/*
 * window___.h
 *
 *  Created on: 2012-8-7
 *      Author: zzzzzzzzzzz
 */

#ifndef WINDOW____H_
#define WINDOW____H_
#include <deque>
#include <map>
#include "view___.h"

#define label_style_auto_ 0
#define label_style_text_ 1
#define label_style_can_close_ 2
#define label_style_default_ label_style_can_close_

#define notebook_end_page_ -1
#define notebook_current_page_ -2
#define notebook_page_no_ -10

//有 GTK_STOCK_* 也在用
#define object_data_window_	""
#define object_data_label_	"l"
#define object_data_box_	"b"

class window_flag___ {
public:
	GtkWindowType wt_;

	bool is_tabpg_, is_tabpg_vbox_;
	GtkPositionType pt_;
	int label_style_;

	bool is_app_paintable_;
	bool has_1page_;
	window_flag___() {
		wt_ = GTK_WINDOW_TOPLEVEL;

		is_tabpg_ = false;
		is_tabpg_vbox_ = false;
		pt_ = GTK_POS_TOP;
		label_style_ = label_style_default_;

		is_app_paintable_ = false;
		has_1page_ = true;
	}
	void copy__(window_flag___* wf) {
		label_style_ = wf->label_style_;
		is_tabpg_vbox_ = wf->is_tabpg_vbox_;
		is_app_paintable_ = wf->is_app_paintable_;
		has_1page_ = wf->has_1page_;
	}
};

class window___ {
private:
	deque<view___*> views_;
	GtkWidget* window_;
	GtkWidget* notebook_;
	string name_;
	window_flag___ flag_;
	bool is_main_;
	static gpointer get_data__(GtkNotebook *notebook, int page_num, const char *key);
public:
	string code_;
	map<int, string> codes_;

	window___(const char* name, bool is_main = false);
	const string& name__(){return name_;}
	void name2__(string& name2, GtkWidget *sw);
	bool can_set__(){return window_!=NULL;}
	bool is_main__() {return is_main_;}
	GtkWidget* widget__(){return window_;}
	GtkWindow* window__(){return GTK_WINDOW (window_);}
	GtkNotebook* notebook__(){return GTK_NOTEBOOK (notebook_);}
	static window___* from__(GtkWidget* widget);
	static window___* from__(GtkNotebook *notebook, int page_num);
	GtkLabel* label__(int page_num);
	GtkWidget* close_button__(int page_num);
	void close__(int page_num);
	GtkWidget* button_new__(int page_num,const char*name,
			const char*iconame,GtkIconSize size,
			const char* code, char clicked);
	GtkWidget* new__(window_flag___* flag);
	GtkWidget* tabpg_new__(const char* name);
	void destroy__();
	void hide__();

	void push__(view___* v);
	void erase__(view___* v);
	view___* view__(int page_num);
	bool is_app_paintable__() {return flag_.is_app_paintable_;}

	int current_page__();
	int n_pages__();
	void set_page__(int page_num);
	const char* page_name__(int page_num);
	int page_num__(const char* name);
	int page_check__(int page_num);
};

#endif /* WINDOW____H_ */
