/*
 * srcview.h
 *
 *  Created on: 2016年1月21日
 *      Author: zzzzzzzzzzz
 */

#ifndef SRCVWSH_SRCVIEW_H_
#define SRCVWSH_SRCVIEW_H_
#include "sh-base/view___.h"
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcebuffer.h>

class src_view___ : public view___ {
public:
	src_view___(GtkWidget* scrolled2, void* window);
	GtkSourceView* handle__() {return GTK_SOURCE_VIEW (widget_);}
	GtkTextView* handle2__() {return GTK_TEXT_VIEW (widget_);}
	GtkSourceBuffer *buf__() {return buf_;}
	GtkTextBuffer* buf2__() {return GTK_TEXT_BUFFER (buf_);}

	void scroll2__(GtkTextIter* ti);
	//g_free (text);
	char* text__();
private:
	GtkSourceBuffer *buf_;
};

#endif /* SRCVWSH_SRCVIEW_H_ */
