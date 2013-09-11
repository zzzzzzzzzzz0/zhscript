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
protected:
	window___* new_window__(const char* name, window_flag___* flag);
	virtual window___* new_window__(const char*name, bool is_main = false);
	window___* get_window__(const string& name, int& page_num, const string& help,
			bool chk_can = true, string* page_num2 = NULL, bool show_err = true);
public:
	shell___();
	int with__(int argc, char *argv[], char* env[]);
	virtual bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* SHELL____H_ */
