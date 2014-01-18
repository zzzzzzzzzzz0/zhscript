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

class shell___ {
private:
	window___* new_window__(const char* name, window_flag___* flag);
	window___* new_window__(const char* name, bool is_main);
protected:
	window___* get_window__(const string& name, int& page_num, const string& help,
			bool chk_can = true, string* page_num2 = NULL, bool show_err = true);
	view___* get_view__(const string& name, int& page_num, const string& help,
			bool chk_can = true, string* page_num2 = NULL, bool show_err = true);
public:
	shell___();
	virtual ~shell___() {};
	int with__(int argc, char *argv[], char* env[]);
	virtual view___* new_view__(GtkWidget* scrolled2, window___* window);
	virtual bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* SHELL____H_ */
