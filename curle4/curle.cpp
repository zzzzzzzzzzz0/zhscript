/*
 * curle.cpp
 *
 *  Created on: 2010-6-22
 *      Author: zzzzzzzzzzz
 */

#include <curl/curl.h>
#include<string>
using namespace std;
#include"def1.h"
#include<stdio.h>

class write___{
public:
	callback2___		cb_;
	void*	jsq_;
	void*	shangji_;
	string		script_;
};

size_t write__(void *ptr, size_t size, size_t nmemb, void *d0)
{
    //int written = fwrite(ptr, size, nmemb, (FILE *)fp);
    //return written;
	write___* w=(write___*)d0;
	char s2[16];
	char s3[16];
	sprintf(s2,"%u",size);
	sprintf(s3,"%u",nmemb);
	int err;
	w->cb_(w->jsq_,w->shangji_,&err,w->script_.c_str(),false,3,ptr,s2,s3);
	if(err)
		return 0;
	return nmemb;
}

dlle___ CURLcode dlln___(curl_easy_callback__)(CURL *curl,
		callback2___		cb,
		void*	jsq,
		void*	shangji,
		char*		script)
{
	CURLcode ret;
	ret=curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write__);
	if(ret!=CURLE_OK)
		return ret;
	write___* w=new write___();
	w->cb_=cb;
	w->jsq_=jsq;
	w->shangji_=shangji;
	w->script_=script;
	return curl_easy_setopt(curl, CURLOPT_WRITEDATA, w);
}
