/*
 * symlnk.cpp
 *
 *  Created on: 2012-4-10
 *      Author: zzzzzzzzzzz
 */

#include "def1.h"
#include<unistd.h>

dlle___ void dlln___(symlnk_get__)(char*buf,int siz,char*path){
	int len=readlink(path,buf,siz);
	if(len<0)
		return;
	buf[len]=0;
}

dlle___ int dlln___(symlnk_create__)(const char* path, const char* name, bool force){
	if(force)
		unlink(name);
	int err=symlink(path,name);
	return err;
}
