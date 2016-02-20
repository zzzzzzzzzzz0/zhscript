#include "gjke.h"
#include "for_arg_.h"

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
