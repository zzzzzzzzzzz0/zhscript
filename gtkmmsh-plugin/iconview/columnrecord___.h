/*
 * columnrecord___.h
 *
 *  Created on: 2013-2-16
 *      Author: zzzzzzzzzzz
 */

#ifndef COLUMNRECORD____H_
#define COLUMNRECORD____H_

#include <gtkmm.h>

class columnrecord___ : public Gtk::TreeModel::ColumnRecord {
public:
	columnrecord___(){
		add(s_);
		add(title_);
		add(icon_);
		add(icon_path_);
		add(s2_);
		add(child_);
	}
	Gtk::TreeModelColumn <Glib::ustring> s_;
	Gtk::TreeModelColumn <Glib::ustring> title_,icon_path_,s2_;
	Gtk::TreeModelColumn <Glib::RefPtr<Gdk::Pixbuf> > icon_;
	Gtk::TreeModelColumn <std::deque<Glib::ustring>*> child_;
};

#endif /* COLUMNRECORD____H_ */
