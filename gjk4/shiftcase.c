#include "1.h"
#include "gjk2.h"
#include "for_arg_.h"

static char a_[]="`~1!2@3#4$5%6^7&8*9(0)-_=+[{]}\\|;:\'\",<.>/?";
static void case__(char* buf,char* s,int i2_min,int i2_max,long siz,int*i1,int ctrl){
	int s_len=strlen(s);
	if(i2_max<=0)
		i2_max+=s_len;
	if(i2_min<0)
		i2_min+=s_len;
	int i2,i3;
	char c;
	int b;
	for(i2=-1;;){
		c=s[++i2];
		if(c==0)
			break;
		if(i2>=i2_min && i2<i2_max) {
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
		}
		if(*i1>=siz)
			break;
		buf[(*i1)++]=c;
	}
}

static void case2__(char* buf,long siz,int argc,va_list argv,int ctrl){
	char* s=NULL;
	int i2_min = 0, i2_max = 0;
	int c4w4;
	if(argc >= 1)
		s = va_arg(argv, char*);
	if(argc >= 2) {
		i2_min = hs7chuan4_zheng3shu4(va_arg(argv, char*), 10, &c4w4);
		if(c4w4)
			return;
	}
	if(argc >= 3) {
		i2_max = hs7chuan4_zheng3shu4(va_arg(argv, char*), 10, &c4w4);
		if(c4w4)
			return;
	}
	if(!s)
		return;
	int i1=0;
	case__(buf,s,i2_min,i2_max,siz,&i1,ctrl);
	buf[i1]=0;
}

_dle void shiftcase__(char* buf,long siz,int argc,...) {
	va_list argv;
	va_start(argv, argc);
	case2__(buf,siz,argc,argv,1);
	va_end(argv);
}

_dle void shiftcase2__(char* buf,long siz,int argc,...) {
	va_list argv;
	va_start(argv, argc);
	case2__(buf,siz,argc,argv,1|2);
	va_end(argv);
}

_dle void unshiftcase__(char* buf,long siz,int argc,...) {
	va_list argv;
	va_start(argv, argc);
	case2__(buf,siz,argc,argv,0x10);
	va_end(argv);
}

_dle void unshiftcase2__(char* buf,long siz,int argc,...) {
	va_list argv;
	va_start(argv, argc);
	case2__(buf,siz,argc,argv,0x10|0x20);
	va_end(argv);
}
