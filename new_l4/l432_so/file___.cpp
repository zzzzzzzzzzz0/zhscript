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

bool file___::add_path2__(const string& path) {
	string path2;
	if(!get_path__(mk_abs_path__(path, path2) ? path2 : path, path2))
		return false;
	if(path2_.size() > 0 && path2_.front() == path2) {
		//cout << "\t" << path2 << endl;
		return false;
	}
	path2_.push_front(path2);
	return true;
}

void file___::add_path1__(const string& path){
	string path2;
	add__(mk_abs_path__(path, path2) ? path2 : path, &path1_);
}

static void name0__(const string& filename,string& ret,ifstream*& f,list<string>& ls){
	if(filename[0] == '/')
		return;
	for(list<string>::iterator li=ls.begin();li!=ls.end();++li) {
		string s=*li+filename;
		//cout << filename << "\t" << *li << endl;
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
	for(;;) {
		name0__(filename,ret,f,path1_);
		if(f!=NULL)
			break;

		name0__(filename,ret,f,path2_);
		if(f!=NULL)
			break;

		if(*(f=new ifstream(filename.c_str()))) {
			ret=filename;
			break;
		}
		if(f){
			delete f;
			f=NULL;
		}

		name0__(filename,ret,f,path_);
		if(f!=NULL)
			break;

		return errinfo_open_;
	}
	delete f;
	return 0;
}

#ifdef ver_android_
extern int aam_get_file__(const char* filename, string& ret);
#endif

int file___::get__(const string& filename,string& filename1, bool is_src,string& ret){
	err_.del__();
	int err;
#ifdef ver_android_
	if((err = aam_get_file__(filename.c_str(), ret))){
		err_ << filename;
		return err;
	}
#else
	if((err=name__(filename,filename1))){
		err_<<filename;
		return err;
	}
	ifstream* f=new ifstream(filename1.c_str());

	//streampos
	ifstream::pos_type o=f->tellg();
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
	if(is_src && ret.length() > 2 && ret[0] == '#' && ret[1] == '!') {
		size_t i = ret.find('\n');
		if(i != string::npos) {
			ret = ret.substr(i + 1);
		}
	}
	delete buf;
#endif

	return 0;
}
