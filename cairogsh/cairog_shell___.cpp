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

window___* cairog_shell___::new_window__(const char*name, bool is_main) {
	return new cairog_window___(name, is_main);
}

cairog_window___* cairog_shell___::get_window__(const string& name, int& page_num, const string& help, bool chk_can) {
	return (cairog_window___*)shell___::get_window__(name, page_num, help, chk_can);
}

bool cairog_shell___::api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret) {
	if(p->size() < 1) {
		err_buzu__();
		return true;
	}
	try {
		const string& p0 = s__(p,0);
		if(p->size() < 2){
			return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
		}
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
		cairog_window___* w;
		int page_num;
		if(p1 == "刷新") {
			w = get_window__(p0, page_num, p1);
			if(!w)
				return true;
			GdkWindow* w1 = 
				#ifdef no_gtk_2_
				gtk_widget_get_window(w->canvas__())
				#else
				w->canvas__()->window
				#endif
				;
			gdk_window_invalidate_rect (w1, NULL, FALSE);
			//gdk_flush
			return true;
		}
		if(p1 == "绘图") {
			w = get_window__(p0, page_num, p1, false);
			if(!w)
				return true;
			w->huitu_ = s__(p,2);
			return true;
		}

		return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
	} catch(...) {
		return false;
	}
}
