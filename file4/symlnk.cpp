/*
 * symlnk.cpp
 *
 *  Created on: 2012-4-10
 *      Author: zzzzzzzzzzz
 */

#include "def1.h"
#include<unistd.h>
#include<string>

dlle___ void dlln___(symlnk_get__)(char*buf,int siz,char*path){
	int len=readlink(path,buf,siz);
	if(len<0)
		return;
	buf[len]=0;
}

dlle___ int dlln___(symlnk_create__)(const char* path, const char* name, bool force){
	if(!path || !name || !path[0] || !name[0]) {
		return 0;
	}
	std::string name1 = name;
	if(name1[name1.size() - 1] == '/') {
		std::string path1 = path;
		for(int i = path1.size() - 1; i >= 0; i--) {
			if(path1[i] == '/') {
				name1 += path + i + 1;
				name = name1.c_str();
				break;
			}
		}
	}
	if(force)
		unlink(name);
	int err=symlink(path,name);
	return err;
}
