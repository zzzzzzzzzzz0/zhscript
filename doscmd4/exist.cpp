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

long st_mode__(char*filename, bool has_l){
	struct stat64 buf;
	if(has_l) {
		if(lstat64(filename,&buf)==-1)
			return -1;
	} else {
		if(stat64(filename,&buf)==-1)
			return -1;
	}
	return buf.st_mode;
}

dlle___ int exist2__(char*filename, char typ, bool has_l = true){
	long m=st_mode__(filename, has_l);
	if(m==-1)
		return 0;
	switch(typ) {
	case 'f': if(S_ISREG(m)) return 1; break;
	case 'd': if(S_ISDIR(m)) return 1; break;
	case 'c': if(S_ISCHR(m)) return 1; break;
	case 'b': if(S_ISBLK(m)) return 1; break;
	case 'p': if(S_ISFIFO(m)) return 1; break;
	case 'l': if(S_ISLNK(m)) return 1; break;
	case 's': if(S_ISSOCK(m)) return 1; break;
#ifdef S_ISWHT
	case 'w': if(S_ISWHT(m)) return 1; break;
#endif
	/*default: return -1;*/
	}
	return 0;
}

int exist__(char*filename, char typ) {
	int b = exist2__(filename, typ);
	if(!b && exist2__(filename, 'l'))
		b = exist2__(filename, typ, false);
	return b;
}
dlle___ int dlln___(exist__)(char*filename){
	return exist__(filename, 'f');
}
dlle___ int dlln___(existdir__)(char*filename){
	return exist__(filename, 'd');
}
