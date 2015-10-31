/*
 * simple___.h
 *
 *  Created on: 2014年6月1日
 *      Author: zzzzzzzzzzz
 */

#ifndef SIMPLE____H_
#define SIMPLE____H_

#include "../container___.h"

class simple___: public container___ {
public:
	simple___(void* w) : container___(w) {}
	virtual ~simple___();

	GtkWidget* new__(GtkWidget* scrolled) {return scrolled;}

	void close__(int page_num);
};

#endif /* SIMPLE____H_ */
