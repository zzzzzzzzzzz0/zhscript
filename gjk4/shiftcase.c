#include "1.h"
#include "for_arg_.h"

static char a_[]="`~1!2@3#4$5%6^7&8*9(0)-_=+[{]}\\|;:\'\",<.>/?";
static void case__(char* buf,char* s,int*i1,int ctrl){
	int i2,i3;
	char c;
	int b;
	if(s){
		for(i2=-1;;){
			c=s[++i2];
			if(c==0)
				break;
			for(;;){
				if(ctrl & 1){
					if(c>='a'&&c<='z'){
						c=c-'a'+'A';
						break;
					}
				}
				if(ctrl & 2){
					b=0;
					for(i3=0;;i3+=2){
						if(a_[i3]==0)
							break;
						if(c==a_[i3]){
							c=a_[i3+1];
							b=1;
							break;
						}
					}
					if(b)
						break;
				}
				if(ctrl & 0x10){
					if(c>='A'&&c<='Z'){
						c=c-'A'+'a';
						break;
					}
				}
				if(ctrl & 0x20){
					b=0;
					for(i3=0;;i3+=2){
						if(a_[i3]==0)
							break;
						if(c==a_[i3+1]){
							c=a_[i3];
							b=1;
							break;
						}
					}
					if(b)
						break;
				}
				break;
			}
			buf[(*i1)++]=c;
		}
	}
}

_dle void shiftcase__(char* buf,long siz,int argc,...) {
	int i1=0;
    _for_args( argc )
		case__(buf,s,&i1,1);
    _next_args
	buf[i1]=0;
}

_dle void shiftcase2__(char* buf,long siz,int argc,...) {
	int i1=0;
    _for_args( argc )
		case__(buf,s,&i1,1|2);
    _next_args
	buf[i1]=0;
}

_dle void unshiftcase__(char* buf,long siz,int argc,...) {
	int i1=0;
    _for_args( argc )
		case__(buf,s,&i1,0x10);
    _next_args
	buf[i1]=0;
}

_dle void unshiftcase2__(char* buf,long siz,int argc,...) {
	int i1=0;
    _for_args( argc )
		case__(buf,s,&i1,0x10|0x20);
    _next_args
	buf[i1]=0;
}
