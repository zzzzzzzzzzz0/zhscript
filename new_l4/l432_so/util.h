/*
 * util.h
 *
 *  Created on: 2010-2-26
 *      Author: zzzzzzzzzzz
 */

#ifndef UTIL_H_
#define UTIL_H_

#include<string>
using namespace std;

string l2s__(long l);
string lu2s__(unsigned long l);
int s2i__(const string& s);
long s2l__(const string& s);
unsigned long s2lu__(const string& s);
double s2d__(const string& s);
string l2x__(long l);
long x2l__(const string& s);
string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value);

//-1一般表示数量，留8个
#define kwnum_no_		-10
#define kwnum_false_	-11
int kw_num__(const string& kw,int min,int max,const string& buf2,const string* kw_len);

#ifdef debug_liucheng_
#define out_clr_1_ '2'
#define out_clr_x_ '1'
#define out_clr_if_ '3'
#define out_clr_t_ '0'
#define out_clr_k_ '7'
	void out_f_t__(const string& src,size_t from,size_t to,char clr=out_clr_1_);
	void out_kw__(const string& kw,char clr=out_clr_1_);
	void out_if__(const char*s,char clr='4');
#endif

string& cb_buf__();

#endif /* UTIL_H_ */
