/*
 * webkit_shell___.h
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#ifndef WEBKIT_SHELL____H_
#define WEBKIT_SHELL____H_

#include "sh-base/shell___.h"
#include "webkit_view___.h"

class webkit_shell___: public shell___ {
public:
	webkit_shell___();
	view___* new_view__(GtkWidget* scrolled2, window___* window);
	bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* WEBKIT_SHELL____H_ */
