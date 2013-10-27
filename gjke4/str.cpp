/*
 * str.cpp
 *
 *  Created on: 2010-10-27
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "string.h"
#include "stdio.h"

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
