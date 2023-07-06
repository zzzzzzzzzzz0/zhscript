/*
 * for_err.cpp
 *
 *  Created on: 2021年5月29日
 *      Author: zzzzzzzzzzz
 */


#include "for_err.h"

#ifndef jieshiqi_err_go_
#define jieshiqi_err_	10000
#define jieshiqi_go_	 1000
#define jieshiqi_err_go_	jieshiqi_err_+jieshiqi_go_
#endif
#ifndef keyword_break_
#define keyword_break_    32
#define keyword_continue_ 33
#endif

#define no_err_ -1

int for_err__(int*err, bool rust) {
	if(*err == no_err_ && rust)
		return 0;
	if(*err){
		if(*err==jieshiqi_err_go_+keyword_continue_){
			*err= rust ? no_err_ : 0;
			return 0;
		}
		if(*err==jieshiqi_err_go_+keyword_break_){
			*err= rust ? no_err_ : 0;
			return 1;
		}
		return 1;
	}
	return 0;
}

