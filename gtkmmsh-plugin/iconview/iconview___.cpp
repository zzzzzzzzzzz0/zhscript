/*
 * iconview___.cpp
 *
 *  Created on: 2010-9-12
 *      Author: zzzzzzzzzzz
 */

#include "iconview___.h"
#include"plugin_def.h"
#include "iconview_data___.h"
#include"util.cpp"
#include "../imagecache/imagecache_def.inc"

/*class menu_item___{
public:
	menu_item___(const Glib::ustring& dong,iconview_data___* id){
		dong_=dong;
		id_=id;
	}
	bool on__(GdkEventButton* eb){
		id_->on_menu__(dong_);
		return true;
	}
private:
	Glib::ustring dong_;
	iconview_data___* id_;
};*/

iconview_data___* get_id__(std::deque<Glib::ustring>* p,size_t i,iconview___*iv,bool err_show=true){
	if(p->size()>i){
		iconview_data___* id=(iconview_data___*)s2l__((*p)[i],0);
		if(!id&&err_show){
			//sh->err_show__((*p)[0].c_str(),(*p)[1].c_str(),(*p)[i].c_str());
			iv->d_(iv->sh_,err_show_,3,(*p)[0].c_str(),(*p)[1].c_str(),(*p)[i].c_str());
		}
		return id;
	}
	if(err_show){
		//sh->err_show_buzu__(p);
		iv->d_(iv->sh_,err_show_buzu_,p);
	}
	return NULL;
}
iconview_data___* get_id__(std::deque<Glib::ustring>* p,iconview___*sh,size_t i,size_t i2,size_t i3=0){
	iconview_data___* id=get_id__(p,i,sh,false);
	if(!id){
		if(i3){
			id=get_id__(p,i2,sh,false);
			if(!id)
				id=get_id__(p,i3,sh);
		}else
			id=get_id__(p,i2,sh);
	}
	return id;
}

int iconview___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		if((*p)[1]=="增加"){
			iconview_data___* id=get_id__(p,this,7,6);
			if(!id)
				return 1;
			id->add__(p);
			return 1;
		}
		if((*p)[1]=="更新"){
			iconview_data___* id=get_id__(p,this,7,6);
			if(!id)
				return 1;
			id->update__(p);
			return 1;
		}
		if((*p)[1]=="移除"){
			iconview_data___* id=get_id__(p,this,4,3,2);
			if(!id)
				return 1;
			id->del__(p,shangji);
			return 1;
		}
		if((*p)[1]=="移动"){
			iconview_data___* id=get_id__(p,3,this);
			if(!id)
				return 1;
			id->move__((*p)[1].c_str(),(*p)[2]);
			return 1;
		}
		if((*p)[1]=="选择"){
			iconview_data___* id=get_id__(p,this,4,3);
			if(!id)
				return 1;
			id->select__(p);
			return 1;
		}
		if((*p)[1]=="遍历"){
			iconview_data___* id=get_id__(p,this,4,3);
			if(!id)
				return 1;
			id->for__(p,shangji);
			return 1;
		}
		if((*p)[1]=="获取"){
			iconview_data___* id=get_id__(p,this,4,3);
			if(!id)
				return 1;
			id->get__(p,shangji,buf);
			return 1;
		}
		if((*p)[1]=="清空"){
			iconview_data___* id=get_id__(p,2,this);
			if(!id)
				return 1;
			id->clear__();
			return 1;
		}
		if((*p)[1]=="类型"){
			if(p->size()<=2){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			iconview_data___::type__((*p)[2],buf,siz);
			return 1;
		}
		Gtk::IconView* iv;
		sh_->builder_->get_widget((*p)[1], iv);
		if(!iv){
			d_(sh_,err_show_fei_,p);
			return 1;
		}
		iconview_data___* id=new iconview_data___(iv,p,this);
		for(size_t i=2;i<p->size();i++){
			switch(id->option__(p,i)){
			case 0:
				continue;
			case -1:
				break;
			default:
				return 1;
			}
			char c;
			if((*p)[i]=="图片缓存")
				c='i';
			else{
				d_(sh_,err_show_buzhichi_,2,p,i);
				return 1;
			}
			if(++i>=p->size()){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			switch(c){
			case'i':
				get_imagecache__((*p)[i].c_str(),ic_,ic_arg1_);
				continue;
			}
		}
		l2s__((long)id,buf);
		return 1;
	}
	if((*p)[0]=="读图片限制"){
		switch(p->size()){
			case 4:
				pix_limit_aspect_=s2i__((*p)[3],pix_limit_aspect_);
			case 3:
				pix_limit_height_=s2i__((*p)[2],pix_limit_height_);
			case 2:
				pix_limit_width_=s2i__((*p)[1],pix_limit_width_);
				break;
		}
		return 2;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new iconview___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
