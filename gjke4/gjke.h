/*
 * gjke.h
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#ifndef GJKE_H_
#define GJKE_H_
#include<string>
#include<iostream>
using namespace std;

#include "def1.h"
#include"call_util.h"
#include "l4/keyword.h"

extern callback2_2___ callback_;
extern callback3_2___ callback3_;
extern var_new___ var_new_;
extern var_get___ var_get_;
extern var_del___ var_del_;
extern var_for_name___ var_for_name_;
extern l4_err_out___ l4_err_out_;
extern void* jsq_;
extern void* main_qu_;
extern string kw_length_,kw_dian_;

extern char* i2s__(int i,char buf[]);
extern char* l2s__(long int i,char buf[]);
extern unsigned long x2lu__(char*s);
extern int s2i__(const char* s);
extern bool startswith__(const char*src,const char*tag);
extern int for_err__(int*err);
#endif /* GJKE_H_ */
