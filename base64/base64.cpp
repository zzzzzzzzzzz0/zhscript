#include"base64.h"

#ifdef ver_rust_
//gxx.zs =so =r -o /zzzzzzzzzzz4/usr/lib/zhscript2-rust/lib/base64.so *.cpp -Dver_rust_
#include <fstream>
using namespace std;
#include "../gjke4/rust.h"

extern "C" void file__(rust_add___ add, void* env, const char* path) {
	ifstream is(path, ifstream::in | ios::binary);
	is.seekg(0, is.end);
	int len = is.tellg();
	is.seekg(0, is.beg);
	char *buf = new char[len];
	is.read(buf, len);
	int len2 = len * 2 + 4 + 1;
	char *buf2 = new char[len2];
	Base64Encode(buf2, buf, len);
	add(buf2, false, env);
	delete buf;
	delete buf2;
}

#else

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
#endif
