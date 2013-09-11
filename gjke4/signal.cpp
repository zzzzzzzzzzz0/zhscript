/*
 * signal.cpp
 *
 *  Created on: 2013-2-12
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include <signal.h>

static string code_;
dlle___ void signal_cb__(const char*code) {
	code_ = code;
}

static void sighandler__(int signum) {
	int err;
	char signum2[16];
	const char* ret = callback_(jsq_, main_qu_, &err, NULL, code_.c_str(), false, NULL,
			1, i2s__(signum, signum2));
	switch(err) {
	case jieshiqi_err_go_ + keyword_exit_:
		break;
	default:
		l4_err_out_(jsq_, ret, err, 1);
	}
}

dlle___ void signal__(int signum) {
	signal(signum, sighandler__);
}
