/*
 * gif_surface___.cpp
 *
 *  Created on: 2013-3-12
 *      Author: zzzzzzzzzzz
 */

#include "gif_surface___.h"

gif_surface___::gif_surface___(const char* file) {
	anim_ = gdk_pixbuf_animation_new_from_file(file, NULL);
	iter_ = NULL;
	pixbuf_ = NULL;
	if(anim_) {
		iter_ = gdk_pixbuf_animation_get_iter(anim_, NULL);
		//pixbuf_ = gdk_pixbuf_animation_get_static_image(anim_);
		if(iter_)
			pixbuf_ = gdk_pixbuf_animation_iter_get_pixbuf(iter_);
	}

	sx_ = sy_ = 1;
	hudu_ = 0;
	px_ = py_ = 0;
	end_code_ = next_code_ = "";
	pause_ = false;
}

gif_surface___::~gif_surface___() {
}

int gif_surface___::w__() {
	if(!anim_)
		return 0;
	return gdk_pixbuf_animation_get_width(anim_);
}
int gif_surface___::h__() {
	if(!anim_)
		return 0;
	return gdk_pixbuf_animation_get_height(anim_);
}
int gif_surface___::delay_time__() {
	if(!iter_)
		return -1;
	return gdk_pixbuf_animation_iter_get_delay_time (iter_);
}
bool gif_surface___::next__() {
	if(!iter_)
		return false;
	bool b = gdk_pixbuf_animation_iter_advance(iter_, NULL);
	if(b)
		pixbuf_ = gdk_pixbuf_animation_iter_get_pixbuf(iter_);
	return b;
}
bool gif_surface___::is_end__() {
	if(!iter_)
		return true;
	return gdk_pixbuf_animation_iter_on_currently_loading_frame(iter_);
}

#include "arg___.cpp"
