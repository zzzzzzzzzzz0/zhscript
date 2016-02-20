/*
 * api_w2.cpp
 *
 *  Created on: 2016年2月13日
 *      Author: zzzzzzzzzzz
 */
#include "shell___.h"
#include "extern.h"
#include "extern2.h"

bool shell___::api_w3__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	const string& p0=(*p)[0];
	const string& p1=(*p)[1];
	window___* w;
	int page_num;

	if(p1=="图标"){
		if(err_buzu2__(p, 3))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		const string& p2=(*p)[2];
		GdkPixbuf* pb;
		if(p->size() >= 4) {
			pb = gtk_icon_theme_load_icon(gtk_icon_theme_get_default(), p2.c_str(), s2i__((*p)[3]),
					GTK_ICON_LOOKUP_USE_BUILTIN, NULL);
		} else {
			pb=gdk_pixbuf_new_from_file(p2.c_str(),NULL);
		}
		if(pb) {
			gtk_window_set_icon_name(w->window__(), p2.c_str());
			gtk_window_set_icon(w->window__(),pb);
			return true;
		}
		err_wufa__(p1,p2.c_str());
		return true;
	}
	if(p1=="不透明度"){
		if(err_buzu2__(p, 3))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_set_opacity(w->window__(),s2f__((*p)[2]));
		return true;
	}
	if(p1=="鼠标穿透"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
#ifndef ver_gtk3_
		GdkRegion *region = gdk_region_new ();
		gdk_window_input_shape_combine_region (w->widget__()->window, region, 0, 0);
		gdk_region_destroy (region);
#endif
		return true;
	}
	if(p1=="地址"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		l2x__((long)w->window__(), buf);
		return true;
	}
	if(p1=="xid"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		get_xid__(w->widget__(), buf);
		return true;
	}
	if(p1=="类名"){
		if(err_buzu2__(p, 3))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		const string& cc = (*p)[p->size() > 3 ? 3 : 2];
		gtk_window_set_wmclass(w->window__(), (*p)[2].c_str(), cc.c_str());
		return true;
	}
	return false;
}


