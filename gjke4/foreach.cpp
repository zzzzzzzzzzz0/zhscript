#include "gjke.h"
#include "for_arg_.h"
#include "l4/errinfo.h"

#include "../../zhscript2-lib/i2.h"
static callback4_3___ cb4_ = NULL;
dlle___ void dlln___(init2__)(callback4_3___ cb) {
	cb4_ = cb;
}

dlle___ void dlln___(for_name__)(int*err,void*ce,void* shangji2,const char*code,void* shangji,int max){
	var_for_name_(jsq_,shangji2,err,ce,code,callback3_,shangji,max);
}

dlle___ void dlln___(foreach__)(int*err,char**addr_ret,void*ce,void* shangji,bool no,const char*code,int argc,...){
	string ret;
	_for_args( argc )
	if(no){
		char buf[32];
		ret+=callback_(jsq_,shangji,err,ce,code,false,NULL,2,i2s__(i+1,buf),s);
	}else
		ret+=callback_(jsq_,shangji,err,ce,code,false,NULL,1,s);
	if(for_err__(err)) break;
	_next_args
	*addr_ret=dup__(ret.c_str());
}
dlle___ void dlln___(foreach2__)(int*err,std::vector<std::string>* ret,void*ce,void* shangji,bool no,const char*code,int argc2,int argc,...){
	if(argc2 <= 0) {
		*err = 1;
		return;
	}
	if(argc % argc2 != 0) {
		*err = 2;
		return;
	}
	char buf[32];
	i2s__(argc / argc2, buf);
	if(no)
		argc2++;
	const char** argv2 = new const char*[argc2];
	char buf2[32];
	std::vector<std::string>* ret2 = ret;
	std::vector<std::string> ret3;
	string ret4;
	bool is_set_1 = false, is_1 = false;
	va_list argv;
	va_start(argv, argc);
	for (int i = 0, i3 = 0; i < argc;) {
		int i2 = 0;
		if(no) {
			i2s__(++i3, buf2);
			argv2[i2++] = buf2;
		}
		for (; i2 < argc2; ++i) {
			argv2[i2++] = va_arg(argv, char*);
		}
		int ret5 = cb4_(jsq_, ce, code,false,NULL,shangji, NULL,NULL, argc2,argv2, ret2);
		cb4_if_err__(ret5, 3)
		if(!is_set_1) {
			is_set_1 = true;
			is_1 = ret2->size() == 1;
			if(is_1) {
				ret4 += (*ret2)[0];
				ret2->clear();
				ret2 = &ret3;
			}
		}
	}
	delete argv2;
	if(is_1) {
		for(size_t i = 0; i < ret3.size(); i++)
			ret4 += ret3[i];
		ret->push_back(ret4);
	}
}

void array_cb__(int*err,void*ce,void* qu,const char*code,char*head1,bool no,bool desc,string&ret){
	string name;
	name=head1;
	name+=kw_length_;
	const char*val;
	if(!(val=var_get_(jsq_,qu,name.c_str())))
		return;
	int len=s2i__(val),len2;
	bool has2;
	char buf2[32];
	name=head1;
	name+=kw_length_;
	name+='2';
	if((val=var_get_(jsq_,qu,name.c_str()))){
		len2=s2i__(val);
		has2=true;
	}else{
		len2=1;
		has2=false;
		buf2[0]='1';
		buf2[1]=0;
	}
	char buf1[32];
	const char*val1[64];
#define val1_length sizeof(val1)/sizeof(const char*)
	if(len2>val1_length)
		len2=val1_length;
	int i1_b,i1_e,i1_i,i2_b,i2_e,i2_i;
	if(desc){
		i1_e=1;
		i1_b=len;
		i2_e=1;
		i2_b=len2;
		i1_i=i2_i=-1;
	}else{
		i1_b=1;
		i1_e=len;
		i2_b=1;
		i2_e=len2;
		i1_i=i2_i=1;
	}
	int v1_add=0;
	if(no)
		v1_add+=1;
	for(int i1=i1_b;;i1+=i1_i){
		if(desc){
			if(i1<i1_e)
				break;
		}else{
			if(i1>i1_e)
				break;
		}
		i2s__(i1,buf1);
		for(int i2=i2_b;;i2+=i2_i){
			if(desc){
				if(i2<i2_e)
					break;
			}else{
				if(i2>i2_e)
					break;
			}
			name=head1;
			if(has2){
				if(len>1){
					name+=kw_dian_;
					name+=buf1;
				}
				if(len2>1||len==1){
					name+=kw_dian_;
					name+=i2s__(i2,buf2);
				}
			}else
				name+=buf1;
			val=var_get_(jsq_,qu,name.c_str());
			if(!val){
				if(has2){
					name=head1+kw_dian_+buf1+kw_dian_+i2s__(i2,buf2);
					val=var_get_(jsq_,qu,name.c_str());
				}
				if(!val) {
					*err = jieshiqi_err_ + errinfo_var_find_;
					return;
				}
			}
			val1[i2-1+v1_add]=val;
		}
		if(no){
			val1[0]=buf1;
		}
		ret+=callback3_(jsq_,qu,err,ce,code,false,NULL,len2+v1_add,val1,0);
		if(for_err__(err)) break;
	}
}

dlle___ void dlln___(for_array__)(int*err,char**addr_ret,void*ce,void* qu,bool no,bool desc,const char*code,int argc,...){
	string ret;
	_for_args( argc )
	array_cb__(err,ce,qu,code,s,no,desc,ret);
			if(*err)
				break;
	_next_args
	*addr_ret=dup__(ret.c_str());
}
