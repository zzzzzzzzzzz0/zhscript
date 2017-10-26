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

dlle___ int exist2__(char*filename, char typ){
	long m=st_mode__(filename);
	if(m==-1)
		return 0;
	switch(typ) {
	case 'f':
		if(S_ISREG(m))
			return 1;
		break;
	case 'd':
		if(S_ISDIR(m))
			return 1;
		break;
	case 'c':
		if(S_ISCHR(m))
			return 1;
		break;
	case 'b':
		if(S_ISBLK(m))
			return 1;
		break;
	case 'p':
		if(S_ISFIFO(m))
			return 1;
		break;
	case 'l':
		if(S_ISLNK(m))
			return 1;
		break;
	case 's':
		if(S_ISSOCK(m))
			return 1;
		break;
#ifdef S_ISWHT
	case 'w':
		if(S_ISWHT(m))
			return 1;
		break;
#endif
		break;
	}
	return 0;
}

dlle___ int dlln___(exist__)(char*filename){
	return exist2__(filename, 'f');
}

dlle___ int dlln___(existdir__)(char*filename){
	return exist2__(filename, 'd');
}
