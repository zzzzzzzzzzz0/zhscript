/*
 * timeout___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "timeout___.h"
#include"plugin_def.h"
#include"util.cpp"

class item___{
private:
	Glib::ustring name_;
	char type_;
	timeout___* to_;
	int argc_;
	const char**argv_;
	std::deque<Glib::ustring> argv0_;
	void free_arg__(){
		if(argc_>0){
			argv0_.clear();
			delete argv_;
			argc_=0;
		}
	}
public:
	guint id_;
	Glib::ustring code_;
	bool pause_;
	item___(timeout___* to,const Glib::ustring& name,char type){
		to_=to;
		name_=name;
		type_=type;
		pause_=false;
		argc_=0;
	}
	~item___(){
		free_arg__();
	}
	void add_arg__(std::deque<Glib::ustring>* p){
		free_arg__();
		int start=4;
		argc_=p->size()-start;
		if(argc_>0){
			argv_=new const char*[argc_];
			for(int i=0;i<argc_;i++){
				argv0_.push_back((*p)[start+i]);
				argv_[i]=argv0_[argv0_.size()-1].c_str();
			}
		}
	}
	const Glib::ustring& name__(){return name_;}
	void stop__(){
		gtk_timeout_remove(id_);
	}
	void on__(){
		if(pause_)
			return;
		if(type_=='1')
			stop__();
		to_->d_(to_->sh_,call4_,code_.c_str(),NULL,to_->name__(),name_.c_str(),name_.c_str(),argc_,argv_,0);
	}
};

gboolean timeout_cb__(gpointer data) {
	item___* t=(item___*)data;
	t->on__();
	return true;
}

void* timeout___::timeout_find__(const Glib::ustring& name){
	for(size_t i=0;i<timeouts_.size();i++){
		item___* t=(item___*)timeouts_[i];
		if(t->name__()==name)
			return t;
	}
	return NULL;
}

int timeout___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	char type;
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		type='t';
	}else if((*p)[0]=="一次" "定时器"){
		if(siz==-1)return 1;
		type='1';
	}else
		return 0;

	if(p->size()<2){
		d_(sh_,err_show_buzu_,p);
		return 1;
	}
	const Glib::ustring&name=(*p)[1];
	item___* t=(item___*)timeout_find__(name);
	if(p->size()>2){
		const Glib::ustring&p2=(*p)[2];
		if(p2=="移除"){
			if(t){
				t->stop__();
				cpy__(buf,"1",siz);
			}
			return 1;
		}
		if(p2=="暂停"){
			if(t){
				t->pause_=true;
				cpy__(buf,"1",siz);
			}
			return 1;
		}
		if(p2=="取消暂停"){
			if(t){
				t->pause_=false;
				cpy__(buf,"1",siz);
			}
			return 1;
		}
	}
	guint32 i=1000;
	if(p->size()>2){
		const Glib::ustring&p2=(*p)[2];
		if(p2.size()>0){
			int i1=1;
			switch(p2[p2.size()-1]){
			case'h':
				i1*=60;
			case'm':
				i1*=60;
			case's':
				i1*=1000;
				(*p)[2].erase(p2.size()-1,1);
				break;
			}
			i=s2u__(p2,0)*i1;
		}
	}
	if(!t){
		t=new item___(this,name,type);
	}else{
		t->stop__();
	}
	if(p->size()>3)
		t->code_=(*p)[3];
	t->add_arg__(p);
	t->id_=gtk_timeout_add(i,timeout_cb__,t);
	timeouts_.push_back(t);
	return 1;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new timeout___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

