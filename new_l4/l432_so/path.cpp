/*
 * path.cpp
 *
 *  Created on: 2010-3-12
 *      Author: zzzzzzzzzzz
 */

#include "path.h"
#include <unistd.h>

bool get_path__(const string& path,string&buf){
	size_t i=path.rfind('/');
	if(i==string::npos)
		i=path.rfind('\\');
	if(i==string::npos){
		buf.clear();
		return false;
	}
	buf=path.substr(0,i+1);
	return true;
}

bool mk_abs_path__(const string& path, string& path2) {
	if(!path.empty() && path[0] == '/')
		return false;
	char cwd[260];
	if(!getcwd(cwd, sizeof(cwd)))
		return false;
	path2 = cwd;
	path2 += "/" + path;
	return true;
}
