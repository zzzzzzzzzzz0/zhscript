/*
 * util.cpp
 *
 *  Created on: 2010-6-5
 *      Author: zzzzzzzzzzz
 */

#include"util.h"
#include <iostream>
//#include<sstream>
#include<stdio.h>

char* l2s__(long num,char* num2){
	/*stringstream ss;
	ss<<num;
	ss>>num2;*/
	sprintf(num2,"%ld",num);
	return num2;
}

char* l2x__(long num,char* buf){
	sprintf(buf,"%lx",num);
	return buf;
}

guint32 s2u__(const Glib::ustring&s,guint32 i){
	sscanf(s.c_str(),"%u",&i);
	return i;
}

gint32 s2i__(const Glib::ustring&s,gint32 i){
	sscanf(s.c_str(),"%d",&i);
	return i;
}

char* d2s__(gdouble d,char*s){
	sprintf(s,"%g",d);
	return s;
}

long s2l__(const Glib::ustring&s,long i){
	sscanf(s.c_str(),"%ld",&i);
	return i;
}

unsigned long x2lu__(const Glib::ustring&s,unsigned long i){
	sscanf(s.c_str(),"%lx",&i);
	return i;
}

void cpy__(char*buf,long num,long siz){
	char num2[32];
	cpy__(buf,l2s__(num,num2),siz);
}

bool file_get__(const char*name,Glib::ustring& buf){
	gchar *contents;
	gsize length;
	GError *error=NULL;
	if(g_file_get_contents(name,&contents,&length,&error)){
		buf+=contents;
		g_free(contents);
		return true;
	}else{
	    if (error != NULL) {
	    	std::cerr << error->message << std::endl;
	        g_clear_error(&error);
	    }
	    return false;
	}
}

#include"call_util.cpp"
