/*
 * exist.cpp
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */
#include "def1.h"
#include <sys/stat.h>
#include <stdio.h>

#include "call_util.h"
#include<string>
using namespace std;

long st_mode__(char*filename){
	struct stat64 buf;
	if(stat64(filename,&buf)==-1)
		return -1;
	return buf.st_mode;
}

dlle___ int dlln___(exist__)(char*filename){
	long m=st_mode__(filename);
	if(m==-1)
		return 0;
	if(S_ISREG(m))
		return 1;
	return 0;
}

dlle___ int dlln___(existdir__)(char*filename){
	long m=st_mode__(filename);
	if(m==-1)
		return 0;
	if(S_ISDIR(m))
		return 1;
	return 0;
}
