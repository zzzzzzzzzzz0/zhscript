/*
 * tmpl___.h
 *
 *  Created on: 2010-6-8
 *      Author: zzzzzzzzzzz
 */

#ifndef set_TMPL____H_
#define set_TMPL____H_

#include <gtkmm.h>

class set_tmpl___ {
private:
	int idx_;
	void ls__(Gtk::Container*c,int i);
	bool z__(int idx,Glib::ustring& s,Gtk::Container*c,int oper);
	int zz__(int idx,Glib::ustring& s,Gtk::Widget*w,int oper);
public:
	bool set__(int idx,Glib::ustring& s,Gtk::Container*c){
		idx_=0;
		return z__(idx,s,c,'s');
	}
	bool get__(int idx,Glib::ustring& s,Gtk::Container*c){
		idx_=0;
		return z__(idx,s,c,'g');
	}
	void ls__(Gtk::Container*c){
		idx_=0;
		ls__(c,0);
	}
};

#endif /* TMPL2____H_ */
