/*
 * s1___.cpp
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#include <deque>
using namespace std;
#include "s1___.h"

static deque<s1___*>* s1s_ = NULL;
size_t s1s_length__() {
	if(!s1s_)
		return 0;
	return s1s_->size();
}
s1___* s1s__(int i) {
	if(!s1s_)
		return NULL;
	return (*s1s_)[i];
}
static void s1s_push__(s1___* s1) {
	if(!s1s_)
		s1s_ = new deque<s1___*>();
	s1s_->push_back(s1);
}

s1___::s1___(const char* src2, const char* signal, char type) {
	init__(src2, signal, type);
}

s1___::s1___(const char* src2, const char* signal, char type, GCallback cb) {
	init__(src2, signal, type);
	cb_ = cb;
}

void s1___::init__(const char* src2, const char* signal, char type) {
	if(src2)
		src2_ = src2;
	else
		src2_ = signal;
	signal_ = signal;
	type_ = type;
	cb_ = NULL;
	i_ = s1s_length__();
	s1s_push__(this);
}
