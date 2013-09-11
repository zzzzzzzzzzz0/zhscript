/*
 * feiqi___.h
 *
 *  Created on: 2010-11-4
 *      Author: zzzzzzzzzzz
 */

#ifndef FEIQI____H_
#define FEIQI____H_

#include <plugin_base___.h>

class feiqi___: public plugin_base___ {
public:
	feiqi___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji);
	void on__(int event){}
	const char* name__(){return "废弃了的隧道字";}
	int version__(){return 1;}
};

#endif /* FEIQI____H_ */
