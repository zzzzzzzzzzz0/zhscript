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
				sprintf(i,"%ld",src-src1);
			callback_(jsq_,shangji,err,ce,code,false,NULL,1,i);
		}
	}
	*addr_ret=dup__(buf.c_str());
}

dlle___ void tag_replace__(int*err,char**addr_ret,char*src1,void*ce,void*shangji,const char*code,int argc,...)
{
	if(!src1){
		return;
	}

	list<const char*> begin, end;
	_for_args( argc ) {
		if(s) {
			switch(s[0]) {
			case '1':
				begin.push_back(s + 1);
				continue;
			case '2':
				end.push_back(s + 1);
				continue;
			}
			*addr_ret=dup__(s);
		}
		*err = 1;
		return;
	} _next_args
	if(begin.size() == 0 || end.size() == 0) {
		*err = 10;
		return;
	}

	string buf;
	for(char*src=src1;*src;){
		bool b=false;
		for(list<const char*>::iterator li=begin.begin();li!=begin.end() && !b;li++){
			const char*sp=*li;
			if(startswith__(src,sp)){
				char*src2=src;
				src2+=strlen(sp);
				for(;*src2;src2++){
					for(list<const char*>::iterator li2=end.begin();li2!=end.end() && !b;li2++){
						const char*sp2=*li2;
						if(startswith__(src2,sp2)){
							char c = src2[0];
							src2[0] = 0;
							src+=strlen(sp);
							const char*ret = callback_(jsq_,shangji,err,ce,code,false,NULL,3, sp,src, sp2);
							if(*err) {
								return;
							}
							buf += ret;
							src2[0] = c;
							src2+=strlen(sp2);
							src = src2;
							b=true;
						}
					}
				}
			}
		}
		if(b)
			continue;
		buf+=*src++;
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
		vector<string> code2;
		int to;
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
				if(!s[0]) {
					to = 2;
				} else {
					to = 0;
					tag1.push_back(s);
				}
			} else {
				switch(to) {
				case 2:
					code2.push_back(s);
					break;
				default:
					code.push_back(s);
					break;
				}
			}
		} _next_args

		string src2 = src1;
		if(code2.size() > 0) {
			string src3;
			for(size_t i2 = 0; i2 < src2.size(); i2++) {
				char c = src2[i2];
				int add = 0;
				for(size_t i = 0; i < code2.size() && add == 0; i++) {
					const string& s = code2[i];
					if(s == "sp-") {if(!(c >= 0 && c < 0x20)) add++; continue;}
					if(s == "0-9") {if(c >= '0' && c <= '9') add++; continue;}
					if(s == "a-z") {if(c >= 'a' && c <= 'z') add++; continue;}
					if(s == "A-Z") {if(c >= 'A' && c <= 'Z') add++; continue;}
					if(s.find(c) != string::npos)
						add++;
				}
				if(add > 0)
					src3 += c;
			}
			src2 = src3;
		}

		const char*src=src2.c_str();
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
