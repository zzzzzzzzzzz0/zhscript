/*
 * cairog_shell___.h
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#ifndef CAIROG_SHELL____H_
#define CAIROG_SHELL____H_

#include "sh-base/shell___.h"
#include "cairog_window___.h"

class cairog_shell___ : public shell___ {
private:
	window___* new_window__(const char*name, bool is_main = false);
	cairog_window___* get_window__(const string& name, int& page_num, const string& help, bool chk_can = true);
public:
	bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* CAIROG_SHELL____H_ */
