/*
 * api.cpp
 *
 *  Created on: 2010-7-4
 *      Author: zzzzzzzzzzz
 */
#include "shell.h"
#include"util.h"
#ifndef ver_exe_
#include <gdk/gdkx.h>
#endif

void shell___::api__(void*shangji,void*ce,std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret){
	/*for(int i=0;i<p->size();i++)
		std::cout<<(*p)[i]<<std::endl;*/
	if(p->size()<1){
		err_show_buzu__(p);
		return;
	}
	if(plugin_proc__(p,buf,siz,addr_ret,shangji,ce))
		return;
	if((*p)[0]=="界面文件名"){
		long i=cpy__(buf,ui_file_,siz);
		if(p->size()>1){
			if((*p)[1]=="主"||(*p)[1]=="0"){
				for(;--i>=0;){
					if(buf[i]=='/')
						break;
					if(buf[i]=='.'){
						buf[i]=0;
						break;
					}
				}
			}else{
				err_show_buzhichi__(p,1);
			}
		}
		return;
	}
	if((*p)[0]=="标题"){
		if(p->size()<2){
			cpy__(buf,main_win_->get_title().c_str(),siz);
		}else{
			main_win_->set_title((*p)[1]);
		}
		return;
	}
	if((*p)[0]=="窗口最大化"){
		main_win_->maximize();
		return;
	}
	if((*p)[0]=="窗口取消最大化"){
		main_win_->unmaximize();
		return;
	}
	if((*p)[0]=="窗口最小化"){
		main_win_hide__();
		return;
	}
	if((*p)[0]=="窗口恢复"){
		main_win_show__();
		return;
	}
	if((*p)[0]=="窗口"){
		cpy__(buf,(long)main_win_->gobj()->default_widget,siz);
		return;
	}
	if((*p)[0]=="窗"){
		cpy__(buf,(long)main_win_->gobj(),siz);
		return;
	}
#ifndef ver_exe_
	if((*p)[0]=="xid"){
		Glib::RefPtr<Gdk::Window> w1;
		if(p->size()>1){
			Gtk::Widget* w;
			builder_->get_widget((*p)[1], w);
			if(!w){
				err_show_wufa__(p,1);
				return;
			}
			w1=w->get_window();
			if(!w1){
				err_show_wufa__(p,1);
				return;
			}
		}else
			w1=main_win_->get_window();
		//GDK_WINDOW_XID(Glib::unwrap(window.get_window()))
		//cpy__(buf,(long)gdk_x11_drawable_get_xid(w1->gobj()),siz);
		sprintf(buf,"%lu",GDK_WINDOW_XID(w1->gobj()));
		return;
	}
#endif
	if((*p)[0]=="终止"){
		main_quit__();
		return;
	}
	if((*p)[0]=="不堵塞"){
		for(;main_->events_pending();)
			main_->iteration(false);
		return;
	}
	if((*p)[0]=="错误提示到控制台"){
		err_show_to_console_=p->size()<2?true:bool__((*p)[1]);
		return;
	}
	if((*p)[0]=="代码"){
		if(p->size()>1){
			src_+=(*p)[1];
		}else
			*addr_ret=dup__(src_.c_str());
		return;
	}

	if(p->size()<2){
		err_show_buzhichi__(p);
		err_show_buzu__(p);
		return;
	}
	if((*p)[0]=="错误提示到框"){
		if((*p)[1][0])
			builder_->get_widget((*p)[1], err_view_);
		else
			err_view_=NULL;
		return;
	}
	if((*p)[0]=="提示"){
		const Glib::ustring& text=(*p)[1];
		Glib::ustring title;
		GtkDialogFlags flags;
		GtkMessageType type;
		GtkButtonsType buttons;
		flags=GTK_DIALOG_DESTROY_WITH_PARENT;
		type=GTK_MESSAGE_INFO;
		buttons=GTK_BUTTONS_OK;
		switch(p->size()){
			case 6:
				flags=(GtkDialogFlags)s2i__((*p)[5],flags);
			case 5:
				buttons=(GtkButtonsType)s2i__((*p)[4],buttons);
			case 4:
				type=(GtkMessageType)s2i__((*p)[3],type);
			case 3:
				title=(*p)[2];
				break;
		}
		GtkWidget* dialog = gtk_message_dialog_new (main_win_->gobj(),
			flags,type,buttons,"%s",text.c_str());
		gtk_window_set_title(GTK_WINDOW(dialog), title.c_str());
		cpy__(buf,gtk_dialog_run(GTK_DIALOG(dialog)),siz);
		gtk_widget_destroy (dialog);
		return;
	}
	if((*p)[0]=="返回码"){
		exit_=s2i__((*p)[1],exit_);
		return;
	}

	if((*p)[0]=="有"){
		Gtk::Widget* w;
		builder_->get_widget((*p)[1], w);
		cpy__(buf,w?"1":"0",siz);
		return;
	}
	err_show_buzhichi__(p);
}

extern Glib::ustring null_;
bool shell___::bool__(const string& s){
	if(s=="0")
		return false;
	if(s.length()<1||s==null_||s=="false")
		return false;
	return true;
}
