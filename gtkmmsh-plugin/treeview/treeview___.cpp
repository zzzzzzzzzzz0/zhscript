/*
 * treeview___.cpp
 *
 *  Created on: 2010-12-24
 *      Author: zzzzzzzzzzz
 */

#include "treeview___.h"
#include"plugin_def.h"
#include "util.cpp"
#include "../imagecache/imagecache_def.inc"

treeview_data___::treeview_data___(Gtk::TreeView *tv,deque<Glib::ustring>* p,shell___*sh,direct___ d,const char* zhao){
	sh_=sh;
	d_=d;
	zhao_=zhao;
	dong_=(*p)[1];
	ic_=0;
	for(size_t i=2;i<p->size();i++){
		char c;
		if((*p)[i]=="命名")
			c='n';
		else if((*p)[i]=="代码")
			c='c';
		else if((*p)[i]=="图片缓存")
			c='i';
		else{
			d_(sh_,err_show_buzhichi_,2,p,i);
			break;
		}
		if(++i>=p->size()){
			d_(sh_,err_show_buzu_,p);
			break;
		}
		switch(c){
		case 'n':
			dong_=(*p)[i];
			continue;
		case'c':
			code_=(*p)[i];
			continue;
		case'i':
			get_imagecache__((*p)[i].c_str(),ic_,ic_arg1_);
			continue;
		}
	}

	tv_=tv;
	ts_=Gtk::TreeStore::create(cr_);
	tv->set_model(ts_);

	//tv->append_column("text",cr_.text_);
	//tv->append_column("icon",cr_.icon_);
	Gtk::TreeView::Column* col = Gtk::manage(new Gtk::TreeView::Column("text"));
	col->pack_start(cr_.icon_, false); //false = don't expand.
	col->pack_start(cr_.text_);
	tv->append_column(*col);

	tv->signal_row_activated().connect(sigc::mem_fun(*this,
				  &treeview_data___::on_row_activated__) );
	tv->set_data("ctl",this);
}

void treeview_data___::on_row_activated__(const Gtk::TreeModel::Path& path,
        Gtk::TreeViewColumn* /* column */)
{
	Gtk::TreeModel::iterator iter = ts_->get_iter(path);
	if(iter){
		Gtk::TreeModel::Row row = *iter;
		Glib::ustring t=row[cr_.text_];
		Glib::ustring t2=row[cr_.text2_];
		d_(sh_,on_,code_.c_str(),NULL,4,zhao_,dong_.c_str(),t.c_str(),t2.c_str());
	}
}

void treeview_data___::add__(deque<Glib::ustring>* p,char*buf){
	Gtk::TreeModel::Row r;
	if(p->size()>6){
		long l=s2l__((*p)[5],0);
		if(l<0||l>=r_.size()){
			d_(sh_,err_show_wufa_,2,p,5);
			return;
		}
		r=r_[l];
		r = *(ts_->append(r.children()));
	}else
		r = *(ts_->append());
	r[cr_.text_]=(*p)[2];
	r[cr_.text2_]=(*p)[3];
	const Glib::ustring& icon=(*p)[4];
	if(icon.size()>0&&ic_){
		r[cr_.icon_] = ic_(ic_arg1_,icon,-1,-1,true);
	}
	l2s__(r_.size(),buf);
	r_.push_back(r);
}

treeview_data___* treeview___::get_d__(deque<Glib::ustring>* p,size_t min){
	if(p->size()<=min){
		d_(sh_,err_show_buzu_,p);
		return NULL;
	}
	return (treeview_data___*)s2l__((*p)[p->size()-1],0);
}

int treeview___::proc__(deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		if(p->size()<=1){
			d_(sh_,err_show_buzu_,p);
			return 1;
		}
		treeview_data___* tvd;
		char c=0;
		int i;
		if((*p)[1]=="增加"){
			c='+';i=5;
		}
		if(c){
			tvd=get_d__(p,i);
			if(tvd){
				switch(c){
				case'+':
					tvd->add__(p,buf);
					break;
				}
			}
			return 1;
		}

		Gtk::TreeView *tv;
		sh_->builder_->get_widget((*p)[1], tv);
		if(!tv){
			d_(sh_,err_show_fei_,p);
			return 1;
		}

		tvd=new treeview_data___(tv,p,sh_,d_,name__());
		l2s__((long)tvd,buf);
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new treeview___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
