/*
 * iconv.cpp
 *
 *  Created on: 2011-1-31
 *      Author: zzzzzzzzzzz
 */

#include"txtotxt.h"
#ifndef ver_no_iconv_
#include <iconv.h>
#include"for_arg_.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define bufsiz_ 512
#endif

static void add__(char* buf, size_t n, char mode, string &ret) {
	switch(mode) {
	case 'x': case 'X': {
		char fmt[] = {'%', '0', '2', mode};
		char buf2[3];
		for(size_t i = 0; i < n; i++) {
			sprintf(buf2, fmt, (unsigned char)buf[i]);
			ret.append(buf2, 2);
		}
		break; }
	case 0:
		ret.append(buf, n);
		break;
	}
}

dlle___ void iconv__(char**addr_ret,char *src,bool src_is_file,int argc,...){
#ifndef ver_no_iconv_
	if(!src)
		return;
	const char *from="gb18030";
	const char *to="utf8";
	char mode = 0;
	_for_args( argc )
		if(!s) continue;
		switch(i){
		case 0:
			if(s[0])
				from=s;
			break;
		case 1:
			if(s[0])
				to=s;
			break;
		case 2:
			mode = s[0];
			break;
		}
	_next_args

	iconv_t cd;
	if((iconv_t)-1 == (cd = iconv_open(to, from)))
		return;

	size_t len;
	char *inbuf;
	char *inbuf0;
	if(src_is_file){
	    FILE * pFile;
	    long lSize;
	    char * buffer;
	    size_t result;
	    pFile = fopen (src, "rb" );
	    if (pFile==NULL)
	        return;
	    fseek (pFile , 0 , SEEK_END);
	    lSize = ftell (pFile);
	    rewind (pFile);

	    buffer = new char[lSize];
	    if (buffer == NULL)
	    	return;

	    /* 将文件拷贝到buffer中 */
	    result = fread (buffer,1,lSize,pFile);
	    fclose (pFile);
	    if (result != lSize)
	    {
	        delete buffer;
	        return;
	    }

	    len = lSize;
	    inbuf0 = inbuf = buffer;
	}else{
		len=strlen(src);
		inbuf0=inbuf=src;
	}
	char* buf=new char[bufsiz_];
	size_t inbytesleft=len;
	char *outbuf;
	size_t outbytesleft;

	string ret;
	while(inbytesleft > 0){
		outbuf=buf;
		outbytesleft=bufsiz_;
		size_t i=iconv (cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
		int err = errno;
		if(outbuf!=buf){
			add__(buf, outbuf-buf, mode, ret);
		}
		if(i != (size_t)-1){
			outbuf=buf;
			outbytesleft=bufsiz_;
			iconv (cd, NULL, NULL, &outbuf, &outbytesleft);
			if(outbuf!=buf){
				add__(buf, outbuf-buf, mode, ret);
			}
			break;
		}
		if(err){
			if(err==E2BIG)
				;
			else if(err==EILSEQ){
			    inbytesleft = len-(inbuf-inbuf0);
			    inbytesleft--;
			    inbuf++;
			}
			else
				break;
		}
	}
	iconv_close(cd);
	delete buf;
	if(src_is_file){
		delete inbuf0;
	}
	*addr_ret=dup__(ret.c_str());
#endif
}
