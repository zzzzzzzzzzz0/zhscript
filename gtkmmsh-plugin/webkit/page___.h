/*
 * page___.h
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */

#ifndef PAGE____H_
#define PAGE____H_

#include <gtkmm.h>
#include <webkit/webkit.h>

class page___{
private:
	Gtk::Notebook* n_;
	WebKitWebView* wwv_;
	Gtk::ScrolledWindow*sw_;
	Gtk::Label*title_;
	Gtk::Widget* parent_;
public:
	page___(size_t i,Gtk::Notebook* n,WebKitWebView* wwv,Gtk::ScrolledWindow*sw);
	WebKitWebView* wwv__(){return wwv_;}

	void titletip__(const Glib::ustring &str);
	const char*titletip__();
	void title__(const Glib::ustring &str);
	const char*title__();
	void titletip__(char**addr_ret);
	void title__(char**addr_ret);

	void close__();
};

#endif /* PAGE____H_ */
