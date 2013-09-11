/*
 * tmpl___.h
 *
 *  Created on: 2010-9-12
 *      Author: zzzzzzzzzzz
 */

#ifndef TMPL____H_
#define TMPL____H_

#include <plugin_base___.h>

class tmpl___: public plugin_base___ {
private:
	Gtk::Container* cpy_tmpl__(Gtk::Container*c,Gtk::Container*c2=NULL,Gtk::Container*c4=NULL);
	Gtk::Container* tmpl_cpy__(Gtk::Container*c,Gtk::Container*c2=NULL,Gtk::Container*c4=NULL);
	int tmpl_cpy_idx_;
public:
	tmpl___(shell___*sh,direct___ de):plugin_base___(sh,de){}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "模板";}
	int version__(){return 1;}
};

#endif /* TMPL____H_ */
