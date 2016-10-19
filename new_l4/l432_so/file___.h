/*
 * file___.h
 *
 *  Created on: 2009-12-12
 *      Author: zzzzzzzzzzz
 */

#ifndef FILE____H_
#define FILE____H_
#include <string>
#include <list>
using namespace std;

#include "err___.h"

class file___ {
private:
	list<string> path_,path1_, path2_;
public:
	file___();
	virtual ~file___();
	void add_path__(const string& path);
	void del_path__(const string& path){
		path_.remove(path);
	}
	void add_path1__(const string& path);
	bool add_path2__(const string& path);
	void del_path2__() {path2_.pop_front();}
	int get__(const string& filename,string& filename1, bool is_src,string& ret);
	int get__(const string& filename, bool is_src,string& ret){
		string filename1;
		return get__(filename,filename1, is_src,ret);
	}
	int name__(const string& filename,string& ret);

	err___ err_;
};

extern file___ file_;
#endif /* FILE____H_ */
