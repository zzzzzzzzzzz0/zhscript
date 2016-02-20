/*
 * callback_item___.cpp
 *
 *  Created on: 2016年1月29日
 *      Author: zzzzzzzzzzz
 */

#include "callbackitem.h"
#include <deque>
#include "extern.h"
#include "extern2.h"

static deque<callback_item___*> callback_item_;

callback_item___* callback_item__(int id) {
	if(id < 1 || (size_t)id > callback_item_.size())
		return 0;
	return callback_item_[id - 1];
}

callback_item___::~callback_item___() {
}

void callback_item___::init__() {
	callback_item_.push_back(this);
	id_ = callback_item_.size();
}

void callback_item___::call__(int i, const char* arg2) {
	const char *code, *arg;
	switch(i) {
	case 1:
		code = code2_.c_str();
		arg = arg2_.c_str();
		break;
	default:
		code = code_.c_str();
		arg = arg_.c_str();
		break;
	}
	char id2[32];
	l2s__(id_, id2);
	int argc = argc_, i2 = argc_ - 1;
	const char* argv[8];
	switch(argc_) {
	case 3:
	{
		argv[0] = arg;
		argv[1] = tooltip_.c_str();
		break;
	}
	}
	if(arg2 != NULL) {
		argv[i2++] = arg2;
		argc++;
	}
	argv[i2] = id2;
	argv[argc] = 0;
	call4__(code, title_.c_str(), argc,argv,0);
}

void call_item__(int id, int i) {
	callback_item___* item = callback_item__(id);
	if(item)
		item->call__(i);
}
