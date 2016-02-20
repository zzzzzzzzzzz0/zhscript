/*
 * toolbar2___.cpp
 *
 *  Created on: 2016年1月18日
 *      Author: zzzzzzzzzzz
 */

#include "toolbar2___.h"
#include <iostream>
#include "extern2.h"
#include "extern.h"

static const char* call4__(void* ce, const string& code, void* shangji, int argc, const char** argv) {
	int err2 = 0;
	const char* ret = call4__(&err2, ce, code.c_str(), NULL, shangji, argc, argv, 0);
	if(err2) {
		err__(err2, ret);
		return NULL;
	}
	return ret;
}

static void err__(deque<string>* p, size_t i2, const char* s) {
	string err;
	if(i2 >= p->size())
		i2 = p->size() - 1;
	for(size_t i = 1; i <= i2; i++)
		err += (*p)[i];
	err += s;
	err__(err.c_str());
}
static bool buzu__(size_t i2, deque<string>* p) {
	if(i2 >= p->size()) {
		err__(p, i2, "参数不足");
		return true;
	}
	return false;
}
static void buzhichi__(size_t i2, deque<string>* p) {
	err__(p, i2, "不支持");
}

enum {
	ID_COLUMN,
	PIXBUF_COLUMN,
	TITLE_COLUMN,
	COLUMNS
};

static int get_id__(GtkTreeModel *model, GtkTreePath *path) {
	int id = 0;
	GtkTreeIter iter;
	if (gtk_tree_model_get_iter(model, &iter, path) == TRUE) {
		gtk_tree_model_get(model, &iter, ID_COLUMN, &id, -1);
	}
	gtk_tree_path_free(path);
	return id;
}

static void selection_changed__ (GtkIconView *view, gpointer user_data) {
	GtkTreeModel *model = gtk_icon_view_get_model (view);

	GList *list = gtk_icon_view_get_selected_items (view);
	if (list == NULL) return;

	for (GList *cur = g_list_first(list); cur != NULL; cur = g_list_next(cur)) {
		call_item__(get_id__(model, (GtkTreePath *)cur->data));
	}

	g_list_free (list);
}

static gboolean
query_tooltip__ (GtkWidget  *widget,
			gint        x,
			gint        y,
			gboolean    keyboard_mode,
			GtkTooltip *tooltip,
			gpointer    user_data)
{
	GtkTreePath *path;
	GtkTreeModel *model;
	switch(((const char*)user_data)[0]) {
	case 'i':
	{
		GtkIconView *view = GTK_ICON_VIEW (widget);
		if (!gtk_icon_view_get_tooltip_context (view, &x, &y, keyboard_mode, NULL, &path, NULL))
			return FALSE;
		model = gtk_icon_view_get_model (view);
		break;
	}
	case 't':
	{
		GtkTreeView *view = GTK_TREE_VIEW (widget);
		if (!gtk_tree_view_get_tooltip_context (view, &x, &y, keyboard_mode, NULL, &path, NULL))
			return FALSE;
		model = gtk_tree_view_get_model (view);
		break;
	}
	default:
		return FALSE;
	}
	int id = get_id__(model, path);
	if(id <= 0)
		return FALSE;

	callback_item___* si = callback_item__(id);
	if(si->tooltip_.size() > 0) {
		gtk_tooltip_set_markup (tooltip, si->tooltip_.c_str());
		return TRUE;
	}
	return FALSE;
}

static void changed__(GtkWidget * widget, gpointer user_data) {
	GtkTreeIter iter;
	GtkTreeModel *model;
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {
		int id = 0;
		gtk_tree_model_get(model, &iter, ID_COLUMN, &id, -1);
		call_item__(id);
	}
}
static void
row_activated__ (GtkTreeView       *tree_view,
               GtkTreePath       *path,
               GtkTreeViewColumn *column,
               gpointer           user_data) {
    GtkTreeIter   iter;
    GtkTreeModel *model = gtk_tree_view_get_model(tree_view);
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
		int id = 0;
		gtk_tree_model_get(model, &iter, ID_COLUMN, &id, -1);
		call_item__(id, 1);
    }
}

GtkNotebook* toolbar2___::left_book__(GtkBox* box2) {
	GtkNotebook* n = NULL;
	if(!left_book_) {
		GtkWidget* w = gtk_notebook_new ();
		n = GTK_NOTEBOOK (w);
		gtk_notebook_set_tab_pos (n, GTK_POS_TOP);
		gtk_notebook_set_scrollable (n, true);
		gtk_box_pack_start(box2,w,FALSE,FALSE,0);
		left_book_ = w;
	} else {
		n = GTK_NOTEBOOK (left_book_);
	}
	return n;
}

void toolbar2___::init1__(GtkWidget* box1, toolbar2_item___* item) {
	GtkBox* box2 = GTK_BOX(box1);
	GtkWidget *scrolled = gtk_scrolled_window_new (NULL, NULL);
	item->scrolled_ = scrolled;
	gtk_scrolled_window_set_policy (item->scrolled__(), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	if(item->in_book_) {
		GtkWidget* label = gtk_label_new ("");
		item->label_ = label;
		gtk_notebook_append_page( left_book__(box2), scrolled, label );
	} else {
		gtk_box_pack_start(box2,scrolled,FALSE,FALSE,0);
		item->label_ = NULL;
	}
}

void toolbar2___::init2__(toolbar2_item___* item) {
	g_object_set (item->widget_, "has-tooltip", TRUE, NULL);
	g_signal_connect (item->widget_, "query-tooltip", G_CALLBACK (query_tooltip__), (gpointer)(item->tag_));
}

void toolbar2___::init__(GtkWidget* box1, icon_item___* item) {
	if(item->is_init_)
		return;
	item->is_init_ = true;
	init1__(box1, item);

	GtkWidget *view = gtk_icon_view_new();
	item->widget_ = view;
	GtkIconView *view2 = item->view__();
	gtk_container_add(item->container__(),view);
	gtk_icon_view_set_item_width (view2, 0);
	g_signal_connect (view, "selection-changed", G_CALLBACK (selection_changed__), NULL);

	init2__(item);

	GtkListStore *store = gtk_list_store_new (COLUMNS, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING);
	item->store_ = store;
	gtk_icon_view_set_model (view2, GTK_TREE_MODEL (store));
	gtk_icon_view_set_pixbuf_column (view2, PIXBUF_COLUMN);
	gtk_icon_view_set_text_column (view2, TITLE_COLUMN);
}

void toolbar2___::init__(GtkWidget* box1, tree_item___* item) {
	if(item->is_init_)
		return;
	item->is_init_ = true;
	init1__(box1, item);

	GtkWidget *view = gtk_tree_view_new();
	item->widget_ = view;
	GtkTreeView *view2 = item->view__();
	gtk_container_add(item->container__(),view);

	GtkTreeSelection *selection = gtk_tree_view_get_selection(view2);
	g_signal_connect(selection, "changed", G_CALLBACK(changed__), NULL);
	g_signal_connect(view, "row-activated", (GCallback) row_activated__, NULL);

	init2__(item);

	GtkTreeStore *store = gtk_tree_store_new (COLUMNS, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING);
	item->store_ = store;
	gtk_tree_view_set_model(view2, GTK_TREE_MODEL (store));

	GtkTreeViewColumn *col = gtk_tree_view_column_new();
	item->col_ = col;
	gtk_tree_view_append_column(view2, col);
	GtkCellRenderer *renderer;
	renderer = gtk_cell_renderer_pixbuf_new ();
	gtk_tree_view_column_pack_start (col, renderer, false);
	gtk_tree_view_column_add_attribute(col, renderer, "pixbuf", PIXBUF_COLUMN);
	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_add_attribute(col, renderer, "text", TITLE_COLUMN);
}

void icon_item___::store_add__(callback_item___* si, GdkPixbuf *pixbuf) {
	GtkTreeIter iter;
	gtk_list_store_append (store_, &iter);
	gtk_list_store_set (store_, &iter,
			ID_COLUMN, si->id_,
			PIXBUF_COLUMN, pixbuf,
			TITLE_COLUMN, si->title_.c_str(),
			-1);
}

void tree_item___::store_add__(callback_item___* si, GdkPixbuf *pixbuf) {
	GtkTreeIter iter2;
	GtkTreePath *path;
	if(!up_.empty()) {
		path = gtk_tree_path_new_from_string (up_.c_str());
		gtk_tree_model_get_iter(model__(), &iter2, path);
		gtk_tree_path_free (path);
	}

	GtkTreeIter iter;
	gtk_tree_store_append (store_, &iter, up_.empty() ? NULL : &iter2);
	gtk_tree_store_set(store_, &iter,
			ID_COLUMN, si->id_,
			PIXBUF_COLUMN, pixbuf,
			TITLE_COLUMN, si->title_.c_str(),
			-1);

	path = gtk_tree_model_get_path (model__(), &iter);
	last_ = gtk_tree_path_to_string (path);
	gtk_tree_path_free (path);
}

static bool set__(size_t& i2, deque<string>* p, int& i) {
	if(buzu__(++i2, p)) return false;
	i = s2i__((*p)[i2]);
	return true;
}
static bool set__(size_t& i2, deque<string>* p, string& s) {
	if(buzu__(++i2, p)) return false;
	s = (*p)[i2];
	return true;
}

void toolbar2___::with__(window___* w, void*shangji,void*ce,deque<string>* p) {
	toolbar2_item___* item;
	if((*p)[1] == toolbar2_tag2_) {
		init__(w->box2__(), left_icon_item_);
		item = left_icon_item_;
	} else if((*p)[1] == toolbar2_tag3_) {
			init__(w->box2__(), tree_item_);
			item = tree_item_;
	} else {
		init__(w->box__(), icon_item_);
		item = icon_item_;
	}
	for(size_t i2=2;i2<p->size();i2++){
		const string& p2=(*p)[i2];
#ifdef ver_gtk3_
		if(p2 == "宽") {
			if(buzu__(++i2, p)) return;
			gtk_scrolled_window_set_min_content_width(item->scrolled__(), s2i__((*p)[i2]));
			continue;
		}
		if(p2 == "高") {
			if(buzu__(++i2, p)) return;
			gtk_scrolled_window_set_min_content_height(item->scrolled__(), s2i__((*p)[i2]));
			continue;
		}
#endif
		if(p2 == "名") {
			if(buzu__(++i2, p)) return;
			if(item->label_) {
				gtk_label_set_markup(GTK_LABEL(item->label_), (*p)[i2].c_str());
			}
			continue;
		}
		if(p2 == "钮宽") {if(set__(i2, p, item->btn_width_)) continue; return;}
		if(p2 == "钮高") {if(set__(i2, p, item->btn_height_)) continue; return;}
		if(p2 == "无标题") {
			if(item->tag_[0] == 'i') {
				gtk_icon_view_set_text_column (GTK_ICON_VIEW (item->widget_), -1);
				continue;
			}
			buzhichi__(i2, p);
			return;
		}
		//gtk_icon_view_set_selection_mode (iconview__(), GTK_SELECTION_MULTIPLE);
		if(p2 == "列头") {
			if(buzu__(++i2, p)) return;
			if(item->tag_[0] == 't') {
				tree_item___* ti = (tree_item___*)item;
				gtk_tree_view_column_set_title(ti->col_, (*p)[i2].c_str());
				continue;
			}
			buzhichi__(i2, p);
			return;
		}
		if(p2 == "加钮") {
			string title, tooltip, code, arg, code2, arg2;
			string set_up;
			for(i2++;i2<p->size();i2++){
				const string& p3=(*p)[i2];
				if(p3 == "名") {if(set__(i2, p, title)) continue; return;}
				if(p3 == "提示") {if(set__(i2, p, tooltip)) continue; return;}
				if(p3 == "代码") {if(set__(i2, p, code)) continue; return;}
				if(p3 == "附") {if(set__(i2, p, arg)) continue; return;}
				if(p3 == "缺省代码") {if(set__(i2, p, item->def_code_)) continue; return;}
				if(p3 == "缺省附") {if(set__(i2, p, item->def_arg_)) continue; return;}
				if(p3 == "双击代码") {if(set__(i2, p, code2)) continue; return;}
				if(p3 == "双击附") {if(set__(i2, p, arg2)) continue; return;}
				if(p3 == "缺省双击代码") {if(set__(i2, p, item->def_code2_)) continue; return;}
				if(p3 == "缺省双击附") {if(set__(i2, p, item->def_arg2_)) continue; return;}
				if(p3 == "设置上") {if(set__(i2, p, set_up)) continue; return;}
				if(p3 == "恢复上") {
					if(item->tag_[0] == 't') {
						string restore_up;
						if(set__(i2, p, restore_up)) {
							const char* ret = call4__(ce, restore_up, shangji, 0, NULL);
							if(!ret) return;
							((tree_item___*)item)->up_ = ret;
						}
					} else {
						buzhichi__(i2, p);
					}
					return;
				}
				if(p3 == "大小") {
					if(buzu__(++i2, p)) return;
					item->btn_width_ = item->btn_height_ = s2i__((*p)[i2]) * 8;
					continue;
				}
				if(p3 == "-") continue;

				GdkPixbuf *pixbuf;
				if(p3.size() > 0) {
					if(p3.find(".") != string::npos)
						pixbuf = gdk_pixbuf_new_from_file_at_size (p3.c_str(), item->btn_width_, item->btn_height_, NULL);
					else
						pixbuf = gtk_icon_theme_load_icon(gtk_icon_theme_get_default(), p3.c_str(), item->btn_width_,
							GTK_ICON_LOOKUP_USE_BUILTIN, NULL);
				} else
					pixbuf = NULL;

				callback_item___* si = new callback_item___(title,
						!code.empty() ? code : item->def_code_,
						!arg.empty() ? arg : item->def_arg_,
						tooltip);
				si->code2_ = !code2.empty() ? code2 : item->def_code2_;
				si->arg2_ = !arg2.empty() ? arg2 : item->def_arg2_;
				item->store_add__(si, pixbuf);

				g_object_unref (pixbuf);

				if(!set_up.empty()) {
					if(item->tag_[0] == 't') {
						tree_item___* ti = (tree_item___*)item;
						const char* argv[] = {ti->up_.c_str()};
						if(!call4__(ce, set_up, shangji, 1, argv))
							return;
						ti->up_ = ti->last_;
					} else {
						buzhichi__(i2, p);
						return;
					}
					set_up.clear();
				}
				code.clear();
				arg.clear();
				tooltip.clear();
			}
			break;
		}
		buzhichi__(i2, p);
		return;
	}
}

bool toolbar2___::use_tag__(const string& p1) {
	return p1==toolbar2_tag_ || p1==toolbar2_tag2_ || p1==toolbar2_tag3_;
}

toolbar2___::toolbar2___() {
	left_book_ = NULL;
	icon_item_ = new icon_item___(false);
	left_icon_item_ = new icon_item___(true);
	tree_item_ = new tree_item___(true);
}

toolbar2___::~toolbar2___() {
}
