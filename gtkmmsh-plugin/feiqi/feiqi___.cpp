/*
 * feiqi___.cpp
 *
 *  Created on: 2010-11-4
 *      Author: zzzzzzzzzzz
 */

#include "feiqi___.h"
#include"plugin_def.h"
#include "util.cpp"

int feiqi___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji) {
	if((*p)[0]=="标签页"){
		Gtk::Notebook* n;
		sh_->builder_->get_widget((*p)[1], n);
		if(n){
			if(p->size()>2){
				int i=1;
				i=s2i__((*p)[2],i)-1;
				n->set_current_page(i);
			}else{
				cpy__(buf,n->get_current_page()+1,siz);
			}
			return 1;
		}
		d_(sh_,err_show_fei_,1,p);
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new feiqi___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
