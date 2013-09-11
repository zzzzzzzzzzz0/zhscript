/*
 * qu___.h
 *
 *  Created on: 2009-12-15
 *      Author: zzzzzzzzzzz
 */

#ifndef QU____H_
#define QU____H_
#include <string>
#include <list>
using namespace std;
#include"args___.h"
#include"var___.h"
#include <map>

class qu___ {
public:
	qu___();
	virtual ~qu___();

	args___* args_;
	string src_;
	map<string,var___> vars_;
	qu___* shangji_;
};

#endif /* QU____H_ */
