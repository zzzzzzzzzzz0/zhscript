/*
 * cairog_window___.h
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#ifndef CAIROG_WINDOW____H_
#define CAIROG_WINDOW____H_

#include "sh-base/window___.h"

class cairog_view___ : public view___ {
public:
	string huitu_;
	cairog_view___(GtkWidget* scrolled2, void* window);
};

#endif /* CAIROG_WINDOW____H_ */
