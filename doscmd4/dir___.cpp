/*
 * dir___.cpp
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#include "dir___.h"
#include<dirent.h>
#include<sys/stat.h>
#include"doscmd.h"
#include "for_arg_.h"
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "l4/keyword.h"

//osx 10.9 need
#include <unistd.h>

#ifdef ver_mac_mini_
#define no_empty_sub_expression__(exp) (!exp[0] ? ".*" : exp)
#else
#define no_empty_sub_expression__(exp) exp
#endif

dir___::dir___() {
}

dir___::~dir___() {
}

void dir___::dir__(int*err1,char*buf,long siz,
		const char*dir,const char*tongpei,const char*opt1,
		const char* src,void*ce,void*qu,callback2_2___ cb)
{
	dir_opt___ opt;
	opt.a_file_=opt.a_lnk_=true;
	for(;*opt1;opt1++){
		switch(*opt1){
		case's':
			opt.subdir_=true;
			continue;
		/*
		T（头匹配）
		A（全匹配）
		 */
		case'T':
		case'A':
			opt.tongpei_=*opt1;
			continue;
		case'l':
			opt.icase_=!opt.icase_;
			continue;
		case'd':
			opt.dir_not_tongpei_=!opt.dir_not_tongpei_;
			continue;
		case'n':
			opt.dirlnk_is_dir_=!opt.dirlnk_is_dir_;
			continue;
		case'p':
			switch(*++opt1){
			case'b':
				opt.out_dir_enter_=!opt.out_dir_enter_;
				continue;
			case'e':
				opt.out_dir_exit_=!opt.out_dir_exit_;
				continue;
			}
			break;
		case'x':
			opt.not_=!opt.not_;
			continue;
		case'f':
			opt.flag_ = !opt.flag_;
			continue;
		case'o':
			opt.sort_=*++opt1-'0';
			if(!(opt.sort_>=0&&opt.sort_<=3))
				break;
			continue;
		case'a':
			switch(*++opt1){
			case'h':
				opt.a_hidden_=!opt.a_hidden_;
				continue;
			case'd':
				opt.a_dir_=!opt.a_dir_;
				continue;
			case'f':
				opt.a_file_=!opt.a_file_;
				continue;
			case'l':
				opt.a_lnk_=!opt.a_lnk_;
				continue;
			case'-':
				switch(*++opt1){
				case'h':
					opt.a_hidden_=false;
					continue;
				case'd':
					opt.a_dir_=false;
					continue;
				case'f':
					opt.a_file_=false;
					continue;
				case'l':
					opt.a_lnk_=false;
					continue;
				}
				break;
			}
		}
		buf[0]=*opt1;
		buf[1]=0;
		*err1='o';
		return;
	}

	regex_t reg;
	switch(opt.tongpei_){
	case 0:
	{
		int cflags=REG_EXTENDED|REG_NEWLINE|REG_NOSUB;
		if(opt.icase_)
			cflags|=REG_ICASE;
		int err=regcomp(&reg, no_empty_sub_expression__(tongpei), cflags);
		if(err){
		   regerror(err, &reg, buf, siz);
		   *err1='r';
		   return;
		}
		break;
	}
	}

	*err1=dir2__(dir,0,"",&reg,tongpei,&opt,src,ce,qu,cb);

	switch(opt.tongpei_){
	case 0:
		regfree(&reg);
		break;
	}

	sort__(opt.sort_);
}

int dir___::dir2__(const char*dir,int depth,string dir2,regex_t* reg,const char*tongpei,
		dir_opt___*opt,const char* src,void*ce,void*qu,callback2_2___ cb)
{
	DIR* d;
	if((d=opendir(dir && dir[0] ? dir : "."))==NULL)
		return 0;//'d'
	string oldir;
	{
		char cwd[260];
		oldir=getcwd(cwd,sizeof(cwd));
	}
	chdir(dir);
	if(dir2.length()>0)
		dir2+='/';
	struct dirent* entry;
	int exec_max = opt->subdir_ ? 2 : 1;
	int err = 0;
	if(opt->out_dir_enter_){
		exec__(reg,tongpei,opt,dir2,"",true,false,src,ce,qu,cb);
	}
	for(int exec = 0; exec < exec_max; exec++) {
		if(exec>0)
			rewinddir(d);
		while((entry=readdir(d)) != NULL) {
			const char* name=entry->d_name;
			//printf("\n%s %s",dir,name);
			struct stat64 statbuf64;
			struct stat statbuf;
			mode_t st_mode;
			if(lstat64(name, &statbuf64) == 0) {
				st_mode = statbuf64.st_mode;
			} else {
				if(lstat(name,&statbuf) == 0) {
					st_mode = statbuf.st_mode;
				} else {
					//printf("{%s/%s %s}\n",dir,name,strerror(errno));
					continue;
				}
			}
			if(name[0]=='.'){
				if(!name[1]||(name[1]=='.'&&!name[2]))
					continue;
				if(!opt->a_hidden_)
					continue;
			}
			bool is_dir=false, is_lnk = false;
			if(S_ISDIR(st_mode))
				is_dir=true;
			else if(S_ISLNK(st_mode)){
				is_lnk = true;
				if(opt->a_lnk_){
					DIR* d2;
					if((d2=opendir(name))){
						closedir(d2);
						is_dir=true;
					}
					if(!opt->dirlnk_is_dir_ && is_dir) {
						if(!opt->a_dir_)
							continue;
						is_dir = false;
					}
				}else
					continue;
			}
			switch(exec){
			case 0:
				if(is_dir){
					if(opt->a_dir_){
						if((err=exec__(reg,tongpei,opt,dir2,name,is_dir, is_lnk,src,ce,qu,cb))){
							break;
						}
					}
					continue;
				}
				if(opt->a_file_){
					if((err=exec__(reg,tongpei,opt,dir2,name,is_dir, is_lnk,src,ce,qu,cb))){
						break;
					}
				}
				continue;
			case 1://子目录时
				if(is_dir){
					dir2__(name,depth+1,dir2+name,reg,tongpei,opt,src,ce,qu,cb);
				}
				continue;
			}
			if(err){
				if(err==jieshiqi_err_go_+keyword_continue_){
					err = 0;
					continue;
				}
				if(err==jieshiqi_err_go_+keyword_break_)
					err = 0;
				break;
			}
		}
	}
	if(opt->out_dir_exit_){
		exec__(reg,tongpei,opt,dir2,"",true,false,src,ce,qu,cb);
	}
	closedir(d);
	chdir(oldir.c_str());
	return err;
}

int dir___::exec__(regex_t* reg,const char*tongpei,dir_opt___*opt,
		string dir2,const char* name,bool is_dir, bool is_lnk,
		const char* src,void*ce,void*qu,callback2_2___ cb)
{
	if(dir2.length()==0 && !name[0])
		return 0;
	bool b=false;
	string name1=name;
	if(opt->flag_ && is_dir && opt->a_file_ && name1.length()>0){
		name1+='/';
	}
	if(is_dir&&opt->dir_not_tongpei_){
		b=true;
	}else{
		switch(opt->tongpei_){
		case 0:
			b=(regexec(reg, name1.c_str(), 0, 0, 0)==0);
			break;
		case'T':
			{
				size_t i=name1.find(tongpei);
				b=(i==0);
			}
			break;
		case'A':
			b=(strcmp(name,tongpei)==0);
			break;
		}
		if(opt->not_)
			b=!b;
	}
	//printf(" %d(%s)",b,name1.c_str());
	if(b){
		int err=0;
		string path=dir2+name1, type;
		type += (is_dir ? 'd' : '-');
		if(is_lnk)
			type += 'l';
		cb((src ? jsq_ : this),qu,&err,ce,src,false,NULL,2,path.c_str(), type.c_str());
		if(err)
			return err;
	}
	return 0;
}

void dir___::sort__(int sort1){
	switch(sort1){
	case 3:
	{
		vector<string>* ls=&list_;
		size_t i1=0;
		for(;;){
			bool b=true;
			for( vector<string>::iterator i=ls->begin()+i1; i != ls->end(); ++i ) {
				string& s=*i;
				size_t i2;
				i2=s.find("index");
				if(i2==0){
				}else{
					/*i2=s.find("/index");
					if(i2!=string::npos)
						if(s.rfind("/")!=i2)*/
							i2=string::npos;
				}
				if(i2!=string::npos){
					string s1=s;
					ls->erase(i);
					ls->insert(ls->begin(),s1);
					b=false;
					i1++;
					break;
				}
			}
			if(b)
				break;
		}
		if(i1>0)
			sort(ls->begin(),ls->begin()+i1);
		sort(ls->begin()+i1,ls->end());
		break;
	}
	case 0:
		sort(list_.begin(),list_.end());
		break;
	case 1:
		sort(list_.rbegin(),list_.rend());
		break;
	}
	first__(sort1);
}

void dir___::first__(int sort1){
	switch(sort1){
	default:
		i2_ = i_=0;
		ii_=1;
		break;
	case 2:
		i2_ = i_=list_.size()-1;
		ii_=-1;
		break;
	}
}

dlle___ void dlln___(dir__)(int*err1,char*buf,long siz,char*dir,char*tongpei,char*ctrl,const char* src,void*ce,void*qu){
	dir___ d;
	d.dir__(err1,buf,siz,dir,tongpei,ctrl,src,ce,qu,cb_);
}

const char* cb__(void* jsq,void* shangji,int* err,void*ce,const char* src,bool src_is_file,const char* src2,int argc,...){
	dir___* d=(dir___*)jsq;
	string s2;
	_for_args( argc )
		if(i > 0)
			s2 += '\t';
		s2 += s;
	_next_args
	d->list_.push_back(s2);
	return NULL;
}

dlle___ dir___* dlln___(dir_begin__)(int*err1,char*buf,long siz,int argc,...){
	const char*dir=".";
	const char*tongpei="";
	const char*opt="";
	_for_args( argc )
		switch(i){
		case 0:
			dir=s;
			break;
		case 1:
			tongpei=s;
			break;
		case 2:
			opt=s;
			break;
		}
	_next_args
	dir___* d=new dir___();
	d->dir__(err1,buf,siz,dir,tongpei,opt,0,0,0,cb__);
	return d;
}

dlle___ void dlln___(dir_end__)(dir___*d){
	if(!d)
		return;
	d->list_.clear();
	delete d;
}

dlle___ void dlln___(dir_first__)(dir___*d,int sort1){
	if(!d)
		return;
	d->first__(sort1);
}

bool dir___::split__(char c, char*buf,long siz) {
	if(i_ < 0 || (size_t)i_ >= list_.size())
		return false;
	const string& s = list_.at(i_);
	size_t i = s.find('\t');
	size_t from, to;
	switch(c) {
	case 't':
		from = i + 1;
		to = s.length();
		break;
	default:
		from = 0;
		to = i;
	}
	i = from;
	for(int i2 = 0;;) {
		if(i >= to || i2 >= siz) {
			buf[i2] = 0;
			break;
		}
		buf[i2++] = s[i++];
	}
	return true;
}

dlle___ void dlln___(dir_filetype__)(char*buf,long siz,dir___*d){
	if(!d)
		return;
	d->split__('t', buf, siz);
}

dlle___ void dlln___(dir_next__)(char*buf,long siz,dir___*d){
	if(!d)
		return;
	d->i_ = d->i2_;
	if(d->split__(0, buf, siz))
		d->i2_ += d->ii_;
}

dlle___ void dlln___(dir_sort__)(dir___*d,int sort1){
	if(!d)
		return;
	d->sort__(sort1);
}

dlle___ int dlln___(dir_count__)(dir___*d){
	if(!d)
		return -1;
	return d->list_.size();
}

dlle___ vector<string>* dlln___(dir_list__)(dir___*d){
	if(!d)
		return NULL;
	return &(d->list_);
}
