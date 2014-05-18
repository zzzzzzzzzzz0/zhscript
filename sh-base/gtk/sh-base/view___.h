/*
 * view___.h
 *
 *  Created on: 2013年12月15日
 *      Author: zzzzzzzzzzz
 */

#ifndef VIEW____H_
#define VIEW____H_
#include "base_.h"

#define object_data_view_		"v"
#define object_data_scrolled_	"s"

class view___ {
protected:
	GtkWidget* widget_;
	void* window_;
public:
	view___(GtkWidget* scrolled2, void* window);
	GtkWidget* widget__() {return widget_;}
	void* window__() {return window_;}
	static view___* from__(void* v);
	static GtkWidget* scrolled_from__(void* v);

	void signal_connect__(GtkWidget* v);
};

#endif /* VIEW____H_ */
