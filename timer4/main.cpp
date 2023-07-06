/*
 * main.cpp
 *
 *  Created on: 2015年3月11日
 *      Author: zzzzzzzzzzz
 */

#include <algorithm>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <deque>

#include "def1.h"
#include "l4/keyword.h"
#include "item___.h"
#include "for_arg_.h"

static void* jsq_;
static void* main_qu_;
static callback3_2___ cb3_;
static l4_err_out___ l4_err_out_;

dlle___ void init__(void* jsq, callback3_2___ cb3,
		l4_err_out___ l4_err_out,
		void* main_qu) {
	jsq_ = jsq;
	cb3_ = cb3;
	l4_err_out_ = l4_err_out;
	main_qu_ = main_qu;
}

#include "../../zhscript2-lib/i2.h"
static callback4_4___ cb4_ = NULL;
dlle___ void init2__(callback4_4___ cb) {
	cb4_ = cb;
}

#include "../gjke4/rust.h"
#include "../gjke4/for_err.cpp"
static rust_cb2___     rust_cb_      = NULL;
static rust_cb_free___ rust_cb_free_;
dlle___ void rust_init__(rust_cb2___ cb, rust_cb_free___ f){
	rust_cb_ = cb;
	rust_cb_free_ = f;
}

static void call4__(const char* code, const char* name, int argc, const char** argv) {
	int err;
	const char*ret = cb3_(jsq_, main_qu_, &err, NULL, code, false, name, argc, argv, 0);
	switch(err) {
	case jieshiqi_err_go_ + keyword_exit_:
		break;
	default:
		l4_err_out_(jsq_, ret, err, 1);
	}
}

static void push__(vector<string>& v1, const vector<string>& v2) {
	for(size_t i = 0; i < v2.size(); i++)
		v1.push_back(v2[i]);
}

static bool cb4__(item___* i1, int argc, const char** argv) {
	if(rust_cb_) {
		string code = "解释【" + i1->name_ + "】下代码" + i1->code_ + "上代码" "、‘参数栈’";
		int err = 0;
		rust_cb_free_(rust_cb_(&err, '0', code.c_str(), argc, argv));
		/*if(for_err__(&err, true)) {
		}*/
		switch(err) {
		case 0:
		case jieshiqi_err_go_+keyword_continue_:
			break;
		default:
			i1->pause_ = true;
			break;
		}
		return true;
	}
	if(cb4_) {
		vector<string> args;
		for(int i = 0; i < argc; i++)
			args.push_back(argv[i]);
		push__(args, i1->args_);
		int ret = cb4_(jsq_, NULL, i1->code_.c_str(), false, i1->name_.c_str(), main_qu_, NULL, NULL, &args, NULL);
		switch(ret) {
		case 0:
			l4_err_out_(jsq_, "", jieshiqi_err_, 1);
		case -3: case -4:
			i1->pause_ = true;
			break;
		}
		return true;
	}
	return false;
}

static deque<item___*> items_;
static bool start_ = false, stop_ = false;

class find___ {
private:
	char* name_;
public:
	find___(char* name) {name_ = name;}
	bool operator () (item___* t) {return t->name_ == name_;}
};

static item___* find__(char* name) {
	deque<item___*>::iterator i = find_if(items_.begin(), items_.end(), find___(name));
	if(i == items_.end())
		return NULL;
	else
		return *i;
}

dlle___ void add__(/*int* err*/char* buf, char* type, int is_loop, char* name, int argc, ...) {
	switch(type[0]) {
	case 'd': case 0:
		break;
	default:
		//*err = 1;
		sprintf(buf, "1");
		return;
	}

	char *time = NULL, *code = NULL;
	vector<string> args;
	_for_args( argc )
		switch(i) {
		case 0:
			time = s;
			break;
		case 1:
			code = s;
			break;
		default:
			args.push_back(s ? s : "NULL");
			break;
		}
	_next_args
	if(!name || ((!code || !code[0]) && !name[0])) {
		sprintf(buf, "11");
		return;
	}

	item___* t = find__(name);
	bool is_new = false;
	if(!t) {
		t = new item___();
		is_new = true;
	}
	t->type_ = type[0];
	int err2;
	if((err2 = t->mk_time__(time))) {
		if(is_new)
			delete t;
		//*err = 200 + err2;
		sprintf(buf, "%d", 200 + err2);
		return;
	}
	t->init__();
	t->name_ = name;
	t->is_loop_ = is_loop;
	t->code_ = code && code[0] ? code : name;
	t->args_.clear();
	push__(t->args_, args);
	if(is_new)
		items_.push_back(t);
}

dlle___ void pause__(char* name, bool b) {
	item___* t = find__(name);
	if(t) {
		t->pause_ = b;
	}
}
dlle___ void reset__(char* name) {
	item___* t = find__(name);
	if(t) {
		t->i_ = 0;
	}
}

void signal__(int signo) {
	if(!start_)
		return;
	switch (signo){
	case SIGALRM:
	case SIGVTALRM:
		//signal(signo, timer__);
		break;
	default:
		return;
	}

	char d_y[8], d_m1[8], d_d[8], d_h[8], d_m[8], d_s[8], d_w[8];
	bool d_prf = false;

	for(deque<item___*>::iterator i = items_.begin(); i != items_.end(); i++) {
		if(!start_)
			break;
		item___* i1 = *i;
		switch(i1->type_) {
		case 'd': {
			if(!d_prf) {
				d_prf = true;

				time_t tt;
				tzset();
				time(&tt);
				struct tm t2;
				struct tm * t = &t2;
				localtime_r(&tt, t);
				sprintf(d_y, "%d", t->tm_year + 1900);
				sprintf(d_m1, "%d", t->tm_mon + 1);
				sprintf(d_d, "%d", t->tm_mday);
				sprintf(d_h, "%d", t->tm_hour);
				sprintf(d_m, "%d", t->tm_min);
				sprintf(d_s, "%d", t->tm_sec);
				sprintf(d_w, "%d", t->tm_wday);
			}
			const char* argv[] = {d_y, d_m1, d_d, d_h, d_m, d_s, d_w};
			if(!i1->begin__(argv))
				continue;
			if(cb4__(i1, 7, argv))
				break;
			call4__(i1->code_.c_str(), i1->name_.c_str(), 7, argv);
			break; }
		default:
			if(!i1->begin__(NULL))
				continue;
			if(cb4__(i1, 0, NULL))
				break;
			call4__(i1->code_.c_str(), i1->name_.c_str(), 0, NULL);
			break;
		}
		if(stop_) {
			stop_ = false;
			return;
		}
		i1->end__();
	}
}

dlle___ void start__() {
	signal(SIGALRM, signal__);
	signal(SIGVTALRM, signal__);

	struct itimerval it;
	it.it_interval.tv_sec = it.it_value.tv_sec = 0;
	it.it_interval.tv_usec = it.it_value.tv_usec = interval_ * 1000;
	start_ = true;
	setitimer(ITIMER_REAL, &it, NULL);
}

dlle___ void stop__() {
	stop_ = true;
	start_ = false;

	struct itimerval it;
	getitimer(ITIMER_REAL, &it);
	it.it_value.tv_usec = 0;

	for(deque<item___*>::iterator i = items_.begin(); i != items_.end();) {
		item___* i1 = *i;
		delete i1;
		i = items_.erase(i);
	}
}

static void for__(int* err, void*ce, void* qu, rust_cb___ cb, rust_cb_free___ f, char* code) {
	#define argc 6
	const char* argv[argc];
	char type[] = {0, 0}, is_loop[] = {0, 0}, is_pause[] = {0, 0};
	argv[1] = type;
	argv[2] = is_loop;
	argv[5] = is_pause;
	for(deque<item___*>::iterator i = items_.begin(); i != items_.end(); i++) {
		item___* i1 = *i;
		argv[0] = i1->name_.c_str();
		type[0] = i1->type_;
		is_loop[0] = i1->is_loop_ + '0';
		argv[3] = i1->time2_.c_str();
		argv[4] = i1->code_.c_str();
		is_pause[0] = i1->pause_ + '0';
		if(cb) {
			f(cb(ce, qu, err, '0', code, argc, argv));
		} else {
			cb3_(jsq_, qu, err, ce, code, false, NULL, argc, argv, 0);
		}
		if(for_err__(err, cb))
			break;
	}
}
dlle___ void for__(int* err, void*ce, void* qu, char* code) {
	for__(err, ce, qu, NULL, NULL, code);
}
dlle___ void rust_for__(int*err, rust_cb___ cb, rust_cb_free___ f, void* env, void* ret, char*code) {
	for__(err, env, ret, cb, f, code);
}
