/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * rptestj
 * Copyright (C) zzzzzzzzzzz 2010 <zzzzzzzzzzzgg@gmail.com>
 *
 * rptestj is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rptestj is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SHELL_H_
#define _SHELL_H_

#include <gtkmm.h>
#include <iostream>
#ifdef ENABLE_NLS
#  include <libintl.h>
#endif
#include<deque>
#include "l4/l4___.hh"

class shell___
{
public:
	shell___();
	~shell___();

	Gtk::Window* main_win_;
	Glib::RefPtr<Gtk::Builder> builder_;

	int with__(int argc, char *argv[], char**env);
	void api__(void*shangji,void*ce,std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret);
	const char* on__(const char*code,void* shangji,int argc,...);

	void err_show__(const char* str,const char*str2="",const char*str3="");
	void err_show_buzhichi__(std::deque<Glib::ustring>* p,int i=1);
	void err_show_buzu__(std::deque<Glib::ustring>* p);
	void err_show_wufa__(std::deque<Glib::ustring>* p,int i=-1,int i1=0);
	void err_show_fei__(std::deque<Glib::ustring>* p);

	l4___ l4_;
	const char* call4__(                   const char*code,void* shangji,const char*zhao,const char*dong,const char* src2,int argc,const char*argv[],int from);
	const char* call4_1__(int* err,void*ce,const char*code,void* shangji,const char*zhao,const char*dong,const char* src2,int argc,const char*argv[],int from);
	void call4_2__(int err);
	void l4_err_show__(int err);
	bool bool__(const string& s);

	void main_win_show__();
	void main_win_hide__();
	bool main_win_is_visible__();

	Glib::ustring src_;
	const char* prgname_;
	const char* ui_file_;
	void* l4_main_qu_;
protected:

private:
	void init__();

	Gtk::Main* main_;
	Glib::ustring realprgname_;
	string default_ui_file_;
	int exit_;
	bool err_show_to_console_;
	Gtk::TextView* err_view_;

	int l4__(char*arg1,int argc, char *argv[],int from,char**env);

	std::deque<void*>plugins_;
	void pluginit__();
	bool plugin_proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void plugin_on__(int event);
	void plugin_uninit__();

	bool main_win_state_evt__(GdkEventWindowState*st);
	bool main_win_delete_evt__(GdkEventAny* event);
	bool firstevted_;
	void main_win_new_evt__();
	int old_width_,old_height_;
	void main_win_resize_evt__(Gtk::Allocation& allo);
	bool main_win_config_evt__(GdkEventConfigure* event);

	bool main_quit_;
	void main_quit__();

#ifdef ver_thread_
	const char*code_;
	int argc_;
	const char*argv_[8];
	Glib::Mutex mutex_;
	void call4_0__();
#endif
	void l4_err_show__(int err,const char*ret);
};
#endif // _SHELL_H_
