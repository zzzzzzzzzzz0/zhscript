/*
 * shell_plugin___.cpp
 *
 *  Created on: 2010-9-11
 *      Author: zzzzzzzzzzz
 */
#include"plugin_base___.h"
#include"util.h"
#include   <dirent.h>
#ifdef ver_exe_
extern "C"{
#endif
#include<dlfcn.h>
#ifdef ver_exe_
}
#endif
#include <stdarg.h>
#include"plugin_def.h"

class plugin___{
public:
	void* dl_;
	Glib::ustring path_;
	plugin_base___* plugin_;
	destroy___* destroy_;
};

const char* direct__(shell___* sh,int cmd,...){
	const char* ret=0;
	va_list argv;
	va_start(argv, cmd);
	switch(cmd){
	case call4_:
	case call4_1_:
	{
		const char*code=va_arg(argv,const char*);
		void*shangji=va_arg(argv,void*);
		const char*zhao=va_arg(argv,const char*);
		const char*dong=va_arg(argv,const char*);
		const char* src2=va_arg(argv,const char*);
		int argc=va_arg(argv,int);
		const char** argv1=va_arg(argv,const char**);
		int from=va_arg(argv,int);
		if(cmd==call4_)
			ret=sh->call4__(code,shangji,zhao,dong,src2,argc,argv1,from);
		else{
			void*ce=va_arg(argv,void*);
			int* err=va_arg(argv,int*);
			ret=sh->call4_1__(err,ce,code,shangji,zhao,dong,src2,argc,argv1,from);
		}
		break;
	}
	case on_:
		{
			const char*code=va_arg(argv,const char*);
			void*shangji=va_arg(argv,void*);
			int i=va_arg(argv,int);
			const char*zhao=va_arg(argv,const char*);
			const char*dong=va_arg(argv,const char*);
			const char*s;
			const char*s2;
			const char*s3;
			const char*s4;
			switch(i){
			case 2:
				ret=sh->on__(code,shangji,i,zhao,dong);
				break;
			case 3:
				s=va_arg(argv,const char*);
				ret=sh->on__(code,shangji,i,zhao,dong,s);
				break;
			case 4:
				s=va_arg(argv,const char*);
				s2=va_arg(argv,const char*);
				ret=sh->on__(code,shangji,i,zhao,dong,s,s2);
				break;
			case 5:
				s=va_arg(argv,const char*);
				s2=va_arg(argv,const char*);
				s3=va_arg(argv,const char*);
				ret=sh->on__(code,shangji,i,zhao,dong,s,s2,s3);
				break;
			case 6:
				s=va_arg(argv,const char*);
				s2=va_arg(argv,const char*);
				s3=va_arg(argv,const char*);
				s4=va_arg(argv,const char*);
				ret=sh->on__(code,shangji,i,zhao,dong,s,s2,s3,s4);
				break;
			}
		}
		break;
	case bool_:
		ret=(char*)sh->bool__(va_arg(argv,const char*));
		break;
	case main_win_is_visible_:
		ret=(const char*)sh->main_win_is_visible__();
	case main_win_hide_:
		sh->main_win_hide__();
		break;
	case main_win_show_:
		sh->main_win_show__();
		break;
	case err_show_buzhichi_:
		{
			int argc=va_arg(argv,int);
			std::deque<Glib::ustring>* p=va_arg(argv,std::deque<Glib::ustring>*);
			int i;
			switch(argc){
			case 1:
				sh->err_show_buzhichi__(p);
				break;
			case 2:
				i=va_arg(argv,int);
				sh->err_show_buzhichi__(p,i);
				break;
			}
		}
		break;
	case err_show_buzu_:
		sh->err_show_buzu__(va_arg(argv,std::deque<Glib::ustring>*));
		break;
	case err_show_fei_:
		sh->err_show_fei__(va_arg(argv,std::deque<Glib::ustring>*));
		break;
	case err_show_wufa_:
		{
			int argc=va_arg(argv,int);
			std::deque<Glib::ustring>* p=va_arg(argv,std::deque<Glib::ustring>*);
			int i,i2;
			switch(argc){
			case 1:
				sh->err_show_wufa__(p);
				break;
			case 2:
				i=va_arg(argv,int);
				sh->err_show_wufa__(p,i);
				break;
			case 3:
				i=va_arg(argv,int);
				i2=va_arg(argv,int);
				sh->err_show_wufa__(p,i,i2);
				break;
			}
		}
		break;
	case err_show_:
		{
			int argc=va_arg(argv,int);
			const char* s1=va_arg(argv,const char*);
			const char* s2;
			const char* s3;
			switch(argc){
			case 1:
				sh->err_show__(s1);
				break;
			case 2:
				s2=va_arg(argv,const char*);
				sh->err_show__(s1,s2);
				break;
			case 3:
				s2=va_arg(argv,const char*);
				s3=va_arg(argv,const char*);
				sh->err_show__(s1,s2,s3);
				break;
			}
		}
		break;
	case call4_2_:
		sh->call4_2__(va_arg(argv,int));
		break;
	case l4_err_show_:
		sh->l4_err_show__(va_arg(argv,int));
		break;
	}
	va_end(argv);
	return ret;
}

void shell___::pluginit__(){
	Glib::ustring dir=realpath__(prgname_);
	{
		size_t i1=dir.rfind('/');
		if(i1==string::npos)
			i1=dir.rfind('\\');
		if(i1!=string::npos){
			dir=dir.substr(0,i1+1);
			dir+="gtkmmsh";
		}
	}
	dir+="-plugin/";
	//std::cout<<dir<<std::endl;
	DIR *d;
	struct   dirent   *de;
	if((d=opendir(dir.c_str()))==NULL)
		return;
	while((de = readdir(d))!=NULL){
		char*name=de->d_name;
		if(name[0]=='.')
			continue;
		Glib::ustring file=dir;
		file+=name;

		void*dl=dlopen(file.c_str(),RTLD_LAZY);
		const char*dlerr;
		dlerr=dlerror();
		if(dlerr){
			err_show__(dlerr);
			continue;
		}
		create___* create = (create___*) dlsym(dl, "create__");
		dlerr=dlerror();
		if(dlerr){
			err_show__(dlerr);
			continue;
		}
		destroy___* destroy = (destroy___*) dlsym(dl, "destroy__");
		dlerr=dlerror();
		if(dlerr){
			err_show__(dlerr);
			continue;
		}

		plugin___* p=new plugin___();
		p->dl_=dl;
		p->path_=file;

		p->plugin_=create(this,direct__);
		p->destroy_=destroy;

		plugins_.push_back(p);
	}
	closedir(d);
}

void shell___::plugin_uninit__(){
	for(size_t i=0;i<plugins_.size();i++){
		plugin___* p=(plugin___*)plugins_[i];
		p->destroy_(p->plugin_);
		dlclose(p->dl_);
	}
}

bool shell___::plugin_proc__(std::deque<Glib::ustring>* p1,char*buf,long siz,char**addr_ret,void*shangji,void*ce){
	const Glib::ustring& p1_0=(*p1)[0];
	if(p1_0=="插件信息"){
		if(p1->size()<=1){
			err_show_buzu__(p1);
			return true;
		}
		char ver[16];
		Glib::ustring ret;
		int err;
		for(size_t i=0;i<plugins_.size();i++){
			plugin___* p=(plugin___*)plugins_[i];
			const char*ret0=l4_.l4_callback_2__(l4_.l4__(),&err,ce,
					(*p1)[1].c_str(),false,p1_0.c_str(),shangji,
					3,
					p->plugin_->name__(),
					l2s__(p->plugin_->version__(),ver),
					p->path_.c_str());
			if(err)
				throw err;
			ret+=ret0;
		}
		if(!ret.empty())
			cpy__(buf,ret.c_str(),siz);
		return true;
	}
	if(p1_0=="谁的"){
		if(p1->size()>1){
			std::deque<Glib::ustring> p2;
			for(size_t i=1;i<p1->size();i++){
				p2.push_back((*p1)[i]);
			}
			for(size_t i=0;i<plugins_.size();i++){
				plugin___* p=(plugin___*)plugins_[i];
				switch(p->plugin_->proc__(&p2,buf,-1,addr_ret,shangji,ce)){
				case 1:
					cpy__(buf,p->path_.c_str(),siz);
					return true;
				}
			}
		}
		return true;
	}
	bool proc=false;
	for(size_t i=0;i<plugins_.size();i++){
		plugin___* p=(plugin___*)plugins_[i];
		switch(p->plugin_->proc__(p1,buf,siz,addr_ret,shangji,ce)){
		case 1:
			return true;
		case 2:
			proc=true;
			break;
		}
	}
	return proc;
}

void shell___::plugin_on__(int event){
	for(size_t i=0;i<plugins_.size();i++){
		plugin___* p=(plugin___*)plugins_[i];
		p->plugin_->on__(event);
	}
}
