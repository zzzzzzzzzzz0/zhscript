/*
 * dlg___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "dlg___.h"
#include"plugin_def.h"
#include"util.cpp"

int fcd__(std::deque<Glib::ustring>* p,Gtk::Window* win,char*buf,long siz){
	Gtk::FileChooserAction fca;
	Gtk::StockID ok=Gtk::Stock::OPEN;
	if((*p)[1]=="打开"){
		fca=Gtk::FILE_CHOOSER_ACTION_OPEN;
	}else if((*p)[1]=="保存"){
		fca=Gtk::FILE_CHOOSER_ACTION_SAVE;
		ok=Gtk::Stock::SAVE;
	}else if((*p)[1]=="文件夹"){
		fca=Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER;
	}else if((*p)[1]=="建立文件夹"){
		fca=Gtk::FILE_CHOOSER_ACTION_CREATE_FOLDER;
	}else
		return 1;
	if(p->size()<=2)
		return 2;
	Gtk::FileChooserDialog dialog((*p)[2],fca);
	dialog.set_transient_for(*win);

	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button(ok, Gtk::RESPONSE_OK);

	for(unsigned int i=3;i<p->size();i++){
		const Glib::ustring& pi=(*p)[i];
		if(pi=="预选"){
			if(++i>=p->size())
				return 2;
			Glib::ustring& name=(*p)[i];
			if(name.length()>0){
				size_t i1=name.rfind('/');
				if(i1!=Glib::ustring::npos){
					dialog.set_current_folder(name.substr(0,i1));
				}
				if(i1!=name.length()-1){
					dialog.set_filename(name);
					dialog.select_filename(name);
					//dialog.set_current_name(name.substr(i1+1));
				}
			}
			continue;
		}
		if(pi=="类型"){
			if(++i>=p->size())
				return 2;
			Gtk::FileFilter filter;
			filter.set_name((*p)[i]);
			/*filter.add_mime_type("text/x-c");
			filter.add_mime_type("text/x-c++");
			filter.add_mime_type("text/x-c-header");*/
			if(++i>=p->size())
				return 2;
			filter.add_pattern((*p)[i]);
			dialog.add_filter(filter);
			continue;
		}
		if(pi=="覆盖确认"){
			dialog.set_do_overwrite_confirmation(true);
			continue;
		}
		return i;
	}

	switch(dialog.run()){
	case(Gtk::RESPONSE_OK):
		cpy__(buf,dialog.get_filename().c_str(),siz);
		break;
	}
	return 0;
}

int dlg___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]=="文件选择"){
		if(siz==-1)return 1;
		int ret=fcd__(p,sh_->main_win_,buf,siz);
		switch(ret){
		case 0:
			break;
		case 1:
			d_(sh_,err_show_buzhichi_,1,p);
			break;
		case 2:
			d_(sh_,err_show_buzu_,p);
			break;
		default:
			d_(sh_,err_show_buzhichi_,2,p,ret);
			break;
		}
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new dlg___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

