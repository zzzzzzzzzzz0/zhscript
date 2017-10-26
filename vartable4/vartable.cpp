/*
 * vartable.cpp
 *
 *  Created on: 2010-7-19
 *      Author: zzzzzzzzzzz
 */

#include"def1.h"
#include<string>
#include<iostream>
using namespace std;
#include"for_arg_.h"
#include<stdio.h>
#include "l4/keyword.h"

var_for_1___ var_for_;
callback3_2___ cb_;
l4_err_out___ l4_err_out_;
void* jsq_;

dlle___ void init__(void* jsq, var_for_1___ var_for, callback3_2___ cb, l4_err_out___ l4_err_out) {
	jsq_=jsq;
	var_for_ = var_for;
	cb_=cb;
	l4_err_out_ = l4_err_out;
}

int callback__(int argc,...){
	_for_args(argc)
		switch(i){
		case 0:
		{
			int i1=0;
			sscanf(s,"%d",&i1);
			for(;--i1>=0;)
				cout<<"\t";
		}
			break;
		default:
			cout<<"{"<<s<<"}";
			break;
		}
	_next_args
	cout<<endl;
	return 0;
}
dlle___ void dlln___(vartable__)(void*qu,int max){
	cout<<endl;
	var_for_(qu,callback__,max);
}

void *shangji_;
string code_;
int callback2__(int argc,...){
	const char** argv2 = new const char*[argc];
	_for_args(argc)
		argv2[i] = s;
	_next_args
	int err;
	const char*ret = cb_(jsq_, shangji_, &err, NULL, code_.c_str(), false, NULL, argc, argv2, 0);
	delete argv2;
	switch(err) {
	case jieshiqi_err_go_+keyword_continue_:
	case jieshiqi_err_go_+keyword_break_:
		return err;
	}
	if(err)
		l4_err_out_(jsq_, ret, err, 1);
	return err;
}
dlle___ void dlln___(vartable2__)(void*qu, void*shangji, const char* code,int max){
	if(!code) {
		dlln___(vartable__)(qu, max);
		return;
	}
	shangji_ = shangji;
	code_ = code;
	var_for_(qu,callback2__,max);
}
