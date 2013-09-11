/*
 * new.cpp
 *
 *  Created on: 2010-7-13
 *      Author: zzzzzzzzzzz
 */
#include "gjke.h"
#include "string.h"
#include "for_arg_.h"

dlle___ char* dlln___(new__)(int siz){
	char* mem=new char[siz];
	if(mem)
		memset(mem,0,siz);
	return mem;
}

dlle___ void dlln___(delete__)(int argc,...){
	_for_args( argc )
			delete (char*)x2lu__(s);
	_next_args
}

//叫复制内存是因为内存还在，不是直接作用
dlle___ char* dlln___(dup__)(char* p){
	return p;
}

dlle___ void* dlln___(pointer__)(char* p){
	char***pp=new char**;
	*pp=&p;
	return (void*)pp;
}

dlle___ char* dlln___(pointer2__)(char*** p){
	return **p;
}
