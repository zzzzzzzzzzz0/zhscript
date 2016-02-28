/*
 * l4___.cpp
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#include "l4___.hh"
#include <sys/stat.h>
#ifndef S_ISLNK
extern "C"{
#endif
#include<dlfcn.h>
#ifndef S_ISLNK
}
#endif
#include <unistd.h>
#include<stdlib.h>
#include "args_util.hh"

l4___::l4___() {
	dl_=NULL;
	l4_=NULL;
}

l4___::~l4___() {
#ifndef ver_loongson_
	uninit__();
#endif
}

int l4___::uninit__(){
	int err;
	if(l4_){
		l4_delete__(l4_);
		l4_=NULL;
	}
	if((err=unload__()))
		return err;
	return 0;
}

int l4___::init__(const char* path,int argc,char** argv,int from){
	string ex;
	get_ex__(argc,argv,from,ex);
	int err;
	if((err=init1__(path,ex.c_str())))
		return err;
	l4_add_arg3__(l4_,argc,argv,from);
	if((err=init3__()))
		return err;
	return 0;
}

int l4___::init__(const char* path,const char* cmdline){
	string s=cmdline;
	string ex;
	get_ex__(s,ex,true);
	int err;
	if((err=init1__(path,ex.c_str())))
		return err;
	l4_add_arg__(l4_,s.c_str());
	if((err=init3__()))
		return err;
	return 0;
}

int l4___::init__(const char* path,const char* cmdline,int argc,char** argv,int from){
	string s=cmdline;
	string ex;
	get_ex__(s,ex,true);
	get_ex__(argc,argv,from,ex);
	int err;
	if((err=init1__(path,ex.c_str())))
		return err;
	l4_add_arg__(l4_,s.c_str());
	l4_add_arg3__(l4_,argc,argv,from);
	if((err=init3__()))
		return err;
	return 0;
}

int l4___::init1__(const char* path,const char* ex){
	int err;
	if((err=load__(path,ex)))
		return err;
	if((err=get_funcs__()))
		return err;
	l4_=l4_new__();
	l4_set_path__(l4_,path_.c_str());
	return 0;
}

void l4___::get_ex__(int argc,char** argv,int from,string& ex){
	for(int i=from;i<argc;i++){
		string s=argv[i];
		int i2=get_ex__(s,ex,false);
		if(i2>0){
			jieshiqi_args_del__(argv[i]);
		}
	}
}

int l4___::get_ex__(string& s,string& ex,bool chuli){
	static string _ex="--ex";
	static size_t iex=_ex.size();
	size_t i=s.find(_ex);
	if(i!=string::npos){
		size_t i2=i+iex;
		size_t i3=s.find(' ',i2);
		if(i3==string::npos)
			i3=s.size();
		size_t i1;
		i1=s.find("--",i2/*,i3-i2*/);
		if(i1!=string::npos&&i1<i3){
			ex=s.substr(i+iex,i1-i2);
			if(chuli){
				jieshiqi_args_del_line__(s, i);
			}
			return 1;
		}
	}
	return 0;
}

int l4___::init3__(){
	int err;
	if((err=l4_parse_args__(l4_)))
		return err;
	return 0;
}

#ifndef S_ISLNK
#define lstat stat
#endif
bool lstat__(const char* path, const char* ext) {
	string file = path;
	if(ext)
		file += ext;
	struct stat info;
	return (lstat(file.c_str(), &info) == 0);
}

bool which__(const char* s,string& buf2){
	bool b=true;
	for(int i=0;s[i];i++){
		if(s[i]=='/'){
			b=false;
			break;
		}
	}
	if(b){
		char*PATH=getenv("PATH");
		if(PATH){
			for(int i=0;;){
				char c=PATH[i++];
				if(c==':'||!c){
					if(buf2.size()>0){
						c=buf2[buf2.size()-1];
						if(c=='/'||c=='\\'){
						}else
							buf2+='/';
						buf2+=s;
						if (lstat__(buf2.c_str(), NULL))
							return true;
						buf2.clear();
					}
				}else
					buf2+=c;
				if(!c)
					break;
			}
		}
	}
	return false;
}

void get_path__(string& path){
	unsigned int i=path.rfind('/');
	if(i==string::npos)
		i=path.rfind('\\');
	if(i==string::npos)
		path.clear();
	else
		path=path.substr(0,i+1);
}

bool abs_path__(const char* s, char* buf, int siz, string& buf2) {
	//s = realpath(s, buf);
	if(s[0]!='/'){
		string s2=s;
		buf2=getcwd(buf,siz);
		buf2+='/';
		buf2+=s2;
		return true;
	}
	return false;
}

bool get_lnk__(const char* s,string& buf2,bool abs, get_lnk_ok___ ok){
#ifdef S_ISLNK
	char buf[1024];
	struct stat info;
	int lnk=0;
	for(int loop=0;loop<1000;loop++){
		if(lstat(s, &info)!=0)
			break;
		if (S_ISLNK(info.st_mode)) {
			lnk++;
			string buf1=s;
			ssize_t len;
			if ((len = readlink(s, buf, sizeof(buf)-1)) >= 0){
				buf[len] = '\0';
				if(buf[0]=='/'){
					buf2=buf;
				}else{
					buf2=buf1;
					get_path__(buf2);
					buf2+=buf;
				}
				if(ok) {
					if(abs) {
						string buf3;
						if(abs_path__(s, buf, sizeof(buf), buf3)) {
							if(ok(buf3.c_str())) {
								buf2 = buf3;
								return true;
							}
						}
					}
					if(ok(buf2.c_str()))
						return true;
				}
				s=buf2.c_str();
			}
		} else
			break;
	}
	if(abs) {
		if(abs_path__(s, buf, sizeof(buf), buf2)) {
			if(ok && ok(buf2.c_str()))
				return true;
		}
	}
	return lnk>0;
#else
	return false;
#endif
}

string realpath__(const char* s){
	string buf2;
	if(which__(s,buf2))
		s=buf2.c_str();
	if(get_lnk__(s,buf2,true, NULL))
		s=buf2.c_str();
	return s;
}

int l4___::load__(const char* s,const char* ex){
	string path=realpath__(s);
	get_path__(path);

	path_=path+"l4"+ex;
#ifdef S_ISLNK
	path_+=".so";
#else
	path_+=".dll";
#endif

	dl_=dlopen(path_.c_str(),RTLD_LAZY);
	if(dlerr__())
		return errinfo_open_;
	return 0;
}

int l4___::unload__(){
	if(!dl_)
		return 0;

	dlclose(dl_);
	if(dlerr__())
		return errinfo_close_;
	dl_=0;
	return 0;
}

void* l4___::get_func__(const char* s){
	void*v=dlsym(dl_, s);
	if(dlerr__())
		return 0;
	return v;
}

bool l4___::dlerr__(){
	const char*dlerr=dlerror();
	if(dlerr){
		err_<<dlerr;
		return true;
	}
	return false;
}

#define get_func2__(n,p)	\
	if(!(n=(p)get_func__(#n)))	\
		return errinfo_get_;
int l4___::get_funcs__(){
	get_func2__(l4_new__,void*(*)());
	get_func2__(l4_delete__,void (*)(void* l4));
	get_func2__(l4_set_path__,void (*)(void* l4,const char* s));
	get_func2__(l4_add_path__,void (*)(const char* s));
	get_func2__(l4_del_path__,void (*)(const char* s));
	get_func2__(l4_add_arg3__,void (*)(void* l4,int argc,char** argv,int from));
	get_func2__(l4_add_arg__,void (*)(void* l4,const char* cmdline));
	get_func2__(l4_parse_args__,int (*)(void* l4));
	get_func2__(l4_jieshi__,int (*)(void* l4,void* shangji));
	get_func2__(l4_jieshi2__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,void* shangji));
	/*get_func2__(l4_callback__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,void*shangji,int argc,...));
	get_func2__(l4_callback3__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,void* shangji,int argc,const char**argv,int from));
	get_func2__(l4_callback_1__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,const char* src2,void*shangji,int argc,...));
	get_func2__(l4_callback3_1__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,const char**argv,int from));*/
	get_func2__(l4_callback_2__,const char* (*)(void* l4,int* err,void*ce,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,...));
	get_func2__(l4_callback3_2__,const char* (*)(void* l4,int* err,void*ce,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,const char**argv,int from));
	get_func2__(l4_err__,const char* (*)(void* l4));
	get_func2__(l4_errinfo__,const char* (*)(void* l4,int err));
	get_func2__(l4_err_clear__,void (*)(void* l4));
	get_func2__(l4_err_out__,void (*)(void* l4, const char* ret, int err, int by));
	get_func2__(l4_go__,void (*)(void* l4, int kw));
	get_func2__(l4_var_new__,int (*)(void* l4,void* qu,const char* name,const char* val,bool readonly,int type,bool is_noparam));
	get_func2__(l4_keyword__,const char* (*)(void* l4,int kw));
	get_func2__(l4_new_main_qu__,void* (*)(void* l4));
	get_func2__(l4_new_qu__,void* (*)(void* shangji));
	get_func2__(l4_delete_qu__,void (*)(void* qu));
	get_func2__(l4_exit_code__,int (*)(void* l4));
	return 0;
}
