/*
 * mkdir.cpp
 *
 *  Created on: 2012-8-25
 *      Author: zzzzzzzzzzz
 */
#include <sys/stat.h>
#include "def1.h"
dlle___ int dlln___(existdir__)(char*filename);

dlle___ int dlln___(mkdir__)(char* filename){
	if(!filename)
		return 0;
	for(int i=0;filename[i];i++){
		char c=filename[i];
		if((c=='/'||c=='\\')&&i>0){
			filename[i]=0;
			int ret=0;
			if(!dlln___(existdir__)(filename))
				ret=mkdir(filename,0755);
			filename[i]=c;
			if(ret!=0)
				return 0;
		}
	}
	return 1;
}
