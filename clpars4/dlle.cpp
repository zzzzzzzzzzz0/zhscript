/*
 * dlle.cpp
 *
 *  Created on: 2015年1月11日
 *      Author: zzzzzzzzzzz
 */

#include "clpars___.h"
#include "../new_gg/def1.h"

dlle___ void del__(clpars___* clp){
	if(clp)
		delete clp;
}

dlle___ void one__(int*err,char*buf,void*ce,void* shangji,bool no,int argc,...){
	clpars___ clp;
	va_list argv;
	va_start(argv, argc);
	int sp;
	clp.set__(buf,err,false,argc,argv,&sp);
	if(!*err)
		clp.par__(buf,err,ce,shangji,argc,argv,sp,no);
	va_end(argv);
}

static clpars___ clpars_;

dlle___ clpars___* set__(int*err,char*buf,bool need_new,bool add,clpars___* clp,int argc,...){
	if(need_new) {
		if(!clp)
			clp=new clpars___();
	} else
		clp=&clpars_;
	va_list argv;
	va_start(argv, argc);
	clp->set__(buf,err,add,argc,argv,NULL);
	va_end(argv);
	return clp;
}

dlle___ void par__(int* err,char*buf,void*ce,void* shangji,clpars___* clp,bool no,int argc,...){
	if(!clp)
		clp=&clpars_;
	va_list argv;
	va_start(argv, argc);
	clp->par__(buf,err,ce,shangji,argc,argv,0,no);
	va_end(argv);
}

dlle___ void info__(char**addr_ret,clpars___* clp,const char* t1,const char* t2,const char* n,bool yange){
	if(!clp)
		clp=&clpars_;
	clp->info__(addr_ret,t1,t2,n,yange);
}

dlle___ void info3__(int* err,char*buf,void*ce,void* shangji,clpars___* clp,char* code){
	if(!clp)
		clp=&clpars_;
	clp->info__(buf,err,ce,shangji,code);
}

dlle___ void pause__(clpars___* clp,bool pause,int argc,...){
	if(!clp)
		clp=&clpars_;
	char** argv = NULL;
	if(argc > 0) {
		argv = new char*[argc];
		va_list argv1;
		va_start(argv1, argc);
		for (int i = 0; i < argc; ++i){
			argv[i] = va_arg(argv1, char*);
		}
		va_end(argv1);
	}
	clp->pause__(pause, argc, argv);
	if(argv)
		delete argv;
}
