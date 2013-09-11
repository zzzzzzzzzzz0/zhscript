/*
 * dlg___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef dlg____H_
#define dlg____H_

#include <plugin_base___.h>

class dlg___: public plugin_base___ {
public:
	dlg___(shell___*sh,direct___ d):plugin_base___(sh,d){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "对话框";}
	int version__(){return 1;}
};

#endif /* dlg____H_ */
