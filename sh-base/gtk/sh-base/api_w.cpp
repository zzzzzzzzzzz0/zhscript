/*
 * api_w.cpp
 *
 *  Created on: 2016年2月12日
 *      Author: zzzzzzzzzzz
 */
#include "shell___.h"
#include "extern.h"
#include "extern2.h"
#include "util3.h"

extern s1___* window_destroy_s1_;

bool shell___::api_w__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	const string& p0=(*p)[0];
	const string& p1=(*p)[1];
	window___* w;
	int page_num;

	if(p1=="标题"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(p->size()<3){
			cpy__(buf, gtk_window_get_title (w->window__()), siz);
		}else
			gtk_window_set_title (w->window__(), (*p)[2].c_str());
		return true;
	}
	if(p1=="焦点"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(p->size() >= 3) {
			const string& p2 = (*p)[2];
			if(p2 == "盒") {
				gtk_widget_grab_focus(w->c__()->box__(page_num));
				return true;
			}
			err_wufa__(p1, p2.c_str());
			return true;
		}
		view___*v = w->c__()->view__(page_num);if(!v) return true;
		gtk_widget_grab_focus(v->widget__());
		return true;
	}
	if(p1=="移动"){
		if(err_buzu2__(p, 4))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		int x,y;
		gtk_window_get_position(w->window__(),&x,&y);
		x=s2i__((*p)[2],x);
		y=s2i__((*p)[3],y);
		if(p->size() > 4) {
			gtk_window_move(w->window__(),x,y);
			const string& eo_code = (*p)[4];
			if(!eo_code.empty()) {
				gint w1 = 0, h1 = 0;
				gtk_window_get_size (w->window__(), &w1, &h1);
				string arg0 = "";
				int x2 = x, y2 = y;
				if(x<0) {
					arg0 += "x-";
					x2 = 0;
				} else {
					int x3 = gdk_screen_width() - w1;
					if(x > x3) {
						arg0 += "x+";
						x2 = x3;
					}
				}
				if(y<0) {
					arg0 += "y-";
					y2 = 0;
				} else {
					int y3 = gdk_screen_height() - h1;
					if(y > y3) {
						arg0 += "y+";
						y2 = y3;
					}
				}
				if(!arg0.empty()) {
					char x1[8], y1[8];
					sprintf(x1, "%d", x2);
					sprintf(y1, "%d", y2);
					const char* argv[] = {arg0.c_str(), x1, y1};
					call4__(eo_code.c_str(), NULL, 3, argv);
				}
			}
		} else {
			if(x<0 && x >= -gdk_screen_width())
				x+=gdk_screen_width();
			if(y<0 && y >= -gdk_screen_height())
				y+=gdk_screen_height();
			gtk_window_move(w->window__(),x,y);
		}
		return true;
	}
	if(p1 == "x" || p1 == "y") {
		w=get_window__(p0,page_num,p1);if(!w)return true;
		int x,y;
		gtk_window_get_position(w->window__(),&x,&y);
		l2s__(p1 == "x" ? x : y, buf);
		return true;
	}
	if(p1=="活动"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		l2s__(gtk_window_is_active(w->window__()),buf);
		return true;
	}
	if(p1=="遍历"){
		if(err_buzu2__(p, 3))
			return true;
		w = get_window__(p0,page_num,p1);if(!w)return true;
		const string& p2 = (*p)[2];
		if(p->size() >= 4) {
			if(p2 == "盒") {
				foreach__(w->c__()->box__(page_num), (*p)[3].c_str(), ce, shangji);
				return true;
			}
			wufa__(3, p);
			return true;
		}
		w->c__()->for__(p2.c_str(), ce, shangji);
		return true;
	}
	if(p1=="工具提示"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(buzu__(2, p))
			return true;
		GtkWidget* box = w->c__()->box__(page_num);
		if(box) {
			GtkWidget* w2 = get__(box, s2i__((*p)[2]));
			if(w2) {
				if(p->size()<4){
					cpy__(buf, gtk_widget_get_tooltip_markup(GTK_WIDGET(w2)), siz);
				}else
					gtk_widget_set_tooltip_markup(GTK_WIDGET(w2), (*p)[3].c_str());
				return true;
			}
			wufa__(2, p);
			return true;
		}
		wufa__(1, p);
		return true;
	}
	if(p1=="敏感"){
		w = get_window__(p0,page_num,p1);if(!w)return true;
		if(p->size() > 2) {
			gtk_widget_set_sensitive(w->widget__(), bool__((*p)[2]));
		} else {
			l2s__(gtk_widget_get_sensitive(w->widget__()), buf);
		}
		return true;
	}
	if(p1=="光标形状"){
		w = get_window__(p0,page_num,p1);if(!w)return true;
		if(w->cursor_) {
			//gdk_cursor_destroy(w->cursor_);
			gdk_cursor_unref(w->cursor_);
		}
		if(p->size() <= 2)
			w->cursor_ = NULL;
		else {
			const string& p2 = (*p)[2];
			int i;
			if(p2 == "移动")
				i = GDK_FLEUR;
			else if(sscanf(p2.c_str(), "%d", &i) != 1) {
				err_buzhichi__(p1, p2.c_str());
				return true;
			}
			w->cursor_ = gdk_cursor_new((GdkCursorType)i);
			if(!w->cursor_) {
				err_buzhichi__(p1, p2.c_str());
				return true;
			}
		}
		gdk_window_set_cursor(gtk_widget_get_window(w->widget__()), w->cursor_);
		//gdk_flush();
		return true;
	}
	if(p1 == "宽度" || p1 == "高度") {
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gint w1 = 0, h1 = 0;
		gtk_window_get_size (w->window__(), &w1, &h1);
		l2s__(p1 == "宽度" ? w1 : h1, buf);
		return true;
	}
	if(p1=="大小" || p1 == "定大小"){
		if(err_buzu2__(p, 4))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		const string &w2 = (*p)[2], &h2 = (*p)[3];
		int w1, h1;
		w1 = s2i__(w2, gdk_screen_width());
		h1 = s2i__(h2, gdk_screen_height());
		if(p1=="大小") {
			gtk_window_set_default_size (w->window__(), w1, h1);
			gtk_window_resize (w->window__(), w1, h1);
		} else
			gtk_widget_set_size_request(w->widget__(), w1, h1);
		return true;
	}
#ifdef ver_gtk3_
	if(p1 == "最小宽度" || p1 == "最小高度"){
		if(err_buzu2__(p, 3))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW(w->view__(page_num)->outer_scrolled__());
		if(!sw) return true;
		if(p1 == "最小宽度") {
			gtk_scrolled_window_set_min_content_width(sw, s2i__((*p)[2]));
		} else {
			gtk_scrolled_window_set_min_content_height(sw, s2i__((*p)[2]));
		}
		return true;
	}
#endif
	if(p1=="关闭"){
		string page_num2;
		w = get_window__(p0,page_num,p1, true, &page_num2);
		if(!w)return true;
		if(page_num < 0 && !page_num2.empty()) {
			err_wufa__(p1,p0.c_str());
			return true;
		}
		w->c__()->close__(page_num);
		return true;
	}

	for(size_t i = 1; i < p->size();) {
		const string& pi = (*p)[i];
		int k;
		for(;;) {
			if(pi == "激活") {k = 1; break;}
			if(pi == "隐藏") {k = 2; break;}
			if(pi == window_destroy_s1_->src2__()) {k = 3; break;}
			if(pi == "最大化") {k = 4; break;}
			if(pi == "取消最大化") {k = 5; break;}
			if(pi == "最小化") {k = 6; break;}
			if(pi == "取消最小化") {k = 7; break;}
			if(pi == "恢复") {k = 8; break;}
			if(pi == "全屏") {k = 9; break;}
			if(pi == "取消全屏") {k = 10; break;}
			if(pi == "置顶") {k = 11; break;}
			if(pi == "取消置顶") {k = 12; break;}
			if(pi == "所有桌面") {k = 13; break;}
			if(pi == "取消所有桌面") {k = 14; break;}
			if(pi == "居中") {k = 15; break;}
			if(pi == "只有关闭钮") {k = 16; break;}
			if(pi == "禁大小") {k = 17; break;}
			if(pi == "无标签") {k = 18; break;}
			if(pi == "无边框") {k = 19; break;}
			if(pi == "无修饰") {k = 20; break;}
			if(pi == "不可关闭") {k = 21; break;}
			if(pi == "框地址") {k = 22; break;}
			if(i == 1) return false; else {err_buzhichi__(pi); return true;}
		}
		if(i == 1) {w=get_window__(p0,page_num,pi);if(!w)return true;}
		switch(k) {
		case 1: gtk_window_present(w->window__()); w->c__()->set_page__(page_num); break;
		case 2: w->hide__(); break;
		case 3: w->destroy__(); break;
		case 4: gtk_window_maximize (w->window__()); break;
		case 5: gtk_window_unmaximize (w->window__()); break;
		case 6: gtk_window_iconify (w->window__()); break;
		case 7: gtk_window_deiconify (w->window__()); break;
		case 8: gtk_window_present (w->window__()); break;
		case 9: gtk_window_fullscreen(w->window__()); break;
		case 10: gtk_window_unfullscreen(w->window__()); break;
		case 11: case 12: gtk_window_set_keep_above (w->window__(), k == 11); break;
		case 13: gtk_window_stick(w->window__()); break;
		case 14: gtk_window_unstick(w->window__()); break;
		case 15: gtk_window_set_position(w->window__(),GTK_WIN_POS_CENTER); break;
		case 16: gtk_window_set_type_hint(w->window__(), GDK_WINDOW_TYPE_HINT_UTILITY); break;
		case 17: gtk_window_set_resizable(w->window__(), bool__(p, ++i)); break;
		case 18: w->c__()->show_tabs__(bool__(p, ++i)); break;
		case 19: w->c__()->show_border__(bool__(p, ++i)); break;
		case 20: gtk_window_set_decorated(w->window__(), bool__(p, ++i)); break;
		case 21:
		{
			GtkWidget* b=w->c__()->close_button__(page_num);
			if(!b){
				err_wufa__(pi, p0.c_str());
				return true;
			}
			//gtk_widget_set_sensitive (b,false);
			gtk_widget_hide (b);
			break;
		}
		case 22: l2x__((long)w->c__()->nth_page2__(page_num), buf); break;
		}
		i++;
	}
	return true;
}
