/*
 * test.cpp
 *
 *  Created on: 2010-8-10
 *      Author: zzzzzzzzzzz
 */

#include "../new_gg/def1.h"
#include"../new_gg/call_util.cpp"
#include "../new_gg/for_arg_.h"
#include<stdio.h>
#include<iostream>
using namespace std;

dlle___ void dlln___(Z__)(int argc,...){
	cout<<"Z(";
	_for_args( argc )
			cout<<i<<":"<<s<<",";
	_next_args
	cout<<")"<<endl;
}

dlle___ void dlln___(l4__)(long l,long l1,long l2,long l3){
	cout<<"l4("<<hex<<l<<" "<<l1<<" "<<l2<<" "<<l3<<dec<<")"<<endl;
}

dlle___ void dlln___(void__)(void){
	cout<<"void"<<endl;
}

dlle___ unsigned char* dlln___(ret_uca__)(unsigned char*s){
	cout<<"ret_uca("<<s<<")"<<endl;
	return s;
}
dlle___ char* dlln___(ret_ca__)(char*s){
	cout<<"ret_ca("<<s<<")"<<endl;
	return s;
}
dlle___ int dlln___(ret_i__)(int i){
	cout<<"ret_i("<<i<<")"<<endl;
	return i;
}
dlle___ long dlln___(ret_l__)(int i){
	cout<<"ret_l("<<i<<")"<<endl;
	return i;
}
dlle___ unsigned int dlln___(ret_ui__)(unsigned int i){
	cout<<"ret_ui("<<i<<")"<<endl;
	return i;
}
dlle___ unsigned long dlln___(ret_ul__)(unsigned long i){
	cout<<"ret_ul("<<i<<")"<<endl;
	return i;
}

char c_='c';
unsigned long ul_=4287654321ul;
const char* s_="this is s";
dlle___ char dlln___(c__)(){return c_;}
dlle___ unsigned long dlln___(ul__)(){return ul_;}
dlle___ const char* dlln___(s__)(){return s_;}

dlle___ void dlln___(iBSAE__)(int i1
		,char*buf2,char*buf,long siz,char**addr_ret,int*err
		,int i2,int i3,int argc,...
		){
	cout<<i1
	<<hex<<" buf2="<<(long)buf2<<" buf="<<(long)buf<<dec<<" siz="<<siz
	<<hex<<" err="<<(long)err<<" addr_ret="<<(long)addr_ret<<dec
	<<" "<<i2<<" "<<i3;
	_for_args( argc )
			cout<<" "<<i<<":"<<s;
	_next_args
	cout<<endl;
	cout<<"buf\t{"<<cpy__(buf,s_,siz)<<"}"<<endl;
	*addr_ret=dup__(s_);
	//*err=1;
}

dlle___ int cb__(callback2___ cb,void* jsq,void* shangji,const char* src,
		long l,unsigned long ul){
	int err=0;
	char s1[16],s2[16],s3[16],s8[16],s9[16];
	sprintf(s1,"%#lx",(long)cb);
	sprintf(s2,"%#lx",(long)jsq);
	sprintf(s3,"%#lx",(long)shangji);
	sprintf(s8,"%ld",l);
	sprintf(s9,"%lu",ul);
	cb(jsq,shangji,&err,src,false,6,s1,s2,s3,src,s8,s9);
	return err;
}

dlle___ const char* cb3__(int*err,char**addr_ret,char*buf,long siz,
		callback3___ cb3,void* jsq,void* shangji,const char* src,bool src_is_file,
		int argc,...){
	const char**argv2=new const char*[argc];
	_for_args( argc )
			argv2[i]=s;
	_next_args
	cb3(jsq,shangji,err,src,src_is_file,argc,argv2,0);
	delete argv2;
	cpy__(buf,"S",siz);
	*addr_ret=dup__("A");
	return "s";
}

dlle___ int v_n__(var_new___ vn,void* jsq,void* qu,const char*name,const char* val,
		bool readonly,int type,bool is_noparam){
	return vn(jsq,qu,name,val,readonly,type,is_noparam);
}
dlle___ const char* v_g__(var_get___ vg,void* jsq,void* qu,const char* name){
	return vg(jsq,qu,name);
}
dlle___ int v_d__(var_del___ vd,void* jsq,void* qu,const char* name){
	return vd(jsq,qu,name);
}

int callback__(int argc,...){
	string s1;
	_for_args( argc ){
		if(i==0){
			s1=s;
			if(s1=="1")
				cout<<"  ";
			cout<<"(";
		}else{
			cout<<s;
			if(i<argc-1)
				cout<<",";
		}
	}_next_args
	cout<<")";
	if(s1=="0"||s1=="3"||(s1=="1"&&argc==2))
		cout<<endl;
	return 0;
}
dlle___ void v_f__(var_for___ vf,void* qu){
	vf(qu,callback__);
}

dlle___ void S0S__(void* jsq,callback2___ cb){
	cout<<"S0S("<<jsq<<","<<(void*)cb<<")"<<endl;
}
dlle___ void SS0__(callback2___ cb,void* jsq){
	cout<<"SS0("<<(void*)cb<<","<<jsq<<")"<<endl;
}
