/*
 * arg___.cpp
 *
 *  Created on: 2013-4-12
 *      Author: zzzzzzzzzzz
 */

#include "arg___.h"

void arg___::del__() {
	if(argv_) {
		delete argv_;
		argv_ = NULL;
	}
}

void arg___::add__(const char* s) {
	del__();
	args_.push_back(s);
}
void arg___::add__(const string& s) {
	add__(s.c_str());
}

void arg___::ins__(const char* s) {
	del__();
	args_.push_front(s);
}
void arg___::ins__(const string& s) {
	ins__(s.c_str());
}

int arg___::c__() {
	return args_.size();
}

const char** arg___::v__() {
	if(!argv_) {
		size_t len = args_.size();
		if(len > 0) {
			argv_ = new const char*[len];
			for(size_t i = 0; i < len; i++)
				argv_[i] = args_[i].c_str();
		}
	}
	return argv_;
}

void arg___::clear__() {
	del__();
	args_.clear();
}

arg___::arg___() {
	argv_ = NULL;
}

arg___::~arg___() {
	clear__();
}
