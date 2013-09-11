/*
 * nostdw___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef nostdw____H_
#define nostdw____H_

#include <plugin_base___.h>

class nostdw___: public plugin_base___ {
public:
	nostdw___(shell___*sh,direct___ d):plugin_base___(sh,d){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "非标准窗口";}
	int version__(){return 1;}
private:
	Glib::RefPtr<Gdk::Pixbuf> pb_;
	Gtk::Window* ww__(std::deque<Glib::ustring>* p,int i);
};

#endif /* nostdw____H_ */
