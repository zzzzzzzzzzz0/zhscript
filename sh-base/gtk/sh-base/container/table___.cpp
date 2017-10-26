/*
 * table___.cpp
 *
 *  Created on: 2014年6月2日
 *      Author: zzzzzzzzzzz
 */

#include "table___.h"
#include "../extern2.h"

table___::table___(int rows, int cols, void* w) : container___(w), rows_(rows), cols_(cols) {
	last_row_ = -1;
	last_col_ = 0;
	table_ = NULL;
	current_page_ = -1;
}

table___::~table___() {
}

table___* table___::new__(deque<string>* p, size_t from, void* w) {
	if(p->size() > from) {
		table___* wf2 = NULL;
		for(;;) {
			const string& p2=(*p)[from];
			if(p2=="表格"){
				break;
			}
			return NULL;
		}
		wf2 = new table___(2, 2, w);
		for(size_t i2=from + 1;i2<p->size();i2++){
			const string& p2=(*p)[i2];
			if(p2=="行"){
				if(++i2 < p->size()) {
					wf2->rows_ = s2i__((*p)[i2], wf2->rows_);
					continue;
				}
			}
			else if(p2=="列"){
				if(++i2 < p->size()) {
					wf2->cols_ = s2i__((*p)[i2], wf2->cols_);
					continue;
				}
			}
			delete wf2;
			return NULL;
		}
		return wf2;
	}
	return NULL;
}

GtkWidget* table___::new__(GtkWidget* scrolled) {
	table_ = gtk_table_new(rows_, cols_, false);
	container_add__(table_, scrolled);
	return page_new__(NULL, true);
}

GtkWidget* table___::page_new__(const char* name, bool to) {
	if(last_col_ >= cols_) {
		return NULL;
	}
	if(++last_row_ >= rows_) {
		last_row_ = 0;
		if(++last_col_ >= cols_) {
			return NULL;
		}
	}

	GtkWidget* scrolled2 = page_new1__(name);

	int i = last_row_, j = last_col_;
    GtkWidget *box2 = gtk_vbox_new(false, 0);
    gtk_box_pack_end(GTK_BOX(box2), scrolled2, true, true, 0);
	GtkWidget *box3 = gtk_hbox_new(false, 0);

	label_new__(box3, scrolled2);

	GtkWidget *box4 = gtk_hbox_new(false, 0);
    gtk_box_pack_end(GTK_BOX(box3), box4, true, true, 0);
	gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_box_,(gpointer)box4);

    gtk_box_pack_start(GTK_BOX(box2), box3, false, false, 0);

    gtk_table_attach_defaults(GTK_TABLE(table_), box2, j, j+1, i, i+1 );

	gtk_object_set_data(GTK_OBJECT(scrolled2),object_data_window_,window_);
	gtk_widget_show_all (box2);

	current_page_++;
	//button_new__(box4, scrolled2, NULL, GTK_STOCK_CLOSE,GTK_ICON_SIZE_MENU, NULL, 0);

	return scrolled2;
}

#include "../window___.h"

int table___::current_page__() {
	GtkWindow* w = ((window___*)window_)->window__();
	GtkWidget *w2 = gtk_window_get_focus(w);
	for(int i = 0; i < n_pages__(); i++) {
		GtkWidget *w3 = views_[i]->widget__();
		if(w2 == w3) {
			current_page_ = i;
			break;
		}
	}
	return current_page_;
}
