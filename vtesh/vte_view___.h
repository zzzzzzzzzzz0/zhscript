/*
 * vte_window___.h
 *
 *  Created on: 2013年12月12日
 *      Author: zzzzzzzzzzz
 */

#ifndef VTE_VIEW____H_
#define VTE_VIEW____H_
#include "sh-base/view___.h"
#ifdef ver_opt2_
#include <src/vte.h>
#else
#include <vte/vte.h>
#endif

class vte_view___: public view___ {
private:
	GPid  pid_;
	glong col_old_, row_old_;
	string outext_;
	void reset_old__();
public:
	vte_view___(GtkWidget* scrolled2, void* window);
	VteTerminal* handle__() {return VTE_TERMINAL(widget_);}

	int fork_command__(const char* cmd, const char* env,
			const char* wd);
	GPid pid__() {return pid_;}
	void reset__();
	void mk_outext__();
	const char* outext__() {return outext_.c_str();}
	bool change_;
};
#endif /* VTE_VIEW____H_ */
