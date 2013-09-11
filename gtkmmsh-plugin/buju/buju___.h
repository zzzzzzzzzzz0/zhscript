/*
 * buju___.h
 *
 *  Created on: 2010-11-4
 *      Author: zzzzzzzzzzz
 */

#ifndef buju____H_
#define buju____H_

#include <plugin_base___.h>

class buju___: public plugin_base___ {
private:
	Gtk::Window* ww__(std::deque<Glib::ustring>* p,int i);
public:
	buju___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "布局";}
	int version__(){return 1;}
};

#endif /* buju____H_ */
