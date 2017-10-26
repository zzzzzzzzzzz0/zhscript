/*
 * menu.cpp
 *
 *  Created on: 2013年12月27日
 *      Author: zzzzzzzzzzz
 */

#include <gtk/gtk.h>
#include <stdio.h>
#include <string>
#include <deque>
using namespace std;

#include "def1.h"
#include "for_arg_.h"
#include "l4/keyword.h"
#include "call_util.cpp"

int s2i__(const string& s,int i=0){
	int i1=i;
	const char* s1=s.c_str();
	sscanf(s1,"%d",&i1);
	return i1;
}

bool err_buzu2__(const deque<string>* p, size_t need, int* err){
	if(p->size()<need){
		*err = 10;
		return true;
	}
	return false;
}

void* jsq_;
void* main_qu_;
callback3_2___ cb3_;
l4_err_out___ l4_err_out_;

void call4__(const char* code, const char* name, int argc = 0, const char** argv = NULL) {
	int err;
	const char*ret = cb3_(jsq_, main_qu_, &err, NULL, code, false, name, argc, argv, 0);
	switch(err) {
	case jieshiqi_err_go_ + keyword_exit_:
		break;
	default:
		l4_err_out_(jsq_, ret, err, 1);
	}
}

class signal_item___ {
public:
	string code_;
};

void item_cb__(GtkWidget *item, gpointer user_data) {
	signal_item___* gi = (signal_item___*)user_data;
	call4__(gi->code_.c_str(), gtk_menu_item_get_label(GTK_MENU_ITEM(item)));
}

bool menu_1__(GtkWidget *menu,
		deque<string>& p1, size_t& i, const char *code1,
		int* err, char* buf, long siz) {
	const char *code = NULL, *set_code = NULL, *icon = NULL;
	GtkIconSize size = GTK_ICON_SIZE_MENU;
	char type = ' ';
	GSList *radio_group = NULL;
	char buf2[32];
	const char* argv[] = {buf2};
	for(; i < p1.size(); i++) {
		const string& s1 = p1[i];
		if(s1 == "代码") {
			if(err_buzu2__(&p1, ++i, err))
				return false;
			code = p1[i].c_str();
			continue;
		}
		if(s1 == "缺省代码") {
			if(err_buzu2__(&p1, ++i, err))
				return false;
			code1 = p1[i].c_str();
			if(!code1[0])
				code1 = NULL;
			continue;
		}
		if(s1 == "得") {
			if(err_buzu2__(&p1, ++i, err))
				return false;
			set_code = p1[i].c_str();
			continue;
		}
		if(s1 == "图标") {
			if(err_buzu2__(&p1, ++i, err))
				return false;
			icon = p1[i].c_str();
			continue;
		}
		if(s1 == "大小"){
			if(err_buzu2__(&p1, ++i, err))
				return false;
			size=(GtkIconSize)s2i__(p1[i]);
			continue;
		}
		if(s1 == "子菜单"){
			if(err_buzu2__(&p1, ++i, err))
				return false;
			GtkWidget *item = gtk_menu_item_new_with_label(p1[i++].c_str());
			gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
			GtkWidget *menu2 = gtk_menu_new();
			gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu2);
			if(i == p1.size()) {
				sprintf(buf, "%lx", (long)menu2);
				return false;
			}
			if(!menu_1__(menu2, p1, i, code1, err, buf, siz))
				return false;
			continue;
		}
		if(s1 == "子菜单止"){
			return true;
		}
		if(s1 == "-"){
			gtk_menu_shell_append(GTK_MENU_SHELL(menu), gtk_separator_menu_item_new());
			continue;
		}
		if(s1 == ".."){
			gtk_menu_shell_append(GTK_MENU_SHELL(menu), gtk_tearoff_menu_item_new());
			continue;
		}
		if(s1 == "多选") {
			type = 'c';
			radio_group = NULL;
			continue;
		}
		if(s1 == "多选/已") {
			type = 'C';
			radio_group = NULL;
			continue;
		}
		if(s1 == "单选") {
			type = 'r';
			continue;
		}
		if(s1 == "单选/已") {
			type = 'R';
			continue;
		}
		if(s1 == "普通") {
			type = ' ';
			radio_group = NULL;
			continue;
		}
		if(s1 == "") {
			if(err_buzu2__(&p1, ++i, err))
				return false;
			const string& label = p1[i];
			GtkWidget *item;
			if(icon) {
				item = gtk_image_menu_item_new_with_label (label.c_str());
				gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM(item),
						gtk_image_new_from_stock(icon, size));
				icon = NULL;
			} else {
				switch(type) {
				case 'c':
				case 'C':
					item = gtk_check_menu_item_new_with_label(label.c_str());
					if(type == 'C')
						gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item), true);
					break;
				case 'r':
				case 'R':
					item = gtk_radio_menu_item_new_with_label(radio_group, label.c_str());
					radio_group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(item));
					if(type == 'R') {
						gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item), true);
						type = 'r';
					}
					break;
				default:
					item = gtk_menu_item_new_with_label(label.c_str());
					break;
				}
			}
			if(code || code1) {
				signal_item___* gi = new signal_item___();
				if(code) {
					gi->code_ = code;
					code = NULL;
				} else
					gi->code_ = code1;
				g_signal_connect(G_OBJECT(item), "activate",
						G_CALLBACK (item_cb__), gi);
			}
			gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
			if(set_code) {
				sprintf(buf2, "%lx", (long)item);
				call4__(set_code, NULL, 1, argv);
				set_code = NULL;
			}
			continue;
		}
		*err = 1;
		cpy__(buf, s1.c_str(), siz);
		return false;
	}
	return true;
}

dlle___ GtkWidget* menu_new__(int *err, char* buf, long siz, int argc, ...) {
	deque<string> p1;
	_for_args( argc )
		p1.push_back(s ? s : "");
	_next_args
	GtkWidget *menu = gtk_menu_new();
	size_t i1 = 0;
	const char *code1 = NULL;
	menu_1__(menu, p1, i1, code1, err, buf, siz);
	gtk_widget_show_all(menu);
	return menu;
}

dlle___ void menu_add__(int *err, char* buf, long siz, GtkWidget *menu, int argc, ...) {
	deque<string> p1;
	_for_args( argc )
		p1.push_back(s ? s : "");
	_next_args
	size_t i1 = 0;
	const char *code1 = NULL;
	menu_1__(menu, p1, i1, code1, err, buf, siz);
	gtk_widget_show_all(menu);
}

/*void
menu_popup_pos__ (GtkMenu *menu, gint *x, gint *y, gboolean *push_in, gpointer user_data) {
	//*x -= 50; *y -= 50;
	//*push_in = true;
}*/

dlle___ void menu_popup__(GtkWidget *widget) {
#if GTK_CHECK_VERSION (3, 22, 11)
	gtk_menu_popup_at_pointer(GTK_MENU(widget), NULL);
#else
	gtk_menu_popup(GTK_MENU(widget), NULL, NULL, NULL/*menu_popup_pos__*/, NULL, 0, 0/*GDK_CURRENT_TIME*/);
#endif
}

dlle___ void init__(void* jsq, callback3_2___ cb3,
		l4_err_out___ l4_err_out,
		void* main_qu) {
	jsq_ = jsq;
	cb3_ = cb3;
	l4_err_out_ = l4_err_out;
	main_qu_ = main_qu;
}
