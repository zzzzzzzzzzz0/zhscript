/*
 * wnck.cpp
 *
 *  Created on: 2011-9-8
 *      Author: zzzzzzzzzzz
 */

#include <stdio.h>
#include <libwnck/libwnck.h>
#include"../new_gg/def1.h"
#include "../new_gg/l4/keyword.h"

#include <string>
#include <map>
#include <algorithm>
using namespace std;

static int s2i__(const char* s1,int i){
	int i1=i;
	if(s1) {
		char c=s1[0];
		if(c) {
			if(c=='+')
				s1++;
			sscanf(s1,"%d",&i1);
			if(c=='+')
				i1+=i;
		}
	}
	return i1;
}

static bool has_b__(const char* x) {
	if(x) {
		for(int i = 0; x[i]; i++) {
			if(x[i] == ',') {
				return true;
			}
		}
	}
	return false;
}

static void* jsq_;
static callback2_2___ cb_ = NULL;
static void* main_qu_;
static l4_err_out___ l4_err_out_;

dlle___ void init__(callback2_2___ cb,void* jsq, void* main_qu, l4_err_out___ l4_err_out){
	jsq_=jsq;
	cb_=cb;
	main_qu_ = main_qu;
	l4_err_out_ = l4_err_out;
}

#include "../gjke4/rust.h"
#include "../gjke4/for_err.cpp"
static rust_cb2___     rust_cb_      = NULL;
static rust_cb_free___ rust_cb_free_;
dlle___ void rust_init__(rust_cb2___ cb, rust_cb_free___ f){
	rust_cb_ = cb;
	rust_cb_free_ = f;
}

static void for__(int*err, void *ce, void* shangji, rust_cb___ cb, rust_cb_free___ f,
		const char*code, bool use_aws, const char*fmt,WnckScreen *screen){
	GList *window_l;
	char p1[32], p2[32], p3[2] = {0, 0};
	WnckWorkspace *aws = NULL;
	if(use_aws)
		aws = wnck_screen_get_active_workspace(screen);
	for (window_l = wnck_screen_get_windows (screen); window_l != NULL; window_l = window_l->next){
		WnckWindow *window = WNCK_WINDOW (window_l->data);
		sprintf(p1,fmt,(long)window);

		WnckWorkspace *ws = wnck_window_get_workspace(window);
		int i = wnck_workspace_get_number(ws) + 1;
		//wnck_window_is_on_workspace(window, aws)
		if(aws && ws == aws)
			i = -i;
		sprintf(p2, "%d", i);
		p3[0] = wnck_window_is_skip_tasklist(window) ? '0' : '1';

		if(cb) {
			const char* argv[] = {p1, p2, p3};
			f(cb(ce, shangji, err, '0', code, 3, argv));
		} else {
			cb_(jsq_,shangji,err, ce,code,false, NULL, 3, p1, p2, p3);
		}
		if(for_err__(err, cb))
			break;
	}
}
dlle___ void for__(int*err, void *ce, void* shangji,const char*code, bool use_aws, const char*fmt,WnckScreen *screen){
	for__(err, ce, shangji, NULL, NULL, code, use_aws, fmt,screen);
}
dlle___ void rust_for__(int*err, rust_cb___ cb, rust_cb_free___ f, void* env, void* ret,
		const char*code, bool use_aws, const char*fmt,WnckScreen *screen){
	for__(err, env, ret, cb, f, code, use_aws, fmt,screen);
}

dlle___ int wnck_screen_get_window_stack_i__ (WnckScreen *ws, WnckWindow* ww) {
	GList *l = wnck_screen_get_windows_stacked (ws);
	return g_list_position(l, g_list_find(l, ww));
}

dlle___ void window_get_geometry__(char* buf, WnckWindow* ww) {
	int x1, y1, w1, h1;
	wnck_window_get_geometry(ww, &x1, &y1, &w1, &h1);
	sprintf(buf, "%d,%d,%d,%d", x1, y1, w1, h1);
}

dlle___ void window_set_geometry__(char* buf, WnckWindow* ww, char* x, char* y, char* w, char* h) {
	int x1, y1, w1, h1;
	WnckWindowMoveResizeMask mrm = (WnckWindowMoveResizeMask)0;
	if(has_b__(x)) {
		if(sscanf(x, "%d,%d,%d,%d", &x1, &y1, &w1, &h1) != 4)
			return;
		if(has_b__(y)) {
			int x2, y2, w2, h2;
			switch(sscanf(y, "%d,%d,%d,%d", &x2, &y2, &w2, &h2)) {
			case 4:
				x1 = x2 == 0 ? 0 : (w2 - w1) / x2;
				y1 = y2 == 0 ? 0 : (h2 - h1) / y2;
				break;
			default:
				return;
			}
		}
	} else {
		wnck_window_get_geometry(ww, &x1, &y1, &w1, &h1);
		x1 = s2i__(x, x1);
		y1 = s2i__(y, y1);
		w1 = s2i__(w, w1);
		h1 = s2i__(h, h1);
	}
	if(x)
		mrm = (WnckWindowMoveResizeMask)(mrm | WNCK_WINDOW_CHANGE_X);
	if(y)
		mrm = (WnckWindowMoveResizeMask)(mrm | WNCK_WINDOW_CHANGE_Y);
	if(w)
		mrm = (WnckWindowMoveResizeMask)(mrm | WNCK_WINDOW_CHANGE_WIDTH);
	if(h)
		mrm = (WnckWindowMoveResizeMask)(mrm | WNCK_WINDOW_CHANGE_HEIGHT);
	wnck_window_set_geometry(ww, WNCK_WINDOW_GRAVITY_STATIC, mrm, x1, y1, w1, h1);
	sprintf(buf, "%d,%d,%d,%d", x1, y1, w1, h1);
}

static void z__(const string& code, void* p1) {
	int err = 0;
	char s1[32];
	sprintf(s1, "%lu", (unsigned long)p1);
	if(cb_) {
		const char* ret = cb_(jsq_, main_qu_, &err, NULL, code.c_str(), false, NULL, 1, s1);
		l4_err_out_(jsq_, ret, err, 1);
		return;
	}
	if(rust_cb_) {
		const char* argv[] = {s1};
		rust_cb_free_(rust_cb_(&err, '0', code.c_str(), 1, argv));
		return;
	}
	printf("\t%s\n%s\n", code.c_str(), s1);
}

static string code_window_opened_;
static void window_opened__(WnckScreen *screen, WnckWindow *window, gpointer user_data) {
	z__(code_window_opened_, window);
}
dlle___ void on_window_opened__(const char*code, WnckScreen *screen) {
	code_window_opened_ = code;
	g_signal_connect (screen, "window-opened", G_CALLBACK (window_opened__), NULL);
}

static string code_window_stacking_changed_;
static void window_stacking_changed__(WnckScreen *screen, gpointer user_data) {
	z__(code_window_stacking_changed_, screen);
}
dlle___ void on_window_stacking_changed__(const char*code, WnckScreen *screen) {
	code_window_stacking_changed_ = code;
	g_signal_connect (screen, "window-stacking-changed", G_CALLBACK (window_stacking_changed__), NULL);
}

static string code_active_workspace_changed_;
static void active_workspace_changed__(WnckScreen *screen, WnckWorkspace *previously_active_space, gpointer user_data) {
	z__(code_active_workspace_changed_, previously_active_space);
}
dlle___ void on_active_workspace_changed__(const char*code, WnckScreen *screen) {
	code_active_workspace_changed_ = code;
	g_signal_connect (screen, "active-workspace-changed", G_CALLBACK (active_workspace_changed__), NULL);
}

class b___ {
public:
	bool name_changed_, workspace_changed_;
	void r__() {
		name_changed_ = workspace_changed_ = false;
	}
	b___() {r__();}
};
static std::map <WnckWindow *, b___> map_;

static string code_window_closed_;
static void window_closed__(WnckScreen *screen, WnckWindow *window, gpointer user_data) {
	z__(code_window_closed_, window);
	map_[window].r__();
}
dlle___ void on_window_closed__(const char*code, WnckScreen *screen) {
	code_window_closed_ = code;
	g_signal_connect (screen, "window-closed", G_CALLBACK (window_closed__), NULL);
}

static string code_name_changed_;
static void name_changed__(WnckWindow *window, gpointer user_data) {
	z__(code_name_changed_, window);
}
dlle___ void on_name_changed__(const char*code, WnckWindow *window) {
	if(map_[window].name_changed_) {
		return;
	}
	map_[window].name_changed_ = true;

	code_name_changed_ = code;
	g_signal_connect (window, "name-changed", G_CALLBACK (name_changed__), NULL);
}

static string code_workspace_changed_;
static void workspace_changed__(WnckWindow *window, gpointer user_data) {
	z__(code_workspace_changed_, window);
}
dlle___ void on_workspace_changed__(const char*code, WnckWindow *window) {
	if(map_[window].workspace_changed_) {
		return;
	}
	map_[window].workspace_changed_ = true;

	code_workspace_changed_ = code;
	g_signal_connect (window, "workspace-changed", G_CALLBACK (workspace_changed__), NULL);
}
