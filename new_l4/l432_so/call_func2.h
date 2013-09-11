/*
 * call_func2.h
 *
 *  Created on: 2010-8-22
 *      Author: zzzzzzzzzzz
 */

#ifndef CALL_func2_H_
#define CALL_func2_H_
#include<string>
#include<deque>
using namespace std;
#include "err___.h"
#include "jieshiqi___.h"
#include "call_ex___.h"

int call_func__(deque<string>* p,string& buf0,err___* err0,const string& null,
		jieshiqi___* jsq,qu___* qu,call_ex___* ce);

unsigned long call_type__(const string& s,err___* err,size_t* i1=NULL,int step=1,
		int* ret2=NULL,string* ret3=NULL,unsigned long* ret4=NULL);

#endif /* CALL_func2_H_ */
