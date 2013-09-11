/*
 * str.cpp
 *
 *  Created on: 2010-10-27
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "string.h"
#include "stdio.h"
#include "for_arg_.h"
#include<list>

dlle___ void dlln___(addslashes__)(char**addr_ret,const char*src,const char*ctl){
	string buf;
	char buf2[8]="\\x";
	if(src){
		size_t len=strlen(src);
		size_t ctlen=ctl?strlen(ctl):0;
		for(size_t i=0;i<len;i++){
			char c=src[i];
			int b=0;
			for(size_t i1=0;i1<ctlen&&!b;i1++){
				switch(ctl[i1]){
				case'C':
					switch(c){
					case'\r':b=1;c='r';break;
					case'\n':b=1;c='n';break;
					case'\t':b=1;c='t';break;
					case'\\':b=1;break;
					case'\'':b=1;break;
					case'"':b=1;break;
					}
					break;
				case'R':
					switch(c){
					case'.':b=1;break;
					case'$':b=1;break;
					case'^':b=1;break;
					case'*':b=1;break;
					case'[':b=1;break;
					case'-':b=1;break;
					case']':b=1;break;
					case'<':b=1;break;
					case'>':b=1;break;
					case'(':b=1;break;
					case')':b=1;break;
					case'|':b=1;break;
					case'+':b=1;break;
					case'?':b=1;break;
					case'{':b=1;break;
					case',':b=1;break;
					case'}':b=1;break;
					}
					break;
				case'x':
					if(c<' '||c>=127){
						sprintf(buf2+2,"%02x",(unsigned char)c);
						b=2;
					}
					break;
				}
			}
			if(b==2){
				buf+=buf2;
				continue;
			}
			if(b)
				buf+='\\';
			buf+=c;
		}
	}
	*addr_ret=dup__(buf.c_str());
}

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
		_for_args( argc )
			lst.push_back(s);
		_next_args
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
