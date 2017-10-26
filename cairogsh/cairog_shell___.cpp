/*
 * cairog_shell___.cpp
 *
 *  Created on: 2013-2-10
 *      Author: zzzzzzzzzzz
 */

#include "cairog_shell___.h"
#include "sh-base/extern.h"
#include "sh-base/extern2.h"

static GdkWindow* get_w__(cairog_view___* v) {
	return
	#ifdef ver_gtk3_
	gtk_widget_get_window(v->widget__())
	#else
	v->widget__()->window
	#endif
	;
}

static guint gif_timeout_ = 0;
static deque<cairog_view___*> gifs_;
static gboolean gif_timeout_cb__(gpointer data) {
	for(size_t i = 0; i < gifs_.size(); i++) {
		cairog_view___* v = gifs_[i];
		gif_surface___* gif = v->gif_;
		if(gif->pause_)
			continue;
		if(gif->is_end__() && !gif->end_code_.empty()) {
			const char* ret = call4__(gif->end_code_.c_str(), NULL, 0, NULL, 0);
			if(ret[0]=='x' && !ret[1]) {
				continue;
			}
		}
		if(gif->next__()) {
			if(!gif->next_code_.empty()) {
				call4__(gif->next_code_.c_str(), NULL,
						gif->next_code_arg_.c__(), gif->next_code_arg_.v__(), 0);
			}
			gdk_window_invalidate_rect(get_w__(v), NULL, FALSE);
		}
	}
	return true;
}
static gif_surface___ *get_gif__(unsigned i2, deque<string>* p) {
	unsigned i;
	if(sscanf(s__(p, i2).c_str(), "%u", &i)) {
		if(i < gifs_.size()) {
			return gifs_[i]->gif_;
		}
	}
	err_buzhichi__(s__(p, i2 - 1), s__(p, i2 - 2).c_str());
	return NULL;
}

view___* cairog_shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	cairog_view___* v = new cairog_view___(scrolled2, window);
	v->addr_fmt_ = addr_fmt_;
	return v;
}

bool cairog_shell___::api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret) {
	try {
		if(p->size() >= 2){
			const string& p0 = s__(p,0);
			const string& p1 = s__(p,1);
			if(p1 == "动画源") {
				if(p->size() > 2) {
					long l;
					if(sscanf(p0.c_str(), "%ld", &l)) {
						gif_surface___ *image = (gif_surface___ *)l;
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
				gdk_window_invalidate_rect (get_w__(v), NULL, FALSE);
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
			if(p1 == "gif") {
				if(p0 == "旋转") {
					gif_surface___ *gif = get_gif__(2, p);if(!gif) return true;
					gif->hudu_ = s2f__(s__(p, 3)) * M_PI/180;
					return true;
				}
				if(p0 == "暂停") {
					gif_surface___ *gif = get_gif__(2, p);if(!gif) return true;
					if(p->size() > 3)
						gif->pause_ = bool__(s__(p, 3));
					else
						gif->pause_ = !gif->pause_;
					return true;
				}
				if(p0 == "起点") {
					gif_surface___ *gif = get_gif__(2, p);if(!gif) return true;
					gif->px_ = s2f__(s__(p, 3)) * gif->sx_;
					gif->py_ = s2f__(s__(p, 4)) * gif->sy_;
					return true;
				}
				if(p0 == "代码") {
					gif_surface___ *gif = get_gif__(2, p);if(!gif) return true;
					gif->next_code_ = s__(p, 3);
					for(size_t i = 4; i < p->size(); i++) {
						gif->next_code_arg_.add__((*p)[i]);
					}
					return true;
				}
				v = (cairog_view___*)get_view__(p0, page_num, p1, false);
				if(!v)
					return true;
				const string& p2 = s__(p,2);
				long l;
				if(sscanf(p2.c_str(), "%ld", &l)) {
					v->gif_ = (gif_surface___ *)l;
					if(p->size() > 3) v->gif_->sx_ = s2f__(s__(p,3));
					if(p->size() > 4) v->gif_->sy_ = s2f__(s__(p,4));
					if(p->size() > 5) v->gif_->end_code_ = s__(p,5);
					if(p->size() > 6) v->gif_->pause_ = bool__(s__(p, 6));
					l2s__(gifs_.size(), buf);
					gifs_.push_back(v);
					if(!gif_timeout_) {
						gif_timeout_ = g_timeout_add(100, gif_timeout_cb__, NULL);
					}
				} else {
					err_buzhichi__(p2, p1.c_str());
				}
				return true;
			}
		}
		return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
	} catch(char c) {
		if(c == 's')
			return true;
		return false;
	} catch(...) {
		return false;
	}
}
