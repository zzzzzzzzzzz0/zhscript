/*
 * only_name.cpp
 *
 *  Created on: 2010-11-23
 *      Author: zzzzzzzzzzz
 */
#include<string>
using namespace std;
#include"def1.h"
#include"call_util.h"
#include <sys/stat.h>


string s__(long i, const string& s1) {
	string s;
	int i3 = s1.size();
	int i1 = (int)(i % i3);
	s = s1[i1] + s;
	long i2 = i / i3;
	if (i2 > 0) {
		s = s__(i2, s1) + s;
	}
	return s;
}

dlle___ void only_name__(char*buf,long siz,char*dir,char*name){
	if(!dir||!name)
		return;
	string name1=name;
	size_t i;
	i=name1.rfind('/');
	if(i!=string::npos){
		name1=name1.substr(i+1);
	}
	string dir1=dir;
	i=dir1.rfind('/');
	if(i==string::npos||i!=dir1.size()-1)
		dir1+='/';
	struct stat info;
	if (lstat((dir1+name1).c_str(), &info) == 0) {
		i=name1.rfind('.');
		string s1,s2;
		char c;
		if(i!=string::npos && i>0){
			s2=name1.substr(0,i);
			s1=name1.substr(i);
			c=name1[i-1];
		}else{
			s2=name1;
			c=name1[name1.size()-1];
		}
		string s4;
		long l;
		if (c >= '0' && c <= '9') {
			s4 = "abcdefghijklmnopqrstuvwxyz";
			l = 0;
		} else {
			s4 = "0123456789";
			l = 1;
		}
		for (;; l++) {
			string s3 = s__(l, s4);
			name1 = s2 + s3 + s1;
			if (lstat((dir1+name1).c_str(), &info) != 0) {
				break;
			}
		}
	}
	cpy__(buf,(dir1+name1).c_str(),siz);
}
