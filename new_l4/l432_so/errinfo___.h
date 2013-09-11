/*
 * errinfo___.h
 *
 *  Created on: 2010-3-29
 *      Author: zzzzzzzzzzz
 */

#ifndef ERRINFO____H_
#define ERRINFO____H_
#include <string>
#include <iostream>
using namespace std;

#include"err___.h"
#include"errinfo.h"

class errinfo___ {
private:
	string errinfos_[errinfos_length_];
	bool has_;
	string buf_;
public:
	errinfo___();
	virtual ~errinfo___();
	int get_file__(const string& path);
	const char* operator[](int i);

	err___ err_;
};

#endif /* ERRINFO____H_ */
