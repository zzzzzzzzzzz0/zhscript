/*
 * dnd___.h
 *
 *  Created on: 2011-9-24
 *      Author: zzzzzzzzzzz
 */

#ifndef dnd____H_
#define dnd____H_

#include <plugin_base___.h>

class dnd_cb___{
public:
	shell___*sh_;
	direct___ d_;
	Glib::ustring code_;
	char type_;
	GtkWidget* w_;
	int sid_;
	dnd_cb___(char type,GtkWidget* w,shell___*sh,direct___ d){
		sh_=sh;
		d_=d;
		type_=type;
		w_=w;
	}
	void unset__();
};

class dnd___: public plugin_base___ {
private:
	deque<dnd_cb___*> cb_;
	void del__(GtkWidget* w1);
public:
	dnd___(shell___*sh,direct___ d):plugin_base___(sh,d){}
	~dnd___();
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "拖放";}
	int version__(){return 1;}
};

#endif /* dnd____H_ */
