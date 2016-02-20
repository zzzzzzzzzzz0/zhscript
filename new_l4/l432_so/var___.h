/*
 * var___.h
 *
 *  Created on: 2010-3-19
 *      Author: zzzzzzzzzzz
 */

#ifndef VAR____H_
#define VAR____H_
#include <string>
#include <list>
#include <iostream>
#include <map>
using namespace std;
#include "var_val___.h"
#include "vartype.h"

class var___ {
private:
	map<int,var_val___>::iterator huashen__(const string& s,char use='s',size_t n=string::npos);
	void huashen__(const string& name,const string& val);
	void del__(map<int,var_val___>::iterator mi);
public:
	var___();
	virtual ~var___();
	map<int,var_val___> huashen_;
	bool readonly_;
	int type_;
	bool is_noparam_;
	bool is_chuantou_;

	void val__(const string& val,list<string>* rems=NULL);
	const string& val__(list<string>* rems=NULL);

	bool del__(list<string>* rems);
	bool del__();
	bool qianche__(const string& rem);
	string qianche_rem_;

	bool has_huashen__(list<string>* rems);
};

#endif /* VAR____H_ */
