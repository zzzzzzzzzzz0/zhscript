/*
 * arg___.h
 *
 *  Created on: 2013-4-12
 *      Author: zzzzzzzzzzz
 */

#ifndef ARG____H_
#define ARG____H_

#include <string>
#include <deque>
using namespace std;

class arg___ {
private:
	const char** argv_;
	deque<string> args_;

	void del__();
public:
	arg___();
	virtual ~arg___();
	int c__();
	const char** v__();
	void add__(const char* s);
	void add__(const string& s);
	void ins__(const char* s);
	void ins__(const string& s);
	void clear__();
};

#endif /* ARG____H_ */
