/*
 * util.cpp
 *
 *  Created on: 2010-2-26
 *      Author: zzzzzzzzzzz
 */

#include "util.h"
#include <sstream>
#include <iostream>

string l2s__(long l){
	string s;
	stringstream ss;
	ss<<l;
	ss>>s;
	return s;
}

string lu2s__(unsigned long l){
	string s;
	stringstream ss;
	ss<<l;
	ss>>s;
	return s;
}

int s2i__(const string& s, int i){
	istringstream ss(s);
	ss>>i;
	return i;
}

long s2l__(const string& s, long i){
	istringstream ss(s);
	ss>>i;
	return i;
}

unsigned long s2lu__(const string& s){
	unsigned long i;
	istringstream ss(s);
	ss>>i;
	return i;
}

double s2d__(const string& s){
	double i;
	istringstream ss(s);
	ss>>i;
	return i;
}

string l2x__(long l){
	string s;
	stringstream ss;
	ss<<hex<<l;
	ss>>s;
	return s;
}

long x2l__(const string& s){
	unsigned long i;
#ifdef ver_sstream_too_bad_
	sscanf(s.c_str(), "%lx", &i);
#else
	istringstream ss(s);
	ss>>hex>>i;
#endif
	return i;
}

bool is_num__(const string& s) {
	for(size_t i=0;i<s.length();i++){
		char c=s[i];
		if(!((c>='0'&&c<='9')||(c=='-'&&i==0&&s.length()>1))){
			return false;
		}
	}
	return true;
}

int kw_num__(const string& kw,int min,int max,const string& buf,const string* kw_len, int* num, int* num2){
	if(buf.compare(0,kw.length(),kw)==0){
		if(num2) {
			*num2 = max;
		}

		string s=buf.substr(kw.length());
		if(s.length()==0) {
			*num = kwnum_no_;
			return kwnum_no_;
		}
		if(kw_len&&s==*kw_len)
			return kwnum_is_len_;

		string s2;
		size_t i2 = s.find('/');
		if(i2 != string::npos) {
			s2 = s.substr(i2 + 1);
			s = s.substr(0, i2);
		}

		if(!is_num__(s))
			return kwnum_false_;
		int i=s2i__(s, kwnum_err_);
		if(i == kwnum_err_)
			return kwnum_false_;
		if(i < 0)
			i += max + 1;
		*num = i;

		if(!s2.empty() && num2) {
			if(!is_num__(s2))
				return kwnum_false_;
			i=s2i__(s2, kwnum_err_);
			if(i == kwnum_err_)
				return kwnum_false_;
			if(i < 0)
				i += max + 1;
			*num2 = i;
		}

		int ret = kwnum_false_;
		if((min==kwnum_no_||*num>=min)&&(max==kwnum_no_||*num<=max))
			ret = kwnum_has_;
		else
			return kwnum_out_;
		if(num2) {
			if((min==kwnum_no_||*num2>=min)&&(max==kwnum_no_||*num2<=max))
				ret = kwnum_has2_;
			else
				return kwnum_out_;
		}
		return ret;
	}
	return kwnum_false_;
}

string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value)
{
	string::size_type i=0;
	while(true)   {
		string::size_type   pos(0);
		if(   (pos=str.find(old_value,i))!=string::npos   ){
			str.replace(pos,old_value.length(),new_value);
			i=new_value.length()+pos;
		}else   break;
	}
	return   str;
}

#ifdef debug_liucheng_
void out_f_t__(const string& src,size_t from,size_t to,char clr){
	cout<<endl<<"\033[0;3"<<clr<<"m----"<<from<<","<<to<<"\t"
		<<(to>from?src.substr(from,to-from):"")<<"\033[0m"<<endl;
}
void out_kw__(const string& kw,char clr){
	cout<<"\033[0;3"<<out_clr_k_<<";4"<<clr<<"m"<<kw<<"\033[0m";
}
void out_if__(const char*s,char clr){
	cout<<"\033[0;3"<<out_clr_if_<<";4"<<clr<<"m"<<s<<"\033[0m";
}
#endif

int cb_buf_i_=-1;
#define cb_buf_max_ 128
string cb_buf_[cb_buf_max_];
string& cb_buf__(){
	if(++cb_buf_i_>=cb_buf_max_)
		cb_buf_i_=0;
	cb_buf_[cb_buf_i_].clear();
	return cb_buf_[cb_buf_i_];
}
