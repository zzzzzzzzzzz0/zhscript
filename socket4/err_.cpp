#include"inc.h"

#ifdef WIN32
#include"get_last_err.c"
typedef int (__stdcall *msgbox_)(void* v,const char* s,const char* title,unsigned int ui);
static msgbox_ msgbox__=(msgbox_)MessageBoxA;
dlle__ void set_msgbox___(long p){
  msgbox__=(msgbox_)p;
}
#endif

int err___(char* s){
#ifdef WIN32
	int i=WSAGetLastError();
	if(s){
		char s1[64];
		get_last_err2___(i,s1,64);
		msgbox__(0,s1,s,0);
	}
	return i;
#else
	if(s){
		//printf("recv: %s\n", strerror(errno));
		perror(s);
	}
	return errno;
#endif
}

int err___(const char* s,const char* s1,int i){
#ifdef WIN32
	msgbox__(0,s1,s,0);
#else
	printf("%s: %s\n", s,s1);
#endif
	return i;
}
