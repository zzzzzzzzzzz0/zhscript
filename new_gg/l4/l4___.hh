/*
 * l4___.h
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#ifndef Loader____H_
#define Loader____H_

#include <string>
#include <iostream>
using namespace std;

#include"err___.hh"
#include"errinfo.h"
#include"keyword.h"
#include"vartype.h"

class l4___ {
private:
	void* dl_;
	void* get_func__(const char* s);
	bool dlerr__();

	int init1__(const char* path,const char* ex);
	void get_ex__(int argc,char** argv,int from,string& ex);
	int get_ex__(string& s,string& ex,bool chuli);
	int init3__();

	int load__(const char* s,const char* ex);
	int unload__();
	string path_;

	void* l4_;
	void* (*l4_new__)();
	void (*l4_delete__)(void* l4);
	void (*l4_set_path__)(void* l4,const char* s);
	void (*l4_add_path__)(const char* s);
	void (*l4_del_path__)(const char* s);
	void (*l4_add_arg3__)(void* l4,int argc,char** argv,int from);
	void (*l4_add_arg__)(void* l4,const char* cmdline);
	int (*l4_parse_args__)(void* l4);
	int (*l4_jieshi__)(void* l4,void* shangji);
	const char* (*l4_jieshi2__)(void* l4,int* err,const char* src,bool src_is_file,void* shangji);
	/*const char* (*l4_callback__)(void* l4,int* err,const char* src,bool src_is_file,void* shangji,int argc,...);
	const char* (*l4_callback3__)(void* l4,int* err,const char* src,bool src_is_file,void* shangji,int argc,const char**argv,int from);
	const char* (*l4_callback_1__)(void* l4,int* err,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,...);
	const char* (*l4_callback3_1__)(void* l4,int* err,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,const char**argv,int from);*/
	const char* (*l4_callback3_2__)(void* l4,int* err,void*ce,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,const char**argv,int from);
	const char* (*l4_err__)(void* l4);
	const char* (*l4_errinfo__)(void* l4,int err);
	void (*l4_err_clear__)(void* l4);
	void (*l4_err_out__)(void* l4, const char* ret, int err, int by);
	void (*l4_go__)(void* l4, int kw);
	int (*l4_var_new__)(void* l4,void* qu,const char* name,const char* val,bool readonly,int type,bool is_noparam);
	const char* (*l4_keyword__)(void* l4,int kw);
	void* (*l4_new_main_qu__)(void* l4);
	void* (*l4_new_qu__)(void* shangji);
	void (*l4_delete_qu__)(void* qu);
	int (*l4_exit_code__)(void* l4);
	bool (*l4_is_end__)(void* l4);
	int get_funcs__();

public:
	l4___();
	virtual ~l4___();

	int init__(const char* path,int argc,char** argv,int from);
	int init__(const char* path,const char* cmdline);
	int init__(const char* path,const char* cmdline,int argc,char** argv,int from);
	int uninit__();
	int jieshi__(void* shangji=NULL){return l4_jieshi__(l4_,shangji);}
	const char* jieshi2__(int* err,const char* src=NULL,bool src_is_file=false,void* shangji=NULL){
		return l4_jieshi2__(l4_,err,src,src_is_file,shangji);
	}
	const char* (*l4_callback_2__)(void* l4,int* err,void*ce,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,...);
	const char* callback3__(int* err,void*ce,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,const char**argv,int from) {
		return 	l4_callback3_2__(l4_,err,ce,src,src_is_file,src2,shangji,argc,argv,from);
	}
	const char* err__(){
		if(!dl_)
			return "";
		return l4_err__(l4_);
	}
	const char* errinfo__(int err){
		if(!dl_)
			return "";
		return l4_errinfo__(l4_,err);
	}
	void err_clear__(){
		if(!dl_)
			return;
		l4_err_clear__(l4_);
	}
	void err_out__(const char*ret, int err, int by);
	void* l4__(){return l4_;}
	int var_new__(const char* name,const char* val,bool readonly=false,void* qu=NULL){
		return l4_var_new__(l4_,qu,name,val,readonly,vartype_var_,false);
	}
	int def_new__(const char* name,const char* val,bool readonly=false,bool is_noparam=false,void* qu=NULL){
		return l4_var_new__(l4_,qu,name,val,readonly,vartype_def_,is_noparam);
	}
	int alias_new__(const char* name,const char* val,bool readonly=false,void* qu=NULL){
		return l4_var_new__(l4_,qu,name,val,readonly,vartype_alias_,false);
	}
	const char* keyword__(int kw){return l4_keyword__(l4_,kw);}
	void add_path__(const char*s){l4_add_path__(s);}
	void del_path__(const char*s){if(l4_)l4_del_path__(s);}
	void* new_main_qu__(){return l4_new_main_qu__(l4_);}
	void* new_qu__(void* shangji){return l4_new_qu__(shangji);}
	void delete_qu__(void* qu){l4_delete_qu__(qu);}
	int exit_code__(){return l4_exit_code__(l4_);}
	bool is_end__(){
		if(!dl_)
			return false;
		return l4_is_end__(l4_);
	}

	err___ err_;
};

typedef bool (*get_lnk_ok___)(const char* path);

extern string realpath__(const char* s);
extern void get_path__(string& path);
extern bool which__(const char* s,string& buf2);
extern bool get_lnk__(const char* s,string& buf2,bool abs, get_lnk_ok___ ok);
extern bool lstat__(const char* path, const char* ext);

#endif /* Loader____H_ */
