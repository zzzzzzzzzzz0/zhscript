/*
 * call_ex___.h
 *
 *  Created on: 2012-2-3
 *      Author: zzzzzzzzzzz
 */

#ifndef CALL_EX____H_
#define CALL_EX____H_
#include<string>
using namespace std;

class call_ex___ {
private:
	int kw_;
	string s_;
public:
	call_ex___();
	call_ex___(int kw, const string& s);
	virtual ~call_ex___();
	const string& s__();
	void s__(const string& s);
	int kw__();
	void kw__(int i);
};

#endif /* CALL_EX____H_ */
