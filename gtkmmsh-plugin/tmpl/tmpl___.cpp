/*
 * tmpl___.cpp
 *
 *  Created on: 2010-9-12
 *      Author: zzzzzzzzzzz
 */

#include "tmpl___.h"
#include "set_tmpl___.h"
#include"util.cpp"
#include"plugin_def.h"

int tmpl___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce){
	if((*p)[0]=="复制模板"){
		if(siz==-1)return 1;
		Gtk::Container* f;
		sh_->builder_->get_widget((*p)[1], f);
		if(f){
			//set_tmpl___ ste;ste.ls__(f);
			Gtk::Container*c;
			c=cpy_tmpl__(f);
			l2s__((long)c,buf);
			if(!c){
				//err_show_buzhichi__(p);
				d_(sh_,err_show_buzhichi_,1,p);
			}
			return 1;
		}
		d_(sh_,err_show_fei_,p);
		return 1;
	}
	if((*p)[0]=="查看模板"){
		if(siz==-1)return 1;
		const Glib::ustring& s=(*p)[1];
		Gtk::Container* f;
		if((s[0]>='0'&&s[0]<='9')||s[0]=='-')
			f=dynamic_cast<Gtk::Container*>((Gtk::Container*)s2l__(s,0));
		else
			sh_->builder_->get_widget(s, f);
		if(f){
			set_tmpl___ ste;
			ste.ls__(f);
			return 1;
		}
		d_(sh_,err_show_fei_,p);
		return 1;
	}
	if((*p)[0]=="设置模板单元"){
		if(siz==-1)return 1;
		if(p->size()>3){
			int i = s2i__((*p)[1],1)-1;
			Gtk::Container*c=(Gtk::Container*)s2l__((*p)[3],0);
			if(c){
				set_tmpl___ ste;
				if(ste.set__(i,(*p)[2],c))
					return 1;
			}
		}
		d_(sh_,err_show_wufa_,1,p);
		return 1;
	}
	if((*p)[0]=="得到模板单元"){
		if(siz==-1)return 1;
		if(p->size()>2){
			int i = s2i__((*p)[1],1)-1;
			Gtk::Container*c=(Gtk::Container*)s2l__((*p)[2],0);
			if(c){
				set_tmpl___ ste;
				Glib::ustring ret;
				if(ste.get__(i,ret,c)){
					*addr_ret=dup__(ret.c_str());
					return 1;
				}
			}
		}
		d_(sh_,err_show_wufa_,1,p);
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new tmpl___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
