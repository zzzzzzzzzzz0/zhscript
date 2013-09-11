#include<stdio.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<string.h>
#ifdef WIN32
#include <io.h>
#define F_OK 0
#else
#include <unistd.h>
#endif

#if !defined(f0zai4_lstat) && !defined(f0zai4_access)
#error f0zai4 lstat or access
#endif

char* f0zai4(char*lu4jing4){
  #ifdef f0zai4_print
  printf("#%s\n",lu4jing4);
  #endif
  #ifdef f0zai4_lstat
  struct stat info;
  if (
#ifdef WIN32
	  stat
#else
	  lstat
#endif
	  (lu4jing4, &info) == 0)
  #endif
  #ifdef f0zai4_access
  if(access(lu4jing4,F_OK)==0)
  #endif
  {
    return lu4jing4;
  }
  return NULL;
}
char* f0lu4shang4(char*huan2jing4,char*ming2,char*lu4jing4){
  char*PATH=getenv(huan2jing4);
  //printf("%s\n",PATH);
  if(PATH==NULL){
    return NULL;
  	}
  bool wan2=false,xing2=false;
  for(size_t i=0,i1=0;;i++){
    if(i>=strlen(PATH)){
      wan2=true;
      xing2=true;
    		}
    char c=PATH[i];
    if(c==
#ifdef WIN32
		';'
#else
		':'
#endif
		){
      xing2=true;
    		}
    if(xing2){
      if(i1>0){
        if(lu4jing4[i1-1]!='/' && lu4jing4[i1-1]!='\\'){
          lu4jing4[i1++]=
#ifdef WIN32
		'\\'
#else
			  '/'
#endif
			  ;
        				}
      			}
      lu4jing4[i1]=0;
      strcat(lu4jing4,ming2);
      if(f0zai4(lu4jing4)!=NULL)
        return lu4jing4;
      if(wan2)
        break;
      xing2=false;
      i1=0;
    }else{
      lu4jing4[i1++]=c;
    		}
  		}
  return NULL;
}
