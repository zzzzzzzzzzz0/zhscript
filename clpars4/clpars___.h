/*
 * clpars___.h
 *
 *  Created on: 2011-7-10
 *      Author: zzzzzzzzzzz
 */

#ifndef CLPARS____H_
#define CLPARS____H_
#include <sstream>
#include <string>
#include <list>
using namespace std;
#include <stdarg.h>

class clpars_item___ {
public:
	string flag_;
	list<string> flags_;
	string info_;
	int argc_;
	string code_;
	char type_;
	clpars_item___(const char*flag,const char*info,const char*code,
			int argc1,char type){
		flag_=flag;
		info_=info;
		code_=code;
		argc_=argc1;
		type_=type;

    	stringstream ss(flag);
    	string s;
    	while(getline(ss,s,'|'))
    		flags_.push_back(s);
	}
};

class clpars___ {
private:
	list<clpars_item___*> item_;
	int cb__(const char*flag,bool by_help,bool no,int& i1,int&i,
			char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv);
	int par__(int& i1,int& i,const char* flag,bool by_help,
			char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,bool no);
public:
	clpars___();
	virtual ~clpars___();
	void set__(char*buf,int* err,bool add,int argc,va_list& argv,int* sp);
	void par__(char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,int from,bool no);
	void info__(char**&addr_ret,const char* t1,const char* t2,const char* n,bool yange);
	void info__(char*buf,int* err,void*ce,void* shangji,char* code);
};

#endif /* CLPARS____H_ */
