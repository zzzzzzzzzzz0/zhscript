/*
 * notebook___.h
 *
 *  Created on: 2014年6月1日
 *      Author: zzzzzzzzzzz
 */

#ifndef NOTEBOOK____H_
#define NOTEBOOK____H_

#include "../container___.h"

#define label_style_auto_ 0
#define label_style_text_ 1
#define label_style_can_close_ 2
#define label_style_default_ label_style_can_close_

class notebook___: public container___ {
private:
	int label_style_;
	GtkPositionType pt_;
	bool has_1page_;

	GtkWidget* notebook_;
	GtkWidget* opener_;

	static gpointer get_data__(GtkNotebook *notebook, int page_num, const char *key);
public:
	notebook___(GtkPositionType pt, void* window) : container___(window), pt_(pt) {
		label_style_ = label_style_default_;
		has_1page_ = true;
		notebook_ = NULL;
		opener_ = NULL;
	}
	virtual ~notebook___();
	GtkNotebook* notebook__(){return GTK_NOTEBOOK (notebook_);}

	static notebook___* new__(deque<string>* p, size_t from, void* w);
	GtkWidget* new__(GtkWidget* scrolled);
	void signal_connect__();
	static void* from__(GtkNotebook *notebook, int page_num);

	view___* view__(int page_num);
	void copy__(container___* c) {
		notebook___* wf = (notebook___*)c;
		label_style_ = wf->label_style_;
		is_vbox_ = wf->is_vbox_;
		has_1page_ = wf->has_1page_;
	}

	GtkWidget* page_new__(const char* name, bool to);

	int current_page__() {
		return gtk_notebook_get_current_page (notebook__());
	}
	int n_pages__() {
		return gtk_notebook_get_n_pages(notebook__());
	}
	GtkWidget* nth_page__(int page_num) {
		return gtk_notebook_get_nth_page(notebook__(), page_num);
	}
	void set_page__(int page_num);
	int page_num__(GtkWidget* sw) {
		return gtk_notebook_page_num(notebook__(), sw);
	}

	GtkLabel* menu_label__(int page_num);
	void close__(int page_num);
	void close__(void* v) {
		close__(page_num__(view___::scrolled_from__(v)));
	}

	void show_tabs__(bool b) {
		gtk_notebook_set_show_tabs(notebook__(), b);
	}
	void show_border__(bool b) {
		gtk_notebook_set_show_border(notebook__(), b);
	}
};

#endif /* NOTEBOOK____H_ */
