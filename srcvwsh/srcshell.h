/*
 * srcshell.h
 *
 *  Created on: 2016年1月21日
 *      Author: zzzzzzzzzzz
 */

#ifndef SRCVWSH_SRCSHELL_H_
#define SRCVWSH_SRCSHELL_H_
#include "sh-base/shell___.h"
#include "srcview.h"

class src_shell___ : public shell___ {
public:
	src_shell___();
	view___* new_view__(GtkWidget* scrolled2, window___* window);
	bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
private:
	bool api2__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};

#endif /* SRCVWSH_SRCSHELL_H_ */
