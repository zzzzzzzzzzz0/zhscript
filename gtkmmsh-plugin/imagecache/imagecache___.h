/*
 * imagecache___.h
 *
 *  Created on: 2010-12-26
 *      Author: zzzzzzzzzzz
 */

#ifndef imagecache____H_
#define imagecache____H_

#include <plugin_base___.h>
#include <sys/stat.h>

class item___{
private:
	Glib::RefPtr<Gdk::Pixbuf> pb_;
	bool is_stock_;
	Glib::ustring filename_;
	int pix_limit_width_;
	int pix_limit_height_;
	bool pix_limit_aspect_;
	__time_t tm_;
	__time_t tm__(const Glib::ustring& filename);
	void from_file__();
public:
	item___(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect);
	Glib::RefPtr<Gdk::Pixbuf> pb__();
};

class imagecache___: public plugin_base___ {
private:
	map<Glib::ustring,item___*> cache_;
	Glib::RefPtr<Gdk::Pixbuf> cache__(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect);
public:
	imagecache___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "图片缓存";}
	int version__(){return 3;}
	Glib::RefPtr<Gdk::Pixbuf> get__(const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect);
};

#endif /* imagecache____H_ */
