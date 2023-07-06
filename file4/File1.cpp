#include<string>
using namespace std;
#include"def1.h"
#include"for_arg_.h"
#include<string.h>
#include<stdio.h>

void extractfilename__(string& buf2,const string& name,int flag){
	int i;
	int mo4=0;
	int wei3=name.length()-1;
	int wei3ba1=wei3;
	for(i=wei3;i>=0;i--){
		if(name[i]=='?'){
			wei3=i-1;
			break;
		}
	}
	for(i=wei3;i>=0;i--){
		if(name[i]=='/' || name[i]=='\\'){
			mo4=i+1;
			break;
		}
	}
	int dian3=wei3+1;
	for(i=wei3;i>=mo4;i--){
		if(name[i]=='.'){
			dian3=i;
			break;
		}
	}
	int dian3a=dian3;
	for(i=mo4;i<dian3;i++){
		if(name[i]=='.'){
			dian3a=i;
			break;
		}
	}
	int tou2=0;
	int pan2=-1;
	int xie3=-1;
	for(i=0;i<=wei3;i++){
		char c=name[i];
		{
			bool b = false;
			switch(c) {
			case '/': case '\\': case '.':
				b = true;
			}
			if(b)
				break;
		}
		if(c==':'){
			if(i==1){
				c=name[i-1];
				if((c>='a' && c<='z') || (c>='A' && c<='Z')){
					pan2=i-1;
					tou2=i+1;
					break;
				}
			}
			if(xie3<0){
				xie3=i;
				tou2=xie3;
				for(;name[i+1]=='/';i++,xie3++);
				if(tou2==xie3)
					tou2=xie3+1;
				else
					tou2=xie3;
			}else{
				c=name[i-1];
				if((c>='a' && c<='z') || (c>='A' && c<='Z')){
					pan2=i-1;
					tou2=i+1;
				}
				break;
			}
		}
	}
	//printf("{%d,%d,%d,%d,%d}",xie3,pan2,tou2,dian3,mo4);
	if(mo4<tou2)
		mo4=tou2;

	int from=0,to=0;
	switch(flag){
		case 0://��չ��
		from=dian3;
		to=wei3+1;
		break;
		case 10:
		from=dian3 + 1;
		to=wei3+1;
		break;
		case 100:
		from=dian3a;
		to=wei3+1;
		break;
		case 1://����
		from=mo4;
		to=dian3;
		break;
		case 11:
		from=mo4;
		to=dian3a;
		break;
		case 2://·��
		from=tou2;
		to=mo4;
		break;
		case 22:
		to=mo4 - 1;
		for(from=to - 1;from > tou2;from--)
			if(name[from]=='/' || name[from]=='\\') {
				from++;
				break;
			}
		break;
		case 3://�̷�
		if(pan2>=0){
			from=pan2;
			to=tou2;
		}
		break;
		case 4://Э��
		if(xie3>=0){
			from=0;
			to=xie3+1;
		}
		break;
		case -1://��չ��
		from=wei3+2;
		to=wei3ba1+1;
		break;
	}
	for(i=from;i<to && i<=wei3ba1;){
		buf2 += name[i++];
	}
}

dlle___
void extractfilename___(char* buf,long siz,char* name0,int argc,...){
	if(!name0)
		return;
	string name=name0, buf2;
	int flag;
	_for_args( argc )
		if(sscanf(s, "%d", &flag) == 1)
			extractfilename__(buf2, name, flag);
		else if(s[0] == '\\')
			buf2 += s + 1;
		else
			buf2 += s;
	_next_args
	int i1=0;
	for(;i1 < buf2.size() && i1<siz-1; i1++){
		buf[i1] = buf2[i1];
	}
	buf[i1]=0;
}

char* strstr__(const char* s, const char* s1) {
	//return strstr(s,s1);
	if(!s||!s1)
		return NULL;
	for(;*s;){
		if(*s==*s1){
			const char* s3=s;
			const char* s2=s1;
			for(;*s2;s2++){
				if(!*s)
					break;
				if(*s==*s2){
					s++;
				} else
					break;
			}
			if(!*s2)
				return (char*)s3;
			continue;
		}
		s++;
	}
	return NULL;
}
void strcpy__(char*s1b, char*s2b) {
	for(;;){
		if(!*s1b){
			*s2b=0;
			break;
		}
		*s2b++=*s1b++;
	}
}

void remove_dd_2__(const char* s, const char* s2, int i) {
	for(;;) {
		char* s1 = strstr__(s, s2);
		if(!s1) break;
		strcpy__(s1 + i, s1);
	}
}
void remove_dd_3__(char* s, const char* s2) {
	unsigned int len2=strlen(s2);
	for(;;) {
		unsigned int i=strlen(s);
		if(i > len2) {
			const char* s3 = s + (i -= len2);
			const char* s4 = s2;
			for(; *s4;) {
				if(*s3++ != *s4++)
					return;
			}
			s[i] = 0;
		}
		return;
	}
}
dlle___ char* remove_dd2_x__(char*src, int opt){
	if(src){
		string src1 = src, dd = "/..";
		for(size_t i0 = 0;;) {
			size_t i = src1.find(dd, i0);
			if(i == string::npos) {
				break;
			}
			string s1 = src1.substr(i0, i - i0), s2 = src1.substr(i + dd.size()), s0 = src1.substr(0, i0);
			printf("|s0=%s i0=%lu\n|s1=%s dd=%s=i=%lu\n|s2=%s\n",s0.c_str(),i0,s1.c_str(),dd.c_str(),i,s2.c_str());
			if(s1 == ".") {
				src1 = s0 + s1 + s2;
				i0 += s1.length();
			} else if(s1 == "..") {
				i0 += s1.length() + dd.length();
			} else if(s1 == "") {
				src1 = s0 + dd + s2;
				i0 += dd.size();
			} else {
				size_t i1 = s1.rfind("/");
				printf("rs1/=i1=%lu\n",i1);
				if(i1 == string::npos) {
					if(i0 == 0) for(; s2[0] == '/';)
						s2 = s2.substr(1);
					src1 = s0 + s2;
				} else {
					s1 = s1.substr(0, i1);
					printf("|s1=%s\n",s1.c_str());
					src1 = s0 + s1 + s2;
					//i0 += s1.length();
				}
			}
			printf("|%s\n",src1.c_str());
		}
		for(size_t i = 0;; i++) {
			if(i >= src1.size()) {
				src[i] = 0;
				break;
			}
			src[i] = src1[i];
		}
	}
	return src;
}
dlle___ char* remove_dd2__(char*src, int opt){
	if(src){
		const char*dd="..";
		unsigned int dd_len=strlen(dd);
		unsigned int start=0;
		char* s1_old=NULL;
		for(;;){
			//printf("%s\n",src);
			char* s1=strstr__(src+start,dd);
			if(!s1 || s1==s1_old)
				break;
			s1_old=s1;
			char* s2=s1-1;
			if(s2<src+start){
				start+=dd_len+1;
				continue;
			}
			for(;;) if(*(s2 - 1) == '/') s2--; else break;
			char c=s2[0];
			for(;;){
				if(--s2<src+start)
					break;
				if(*s2==c){
					//strcpy(s1,s2+1);
					strcpy__(s1+dd_len, s2);
					break;
				}
			}
		}
		if(opt & 1) remove_dd_2__(src,"//", 1);
		if(opt & 2) {
			remove_dd_2__(src,"/./", 2);
			remove_dd_3__(src,"/.");
		}
		if(opt & 4) remove_dd_3__(src,"/");
	}
	return src;
}
dlle___ char* remove_dd__(char*src){
	return remove_dd2__(src, 0);
}

dlle___ void add__(char*buf,long siz, char*src0, char*tag){
	if(!src0 || !tag) return;
	int pos = -1;
	for(int i = 0;; i++) {
		char c1 = src0[i], c2 = tag[i];
		if(!c1 || !c2 || c1 != c2) break;
		if(c1 == '/') pos = i;
	}
	string src = src0;
	if(pos > -1) {
		src = src.substr(pos + 1);
		size_t cnt = 0;
		for(int i = pos;; i++) {
			char c2 = tag[i];
			if(!c2) break;
			if(c2 == '/') cnt++;
		}
		for(; cnt > 0; cnt--) {
			src = "../" + src;
		}
	}
	size_t i = 0;
	for(; i < siz - 1 && i < src.size(); i++) {
		buf[i] = src[i];
	}
	buf[i] = 0;
}

static void shenglvename_1__(string& s, char*name, int start, bool qugangtou) {
	s = &name[start];
	if((s[0]=='i' &&
		s[1]=='n' &&
		s[2]=='d' &&
		s[3]=='e' &&
		s[4]=='x')
	|| (qugangtou && s.size() >= 2 && s[s.size() - 1] == '_')){
		s.clear();
	}
}
dlle___ void shenglvename__(char*buf,long bufsiz,char*name,int argc,...){
	if(!name)
		return;

	bool quhouzhui=false, qukongceng=true, qugangtou=false;
	size_t youchang = 0;
	char* fengefu="/";
	_for_args( argc )
			switch(s[0]){
			case'x':
				quhouzhui=true;
				break;
			case'_':
				qukongceng=false;
				break;
			case'-':
				qugangtou=true;
				break;
			case'/':
				fengefu=s + 1;
				break;
			case'l':
				youchang = 15;
				sscanf(s + 1, "%lu", &youchang);
				break;
			default:
				return;
			}
	_next_args
	int len=0;
	for(i=0;name[i];i++){
		switch(name[i]){
		case'/':
			len++;
			break;
		}
	}
	len++;
	if(quhouzhui){
		for(;i>=0;i--){
			if(name[i]=='/')
				break;
			if(name[i]=='.'){
				name[i]=0;
				break;
			}
		}
	}
	string* ss=new string[len];
	int i1=0,start=0;
	for(i=0;;i++){
		if(!name[i]){
			shenglvename_1__(ss[i1], name, start, qugangtou);
			break;
		}
		switch(name[i]){
		case'/':
			name[i]=0;
			
			shenglvename_1__(ss[i1++], name, start, qugangtou);
			start=i+1;
			break;
		}
	}
	//for(i=0;i<len;i++)printf("%d/%d=%s\n",i,len,ss[i].c_str());
	for(int i5=0;i5<len-1;i5++){
		for(int i6=i5+1;i6<len;i6++){
			int i5size = ss[i5].size();
			for(int i7=i5size;i7>0;i7--){
				if(i7 < i5size) {
					unsigned char c = ss[i5][i7];
					if(c >= '0' && c <= '9')
						continue;
					if((c & 0xc0) == 0x80)
						continue;
				}
				string s=ss[i5].substr(0,i7);
				if(ss[i6].find(s)==0){
					ss[i6]=ss[i6].substr(s.size());
					//printf("%d/%d/%s=%s\n",i5,i6,s.c_str(),ss[i6].c_str());
					break;
				}
			}
			for(;;){
				bool b=false;
				if(ss[i6].size()>0){
					char c=ss[i6][0];
					switch(c){
					case'.':case' ':case'-':case'_':case':':
						//printf("%dt=%s\n",i6,ss[i6].c_str());
						ss[i6]=ss[i6].substr(1);
						break;
					default:
						b=true;
						break;
					}
				}else
					b=true;
				if(b)
					break;
			}
		}
	}
	int i5=0;
	if(youchang) {
		size_t i2 = 0;
		for(i = len; --i >= 0;) {
			if((i2 += ss[i].size()) >= youchang) {
				i5 = i;
				break;
			}
		}
	}
	string o;
	for(;i5<len;i5++){
		if(ss[i5].size()<1&&(i5==len-1||qukongceng))
				continue;
		if(o.size()>0)
			o+=fengefu;
		o+=ss[i5];
	}
	//delete ss;
	//printf("%s\n",o.c_str());
	for(i=0;(buf[i]=o[i]);i++);
}
