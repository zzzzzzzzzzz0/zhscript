/*
 * main.cpp
 *
 *  Created on: 2015年7月11日
 *      Author: zzzzzzzzzzz
 */

#include <libgnomeui/libgnomeui.h>
#include <string>
using namespace std;

#include "def1.h"
#include "l4/keyword.h"

static callback2_2___ cb_;
static callback3_2___ cb2_;
static void* jsq_;
static void* main_qu_;
static l4_err_out___ l4_err_out_;

dlle___ void init__(void* jsq, callback2_2___ cb, callback3_2___ cb2, void* main_qu, l4_err_out___ l4_err_out) {
	jsq_ = jsq;
	cb_ = cb;
	cb2_ = cb2;
	main_qu_ = main_qu;
	l4_err_out_ = l4_err_out;
}

dlle___ void init2__(char* name) {
	char* argv[] = {"gnomeu4"};
	gnome_init_with_popt_table(name, "1.0", 1, argv, NULL, 0, NULL);
}

class item___ {
public:
	string name_, code_;
	item___(const char* name, const char* code) {
		name_ = name;
		code_ = code;
	}
};

static void cb__(item___* i) {
	int err;
	const char*ret = cb_(jsq_, main_qu_, &err, NULL, i->code_.c_str(), false, i->name_.c_str(), 0);
	switch(err) {
	case jieshiqi_err_go_ + keyword_exit_:
		break;
	default:
		l4_err_out_(jsq_, ret, err, 1);
	}
}

static gboolean save_yourself__(GnomeClient *client, gint phase, GnomeRestartStyle restart, gint shutdown, GnomeInteractStyle interact, gint fast, gpointer user_data) {
	cb__((item___*)user_data);
	return TRUE;
}

dlle___ void signal_connect_save_yourself__(char* code) {
	item___* i = new item___("save-yourself", code);
	gtk_signal_connect(GTK_OBJECT(gnome_master_client()), i->name_.c_str(), GTK_SIGNAL_FUNC(save_yourself__), i);
}

static void die__(GnomeClient *client, gpointer user_data) {
	cb__((item___*)user_data);
}

dlle___ void signal_connect_die__(char* code) {
	item___* i = new item___("die", code);
	gtk_signal_connect(GTK_OBJECT(gnome_master_client()), i->name_.c_str(), GTK_SIGNAL_FUNC(die__), i);
}
