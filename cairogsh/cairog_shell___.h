/*
 * cairog_shell___.h
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#ifndef CAIROG_SHELL____H_
#define CAIROG_SHELL____H_

#include "sh-base/shell___.h"
#include "cairog_view___.h"

class cairog_shell___ : public shell___ {
public:
	view___* new_view__(GtkWidget* scrolled2, window___* window);
	bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* CAIROG_SHELL____H_ */
