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

int s2i__(const string& s){
	int i;
	istringstream ss(s);
	ss>>i;
	return i;
}

long s2l__(const string& s){
	long i;
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
	istringstream ss(s);
	ss>>hex>>i;
	return i;
}

int kw_num__(const string& kw,int min,int max,const string& buf2,const string* kw_len){
	if(buf2.compare(0,kw.length(),kw)==0){
		string s=buf2.substr(kw.length());
		if(s.length()==0)
			return kwnum_no_;
		if(kw_len&&s==*kw_len)
			return -1;

		bool b=true;
		for(size_t i=0;i<s.length();i++){
			char c=s[i];
			if(!((c>='0'&&c<='9')||(c=='-'&&i==0&&s.length()>1))){
				b=false;
				break;
			}
		}
		if(b){
			int i=s2i__(s);
			if((min==kwnum_no_||i>=min)&&(max==kwnum_no_||i<=max)){
				return i;
			}
		}
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
