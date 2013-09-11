/*
 * zhi___.h
 *
 *  Created on: 2010-3-13
 *      Author: zzzzzzzzzzz
 */

#ifndef ZHI____H_
#define ZHI____H_
#include <string>
#include <iostream>
using namespace std;

class zhi___ {
public:
	zhi___();
	virtual ~zhi___();
	bool operator==(zhi___ &b){
		if(type_=='l'&&b.type_=='l')
			return l_==b.l_;
		if(type_=='d'&&b.type_=='d')
			return d_==b.d_;
		if(type_=='l'&&b.type_=='d')
			return l_==b.d_;
		if(type_=='d'&&b.type_=='l')
			return d_==b.l_;
		return (s_ == b.s_);
	}
	bool operator!=(zhi___ &b){
		if(type_=='l'&&b.type_=='l')
			return l_!=b.l_;
		if(type_=='d'&&b.type_=='d')
			return d_!=b.d_;
		if(type_=='l'&&b.type_=='d')
			return l_!=b.d_;
		if(type_=='d'&&b.type_=='l')
			return d_!=b.l_;
		return (s_ != b.s_);
	}
	bool operator<=(zhi___ &b){
		if(type_=='l'&&b.type_=='l')
			return l_<=b.l_;
		if(type_=='d'&&b.type_=='d')
			return d_<=b.d_;
		if(type_=='l'&&b.type_=='d')
			return l_<=b.d_;
		if(type_=='d'&&b.type_=='l')
			return d_<=b.l_;
		return (s_ <= b.s_);
	}
	bool operator<(zhi___ &b){
		if(type_=='l'&&b.type_=='l')
			return l_<b.l_;
		if(type_=='d'&&b.type_=='d')
			return d_<b.d_;
		if(type_=='l'&&b.type_=='d')
			return l_<b.d_;
		if(type_=='d'&&b.type_=='l')
			return d_<b.l_;
		return (s_ < b.s_);
	}
	bool operator>=(zhi___ &b){
		if(type_=='l'&&b.type_=='l')
			return l_>=b.l_;
		if(type_=='d'&&b.type_=='d')
			return d_>=b.d_;
		if(type_=='l'&&b.type_=='d')
			return l_>=b.d_;
		if(type_=='d'&&b.type_=='l')
			return d_>=b.l_;
		return (s_ >= b.s_);
	}
	bool operator>(zhi___ &b){
		if(type_=='l'&&b.type_=='l')
			return l_>b.l_;
		if(type_=='d'&&b.type_=='d')
			return d_>b.d_;
		if(type_=='l'&&b.type_=='d')
			return l_>b.d_;
		if(type_=='d'&&b.type_=='l')
			return d_>b.l_;
		return (s_ > b.s_);
	}
	zhi___& operator=(string &s){
		s_=s;
		set_type__();
		return *this;
	}
	operator const char*(){
		return s_.c_str();
	}
	bool bool__(const string& null,int fei_cnt,int fei_len);
private:
	char type_;
	string s_;
	long l_;
	double d_;
	bool b_;
	void set_type__();
};

#endif /* ZHI____H_ */
