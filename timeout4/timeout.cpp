/*
 * timeout.cpp
 *
 *  Created on: 2013-2-16
 *      Author: zzzzzzzzzzz
 */

#include <stdio.h>
#include <algorithm>
#include "def1.h"
#include "l4/keyword.h"
#include "for_arg_.h"
#include "item___.h"

void* jsq_;
void* main_qu_;
callback3_2___ cb3_;
l4_err_out___ l4_err_out_;

void call4__(const char* code, const char* name, int argc, const char** argv) {
	int err;
	const char*ret = cb3_(jsq_, main_qu_, &err, NULL, code, false, name, argc, argv, 0);
	switch(err) {
	case jieshiqi_err_go_ + keyword_exit_:
		break;
	default:
		l4_err_out_(jsq_, ret, err, 1);
	}
}

dlle___ void init__(void* jsq, callback3_2___ cb3,
		l4_err_out___ l4_err_out,
		void* main_qu) {
	jsq_ = jsq;
	cb3_ = cb3;
	l4_err_out_ = l4_err_out;
	main_qu_ = main_qu;
}

deque<item___*> timeouts_;

//boolean timeout_cb__(gpointer data)
int timeout_cb__(void* data) {
	((item___*)data)->on__();
	return true;
}

class timeout_find___ {
private:
	char* name_;
	item___* t_;
	char type_;
public:
	timeout_find___(char* name) {
		name_ = name;
		type_ = 'n';
	}
	timeout_find___(item___* t) {
		t_ = t;
		type_ = 't';
	}
    bool operator () (item___* t) {
    	switch(type_) {
    	case 't':
    		return t == t_;
    	}
        return t->name__() == name_;
    }
};

item___* timeout_find__(char* name) {
	deque<item___*>::iterator i = find_if(timeouts_.begin(), timeouts_.end(), timeout_find___(name));
	if(i == timeouts_.end())
		return NULL;
	return *i;
}

void timeout_remove2__(item___* t) {
	deque<item___*>::iterator i = find_if(timeouts_.begin(), timeouts_.end(), timeout_find___(t));
	if(i == timeouts_.end())
		return;
	timeouts_.erase(i);
	delete t;
}

dlle___ void timeout_add__(char* name, char* time, bool is_loop, char* code, int argc, ...) {
	item___* t = timeout_find__(name);
	if(t)
		timeout_remove2__(t);
	t = new item___(name, is_loop);
	_for_args( argc )
		t->arg_.add__(s);
	_next_args

	//guint
	unsigned int time1 = 1000;
	string time2 = time;
	if(time2.size() > 0) {
		int x = 1;
		switch(time2[time2.size() - 1]) {
		case 'h':
			x *= 60;
		case 'm':
			x *= 60;
		case 's':
			x *= 1000;
			time2.erase(time2.size() - 1, 1);
			break;
		}
		float time3;
		if(sscanf(time2.c_str(), "%f", &time3) == 1) {
			time1 = time3 * x;
		}
	}

	t->code__(code && code[0] ? code : name);
	t->id__(g_timeout_add(time1, timeout_cb__, t));
	timeouts_.push_back(t);
}

dlle___ void timeout_remove__(char* name) {
	item___* t = timeout_find__(name);
	if(t)
		timeout_remove2__(t);
}

dlle___ void timeout_pause__(char* name, bool b) {
	item___* t = timeout_find__(name);
	if(t)
		t->pause__(b);
}

#include "arg___.cpp"
