/*
 * err___.cpp
 *
 *  Created on: 2009-12-20
 *      Author: zzzzzzzzzzz
 */

#include "err___.h"
#include "util.h"
#include <iostream>

err___& err___::operator<<(long l){
	buf_+=l2s__(l);
	return *this;
}
