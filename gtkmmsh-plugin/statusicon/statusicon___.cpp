/*
 * statusicon___.cpp
 *
 *  Created on: 2010-9-11
 *      Author: zzzzzzzzzzz
 */

#include "statusicon___.h"
#include"call_util.cpp"
#include"plugin_def.h"

int statusicon___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		if(p->size()>1){
			stt_icon_->set_from_file((*p)[1]);
			return 1;
		}
		cpy__(buf,stt_icon_->get_icon_name().c_str(),siz);
		return 1;
	}
	if((*p)[0]=="托盘提示"){
		if(siz==-1)return 1;
		if(p->size()>1){
			stt_icon_->set_tooltip((*p)[1]);
			return 1;
		}
		cpy__(buf,stt_icon_->get_tooltip_text().c_str(),siz);
		return 1;
	}
	if((*p)[0]=="最小化到托盘"){
		if(siz==-1)return 1;
		hide_in_mini_=true;
	}else if((*p)[0]=="托盘应用"){
		if(siz==-1)return 1;
		stt_icon_keep_=only_=show_=true;
	}else
		return 0;
	size_t file=0;
	if(p->size()>1){
		for(size_t i=1;i<p->size();i++){
			if((*p)[i]=="驻留"){
				stt_icon_keep_=true;
				continue;
			}
			if((*p)[i]=="图标"){
				if(++i<p->size()){
					file=i;
					continue;
				}
			}
			//sh_->err_show_buzhichi__(p);
			d_(sh_,err_show_buzhichi_,2,p,i);
			return 1;
		}
	}
	if(file){
		stt_icon_ = Gtk::StatusIcon::create_from_file((*p)[file]);
	}else{
		Glib::RefPtr<Gdk::Pixbuf> i=sh_->main_win_->get_icon();
		if(i)
			stt_icon_ = Gtk::StatusIcon::create(i);
		else{
			const Glib::ustring& s = sh_->main_win_->get_icon_name();
			if(s.empty()){
				stt_icon_ = Gtk::StatusIcon::create(Gtk::Stock::DIALOG_INFO);
			}else
				stt_icon_ = Gtk::StatusIcon::create(s);
		}
	}
	stt_icon_->set_tooltip(sh_->main_win_->get_title());
	stt_icon_->signal_activate().connect(sigc::mem_fun(*this,&statusicon___::main_win_sw__));
	if(!stt_icon_keep_)
		stt_icon_->set_visible(false);
	return 1;
}

void statusicon___::main_win_sw__(){
	bool show;
	if(only_){
		show=show_;
		show_=!show_;
	}else
		show=d_(sh_,main_win_is_visible_);
	/*if (sh_->main_win_is_visible__())
		sh_->main_win_hide__();
	else
		sh_->main_win_show__();*/
	if(show)
		d_(sh_,main_win_hide_);
	else
		d_(sh_,main_win_show_);
}

void statusicon___::on__(int event){
	switch(event){
	case main_win_show_:
		if(hide_in_mini_){
			if(!stt_icon_keep_)
				stt_icon_->set_visible(false);
			sh_->main_win_->set_skip_taskbar_hint(false);
		}
		break;
	case main_win_hide_:
		if(hide_in_mini_){
			sh_->main_win_->set_skip_taskbar_hint(true);
			stt_icon_->set_visible(true);
		}
		break;
	}
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new statusicon___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

