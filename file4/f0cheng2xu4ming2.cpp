#ifndef WIN32
#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdlib.h>
#include<string>
#endif
using namespace std;
#include"f0lu4shang4.h"

#include"def1.h"

dlle___
const void cheng2xu4ming2___(char* buf,long bufsiz,char*ming2){
#ifdef WIN32
	if(f0zai4(ming2)!=NULL){
		int i;
		for(i=0;ming2[i];i++){
			if(i==0 && ming2[i]=='.')
				break;
			if(ming2[i]=='\\' || ming2[i]=='/'){
				i=-1;
				break;
			}
		}
		if(i==-1)
			buf[0]=0;
		else{
			GetCurrentDirectory(bufsiz,buf);
			lstrcat(buf,"\\");
		}
		lstrcat(buf,ming2);
	}else{
		ming2=f0lu4shang4("PATH",ming2,buf);
		if(ming2==NULL){
			delete buf;
			return NULL;
		}
	}
#else
	struct stat info;
	if (lstat(ming2, &info) == 0) {
		ming2 = realpath(ming2, buf);
	} else {
		ming2 = f0lu4shang4("PATH", ming2, buf);
	}
	if (ming2 == NULL) {
		buf[0]=0;
		return;
	}
	lstat(ming2, &info);
	if (S_ISLNK(info.st_mode)) {
		int i = readlink(ming2, buf, bufsiz);
		if (i < 0) {
			//perror("readlink() error");
			return;
		}
		buf[i] = 0;
	}
#endif
}
