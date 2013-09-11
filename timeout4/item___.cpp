/*
 * item___.cpp
 *
 *  Created on: 2013-2-16
 *      Author: zzzzzzzzzzz
 */

#include "item___.h"
#include "extern.h"

void item___::on__() {
	if(pause_)
		return;
	if(!is_loop_)
		stop__();
	call4__(code_.c_str(), name_.c_str(), arg_.c__(), arg_.v__());
}

void item___::stop__() {
	if(id_ > 0) {
		//g_timeout_remove
		g_source_remove(id_);
		id_ = 0;
	}
}

item___::~item___() {
	stop__();
}
