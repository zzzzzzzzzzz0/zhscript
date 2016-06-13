/*
 * var_oper___.cpp
 *
 *  Created on: 2010-3-28
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include "util.h"
#include "jieshiqi_call.h"

#include <stdlib.h>
#include <errno.h>
#ifdef ver_dll_
extern "C"{
#endif
#include<dlfcn.h>
#ifdef ver_dll_
}
#endif
#include <stdio.h>
#include "call_func2.h"
#include"defi.h"

bool dlerr__(err___* err){
	const char*dlerr=dlerror();
	if(dlerr){
		*err<<dlerr;
		return true;
	}
	return false;
}

int jieshiqi___::call__(deque<string>* p,string& buf,qu___* qu){
	if(p->size()<1)
		return errinfo_param_num_;
	string first=(*p)[0];
	unsigned long type=call_type__(first,&err_);
	if(type & calltype_err_type_)
		return errinfo_func_type_;
	if(type & calltype_loadlibrary_){
		if(p->size()<2)
			return errinfo_param_num_;
		void* dl=0;
		err___ err;
		for(size_t i=1;i<p->size();i++){
			dl=dlopen((*p)[i].c_str(),RTLD_LAZY);
			if(!dlerr__(&err)){
				err.del__();
				break;
			}
		}
		if(err.has__()){
			err_<<err;
			return errinfo_open_;
		}
		buf+=l2x__((long)dl);
		return 0;
	}
	if(type & calltype_getprocaddr_){
		if(p->size()<3)
			return errinfo_param_num_;
		void* dl=(void*)x2l__((*p)[1]);
		void*func=dlsym(dl,(*p)[2].c_str());
		if(dlerr__(&err_))
			return errinfo_get_;
		for(size_t i=1;i<first.length();){
			char c=first[i++];
			switch(c){
			case' ':
				break;
			default:
				buf+=c;
				break;
			}
		}
		buf+=funcfmt_func_fengefu_;
		buf+=l2x__((long)func);
		buf+=funcfmt_func_fengefu_;
		for(size_t i=3;i<p->size();i++){
			string s=(*p)[i];
			type=call_type__(s,&err_);
			if(type & calltype_err_type_)
				return errinfo_func_type_;
			if(type==calltype_void_)
				continue;
			if(i>3)
				buf+=funcfmt_param_fengefu_;
			for(size_t i2=0;i2<s.length();){
				char c=s[i2++];
				switch(c){
				case' ':
				case funcfmt_param_fengefu_:
					break;
				case'$':
					if(s[i2]=='{'){
						buf+=c;//奇怪，这一行不能去掉成下下行移到循环最后
						for(;i2<s.length();){
							c=s[i2++];
							buf+=c;
							if(c=='}')
								break;
						}
						break;
					}
				default:
					buf+=c;
					break;
				}
			}
		}
		return 0;
	}
	if(type & calltype_freelibrary_){
		if(p->size()<2)
			return errinfo_param_num_;
		for(size_t i=1;i<p->size();i++){
			void* dl=(void*)x2l__((*p)[i]);
			dlclose(dl);
			if(dlerr__(&err_))
				return errinfo_close_;
		}
		return 0;
	}
	{
		call_ex___ ce;
		int err=call_func__(p,buf,&err_,syn_[keyword_null_],this,qu,&ce);
		if(err){
			switch(err){
			case jieshiqi_go_+keyword_end_:
			case jieshiqi_go_+keyword_exit_:
			case jieshiqi_go_+keyword_break_:
			case jieshiqi_go_+keyword_continue_:
				throw err-jieshiqi_go_;
			}
			switch(ce.kw__()) {
			case keyword_no_:
				break;
			default:
				throw new call_ex___(ce.kw__(), ce.s__());
			}
			return err;
		}
	}
	return 0;
}

int jieshiqi___::exec__(deque<string>* p,string& buf){
	string s;
	for(deque<string>::iterator li=p->begin();li!=p->end();++li) {
		if(li != p->begin())
			s += ' ';
		s+=*li;
	}
#ifdef WIFEXITED
	int ret;
    if ( (ret=system( s.c_str() )) == -1 )
    	buf+=l2s__(ret);
    else if(WIFEXITED(ret))
		buf+=l2s__(WEXITSTATUS(ret));
#else
    buf+=l2s__(system( s.c_str() ));
#endif
	return 0;
}
