/*
 * type.cpp
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */
#include<string>
using namespace std;
#define strstart_ 0
#include<stdio.h>
#include<stdlib.h>

#include "for_arg_.h"
#include "def1.h"
#include"call_util.h"

char* getfile___(char* filename){
	FILE* f;
	char* s;
	f=fopen(filename,"rb");
	if(f==NULL)
		return NULL;
	if(fseek(f, 0L, SEEK_END) == 0) {
		long l = ftell(f);
		if(l > 0) {
			rewind(f);
			s=(char*)malloc(l+1);
			if(s!=NULL) {
				if(fread(s,1,l,f)!=l){
					free(s);
					return NULL;
				}
				s[l]=0;
			}
		} else {
			string s2;
			int c;
			for(; (c = fgetc(f)) != EOF;)
				s2.push_back(c ? c : '\n');
			s=(char*)malloc(s2.length() + 1);
			if(s != NULL) {
				size_t i = 0;
				for(; i < s2.length(); i++)
					s[i] = s2[i];
				s[i] = 0;
			}
		}
	} else
		s = NULL;
	fclose(f);
	return s;
}

void file__(FILE* tfs,long l_begin,long l_end,string&buf1,bool hex_get){
	if(!tfs)
		return;
	long lo=0;
	if(l_begin>0){
		if(fseek(tfs,l_begin,SEEK_SET)==0)
			lo=l_begin;
	}
	unsigned char buf[512];
	bool b=false;
	for(;!b;){
		int siz=fread(buf,1,sizeof(buf),tfs);
		if(siz<=0)
			break;
		for(int i1=0;i1<siz;i1++,lo++){
			if(lo<l_begin)
				continue;
			if(l_end>=0){
				if(lo>l_end){
					b=true;
					break;
				}
			}

			unsigned char c = buf[i1];
			if(hex_get){
				char buf2[16];
				sprintf(buf2,"%02X",c);
				buf1+=buf2;
			}else {
				buf1+= c ? c : '\n';
			}
		}
	}
}

dlle___ void dlln___(type__)(char**addr_ret,int argNum,...){
	int is_set=0;
	bool cmd_end=false;
	bool hex_get=false;
	bool is_p=false;
	long l_begin=-1,l_end=-1;
	string buf1;
	_for_args(argNum)
		if(!cmd_end){
			if(is_set){
				switch(is_set){
				case 'b':
					sscanf(s,"%ld",&l_begin);
					break;
				case 'e':
					sscanf(s,"%ld",&l_end);
					break;
				}
				is_set=0;
				continue;
			}
			string s1=s;
			if(s1=="-o"||s1=="-b"||s1=="-e"){
				is_set=s1[1+strstart_];
				continue;
			}
			if(s1=="-hex"){
				hex_get=!hex_get;
				continue;
			}
			if(s1=="-c"){
				is_p=!is_p;
				continue;
			}
			if(s1=="--"){
				cmd_end=true;
				continue;
			}
		}
		bool is_in=(s[0]=='-'&&!s[1]);
		if(hex_get||is_in || l_begin != -1 || l_end != -1){
			FILE* tfs;
			if(is_in)
				tfs=stdin;
			else if(is_p)
				tfs=popen(s,"r");
			else
				tfs=fopen(s,"rb");
			file__(tfs,l_begin,l_end,buf1,hex_get);
			if(tfs){
				if(is_p)
					pclose(tfs);
				else
					fclose(tfs);
			}
		}else{
			char* s1=getfile___(s);
			if (s1!=NULL){
				buf1+=s1;
				free(s1);
			}
		}
	_next_args
	*addr_ret=dup__(buf1.c_str());
}
