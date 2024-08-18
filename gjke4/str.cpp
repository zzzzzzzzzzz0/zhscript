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
#include "strlen_sp.h"
#include "rust.h"

dlle___ int sp_len__(char* s1, int argc,...) {
	int len1 = -1;
	_for_args( argc )
		switch(i){
		case 0:
			len1 = s2i__(s);
			break;
		}
	_next_args
	return s1 ? strlen_sp__(s1, len1) : 0;
}

static string trim__(const char*src, int ctl, const char* sp1) {
	if(!src)
		return "";
	string buf = src;
	const char* sp = sp1 ? sp1 : " \t\r\n";
	if(ctl & 1)
		buf.erase(0, buf.find_first_not_of(sp));
	if(ctl & 2)
		buf.erase(buf.find_last_not_of(sp) + 1);
	return buf;
}
dlle___ void trim__(char**addr_ret, const char*src, int ctl) {
	string buf = trim__(src, ctl, NULL);
	*addr_ret = dup__(buf.c_str());
}
dlle___ void rust_trim2__(rust_add___ add, void* env, const char*src, const char*sp, int ctl) {
	string buf = trim__(src, ctl, sp);
	add(buf.c_str(), false, env);
}
dlle___ void rust_trim__(rust_add___ add, void* env, const char*src, int ctl) {
	rust_trim2__(add, env, src, NULL, ctl);
}

static void addslashes__(char**addr_ret,rust_add___ add, void* env, const char*src,const char*ctl){
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
	if(addr_ret)
		*addr_ret=dup__(buf.c_str());
	if(add)
		add(buf.c_str(), false, env);
}
dlle___ void dlln___(addslashes__)(char**addr_ret,const char*src,const char*ctl){
	addslashes__(addr_ret,NULL,NULL, src,ctl);
}
dlle___ void rust_addslashes__(rust_add___ add, void* env, const char*src,const char*ctl){
	addslashes__(NULL,add, env, src,ctl);
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

static void strmid__(string& buf2,char* s, long i1, long i2, char *s2 = 0, char *s3 = 0, char *s4 = 0){
	if(!s)
		return;

	string buf = s;
	long siz = buf.size();
	int use_s4 = 0;

	if(i2<=0)
		i2+=siz;
	if(i1<0) {
		i1+=siz;
		if(i1 > 0)
			use_s4 |= 1;
	}
	if(i2<0)
		return;
	if(i1<0)
		i1 = 0;

	if(s2)
		i1+=strlen(s2);
	if(s3)
		i2 -= strlen(s3);
	if(i2 < siz)
		use_s4 |= 2;

	if(i1>=siz)
		return;

	if(i2>siz)
		i2=siz;

	for(; i1 > 0 && i1 < i2; i1++) {
		if(((unsigned char)buf[i1] & 0xc0) != 0x80)
			break;
	}
	for(; i2 > 0; i2--) {
		unsigned char c = buf[i2 - 1];
		/*
		1字节：0xxxxxxx
		2字节：110xxxxx 10xxxxxx
		3字节：1110xxxx 10xxxxxx 10xxxxxx
		4字节：11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		5字节：111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		6字节：1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		*/
		c &= 0xc0;
		//11000000
		if(c == 0xc0) {
			i2--;
			break;
		}
		//10000000
		if(c == 0x80) {
			if(i2 == siz)
				break;
			if(((unsigned char)buf[i2] & 0xc0) != 0x80)
				break;
		} else
			break;
	}

	long len = i2 - i1;
	if(len <= 0)
		return;
	buf = buf.substr(i1, len);
	if(s4) {
		if(use_s4 & 1)
			buf = s4 + buf;
		if(use_s4 & 2)
			buf += s4;
	}
	buf2 = buf;
}
static void strmid__(string& buf2,char* s,int argc,va_list& argv){
	long i1=0;
	long i2=0;
	char *s2=0, *s3 = 0, *s4 = 0;
	for (int i = 0; i < argc; ++i){
		char*s = va_arg(argv, char*);
		switch(i){
		case 4:
			s4=s;
			break;
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
	}
	strmid__(buf2, s, i1, i2, s2, s3, s4);
}
dlle___ void strmid__(char**addr_ret,char* s,int argc,...){
	va_list argv;
	va_start(argv, argc);
	string buf;
	strmid__(buf, s, argc, argv);
	va_end(argv);
	*addr_ret=dup__(buf.c_str());
}
dlle___ void rust_strmid__(rust_add___ add, void* env,char* s,int argc,...){
	va_list argv;
	va_start(argv, argc);
	string buf;
	strmid__(buf, s, argc, argv);
	va_end(argv);
	add(buf.c_str(), 0, env);
}
dlle___ void rust_strmmid__(rust_add___ add, void* env,char* s1, long i1, long i2, int argc,...){
	string buf;
	strmid__(buf, s1, i1, i2);
	add(buf.c_str(), 0, env);

	va_list argv;
	va_start(argv, argc);
	for (int i = 0; i < argc; ++i){
		char*s = va_arg(argv, char*);
		switch(i % 2) {
		case 0:
			i1=s2l__(s);
			break;
		case 1:
			i2=s2l__(s);
			buf.clear();
			strmid__(buf, s1, i1, i2);
			add(buf.c_str(), 1, env);
			break;
		}
	}
	va_end(argv);
}

long strpos__(char* src,char* ss, size_t from, const char* skip, char ctl, bool utf8, bool r) {
	if(!src || !ss)
		return -1;
	string buf = src;
	size_t pos;
	if(r) {
		if(skip)
			from -= strlen(skip);
		pos = buf.rfind(ss, from);
	} else {
		if(skip)
			from += strlen(skip);
		pos = buf.find(ss, from);
	}
	if(pos == string::npos)
		return -1;
	if(utf8)
		pos = strlen_sp__(buf, pos, 1);
	switch(ctl) {
	case '2':
		pos += strlen(ss);
		break;
	}
	return pos;
}
void strpos__(int i, char* s, size_t &from, const char* &skip, char &ctl) {
	if(!s)
		return;
	switch(i) {
	case 0: {
		int i2 = s2i__(s);
		from = i2 > 0 ? i2 : 0;
		break; }
	case 1:
		skip = s;
		break;
	case 2:
		ctl = s[0];
		break;
	}
}
dlle___ long strpos__(char* src,char* ss, bool utf8, int argc, ...) {
	size_t from = 0;
	const char* skip = NULL;
	char ctl = 0;
	_for_args( argc )
		strpos__(i, s, from, skip, ctl);
	_next_args
	return strpos__(src, ss, from, skip, ctl, utf8, false);
}
dlle___ long strrpos__(char* src,char* ss, bool utf8, int argc, ...) {
	size_t from = string::npos;
	const char* skip = NULL;
	char ctl = 0;
	_for_args( argc )
		strpos__(i, s, from, skip, ctl);
	_next_args
	return strpos__(src, ss, from, skip, ctl, utf8, true);
}

dlle___ bool strstr__(const char* s1, int c, int argc, ...) {
	if(s1) {
		string s11 = s1;
		_for_args( argc )
			if(s) {
				switch(c) {
				case 1:
					if(s[0] && s11.find(s) == 0)
						return true;
					break;
				case 2:
					if(s[0]) {
						size_t pos = s11.rfind(s);
						if(pos != string::npos && pos == s11.length() - string(s).length())
							return true;
					}
					break;
				case 3:
					if(s11 == s)
						return true;
					break;
				default:
					if(s11.find(s) != string::npos)
						return true;
					break;
				}
			}
		_next_args
	}
	return false;
}

#include "strcmp.h"
dlle___ int strcmp__(char* s1, char* s2) {
	if(!s1 && !s2) return 0;
	if(s1 && !s2) return 1;
	if(!s1 && s2) return -1;
	return strcmp__(s1, s2, 0);
}
dlle___ int strcm2__(char* s1, char* s2) {
	if(!s1 || !s2) return 0;
	return strcmp2__(s1, s2);
}
