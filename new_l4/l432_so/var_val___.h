/*
 * var_val___.h
 *
 *  Created on: 2010-4-21
 *      Author: zzzzzzzzzzz
 */

#ifndef VAR_VAL____H_
#define VAR_VAL____H_
#include <string>
#include <iostream>
#include <deque>
using namespace std;


class var_val___{
private:
	static deque<string> rems_;
	int i_;
	string val_;
public:
	var_val___(){i_=-1;}
	var_val___(const string& rem,const string& val);
	bool rfind__(const string& s,size_t n=string::npos);

	const string& val__(){return val_;}
	void val__(const string& val){val_=val;}
	const string& name__(){
		/*if(i_<0)
			return rems_[0];*/
		return rems_[i_];
	}

	bool is__(const string& rem){return (i_>=0&&rems_[i_]==rem);}
};

#endif /* VAR_VAL____H_ */
