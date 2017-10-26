/*
 * vte_shell___.h
 *
 *  Created on: 2013年12月11日
 *      Author: zzzzzzzzzzz
 */

#ifndef VTE_SHELL____H_
#define VTE_SHELL____H_
#include "sh-base/shell___.h"
#include "vte_view___.h"

class vte_shell___: public shell___ {
private:
	vte_view___* view__(const string& name, int& page_num, const string& help);
public:
	vte_shell___();
	view___* new_view__(GtkWidget* scrolled2, window___* window);
	bool api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret);
};
#endif /* VTE_SHELL____H_ */
