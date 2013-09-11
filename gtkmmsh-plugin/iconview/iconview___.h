/*
 * iconview___.h
 *
 *  Created on: 2010-9-12
 *      Author: zzzzzzzzzzz
 */

#ifndef ICONVIEW____H_
#define ICONVIEW____H_

#include <plugin_base___.h>
#include "../imagecache/imagecache_def.h"

class iconview___: public plugin_base___ {
private:
	imagecache___ ic_;
	void* ic_arg1_;
	int pix_limit_width_,pix_limit_height_;
	bool pix_limit_aspect_;
public:
	iconview___(shell___*sh,direct___ de):plugin_base___(sh,de){
		pix_limit_width_=-1;
		pix_limit_height_=-1;
		pix_limit_aspect_=true;
		ic_=0;
	}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "图标夹";}
	int version__(){return 2;}

	Glib::RefPtr<Gdk::Pixbuf> pix__(const string& filename){
		Glib::RefPtr<Gdk::Pixbuf> pb;
		if(ic_)
			pb=ic_(ic_arg1_,filename,pix_limit_width_,pix_limit_height_,pix_limit_aspect_);
		return pb;
	}
};

#endif /* ICONVIEW____H_ */
