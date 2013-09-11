/*
 * inotify.cpp
 *
 *  Created on: 2010-11-30
 *      Author: zzzzzzzzzzz
 */

#include"def1.h"
#include <sys/inotify.h>
#include <unistd.h>
#include <stdio.h>

dlle___ int init__(){
	return inotify_init();
}

dlle___ int add_watch__(int fd,const char*path,uint32_t mask){
    return inotify_add_watch(fd, path, mask);
}

dlle___ int rm_watch__(int fd, uint32_t wd){
    return inotify_rm_watch(fd, wd);
}

dlle___ int for__(int fd,callback2___ cb,void* jsq,void* shangji,const char* src){
	int len, index;
#define MAX_BUF_SIZE 1024
    char buffer[MAX_BUF_SIZE];
    struct inotify_event *event;
    int err=0;
    char num[16];

    while((len = read(fd, buffer, MAX_BUF_SIZE))){
        index = 0;
        while(index < len){
            event = (struct inotify_event *)(buffer+index);
            sprintf(num,"%d",event->mask);
            if(event->len>0){
				if(!cb(jsq,shangji,&err,src,false,2,num,event->name))
					return err;
            }else{
				if(!cb(jsq,shangji,&err,src,false,1,num))
					return err;
            }
            index += sizeof(struct inotify_event)+event->len;
        }
    }
    return 0;
}

dlle___ int close__(int fd){
    return close(fd);
}
