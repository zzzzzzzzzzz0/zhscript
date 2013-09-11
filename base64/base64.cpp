#include"base64.h"
#include"def1.h"

dlle___ void dlln___(base64encode__)(/*char**addr_ret*/char*buf,int siz,char * str){
	int len = strlen(str) * 2 + 4 + 1;
	if(len>siz)
		return;
	//*addr_ret=new char[len];
	Base64Encode(/**addr_ret*/buf, str);
}

dlle___ void dlln___(base64decode__)(/*char**addr_ret*/char*buf,int siz,char * base64code){
	int len = (strlen(base64code)-4)/2 + 1;
	if(len>siz)
		return;
	//*addr_ret=new char[len];
	Base64Decode(/**addr_ret*/buf, base64code);
}
