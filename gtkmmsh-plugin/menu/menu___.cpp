/*
 * menu___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "menu___.h"
#include"plugin_def.h"

char* l2s__(long num,char* num2){
	sprintf(num2,"%ld",num);
	return num2;
}
char* d2s__(gdouble d,char*s){
	sprintf(s,"%g",d);
	return s;
}

class menu_press___{
private:
	Gtk::Menu* menu_;
public:
	menu_press___(Gtk::Menu* m){
		menu_=m;
	}

	bool on__(GdkEventButton* event){
		if( (event->type == GDK_BUTTON_PRESS) && (event->button == 3) ){
			menu_->popup(event->button, event->time);
			return true;
		}
		return false;
	}
};

class control___{
private:
	Glib::ustring argv_[8];
	int argc_;
	shell___* sh_;
	direct___ d_;
	Glib::ustring code_;
	void init1__(shell___* sh,direct___ d){
		argc_=0;
		sh_=sh;
		d_=d;
	}
	void add_arg__(const string&s){
		argv_[argc_++]=s;
	}
public:
	control___(const string&zhao,const string&dong,shell___* sh,direct___ d,const string&code,const string&arg3){
		init1__(sh,d);
		code_=code;
		add_arg__(zhao);
		add_arg__(dong);
		add_arg__(arg3);
	}

	bool on1__(GdkEventButton* eb){
		char buf[16],bufx[32],bufy[32];
		l2s__(eb->button,buf);
		d2s__(eb->x,bufx);
		d2s__(eb->y,bufy);
		d_(sh_,on_,code_.c_str(),NULL,6,argv_[0].c_str(),argv_[1].c_str(),argv_[2].c_str(),buf,bufx,bufy);
		return true;
	}
};

int menu___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		Gtk::Menu* m;
		sh_->builder_->get_widget((*p)[1], m);
		if(m){
			Gtk::Widget* w;
			for(size_t i=2;i<p->size();i++){
				sh_->builder_->get_widget((*p)[i], w);
				if(w){
					menu_press___* mp=new menu_press___(m);
					w->signal_button_press_event().connect(sigc::mem_fun(mp,&menu_press___::on__),false);
					w->set_data("ctl",mp);
				}else
					d_(sh_,err_show_wufa_,2,p,i);
			}
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if((*p)[0]=="侦听"){
		if(p->size()>2){
			if((*p)[1]=="点击"){
				Glib::ustring code;
				size_t size=p->size();
				if(size>=4)
					code=(*p)[--size];
				int ret=0;
				for(size_t i=2;i<size;i++){
					if((*p)[i].length()==0)
						continue;
					Gtk::MenuItem* mi;
					sh_->builder_->get_widget((*p)[i], mi);
					if(mi){
						ret=1;
						control___* c=new control___("菜单",(*p)[i],sh_,d_,code,mi->get_label());
						mi->signal_button_press_event().connect(sigc::mem_fun(*c, &control___::on1__));
						mi->set_data("ctl",c);
					}
					if(p->size()==4)
						break;
				}
				return ret;
			}
		}
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new menu___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

