/*
 * clipboard.cpp
 *
 *  Created on: 2014年3月2日
 *      Author: zzzzzzzzzzz
 */

#include <gtk/gtk.h>
#include <string.h>
#include "../new_gg/def1.h"
#include "../new_gg/call_util.cpp"

static GtkClipboard *cb__() {
	return gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
}

dlle___ void cb_set_text__(const char* s) {
	if(!s)
		return;
	GtkClipboard *cb = cb__();
	if(!cb)
		return;
	gtk_clipboard_set_text(cb, s, strlen(s));
}

dlle___ void cb_get_text__(char** addr_ret) {
	GtkClipboard *cb = cb__();
	if(!cb)
		return;
	const char* s = gtk_clipboard_wait_for_text(cb);
	if(!s)
		return;
	*addr_ret = dup__(s);
	g_free((void*)s);
}

dlle___ void cb_clear__() {
	GtkClipboard *cb = cb__();
	if(!cb)
		return;
	gtk_clipboard_clear(cb);
}
