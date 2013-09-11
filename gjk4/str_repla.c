#include"1.h"
#include"strpos.h"

_dle void __str_replace_free(){
	free___();
}

_dle char* __str_replace(char* s,char* s1,char* s2){
	unsigned int i=0;
	int i1=strpos_2__(s,s1,i,0);
	if(i1<0)
		return s;
	__str_replace_free();
	for(;;){
		/*{
			char c[512];
			sprintf(c,"i=%d\ni1=%d\n_s=%s\n_s_len=%d",i,i1,_s,_s_len);
			MessageBox(0,c,"str_replace",0);
		}*/
		if(__cat(s+i,i1-i)<0)
			return 0;
		i=i1+strlen(s1);
		if(i>strlen(s))
			break;
		if(__cat(s2,strlen(s2))<0)
			return 0;
		i1=strpos_2__(s,s1,i,_strpos_return_len);
		if(i1<0)
			break;
	}
	return s___();
}
