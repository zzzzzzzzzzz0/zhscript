/*
 * cairog_window___.cpp
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#include "cairog_view___.h"
#include "sh-base/extern.h"
#include "sh-base/extern2.h"
#include "gif_surface___.h"
#include "for_arg_.h"
#include <deque>

static void callback__(cairo_t *cr, int argc, ...) {
	deque<string> p;
	_for_args( argc )
		p.push_back(s ? s : null_.c_str());
	_next_args
	try {
		const string& p0 = s__(p,0);
		if(p0 == "源") {
			long l;
			if(sscanf(s__(p,1).c_str(), "%ld", &l))
				cairo_set_source_surface(cr, (cairo_surface_t *)l, s2f__(s__(p,2)), s2f__(s__(p,3)));
			return;
		}
		if(p0 == "动画源") {
			long l;
			if(sscanf(s__(p,1).c_str(), "%ld", &l)) {
				gif_surface___ *image = (gif_surface___ *)l;
				if(image->pixbuf__()) {
					gdk_cairo_set_source_pixbuf(cr, image->pixbuf__(),
							s2f__(s__(p,2)), s2f__(s__(p,3)));
				}
			}
			return;
		}
		if(p0 == "OPERATOR_SOURCE") {
			cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
			return;
		}
		if(p0 == "OPERATOR_CLEAR") {
			cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
			return;
		}
		if(p0 == "OPERATOR_OVER") {
			cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
			return;
		}
		if(p0 == "绘制") {
			cairo_paint(cr);
			return;
		}
		if(p0 == "移") {
			cairo_move_to(cr, s2f__(s__(p,1)), s2f__(s__(p,2)));
			return;
		}
		if(p0 == "文字") {
			cairo_show_text (cr, s__(p,1).c_str());
			return;
		}
		if(p0 == "文字字体") {
			cairo_select_font_face (cr, s__(p,1).c_str(), CAIRO_FONT_SLANT_NORMAL,
									   CAIRO_FONT_WEIGHT_BOLD);
			return;
		}
		if(p0 == "文字大小") {
			cairo_set_font_size (cr, s2f__(s__(p,1)));
			return;
		}
		if(p0 == "缩放") {
			cairo_scale(cr, s2f__(s__(p,1)), s2f__(s__(p,2)));
			return;
		}
		err_buzhichi__(p0);
	} catch(...) {
	}
}

static char cr_[32], callback_[64];
static const char* argv_[] = {callback_, cr_, };
static gboolean expose_event__(GtkWidget * widget, GdkEventExpose * event, gpointer data) {
	cairog_view___* w = (cairog_view___*)data;
	cairo_t *cr = gdk_cairo_create(
		#ifdef ver_gtk3_
		gtk_widget_get_window(widget)
		#else
		widget->window
		#endif
		);

	if(w->gif_) {
		gif_surface___* gif = w->gif_;
		cairo_scale(cr, gif->sx_, gif->sy_);
		cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);

		if(gif->hudu_ > 0 || gif->hudu_ < 0) {
			double x = 0.5 * gif->w__() + gif->px_, y = 0.5 * gif->h__() + gif->py_;
			cairo_translate (cr, x, y);
			cairo_rotate (cr, gif->hudu_);
			cairo_translate (cr, -x, -y);
		}

		if(gif->pixbuf__()) {
			gdk_cairo_set_source_pixbuf(cr, gif->pixbuf__(), gif->px_, gif->py_);
		}
		cairo_paint(cr);
	} else {
		if(!w->huitu_.empty()) {
			sprintf(cr_, "%ld", (long)cr);
			if(w->addr_fmt_ == 16)
				sprintf(callback_, "/%lx/${l%ld}-Z", (long)callback__, (long)cr);
			else
				sprintf(callback_, "/%lu/-${l%ld}-Z", (long)callback__, (long)cr);
			call4__(w->huitu_.c_str(), NULL, 2, argv_, 0);
		}
	}
	cairo_destroy(cr);
	return FALSE;
}

cairog_view___::cairog_view___(GtkWidget* scrolled2, void* window):view___(scrolled2, window) {
	widget_ = gtk_drawing_area_new ();
	gtk_container_add (GTK_CONTAINER (scrolled2), widget_);
	gtk_widget_show(widget_);
	g_signal_connect(G_OBJECT(widget_),
#ifdef ver_gtk3_
		"draw"
#else
		"expose-event"
#endif
		, G_CALLBACK(expose_event__), this);

	gif_ = NULL;
}
