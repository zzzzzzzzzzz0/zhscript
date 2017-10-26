/*
 * container___.h
 *
 *  Created on: 2014年6月1日
 *      Author: zzzzzzzzzzz
 */

#ifndef CONTAINER____H_
#define CONTAINER____H_
#include "s1___.h"
#include "view___.h"
#include <deque>

//有 GTK_STOCK_* 也在用
#define object_data_window_	""
#define object_data_label_	"l"
#define object_data_label2_	"l2"
#define object_data_box_	"b"

#define notebook_end_page_		-1
#define notebook_current_page_	-2
#define notebook_page_no_		-10

class container___ {
protected:
	void* window_;
	deque<view___*> views_;

	bool is_vbox_;

	GtkWidget* page_new1__(const char* name);
public:
	container___(void* window);
	virtual ~container___();
	virtual GtkWidget* new__(GtkWidget* scrolled) = 0;
	virtual void signal_connect__() {}

	virtual view___* view__(int page_num);
	void push__(view___* v) {
		views_.push_back(v);
	}
	void erase__(view___* v);
	virtual void copy__(container___* c) {}
	void name2__(string& name2, GtkWidget *sw);

	virtual GtkWidget* page_new__(const char* name, bool to) {
		return NULL;
	}
	void label_new__(GtkWidget *box, GtkWidget* scrolled2);
	GtkWidget* button_new__(int page_num,
			const char*name, const char*iconame,GtkIconSize size,
			const char* code, char clicked);
	GtkWidget* button_new__(GtkWidget* box, GtkWidget* scrolled2,
			const char*name,const char*iconame,GtkIconSize size,
			const char* code,char clicked);
	GtkWidget* box__(int page_num, GtkWidget** scrolled2 = NULL);

	virtual int n_pages__() {
		return views_.size();
	}
	virtual int current_page__();
	virtual GtkWidget* nth_page__(int page_num);
	virtual void set_page__(int page_num) {}
	int page_num__(const char* name);
	virtual int page_num__(GtkWidget* sw);
	int page_check__(int page_num);
	GtkWidget* nth_page2__(int page_num);
	gpointer get_data__(int page_num, const char *key);
	void set_data__(int page_num, const char *key, const string& data);

	void for__(const char* code, void*ce, void* shangji);

	GtkLabel* label__(int page_num);
	GtkLabel* label2__(int page_num);
	virtual GtkLabel* menu_label__(int page_num) {return NULL;}
	GtkWidget* close_button__(int page_num);
	virtual void close__(int page_num) {}
	virtual void close__(void* v) {}

	virtual void show_tabs__(bool b) {}
	virtual void show_border__(bool b) {}
};

extern void clicked_close__(GtkButton *button, gpointer user_data);
extern void clicked__(GtkButton *button, gpointer user_data);
extern void button_code__(GtkWidget* w, const char* c);

#endif /* CONTAINER____H_ */
