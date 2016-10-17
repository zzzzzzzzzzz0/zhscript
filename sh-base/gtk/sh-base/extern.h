/*
 * extern.h
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#ifndef EXTERN_H_
#define EXTERN_H_
#include "window___.h"
#include "s1___.h"
#include <deque>

extern const char* call4__(int* err, void*ce, const char* code, const char* src2,void* shangji, int argc, const char**argv2, int from = 0);
extern const char* call4__(int* err,const char* code,const char* src2,int argc,const char**argv2,int from = 0);
extern const char* call4__(const char* code,const char* src2,int argc,const char**argv2,int from = 0);
extern const char* call4__(GtkWidget* sw,window___* w,s1___* s1,int argc,...);

extern void err__(int err, const char* ret);
extern void err__(const char* s,const char* s2=NULL,const char* s3=NULL);
extern void err_buzu__(const char* s=NULL);
extern bool err_buzu2__(const deque<string>* p, size_t need, size_t i = 1);
extern void err_wufa__(const string& s3,const char* s=NULL);
extern void err_buzhichi__(const string& s3,const char* s=NULL);

extern const char* call4__(void* ce, const string& code, void* shangji, int argc, const char** argv, int* err = NULL, bool for4 = false);
extern void err__(deque<string>* p, size_t i2, const char* s, bool hou = true);
extern bool buzu__(size_t i2, deque<string>* p);
extern void buzhichi__(size_t i2, deque<string>* p);
extern void wufa__(size_t i2, deque<string>* p);

extern string null_;

extern const string& s__(const deque<string>& p, size_t i);
extern const string& s__(const deque<string>* p, size_t i);

#endif /* EXTERN_H_ */
