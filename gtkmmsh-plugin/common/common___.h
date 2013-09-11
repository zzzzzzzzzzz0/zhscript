/*
 * common___.h
 *
 *  Created on: 2010-11-4
 *      Author: zzzzzzzzzzz
 */

#ifndef common____H_
#define common____H_

#include <plugin_base___.h>

class common___: public plugin_base___ {
private:
	Gtk::Window* w__(std::deque<Glib::ustring>* p,size_t i);
public:
	common___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "一般";}
	int version__(){return 1;}
};

#endif /* common____H_ */
