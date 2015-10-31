/*
 * sourceview___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "sourceview___.h"
#include"plugin_def.h"
#include"util.cpp"
/*#include <gtksourceviewmm/sourceview.h>
#include <gtksourceviewmm/sourcelanguage.h>
#include <gtksourceviewmm/sourcelanguagemanager.h>*/

#ifdef ver_all_
int s2i_plus__(const ustring& s,int defa){
	return s[0]=='+'?defa+s2i__(s.substr(1)):s2i__(s,defa);
}
#endif

class control___:GObject{
private:
	shell___*sh_;
	direct___ d_;
	ustring code_,zhao_,dong_,xin_;
public:
	control___(shell___*sh,direct___ d,const ustring&zhao,const ustring&dong,const ustring&xin){
		sh_=sh;
		d_=d;
		zhao_=zhao;
		dong_=dong;
		xin_=xin;
	}
	void code__(const ustring&code){code_=code;}
	void set_manage(){}
	void modified_changed__(){
		if(code_.empty())
			d_(sh_,on_,NULL,NULL,3,zhao_.c_str(),dong_.c_str(),xin_.c_str());
		else
			d_(sh_,on_,code_.c_str(),NULL,2,zhao_.c_str(),dong_.c_str());
	}
};

#ifdef ver_all_
int sourceview___::insert__(deque<ustring>* p,size_t start){
	SourceView*sv=tv__(p,1+start);
	if(!sv){
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
	RefPtr < Gtk::TextBuffer > tb = sv->get_buffer();
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
	scroll2__(sv,tb->insert(i1, (*p)[2+start]));
	return 1;
}
void sourceview___::scroll2__(SourceView*sv,Gtk::TextIter ti){
	RefPtr<Gtk::TextBuffer> tb=sv->get_buffer();
	tb->place_cursor(ti);
	Gtk::TextBuffer::iterator i1,i2;
	tb->get_selection_bounds(i1,i2);

	Gdk::Rectangle rect;
	sv->get_visible_rect(rect);
	int y = -1;
	int height = -1;
	sv->get_line_yrange(i1, y, height);
	if (y < rect.get_y() + rect.get_height() + 16)
		 sv->scroll_to_mark(tb->get_insert(), 0);
}
#endif

int sourceview___::proc__(deque<ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	char sdz=0;
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		sdz='s';
	}else
		return 0;
	if(p->size()<=2){
		d_(sh_,err_show_buzu_,p);
		return 1;
	}
	switch(sdz){
	case's':
	{
		SourceView* sv=NULL;
		char sdz1=0;
		const ustring& p1=(*p)[1];
		if(p1=="撤销")
			sdz1='u';
		else if(p1=="重做")
			sdz1='r';
		else if(p1=="撤销不记始")
			sdz1='B';
		else if(p1=="撤销不记终")
			sdz1='E';
		else if(p1=="语法高亮")
			sdz1='h';
#ifdef ver_all_
		else if(p1=="剪切")
			sdz1='x';
		else if(p1=="复制")
			sdz1='c';
		else if(p1=="粘贴")
			sdz1='v';
		else if(p1=="已修改")
			sdz1='m';
		else if(p1=="内容")
			sdz1=' ';
		else if(p1=="打开文件")
			sdz1='o';
		else if(p1=="保存文件")
			sdz1='s';
		else if(p1=="焦点")
			sdz1='.';
		else if(p1=="不可编辑")
			sdz1='e';
		else if(p1=="光标位置")
			sdz1='p';
		else if(p1=="光标行列")
			sdz1='l';
		else if(p1=="插入")
			return insert__(p,1);
#endif
		else{
			switch(sdz){
			case's':
			{
				Gtk::ScrolledWindow* sw;
				sh_->builder_->get_widget((*p)[2], sw);
				if(!sw){
					d_(sh_,err_show_wufa_,2,p,2);
					return 1;
				}

				sv=Gtk::manage(new SourceView());
				sv->set_show_line_numbers(true);
				sv->set_auto_indent (true);
				sv->set_tab_width(4);
				//GTK_SOURCE_SMART_HOME_END_ALWAYS
				sv->set_smart_home_end((SourceSmartHomeEndType)2);
				sv->set_can_focus(true);

				names_[p1]=sv;
				sw->add(*sv);
				sw->show_all_children ();
				return 1;
			}
			}
		}
		sv=tv__(p,2);
		if(!sv)
			return 1;
		RefPtr < SourceBuffer > sb=sv->get_source_buffer();
		switch(sdz1){
#ifdef ver_all_
		case'x':
		case'c':
		case'v':
		{
			RefPtr<Gtk::Clipboard> cb = Gtk::Clipboard::get();
			switch(sdz1){
			case'x':
				sb->cut_clipboard(cb);
				break;
			case'c':
				sb->copy_clipboard(cb);
				break;
			case'v':
				sb->paste_clipboard(cb);
				break;
			}
			break;
		}
		case'm':
			if(p->size()>3){
				const ustring&s=(*p)[3];
				if(s=="侦听"){
					control___* ctl=Gtk::manage(new control___(sh_,d_,(*p)[0],(*p)[2],p1));
					if(p->size()>4)
						ctl->code__((*p)[4]);
					sb->signal_modified_changed().connect(sigc::mem_fun(*ctl,&control___::modified_changed__),false);
				}else
					sb->set_modified(d_(sh_,bool_,s.c_str()));
			}else
				l2s__(sb->get_modified(),buf);
			break;
		case' ':
			if(p->size()>3)
				sb->set_text((*p)[3]);
			else
				*addr_ret=dup__(sb->get_text().c_str());
			break;
		case'o':
			if(p->size()>3){
				ustring s;
				file_get__((*p)[3].c_str(),s);
				sb->set_text(s);
			}
			break;
		case's':
			if(p->size()>3){
				GError *error = NULL;
				g_file_set_contents ((*p)[3].c_str(), sb->get_text().c_str(), -1, &error);
			    if (error != NULL) {
			    	cpy__(buf,error->message,siz);
			        g_clear_error(&error);
			    }
			}
			break;
		case'.':
			sv->grab_focus();
			break;
		case'e':
			if(p->size()>3)
				sv->set_editable(d_(sh_,bool_,(*p)[3].c_str()));
			else
				sv->set_editable(false);
			break;
		case'p':
		case'l':
		{
			Gtk::TextIter ti=sb->get_iter_at_mark(sb->get_mark("insert"));
			if(sdz1=='l'){
				if(p->size()<=3)
					sprintf(buf,"%d,%d,",ti.get_line (),ti.get_line_offset ());
				else{
					int line_offset=ti.get_line_offset ();
					if(p->size()>3)
						ti.set_line (s2i_plus__((*p)[3],ti.get_line ()));
					if(p->size()>4)
						ti.set_line_offset (s2i_plus__((*p)[4],line_offset));
					//sb->place_cursor(ti);
					scroll2__(sv,ti);
				}
			}else{
				if(p->size()>3){
					ti.set_offset (s2i_plus__((*p)[3],ti.get_offset ()));
					//sb->place_cursor(ti);
					scroll2__(sv,ti);
				}else
					l2s__(ti.get_offset (),buf);
			}
			break;
		}
#endif
		case'u':
			if(sb->can_undo())
				sb->undo();
			break;
		case'r':
			if(sb->can_redo())
				sb->redo();
			break;
		case'B':
			sb->begin_not_undoable_action();
			break;
		case'E':
			sb->end_not_undoable_action();
			break;
		case'h':
			if(p->size()>3){
				RefPtr<SourceLanguageManager> slm=SourceLanguageManager::get_default();
				RefPtr<SourceLanguage> sl=slm->get_language((*p)[3]);
				if(sl){
					sb->set_language(sl);
					sb->set_highlight_syntax(true);
					break;
				}
			}
			sb->set_highlight_syntax(false);
			break;
		}
		break;
	}
	}
	return 1;
}

SourceView* sourceview___::tv__(deque<ustring>* p,size_t i){
	SourceView* sv=(SourceView*)get__((*p)[i]);
	if(!sv){
		d_(sh_,err_show_wufa_,2,p,i);
		return NULL;
	}
	return sv;
}

void* sourceview___::get__(const ustring&name){
	map<ustring,void*>::iterator mi=names_.find(name);
	if(mi!=names_.end())
		return mi->second;
	return NULL;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new sourceview___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

