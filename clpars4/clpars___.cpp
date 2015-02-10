/*
 * clpars___.cpp
 *
 *  Created on: 2011-7-10
 *      Author: zzzzzzzzzzz
 */

#include "clpars___.h"
#include <algorithm>
#include <stdio.h>
#include "../new_gg/def1.h"
#include "../new_gg/l4/keyword.h"
#include "../new_gg/call_util.cpp"

void* jsq_;
callback3_2___ cb2_;
dlle___ void init__(void* jsq,callback3_2___ cb2){
	jsq_=jsq;
	cb2_=cb2;
}

clpars___::clpars___() {
}

clpars___::~clpars___() {
}

void clpars___::set__(char*buf,int*err,bool add,int argc,va_list& argv,int* sp){
	if(!add)
		item_.clear();

	const char*flag;
	const char*info;
	const char*code;
	const char*s;
	int argc1;
    for (int i = 0; i < argc; ){
        flag = va_arg(argv, const char*); i++;
        if(i <= argc){
			if(sp){
				if(flag[0]=='-'&&flag[1]=='-'&&flag[2]=='-'&&flag[3]=='-'&&!flag[4]){
					*sp=i;
					break;
				}
			}
        }
        info = va_arg(argv, const char*); i++;
        s = va_arg(argv, const char*); i++;
        code = va_arg(argv, const char*); i++;
        if(i>argc){
        	sprintf(buf,"no arg");
        	*err=1;
        	return;
        }
        if(!flag||!code||!s){
        	sprintf(buf,"is null");
        	*err=10;
        	return;
        }
        char type=' ';
        switch(s[0]) {
        case 'a':
        case 'b':
        case 'e':
        case 'c':
        case 'h':
			type=s[0];
        	if(!s[1]) {
				argc1=0;
				break;
        	}
        	s++;
        default:
            if(sscanf(s,"%d",&argc1)!=1){
            	sprintf(buf,"no int");
            	*err=2;
            	return;
            }
            switch(argc1){
            case -1:
            	type='b';
            	break;
            case -2:
            	type='e';
            	break;
            case -3:
            	type='c';
            	break;
            }
        }
		clpars_item___* item=new clpars_item___(flag,info,code,argc1,type);
		item_.push_back(item);
    }
}

class comp___ {
private:
	char type_;
	const char*s_;
	const char**src2_;
	string*arg1_;
public:
	comp___(const char*s, char type,const char**src2,string*arg1) {
		s_ = s;
		type_ = type;
		src2_=src2;
		arg1_=arg1;
	}
    bool operator () (string& s2) {
        return bool__(s2, s_, type_, src2_,arg1_);
    }
    bool bool__(const string&s2,const string&s,char type,const char**src2,string*arg1) {
    	bool b=false;
		switch(type){
		case 'b':case 'e':case 'c':
			{
				size_t i;
				switch(type){
				case 'e':
					i=s.rfind(s2);
					break;
				default:
					i=s.find(s2);
					break;
				}
				switch(type){
				case 'b':
					b=(i == 0);
					break;
				case 'e':
					b=(i == s.size()-s2.size());
					break;
				case 'c':
					b=(i != string::npos);
					break;
				}
				if(b){
					*src2 = s2.c_str();
					switch(type){
					case 'b':
						*arg1 = s.substr(s2.size());
						break;
					case 'e':
						*arg1 = s.substr(0, s.size()-s2.size());
						break;
					case 'c':
						*arg1 = s;
						break;
					}
				}
				break;
			}
		default:
			b=(s2==s);
			break;
		}
		return b;
    }
};

int clpars___::cb__(const char*flag,bool by_help,bool no,int& i1,int&i,
		char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv)
{
	const char**argv2 = new const char*[argc];
	char no1[16];
	int has=0;
	const char* src2 = flag;
	string arg1;
	for(int scan = 0; scan < 2 && !has; scan++) {
		int start=0,i2=0;
		int i2_old = i2;
		for(list<clpars_item___*>::iterator cii=item_.begin();cii!=item_.end();cii++){
			clpars_item___* ci=*cii;
			if(ci->pause_)
				continue;
			bool b=false;
			switch(scan) {
			case 0:
				if(by_help){
					b=(ci->type_ == 'h');
				} else {
					if(!b){
						bool b2 = true;
						switch(ci->type_) {
						case 'b': case 'e': case 'c':
							if(has > 0)
								b2 = false;
							break;
						}
						if(b2) {
							list<string>::iterator si = find_if(
									ci->flags_.begin(), ci->flags_.end(),
									comp___(flag,ci->type_,&src2,&arg1) );
							b=(si != ci->flags_.end());
						}
					}
				}
				break;
			case 1:
				if(by_help){
				} else {
					if(ci->flag_.empty())
						b = true;
				}
				break;
			}
			if(b){
				has++;
				const char*code;
				if(ci->code_.empty())
					code=ci->info_.c_str();
				else
					code=ci->code_.c_str();
				switch(scan) {
				case 0:
					if(by_help){
					} else {
						if(has==1){
							switch(ci->type_){
							case 'b':case 'e':case 'c':
								argv2[i2++] = arg1.c_str();
								start++;
								break;
							}
						}
					}
					break;
				case 1:
					if(no) {
						sprintf(no1,"%d",++i1);
						argv2[i2++]=no1;
						start++;
					}
					argv2[i2++]=flag;
					if(ci->type_ == 'a')
						start++;
					break;
				}
				if(has==1){
					if(ci->argc_ > 0 || ci->type_ == 'a'){
						int argc2 = start + (ci->type_ == 'a' ?
								argc - i : ci->argc_);
						for(;i2<argc2;i2++,i++){
							argv2[i2] = va_arg(argv, char*);
						}
						if(i>argc){
							sprintf(buf,"'%s'(%c%d) no arg",flag,ci->type_,ci->argc_);
							*err=1;
							break;
						}
					}
					i2_old = i2;
				}else{
					i2 = i2_old;
				}
				cb2_(jsq_,shangji,err,ce,code,false,src2,i2,argv2,0);
				switch(*err){
				case jieshiqi_err_go_+keyword_continue_:
					*err=0;
					break;
				}
				if(*err)
					break;
			}
		}
	}
    delete argv2;
	return has;
}

int clpars___::par__(int& i1,int& i,const char* flag,bool by_help,
		char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,bool no)
{
    if(!flag){
    	sprintf(buf,"is null");
    	*err=10;
    	return 1;
    }
    i++;

    int has=cb__(flag,by_help,no,i1,i,buf,err,ce,shangji,argc,argv);
	if(*err)
		return 1;
    if(has)
    	return 0;

    if(by_help)
    	return 0;

	sprintf(buf,"no parse");
	*err=3;
	return 1;
}

void clpars___::par__(char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,int from,bool no){
	int i1=0,i = from;
	if(argc == 0)
		par__(i1,i,"",true,buf,err,ce,shangji,argc,argv,no);
	else {
		for (; i < argc; ){
			switch(par__(i1,i,va_arg(argv, char*),false,buf,err,ce,shangji,argc,argv,no)){
			case 1:
				return;
			}
		}
	}
}

void clpars___::info__(char**&addr_ret,const char* t1,const char* t2,const char* n,bool yange){
	string info;
	list<clpars_item___*>::iterator cii;
	clpars_item___* ci;
	for(cii=item_.begin();cii!=item_.end();cii++){
		ci=*cii;
		info+=t1;
		info+=ci->flag_;
		if(yange||!ci->flag_.empty())
			info+=t2;
		info+=ci->info_;
		info+=n;
    }
	*addr_ret=dup__(info.c_str());
}

void clpars___::info__(char*buf,int* err,void*ce,void* shangji,char* code){
	list<clpars_item___*>::iterator cii;
	clpars_item___* ci;
	const char*argv2[32];
	int argc2;
	for(cii=item_.begin();cii!=item_.end();cii++){
		ci=*cii;
		argc2=0;
		argv2[argc2++]=ci->info_.c_str();
		argv2[argc2++]=ci->flag_.c_str();
		for(list<string>::iterator si=ci->flags_.begin();si!=ci->flags_.end();si++){
			argv2[argc2++]=(*si).c_str();
		}
		cb2_(jsq_,shangji,err,ce,code,false,NULL,argc2,argv2,0);
		if(*err)
			break;
    }
}

void clpars___::pause__(bool pause, int argc, char** argv) {
	for(list<clpars_item___*>::iterator cii=item_.begin();cii!=item_.end();cii++){
		clpars_item___* ci=*cii;
		if(ci->flag_.empty())
			continue;
		if(argc <= 0)
			ci->pause_ = pause;
		else {
			for(int i = 0; i < argc; i++) {
				for(list<string>::iterator si=ci->flags_.begin();si!=ci->flags_.end();si++){
					if((*si) == argv[i]) {
						ci->pause_ = pause;
						break;
					}
				}
			}
		}
    }

}
