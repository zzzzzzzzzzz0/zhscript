/*
 * statusicon___.h
 *
 *  Created on: 2010-9-11
 *      Author: zzzzzzzzzzz
 */

#ifndef STATUSICON____H_
#define STATUSICON____H_
#include"plugin_base___.h"

class statusicon___:public plugin_base___{
private:
	Glib::RefPtr<Gtk::StatusIcon> stt_icon_;
	bool stt_icon_keep_;
	bool hide_in_mini_;
	bool only_,show_;
	void main_win_sw__();
public:
	statusicon___(shell___*sh,direct___ d):plugin_base___(sh,d){
		hide_in_mini_=stt_icon_keep_=only_=false;
	}
	virtual int proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event);
	const char* name__(){return "托盘图标";}
	int version__(){return 1;}
};

#endif /* STATUSICON____H_ */
