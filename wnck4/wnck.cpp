/*
 * wnck.cpp
 *
 *  Created on: 2011-9-8
 *      Author: zzzzzzzzzzz
 */

#include <stdio.h>
#include <libwnck/libwnck.h>
#include"../new_gg/def1.h"

void* jsq_;
callback2___ cb_;

dlle___ void init__(callback2___ cb,void* jsq){
	jsq_=jsq;
	cb_=cb;
}

dlle___ void for__(int*err,void* shangji,const char*code,WnckScreen *screen){
	GList *window_l;
	char p1[32];
	for (window_l = wnck_screen_get_windows (screen); window_l != NULL; window_l = window_l->next){
		WnckWindow *window = WNCK_WINDOW (window_l->data);
		sprintf(p1,"%lx",(long)window);
		cb_(jsq_,shangji,err,code,false,1,p1);
	}
}
