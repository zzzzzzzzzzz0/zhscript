/*
 * treeview___.h
 *
 *  Created on: 2010-12-24
 *      Author: zzzzzzzzzzz
 */

#ifndef treeview____H_
#define treeview____H_

#include <plugin_base___.h>
#include "../imagecache/imagecache_def.h"

class treeview_data___{
private:
	imagecache___ ic_;
	void* ic_arg1_;

	Gtk::TreeView *tv_;
	Glib::RefPtr<Gtk::TreeStore> ts_;
	class columnrecord___ : public Gtk::TreeModel::ColumnRecord{
	public:
		columnrecord___(){
			add(text_);
			add(text2_);
			add(icon_);
		}
		Gtk::TreeModelColumn<Glib::ustring> text_;
		Gtk::TreeModelColumn<Glib::ustring> text2_;
		Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf> > icon_;
	};
	columnrecord___ cr_;
	deque<Gtk::TreeModel::Row> r_;
	void on_row_activated__(const Gtk::TreeModel::Path& path,Gtk::TreeViewColumn*);
	shell___*sh_;
	direct___ d_;
	Glib::ustring code_;
	const char* zhao_;
	Glib::ustring dong_;
public:
	treeview_data___(Gtk::TreeView *tv,deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao);
	void add__(deque<Glib::ustring>* p,char*buf);
};

class treeview___: public plugin_base___ {
private:
	treeview_data___* get_d__(deque<Glib::ustring>* p,size_t min);
public:
	treeview___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	virtual int proc__(deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "树";}
	int version__(){return 2;}
};

#endif /* treeview____H_ */
