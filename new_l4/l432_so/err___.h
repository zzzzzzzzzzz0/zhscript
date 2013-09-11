/*
 * err___.h
 *
 *  Created on: 2009-12-20
 *      Author: zzzzzzzzzzz
 */

#ifndef ERR____H_
#define ERR____H_
#include <string>
using namespace std;

class err___ {
private:
	string buf_;
	void reset__(){
		add1_=false;
	}
public:
	bool add1_;
	err___(){
		reset__();
	}
	err___& operator<<(const string& s){
		buf_+=s;
		return *this;
	}
	err___& operator<<(long l);
	operator string(){return buf_;}
	operator const char*(){return buf_.c_str();}
	/*void move__(const err___& err){
		err<<buf_;
		buf_.clear();
	}*/
	void del__(){
		buf_.clear();
		reset__();
	}
	bool has__(){return !buf_.empty();}
};
#endif /* ERR____H_ */
