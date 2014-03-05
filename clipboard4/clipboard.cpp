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
	gtk_clipboard_set_text(cb__(), s, strlen(s));
}

dlle___ void cb_get_text__(char** addr_ret) {
	*addr_ret = dup__(gtk_clipboard_wait_for_text(cb__()));
}
