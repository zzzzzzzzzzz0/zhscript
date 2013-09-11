/*
 * call_ex___.cpp
 *
 *  Created on: 2012-2-3
 *      Author: zzzzzzzzzzz
 */

#include "call_ex___.h"
#include "keyword.h"

call_ex___::call_ex___() {
	kw_=keyword_no_;
}

call_ex___::call_ex___(int kw, const string& s) {
	kw_ = kw;
	s_ = s;
}

call_ex___::~call_ex___() {
}

const string& call_ex___::s__(){
	return s_;
}
void call_ex___::s__(const string& s){
	s_=s;
}

int call_ex___::kw__(){
	return kw_;
}
void call_ex___::kw__(int i){
	kw_=i;
}
