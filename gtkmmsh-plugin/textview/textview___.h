/*
 * textview___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef textview____H_
#define textview____H_

#include <plugin_base___.h>

class textview___: public plugin_base___ {
private:
	int insert__(std::deque<Glib::ustring>* p,size_t start);
	Gtk::TextView* tv__(std::deque<Glib::ustring>* p,size_t i);
public:
	textview___(shell___*sh,direct___ d):plugin_base___(sh,d){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "文本框";}
	int version__(){return 3;}
};

#endif /* textview____H_ */
