/*
 * plugin_base___.h
 *
 *  Created on: 2010-9-11
 *      Author: zzzzzzzzzzz
 */

#ifndef PLUGIN_BASE____H_
#define PLUGIN_BASE____H_
#include"shell.h"

typedef const char* (*direct___)(shell___* sh,int cmd,...);

class plugin_base___{
protected:
public:
	shell___* sh_;
	direct___ d_;
	plugin_base___(shell___* sh,direct___ d){
		sh_=sh;
		d_=d;
	}
	virtual ~plugin_base___(){}

	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) = 0;
	virtual void on__(int event) = 0;

	virtual const char* name__() = 0;
	virtual int version__() = 0;
};

typedef plugin_base___* create___(shell___* sh,direct___ de);
typedef void destroy___(plugin_base___*);

extern "C" plugin_base___* create__(shell___* sh,direct___ de);
extern "C" void destroy__(plugin_base___* p);

#endif /* PLUGIN_BASE____H_ */
