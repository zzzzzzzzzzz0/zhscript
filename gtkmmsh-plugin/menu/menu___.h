/*
 * menu___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef menu____H_
#define menu____H_

#include <plugin_base___.h>

class menu___: public plugin_base___ {
public:
	menu___(shell___*sh,direct___ d):plugin_base___(sh,d){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "菜单";}
	int version__(){return 1;}
};

#endif /* menu____H_ */
