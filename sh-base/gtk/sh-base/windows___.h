/*
 * windows___.h
 *
 *  Created on: 2013-2-9
 *      Author: zzzzzzzzzzz
 */

#ifndef WINDOWS____H_
#define WINDOWS____H_
#include<deque>
#include"window___.h"

class windows___ {
private:
	deque<window___*> windows_;
public:
	void push__(window___* w);
	void erase__(window___* w);
	window___* get__(const char* name);
	window___* main__();
};

#endif /* WINDOWS____H_ */
