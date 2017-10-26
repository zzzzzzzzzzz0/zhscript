/*
 * util2.cpp
 *
 *  Created on: 2016年2月29日
 *      Author: zzzzzzzzzzz
 */

#include <iostream>
#include"for_arg_.h"
#include "extern.h"
#include "def1.h"
#include "l4/keyword.h"

const string& s__(const deque<string>* p, size_t i) {
	if(i >= p->size()) {
		if(p->size() > 0)
			err_buzu__((*p)[0].c_str());
		throw 's';
	}
	return (*p)[i];
}
const string& s__(const deque<string>& p, size_t i) {
	return s__(&p, i);
}

const char* call4__(int* err,const char* code,const char* src2,int argc,const char**argv2,int from){
	return call4__(err, NULL, code, src2, NULL, argc, argv2, from);
}
const char* call4__(const char* code,const char* src2,int argc,const char**argv2,int from){
	int err;
	return call4__(&err, code, src2, argc, argv2, from);
}
const char* call4__(GtkWidget* sw,window___* w,s1___* s1,int argc,...){
	const char*argv2[16];
	_for_args( argc )
		argv2[i]=s;
	_next_args
	const char* code=NULL;
	if(w && s1) {
		map<int, string>::iterator it = w->codes_.find(s1->i__());
		if(it != w->codes_.end())
			code=(*it).second.c_str();
	}
	if(!code || !code[0]){
		for(;;){
			if(w) {
				code = w->code_.c_str();
				if(code[0])
					break;
			}
			break;
		}
	}
	string name2;
	if(w) {
		w->name2__(name2, sw);
		argv2[argc++]=name2.c_str();
	}
	const char* src2 = NULL;
	if(s1)
		src2 = s1->src2__();
	return call4__(code,src2,argc,argv2);
}

void err_buzu__(const char* s){
	err__(s,"参数不足");
}
bool err_buzu2__(const deque<string>* p, size_t need, size_t i){
	if(p->size()<need){
		string s;
		for(; i < p->size(); i++)
			s += (*p)[i];
		err_buzu__(s.c_str());
		return true;
	}
	return false;
}
void err_wufa__(const string& s3,const char* s){
	err__(s,"无法",s3.c_str());
}
void err_buzhichi__(const string& s3,const char* s){
	err__(s,"不支持",s3.c_str());
}

const char* call4__(void* ce, const string& code, void* shangji, int argc, const char** argv, int* err, bool for4) {
	const char* ret = call4__(err, ce, code.c_str(), NULL, shangji, argc, argv, 0);
	if(err && *err) {
		if(for4 && *err == jieshiqi_go_ + keyword_continue_)
			*err = 0;
		else
			err__(*err, ret);
	}
	return ret;
}

void err__(deque<string>* p, size_t i2, const char* s, bool hou) {
	string err;
	if(!hou)
		err += s;
	if(i2 >= p->size())
		i2 = p->size() - 1;
	for(size_t i = 0; i <= i2; i++)
		err += (*p)[i];
	if(hou)
		err += s;
	err__(err.c_str());
}
bool buzu__(size_t i2, deque<string>* p) {
	if(i2 >= p->size()) {
		err__(p, i2, "参数不足");
		return true;
	}
	return false;
}
void buzhichi__(size_t i2, deque<string>* p) {
	err__(p, i2, "不支持");
}
void wufa__(size_t i2, deque<string>* p) {
	err__(p, i2, "无法", false);
}
