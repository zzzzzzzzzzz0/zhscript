/*
 * webkit_shell___.h
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#ifndef WEBKIT_SHELL____H_
#define WEBKIT_SHELL____H_

#include "sh-base/shell___.h"
#include "webkit_window___.h"

class webkit_shell___: public shell___ {
private:
	window___* new_window__(const char*name, bool is_main = false);
	webkit_window___* get_window__(const string& name,int& page_num,const string& help,
			bool chk_can=true, string* page_num2 = NULL);
public:
	webkit_shell___();
	bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* WEBKIT_SHELL____H_ */
