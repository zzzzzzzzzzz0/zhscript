#include "1.h"

//起始不必为 0是末尾 如同 结束0便不是头
_dle char* strmid__(char* s1,char* s,int i1,int i2,char* s2){
	int s_len;

	if(!s1 || !s)
		return 0;

	s_len=strlen(s);
	s1[0]=0;

	if(i2<=0)
		i2+=s_len;
	if(i1<0)
		i1+=s_len;
	if(i2<0 || i1<0)
		return s1;

	if(s2)
		i1+=strlen(s2);

	if(i1>=s_len)
		return s1;

	if(i2>s_len)
		i2=s_len;

	return __strcpyn(s1,s+i1,i2-i1+1);
}

_dle char* strmid_a4__(char* s1,char* s,int i1,int i2){
	return strmid__(s1,s,i1,i2,NULL);
}

#include "for_arg_.h"
#include "gjk2.h"
_dle void strmid_(int *c4w4,char* s1,long s1_len,char* s,int argc,...){
	int i1=0;
	int i2=0;
	char* s2=0;
	_for_args( argc )
		switch(i){
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

	strmid__(s1,s,i1,i2,s2);
}
