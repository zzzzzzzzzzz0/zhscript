/*
 * jieshiqi_callback.h
 *
 *  Created on: 2011-1-7
 *      Author: zzzzzzzzzzz
 */

#ifndef JIESHIQI_CALLBACK_H_
#define JIESHIQI_CALLBACK_H_
#include "jieshiqi___.h"
#include "call_ex___.h"
#include <stdarg.h>

#define callback_max_	24

extern const char* callback1__(jieshiqi___* jsq,qu___* shangji,int* err,bool bylib,call_ex___* ce,
		const char* src,bool src_is_file,const char* src2,int argc,va_list& argv);
extern const char* callback3__(jieshiqi___* jsq,qu___* shangji,int* err,bool bylib,call_ex___* ce,
		const char* src,bool src_is_file,const char* src2,int argc,const char**argv,int from);
extern string callbackx__(int num,jieshiqi___* jsq,qu___* qu);

#endif /* JIESHIQI_CALLBACK_H_ */
