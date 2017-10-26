/*
 * queue.cpp
 *
 *  Created on: 2016年1月22日
 *      Author: zzzzzzzzzzz
 */
#include "gjks.h"

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
	p->push_back(s ? s : "NULL");
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
