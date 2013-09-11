/*
 * err___.h
 *
 *  Created on: 2009-12-20
 *      Author: zzzzzzzzzzz
 */

#ifndef ERR____H_
#define ERR____H_
#include <string>
#include <iostream>
using namespace std;

class err___ {
private:
	string buf_;
public:
	err___(){}
	err___& operator<<(const string& s){
		buf_+=s;
		return *this;
	}
	operator string(){return buf_;}
	operator const char*(){return buf_.c_str();}
};
#endif /* ERR____H_ */
