#include "1.h"

//起始不必为 0是末尾 如同 结束0便不是头
static int strmid__(char* s1,long s1_len,char* s,int i1,int i2,char* s2, char* s3){
	int s_len, len;

	if(!s1 || !s)
		return 10;

	s_len=strlen(s);
	s1[0]=0;

	if(i2<=0)
		i2+=s_len;
	if(i1<0)
		i1+=s_len;
	if(i2<0 || i1<0)
		return 0;

	if(s2)
		i1+=strlen(s2);
	if(s3)
		i2 -= strlen(s3);

	if(i1>=s_len)
		return 0;

	if(i2>s_len)
		i2=s_len;

	len = i2-i1+1;
	if(len > s1_len)
		return s1_len;

	//__strcpyn(s1,s+i1,len);
	int i, i3 = 0, i4;
	for(i = 0; i < i2;) {
		unsigned char c = s[i];
		int n;
		if(c >= 224)
			n = 3;
		else if(c >= 192)
			n = 2;
		else
			n = 1;
		if(i >= i1) {
			for(i4 = 0; i4 < n; i4++)
				s1[i3++] = s[i++];
		} else
			i += n;
	}
	s1[i3] = 0;
	return 0;
}

#include "for_arg_.h"
#include "gjk2.h"
_dle void strmid_(int *c4w4,char* s1,long s1_len,char* s,int argc,...){
	int i1=0;
	int i2=0;
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
			i2=atoi(s);
			break;
		case 0:
			i1=atoi(s);
			break;
		}
	_next_args

	*c4w4 = strmid__(s1,s1_len,s,i1,i2,s2, s3);
}
