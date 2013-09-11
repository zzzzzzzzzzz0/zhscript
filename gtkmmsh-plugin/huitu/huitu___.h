/*
 * huitu___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef HUITU____H_
#define HUITU____H_

#include <plugin_base___.h>

class huitu___: public plugin_base___ {
public:
	huitu___(shell___*sh,direct___ d):plugin_base___(sh,d){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "绘图";}
	int version__(){return 1;}
};

#endif /* HUITU____H_ */
