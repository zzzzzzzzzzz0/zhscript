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

extern const char* call4__(const char* code,const char* src2,int argc,const char**argv2,int from);
extern const char* call4__(GtkWidget* sw,window___* w,s1___* s1,int argc,...);
extern void err_buzu__(const char* s=NULL);
extern void err_wufa__(const string& s3,const char* s=NULL);
extern void err_buzhichi__(const string& s3,const char* s=NULL);

extern string null_;

extern const string& s__(const deque<string>& p, size_t i);
extern const string& s__(const deque<string>* p, size_t i);

#endif /* EXTERN_H_ */
