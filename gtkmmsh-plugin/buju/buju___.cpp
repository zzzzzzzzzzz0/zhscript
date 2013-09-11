/*
 * buju___.cpp
 *
 *  Created on: 2010-11-4
 *      Author: zzzzzzzzzzz
 */

#include "buju___.h"
#include"plugin_def.h"
#include "util.cpp"

void i1_i2__(std::deque<Glib::ustring>* p,int from,int& i1,int& i2){
	const Glib::ustring& p1=(*p)[from];
	const Glib::ustring& p2=(*p)[from+1];
	if(p1[0]){
		if(p1[0]=='+')
			i1+=s2i__(p1.substr(1),0);
		else
			i1=s2i__(p1,0);
	}
	if(p2[0]){
		if(p2[0]=='+')
			i2+=s2i__(p2.substr(1),0);
		else
			i2=s2i__(p2,0);
	}
}

Gtk::Window* buju___::ww__(std::deque<Glib::ustring>* p,int i){
	if(p->size()<=i)
		return sh_->main_win_;
	Gtk::Window* w;
	sh_->builder_->get_widget((*p)[i], w);
	if(!w){
		d_(sh_,err_show_wufa_,2,p,i);
	}
	return w;
}

int buju___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	const Glib::ustring& p0=(*p)[0];
	if(p0=="窗口宽"||p0=="窗口高"){
		if(siz==-1)return 1;
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		bool is_w=(p0=="窗口宽");
		int w,h;
		if(is_w)
			w=ww->get_width();
		else
			h=ww->get_height();
		for(;;){
			if(is_w){
				if(w>1)
					break;
			}else{
				if(h>1)
					break;
			}
			ww->get_size(w,h);
			if(w>1)
				break;
			ww->get_default_size(w,h);
			if(w>1)
				break;
			if(is_w)
				w=Glib::PropertyProxy<int>(ww, "width_request");
			else
				h=Glib::PropertyProxy<int>(ww, "height_request");
			break;
		}
		cpy__(buf,is_w?w:h,siz);
		return 1;
	}
	if(p0=="窗口宽高"){
		if(siz==-1)return 1;
		Gtk::Window* ww=ww__(p,3);
		if(!ww)
			return 1;
		if(p->size()>2){
			int w,h;
			ww->get_size(w,h);
			i1_i2__(p,1,w,h);
			ww->set_default_size(w,h);
			ww->resize(w,h);
			return 1;
		}
		d_(sh_,err_show_buzu_,p);
		return 1;
	}
	if(p0=="窗口居中"){
		if(siz==-1)return 1;
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		ww->set_position(Gtk::WIN_POS_CENTER);
		return 1;
	}
	if(p0=="边框宽"){
		if(siz==-1)return 1;
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		cpy__(buf,ww->get_border_width(),siz);
		return 1;
	}
	if(p0=="屏幕宽"){
		if(siz==-1)return 1;
		cpy__(buf,Gdk::screen_width(),siz);
		return 1;
	}
	if(p0=="屏幕高"){
		if(siz==-1)return 1;
		cpy__(buf,Gdk::screen_height(),siz);
		return 1;
	}
	if(p0=="建立表格"){
		if(siz==-1)return 1;
		if(p->size()>3){
			Gtk::ScrolledWindow* sw;
			sh_->builder_->get_widget((*p)[3], sw);
			if(sw){
				Gtk::Table* t;
				guint n_rows = s2i__((*p)[1],1);
				guint n_columns = s2i__((*p)[2],1);
				t=Gtk::manage(new Gtk::Table(n_rows,n_columns));
				t->show();
				sw->add(*t);
				l2s__((long)t,buf);
				return 1;
			}
			d_(sh_,err_show_wufa_,2,p,3);
			return 1;
		}
		d_(sh_,err_show_wufa_,1,p);
		return 1;
	}
	if(p0=="设置表格单元"){
		if(siz==-1)return 1;
		if(p->size()>4){
			int i = s2i__((*p)[1],1)-1;
			int j = s2i__((*p)[2],1)-1;
			Gtk::Container*w=(Gtk::Container*)s2l__((*p)[3],0);
			Gtk::Table*t=(Gtk::Table*)s2l__((*p)[4],0);
			if(w&&t){
				//t->remove((*t)[i][j]);
				t->attach(*w, i, i+1, j, j+1,Gtk::FILL|Gtk::EXPAND,Gtk::FILL);
				return 1;
			}
		}
		d_(sh_,err_show_wufa_,1,p);
		return 1;
	}
	if(p0=="移动"){
		if(siz==-1)return 1;
		if(p->size()>2){
			switch(p->size()){
			case 3:
			{
				int x,y;
				sh_->main_win_->get_position(x,y);
				i1_i2__(p,1,x,y);
				sh_->main_win_->move(x,y);
				return 1;
			}
			case 5:
			{
				Gtk::Fixed*f;
				sh_->builder_->get_widget((*p)[1], f);
				Gtk::Widget* w;
				sh_->builder_->get_widget((*p)[2], w);
				if(f&&w){
					f->move(*w,s2i__((*p)[3],0),s2i__((*p)[4],0));
					return 1;
				}
				break;
			}
			case 4:
			{
				Gtk::ScrolledWindow* sw;
				sh_->builder_->get_widget((*p)[1], sw);
				if(sw){
					Gtk::HScrollbar* hs=sw->get_hscrollbar();
					Gtk::VScrollbar* vs=sw->get_vscrollbar();
					int x=hs->get_value(),y=vs->get_value();
					i1_i2__(p,2,x,y);
					hs->set_value(x);
					vs->set_value(y);
					return 1;
				}
				Gtk::Window* w;
				sh_->builder_->get_widget((*p)[1], w);
				if(w){
					int x,y;
					w->get_position(x,y);
					i1_i2__(p,2,x,y);
					w->move(x,y);
					return 1;
				}
				break;
			}
			}
		}
		d_(sh_,err_show_wufa_,1,p);
		return 1;
	}
	if(p0=="窗口x"||p0=="窗口y"){
		if(siz==-1)return 1;
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		int x,y;
		ww->get_position(x,y);
		cpy__(buf,p0=="窗口x"?x:y,siz);
		return 1;
	}
	if(p0=="位置"){
		if(siz==-1)return 1;
		if(p->size()<=1){
			d_(sh_,err_show_buzu_,p);
			return 1;
		}
		Gtk::Paned* p1;
		sh_->builder_->get_widget((*p)[1], p1);
		if(!p1){
			d_(sh_,err_show_wufa_,1,p);
			return 1;
		}
		if(p->size()>2){
			p1->set_position (s2i__((*p)[2]));
		}else{
			l2s__(p1->get_position (),buf);
		}
		return 1;
	}
	if(p->size()<2){
		return 0;
	}
	if(p0=="宽"||p0=="高"){
		if(siz==-1)return 1;
		Gtk::Widget* w=NULL;
		switch(p->size()){
		case 3:
			Gtk::ScrolledWindow* sw;
			sh_->builder_->get_widget((*p)[1], sw);
			if(sw){
				if((*p)[2]=="横滚动条")
					w=sw->get_hscrollbar();
				else if((*p)[2]=="竖滚动条")
					w=sw->get_vscrollbar();
				else{
					d_(sh_,err_show_wufa_,2,p,2);
					return 1;
				}
			}
			break;
		default:
			sh_->builder_->get_widget((*p)[1], w);
			break;
		}
		if(w){
			cpy__(buf,p0=="宽"?w->get_width():w->get_height(),siz);
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new buju___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
