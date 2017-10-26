/*
 * callback_item___.cpp
 *
 *  Created on: 2016年1月29日
 *      Author: zzzzzzzzzzz
 */

#include "callbackitem.h"
#include "extern.h"
#include "extern2.h"

const char* callback_item___::get__(const deque<string> &a, int i) {
	if(i < 0 || i >= a.size())
		return "";
	return a[i].c_str();
}
void* callback_item___::data__(int i) {
	if(i < 0 || i >= datas_.size())
		return NULL;
	return datas_[i];
}
void callback_item___::data__(int i, void* data) {
	for(int i2 = datas_.size(); i2 <= i; i2++)
		add_data__(NULL);
	callback_item___::datas_[i] = data;
}

void callback_item___::call__(int i, const char* arg2, const char* code3, void* shangji, void* ce) {
	const char *code, *arg;
	switch(i) {
	case 32:
		code = code__(2);
		arg = arg__(0);
		break;
	case 3:
	case 2:
		code = code3;
		arg = arg__(i - 2);
		break;
	case 1:
	case 0:
		code = code__(i);
		arg = arg__(i);
		break;
	default:
		return;
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
	int err;
	call4__(&err, ce, code, title_.c_str(), shangji, argc, argv);
}

void call_item__(int id, int i, const char* code3, void* shangji, void* ce) {
	callback_item___* item = callback_item__(id);
	if(item)
		item->call__(i, NULL, code3, shangji, ce);
}

callback_item___::~callback_item___() {
}

static deque<callback_item___*> callback_item_;

callback_item___* callback_item__(int id) {
	if(id < 1 || (size_t)id > callback_item_.size())
		return 0;
	return callback_item_[id - 1];
}

void callback_item___::init__(bool has_id) {
	i_ = 0;

	if(has_id) {
		callback_item_.push_back(this);
		id_ = callback_item_.size();
	} else
		id_ = 0;
}
