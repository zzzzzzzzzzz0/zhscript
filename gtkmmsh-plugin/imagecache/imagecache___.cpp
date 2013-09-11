/*
 * imagecache___.cpp
 *
 *  Created on: 2010-12-26
 *      Author: zzzzzzzzzzz
 */

#include "imagecache___.h"
#include"plugin_def.h"
#include "util.cpp"

GdkPixbuf *obtain_pixbuf_from_stock(const gchar *stock_id, GtkIconSize is)
{
	GtkWidget *widget;
	GdkPixbuf *pixbuf;

	widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	pixbuf = gtk_widget_render_icon(widget, stock_id, is, NULL);
	gtk_widget_destroy(widget);

	return pixbuf;
}

static Glib::ustring cachename__(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect){
	Glib::ustring name=filename;
	char buf[16];
	name+="|";
	name+=l2s__(pix_limit_width,buf);
	name+="|";
	name+=l2s__(pix_limit_height,buf);
	name+="|";
	name+=l2s__(pix_limit_aspect,buf);
	return name;
}

__time_t item___::tm__(const Glib::ustring& filename){
	struct stat64 stt;
	if(stat64(filename.c_str(),&stt)==-1)
		return 0;
	else
		return stt.st_mtime;
}

void item___::from_file__(){
	if(g_file_test(filename_.c_str(), G_FILE_TEST_EXISTS)){
		//cout<<filename_<<","<<pix_limit_width_<<","<<pix_limit_height_<<","<<pix_limit_aspect_<<endl;
		if(pix_limit_width_>0&&pix_limit_height_>0)
			pb_=Gdk::Pixbuf::create_from_file(filename_,pix_limit_width_,pix_limit_height_,pix_limit_aspect_);
		else
			pb_=Gdk::Pixbuf::create_from_file(filename_);
	}
}

item___::item___(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect){
	filename_=filename;
	pix_limit_width_=pix_limit_width;
	pix_limit_height_=pix_limit_height;
	pix_limit_aspect_=pix_limit_aspect;
	is_stock_=(filename[0]=='-');
	if(is_stock_){
		GtkIconSize is = GTK_ICON_SIZE_MENU;
		int i = 1;
		char c = filename[1];
		if(filename[2] == '-' && c >= '0' && c<= '9') {
			is = (GtkIconSize)(c - '0');
			i = 3;
		}
		GdkPixbuf *p=obtain_pixbuf_from_stock(filename.c_str() + i, is);
		if(p){
			if(pix_limit_width>0&&pix_limit_height>0)
				p=gdk_pixbuf_scale_simple(p,pix_limit_width,pix_limit_height,GDK_INTERP_BILINEAR);
			pb_ = Glib::wrap(p);
		}
	}
	else
		from_file__();
	tm_=is_stock_?0:tm__(filename);
}

Glib::RefPtr<Gdk::Pixbuf> item___::pb__(){
	if(is_stock_){
	}else if(tm__(filename_)!=tm_){
		from_file__();
	}
	return pb_;
}

Glib::RefPtr<Gdk::Pixbuf> imagecache___::cache__(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect){
	Glib::RefPtr<Gdk::Pixbuf> pb;
	if(filename.size()<1)
		return pb;
	item___* item=new item___(filename,pix_limit_width,pix_limit_height,pix_limit_aspect);
	Glib::ustring name=cachename__(filename,pix_limit_width,pix_limit_height,pix_limit_aspect);
	cache_[name]=item;
	return item->pb__();
}

Glib::RefPtr<Gdk::Pixbuf> imagecache___::get__(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect){
	map<Glib::ustring,item___*>::iterator mi=cache_.find(cachename__(filename,pix_limit_width,pix_limit_height,pix_limit_aspect));
	if(mi!=cache_.end()){
		item___*item=mi->second;
		return item->pb__();
	}
	return cache__(filename,pix_limit_width,pix_limit_height,pix_limit_aspect);
}

Glib::RefPtr<Gdk::Pixbuf> imagecache__(imagecache___* ic,const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect){
	return ic->get__(filename,pix_limit_width,pix_limit_height,pix_limit_aspect);
}

int imagecache___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		sprintf(buf,"%lx|%lx",(long)imagecache__,(long)this);
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new imagecache___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
