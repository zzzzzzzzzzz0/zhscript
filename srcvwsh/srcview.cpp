/*
 * srcview.cpp
 *
 *  Created on: 2016年1月21日
 *      Author: zzzzzzzzzzz
 */

#include "srcview.h"

src_view___::src_view___(GtkWidget* scrolled2, void* window):view___(scrolled2, window) {
	buf_ = GTK_SOURCE_BUFFER (gtk_source_buffer_new (NULL));

	widget_ = gtk_source_view_new_with_buffer(buf_);
	gtk_container_add (GTK_CONTAINER (scrolled2), widget_);

	GtkSourceView* sv = handle__();
	gtk_source_view_set_show_line_numbers(sv, true);
	gtk_source_view_set_tab_width(sv, 4);
	gtk_source_view_set_auto_indent (sv, true);
	gtk_source_view_set_smart_home_end(sv, GTK_SOURCE_SMART_HOME_END_ALWAYS);
	gtk_source_view_set_draw_spaces (sv, GTK_SOURCE_DRAW_SPACES_ALL);
	gtk_widget_set_can_focus(widget_, true);
}

void src_view___::scroll2__(GtkTextIter* ti) {
	gtk_text_buffer_place_cursor(buf2__(), ti);
	GtkTextIter i1,i2;
	gtk_text_buffer_get_selection_bounds (buf2__(), &i1,&i2);

	GdkRectangle rect;
	gtk_text_view_get_visible_rect (handle2__(), &rect);
	int y = -1;
	int height = -1;
	gtk_text_view_get_line_yrange (handle2__(), &i1, &y, &height);
	if (y < rect.y + rect.height + 16)
		gtk_text_view_scroll_to_mark (handle2__(), gtk_text_buffer_get_insert(buf2__()), 0, false, 0, 0);
}

char* src_view___::text__() {
	GtkTextIter start, end;
	gtk_text_buffer_get_start_iter (buf2__(), &start);
	gtk_text_buffer_get_end_iter (buf2__(), &end);
	return gtk_text_buffer_get_text (buf2__(), &start, &end, FALSE);
}
