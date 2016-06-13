/*
 * str.cpp
 *
 *  Created on: 2010-10-27
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "for_arg_.h"
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

dlle___ bool is_noname__(const char*s) {
	if(s) {
		bool has_ad = false, has1 = false, has2 = false;
		int has_09 = 0, has_ez = 0, has_AZ = 0;
		for(; *s; s++) {
			char c = *s;
			if(c >= '0' && c <= '9') {
				has_09++;
				continue;
			}
			if(c >= 'a' && c <= 'd') {
				has_ad = true;
				continue;
			}
			if(c >= 'e' && c <= 'z') {
				has_ez++;
				continue;
			}
			if(c >= 'A' && c <= 'Z') {
				has_AZ++;
				continue;
			}
			switch(c) {
			case '-':
				has1 = true;
				continue;
			case '_': case '.':
				has2 = true;
				continue;
			}
			return false;
		}
		if(has_ez > 2 && has_AZ > 2)
			return false;
		if(!has_ad && !has_ez && !has_AZ && !has2) {
			if(has_09 <= 4 &&  !has1)
				return false;
			if(has_09 <= 10 &&  has1)
				return false;
		}
	}
	return true;
}

dlle___ void strmid__(char**addr_ret,char* s,int argc,...){
	if(!s)
		return;

	long i1=0;
	long i2=0;
	char *s2=0, *s3 = 0;
	_for_args( argc )
		switch(i){
		case 3:
			s3=s;
			break;
		case 2:
			s2=s;
			break;
		case 1:
			i2=s2l__(s);
			break;
		case 0:
			i1=s2l__(s);
			break;
		}
	_next_args

	string buf = s;

	if(i2<=0)
		i2+=buf.size();
	if(i1<0)
		i1+=buf.size();
	if(i2<0 || i1<0)
		return;

	if(s2)
		i1+=strlen(s2);
	if(s3)
		i2 -= strlen(s3);

	if(i1>=(long)buf.size())
		return;

	if(i2>(long)buf.size())
		i2=buf.size();

	long len = i2 - i1;
	if(len <= 0)
		return;
	buf = buf.substr(i1, len);

	*addr_ret=dup__(buf.c_str());
}

dlle___ long strpos_2a2__(char* s,char* ss){
	if(!s || !ss)
		return -1;
	string buf = s;
	size_t i = buf.find(ss);
	if(i == string::npos)
		return -1;
	return i;
}
