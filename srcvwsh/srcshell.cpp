/*
 * srcshell.cpp
 *
 *  Created on: 2016年1月21日
 *      Author: zzzzzzzzzzz
 */

#include "srcshell.h"
#include "sh-base/extern.h"
#include "sh-base/extern2.h"
#include "sh-base/callbackitem.h"
#include "gtksourceview/gtksourcelanguagemanager.h"
#include <gtksourceview/gtksourcelanguage.h>
#include <sys/stat.h>

static s1___* new_view_s1_ = new s1___("新开", "", ' ');

src_shell___::src_shell___():shell___() {
}

view___* src_shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	return new src_view___(scrolled2, window);
}

static void modified_changed__ (GtkTextBuffer *textbuffer, gpointer user_data) {
	callback_item___* cbi = (callback_item___*)user_data;
	window___* w = (window___*)cbi->data2_;
	src_view___* v = (src_view___*)cbi->data_;
	string name;
	w->name2__(name, v->scrolled__());
	cbi->call__(0, name.c_str());
}

bool file_get__(const char*name,string& buf){
	gchar *contents;
	gsize length;
	GError *error=NULL;
	if(g_file_get_contents(name,&contents,&length,&error)){
		buf+=contents;
		g_free(contents);
		return true;
	}else{
	    if (error != NULL) {
	    	std::cerr << error->message << std::endl;
	        g_clear_error(&error);
	    }
	    return false;
	}
}

bool src_shell___::api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret) {
	if(p->size() >= 2) {
		const string& p0=(*p)[0];
		const string& p1=(*p)[1];
		int page_num;
		window___* w;
		src_view___* v;
		if(p1 == new_view_s1_->src2__()) {
			string page_num2;
			w=get_window__(p0,page_num,p1, true, &page_num2);if(!w)return true;
			v=(src_view___*)w->view__(page_num);
			if(page_num2.empty() || !v){
				v = (src_view___*)new_page__(page_num2.c_str(), w);
				if(v) {
					call4__(v->scrolled__(), w, new_view_s1_, 0);
				} else {
					err_wufa__(p1);
				}
			} else {
				w->c__()->set_page__(page_num);
			}
			return true;
		}
		char sdz1=0;
		if(p1=="撤销")
			sdz1='u';
		else if(p1=="重做")
			sdz1='r';
		else if(p1=="撤销不记始")
			sdz1='\xa0';
		else if(p1=="撤销不记终")
			sdz1='\xa1';
		else if(p1=="语法高亮")
			sdz1='h';
		else if(p1=="剪切")
			sdz1='x';
		else if(p1=="复制")
			sdz1='c';
		else if(p1=="粘贴")
			sdz1='v';
		else if(p1=="已修改")
			sdz1='m';
		else if(p1=="内容")
			sdz1=' ';
		else if(p1=="打开文件")
			sdz1='o';
		else if(p1=="保存文件")
			sdz1='s';
		/*else if(p1=="焦点")
			sdz1='.';*/
		else if(p1=="不可编辑")
			sdz1='e';
		else if(p1=="光标位置")
			sdz1='p';
		else if(p1=="光标行列")
			sdz1='l';
		else if(p1=="插入")
			sdz1='i';
		else if(p1=="字体")
			sdz1='f';
		else if(p1=="列可语法高亮")
			sdz1='\xf1';
		if(sdz1) {
			w=get_window__(p0,page_num,p1);if(!w)return true;
			v=(src_view___*)w->view__(page_num);
			switch(sdz1) {
			case'x':
			case'c':
			case'v':
			{
				GtkClipboard *cb = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
				switch(sdz1){
				case'x':
					gtk_text_buffer_cut_clipboard(v->buf2__(), cb, true);
					break;
				case'c':
					gtk_text_buffer_copy_clipboard(v->buf2__(), cb);
					break;
				case'v':
					gtk_text_buffer_paste_clipboard(v->buf2__(), cb, NULL, true);
					break;
				}
				break;
			}
			case'm':
				if(p->size()>2){
					const string&s=(*p)[2];
					if(s=="侦听"){
						if(err_buzu2__(p, 4))
							break;
						callback_item___* cbi = new callback_item___(p1, (*p)[3]);
						cbi->data_ = v;
						cbi->data2_ = w;
						g_signal_connect(v->buf2__(), "modified-changed", G_CALLBACK(modified_changed__), cbi);
					}else
						gtk_text_buffer_set_modified(v->buf2__(), bool__(s));
				}else
					l2s__(gtk_text_buffer_get_modified(v->buf2__()),buf);
				break;
			case' ':
				if(p->size()>2) {
					const string&s=(*p)[2];
					bool no_undo = true;
					for(size_t i = 3; i < p->size(); i++) {
						const string& p3=(*p)[i];
						if(p3 == "可撤销") {
							no_undo = false;
							continue;
						}
						err_buzhichi__(p1, p3.c_str());
						return true;
					}
					if(no_undo)
						gtk_source_buffer_begin_not_undoable_action(v->buf__());
					gtk_text_buffer_set_text(v->buf2__(), s.c_str(), s.size());
					if(no_undo)
						gtk_source_buffer_end_not_undoable_action(v->buf__());
				} else {
					char* text = v->text__();
					*addr_ret=dup__(text);
					g_free (text);
				}
				break;
			case'o':
			{
				if(err_buzu2__(p, 3)) break;
				string s;
				if(file_get__((*p)[2].c_str(),s)) {
					gtk_source_buffer_begin_not_undoable_action(v->buf__());
					gtk_text_buffer_set_text(v->buf2__(), s.c_str(), s.size());
					gtk_source_buffer_end_not_undoable_action(v->buf__());
					gtk_text_buffer_set_modified(v->buf2__(), false);
				}
				break;
			}
			case's':
			{
				if(err_buzu2__(p, 3)) break;
				GError *error = NULL;
				const string& filename = (*p)[2];
				char* text = v->text__();
				struct stat st;
				int st_err = stat(filename.c_str(), &st);
				g_file_set_contents (filename.c_str(), text, -1, &error);
				if (error != NULL) {
					cpy__(buf,error->message,siz);
					g_clear_error(&error);
				} else {
					if(!st_err)
						chmod(filename.c_str(), st.st_mode);
				}
				g_free (text);
				break;
			}
			case'e':
				gtk_text_view_set_editable(v->handle2__(), bool__(p, 2));
				break;
			case '\xa0':
				gtk_source_buffer_begin_not_undoable_action(v->buf__());
				break;
			case '\xa1':
				gtk_source_buffer_end_not_undoable_action(v->buf__());
				break;
			case'p':
			case'l':
			{
				GtkTextIter ti;
				gtk_text_buffer_get_iter_at_mark (v->buf2__(), &ti, gtk_text_buffer_get_insert (v->buf2__()));
				if(sdz1=='l'){
					int line = gtk_text_iter_get_line (&ti), line_offset=gtk_text_iter_get_line_offset (&ti);
					if(p->size()<=2)
						sprintf(buf,"%d,%d,",line,line_offset);
					else {
						if(p->size()>2)
							gtk_text_iter_set_line (&ti, s2i__((*p)[2], line));
						if(p->size()>3)
							gtk_text_iter_set_line_offset (&ti, s2i__((*p)[3], line_offset));
						v->scroll2__(&ti);
					}
				} else {
					int offset = gtk_text_iter_get_offset (&ti);
					if(p->size()>2){
						gtk_text_iter_set_offset (&ti, s2i__((*p)[2],offset));
						v->scroll2__(&ti);
					}else
						l2s__(offset,buf);
				}
				break;
			}
			case 'u':
				if(gtk_source_buffer_can_undo(v->buf__()))
					gtk_source_buffer_undo(v->buf__());
				break;
			case 'r':
				if(gtk_source_buffer_can_redo(v->buf__()))
					gtk_source_buffer_redo(v->buf__());
				break;
			case'h':
				if(p->size()>2){
					GtkSourceLanguageManager *slm = gtk_source_language_manager_get_default ();
					GtkSourceLanguage *sl = gtk_source_language_manager_get_language (slm, (*p)[2].c_str());
					if(sl){
						gtk_source_buffer_set_language (v->buf__(), sl);
						gtk_source_buffer_set_highlight_syntax(v->buf__(), true);
						break;
					}
				}
				gtk_source_buffer_set_highlight_syntax(v->buf__(), false);
				break;
			case 'i':
			{
				if(err_buzu2__(p, 3)) return true;
				const string& p2 = (*p)[2];
				GtkTextIter i1;
				bool i1_has_use = false;
				if(p->size() > 3) {
					const string& p3 = (*p)[3];
					i1_has_use = true;
					if(p3 == "头")
						gtk_text_buffer_get_start_iter (v->buf2__(), &i1);
					else if(p3 == "尾")
						gtk_text_buffer_get_end_iter (v->buf2__(), &i1);
					else {
						err_buzhichi__(p1, p3.c_str());
						return true;
					}
				}
				if(!i1_has_use) {
					GtkTextIter i2;
					gtk_text_buffer_get_selection_bounds (v->buf2__(), &i1, &i2);
					if(gtk_text_iter_get_offset (&i2) > gtk_text_iter_get_offset (&i1)){
						gtk_text_buffer_delete(v->buf2__(), &i1,&i2);
					}
				}
				gtk_text_buffer_insert (v->buf2__(), &i1, p2.c_str(), p2.size());
				v->scroll2__(&i1);
				return true;
			}
			case 'f':
			{
				if(err_buzu2__(p, 3)) break;
				PangoFontDescription *font_desc = pango_font_description_from_string ((*p)[2].c_str());
				gtk_widget_modify_font (v->widget__(), font_desc);
				pango_font_description_free (font_desc);
				break;
			}
			case '\xf1':
			{
				if(err_buzu2__(p, 3)) break;
				GtkSourceLanguageManager *slm = gtk_source_language_manager_get_default ();
				const gchar * const *ids = gtk_source_language_manager_get_language_ids (slm);
				char noh[] = {0, 0};
				const char* argv[] = {noh, 0, 0, 0};
				int err = 0;
				for (int i = 0; ids[i] != NULL; i++) {
					const gchar * id = ids[i];
					GtkSourceLanguage *sl = gtk_source_language_manager_get_language (slm, id);
					argv[1] = id;
					/*string mime;
					gchar** mime_types = gtk_source_language_get_mime_types(sl);
					if(mime_types != NULL) {
						for(gchar** mime_type = mime_types; *mime_type != NULL; ++ mime_type) {
							if(!mime.empty())
								mime += ",";
							mime += *mime_type;
						}
						g_strfreev(mime_types);
					}
					argv[1] = mime.c_str();*/
					argv[2] = gtk_source_language_get_name (sl);
					argv[3] = gtk_source_language_get_section (sl);
					noh[0] = '0' + !gtk_source_language_get_hidden (sl);
					const char* ret = call4__(&err, ce, (*p)[2].c_str(), NULL, shangji, 4, argv, 0);
					if(err) {
						err__(err, ret);
						return true;
					}
				}
				break;
			}
			}
			return true;
		}
	}
	return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
}
/*
  PangoFontDescription *font_desc = pango_font_description_new();
  pango_font_description_set_family (font_desc, "monospace");
  gtk_widget_modify_font (editor, font_desc);
 */
