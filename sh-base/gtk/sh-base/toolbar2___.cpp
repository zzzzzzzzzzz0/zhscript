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

enum {
	ID_COLUMN,
	PIXBUF_COLUMN,
	TITLE_COLUMN,
	COLUMNS
};

static int get_id__(GtkTreeModel *model, GtkTreePath *path, bool path_free = true) {
	int id = 0;
	GtkTreeIter iter;
	if (gtk_tree_model_get_iter(model, &iter, path) == TRUE) {
		gtk_tree_model_get(model, &iter, ID_COLUMN, &id, -1);
	}
	if(path_free)
		gtk_tree_path_free(path);
	return id;
}

static void icon_view_select__(GtkIconView *view, const char* code3 = NULL, void* shangji = NULL, void* ce = NULL) {
	GtkTreeModel *model = gtk_icon_view_get_model (view);

	GList *list = gtk_icon_view_get_selected_items (view);
	if (list == NULL) return;

	for (GList *cur = g_list_first(list); cur != NULL; cur = g_list_next(cur)) {
		call_item__(get_id__(model, (GtkTreePath *)cur->data), code3 ? 2 : 0, code3, shangji, ce);
	}

	g_list_free (list);
}
static void selection_changed__ (GtkIconView *view, gpointer user_data) {
	icon_view_select__(view);
}
static void
item_activated__ (GtkIconView *iconview,
               GtkTreePath *path,
               gpointer     user_data) {
	call_item__(get_id__(gtk_icon_view_get_model (iconview), path, false), 1);
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
	switch((char)(long)user_data) {
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
	int id = get_id__(gtk_tree_view_get_model(tree_view), path, false);
	if(id > 0)
		call_item__(id, 1);
}
static gboolean button_press_event__(GtkWidget *widget, GdkEventButton *event, gpointer userdata) {
	if (event->type == GDK_BUTTON_PRESS && event->button == 3) {
		GtkTreePath *path;
		GtkTreeView *tree_view = GTK_TREE_VIEW (widget);
		if(gtk_tree_view_get_path_at_pos (tree_view, (int) event->x, (int) event->y, &path, NULL, NULL, NULL)) {
			int id = get_id__(gtk_tree_view_get_model(tree_view), path, false);
			if(id > 0) {
				call_item__(id, 32);
				return TRUE;
			}
		}
	}
	return FALSE;
}

static bool iter_by_id__(GtkTreeModel *m, int id2, GtkTreeIter *i) {
	if (gtk_tree_model_get_iter_first(m, i)) {
		for(;;) {
			int id = 0;
			gtk_tree_model_get(m, i, ID_COLUMN, &id, -1);
			if(id2 == id) {
				return true;
			}
			if(!gtk_tree_model_iter_next(m, i))
				break;
		}
	}
	return false;
}

GtkNotebook* toolbar2___::book__(GtkBox* box2, char in) {
	GtkNotebook* n = NULL;
	GtkWidget *&nb = in == 'l' ? left_book_ : right_book_;
	if(!nb) {
		GtkWidget* w = gtk_notebook_new ();
		n = GTK_NOTEBOOK (w);
		gtk_notebook_set_tab_pos (n, GTK_POS_TOP);
		gtk_notebook_set_scrollable (n, true);
		if(in == 'l')
			gtk_box_pack_start(box2,w,FALSE,FALSE,0);
		else
			gtk_box_pack_end(box2,w,FALSE,FALSE,0);
		nb = w;
	} else {
		n = GTK_NOTEBOOK (nb);
	}
	return n;
}

void toolbar2___::init1__(GtkWidget* box1, toolbar2_item___* item) {
	GtkBox* box2 = GTK_BOX(box1);
	GtkWidget *scrolled = gtk_scrolled_window_new (NULL, NULL);
	item->scrolled_ = scrolled;
	gtk_scrolled_window_set_policy (item->scrolled__(), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	switch(item->in_book_) {
	case 'l': case 'r':
	{
		GtkWidget* label = gtk_label_new ("");
		item->label_ = label;
		gtk_notebook_append_page(book__(box2, item->in_book_), scrolled, label);
		break;
	}
	default:
		if(!item->in_book_)
			gtk_box_pack_start(box2,scrolled,FALSE,FALSE,0);
		else
			gtk_box_pack_end(box2,scrolled,FALSE,FALSE,0);
		item->label_ = NULL;
		break;
	}
}

void toolbar2___::init2__(toolbar2_item___* item) {
	gtk_widget_set_can_focus(item->widget_, false);
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
	GtkIconView *view2 = item->icon_view__();
	gtk_container_add(item->container__(),view);
	gtk_icon_view_set_item_width (view2, 0);
	g_signal_connect (view, "selection-changed", G_CALLBACK (selection_changed__), NULL);
	g_signal_connect (view, "item-activated", G_CALLBACK (item_activated__), NULL);

	init2__(item);

	GtkListStore *store = gtk_list_store_new (COLUMNS, G_TYPE_INT, GDK_TYPE_PIXBUF, G_TYPE_STRING);
	item->store_ = store;
	gtk_icon_view_set_model (view2, item->model__());
	gtk_icon_view_set_pixbuf_column (view2, PIXBUF_COLUMN);
	//gtk_icon_view_set_text_column (view2, TITLE_COLUMN);
	gtk_icon_view_set_markup_column (view2, TITLE_COLUMN);
}

void toolbar2___::init__(GtkWidget* box1, tree_item___* item) {
	if(item->is_init_)
		return;
	item->is_init_ = true;
	init1__(box1, item);

	GtkWidget *view = gtk_tree_view_new();
	item->widget_ = view;
	GtkTreeView *view2 = item->tree_view__();
	gtk_container_add(item->container__(),view);

	GtkTreeSelection *selection = gtk_tree_view_get_selection(view2);
	g_signal_connect(selection, "changed", G_CALLBACK(changed__), NULL);
	g_signal_connect(view, "row-activated", (GCallback) row_activated__, NULL);
	g_signal_connect (view, "button_press_event", G_CALLBACK (button_press_event__), NULL);

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

void icon_item___::store_add__(callback_item___* si, GdkPixbuf *pixbuf, int posi) {
	switch(posi) {
	case -2: case -3:
	{
		GList *list = gtk_icon_view_get_selected_items (icon_view__());
		if (list) {
			GtkTreeModel *m = model__();
			int id_first = get_id__(m, (GtkTreePath *)(g_list_last(list)->data));
			int id_last = g_list_length(list) > 1 ? get_id__(m, (GtkTreePath *)(g_list_first(list)->data)) : id_first;
			/*for(GList *l = g_list_first(list); l; l = g_list_next(l)) {
				int id = get_id__(m, (GtkTreePath *)l->data);
				cout << id << endl;
			}*/
			g_list_free (list);

			GtkTreeIter i;
			if (gtk_tree_model_get_iter_first(m, &i)) {
				int posi2 = posi;
				for(int i2 = 1;; i2++) {
					int id = 0;
					gtk_tree_model_get(m, &i, ID_COLUMN, &id, -1);
					if(posi == -3) {
						if(id == id_first) {
							posi2 = i2 - 1;
							break;
						}
					} else {
						if(id == id_last) {
							posi2 = i2;
							break;
						}
					}
					if(!gtk_tree_model_iter_next(m, &i))
						break;
				}
				posi = posi2;
			}
		}
		break;
	}
	}
	GtkTreeIter iter;
	gtk_list_store_insert (store_, &iter, posi);
	gtk_list_store_set (store_, &iter,
			ID_COLUMN, si->id_,
			PIXBUF_COLUMN, pixbuf,
			TITLE_COLUMN, si->title_.c_str(),
			-1);
}

void tree_item___::store_add__(callback_item___* si, GdkPixbuf *pixbuf, int posi) {
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

static gboolean
tree_foreach_cb__ (GtkTreeModel *model,
                            GtkTreePath *path,
                            GtkTreeIter *iter,
                            gpointer data) {
	callback_item___* cbi = (callback_item___*)data;
	int id = 0;
	gtk_tree_model_get(model, iter, ID_COLUMN, &id, -1);
	char buf[8];
	sprintf(buf, "%d", id);
	callback_item___* cbi2 = callback_item__(id);
	#define argc 4
	const char* argv[argc] = {cbi2->title_.c_str(), cbi2->arg__(0), cbi2->tooltip_.c_str(), buf};
	int err;
	call4__(cbi->data__(0), cbi->code__(0), cbi->data__(1), argc, argv, &err, true);
	if(err)
		return true;
	return false;
}
static void tree_foreach__(GtkTreeModel *model, const string& code, void* ce, void* shangji) {
	callback_item___* cbi = new callback_item___();
	cbi->add_code__(code);
	cbi->add_data__(ce);
	cbi->add_data__(shangji);
	gtk_tree_model_foreach (model, tree_foreach_cb__, cbi);
}
void toolbar2_item___::for__(const string& code, void* ce, void* shangji) {
	tree_foreach__(model__(), code, ce, shangji);
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

void toolbar2___::with__(window___* w, void*shangji,void*ce,deque<string>* p, int addr_fmt, char*buf) {
	toolbar2_item___* item;
	if((*p)[1] == toolbar2_tag2_) {
		init__(w->box2__(), left_icon_item_);
		item = left_icon_item_;
	} else if((*p)[1] == toolbar2_tag3_) {
		init__(w->box2__(), tree_item_);
		item = tree_item_;
	} else if((*p)[1] == toolbar2_tag4_) {
		init__(w->box3__(), right_icon_item_);
		item = right_icon_item_;
	} else if((*p)[1] == toolbar2_tag5_) {
		init__(w->box4__(), bottom_icon_item_);
		item = bottom_icon_item_;
	} else if((*p)[1] == toolbar2_tag6_) {
		init__(w->box3__(), right_tree_item_);
		item = right_tree_item_;
	} else {
		init__(w->box__(), icon_item_);
		item = icon_item_;
	}
	for(size_t i2=2;i2<p->size();i2++){
		const string& p2=(*p)[i2];
		if(p2 == "选择") {
			GtkTreeModel *m = item->model__();
			GtkTreeIter i;
			GtkTreePath *path;
			for(size_t i3 = i2;i3 < p->size() - 1;) {
				int id2 = 0;
				if(!set__(i3, p, id2)) return;
				if(!iter_by_id__(m, id2, &i)) {
					buzhichi__(i3, p);
					return;
				}
				switch(item->tag_) {
				case 'i':
					path = gtk_tree_model_get_path (m, &i);
					gtk_icon_view_select_path (item->icon_view__(), path);
					gtk_tree_path_free (path);
					break;
				}
			}
			return;
		}
		if(p2 == "遍历") {
			if(buzu__(++i2, p)) return;
			item->for__((*p)[i2], ce, shangji);
			continue;
		}
		if(p2 == "设") {
			int id = 0;
			if(!set__(i2, p, id)) return;
			callback_item___* cbi = callback_item__(id);
			if(!cbi) {
				wufa__(p->size(), p);
				return;
			}
			GtkTreeModel *m = item->model__();
			GtkTreeIter i;
			for(i2++; i2 < p->size(); i2++) {
				const string& p3 = (*p)[i2];
				if(p3 == "名") {
					if(set__(i2, p, cbi->title_)) {
						if(!iter_by_id__(m, cbi->id_, &i)) {
							buzhichi__(i2, p);
							return;
						}
						switch(item->tag_) {
						case 'i':
							gtk_list_store_set(((icon_item___*)item)->store_, &i, TITLE_COLUMN, cbi->title_.c_str(), -1);
							continue;
						}
					}
					return;
				}
				if(p3 == "提示") {if(set__(i2, p, cbi->tooltip_)) continue; return;}
				if(p3 == "图标") {
					string name;
					if(!set__(i2, p, name)) return;
					GdkPixbuf *pixbuf = item->get_icon__(name);
					switch(item->tag_) {
					case 'i':
						gtk_list_store_set(((icon_item___*)item)->store_, &i, PIXBUF_COLUMN, pixbuf, -1);
						break;
					}
					g_object_unref (pixbuf);
					continue;
				}
				buzhichi__(i2, p);
			}
			break;
		}
		if(p2 == "获取") {
			string code3;
			if(!set__(i2, p, code3)) return;
			switch(item->tag_) {
			case 'i':
				icon_view_select__(item->icon_view__(), code3.c_str(), shangji, ce);
				break;
			}
			continue;
		}
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
		if(p2 == "名提示") {item->title_tooltip_ = true; continue;}
		if(p2 == "可拖动") {
			switch(item->tag_) {
			case 'i':
				gtk_icon_view_set_reorderable(item->icon_view__(), true);
				break;
			case 't':
				gtk_tree_view_set_reorderable(item->tree_view__(), true);
				break;
			}
			continue;
		}
		if(p2 == "可选择") {
			int i;
			if(!set__(i2, p, i)) return;
			switch(item->tag_) {
			case 'i':
				gtk_icon_view_set_selection_mode(item->icon_view__(), (GtkSelectionMode)i);
				break;
			}
			continue;
		}
		if(p2 == "无标题") {
			if(item->tag_ == 'i') {
				//gtk_icon_view_set_text_column (item->icon_view__(), -1);
				gtk_icon_view_set_markup_column (item->icon_view__(), -1);
				continue;
			}
			buzhichi__(i2, p);
			return;
		}
		//gtk_icon_view_set_selection_mode (iconview__(), GTK_SELECTION_MULTIPLE);
		if(p2 == "列头") {
			if(buzu__(++i2, p)) return;
			if(item->tag_ == 't') {
				tree_item___* ti = (tree_item___*)item;
				gtk_tree_view_column_set_title(ti->col_, (*p)[i2].c_str());
				continue;
			}
			buzhichi__(i2, p);
			return;
		}
		if(p2 == "删钮") {
			GtkTreeModel *m = item->model__();
			GtkTreeIter i;
			for(size_t i3 = i2;i3 < p->size() - 1;) {
				int id2 = 0;
				if(!set__(i3, p, id2)) return;
				if(!iter_by_id__(m, id2, &i)) {
					buzhichi__(i3, p);
					return;
				}
				item->store_del__(&i);
			}
			break;
		}
		if(p2 == "加钮") {
			string title, tooltip, code, arg, code2, arg2, code3_2;
			string set_up;
			int posi = -1;
			for(i2++;i2<p->size();i2++){
				const string& p3=(*p)[i2];
				if(p3 == "名") {if(set__(i2, p, title)) continue; return;}
				if(p3 == "提示") {if(set__(i2, p, tooltip)) continue; return;}
				if(p3 == "代码") {if(set__(i2, p, code)) continue; return;}
				if(p3 == "附") {if(set__(i2, p, arg)) continue; return;}
				if(p3 == "位置") {if(set__(i2, p, posi)) continue; return;}
				if(p3 == "缺省代码") {if(set__(i2, p, item->def_code_)) continue; return;}
				if(p3 == "缺省附") {if(set__(i2, p, item->def_arg_)) continue; return;}
				if(p3 == "双击代码") {if(set__(i2, p, code2)) continue; return;}
				if(p3 == "双击附") {if(set__(i2, p, arg2)) continue; return;}
				if(p3 == "缺省双击代码") {if(set__(i2, p, item->def_code2_)) continue; return;}
				if(p3 == "缺省双击附") {if(set__(i2, p, item->def_arg2_)) continue; return;}
				if(p3 == "右击代码") {if(set__(i2, p, code3_2)) continue; return;}
				if(p3 == "缺省右击代码") {if(set__(i2, p, item->def_code3_2_)) continue; return;}
				if(p3 == "设置上") {if(set__(i2, p, set_up)) continue; return;}
				if(p3 == "恢复上") {
					if(item->tag_ == 't') {
						string restore_up;
						if(set__(i2, p, restore_up)) {
							int err;
							const char* ret = call4__(ce, restore_up, shangji, 0, NULL, &err);
							if(err) return;
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

				GdkPixbuf *pixbuf = item->get_icon__(p3);

				callback_item___* si = new callback_item___(title,
						!code.empty() ? code : item->def_code_,
						!arg.empty() ? arg : item->def_arg_,
								tooltip.empty() && item->title_tooltip_ ? title : tooltip);
				si->add_code__(!code2.empty() ? code2 : item->def_code2_);
				si->add_arg__(!arg2.empty() ? arg2 : item->def_arg2_);
				si->add_code__(!code3_2.empty() ? code3_2 : item->def_code3_2_);
				item->store_add__(si, pixbuf, posi);

				g_object_unref (pixbuf);

				if(!set_up.empty()) {
					if(item->tag_ == 't') {
						tree_item___* ti = (tree_item___*)item;
						const char* argv[] = {ti->up_.c_str()};
						int err;
						call4__(ce, set_up, shangji, 1, argv, &err);
						if(err)
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
				code2.clear();
				arg2.clear();
				code3_2.clear();
				posi = -1;
			}
			break;
		}
		if(p2 == "清空") {
			switch(item->tag_) {
			case 'i':
				gtk_list_store_clear (((icon_item___*)item)->store_);
				continue;
			}
		}
		if(p2 == "地址") {
			if(addr_fmt == 16)
				l2x__((long)item->scrolled_, buf);
			else
				l2s__((long)item->scrolled_, buf);
			continue;
		}
		buzhichi__(i2, p);
		return;
	}
}

GdkPixbuf *toolbar2_item___::get_icon__(const string& name) {
	GdkPixbuf *p = NULL;
	if(name.size() > 0) {
		if(name.find(".") != string::npos)
			p =  gdk_pixbuf_new_from_file_at_size (name.c_str(), btn_width_, btn_height_, NULL);
		else
			p = get_stock_icon__(name.c_str());
		if(!p)
			p = get_stock_icon__("gtk-no");
	}
	return p;
}
GdkPixbuf *toolbar2_item___::get_stock_icon__(const char* name) {
	return gtk_icon_theme_load_icon(gtk_icon_theme_get_default(), name, btn_width_, GTK_ICON_LOOKUP_USE_BUILTIN, NULL);
}

bool toolbar2___::use_tag__(const string& p1) {
	return p1==toolbar2_tag_
			|| p1==toolbar2_tag2_
			|| p1==toolbar2_tag3_
			|| p1==toolbar2_tag4_
			|| p1==toolbar2_tag5_
			|| p1==toolbar2_tag6_;
}

toolbar2___::toolbar2___() {
	left_book_ = right_book_ = NULL;
	icon_item_ = new icon_item___(0);
	left_icon_item_ = new icon_item___('l');
	tree_item_ = new tree_item___('l');
	right_icon_item_ = new icon_item___('r');
	bottom_icon_item_ = new icon_item___('b');
	right_tree_item_ = new tree_item___('r');
}

toolbar2___::~toolbar2___() {
}
