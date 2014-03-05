/*
 * args_util.cc
 *
 *  Created on: 2014年2月18日
 *      Author: zzzzzzzzzzz
 */

#include "args_util.hh"

void jieshiqi_args_del__(std::string& s) {
	s = jieshiqi_args_del_;
}
void jieshiqi_args_del_line__(std::string& s, size_t from) {
	const char* s1 = jieshiqi_args_del_;
	for(size_t i = from; i < s.size(); i++) {
		if(*s1) {
			s[i] = *s1++;
		} else {
			if(s[i] == ' ')
				break;
			s[i] = ' ';
		}
	}
}
void jieshiqi_args_del__(char* s) {
	if(!s)
		return;
	const char* s1 = jieshiqi_args_del_;
	for(; (*s++ = *s1++););
}
void jieshiqi_args_del_line__(char* s, size_t from) {
	if(!s)
		return;
	const char* s1 = jieshiqi_args_del_;
	for(size_t i = from; s[i]; i++) {
		if(*s1) {
			s[i] = *s1++;
		} else {
			if(s[i] == ' ')
				break;
			s[i] = ' ';
		}
	}
}
