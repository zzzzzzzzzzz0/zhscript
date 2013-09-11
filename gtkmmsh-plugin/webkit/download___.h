/*
 * download___.h
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */

#ifndef DOWNLOAD____H_
#define DOWNLOAD____H_
//#ifdef ver_3_
#include"control___.h"

class download___{
private:
	control___*c_;
	Glib::ustring sdz_,url_,code_;
	int argc_;
	char arg0_[16];
	const char**argv_;
	std::deque<Glib::ustring> argv1_;
	Glib::ustring filename_;
public:
	download___(std::deque<Glib::ustring>* p,control___*c);
	~download___();
	const char* status__(int i);
	const char*filename__(){return filename_.c_str();}
};

void zhenting_download__(WebKitWebView *wwv);
void new_download__(std::deque<Glib::ustring>* p,WebKitWebView *wwv);

//#endif
#endif /* DOWNLOAD____H_ */
