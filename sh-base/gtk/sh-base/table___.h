/*
 * table___.h
 *
 *  Created on: 2014年6月2日
 *      Author: zzzzzzzzzzz
 */

#ifndef TABLE____H_
#define TABLE____H_

#include "container___.h"

class table___: public container___ {
private:
	int rows_, cols_;
	GtkWidget *table_;
	int last_row_, last_col_;
	int current_page_;
public:
	table___(int rows, int cols, void* w);
	virtual ~table___();

	static table___* new__(deque<string>* p, size_t from, void* w);
	GtkWidget* new__(GtkWidget* scrolled);

	GtkWidget* page_new__(const char* name);

	int current_page__();
};

#endif /* TABLE____H_ */
