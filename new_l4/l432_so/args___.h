/*
 * args___.h
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#ifndef ARGS____H_
#define ARGS____H_
#include <string>
#include <list>
#include<deque>
#include <iostream>
using namespace std;

#include"err___.h"
#include"errinfo.h"

class args___ {
private:
	list<string> args_;
	bool get_arg_str__(unsigned char c1,unsigned char c,const string& s,size_t& i,string& buf);
	int get_arg__(const string& s1,string& s2,list<string>::iterator& li);
	void add_arg2__(const string& cmdline,list<string>::iterator li,bool use_li);
	int get_ini_file__(list<string>::iterator& li);
public:
	args___();
	virtual ~args___();

	void set_path__(const string& s);

	string syn_file_,err_file_;
	string src_,src2_;
	bool src_is_file_;
	deque<string> params_;
	bool is_server_pages_;

	void add_arg__(int argc,char** argv,int from=0);
	void add_arg__(const string& cmdline);
	int parse_args__();

	err___ err_;
};

#endif /* ARGS____H_ */
