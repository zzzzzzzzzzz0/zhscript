/*
 * tmpl___.cpp
 *
 *  Created on: 2010-6-8
 *      Author: zzzzzzzzzzz
 */

#include "set_tmpl___.h"
#include "util.h"
#include <iostream>

static void o__(int i1,const char*s,const char*s1=NULL){
	for(int i2=0;i2<i1;i2++)
		std::cout<<"\t";
	std::cout<<s;
	if(s1)
		std::cout<<" "<<s1;
	std::cout<<std::endl;
}
static void o__(int i1,Gtk::Widget*w,int i){
	Glib::ustring s;
	s+=w->get_name();

	s+=' ';
	char buf[32];
	s+=l2s__(i+1,buf);

	s+=' ';
	s+=w->get_visible()?"v":"V";

	/*Glib::ustring s1,s2;
	w->class_path(s1,s2);
	s+=' ';
	s+=s1;
	s+=' ';
	s+=s2;*/
	o__(i1,s.c_str());
}

int set_tmpl___::zz__(int idx,Glib::ustring& s,Gtk::Widget*w,int oper){
	//o__(0,w,idx_);
	if(idx==idx_++){
		Gtk::TextView* tv=dynamic_cast<Gtk::TextView*>(w);
		if(tv){
			switch(oper){
			case's':
				tv->get_buffer()->set_text(s);
				break;
			case'g':
				s=tv->get_buffer()->get_text();
				break;
			}
			return 1;
		}
		Gtk::Frame* f=dynamic_cast<Gtk::Frame*>(w);
		if(f){
			switch(oper){
			case's':
				f->set_label(s);
				break;
			case'g':
				s=f->get_label();
				break;
			}
			return 1;
		}
		Gtk::Label* l=dynamic_cast<Gtk::Label*>(w);
		if(l){
			switch(oper){
			case's':
				l->set_markup(s);
				break;
			case'g':
				s=l->get_label();
				break;
			}
			return 1;
		}
		Gtk::Entry* e=dynamic_cast<Gtk::Entry*>(w);
		if(e){
			switch(oper){
			case's':
				e->set_text(s);
				break;
			case'g':
				s=e->get_text();
				break;
			}
			return 1;
		}
		Gtk::Button* b=dynamic_cast<Gtk::Button*>(w);
		if(b){
			switch(oper){
			case's':
				b->set_label(s);
				break;
			case'g':
				s=b->get_label();
				break;
			}
			return 1;
		}
		return -1;
	}
	return 0;
}

bool set_tmpl___::z__(int idx,Glib::ustring& s,Gtk::Container*c,int oper){
	switch(zz__(idx,s,c,oper)){
	case 1:
		return true;
	case -1:
		return false;
	}
	Glib::ListHandle<Gtk::Widget*> ls=c->get_children();
	for(Glib::ListHandle<Gtk::Widget*>::const_iterator i=ls.begin();i!=ls.end();i++){
		Gtk::Widget*w=*i;
		Gtk::Container*c1 = dynamic_cast<Gtk::Container*>(w);
		if(c1){
			if(z__(idx,s,c1,oper))
				return true;
		}else{
			switch(zz__(idx,s,w,oper)){
			case 1:
				return true;
			case -1:
				return false;
			}
		}
	}
	return false;
}

void set_tmpl___::ls__(Gtk::Container*c,int i1){
	o__(i1,c,idx_++);
	o__(i1++,"{");
	Glib::ListHandle<Gtk::Widget*> ls=c->get_children();
	for(Glib::ListHandle<Gtk::Widget*>::const_iterator i=ls.begin();i!=ls.end();i++){
		Gtk::Widget*w=*i;
		Gtk::Container*c1 = dynamic_cast<Gtk::Container*>(w);
		if(c1){
			ls__(c1,i1);
		}else{
			o__(i1,w,idx_++);
		}
	}
	o__(--i1,"}");
}
