/*
 * cairog_window___.h
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#ifndef CAIROG_WINDOW____H_
#define CAIROG_WINDOW____H_

#include "sh-base/window___.h"

class cairog_window___ : public window___ {
private:
	GtkWidget *canvas_;
public:
	string huitu_;
	cairog_window___(const char* name, bool is_main = false);
	GtkWidget* new__(window_flag___* flag);
	GtkWidget* canvas__() {return canvas_;}

};

#endif /* CAIROG_WINDOW____H_ */
