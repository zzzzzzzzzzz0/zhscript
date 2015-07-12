/*
 * gif_surface___.h
 *
 *  Created on: 2013-3-12
 *      Author: zzzzzzzzzzz
 */

#ifndef GIF_SURFACE____H_
#define GIF_SURFACE____H_
#include <gtk/gtk.h>
#include <string>
using namespace std;
#include "arg___.h"

class gif_surface___ {
private:
	GdkPixbufAnimation* anim_;
	GdkPixbufAnimationIter *iter_;
	GdkPixbuf *pixbuf_;
public:
	double sx_, sy_, hudu_, px_, py_;
	string end_code_, next_code_;
	arg___ next_code_arg_;
	bool pause_;

	gif_surface___(const char* file);
	virtual ~gif_surface___();
	GdkPixbuf *pixbuf__() {return pixbuf_;}
	int w__();
	int h__();
	int delay_time__();
	bool next__();
	bool is_end__();
};

#endif /* GIF_SURFACE____H_ */
