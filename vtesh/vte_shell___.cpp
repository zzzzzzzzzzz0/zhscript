/*
 * vte_shell___.cpp
 *
 *  Created on: 2013年12月11日
 *      Author: zzzzzzzzzzz
 */

#include "vte_shell___.h"
#include "sh-base/extern.h"
#include "sh-base/extern2.h"

#ifdef ver_2_91_
#define vte_terminal_set_color_foreground_rgba vte_terminal_set_color_foreground
#define vte_terminal_set_color_background_rgba vte_terminal_set_color_background
#endif

static window___* window__(vte_view___* v) {
	return (window___*)v->window__();
}

static void call4__(VteTerminal* vte, void* data_in, s1___* contents_changed_s1 = NULL) {
	vte_view___* v = (vte_view___*)vte_view___::from__(vte);
	s1___* s1 = NULL;

	for(size_t i = 0; i < s1s_length__(); i++) {
		s1___* s1b = s1s__(i);
		if((s1___*)data_in == s1b) {
			s1 = s1b;
			break;
		}
	}
	if(!s1) {
		printf("{cb! %p %p %p}\n",v,vte,data_in);
		return;
	}

	if(s1 == contents_changed_s1) {
		v->mk_outext__();
	}
	call4__(vte_view___::scrolled_from__(vte), window__(v), s1, 0);
}

static void cb2__(VteTerminal* vte, int arg1, void* data_in) {
	call4__(vte, data_in);
}
static void cb3__(VteTerminal* vte, int arg1, int arg2, void* data_in) {
	call4__(vte, data_in);
}
static void cb3_2__(VteTerminal* vte, char* arg1, int arg2, void* data_in) {
	call4__(vte, data_in);
}

static s1___* new_view_s1_ = new s1___("新开", "", ' ');
static s1___* contents_changed_s1_ = new s1___("内容改变", "contents-changed", 'v');
//static s1___* char_size_changed_s1_ = new s1___(NULL, "char-size-changed", 'v', G_CALLBACK(cb3__));
//static s1___* commit_s1_ = new s1___(NULL, "commit", 'v', G_CALLBACK(cb3_2__));
static s1___* beep_s1_ = new s1___(NULL, "beep", 'v');
static s1___* child_exited_s1_ = new s1___(NULL, "child-exited", 'v'
#ifdef ver_2_91_
		, G_CALLBACK(cb2__)
#endif
);
static s1___* copy_clipboard_s1_ = new s1___(NULL, "copy-clipboard", 'v');
static s1___* current_directory_uri_changed_s1_ = new s1___(NULL, "current-directory-uri-changed", 'v');
static s1___* current_file_uri_changed_s1_ = new s1___(NULL, "current-file-uri-changed", 'v');
static s1___* cursor_moved_s1_ = new s1___(NULL, "cursor-moved", 'v');
static s1___* decrease_font_size_s1_ = new s1___(NULL, "decrease-font-size", 'v');
static s1___* deiconify_window_s1_ = new s1___(NULL, "deiconify-window", 'v');
static s1___* emulation_changed_s1_ = new s1___(NULL, "emulation-changed", 'v');
static s1___* encoding_changed_s1_ = new s1___(NULL, "encoding-changed", 'v');
static s1___* eof_s1_ = new s1___(NULL, "eof", 'v');
static s1___* icon_title_changed_s1_ = new s1___("图标标题改变", "icon-title-changed", 'v');
static s1___* iconify_window_s1_ = new s1___(NULL, "iconify-window", 'v');
static s1___* increase_font_size_s1_ = new s1___(NULL, "increase-font-size", 'v');
static s1___* lower_window_s1_ = new s1___(NULL, "lower-window", 'v');
static s1___* maximize_window_s1_ = new s1___(NULL, "maximize-window", 'v');
static s1___* move_window_s1_ = new s1___(NULL, "move-window", 'v', G_CALLBACK(cb3__));
static s1___* paste_clipboard_s1_ = new s1___(NULL, "paste-clipboard", 'v');
static s1___* raise_window_s1_ = new s1___(NULL, "raise-window", 'v');
static s1___* refresh_window_s1_ = new s1___(NULL, "refresh-window", 'v');
static s1___* resize_window_s1_ = new s1___(NULL, "resize-window", 'v', G_CALLBACK(cb3__));
static s1___* restore_window_s1_ = new s1___(NULL, "restore-window", 'v');
static s1___* selection_changed_s1_ = new s1___(NULL, "selection-changed", 'v');
static s1___* status_line_changed_s1_ = new s1___(NULL, "status-line-changed", 'v');
static s1___* text_deleted_s1_ = new s1___(NULL, "text-deleted", 'v');
static s1___* text_inserted_s1_ = new s1___(NULL, "text-inserted", 'v');
static s1___* text_modified_s1_ = new s1___(NULL, "text-modified", 'v');
static s1___* text_scrolled_s1_ = new s1___(NULL, "text-scrolled", 'v', G_CALLBACK(cb2__));
static s1___* window_title_changed_s1_ = new s1___(NULL, "window-title-changed", 'v');

static void cb__(VteTerminal* vte, void* data_in) {
	call4__(vte, data_in, contents_changed_s1_);
}

view___* vte_shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	return new vte_view___(scrolled2, window);
}

bool vte_shell___::api__(void* shangji, void* ce, deque<string>* p, char* buf, long siz, char** addr_ret) {
	if(p->size() >= 2) {
		const string& p0=(*p)[0];
		const string& p1=(*p)[1];
		int page_num;
		vte_view___* v;
		if(p1 == "输入") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			if(err_buzu2__(p, 3))
				return true;
			const string& data = (*p)[2];
			vte_terminal_feed_child(v->handle__(), data.c_str(), data.length());
			return true;
		}
		if(p1 == "提示") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			if(err_buzu2__(p, 3))
				return true;
			const string& data = (*p)[2];
			vte_terminal_feed(v->handle__(), data.c_str(), data.length());
			return true;
		}
		if(p1 == "输出") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			*addr_ret = dup__(v->outext__());
			return true;
		}
		if(p1 == "变") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			l2s__(v->change_, buf);
			return true;
		}
		if(p1 == "复制到剪贴板") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			vte_terminal_copy_clipboard(v->handle__());
			return true;
		}
		if(p1 == "从剪贴板粘贴") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			vte_terminal_paste_clipboard(v->handle__());
			return true;
		}
#ifdef ver_opt2_
		if(p1 == "当前目录") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			* addr_ret = dup__(vte_terminal_get_current_directory_uri(v->handle__()));
			return true;
		}
		if(p1 == "当前文件") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			* addr_ret = dup__(vte_terminal_get_current_file_uri(v->handle__()));
			return true;
		}
#endif
		if(p1 == "pid") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			l2s__(v->pid__(), buf);
			return true;
		}
		if(p1 == "图标标题") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			*addr_ret = dup__(vte_terminal_get_icon_title(v->handle__()));
			return true;
		}
		if(p1 == "reset") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			v->reset__();
			return true;
		}
		if(p1 == "z") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			//printf("%s\n",vte_get_features());
			//printf("%s\n",vte_terminal_get_status_line (v->handle__()));
			//printf("%s\n",vte_terminal_get_window_title (v->handle__()));

			/*vte_terminal_reset(v->handle__(), false, false);
			gchar *vte_text = vte_terminal_get_text (v->handle__(), NULL, NULL, NULL);
			printf("%s",vte_text);
			g_free (vte_text);*/

			/*if(vte_terminal_search_get_regex (v->handle__()) == NULL)
				vte_terminal_search_set_regex (v->handle__(),
						vte_regex_new ("z", 1, 0//guint32 flags
								, NULL//GError **error
								),
						0//guint32 flags
						);*/
			vte_terminal_search_find_next (v->handle__());
			return true;
		}
		if(p1 == "背景色" || p1 == "前景色") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			if(err_buzu2__(p, 6))
				return true;
			GdkRGBA colour;
			colour.red = s2f__((*p)[2]);
			colour.green = s2f__((*p)[3]);
			colour.blue = s2f__((*p)[4]);
			colour.alpha = s2f__((*p)[5]);
			if(p1 == "前景色")
				vte_terminal_set_color_foreground_rgba(v->handle__(), &colour);
			else
				vte_terminal_set_color_background_rgba(v->handle__(), &colour);
			return true;
		}
		if(p1 == "字体") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			if(err_buzu2__(p, 3))
				return true;
#ifdef ver_2_91_
			vte_terminal_set_font (v->handle__(), pango_font_description_from_string ((*p)[2].c_str()));
#else
			vte_terminal_set_font_from_string(v->handle__(), (*p)[2].c_str());
#endif
			return true;
		}
		if(p1 == "行数") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			if(err_buzu2__(p, 3))
				return true;
			vte_terminal_set_scrollback_lines(v->handle__(), s2i__((*p)[2]));
			return true;
		}
		if(p1 == "命令") {
			v=(vte_view___*)get_view__(p0,page_num,p1);if(!v)return true;
			if(err_buzu2__(p, 3))
				return true;
			const char* cmd = NULL;
			const char* env = NULL;
			const char* wd = NULL;
			switch(p->size()) {
			case 5:
				if((*p)[4] != null_)
					wd = (*p)[4].c_str();
			case 4:
				if((*p)[3] != null_)
					env = (*p)[3].c_str();
			case 3:
				if((*p)[2] != null_)
					cmd = (*p)[2].c_str();
			}
			l2s__(v->fork_command__(cmd, env, wd), buf);
			return true;
		}
		if(p1 == new_view_s1_->src2__()) {
			string page_num2;
			window___* w=get_window__(p0,page_num,p1, true, &page_num2);if(!w)return true;
			v=(vte_view___*)w->view__(page_num);
			if(page_num2.empty() || !v){
				v = (vte_view___*)new_page__(page_num2.c_str(), w);
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
	}
	return shell___::api__(shangji,ce,p,buf,siz,addr_ret);
}

vte_shell___::vte_shell___():shell___() {
	GCallback cb = G_CALLBACK(cb__);
	for(size_t i = 0; i < s1s_length__(); i++) {
		s1___* s1 = s1s__(i);
		if(s1->type__() == 'v' && !s1->cb_) {
			s1->cb_ = cb;
		}
	}
}
