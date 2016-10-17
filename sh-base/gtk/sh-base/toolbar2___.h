/*
 * toolbar2___.h
 *
 *  Created on: 2016年1月18日
 *      Author: zzzzzzzzzzz
 */

#ifndef SRCVWSH_SH_BASE_TOOLBAR2____H_
#define SRCVWSH_SH_BASE_TOOLBAR2____H_
#include "window___.h"
#include "callbackitem.h"

#define toolbar2_tag_ "图标夹"
#define toolbar2_tag2_ "左图标夹"
#define toolbar2_tag3_ "树"

class toolbar2_item___ {
public:
	bool is_init_, in_book_;
	GtkWidget *scrolled_, *widget_, *label_;
	int btn_width_, btn_height_;
	string def_code_, def_arg_;
	string def_code2_, def_arg2_;
	char tag_;
	bool title_tooltip_;

	virtual void store_add__(callback_item___* si, GdkPixbuf *pixbuf, int posi) = 0;
	virtual void store_del__(GtkTreeIter* i) = 0;
	virtual GtkTreeModel *model__() = 0;
	virtual void for__(const string& code, void* ce, void* shangji);

	GtkIconView *icon_view__() {return GTK_ICON_VIEW(widget_);}
	GtkTreeView *tree_view__() {return GTK_TREE_VIEW(widget_);}

	toolbar2_item___(bool in_book) {
		is_init_ = false;
		in_book_ = in_book;
		btn_width_ = btn_height_ = -1;
		tag_ = 0;
		title_tooltip_ = false;
	}
	GtkContainer* container__() {return GTK_CONTAINER(scrolled_);}
	GtkScrolledWindow* scrolled__() {return GTK_SCROLLED_WINDOW (scrolled_);}
};

class icon_item___ : public toolbar2_item___ {
public:
	GtkListStore *store_;
	icon_item___(bool in_book) : toolbar2_item___(in_book) {
		tag_ = 'i';
	}
	GtkTreeModel *model__() {return GTK_TREE_MODEL (store_);}
	void store_add__(callback_item___* si, GdkPixbuf *pixbuf, int posi);
	void store_del__(GtkTreeIter* i) {gtk_list_store_remove(store_, i);}
};

class tree_item___ : public toolbar2_item___ {
public:
	GtkTreeStore *store_;
	GtkTreeViewColumn *col_;
	string up_, last_;
	tree_item___(bool in_book) : toolbar2_item___(in_book) {
		tag_ = 't';
	}
	GtkTreeModel *model__() {return gtk_tree_view_get_model(tree_view__());}
	void store_add__(callback_item___* si, GdkPixbuf *pixbuf, int posi);
	void store_del__(GtkTreeIter* i) {}
};

class toolbar2___ {
public:
	toolbar2___();
	virtual ~toolbar2___();
	void with__(window___* w, void*shangji,void*ce,deque<string>* p);
	bool use_tag__(const string& p1);
private:
	GtkWidget* left_book_;
	GtkNotebook* left_book__(GtkBox* box2);

	void init1__(GtkWidget* box1, toolbar2_item___* item);
	void init2__(toolbar2_item___* item);

	icon_item___ *icon_item_, *left_icon_item_;
	void init__(GtkWidget* box1, icon_item___* item);

	tree_item___ *tree_item_;
	void init__(GtkWidget* box1, tree_item___* item);
};

#endif /* SRCVWSH_SH_BASE_TOOLBAR2____H_ */
