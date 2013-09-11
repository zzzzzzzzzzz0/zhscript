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

#define argc_max_ 16

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
        if(sscanf(s,"%d",&argc1)!=1){
        	sprintf(buf,"no int");
        	*err=2;
        	return;
        }
        if(argc1 < -3 || argc1 >= argc_max_){
        	sprintf(buf,"< %d or >= %d", -3, argc_max_);
        	*err=2;
        	return;
        }
		clpars_item___* item=new clpars_item___(flag,info,code,argc1);
		item_.push_back(item);
    }
}

class comp___ {
private:
	int type_;
	const char*s_;
	const char**src2_;
	string*arg1_;
public:
	comp___(const char*s, int type,const char**src2,string*arg1) {
		s_ = s;
		type_ = type;
		src2_=src2;
		arg1_=arg1;
	}
    bool operator () (string& s2) {
        return bool__(s2, s_, type_, src2_,arg1_);
    }
    static bool bool__(const string&s2,const string&s,int type,const char**src2,string*arg1) {
    	bool b=false;
		switch(type){
		case -1:case -2:case -3:
			{
				size_t i;
				switch(type){
				case -2:
					i=s.rfind(s2);
					break;
				default:
					i=s.find(s2);
					break;
				}
				switch(type){
				case -1:
					b=(i == 0);
					break;
				case -2:
					b=(i == s.size()-s2.size());
					break;
				case -3:
					b=(i != string::npos);
					break;
				}
				if(b){
					*src2 = s2.c_str();
					switch(type){
					case -1:
						*arg1 = s.substr(s2.size());
						break;
					case -2:
						*arg1 = s.substr(0, s.size()-s2.size());
						break;
					case -3:
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

int clpars___::cb__(char*buf,int* err,void*ce,void* shangji,const char*flag,const char*flag2,int i1,
		int argc,va_list& argv,int&i){
	const char*argv2[argc_max_];
	int start;
	char no1[16];
	int i2=0;
	if(i1>0){
		sprintf(no1,"%d",i1);
		argv2[i2++]=no1;
		start=1;
	}else
		start=0;
	if(!flag2[0]){
		argv2[i2++]=flag;
	}
	int has=0;
	const char* src2 = flag2;
	string arg1;
	int i2_old = i2;
    for(list<clpars_item___*>::iterator cii=item_.begin();cii!=item_.end();cii++){
    	clpars_item___* ci=*cii;
    	bool b=false;
		switch(ci->argc_){
		case -1:case -2:case -3:
			if(!flag2[0])
				b=true;
			break;
		}
		if(b)
			continue;
    	if(!b && ci->flags_.size() <= 1){
    		b = comp___::bool__(ci->flag_,flag2,ci->argc_,&src2,&arg1);
    	}
    	if(!b){
    		list<string>::iterator si = find_if(ci->flags_.begin(), ci->flags_.end(),
    				comp___(flag2,ci->argc_,&src2,&arg1) );
    		b=(si != ci->flags_.end());
    	}
    	if(b){
    		has++;
    		const char*code;
    		if(ci->code_.empty())
    			code=ci->info_.c_str();
    		else
    			code=ci->code_.c_str();
    		if(has==1){
    			if(ci->argc_ >= 0){
					int argc2 = ci->argc_ + start;
					for(;i2<argc2;i2++,i++){
						argv2[i2] = va_arg(argv, char*);
					}
					if(i>argc){
						sprintf(buf,"'%s' no arg",flag2);
						*err=1;
						break;
					}
    			}else{
    				i2_old = i2;
    			}
    		}
    		if(ci->argc_ < 0){
    			i2 = i2_old;
				switch(ci->argc_){
				case -1:case -2:
					argv2[i2++] = arg1.c_str();
				case -3:
					argv2[i2++] = flag;
					break;
				}
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
	return has;
}

void clpars___::par__(char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,int from,bool no){
	char*flag;
	int i1=0;
    for (int i = from; i < argc; ){
        flag = va_arg(argv, char*);
        if(!flag){
        	sprintf(buf,"is null");
        	*err=10;
        	return;
        }
        i++;

        int has=cb__(buf,err,ce,shangji,flag,flag,0,argc,argv,i);
		if(*err)
			return;
        if(has)
        	continue;

		if(no){
			++i1;
		}
		has=cb__(buf,err,ce,shangji,flag,"",i1,argc,argv,i);
		if(*err)
			return;
        if(has)
        	continue;

    	sprintf(buf,"no parse");
    	*err=3;
    	return;
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

dlle___ clpars___* set__(int*err,char*buf,bool need_new,bool add,int argc,...){
	clpars___* clp;
	if(need_new)
		clp=new clpars___();
	else
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
