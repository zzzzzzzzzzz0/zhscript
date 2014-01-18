/*
 * cairog_shell___.cpp
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#include "cairog_shell___.h"
#include "sh-base/extern.h"
#include "sh-base/extern2.h"
#include "gif_surface___.h"

view___* cairog_shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	return new cairog_view___(scrolled2, window);
}

bool cairog_shell___::api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret) {
	try {
		if(p->size() >= 2){
			const string& p0 = s__(p,0);
			const string& p1 = s__(p,1);
			if(p1 == "动画源") {
				if(p->size() > 2) {
					gif_surface___ *image;
					if(sscanf(p0.c_str(), "%ld", &image)) {
						const string& p2 = s__(p,2);
						if(p2 == "有更") {
							l2s__(image->next__(), buf);
							return true;
						}
						if(p2 == "末尾") {
							l2s__(image->is_end__(), buf);
							return true;
						}
						if(p2 == "间隔") {
							l2s__(image->delay_time__(), buf);
							return true;
						}
						if(p2 == "宽") {
							l2s__(image->w__(), buf);
							return true;
						}
						if(p2 == "高") {
							l2s__(image->h__(), buf);
							return true;
						}
						err_buzhichi__(p2, p1.c_str());
					}
					return true;
				}
				l2s__((long)new gif_surface___(p0.c_str()), buf);
				return true;
			}
			if(p1 == "源") {
				l2s__((long)cairo_image_surface_create_from_png(p0.c_str()), buf);
				return true;
			}
			cairog_view___* v;
			int page_num;
			if(p1 == "刷新") {
				v = (cairog_view___*)get_view__(p0, page_num, p1);
				if(!v)
					return true;
				GdkWindow* w1 =
					#ifdef no_gtk_2_
					gtk_widget_get_window(v->widget__())
					#else
					v->widget__()->window
					#endif
					;
				gdk_window_invalidate_rect (w1, NULL, FALSE);
				//gdk_flush
				return true;
			}
			if(p1 == "绘图") {
				v = (cairog_view___*)get_view__(p0, page_num, p1, false);
				if(!v)
					return true;
				v->huitu_ = s__(p,2);
				return true;
			}
		}
		return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
	} catch(...) {
		return false;
	}
}
