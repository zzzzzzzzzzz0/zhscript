#include"1.h"

char* ltoa_(long l,char* buf,int radix){
    #ifdef _WINDOWS
    ltoa(l,buf,radix);
    #else
	char* fmt=(char*)"%ld";
	switch(radix){
	case 16:
		fmt=(char*)"%lx";
		break;
	}
	sprintf(buf,fmt,l);
    #endif
	return buf;
}

char* __strcpyn(char* s,const char* chuan4,int chang2){
	if(chang2<=0){
		s[0]=0;
		return s;
	}
#ifdef _WINDOWS
	return lstrcpyn( s, chuan4, chang2 );
#else
	memcpy( s, chuan4, --chang2 );
	s[chang2]=0;
	return s;
#endif
}

static char* _s=0;
static int _s_len;

char* s___(){return _s;}

int alloc___(int len){
	if(_s==0)
	{
		_s_len=len;
		_s=(char*)malloc(_s_len+1);
	}
	else if(_s_len<len)
	{
		_s_len=len;
		_s=(char*)realloc(_s,_s_len+1);
	}
	return _s!=0;
}

int __cat(char* s,int len){
	int i=_s_len;
	if(!alloc___(i+len))
		return -1;
	__strcpyn(_s+i,s,len+1);
	return len;
}

void cat4__(char* s){
	if(!s)
		return;
	__cat(s,strlen(s));
}

void head4__(char* s){
	int len;
	char c;
	if(!s)
		return;
	len=strlen(s);
	if(!alloc___(_s_len+len))
		return;
	__strcpyn(_s+len,_s,_s_len+1);
	c=_s[len];
	__strcpyn(_s,s,len+1);
	_s[len]=c;
}

void free___(){
		if(_s!=0){
				free(_s);
				_s=0;
		}
		_s_len=0;
}

void cpy4__(char* s){
	int	len;
	free___();
	if(!s)
		return;
    len=strlen(s);
	if(!alloc___(len))
		return;
	__strcpyn(_s,s,len+1);
}

const char* ret_s___(char* s) {
    cpy4__(s);
	return _s;
}

const char* ret___(long l) {
	char buf[32];
	return ret_s___(ltoa_(l,buf,10));
}
