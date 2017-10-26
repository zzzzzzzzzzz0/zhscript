/*
 * cairog_window___.h
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#ifndef CAIROG_WINDOW____H_
#define CAIROG_WINDOW____H_

#include "sh-base/window___.h"
#include "gif_surface___.h"

#define M_PI 3.1415926535897932384626

class cairog_view___ : public view___ {
public:
	string huitu_;
	int addr_fmt_;

	gif_surface___ * gif_;

	cairog_view___(GtkWidget* scrolled2, void* window);
};

#endif /* CAIROG_WINDOW____H_ */
