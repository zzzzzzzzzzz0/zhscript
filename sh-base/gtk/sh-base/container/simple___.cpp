/*
 * simple___.cpp
 *
 *  Created on: 2014年6月1日
 *      Author: zzzzzzzzzzz
 */

#include "simple___.h"

simple___::~simple___() {
}

#include "../window___.h"

void simple___::close__(int page_num){
	window___* w = (window___*)window_;
	w->destroy__();
}
