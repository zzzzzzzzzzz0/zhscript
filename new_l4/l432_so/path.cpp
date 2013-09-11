/*
 * path.cpp
 *
 *  Created on: 2010-3-12
 *      Author: zzzzzzzzzzz
 */

#include "path.h"

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
