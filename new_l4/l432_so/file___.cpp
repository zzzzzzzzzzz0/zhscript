/*
 * file___.cpp
 *
 *  Created on: 2009-12-12
 *      Author: zzzzzzzzzzz
 */

#include "file___.h"
#include<fstream>
#include<algorithm>
#include<iostream>
#include "path.h"
#include "errinfo.h"

file___ file_;

file___::file___() {
}

file___::~file___() {
}

static void add__(const string& path,list<string>* ls){
	string buf;
	if(!get_path__(path,buf))
		return;
	if(find(ls->begin(),ls->end(),buf)!=ls->end())
		return;
	ls->push_back(buf);
}

void file___::add_path__(const string& path){
	add__(path,&path_);
}

void file___::add_path1__(const string& path){
	add__(path,&path1_);
}

static void name0__(const string& filename,string& ret,ifstream*& f,list<string>& ls){
	for(list<string>::iterator li=ls.begin();li!=ls.end();++li) {
		string s=*li+filename;
		if(*(f=new ifstream(s.c_str()))){
			ret=s;
			break;
		}
		delete f;
		f=NULL;
	}
}

int file___::name__(const string& filename,string& ret){
	if(filename.empty())
		return errinfo_open_;
	ifstream* f=NULL;
	name0__(filename,ret,f,path1_);
	if(f==NULL){
		if(*(f=new ifstream(filename.c_str())))
			ret=filename;
		else{
			if(f){
				delete f;
				f=NULL;
			}
			name0__(filename,ret,f,path_);
			if(f==NULL)
				return errinfo_open_;
		}
	}
	delete f;
	return 0;
}

int file___::get__(const string& filename,string& filename1,string& ret){
	err_.del__();
	int err=name__(filename,filename1);
	if(err){
		err_<<filename;
		return err;
	}
	ifstream* f=new ifstream(filename1.c_str());

	streampos o=f->tellg();
	f->seekg(0,ios::end);
	int bufsiz=f->tellg();
	f->seekg(o);
	char* buf=new char[bufsiz+1];
	if(!buf){
		err_<<filename;
		return errinfo_new_;
	}
	f->read(buf,bufsiz);
	buf[bufsiz]=0;

	f->close();
	delete f;

	ret=buf;
	delete buf;

	return 0;
}
