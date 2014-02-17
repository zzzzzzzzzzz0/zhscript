/*
 * str.cpp
 *
 *  Created on: 2010-10-27
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "string.h"
#include "stdio.h"

dlle___ void trim__(char**addr_ret, const char*src, int ctl) {
	if(!src){
		return;
	}
	string buf = src;
	if(ctl & 1)
		buf.erase(0, buf.find_first_not_of(' '));
	if(ctl & 2)
		buf.erase(buf.find_last_not_of(' ') + 1);
	*addr_ret = dup__(buf.c_str());
}

dlle___ void dlln___(addslashes__)(char**addr_ret,const char*src,const char*ctl){
	if(!src){
		return;
	}
	string buf;
	char buf2[8]="\\x";
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
	*addr_ret=dup__(buf.c_str());
}
