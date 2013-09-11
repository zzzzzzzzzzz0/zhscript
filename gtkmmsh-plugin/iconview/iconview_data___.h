/*
 * iconview_data___.h
 *
 *  Created on: 2013-2-16
 *      Author: zzzzzzzzzzz
 */

#ifndef ICONVIEW_DATA____H_
#define ICONVIEW_DATA____H_

#include "columnrecord___.h"
#include "iconview___.h"

#define id_status_use_	0
#define id_status_edit_	1

class iconview_data___ {
private:
	Glib::RefPtr<Gtk::ListStore> ls_;
	columnrecord___* cr_;
	Gtk::IconView* iv_;

	shell___* sh_;
	direct___ d_;
	const char* zhao_;

	iconview___* iv1_;

public:
	Glib::ustring code_;
	Glib::ustring dong_;
	Gtk::Menu* menu_;
	Gtk::Menu* menu1_;

	int status_;

	iconview_data___(Gtk::IconView* iv,std::deque<Glib::ustring>* p,iconview___* iv1);
	int option__(std::deque<Glib::ustring>* p,size_t& i);
	void clear__(){
		ls_->clear();
	}
	/*void on_menu__(const Glib::ustring& dong){
		on_path__(menu_path_,"菜单",dong.c_str());
	}*/
	bool on_press__(GdkEventButton* event);
	void on_select__();
	void on_activated__(const Gtk::TreeModel::Path& path){
		on_path__(path,"活性");
	}
	void add__(std::deque<Glib::ustring>* p);
	void del__(deque<Glib::ustring>* p,void*shangji);
	void move__(const char*oper,Glib::ustring& fangxiang);
	void for__(deque<Glib::ustring>* p,void*shangji);
	void select__(deque<Glib::ustring>* p);
	void get__(deque<Glib::ustring>* p,void*shangji,char*buf);
	void update__(std::deque<Glib::ustring>* p);
	static void type__(const Glib::ustring& t,char* buf,long siz);
private:
	int dir__(Gtk::TreeModel::iterator& iter,Gtk::TreeModel::Row& r,
			const Glib::ustring& t,const Glib::ustring& s,bool is_add);

	bool get_pos_path__(GdkEventButton* event,Gtk::TreeModel::Path& path);

	void set__(Gtk::TreeModel::Row& r,std::deque<Glib::ustring>* p,int from,bool is_add);

	Gtk::TreeModel::Path menu_path_;
	std::list<Gtk::TreeModel::Path> sel_;
	void on_path__(const Gtk::TreeModel::Path& path,const char*arg3=NULL,const char*arg4=NULL);
	void on__(void*shangji,const char*s,const char*s2,const char*oper=NULL,const char*arg3=NULL,const char*arg4=NULL);
	string call4__(Gtk::TreeModel::iterator ti,Glib::ustring& code,void*shangji,char*buf1=NULL);
	void icon__(Gtk::TreeModel::Row& r,Glib::ustring& p3);
};

#endif /* ICONVIEW_DATA____H_ */
