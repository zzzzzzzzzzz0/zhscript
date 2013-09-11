/*
 * common___.cpp
 *
 *  Created on: 2010-11-4
 *      Author: zzzzzzzzzzz
 */

#include "common___.h"
#include"plugin_def.h"
#include "util.cpp"
#include "def1.h"

class control___{
private:
	Glib::ustring argv_[8];
	int argc_;
	shell___* sh_;
	direct___ d_;
	Glib::ustring code_;
	void init1__(shell___* sh,direct___ d){
		argc_=0;
		sh_=sh;
		d_=d;
	}
	void add_arg__(const char*s){
		argv_[argc_++]=s;
	}
public:
	control___(const char*zhao,const char*dong,shell___* sh,direct___ d,const char*code,const char*arg3){
		init1__(sh,d);
		code_=code;
		add_arg__(zhao);
		add_arg__(dong);
		add_arg__(arg3);
	}
	control___(const char*zhao,const char*dong,shell___* sh,direct___ d,const char*code,const char*arg3,const char*arg4){
		init1__(sh,d);
		code_=code;
		add_arg__(zhao);
		add_arg__(dong);
		add_arg__(arg3);
		add_arg__(arg4);
	}
	void on__(){
		switch(argc_){
		/*case 2:
			d_(sh_,on_,code_.c_str(),NULL,2,argv_[0].c_str(),argv_[1].c_str());
			break;*/
		case 3:
			d_(sh_,on_,code_.c_str(),NULL,3,argv_[0].c_str(),argv_[1].c_str(),argv_[2].c_str());
			break;
		case 4:
			d_(sh_,on_,code_.c_str(),NULL,4,argv_[0].c_str(),argv_[1].c_str(),argv_[2].c_str(),argv_[3].c_str());
			break;
		}
	}

	bool on1__(GdkEventButton* eb){
		char buf[16],bufx[32],bufy[32];
		l2s__(eb->button,buf);
		d2s__(eb->x,bufx);
		d2s__(eb->y,bufy);
		switch(argc_){
		/*case 2:
			d_(sh_,on_,code_.c_str(),NULL,5,argv_[0].c_str(),argv_[1].c_str(),buf,bufx,bufy);
			break;*/
		case 3:
			d_(sh_,on_,code_.c_str(),NULL,6,argv_[0].c_str(),argv_[1].c_str(),argv_[2].c_str(),buf,bufx,bufy);
			break;
		/*case 4:
			d_(sh_,on_,code_.c_str(),NULL,7,argv_[0].c_str(),argv_[1].c_str(),argv_[2].c_str(),argv_[3].c_str(),buf,bufx,bufy);
			break;*/
		}
		return true;
	}
};

Gtk::Window* common___::w__(std::deque<Glib::ustring>* p,size_t i){
	if(p->size()<=i)
		return sh_->main_win_;
	Gtk::Window* w;
	sh_->builder_->get_widget((*p)[i], w);
	if(!w){
		d_(sh_,err_show_wufa_,2,p,i);
	}
	return w;
}

int common___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	const Glib::ustring& p0=(*p)[0];

	if(p0=="剪贴板"){
		if(siz==-1)return 1;
		Glib::RefPtr<Gtk::Clipboard> cb = Gtk::Clipboard::get();
		if(p->size()>1)
			cb->set_text((*p)[1].c_str());
		else
			*addr_ret=dup__(cb->wait_for_text().c_str());
		return 1;
	}
	if(p0=="全屏"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		w->fullscreen();
		return 1;
	}
	if(p0=="取消全屏"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		w->unfullscreen();
		return 1;
	}
	if(p0=="置顶"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		w->set_keep_above(true);
		return 1;
	}
	if(p0=="取消置顶"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		w->set_keep_above(false);
		return 1;
	}
	if(p0=="无边框"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		w->set_decorated(false);
		return 1;
	}
	if(p0=="跳过任务栏"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		w->set_skip_taskbar_hint(true);
		return 1;
	}
	if(p0=="窗口活动"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,1);
		if(!w)
			return 1;
		cpy__(buf,w->property_is_active(),siz);
		return 1;
	}
	if(p0=="图标"){
		if(siz==-1)return 1;
		Gtk::Window* w=w__(p,2);
		if(!w)
			return 1;
		if(p->size()>1){
			const Glib::ustring& p1=(*p)[1];
			w->set_icon_name(p1);
			Glib::RefPtr<Gdk::Pixbuf> pb=Gdk::Pixbuf::create_from_file(p1);
			if(pb)
				w->set_icon(pb);
		}else
			cpy__(buf,w->get_icon_name().c_str(),siz);
		return 1;
	}

	if(p->size()<2){
		return 0;
	}
	const Glib::ustring& p1=(*p)[1];

	Gtk::Entry* e;
	Gtk::Label* l;
	Gtk::Button* b;
	Gtk::ToolButton* tb;
	Gtk::TextView* tv;
	Gtk::Notebook* n;
	Gtk::Bin* bI;
	Gtk::Widget* w;
	Gtk::Statusbar* sB;
	Gtk::FileChooserButton* fcb;
	Gtk::ToggleButton* tOb;//CheckButton RadioButton
	Gtk::ToggleToolButton*ttb;
	//Gtk::RadioButtonGroup* rbg;
	Gtk::MenuItem* mi;
	Gtk::CheckMenuItem* cmi;
	Gtk::SpinButton* sb;

	if(p0=="窗口标题"){
		if(siz==-1)return 1;
		Gtk::Window* w1;
		if(p1=="")
			w1=sh_->main_win_;
		else{
			sh_->builder_->get_widget(p1, w);
			if(!w){
				d_(sh_,err_show_wufa_,2,p,1);
				return 1;
			}
			w1=(Gtk::Window*)w;
		}
		if(p->size()<3){
			cpy__(buf,w1->get_title().c_str(),siz);
		}else{
			w1->set_title((*p)[2]);
		}
		return 1;
	}

	if(p0=="内容"){
		if(siz==-1)return 1;
		Glib::ustring text;
		bool read=false;
		int start=2;
		if(p->size()>2&&(*p)[2]=="读取"){
			read=true;
			start=3;
		}
		for(size_t i=start;i<p->size();i++){
			if((*p)[i]=="源码")
				text+=sh_->src_;
			else{
				if(read){
					string name=sh_->ui_file_;
					size_t i1=name.rfind('/');
					if(i1==string::npos)
						i1=name.rfind('\\');
					if(i1!=string::npos)
						name=name.substr(0,i1+1);
					name+=(*p)[i];
					file_get__(name.c_str(),text);
				}else
					text+=(*p)[i];
			}
		}
		if(p1=="源码"){
			if(p->size()>2)
				sh_->src_=text;
			else
				*addr_ret=dup__(sh_->src_.c_str());
			return 1;
		}else{
			sh_->builder_->get_widget(p1, sb);
			if(sb){
				if(p->size()>2){
					float f=0;
					sscanf(text.c_str(),"%f",&f);
					sb->set_value(f);
					return 1;
				}
			}
			sh_->builder_->get_widget(p1, e);
			if(e){
				if(p->size()<3){
					*addr_ret=dup__(e->get_text().c_str());
				}else{
					e->set_text(text);
				}
				return 1;
			}
			sh_->builder_->get_widget(p1, l);
			if(l){
				if(p->size()<3){
					*addr_ret=dup__(l->get_text().c_str());
				}else{
					l->set_markup(text);
				}
				return 1;
			}
			sh_->builder_->get_widget(p1, tv);
			if(tv){
				if(p->size()<3){
					*addr_ret=dup__(tv->get_buffer()->get_text().c_str());
				}else{
					tv->get_buffer()->set_text(text);
				}
				return 1;
			}
			sh_->builder_->get_widget(p1, fcb);
			if(fcb){
				if(p->size()<3){
					*addr_ret=dup__(fcb->get_filename().c_str());
				}else{
					fcb->set_filename(text);

					  /*GtkFileChooser *chooser=(GtkFileChooser *)fcb->gobj();
					  const gchar    *filename=text.c_str();
					  gtk_file_chooser_unselect_all (chooser);
					  //gtk_file_chooser_select_filename (chooser, filename);
					  GFile *file;
					  gboolean result;
					  file = g_file_new_for_path (filename);
					  result = gtk_file_chooser_select_file (chooser, file, NULL);
//#define GTK_FILE_CHOOSER_GET_IFACE(inst)  (G_TYPE_INSTANCE_GET_INTERFACE ((inst), GTK_TYPE_FILE_CHOOSER, GtkFileChooserIface))
					  //result = GTK_FILE_CHOOSER_GET_IFACE (chooser)->select_file (chooser, file, NULL);
					  g_object_unref (file);*/
				}
				return 1;
			}
			sh_->builder_->get_widget(p1, tOb);
			if(tOb){
				if(p->size()<3){
					cpy__(buf,tOb->get_label().c_str(),siz);
				}else{
					tOb->set_label(text);
				}
				return 1;
			}
			sh_->builder_->get_widget(p1, sB);
			if(sB){
				if(p->size()<3){
				}else{
					sB->push(text,sB->get_context_id(text));
					return 1;
				}
			}
			sh_->builder_->get_widget(p1, n);
			if(n){
				if(p->size()<3){
					cpy__(buf,n->get_current_page()+1,siz);
				}else{
					n->set_current_page(s2i__(text,1)-1);
				}
				return 1;
			}
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="勾选"){
		if(siz==-1)return 1;
		if(p->size()>2){
			bool b=d_(sh_,bool_,(*p)[p->size()-1].c_str());
			for(size_t i=1;i<p->size()-1;i++){
				sh_->builder_->get_widget((*p)[i], tOb);
				if(tOb){
					tOb->set_active(b);
					continue;
				}
				sh_->builder_->get_widget((*p)[i], ttb);
				if(ttb){
					ttb->set_active(b);
					continue;
				}
				sh_->builder_->get_widget((*p)[i], cmi);
				if(cmi){
					cmi->set_active(b);
					continue;
				}
				d_(sh_,err_show_wufa_,2,p,i);
				return 1;
			}
		}else{
			sh_->builder_->get_widget(p1, tOb);
			if(tOb){
				cpy__(buf,tOb->get_active(),siz);
				return 1;
			}
			sh_->builder_->get_widget(p1, ttb);
			if(ttb){
				cpy__(buf,ttb->get_active(),siz);
				return 1;
			}
			sh_->builder_->get_widget(p1, cmi);
			if(cmi){
				cpy__(buf,cmi->get_active(),siz);
				return 1;
			}
			d_(sh_,err_show_wufa_,2,p,1);
		}
		return 1;
	}
	if(p0=="提示文字"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, w);
		if(w){
			if(p->size()<3){
				cpy__(buf,w->get_tooltip_markup().c_str(),siz);
			}else{
				w->set_tooltip_markup((*p)[2]);
			}
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="焦点"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, w);
		if(w){
			w->grab_focus();
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="侦听"){
		if(siz==-1)return 1;
		if(p->size()>2){
			if(p1=="点击"){
				Glib::ustring code;
				size_t size=p->size();
				if(size>=4)
					code=(*p)[--size];
				for(size_t i=2;i<size;i++){
					if((*p)[i].length()==0)
						continue;
					Glib::SignalProxy0< void >* sp0=NULL;
					Glib::SignalProxy1< bool, GdkEventButton* >* sp1=NULL;
					Glib::ustring dong;
					bI=NULL;
					w=NULL;
					for(;;){
						sh_->builder_->get_widget((*p)[i], b);
						if(b){
							bI=b;
							w=b;
							dong=b->get_label();
							sp0=&b->signal_clicked();
							break;
						}

						sh_->builder_->get_widget((*p)[i], tb);
						if(tb){
							bI=tb;
							w=tb;
							dong=tb->get_label();
							sp0=&tb->signal_clicked();
							break;
						}

						sh_->builder_->get_widget((*p)[i], mi);
						if(mi){
							bI=mi;
							w=mi;
							sp1=&mi->signal_button_press_event();
							break;
						}

						sh_->builder_->get_widget((*p)[i], w);
						if(w){
							sp1=&w->signal_button_press_event();
							break;
						}

						d_(sh_,err_show_wufa_,3,p,i,0);
						return 1;
					}

					if(w){
						const char*arg4;
						if(dong.empty()){
							dong=(*p)[i];
							arg4=NULL;
						}else
							arg4=(*p)[i].c_str();
						control___* c;
						const char*zhao;
						const char*arg3;
						//不buf会乱指
						Glib::ustring buf3;
						if(w==mi){
							zhao="菜单";
							buf3=mi->get_label();
						}else{
							zhao=bI!=NULL?"按钮":p1.c_str();
							buf3=w->get_tooltip_text();
						}
						arg3=buf3.c_str();
						if(!arg4)
							c=new control___(zhao,dong.c_str(),sh_,d_,code.c_str(),arg3);
						else
							c=new control___(zhao,dong.c_str(),sh_,d_,code.c_str(),arg3,arg4);
						if(sp0)
							sp0->connect(sigc::mem_fun(*c, &control___::on__));
						else if(sp1)
							sp1->connect(sigc::mem_fun(*c, &control___::on1__));
						w->set_data("ctl",c);
						if(p->size()==4)
							break;
					}
				}
				return 1;
			}
			d_(sh_,err_show_wufa_,2,p,1);
			return 1;
		}
		d_(sh_,err_show_buzu_,p);
		return 1;
	}
	if(p0=="点击"){
		if(siz==-1)return 1;
		for(size_t i=1;i<p->size();i++){
			w=NULL;
			for(;;){
				sh_->builder_->get_widget((*p)[i], b);
				if(b){
					w=b;
					break;
				}
				sh_->builder_->get_widget((*p)[i], tb);
				if(tb){
					w=tb;
					break;
				}
				sh_->builder_->get_widget((*p)[i], mi);
				if(mi){
					w=mi;
					break;
				}
				sh_->builder_->get_widget((*p)[i], w);
				if(w){
					break;
				}
				d_(sh_,err_show_wufa_,3,p,i,0);
				return 1;
			}
			control___* c=(control___*)w->get_data("ctl");
			if(!c){
				d_(sh_,err_show_wufa_,3,p,i,0);
				return 1;
			}
			c->on__();
		}
		return 1;
	}
	if(p0=="可见"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, w);
		if(w){
			if(p->size()>2){
				bool b=d_(sh_,bool_,(*p)[p->size()-1].c_str());
				for(size_t i=1;i<p->size()-1;i++){
					sh_->builder_->get_widget((*p)[i], w);
					if(w)
						w->set_visible(b);
					else
						d_(sh_,err_show_wufa_,2,p,i);
				}
			}else
				cpy__(buf,w->get_visible(),siz);
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="可见状态"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, e);
		if(e){
			bool b;
			if(p->size()>2)
				b=d_(sh_,bool_,(*p)[2].c_str());
			else
				b=!e->get_visibility();
			e->set_visibility(b);
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="敏感"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, w);
		if(w){
			if(p->size()>2){
				bool b=d_(sh_,bool_,(*p)[p->size()-1].c_str());
				for(size_t i=1;i<p->size()-1;i++){
					sh_->builder_->get_widget((*p)[i], w);
					if(w)
						w->set_sensitive(b);
					else
						d_(sh_,err_show_wufa_,2,p,i);
				}
			}else
				cpy__(buf,w->get_sensitive(),siz);
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="区域信息"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, w);
		if(w){
			Gtk::Allocation a=w->get_allocation();
			sprintf(buf,"%d,%d,%d,%d,",a.get_x(),a.get_y(),a.get_width(),a.get_height());
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="鼠标"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, w);
		if(w){
			gint  x,y;
			/*Glib::RefPtr<Gdk::Window> w2=w->get_window();
			w2->get_pointer(x,y,);*/
			w->get_pointer(x,y);
			sprintf(buf,"%d,%d,",x,y);
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="数目"){
		if(siz==-1)return 1;
		sh_->builder_->get_widget(p1, n);
		if(n){
			sprintf(buf,"%d",n->get_n_pages());
			return 1;
		}
		d_(sh_,err_show_wufa_,2,p,1);
		return 1;
	}
	if(p0=="遍历"){
		if(siz==-1)return 1;
		const Glib::ustring& code=(*p)[p->size()-1];
		bool exe=true;
		char s1[16];
		const char*argv[]={s1};
		int err;
		for(size_t i=1;i<p->size()-1&&exe;i++){
			sh_->builder_->get_widget((*p)[i], n);
			if(n){
				for(int pn=0;pn<n->get_n_pages();pn++){
					w=n->get_nth_page(pn);
					sprintf(s1,"%d",pn+1);
					d_(sh_,call4_1_,code.c_str(),shangji,NULL,NULL,NULL,1,argv,0,ce,&err);
					if(err){
						if(err==jieshiqi_go_+keyword_break_)
							break;
						if(err==jieshiqi_go_+keyword_continue_)
							continue;
						if(err==jieshiqi_go_+keyword_exit_){
							exe=false;
							break;
						}
						d_(sh_,call4_2_,err);
						return 1;
					}
				}
				continue;
			}
			d_(sh_,err_show_wufa_,2,p,i);
		}
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new common___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
