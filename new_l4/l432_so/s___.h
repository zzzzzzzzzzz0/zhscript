/*
 * s___.h
 *
 *  Created on: 2016年7月10日
 *      Author: zzzzzzzzzzz
 */

#ifndef S____H_
#define S____H_
#include <string>
using namespace std;

class s___ {
private:
	string s_;
	int u_;
public:
	s___(const string& s, int u = 0) {
		s_ = s;
		u_ = u;
	}
	s___() {u_ = -1;}
	int u__() {return u_;}
	operator const string&() {return s_;}
	const char* c_str() {return s_.c_str();}
	size_t length() {return s_.length();}
	char operator [](int i) {return s_[i];}
};
#endif /* S____H_ */
