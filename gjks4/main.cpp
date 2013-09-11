/*
 * main.cpp
 *
 *  Created on: 2013-1-23
 *      Author: zzzzzzzzzzz
 */

#include <string>
#include <deque>
#include <vector>
#include <stdio.h>
#include "def1.h"
#include "for_arg_.h"
#include "call_util.cpp"
using namespace std;

callback3_2___ cb_;
void* jsq_;

dlle___ void init__(void* jsq, callback3_2___ cb) {
	jsq_=jsq;
	cb_=cb;
}

static bool ok__(void* p) {
	return p != NULL;
}

dlle___ deque<string>* new_queue__() {
	return new deque<string>();
}

dlle___ void delete_queue__(deque<string>* p) {
	if(!ok__(p))
		return;
	delete p;
}

dlle___ void queue_push__(deque<string>* p, const char* s) {
	if(!ok__(p))
		return;
	p->push_back(s);
}

dlle___ void queue_pop__(char** addr_ret, deque<string>* p) {
	if(!ok__(p) || p->size() == 0)
		return;
	*addr_ret = dup__(p->front().c_str());
	p->pop_front();
}

dlle___ void queue_push_front__(deque<string>* p, const char* s) {
	if(!ok__(p))
		return;
	p->push_front(s);
}

dlle___ void queue_pop_back__(char** addr_ret, deque<string>* p) {
	if(!ok__(p) || p->size() == 0)
		return;
	*addr_ret = dup__(p->back().c_str());
	p->pop_back();
}

dlle___ vector<vector<string>*>* new_list__() {
	return new vector<vector<string>*>();
}

dlle___ void clear_list__(vector<vector<string>*>* p) {
	if(!ok__(p))
		return;
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		delete v;
	}
	p->clear();
}

dlle___ void delete_list__(vector<vector<string>*>* p) {
	clear_list__(p);
	if(!ok__(p))
		return;
	delete p;
}

dlle___ size_t list_length__(vector<vector<string>*>* p, int i1) {
	if(!ok__(p))
		return 0;
	i1--;
	if(i1 < 0)
		return p->size();
	if((size_t)i1 >= p->size())
		return 0;
	return (*p)[i1]->size();
}

dlle___ void list_add__(vector<vector<string>*>* p, int colnum, int argc, ...) {
	if(!ok__(p) || colnum <= 0)
		return;
	int i1 = colnum;
	vector<string>* v;
	_for_args( argc )
		if(i1 >= colnum) {
			v = new vector<string>();
			p->push_back(v);
			i1 = 0;
		}
		v->push_back(s);
		i1++;
	_next_args
}

dlle___ void list_foreach__(int* err, void*ce, void* shangji,
		bool has_num, vector<vector<string>*>* p, char* code)
{
	if(!ok__(p) || !code) {
		*err = 1;
		return;
	}
	size_t argc = 0;
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		if(argc < v->size())
			argc = v->size();
	}
	const char**argv = new const char*[argc + 1];
	char num[16];
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		argc = v->size();
		size_t add = 0;
		if(has_num) {
			sprintf(num, "%d", i1 + 1);
			argv[0] = num;
			add++;
		}
		for(size_t i = 0; i < argc; i++)
			argv[i + add] = (*v)[i].c_str();
		cb_(jsq_, shangji, err, ce, code, false, NULL, argc + add, argv, 0);
		if(*err)
			break;
	}
	delete argv;
}

dlle___ void list_get__(int* err, char** addr_ret, vector<vector<string>*>* p, char* i1i2) {
	if(!ok__(p)) {
		*err = 1;
		return;
	}
	int i1, i2;
	if(sscanf(i1i2, "%d,%d", &i1, &i2) != 2) {
		*err = 2;
		return;
	}
	i1--;
	i2--;
	if(i1 < 0 || (size_t)i1 >= p->size()) {
		return;
	}
	vector<string>* v = (*p)[i1];
	if(i2 < 0 || (size_t)i2 >= v->size()) {
		return;
	}
	*addr_ret = dup__((*v)[i2].c_str());
}

dlle___ void list_find__(char* buf, vector<vector<string>*>* p, char* s, int i_only) {
	if(!ok__(p))
		return;
	i_only--;
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		for(size_t i = 0; i < v->size(); i++) {
			if(i_only < 0 || i == (size_t)i_only) {
				if((*v)[i] == s) {
					i1++;
					if(i_only < 0)
						sprintf(buf, "%d,%d", i1, i + 1);
					else
						sprintf(buf, "%d", i1);
					return;
				}
			}
		}
	}
}
