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
	int tou2=0;
	int pan2=-1;
	int xie3=-1;
	for(i=0;i<=wei3;i++){
		if(name[i]=='/' || name[i]=='\\')
			break;
		if(name[i]==':'){
			if(i==1){
				char c=name[i-1];
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
				char c=name[i-1];
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
		case 0://扩展名
		from=dian3;
		to=wei3+1;
		break;
		case 1://主名
		from=mo4;
		to=dian3;
		break;
		case 2://路径
		from=tou2;
		to=mo4;
		break;
		case 3://盘符
		if(pan2>=0){
			from=pan2;
			to=tou2;
		}
		break;
		case 4://协议
		if(xie3>=0){
			from=0;
			to=xie3+1;
		}
		break;
		case -1://扩展名
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

dlle___ void shenglvename__(char*buf,long bufsiz,char*name,int argc,...){
	if(!name)
		return;

	bool quhouzhui=false;
	char* fengefu="/";
	bool qukongceng=true;
	_for_args( argc )
			switch(s[0]){
			case'x':
				quhouzhui=true;
				break;
			case'/':
				fengefu=s + 1;
				break;
			case'_':
				qukongceng=false;
				break;
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
			ss[i1]=&name[start];
			break;
		}
		switch(name[i]){
		case'/':
			name[i]=0;
			ss[i1++]=&name[start];
			start=i+1;
			break;
		}
	}
	//for(i=0;i<len;i++)printf("%d/%d=%s\n",i,len,ss[i].c_str());
	for(int i5=0;i5<len-1;i5++){
		for(int i6=i5+1;i6<len;i6++){
			if(ss[i6]=="index"){
				ss[i6].clear();
				continue;
			}
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
	string o;
	for(int i5=0;i5<len;i5++){
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
