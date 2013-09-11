/*
 * timeout___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef timeout____H_
#define timeout____H_

#include <plugin_base___.h>

class timeout___: public plugin_base___ {
public:
	timeout___(shell___*sh,direct___ d):plugin_base___(sh,d){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "定时器";}
	int version__(){return 1;}
private:
	std::deque<void*>timeouts_;
	void* timeout_find__(const Glib::ustring& name);
};

#endif /* timeout____H_ */
