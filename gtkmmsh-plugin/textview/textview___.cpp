/*
 * textview___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "textview___.h"
#include"plugin_def.h"
#include"util.cpp"

int s2i_plus__(const Glib::ustring& s,int defa){
	return s[0]=='+'?defa+s2i__(s.substr(1)):s2i__(s,defa);
}

class control___:GObject{
private:
	shell___*sh_;
	direct___ d_;
	Glib::ustring code_,zhao_,dong_,xin_;
public:
	control___(shell___*sh,direct___ d,const Glib::ustring&zhao,const Glib::ustring&dong,const Glib::ustring&xin){
		sh_=sh;
		d_=d;
		zhao_=zhao;
		dong_=dong;
		xin_=xin;
	}
	void code__(const Glib::ustring&code){code_=code;}
	void set_manage(){}
	void modified_changed__(){
		if(code_.empty())
			d_(sh_,on_,NULL,NULL,3,zhao_.c_str(),dong_.c_str(),xin_.c_str());
		else
			d_(sh_,on_,code_.c_str(),NULL,2,zhao_.c_str(),dong_.c_str());
	}
};

int textview___::insert__(std::deque<Glib::ustring>* p,size_t start){
	Gtk::TextView* tv=tv__(p,1+start);
	if(!tv){
		return 1;
	}
	int i=0;
	size_t i_ctl=3+start;
	if(p->size()>i_ctl){
		if((*p)[i_ctl]=="头")
			i=1;
		else if((*p)[i_ctl]=="尾")
			i=2;
		else{
			d_(sh_,err_show_buzhichi_,2,p,i_ctl);
			return 1;
		}
	}
	Glib::RefPtr < Gtk::TextBuffer > tb = tv->get_buffer();
	Gtk::TextBuffer::iterator i1,i2;
	switch(i){
	case 1:
		i1=tb->begin();
		break;
	case 2:
		i1=tb->end();
		break;
	default:
		tb->get_selection_bounds(i1,i2);
		if(i2>i1){
			i1=tb->erase(i1,i2);
		}
		break;
	}
	Gdk::Rectangle rect;
	tv->get_visible_rect(rect);
	int y = -1;
	int height = -1;
	tv->get_line_yrange(i1, y, height);
	tb->place_cursor(tb->insert(i1, (*p)[2+start]));
	if (y < rect.get_y() + rect.get_height() + 16)
		 tv->scroll_to_mark(tb->get_insert(), 0);
	return 1;
}

int textview___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	char sdz=0;
	if((*p)[0]=="插入"){
		if(siz==-1)return 1;
		sdz='i';
	}else if((*p)[0]==name__()){
		if(siz==-1)return 1;
		sdz='t';
	}else
		return 0;
	if(p->size()<=2){
		d_(sh_,err_show_buzu_,p);
		return 1;
	}
	switch(sdz){
	case'i':
		return insert__(p,0);
	case't':
	{
		Gtk::TextView* tv;
		char sdz1=0;
		const Glib::ustring& p1=(*p)[1];
		if(p1=="剪切")
			sdz1='x';
		else if(p1=="复制")
			sdz1='c';
		else if(p1=="粘贴")
			sdz1='v';
		else if(p1=="已修改")
			sdz1='m';
		else if(p1=="内容")
			sdz1=' ';
		else if(p1=="焦点")
			sdz1='.';
		else if(p1=="不可编辑")
			sdz1='e';
		else if(p1=="光标位置")
			sdz1='p';
		else if(p1=="光标行列")
			sdz1='l';
		else if(p1=="选择")
			sdz1='S';
		else if(p1=="插入")
			return insert__(p,1);
		else{
			switch(sdz){
			case't':
				d_(sh_,err_show_buzhichi_,2,p,1);
				return 1;
			}
		}
		tv=tv__(p,2);
		if(!tv)
			return 1;
		Glib::RefPtr < Gtk::TextBuffer > tb = tv->get_buffer();
		switch(sdz1){
		case'x':
		case'c':
		case'v':
		{
			Glib::RefPtr<Gtk::Clipboard> cb = Gtk::Clipboard::get();
			switch(sdz1){
			case'x':
				tb->cut_clipboard(cb);
				break;
			case'c':
				tb->copy_clipboard(cb);
				break;
			case'v':
				tb->paste_clipboard(cb);
				break;
			}
			break;
		}
		case'm':
			if(p->size()>3){
				const Glib::ustring&s=(*p)[3];
				if(s=="侦听"){
					control___* ctl=Gtk::manage(new control___(sh_,d_,(*p)[0],(*p)[2],p1));
					if(p->size()>4)
						ctl->code__((*p)[4]);
					tb->signal_modified_changed().connect(sigc::mem_fun(*ctl,&control___::modified_changed__),false);
				}else
					tb->set_modified(d_(sh_,bool_,s.c_str()));
			}else
				l2s__(tb->get_modified(),buf);
			break;
		case' ':
			if(p->size()>3)
				tb->set_text((*p)[3]);
			else
				*addr_ret=dup__(tb->get_text().c_str());
			break;
		case'.':
			tv->grab_focus();
			break;
		case'e':
			if(p->size()>3)
				tv->set_editable(d_(sh_,bool_,(*p)[3].c_str()));
			else
				tv->set_editable(false);
			break;
		case'p':
		case'l':
		{
			Gtk::TextIter ti=tb->get_iter_at_mark(tb->get_mark("insert"));
			if(sdz1=='l'){
				if(p->size()<=3)
					sprintf(buf,"%d,%d,",ti.get_line (),ti.get_line_offset ());
				else{
					int line_offset=ti.get_line_offset ();
					if(p->size()>3)
						ti.set_line (s2i_plus__((*p)[3],ti.get_line ()));
					if(p->size()>4)
						ti.set_line_offset (s2i_plus__((*p)[4],line_offset));
					tb->place_cursor(ti);
				}
			}else{
				if(p->size()>3){
					ti.set_offset (s2i_plus__((*p)[3],ti.get_offset ()));
					tb->place_cursor(ti);
				}else
					l2s__(ti.get_offset (),buf);
			}
			break;
		}
		case'S':
			if(p->size()>4){
				Gtk::TextIter ti1=tb->begin(),ti2=tb->begin();
				ti1.set_offset(s2i__((*p)[3]));
				ti2.set_offset(s2i__((*p)[4]));
				tb->select_range(ti1,ti2);
			}
			break;
		}
		break;
	}
	}
	return 1;
}

Gtk::TextView* textview___::tv__(std::deque<Glib::ustring>* p,size_t i){
	Gtk::TextView* tv=NULL;
	sh_->builder_->get_widget((*p)[i], tv);
	if(!tv){
		d_(sh_,err_show_wufa_,2,p,i);
		return NULL;
	}
	return tv;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new textview___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

