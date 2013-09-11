/*
 * gif_surface___.h
 *
 *  Created on: 2013-3-12
 *      Author: zzzzzzzzzzz
 */

#ifndef GIF_SURFACE____H_
#define GIF_SURFACE____H_
#include <gtk/gtk.h>

class gif_surface___ {
private:
	GdkPixbufAnimation* anim_;
	GdkPixbufAnimationIter *iter_;
	GdkPixbuf *pixbuf_;
public:
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
