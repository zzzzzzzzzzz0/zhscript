/*
 * shell___.h
 *
 *  Created on: 2012-8-8
 *      Author: zzzzzzzzzzz
 */

#ifndef SHELL____H_
#define SHELL____H_
#include "l4/l4___.hh"
#include "call_util.h"
#include <deque>
#include "window___.h"
#include "s1___.h"

class shell___ {
private:
	window___* new_window__(const char* name, window_flag___* flag, container___* c);
	window___* new_window__(const char* name, bool is_main);
	bool api_page__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
	bool api_w__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
	bool api_w2__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
	bool api_w3__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
protected:
	int addr_fmt_;
	window___* get_window__(const string& name, int& page_num, const string& help,
			bool chk_can = true, string* page_num2 = NULL, bool show_err = true);
	view___* get_view__(const string& name, int& page_num, const string& help,
			bool chk_can = true, string* page_num2 = NULL, bool show_err = true);
public:
	shell___();
	virtual ~shell___() {};
	int with__(int argc, char *argv[], char* env[]);
	virtual view___* new_view__(GtkWidget* scrolled2, window___* window);
	static view___* new_page__(const char* name, bool to, window___* window);
	virtual bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
	bool api_new_view__(const string& p0, const string& p1, deque<string>* p, s1___* s1, const char* arg_alias = NULL, view___**v2 = NULL);
};

extern void get_xid__(GtkWidget* w, char* buf);
extern bool bool__(deque<string>* p, size_t i, bool b /*= false*/);
#endif /* SHELL____H_ */
