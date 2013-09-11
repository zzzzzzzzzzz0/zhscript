/*
 * gets.cpp
 *
 *  Created on: 2013-8-12
 *      Author: zzzzzzzzzzz
 */
#include <stdio.h>
#include "../new_gg/def1.h"

extern void* jsq_;
extern callback3_2___ cb2_;

dlle___ void gets__(int*err, char*buf, long bufsiz,void*ce, void*shangji, const char*code) {
	char* ret;
	const char*argv2[] = {buf};
	for(;;) {
		ret = fgets(buf, bufsiz, stdin);
		if(ret != buf)
			break;
		for(int i = 0; buf[i]; i++) {
			switch(buf[i]) {
			case '\n':
			case '\r':
				buf[i] = 0;
				break;
			}
		}
		cb2_(jsq_,shangji,err,ce,code,false,NULL,1,argv2,0);
		if(*err)
			break;
	}
}
