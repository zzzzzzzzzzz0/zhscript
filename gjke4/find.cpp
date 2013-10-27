/*
 * find.cpp
 *
 *  Created on: 2013-10-27
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "string.h"
#include "stdio.h"
#include <list>
#include <vector>
#include "for_arg_.h"

bool startswith__(const char*src,const char*tag){
	if(!tag)
		return false;
	for(;;){
		if(!*tag)
			return true;
		if(!*src)
			return false;
		if(*tag++!=*src++)
			return false;
	}
}

dlle___ void find_and_get__(int*err,char**addr_ret,const char*src1,int from,
		const char*tag1,void*ce,void*shangji,const char*code,int argc,...){
	string buf;
	if(src1){
		const char*src=src1;
		for(;--from>=0;)
			src++;
		list<const char*> lst;
		_for_args( argc ) {
			if(!s) {
				*err = 1;
				return;
			}
			lst.push_back(s);
		} _next_args
		if(tag1){
			for(;*src;src++){
				if(startswith__(src,tag1)){
					src+=strlen(tag1);
					break;
				}
			}
		}
		bool b=false;
		for(;*src;src++){
			for(list<const char*>::iterator li=lst.begin();li!=lst.end();li++){
				const char*sp=*li;
				if(startswith__(src,sp)){
					src+=strlen(sp);
					b=true;
					break;
				}
			}
			if(b)
				break;
			buf+=*src;
		}
		if(code){
			char i[8]="-1";
			if(*src)
				sprintf(i,"%d",src-src1);
			callback_(jsq_,shangji,err,ce,code,false,NULL,1,i);
		}
	}
	*addr_ret=dup__(buf.c_str());
}

dlle___ void replace__(int*err,char**addr_ret,void*ce,void*shangji,
		const char*src1,int argc,...)
{
	string buf;
	if(src1){
		vector<const char*> tag1;
		vector<const char*> code;
		_for_args( argc ) {
			if(!s) {
				*err = 1;
				return;
			}
			if(i % 2 == 0) {
				if(i + 1 >= argc) {
					*err = 2;
					return;
				}
				tag1.push_back(s);
			} else {
				code.push_back(s);
			}
		} _next_args

		const char*src=src1;
		for(;*src;){
			bool b=false;
			for(size_t i = 0; i < tag1.size(); i++) {
				const char*sp = tag1[i];
				if(startswith__(src,sp)){
					src+=strlen(sp);
					b=true;

					buf += callback_(jsq_,shangji,err,ce,
							code[i],false,sp,0);
					if(*err)
						return;
					break;
				}
			}
			if(b)
				continue;
			buf+=*src++;
		}
	}
	*addr_ret=dup__(buf.c_str());
}
