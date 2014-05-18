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

class cairog_view___ : public view___ {
public:
	string huitu_;

	gif_surface___ * gif_;
	double gif_sx_, gif_sy_;
	string gif_code_;

	cairog_view___(GtkWidget* scrolled2, void* window);
	void set_gif__(gif_surface___ * gif, double sx, double sy, const char*code) {
		gif_ = gif;
		gif_sx_ = sx;
		gif_sy_ = sy;
		gif_code_ = code;
	}
};

#endif /* CAIROG_WINDOW____H_ */
