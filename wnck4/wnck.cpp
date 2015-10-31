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
using namespace std;

static int s2i__(const char* s1,int i){
	int i1=i;
	char c=s1[0];
	if(c=='+')
		s1++;
	sscanf(s1,"%d",&i1);
	if(c=='+')
		i1+=i;
	return i1;
}

static void* jsq_;
static callback2___ cb_;
static void* main_qu_;
static l4_err_out___ l4_err_out_;

dlle___ void init__(callback2___ cb,void* jsq, void* main_qu, l4_err_out___ l4_err_out){
	jsq_=jsq;
	cb_=cb;
	main_qu_ = main_qu;
	l4_err_out_ = l4_err_out;
}

dlle___ void for__(int*err,void* shangji,const char*code,WnckScreen *screen){
	GList *window_l;
	char p1[32], p2[] = {0, 0}, p3[32];
	WnckWorkspace *aws = wnck_screen_get_active_workspace(screen);
	for (window_l = wnck_screen_get_windows (screen); window_l != NULL; window_l = window_l->next){
		WnckWindow *window = WNCK_WINDOW (window_l->data);
		sprintf(p1,"%lx",(long)window);
		p2[0] = wnck_window_is_skip_tasklist(window) ? '0' : '1';

		WnckWorkspace *ws = wnck_window_get_workspace(window);
		int i = wnck_workspace_get_number(ws) + 1;
		//wnck_window_is_on_workspace(window, aws)
		if(ws == aws)
			i = -i;
		sprintf(p3, "%d", i);

		cb_(jsq_,shangji,err,code,false, 3, p1, p2, p3);
		if(*err){
			if(*err==jieshiqi_err_go_+keyword_continue_){
				*err=0;
				continue;
			}
			if(*err==jieshiqi_err_go_+keyword_break_){
				*err=0;
				break;
			}
			break;
		}
	}
}

dlle___ void window_set_geometry__(char* buf, WnckWindow* ww, char* x, char* y, char* w, char* h) {
	int x1, y1, w1, h1;
	wnck_window_get_geometry(ww, &x1, &y1, &w1, &h1);
	x1 = s2i__(x, x1);
	y1 = s2i__(y, y1);
	w1 = s2i__(w, w1);
	h1 = s2i__(h, h1);
	sprintf(buf, "%d,%d,%d,%d", x1, y1, w1, h1);
	wnck_window_set_geometry(ww, WNCK_WINDOW_GRAVITY_CURRENT,
			(WnckWindowMoveResizeMask)(WNCK_WINDOW_CHANGE_X | WNCK_WINDOW_CHANGE_Y | WNCK_WINDOW_CHANGE_WIDTH | WNCK_WINDOW_CHANGE_HEIGHT),
			x1, y1, w1, h1);
}

static void z__(const string& code) {
	int err;
	const char* ret = cb_(jsq_, main_qu_, &err, code.c_str(), false, 0);
	l4_err_out_(jsq_, ret, err, 1);
}

static string code_window_opened_;
static void window_opened__(WnckScreen *screen, WnckWindow *window, gpointer user_data) {
	z__(code_window_opened_);
}
dlle___ void on_window_opened__(const char*code, WnckScreen *screen) {
	code_window_opened_ = code;
	g_signal_connect (screen, "window-opened", G_CALLBACK (window_opened__), NULL);
}

static string code_window_closed_;
static void window_closed__(WnckScreen *screen, WnckWindow *window, gpointer user_data) {
	z__(code_window_closed_);
}
dlle___ void on_window_closed__(const char*code, WnckScreen *screen) {
	code_window_closed_ = code;
	g_signal_connect (screen, "window-closed", G_CALLBACK (window_closed__), NULL);
}

static string code_active_workspace_changed_;
static void active_workspace_changed__(WnckScreen *screen, WnckWorkspace *previously_active_space, gpointer user_data) {
	z__(code_active_workspace_changed_);
}
dlle___ void on_active_workspace_changed__(const char*code, WnckScreen *screen) {
	code_active_workspace_changed_ = code;
	g_signal_connect (screen, "active-workspace-changed", G_CALLBACK (active_workspace_changed__), NULL);
}
