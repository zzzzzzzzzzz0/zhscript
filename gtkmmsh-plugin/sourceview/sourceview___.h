/*
 * sourceview___.h
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#ifndef sourceview____H_
#define sourceview____H_

#include <plugin_base___.h>
#include <gtksourceviewmm.h>
using namespace gtksourceview;
/*#include <gtksourceview/gtksourceview.h>
#define SourceView GtkSourceView*/
using namespace Glib;

#define ver_all_

class sourceview___: public plugin_base___ {
private:
	map<ustring,void*> names_;
	void* get__(const ustring&name);
#ifdef ver_all_
	int insert__(deque<ustring>* p,size_t start);
	void scroll2__(SourceView*sv,Gtk::TextIter ti);
#endif
	SourceView* tv__(deque<ustring>* p,size_t i);
public:
	sourceview___(shell___*sh,direct___ d):plugin_base___(sh,d){
		gtksourceview::init();
	}

	virtual int proc__(deque<ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce);
	void on__(int event){}
	const char* name__(){return "源码框";}
	int version__(){return 1;}
};

#endif /* sourceview____H_ */
