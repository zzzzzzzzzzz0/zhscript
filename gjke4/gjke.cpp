/*
 * gjke.cpp
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#include"gjke.h"

callback2_2___ callback_;
callback3_2___ callback3_;
var_new___ var_new_;
var_get___ var_get_;
var_del___ var_del_;
var_for_name___ var_for_name_;
l4_err_out___ l4_err_out_;
void* jsq_;
void* main_qu_;
string kw_length_,kw_dian_;
string kw_eval_, kw_begin_, kw_end_, kw_dunhao_, kw_yybegin_, kw_yyend_;

dlle___ void dlln___(init__)(void* jsq,
		callback2_2___ cb,
		callback3_2___ cb3,
		var_new___ var_new,var_get___ var_get,var_del___ var_del,
		var_for_name___ var_for_name,
		l4_err_out___ l4_err_out,
		void* main_qu,
		char*len,char*dian,
		char*kw_eval, char*kw_begin, char*kw_end, char*kw_dunhao, char*kw_yybegin, char*kw_yyend)
{
	jsq_=jsq;
	callback_=cb;
	callback3_=cb3;
	var_new_=var_new;
	var_get_=var_get;
	var_del_=var_del;
	var_for_name_ = var_for_name;
	l4_err_out_=l4_err_out;
	main_qu_ = main_qu;
	kw_length_=len;
	kw_dian_=dian;
	kw_eval_ = kw_eval;
	kw_begin_ = kw_begin;
	kw_end_ = kw_end;
	kw_dunhao_ = kw_dunhao;
	kw_yybegin_ = kw_yybegin;
	kw_yyend_ = kw_yyend;
}

int for_err__(int*err) {
	if(*err){
		if(*err==jieshiqi_err_go_+keyword_continue_){
			*err=0;
			return 0;
		}
		if(*err==jieshiqi_err_go_+keyword_break_){
			*err=0;
			return 1;
		}
		return 1;
	}
	return 0;
}

#include<stdio.h>

char* i2s__(int i,char buf[]){
	sprintf(buf,"%d",i);
	return buf;
}
char* l2s__(long int i,char buf[]){
	sprintf(buf,"%ld",i);
	return buf;
}
unsigned long x2lu__(char*s, unsigned long l){
	sscanf(s,"%lx",&l);
	return l;
}
int s2i__(const char* s, int i){
	sscanf(s,"%d",&i);
	return i;
}
long s2l__(const char* s, long i){
	sscanf(s,"%ld",&i);
	return i;
}

#include"call_util.cpp"


/*#include <sys/utsname.h>
#include "../../zhscript2-lib/i2.h"
#include "for_arg_.h"

dlle___ void uname__(std::vector<std::string>* ret, int argc, ...) {
	struct utsname testbuff;
	if(uname(&testbuff) < 0)
		return;
	_for_args( argc ) {
		string s1 = s;
		if(s1 == "-s") {
			ret->push_back(testbuff.sysname);
			continue;
		}
		if(s1 == "-n") {
			ret->push_back(testbuff.nodename);
			continue;
		}
		if(s1 == "-r") {
			ret->push_back(testbuff.release);
			continue;
		}
		if(s1 == "-v") {
			ret->push_back(testbuff.version);
			continue;
		}
		if(s1 == "-m") {
			ret->push_back(testbuff.machine);
			continue;
		}
		if(s1 == "-d") {
			ret->push_back(testbuff.domainname);
			continue;
		}
		ret->push_back(s);
	} _next_args
}*/

