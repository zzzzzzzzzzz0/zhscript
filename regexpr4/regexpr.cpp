#include<string>
using namespace std;
#include <regex.h>
#include"def1.h"
#include"for_arg_.h"
#include"call_util.cpp"
#include "l4/keyword.h"
#include<string.h>
#include<stdio.h>
#include<list>
#include <algorithm>

#ifdef ver_mac_mini_
#define no_empty_sub_expression__(exp) (!exp[0] ? ".*" : exp)
#else
#define no_empty_sub_expression__(exp) exp
#endif

#define nmatch_ 128

callback2_2___ callback_;
callback3_2___ callback3_;
var_new___ var_new_;
var_get___ var_get_;
var_del___ var_del_;
void* jsq_;
string kw_length_,kw_dian_;

dlle___ void dlln___(init__)(void* jsq,
		callback2_2___ cb,
		callback3_2___ cb3,
		var_new___ var_new,var_get___ var_get,var_del___ var_del,
		char*len,char*dian)
{
	jsq_=jsq;
	callback_=cb;
	callback3_=cb3;
	var_new_=var_new;
	var_get_=var_get;
	var_del_=var_del;
	kw_length_=len;
	kw_dian_=dian;
}

#include "../../zhscript2-lib/i2.h"
static callback4_3___ cb4_ = NULL;
dlle___ void dlln___(init2__)(callback4_3___ cb) {
	cb4_ = cb;
}

int get_maxlen__(regmatch_t pm[],int nmatch){
	int max=0;
	for(int i=0;i<nmatch;i++){
		if(pm[i].rm_so == -1){
			break;
		}
		if(pm[i].rm_eo>max){
			max=pm[i].rm_eo;
		}
	}
	return max;
}

int cflags__(char*s,char*buf,int defa){
	int cflags=defa;
	for(int i1=0;s[i1];i1++){
		switch(s[i1]){
		case'e':
			cflags|=REG_EXTENDED;
			break;
		case'i':
			cflags|=REG_ICASE;
			break;
		case'n':
			cflags|=REG_NOSUB;
			break;
		case'l':
			cflags|=REG_NEWLINE;
			break;
		default:
			if(buf)
				sprintf(buf,"cflags:%s",s);
			return -1;
		}
	}
	return cflags;
}

int eflags__(char*s,char*buf,int defa){
	int eflags=defa;
	for(int i1=0;s[i1];i1++){
		switch(s[i1]){
		case'e':
			eflags|=REG_NOTEOL;
			break;
		case'b':
			eflags|=REG_NOTBOL;
			break;
		default:
			if(buf)
				sprintf(buf,"eflags:%s",s);
			return -1;
		}
	}
	return eflags;
}

bool flags__(int argc, va_list &argv, char*buf, int &cflags, int &eflags) {
	for (int i = 0; i < argc; ++i) {
		char*s = va_arg(argv, char*);
		switch(i){
		case 0:
			if((cflags=cflags__(s,buf,cflags))==-1){
				return false;
			}
			break;
		case 1:
			if((eflags=eflags__(s,buf,eflags))==-1){
				return false;
			}
			break;
		}
	}
	va_end(argv);
	return true;
}

dlle___ void dlln___(regexpr_test__)(char*buf,size_t siz,char*src,char*exp,int argc,...){
	if(!src||!exp)
		return;
	int cflags=REG_EXTENDED|REG_NOSUB, eflags=0;
	{
		va_list argv;
		va_start(argv, argc);
		if(!flags__(argc, argv, buf, cflags, eflags))
			return;
	}
	regex_t reg;
	int z=regcomp(&reg, no_empty_sub_expression__(exp), cflags);
	if(z==0){
		z = regexec(&reg, src, 0, 0, eflags);
	}
	if(z==0){
		buf[0]='1';
		buf[1]=0;
	}else if(z == REG_NOMATCH){
		buf[0]='0';
		buf[1]=0;
	}else{
		regerror(z, &reg, buf, siz);
	}
	regfree(&reg);
}

dlle___ void dlln___(regexpr_get__)(int*err,char*buf,long siz,
		void* qu,char* src,char* exp,int argc,...)
{
	if(!src||!exp)
		return;
	string head;
	bool readonly=false;
	int cflags=REG_EXTENDED, eflags=0;
	bool rmcf=false;

	int argi;
	char argmode='n';
	bool argk;

	_for_args(argc)
	switch(i){
	case 0:
		head=s;
		continue;
	default:
		if(i==1){
			if(s[0]=='-'&&!s[1]){
				argmode='k';
				argk=false;
				continue;
			}
		}
		switch(argmode){
		case'k':
			argk=!argk;
			if(argk){
				string arg=s;
				if(arg=="readonly"){
					argi=1;
					continue;
				}
				if(arg=="cflags"){
					argi=2;
					continue;
				}
				if(arg=="eflags"){
					argi=3;
					continue;
				}
				if(arg=="rmcf"){
					argi=4;
					continue;
				}
				sprintf(buf,"key:%s",s);
				*err=3;
				return;
			}
			break;
		default:
			argi=i;
		}
	}
	switch(argi){
	case 1:
		sscanf(s,"%d",&readonly);
		break;
	case 2:
		if((cflags=cflags__(s,buf,0))==-1){
			*err=3;
			return;
		}
		break;
	case 3:
		if((eflags=eflags__(s,buf,0))==-1){
			*err=3;
			return;
		}
		break;
	case 4:
		sscanf(s,"%d",&rmcf);
		break;
	}
	_next_args

	list<string> cf_v;

	regex_t reg;
	int z=regcomp(&reg, no_empty_sub_expression__(exp), cflags);
	if(z != 0)
	{
		regerror(z, &reg, buf, siz);
		regfree(&reg);
		*err=1;
		return;
	}
	regmatch_t pm[nmatch_];
	bzero(pm, sizeof(pm));
	unsigned int start=0,len=strlen(src);
	int i1=0,i2=0;
	for(;;){
		z = regexec(&reg, src+start, nmatch_, pm, eflags);
		if(z == REG_NOMATCH || z != 0)
			break;
		int max=get_maxlen__(pm,nmatch_);
		if(max==0)
			break;
		i2=0;
		for(int i=1;i<nmatch_;i++,i2++){
			if(pm[i].rm_so == -1)
				break;
		}
		bool add=true;
		for(int i=1;i<nmatch_;i++){
			if(pm[i].rm_so != -1){
				string val;
				for(int i3=pm[i].rm_so;i3<pm[i].rm_eo;)
					val+=src[start+i3++];
				if(rmcf){
					if(find(cf_v.begin(),cf_v.end(),val)!=cf_v.end())
						continue;
					cf_v.push_back(val);
				}
				if(add){
					add=false;
					i1++;
				}
			 	string name;
				name=head;
				name+=kw_dian_;
				sprintf(buf,"%d",i1);
				name+=buf;
				if(i2>1){
					name+=kw_dian_;
					sprintf(buf,"%d",i);
					name+=buf;
				}
				//printf("%s=%s;\n",name.c_str(),val.c_str());
				if((*err=var_new_(jsq_,qu,name.c_str(),val.c_str(),readonly,false,false))){
					regfree(&reg);
					return;
				}
			}
		}
		start+=max;
		if(start>=len)
			break;
	}
	regfree(&reg);
	if(i1==1&&i2>1){
		for(int i=1;i<=i2;i++){
			string name;
			name=head;
			name+=kw_dian_+"1"+kw_dian_;
			sprintf(buf,"%d",i);
			name+=buf;
			string val=var_get_(jsq_,qu,name.c_str());
			var_del_(jsq_,qu,name.c_str());
			name=head;
			name+=kw_dian_;
			sprintf(buf,"%d",i);
			name+=buf;
			if((*err=var_new_(jsq_,qu,name.c_str(),val.c_str(),readonly,false,false)))
				return;
		}
	}
	sprintf(buf,"%d",i1);
	if((*err=var_new_(jsq_,qu,(head+"-1").c_str(),buf,readonly,false,false)))
		return;
	if((*err=var_new_(jsq_,qu,(head+kw_length_).c_str(),buf,readonly,false,false)))
		return;
	sprintf(buf,"%d",i2);
	if((*err=var_new_(jsq_,qu,(head+"-2").c_str(),buf,readonly,false,false)))
		return;
	if((*err=var_new_(jsq_,qu,(head+kw_length_+"2").c_str(),buf,readonly,false,false)))
		return;
}

void get_reg_err__(int z,regex_t*reg,char* ebuf,size_t sizeof_ebuf){
	regerror(z, reg, ebuf, sizeof_ebuf);
}


void add_pm__(char* str,regmatch_t pm,string& s){
	if(pm.rm_so == -1)
		return;
	//printf("%d--%d\n",pm.rm_so,pm.rm_eo);
	for(int i=pm.rm_so;i<pm.rm_eo;)
		s+=str[i++];
}

bool regexpreplace__(int*err,void* ce,char*buf,long siz,char* src,char* from,
		char* to,void* shangji,int cflags,int eflags, bool duocan, bool all_s,
		string* s, std::vector<std::string>* ret1){
	regex_t reg;
	int z=regcomp(&reg, no_empty_sub_expression__(from), cflags);
	if(z != 0)
	{
		get_reg_err__(z,&reg,buf,siz);
		regfree(&reg);
		*err=1;
		return false;
	}
	unsigned int start=0,len=strlen(src);
	int i1=0;
	regmatch_t pm[nmatch_];
	bzero(pm, sizeof(pm));
	std::string ret1a;
	for(;;){
		z = regexec(&reg, src+start, nmatch_, pm, eflags);
		//printf("%d=%s/%d %s %s\n",z,src+start,start,from,to);
		if(z == REG_NOMATCH || z != 0)
			break;
		i1++;
		if(all_s) {
			if(ret1) {
				for(int i2=0;i2<pm[0].rm_so;i2++)
					ret1a+=src[start+i2];
			}
			if(s) {
				for(int i2=0;i2<pm[0].rm_so;i2++)
					*s+=src[start+i2];
			}
		}
		if(shangji){
			if(duocan){
				int argc=0;
				const char* argv[nmatch_];
				string argv2[nmatch_];
				for(int i2=1;i2<nmatch_;i2++){
					regmatch_t pm2=pm[i2];
					if(pm2.rm_so == -1)
						break;
					size_t eo=start+pm2.rm_eo;
					size_t so=start+pm2.rm_so;
					for(size_t i=so;i<eo;i++)
						argv2[argc]+=src[i];
					argv[argc]=argv2[argc].c_str();
					argc++;
				}
				if(ret1) {
					std::vector<std::string> ret2;
					int ret = cb4_(jsq_, ce, to,false,NULL,shangji, NULL,NULL, argc,argv, &ret2);
					size_t end2 = ret2.size();
					if(end2 > 1) {
						ret1a += ret2[0];
						ret1->push_back(ret1a);
						ret1a.clear();
						end2--;
						for(size_t i = 1; i < end2; i++) {
							ret1->push_back(ret2[i]);
						}
						ret1a += ret2[end2];
					} else if(end2 == 1)
						ret1a += ret2[0];
					cb4_if_err__(ret, 2)
				} else {
					const char* ret=callback3_(jsq_,shangji,err,ce,to,false,NULL,argc,argv,0);
					if(s)
						*s+=ret;
					if(*err==jieshiqi_err_go_+keyword_continue_)
						*err=0;
				}
			}else{
			 	char buf1[16],buf2[8], buf3[16] = "";
				sprintf(buf1,"%d",i1);
				for(int i2=1;i2<nmatch_;i2++){
					regmatch_t pm2=pm[i2];
					if(pm2.rm_so == -1)
						break;
					/*size_t eo=start+pm2.rm_eo;
					char c_old=src[eo];
					src[eo]=0;*/
					sprintf(buf2,"%d",i2);
					if(s)
						sprintf(buf3,"%u",(*s).size());
					string buf4;
					for(int i4 = pm2.rm_so; i4 < pm2.rm_eo; i4++)
						buf4 += src[i4+start];
					const char* ret=callback_(jsq_,shangji,err,ce,to,false,NULL,4,
							//src+start+pm2.rm_so,
							buf4.c_str(),
							buf2,buf1, buf3);
					if(s)
						*s+=ret;
					//src[eo]=c_old;
					if(*err){
						if(*err==jieshiqi_err_go_+keyword_continue_){
							*err=0;
						}else
							break;
					}
				}
			}
			if(*err){
				if(*err==jieshiqi_err_go_+keyword_break_){
					*err=0;
					break;
				}
				regfree(&reg);
				return false;
			}
		}else{
			if(s)
			for(int i2=0;to[i2];i2++){
				char c=to[i2];
				switch(c){
				case'$':
					c=to[++i2];
					if(c>='0' && c<='9'){
						add_pm__(src+start,pm[c-'0'],*s);
					}
					else{
						*s+=c;
					}
					break;
				default:
					*s+=c;
				}
			}
		}

		int max=get_maxlen__(pm,nmatch_);
		if(max==0)
			break;
		start+=max;
		if(start>=len)
			break;
	}
	if(all_s) {
		if(ret1) {
			for(unsigned int i2=start;i2<len;i2++)
				ret1a+=src[i2];
		}
		if(s){
			for(unsigned int i2=start;i2<len;i2++)
				*s+=src[i2];
		}else if(buf)
			sprintf(buf,"%d",i1);
	}
	if(ret1) {
		if(!ret1a.empty())
			ret1->push_back(ret1a);
	}
	regfree(&reg);
	return true;
}

dlle___ void dlln___(regexpreplace__)(int*err,char**addr_ret,char*buf,long siz,
		bool fore,bool duocan, bool all_s, void* ce,void* shangji,char* src,char* from,char* to,int argc,...){
	if(!src||!from||!to)
		return;
	int cflags=REG_EXTENDED,eflags=0;
	{
		va_list argv;
		va_start(argv, argc);
		if(!flags__(argc, argv, buf, cflags, eflags))
			return;
	}
	string s;
	if(!regexpreplace__(err,ce,buf,siz,src,from,to,shangji,cflags,eflags,duocan, all_s, fore?NULL:&s, NULL))
		return;
	*addr_ret=dup__(s.c_str());
}
dlle___ void dlln___(regexpr_get2__)(int*err, std::vector<std::string>* ret,
		void* ce,void* shangji,char* src,char* from,char* to, bool all_s, int argc,...){
	if(!src||!from||!to)
		return;
	int cflags=REG_EXTENDED,eflags=0;
	{
		va_list argv;
		va_start(argv, argc);
		char buf[32];
		if(!flags__(argc, argv, buf, cflags, eflags))
			return;
	}
	regexpreplace__(err,ce,NULL,0,src,from,to,shangji,cflags,eflags,true, all_s, NULL, ret);
}

dlle___ void dlln___(regexpr__)(int*err,char**addr_ret,char*buf,long siz,int argc,...){
	if(argc<1)
		return;
	char* src;
	char* exp=(char*)"([0-9]+)";
	char* fmt=(char*)"%1";
	int top=0;
	int btm=0;
	_for_args(argc)
		//printf("%s\n",s);
		switch(i){
			case 0:
			src=s;
			break;
			case 1:
			exp=s;
			break;
			case 2:
			fmt=s;
			break;
			case 3:
			sscanf(s,"%d",&top);
			break;
			case 4:
			sscanf(s,"%d",&btm);
			break;
		}
	_next_args

	regex_t reg;
	int z=regcomp(&reg, no_empty_sub_expression__(exp), REG_EXTENDED|REG_NEWLINE);
	if(z != 0)
	{
		get_reg_err__(z,&reg,buf,siz);
		regfree(&reg);
		*err=1;
		return;
	}
	string s;
	regmatch_t pm[nmatch_];
	bzero(pm, sizeof(pm));
	unsigned int start=0;
	for(int i1=1;;i1++){
		if(btm>0 && i1>btm)
			break;
		z = regexec(&reg, src+start, nmatch_, pm, 0);
		//printf("%d=%s/%d %s\n",z,str+start,start,exp);
		if(z == REG_NOMATCH || z != 0)
		{
			break;
		}
		if(i1>=top){
			for(int i2=0;fmt[i2];i2++){
				char c=fmt[i2];
				switch(c){
				case'%':
					c=fmt[++i2];
					if(c>='0' && c<='9'){
						add_pm__(src+start,pm[c-'0'],s);
					}
					else if(c>='a' && c<='f'){
						add_pm__(src+start,pm[c-'a'+10],s);
					}
					else{
						s+=c;
					}
					break;
				default:
					s+=c;
				}
			}
		}
		int max=get_maxlen__(pm,nmatch_);
		if(max==0)
			break;
		start+=max;
		if(start>=strlen(src))
			break;
	}
	regfree(&reg);
	*addr_ret=dup__(s.c_str());
}
