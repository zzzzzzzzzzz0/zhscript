/*
 * clpars___.cpp
 *
 *  Created on: 2011-7-10
 *      Author: zzzzzzzzzzz
 */

#include "clpars___.h"
#include <algorithm>
#include <stdio.h>
#include "../new_gg/call_util.cpp"
#include "pub.h"
#include "../../zhscript2-lib/i.h"
#include "../../zhscript2-lib/i2.h"

void* jsq_;
callback3_2___ cb2_;
dlle___ void init__(void* jsq,callback3_2___ cb2){
	jsq_=jsq;
	cb2_=cb2;
}
static callback4_3___ cbx3_ = NULL;
dlle___ void init2__(callback4_3___ cbx3){
	cbx3_ = cbx3;
}

static void attr__(std::vector<std::string>* ret, int* err, clpars_item___* ci, int argc, ...) {
	va_list argv;
	va_start(argv, argc);
	for (int i = 0; i < argc; i++) {
		char* s = va_arg(argv, char*);
		if(s) {
			string s2 = s;
			if(s2 == "1" || s2 == "flag") {
				ret->push_back(ci->flag_);
			} else if(s2 == "2" || s2 == "info" || s2 == "rem") {
				ret->push_back(ci->info_);
			} else if(s2 == "3" || s2 == "type" || s2 == "argc") {
				char buf[16];
				int i;
				if(s2 == "3" || s2 == "type")
					i = sprintf(buf, "%c", ci->type_);
				else
					i = 0;
				sprintf(buf + i, "%i", ci->argc_);
				ret->push_back(buf);
			} else if(s2 == "4" || s2 == "code") {
				ret->push_back(ci->code_);
			} else {
				*err = 1;
				break;
			}
		}
	}
	va_end(argv);
}

#include <sstream>
void clpars_item___::flags__() {
	string s;
//#ifdef ver_sstream_too_bad_
	for(size_t i = 0; i < flag_.size(); i++) {
		char c = flag_[i];
		if(c == '|') {
			flags_add__(s);
			s.clear();
			continue;
		}
		if(!is_sp__(c))
			s += c;
	}
	if(!s.empty())
		flags_add__(s);
/*#else
	stringstream ss(flag_);
	while(getline(ss,s,'|'))
		flags_add__(s);
#endif*/
	if(code_.empty() && info_.empty()) {
		bool can = true;
		for(list<string>::iterator si=flags_.begin();si!=flags_.end();si++){
			if(is_help__(si->c_str())) {
				can = false;
				break;
			}
		}
		if(can)
			flags_.clear();
	}
}

void clpars_item___::flags_add__(string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_sp_));
	s.erase(std::find_if(s.rbegin(), s.rend(), is_sp_).base(), s.end());
	flags_.push_back(s);
}

is_sp___ clpars_item___::is_sp_ = std::not1(std::ptr_fun<int, int>(/*std::isspace*/is_sp__));

clpars_item___::~clpars_item___() {
	if(reg_) {
		regfree(reg_);
		delete reg_;
		reg_ = NULL;
	}
}

clpars___::clpars___() {
	par_1_ = 0;
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
	regex_t *reg = NULL;
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
		case 'r': {
			type=s[0];
			argc1=0;
			reg = new regex_t;
			int z = regcomp(reg, flag, REG_EXTENDED|REG_NEWLINE);
			if(z != 0) {
				regerror(z, reg, buf, 512);
				*err=2;
				return;
			}
			break;
		}
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
				sprintf(buf,"'%s' no int", s);
				*err=2;
				return;
			}
			if(argc1 < 0) {
				sprintf(buf,"%d bad argc", argc1);
				*err=2;
				return;
			}
		}
		if(!flag[0] && !(argc1 > 0 || type == 'a' || type == 'h')) {
			sprintf(buf,"empty flag no %c%d", type, argc1);
			*err=2;
			return;
		}
		clpars_item___* item=new clpars_item___(flag,info,code,argc1,reg,type);
		item_.push_back(item);
	}
}

class comp___ {
private:
	clpars_item___* ci_;
	string s_;
	const char**src2_;
	list<string> *arg1_;
public:
	comp___(const char*s, clpars_item___* ci,const char**src2,list<string> *arg1) {
		s_ = s;
		ci_ = ci;
		src2_=src2;
		arg1_=arg1;
	}
	bool operator () (string& s2) {
		bool b = false;
		switch(ci_->type_){
		case 'b':
			if(s_.find(s2) == 0) {
				arg1_->push_back(s_.substr(s2.size()));
				b = true;
			}
			break;
		case 'e':
			if(s_.size() >= s2.size() && s_.rfind(s2) == s_.size()-s2.size()) {
				arg1_->push_back(s_.substr(0, s_.size()-s2.size()));
				b = true;
			}
			break;
		case 'c':
			if(s_.find(s2) != string::npos) {
				arg1_->push_back(s_);
				b = true;
			}
			break;
		case 'r': {
#define pm_len 128
			regmatch_t pm[pm_len];
			size_t off = 0;
			while(off < s_.size() && regexec(ci_->reg_, s_.c_str() + off, pm_len, pm, 0) == 0) {
				for(int i2 = 1; i2 < pm_len; i2++) {
					if(pm[i2].rm_so == -1)
						break;
					string s;
					for(int i = pm[i2].rm_so; i < pm[i2].rm_eo; i++)
						s += s_[i];
					arg1_->push_back(s);
				}
				off += pm[0].rm_eo;
				b = true;
			}
			break;
		}
		default:
			b = (s2==s_);
			break;
		}
		if(b) {
			*src2_ = s2.c_str();
		}
		return b;
	}
};

int clpars___::cb__(const char*flag,bool by_help,bool no,int& i1,int&i, int& pause,
		char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv)
{
	char no1[16];
	int has=0;
	const char* src2 = NULL;
	list<string> argv3, argv4;
	for(int scan = 0; scan < 2 && !has; scan++) {
		for(list<clpars_item___*>::iterator cii=item_.begin();cii!=item_.end();cii++){
			clpars_item___* ci=*cii;
			if(ci->pause_ == 2) {
				pause++;
				continue;
			}
			bool b=false;
			switch(scan) {
			case 0:
				if(by_help){
					b=(ci->type_ == 'h');
				} else {
					if(!b){
						bool b2 = true;
						switch(ci->type_) {
						case 'b': case 'e': case 'c': case 'r':
							if(has > 0)
								b2 = false;
							break;
						}
						if(b2) {
							list<string>::iterator si = find_if(
									ci->flags_.begin(), ci->flags_.end(),
									comp___(flag,ci,&src2,&argv3) );
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
						src2 = (*ci->flags_.begin()).c_str();
					} else {
						if(has==1){
							switch(ci->type_){
							case 'b':case 'e':case 'c':case 'r':
								for(list<string>::iterator si = argv3.begin(); si != argv3.end(); si++)
									argv4.push_back(*si);
								break;
							}
						}
					}
					break;
				case 1:
					if(no) {
						sprintf(no1,"%d",++i1);
						argv4.push_back(no1);
					}
					argv4.push_back(flag);
					break;
				}
				if(has==1){
					if(ci->argc_ > 0 || ci->type_ == 'a'){
						int argc2 = ci->type_ == 'a' ? argc - i : (ci->argc_ - (ci->flag_.empty() ? 1 : 0));
						if(ci->type_ == 'a') {
							if(argc2 < ci->argc_) {
								sprintf(buf,"'%s'(%c%d) no arg",flag,ci->type_,ci->argc_);
								*err=1;
								return has;
							}
						}
						for(int i2 = 0; i2 < argc2; i2++, i++){
							if(i>=argc){
								sprintf(buf,"'%s'(%c%d) no arg",flag,ci->type_,ci->argc_);
								*err=1;
								return has;
							}
							char* s = va_arg(argv, char*);
							argv4.push_back(s ? s : "NULL");
						}
					}
				}
				if(ci->pause_)
					continue;
				if(help__(by_help ? src2 : flag, code, err))
					break;
				const char**argv2 = new const char*[argv4.size()];
				int i2=0;
				for(list<string>::iterator si = argv4.begin(); si != argv4.end(); si++, i2++) {
					argv2[i2] = (*si).c_str();
				}
				if(cbx3_) {
					switch(cbx3_(jsq_, ce, code,false,src2,shangji, (void*)attr__, ci, i2,argv2,0)) {
					case -1: *err = jieshiqi_err_go_+keyword_break_; break;
					case -2: *err = jieshiqi_err_go_+keyword_continue_; break;
					case -3: *err = jieshiqi_err_go_+keyword_end_; break;
					case 0: *err = jieshiqi_err_; break;
					}
				} else
					cb2_(jsq_,shangji,err,ce,code,false,src2,i2,argv2,0);
				delete argv2;
				if(*err == jieshiqi_err_go_+keyword_continue_){
					*err=0;
					continue;
				}
				if(*err == jieshiqi_err_go_+keyword_break_){
					*err=0;
					break;
				}
				if(*err)
					break;
			}
		}
	}
	return has;
}

bool clpars_item___::is_help__(const char* flag) {
	string flag2 = flag ? flag : "";
	if((flag2 == "-h" || flag2 == "--help" || flag2 == "#"))
		return true;
	return false;
}

bool clpars___::help__(const char* flag, const char* code, int* err) {
	if(clpars_item___::is_help__(flag) && !code[0]) {
		string info;
		info__(info, "", "\t", "\n", false);
		printf("%s", info.c_str());
		*err = jieshiqi_err_go_+keyword_end_;
		return true;
	}
	return false;
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

	int pause = 0;
	if(par_1_ > 100) {
		sprintf(buf,"is loop");
		*err=11;
		par_1_ = 0;
		return 1;
	}
	par_1_++;
	int has=cb__(flag,by_help,no,i1,i,pause,buf,err,ce,shangji,argc,argv);
	par_1_--;
	if(*err)
		return 1;
	if(has)
		return 0;
	if(by_help)
		return 0;
	if(pause)
		return 0;

	if(help__(flag, "", err))
		return 1;

	sprintf(buf,"'%s' no parse", flag);
	*err=3;
	return 1;
}

void clpars___::par__(char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,int from,bool no){
	int i1=0,i = from;
	if(argc == 0)
		par__(i1,i,"",true,buf,err,ce,shangji,argc,argv,no);
	else {
		for (; i < argc; ){
			if(0 != par__(i1,i,va_arg(argv, char*),false,buf,err,ce,shangji,argc,argv,no)){
				return;
			}
		}
	}
}

void clpars___::info__(string& info,const char* t1,const char* t2,const char* n,bool yange){
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
}

void clpars___::info__(char**&addr_ret,const char* t1,const char* t2,const char* n,bool yange){
	string info;
	info__(info, t1, t2, n, yange);
	*addr_ret=dup__(info.c_str());
}

void clpars___::info__(char*buf,int* err,void*ce,void* shangji,char* code, char**addr_ret){
	list<clpars_item___*>::iterator cii;
	clpars_item___* ci;
	const char*argv2[32];
	int argc2;
	string ret;
	char buf2[16], typ[2] = {0, 0}, pause[2] = {0, 0};
	for(cii=item_.begin();cii!=item_.end();cii++){
		ci=*cii;
		argc2=0;
		if(addr_ret) {
			pause[0] = ci->pause_ ? '1' : '0';
			argv2[argc2++]=pause;
		}
		argv2[argc2++]=ci->info_.c_str();
		if(addr_ret) {
			argv2[argc2++]=ci->code_.c_str();
			typ[0] = ci->type_;
			argv2[argc2++]=typ;
			sprintf(buf2,"%d",ci->argc_);
			argv2[argc2++]=buf2;
		}
		argv2[argc2++]=ci->flag_.c_str();
		for(list<string>::iterator si=ci->flags_.begin();si!=ci->flags_.end();si++){
			argv2[argc2++]=(*si).c_str();
		}
		const char* ret2 = cb2_(jsq_,shangji,err,ce,code,false,NULL,argc2,argv2,0);
		if(ret2)
			ret += ret2;
		if(*err)
			break;
	}
	if(addr_ret)
		*addr_ret=dup__(ret.c_str());
}

void clpars___::pause__(int pause, int argc, char** argv) {
	for(list<clpars_item___*>::iterator cii=item_.begin();cii!=item_.end();cii++){
		clpars_item___* ci=*cii;
		if(argc <= 0)
			ci->pause_ = pause;
		else {
			for(int i = 0; i < argc && ci->pause_ != pause; i++) {
				char* arg = argv[i];
				if(!arg)
					continue;
				if(ci->flag_.empty()) {
					if(!arg || !arg[0])
						ci->pause_ = pause;
					continue;
				}
				for(list<string>::iterator si=ci->flags_.begin();si!=ci->flags_.end();si++){
					if((*si) == arg) {
						ci->pause_ = pause;
						break;
					}
				}
			}
		}
	}

}
