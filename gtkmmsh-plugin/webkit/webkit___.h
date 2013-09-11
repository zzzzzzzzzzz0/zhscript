/*
 * webkit___.h
 *
 *  Created on: 2010-12-30
 *      Author: zzzzzzzzzzz
 */

#ifndef webkit____H_
#define webkit____H_

#include <plugin_base___.h>
#include <webkit/webkit.h>

class webkit___: public plugin_base___ {
private:
#ifdef ver_3_
	void element__(WebKitWebView* wwv,std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji);
#endif
public:
	webkit___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){
		return "webkit"
#ifdef ver_3_
				"3"
#endif
				;
	}
	int version__(){return 5;}
};

#endif /* webkit____H_ */
