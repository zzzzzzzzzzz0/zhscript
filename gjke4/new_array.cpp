/*
 * new_array.cpp
 *
 *  Created on: 2010-4-24
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "for_arg_.h"
#include<list>

#define var_new__(name,val) var_new_(jsq_,qu,name.c_str(),val,false,false,false)

int new_array0__(void* qu,char*head1,int well_i,int argc,va_list argv,int i1=1){
	if(!qu||!head1)
		return -1;
	string head=head1;
	int i2=1;
	string name;
	char buf[32];
	int err;
	for (int i = 0; i < argc; ++i){
		char*s = va_arg(argv, char*);
		if(!s)
			return -2;
		if(i==argc-1&&!s[0]&&i2==1)
			break;
		name=head+kw_dian_+i2s__(i1,buf);
		if(well_i>1){
			name+=kw_dian_;
			name+=i2s__(i2,buf);
		}
		if((err=var_new__(name,s)))
			return err;
		if(++i2>well_i){
			i2=1;
			i1++;
		}
	}
	/*name=head+"-1";
	if((err=var_new__(name,i2s__(i1-1,buf))))
		return err;
	name=head+"-2";
	if((err=var_new__(name,i2s__(well_i,buf))))
		return err;*/
	name=head+kw_length_;
	if((err=var_new__(name,i2s__(i1-1,buf))))
		return err;
	name=head+kw_length_+"2";
	if((err=var_new__(name,i2s__(well_i,buf))))
		return err;
	return 0;
}

dlle___ int dlln___(new_array__)(void* qu,char*head1,int well_i,int argc,...){
    va_list argv;
    va_start(argv, argc);
    int ret=new_array0__(qu,head1,well_i,argc,argv);
    va_end(argv);
    return ret;
}

dlle___ int dlln___(add_to_array__)(void* qu,char*head1,int well_i,int argc,...){
	if(!qu||!head1)
		return -1;
    int i1=1;
    {
		string name=head1+kw_length_;
		const char*val=var_get_(jsq_,qu,name.c_str());
		/*if(!val){
			name=head1;
			name+="-1";
			val=var_get_(jsq_,qu,name.c_str());
		}*/
		if(val)
			i1=s2i__(val)+1;
    }

    va_list argv;
    va_start(argv, argc);
    int ret=new_array0__(qu,head1,well_i,argc,argv,i1);
    va_end(argv);
    return ret;
}

dlle___ int dlln___(array_find__)(void* qu,char*head1,int argc,...){
	if(!qu||!head1)
		return -1;
	list<const char*> lst;
	_for_args( argc )
		/*if(!s)
			return -2;*/
		lst.push_back(s);
	_next_args

	string name;
	char buf[32];
	const char*val;
	name=head1;
	name+=kw_length_;
	val=var_get_(jsq_,qu,name.c_str());
	if(!val)
		return -1;
	int len=s2i__(val);
	name=head1;
	name+=kw_length_;
	name+='2';
	val=var_get_(jsq_,qu,name.c_str());
	if(!val)
		return -1;
	int len2=s2i__(val);
	for(int i1=1;i1<=len;i1++){
		int i2=1;
		bool all=true;
		for(list<const char*>::iterator li=lst.begin();li!=lst.end();li++,i2++){
			const char*s1=*li;
			if(!s1)
				continue;
			if(i2>len2)
				break;
			name=head1;
			name+=kw_dian_;
			name+=i2s__(i1,buf);
			if(len2>1){
				name+=kw_dian_;
				name+=i2s__(i2,buf);
			}
			val=var_get_(jsq_,qu,name.c_str());
			if(!val)
				return -2;
			if(string(s1)!=val){
				all=false;
				break;
			}
		}
		if(all)
			return i1;
	}
	return 0;
}
