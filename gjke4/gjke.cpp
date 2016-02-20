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

dlle___ void dlln___(init__)(void* jsq,
		callback2_2___ cb,
		callback3_2___ cb3,
		var_new___ var_new,var_get___ var_get,var_del___ var_del,
		var_for_name___ var_for_name,
		l4_err_out___ l4_err_out,
		void* main_qu,
		char*len,char*dian)
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
unsigned long x2lu__(char*s){
	unsigned long l=0;
	sscanf(s,"%lx",&l);
	return l;
}
int s2i__(const char* s){
	int i;
	sscanf(s,"%d",&i);
	return i;
}

#include"call_util.cpp"
