/*
 * gets.cpp
 *
 *  Created on: 2013-8-12
 *      Author: zzzzzzzzzzz
 */
#include <stdio.h>
#include <string.h>
#include "pub.h"

dlle___ void gets__(int*err, char*buf, long bufsiz,void*ce, void*shangji, const char*code) {
	char* ret;
	const char*argv2[] = {buf};
	for(;;) {
		ret = fgets(buf, bufsiz, stdin);
		if(ret != buf)
			break;
		size_t i = strlen(buf);
		while(i > 0) {
			char c = buf[i];
			if(c == '\n' || c == '\r')
				buf[i] = 0;
			else
				break;
			i--;
		}
		cb2_(jsq_,shangji,err,ce,code,false,NULL,1,argv2,0);
		if(*err == jieshiqi_err_go_+keyword_continue_){
			*err=0;
			continue;
		}
		if(*err == jieshiqi_err_go_+keyword_break_){
			*err=0;
			break;
		}
		if(*err)
			break;
	}
}
