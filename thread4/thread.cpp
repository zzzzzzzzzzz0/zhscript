/*
 * thread.cpp
 *
 *  Created on: 2011-3-9
 *      Author: zzzzzzzzzzz
 */
#include<string>
#include<iostream>
using namespace std;

//osx 10.9 need
#include <unistd.h>

#include "def1.h"
#include "for_arg_.h"
#include "l4/keyword.h"

callback3___ callback3_;
void* jsq_;

dlle___ void dlln___(init__)(void* jsq,
		callback3___ cb3)
{
	jsq_=jsq;
	callback3_=cb3;
}

struct thread_data___{
	void* shangji_;
	const char*code_;
	int argc_;
	const char*argv_[32];
};

void* pthread1__(void *arg){
	thread_data___*data=(thread_data___*)arg;
	thread_data___*d=new thread_data___;
	d->shangji_=data->shangji_;
	d->argc_=data->argc_;
	string code=data->code_;
	d->code_=code.c_str();
	string s[32];
	for(int i=0;i<d->argc_;i++){
		s[i]=data->argv_[i];
		d->argv_[i]=s[i].c_str();
	}
	int err;
	callback3_(jsq_,d->shangji_,&err,d->code_,false,d->argc_,d->argv_,0);
	delete d;
	return NULL;
}

#include <pthread.h>
dlle___ int dlln___(thread_eval__)(void* shangji,const char*code,int argc,...){
	thread_data___ data;
	data.code_=code;
	data.shangji_=shangji;
	data.argc_=argc;
	_for_args( argc )
		data.argv_[i]=s;
	_next_args

	pthread_t id1;
	int ret;
	ret = pthread_create(&id1,NULL,pthread1__,&data);
	if(ret!=0)
		return 1;
	//pthread_join(id1,NULL);
	//usleep(100);
	sleep(1);
	return 0;
}
