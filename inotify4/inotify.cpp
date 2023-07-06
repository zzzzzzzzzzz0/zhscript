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
#include <string>
#include "../gjke4/rust.h"

dlle___ int init__(){
	return inotify_init();
}

dlle___ int close__(int fd){
	return close(fd);
}

dlle___ int add_watch__(int fd,const char*path,uint32_t mask){
	return inotify_add_watch(fd, path, mask);
}

dlle___ int rm_watch__(int fd, uint32_t wd){
	return inotify_rm_watch(fd, wd);
}

#define mask_len_ 12
static const char *mask_[mask_len_] = {
	"访问",
	"修改",
	"属性",
	"关闭写",
	"关闭没写",
	"打开",
	"移动从",
	"移动至",
	"建立",
	"删除",
	"自删除",
	"自移动"
};
static void mask2s__(uint32_t mask, std::string &s) {
	s.clear();
	for(int i = 0; i < mask_len_; i++) {
		if((mask >> i) & 1) {
			s += "+";
			s += mask_[i];
		}
	}
	if(!s.empty())
		s += "+";
}
dlle___ uint32_t s2mask__(char* s) {
	uint32_t ret = 0;
	if(s) for(int i2 = 0, i2_la = 0;; i2++) {
		char c = s[i2];
		if(!c || c == '+') {
			if(i2_la < i2) {
				s[i2] = 0;
				std::string s2 = s + i2_la;
				s[i2] = c;
				for(int i = 0; i < mask_len_; i++) {
					if(s2 == mask_[i]) {
						ret += (1 << i);
						break;
					}
				}
			}
			if(!c)
				break;
			i2_la = i2 + 1;
		}
	}
	return ret;
}

static int for__(int fd,
		callback2___ cb,
		callback2_2___ cb2,
		rust_cb___ rust_cb, rust_cb_free___ rust_f,
		void* jsq,void* shangji, void* ce,
		const char* src){
	int len, index;
#define MAX_BUF_SIZE 1024
	char buffer[MAX_BUF_SIZE];
	struct inotify_event *event;
	int err=0;
	char num[16];
	std::string s;

	while((len = read(fd, buffer, MAX_BUF_SIZE))){
		index = 0;
		while(index < len){
			event = (struct inotify_event *)(buffer+index);
			sprintf(num,"%d",event->mask);
			mask2s__(event->mask, s);
			if(rust_cb) {
				const char*argv[] = {s.c_str(),event->name};
				rust_f(rust_cb(ce, shangji, &err, '0', src, event->len>0 ? 2 : 1, argv));
				if(err)
					return err;
			} else {
				if(event->len>0){
					if(cb2) {
						cb2(jsq,shangji,&err, ce, src,false, 0, 2,s.c_str(),event->name);
						if(err)
							return err;
					} else {
						if(!cb(jsq,shangji,&err,src,false,2,num,event->name))
							return err;
					}
				}else{
					if(cb2) {
						cb2(jsq,shangji,&err, ce, src,false, 0, 1,s.c_str());
						if(err)
							return err;
					} else {
						if(!cb(jsq,shangji,&err,src,false,1,num))
							return err;
					}
				}
			}
			index += sizeof(struct inotify_event)+event->len;
		}
	}
	return 0;
}
dlle___ int for__(int fd,callback2___ cb,void* jsq,void* shangji,const char* src){
	return for__(fd, cb, 0, 0, 0, jsq, shangji, 0, src);
}
dlle___ int for2__(int fd,callback2_2___ cb,void* jsq,void* shangji, void* ce, const char* src){
	return for__(fd, 0, cb, 0, 0, jsq, shangji, ce, src);
}
dlle___ int rust_for__(int fd,rust_cb___ cb, rust_cb_free___ f, void* env, void* ret,const char* src){
	return for__(fd, 0, 0, cb, f, 0, ret, env, src);
}

