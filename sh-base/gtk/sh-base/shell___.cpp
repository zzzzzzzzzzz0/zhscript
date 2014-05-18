/*
 * shell___.cpp
 *
 *  Created on: 2012-8-8
 *      Author: zzzzzzzzzzz
 */

#include "shell___.h"
#include"l4/args_util.cc"
#include"l4/l4___.cc"
#include"l4/keyword.h"
#include"for_arg_.h"
#include"def1.h"
#include"call_util.cpp"
#include<gdk/gdkx.h>
#include "s1___.h"
#include "windows___.h"
#include "extern2.h"

void get_xid__(GtkWidget* w, char* buf) {
	GdkWindow* w2=gtk_widget_get_window(w);
	//GDK_DRAWABLE(w2)
	sprintf(buf,"%lu",GDK_WINDOW_XID(w2));
	/*sprintf(buf,"%lu",
			gdk_x11_drawable_get_xid(
					gtk_widget_get_window(GTK_WIDGET(w->widget__()))));*/
}

static void not_block__() {
	while (gtk_events_pending ())
	  gtk_main_iteration ();
}

static bool file__(const char* path,const char* ext,const char* sp,string& cmdline){
	string file;
	file=path;
	file+=ext;
	struct stat info;
	if(lstat(file.c_str(), &info) == 0){
		cmdline+=sp;
		cmdline+=file;
		return true;
	}
	return false;
}
static bool file__(const char* path,string& cmdline){
	int i=0;
	if(file__(path,".ini"," -I ",cmdline))
		i++;
	if(file__(path,".zs"," ",cmdline))
		i++;
	return i>0;
}

static l4___ l4_;
static void* l4_main_qu_;
string null_;
static string code_;
static window_flag___ main_window_flag_;
static windows___ windows_;

static void err__(int err, const char* ret){
	if(err)
		cerr<<endl<<ret<<l4_.err_<<l4_.err__()<<l4_.errinfo__(err)<<endl;
}

static void err__(const char* s,const char* s2=NULL,const char* s3=NULL){
	cerr<<endl;
	if(s)
		cerr<<s;
	if(s2)
		cerr<<s2;
	if(s3)
		cerr<<s3;
	cerr<<endl;
}
void err_buzu__(const char* s=NULL){
	err__(s,"参数不足");
}
bool err_buzu2__(const deque<string>* p, size_t need, size_t i = 1){
	if(p->size()<need){
		err_buzu__(p->size() > i ? (*p)[i].c_str() : NULL);
		return true;
	}
	return false;
}
void err_wufa__(const string& s3,const char* s=NULL){
	err__(s,"无法",s3.c_str());
}
void err_buzhichi__(const string& s3,const char* s=NULL){
	err__(s,"不支持",s3.c_str());
}

const char* call4__(const char* code,const char* src2,int argc,const char**argv2,int from){
	int err;
	const char* ret=l4_.l4_callback3_2__(l4_.l4__(),&err,NULL,code,false,src2,l4_main_qu_,
			argc,argv2,from);
	switch(err){
	case 0:
	case jieshiqi_go_+keyword_exit_:
		break;
	case jieshiqi_go_+keyword_end_:
		windows_.main__()->destroy__();
		break;
	default:
		err__(err,ret);
		break;
	}
	return ret;
}
const char* call4__(GtkWidget* sw,window___* w,s1___* s1,int argc,...){
	const char*argv2[16];
	_for_args( argc )
		argv2[i]=s;
	_next_args
	const char* code=NULL;
	if(w) {
		map<int, string>::iterator it = w->codes_.find(s1->i__());
		if(it != w->codes_.end())
			code=(*it).second.c_str();
	}
	if(!code || !code[0]){
		for(;;){
			if(w) {
				code = w->code_.c_str();
				if(code[0])
					break;
			}
			code=code_.c_str();
			if(code[0])
				break;
			return "";
		}
	}
	string name2;
	if(w) {
		w->name2__(name2, sw);
		argv2[argc++]=name2.c_str();
	}
	return call4__(code,s1->src2__(),argc,argv2,0);
}

const string& s__(const deque<string>* p, size_t i) {
	if(i >= p->size()) {
		err_buzu__((*p)[0].c_str());
		throw 's';
	}
	return (*p)[i];
}
const string& s__(const deque<string>& p, size_t i) {
	return s__(&p, i);
}

class event_button___ {
public:
	string code_;
};

static gint event_button__(GtkWidget *widget, GdkEventButton *event, gpointer data) {
	event_button___* eb = (event_button___*)data;
	call4__(eb->code_.c_str(), NULL, 0, NULL, 0);
	return FALSE;
}

static s1___* new_window_s1_ = new s1___("创建", "", 'w');
static s1___* show_window_s1_ = new s1___("显现", "", 'w');
static s1___* window_destroy_s1_ = new s1___("销毁", "", 'w');
static s1___* switch_page_s1_ = new s1___("标签页切换", "switch-page", 'n');

static void show_window__(window___* w){
	gtk_widget_show_all (w->widget__());
	call4__(NULL,w,show_window_s1_,0);
}

static void destroy__(GtkWidget *widget,gpointer gdata) {
	window___* w=window___::from__(widget);
	windows_.erase__(w);
	const char* ret=call4__(NULL,w,window_destroy_s1_,0);
	if(ret[0]=='x'&&!ret[1])
		return;
	if(w->is_main__()){
		gtk_main_quit();
	}
}

static void switch_page__(GtkNotebook *notebook, gpointer *page,gint page_num){
	window___* w=window___::from__(notebook,page_num);
	if(!w)
		return;
	char s[16];
	l2s__(page_num+1,s);
	call4__(NULL,w,switch_page_s1_,1,s);
}

static void suidao__(char**addr_ret,char*buf,long siz,shell___* sh,void*ce,void* shangji,int argc,...) {
	deque<string> p;
	_for_args( argc )
		p.push_back(s ? s : null_.c_str());
	_next_args
	sh->api__(shangji,ce,&p,buf,siz,addr_ret);
}

static void new_window0__(window___* w, window_flag___* flag, shell___* sh){
	GtkWidget* w2 = w->new__(flag);
	if(w2)
		w->push__(sh->new_view__(w2, w));

	g_signal_connect(w->window__(), "destroy", G_CALLBACK(destroy__), NULL);
	for(size_t i = 0; i < s1s_length__(); i++) {
		s1___* s1 = s1s__(i);
		if(s1->type__() == 'n' && s1->cb_) {
			g_signal_connect(w->notebook__(), s1->signal__(), s1->cb_, NULL);
		}
	}
	call4__(NULL,w,new_window_s1_,0);
}

view___* shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	return new view___(scrolled2, window);
}

window___* shell___::new_window__(const char* name, window_flag___* flag) {
	window___* w=windows_.get__(name);
	if(!w){
		w=new_window__(name, false);
		windows_.push__(w);
		new_window0__(w, flag, this);
	}
	return w;
}
window___* shell___::new_window__(const char* name, bool is_main) {
	return new window___(name, is_main);
}

window___* shell___::get_window__(const string& name,int& page_num,const string& help,
		bool chk_can, string* page_num2, bool show_err){
	window___* w;
	size_t i=name.find('#');
	if(i==string::npos){
		w=windows_.get__(name.c_str());
		page_num=notebook_current_page_;
	}else{
		w=windows_.get__(name.substr(0,i).c_str());
		if(w) {
			string num = name.substr(1+i);
			if(page_num2)
				*page_num2 = num;
			page_num = w->page_num__(num.c_str());
			if(page_num < 0) {
				page_num = s2i__(num, page_num);
				if(page_num > 0)
					--page_num;
			}
		}
	}
	if(!w || (chk_can && !w->can_set__())){
		if(show_err)
			err_wufa__(help,name.c_str());
		return NULL;
	}
	return w;
}

view___* shell___::get_view__(const string& name, int& page_num, const string& help,
		bool chk_can, string* page_num2, bool show_err) {
	window___* w = get_window__(name, page_num, help, chk_can, page_num2, show_err);
	if(!w)
		return NULL;
	return w->view__(page_num);
}

bool shell___::api__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	if(err_buzu2__(p, 1))
		return true;
	const string& p0=(*p)[0];
	if(p0=="不堵塞"){
		not_block__();
		return true;
	}
	if(err_buzu2__(p, 2, 0))
		return true;
	const string& p1=(*p)[1];
	window___* w;
	int page_num;
	if(p1=="有"){
		string page_num2;
		w=get_window__(p0,page_num,p1, true, &page_num2, false);
		const char* ret;
		if(w) {
			ret = "1";
			if(!page_num2.empty() && w->page_check__(page_num) < 0)
				ret = "-1";
		} else
			ret = "0";
		cpy__(buf, ret, siz);
		return true;
	}
	if(p1=="标签号"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(p->size()<3){
			l2s__(w->current_page__()+1,buf);
		}else
			w->set_page__(s2i__((*p)[2])-1);
		return true;
	}
	if(p1=="标签名"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkWidget*sw = w->nth_page__(page_num);
		if(p->size()<3){
			string name2;
			w->name2__(name2, sw);
			cpy__(buf, name2.c_str(), siz);
		} else {
			const char* name = (*p)[2].c_str();
			if(w->page_num__(name) != notebook_page_no_) {
				err_wufa__(p1, name);
				return true;
			}
			gtk_widget_set_name(sw, name);
		}
		return true;
	}
	if(p1=="标签数目"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		l2s__(w->n_pages__(), buf);
		return true;
	}
	if(p1=="标签"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkLabel* l=w->label__(page_num);
		if(!l){
			err_wufa__(p1,p0.c_str());
			return true;
		}
		if(p->size()<3){
			cpy__(buf, gtk_label_get_text(l), siz);
		}else
			gtk_label_set_markup(l, (*p)[2].c_str());
		return true;
	}
	if(p1=="标签提示"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkLabel* l=w->label__(page_num);
		if(!l){
			err_wufa__(p1,p0.c_str());
			return true;
		}
		if(p->size()<3){
		}else
			gtk_widget_set_tooltip_markup(GTK_WIDGET(l), (*p)[2].c_str());
		return true;
	}
	if(p1=="标题"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(p->size()<3){
			cpy__(buf, gtk_window_get_title (w->window__()), siz);
		}else
			gtk_window_set_title (w->window__(), (*p)[2].c_str());
		return true;
	}
	if(p1=="焦点"){
		view___*v = get_view__(p0,page_num,p1);if(!v) return true;
		gtk_widget_grab_focus(v->widget__());
		return true;
	}
	if(p1=="敏感"){
		view___*v = get_view__(p0,page_num,p1);if(!v) return true;
		if(p->size()<3){
			l2s__(gtk_widget_get_sensitive(v->widget__()), buf);
		}else
			gtk_widget_set_sensitive(v->widget__(), s2i__((*p)[2],0));
		return true;
	}
	if(p1=="移动"){
		if(err_buzu2__(p, 4))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		int x,y;
		gtk_window_get_position(w->window__(),&x,&y);
		x=s2i__((*p)[2],x);
		y=s2i__((*p)[3],y);
		if(x<0)
			x+=gdk_screen_width();
		if(y<0)
			y+=gdk_screen_height();
		gtk_window_move(w->window__(),x,y);
		return true;
	}
	if(p1=="活动"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		l2s__(gtk_window_is_active(w->window__()),buf);
		return true;
	}
	if(p1=="激活"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_present(w->window__());
		w->set_page__(page_num);
		return true;
	}
	if(p1=="隐藏"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		w->hide__();
		return true;
	}
	if(p1=="关闭"){
		string page_num2;
		w = get_window__(p0,page_num,p1, true, &page_num2);
		if(!w)return true;
		if(page_num < 0 && !page_num2.empty()) {
			err_wufa__(p1,p0.c_str());
			return true;
		}
		w->close__(page_num);
		return true;
	}
	if(p1==window_destroy_s1_->src2__()){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		w->destroy__();
		return true;
	}
	if(p0=="屏幕"){
		if(p1 == "宽度") {
			l2s__(gdk_screen_width(), buf);
			return true;
		}
		if(p1 == "高度") {
			l2s__(gdk_screen_height(), buf);
			return true;
		}
		err_buzhichi__(p0, p1.c_str());
		return true;
	}
	if(p1=="大小"){
		if(err_buzu2__(p, 4))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		int w1 = s2i__((*p)[2], gdk_screen_width()),
			h1 = s2i__((*p)[3], gdk_screen_height());
		gtk_window_set_default_size (w->window__(), w1, h1);
		//gtk_widget_set_usize(w->widget__(), w1, h1);
		gtk_window_resize (w->window__(), w1, h1);
		return true;
	}
	if(p1=="最大化"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_maximize (w->window__());
		return true;
	}
	if(p1=="取消最大化"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_unmaximize (w->window__());
		return true;
	}
	if(p1=="最小化"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_iconify (w->window__());
		return true;
	}
	if(p1=="恢复"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_present (w->window__());
		return true;
	}
	if(p1=="置顶" || p1=="取消置顶"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_set_keep_above (w->window__(), p1=="置顶");
		return true;
	}
	if(p1=="无标签"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
	    gtk_notebook_set_show_tabs(w->notebook__(), false);
		return true;
	}
	if(p1=="无边框"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_notebook_set_show_border(w->notebook__(), false);
		return true;
	}
	if(p1=="不可关闭"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkWidget* b=w->close_button__(page_num);
		if(!b){
			err_wufa__(p1,p0.c_str());
			return true;
		}
		//gtk_widget_set_sensitive (b,false);
		gtk_widget_hide (b);
		return true;
	}
	if(p1=="居中"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_set_position(w->window__(),GTK_WIN_POS_CENTER);
		return true;
	}
	if(p1=="显现"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		show_window__(w);
		return true;
	}
	if(p1=="加钮"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		char clicked=' ';
		GtkIconSize size=GTK_ICON_SIZE_MENU;
		const char *name=NULL,*iconame, *code = NULL, *code1 = NULL;
		bool is_focus = false;
		for(size_t i=2;i<p->size();i++){
			const string& p2=(*p)[i];
			if(p2=="点有焦点"){
				clicked='f';
				continue;
			}
			if(p2=="点无焦点"){
				clicked=' ';
				continue;
			}
			if(p2=="焦点"){
				is_focus = true;
				continue;
			}
			if(p2=="大小"){
				if(err_buzu2__(p, ++i))
					return true;
				size=(GtkIconSize)s2i__((*p)[i]);
				continue;
			}
			if(p2=="名"){
				if(err_buzu2__(p, ++i))
					return true;
				name=(*p)[i].c_str();
				continue;
			}
			if(p2=="代码"){
				if(err_buzu2__(p, ++i))
					return true;
				code=(*p)[i].c_str();
				continue;
			}
			if(p2 == "缺省代码") {
				if(err_buzu2__(p, ++i))
					return true;
				code1 = (*p)[i].c_str();
				if(!code1[0])
					code1 = NULL;
				continue;
			}
			iconame=p2.c_str();
			if(!name)
				name=iconame;
			GtkWidget* btn = w->button_new__(page_num,name,iconame,size,
					code ? code : code1,clicked);
			if(!btn) {
				err_wufa__(p1,p0.c_str());
				return true;
			}
			if(is_focus) {
				gtk_widget_grab_focus(btn);
				is_focus = false;
			}
			code = name = NULL;
		}
		return true;
	}
	if(p1=="侦听" || p1=="加侦听"){
		w=get_window__(p0,page_num,p1,false);if(!w)return true;
		bool is_add = p1=="加侦听";
		for(size_t i2=2;i2<p->size();i2++){
			const string& p2=(*p)[i2];
			int i1;
			if(p2 == "代码") {
				i1 = -2;
			} else {
				i1 = -1;
				for(size_t i = 0; i < s1s_length__(); i++) {
					if(p2 == s1s__(i)->src2__()) {
						i1=i;
						break;
					}
				}
				if(i1<0 || (i1==new_window_s1_->i__() && !w->is_main__())){
					err_buzhichi__(p2,p1.c_str());
					return true;
				}
			}
			if(err_buzu2__(p, ++i2))
				return true;
			const string& p3=(*p)[i2];
			switch(i1) {
			case -2:
				if(is_add)
					w->code_ += p3;
				else
					w->code_ = p3;
				break;
			default:
				if(i1 >= 0){
					if(is_add)
						w->codes_[i1] += p3;
					else
						w->codes_[i1] = p3;
				}
			}
		}
		return true;
	}
	if(p1 == "事件") {
		w=get_window__(p0,page_num,p1,false);if(!w)return true;
		for(size_t i2 = 2; i2 < p->size();) {
			const string& p2 = (*p)[i2++];
			if(err_buzu2__(p, i2))
				return true;
			const string& p3 = (*p)[i2++];
			event_button___* eb = new event_button___();
			eb->code_ = p3;
			g_signal_connect(G_OBJECT(w->widget__()), p2.c_str(),
					GTK_SIGNAL_FUNC(event_button__), eb);
		}
		return true;
	}
	if(p1=="创建"){
		const char* name=p0.c_str();
		window___* w=windows_.get__(name);
		window_flag___ wf;
		window_flag___* wf2;
		if(w && w->is_main__()){
			wf2 = &main_window_flag_;
		}else{
			wf2 = &wf;
		}
		for(size_t i2=2;i2<p->size();i2++){
			const string& p2=(*p)[i2];
			if(p2=="弹出窗"){
				wf2->wt_=GTK_WINDOW_POPUP;
				continue;
			}
			if(p2=="标签页"){
				wf2->is_tabpg_=true;
				continue;
			}
			if(p2=="左标签页"){
				wf2->is_tabpg_=true;
				wf2->pt_=GTK_POS_LEFT;
				continue;
			}
			if(p2=="右标签页"){
				wf2->is_tabpg_=true;
				wf2->pt_=GTK_POS_RIGHT;
				continue;
			}
			if(p2=="顶标签页"){
				wf2->is_tabpg_=true;
				wf2->pt_=GTK_POS_TOP;
				continue;
			}
			if(p2=="底标签页"){
				wf2->is_tabpg_=true;
				wf2->pt_=GTK_POS_BOTTOM;
				continue;
			}
			if(p2=="自动标签"){
				wf2->label_style_=label_style_auto_;
				continue;
			}
			if(p2=="文字标签"){
				wf2->label_style_=label_style_text_;
				continue;
			}
			if(p2=="可关闭标签"){
				wf2->label_style_=label_style_can_close_;
				continue;
			}
			if(p2=="标签竖向"){
				wf2->is_tabpg_vbox_=true;
				continue;
			}
			if(p2=="自绘") {
				wf2->is_app_paintable_ = true;
				continue;
			}
			if(p2=="空") {
				wf2->has_1page_ = false;
				continue;
			}
			err_buzhichi__(p2,p1.c_str());
			return true;
		}
		new_window__(name, wf2);
		return true;
	}
	if(p1=="图标"){
		if(err_buzu2__(p, 3))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		const string& p2=(*p)[2];
		GdkPixbuf* pb=gdk_pixbuf_new_from_file(p2.c_str(),NULL);
		if(pb) {
			gtk_window_set_icon(w->window__(),pb);
		}else {
			err_wufa__(p1,p2.c_str());
		}
		return true;
	}
	if(p1=="不透明度"){
		if(err_buzu2__(p, 3))
			return true;
		w=get_window__(p0,page_num,p1);if(!w)return true;
		gtk_window_set_opacity(w->window__(),s2f__((*p)[2]));
		return true;
	}
	if(p1=="无修饰"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		bool b = false;
		if(p->size() > 2) {
			b = !s2i__((*p)[2], b);
		}
		gtk_window_set_decorated(w->window__(), b);
		return true;
	}
	if(p1=="鼠标穿透"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
#ifndef no_gtk_2_
		GdkRegion *region = gdk_region_new ();
		gdk_window_input_shape_combine_region (w->widget__()->window, region, 0, 0);
		gdk_region_destroy (region);
#endif
		return true;
	}
	if(p1=="地址"){
		view___*v = get_view__(p0,page_num,p1);if(!v)return true;
		l2x__((long)v->widget__(), buf);
		return true;
	}
	if(p1=="xid"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		get_xid__(w->widget__(), buf);
		return true;
	}
	if(p0=="代码"){
		code_=p1;
		return true;
	}
	if(p1 == "等待") {
		time_t start = time(NULL), len;
		char c;
		switch(sscanf(p0.c_str(), "%ld%c", &len, &c)) {
		case 2:
			switch(c) {
			case 'd':
				len *= 24;
			case 'h':
				len *= 60;
			case 'm':
				len *= 60;
			case 's':
				break;
			default:
				err_buzhichi__(p1, p0.c_str());
				return true;
			}
		case 1:
			break;
		default:
			err_buzhichi__(p1, p0.c_str());
			return true;
		}
		for(;time(NULL) - start < len;)
			not_block__();
		return true;
	}
	err_buzhichi__(p1);
	return false;
}

static string log_no_="cwdmi";
static void g_log__(const gchar *log_domain, GLogLevelFlags log_level,const gchar *message,gpointer user_data){
	char c='N';
	switch(log_level){
	case G_LOG_LEVEL_CRITICAL:	c='c';break;
	case G_LOG_LEVEL_WARNING:	c='w';break;
	case G_LOG_LEVEL_DEBUG:		c='d';break;
	case G_LOG_LEVEL_MESSAGE:	c='m';break;
	case G_LOG_LEVEL_INFO:		c='i';break;
	case G_LOG_FLAG_RECURSION:	c='r';break;
	case G_LOG_FLAG_FATAL:		c='f';break;
	case G_LOG_LEVEL_ERROR:		c='e';break;
	case G_LOG_LEVEL_MASK:		c='M';break;
	}
	if(log_no_.find(c)!=string::npos)
		return;
	cout<<"log--"<<(log_domain?log_domain:"")
			<<"--"<<c//<<"/"<<log_level
			<<"--"<<message<<endl;
}

int shell___::with__(int argc, char *argv[], char* env[]) {
	if(!g_thread_supported())
		g_thread_init (NULL);
	{
		GLogLevelFlags llf=(GLogLevelFlags)(G_LOG_LEVEL_MASK);
		g_log_set_handler (NULL, llf, g_log__, NULL);
		g_log_set_handler ("Gtk", llf, g_log__, NULL);
		g_log_set_handler ("Gdk", llf, g_log__, NULL);
		g_log_set_handler ("GLib", llf, g_log__, NULL);
		g_log_set_handler ("GLib-GObject", llf, g_log__, NULL);
	}

	gtk_init_check(&argc, &argv);

	windows_.push__(new_window__("主窗", true));

	int err;
	{
		const char* path=argv[0];
		string buf;
		if(which__(path,buf))
			path=buf.c_str();
		string cmdline="-S syn-zh -E err-zh";
		if(!file__(path,cmdline)&&get_lnk__(path,buf,true)){
			path=buf.c_str();
			file__(path,cmdline);
		}
		err=l4_.init__(path,cmdline.c_str(),argc,argv,1);
	}
	if(!err){
		l4_main_qu_=l4_.new_main_qu__();
		null_=l4_.keyword__(keyword_null_);
		char buf[32];
		const char
			*dy=l4_.keyword__(keyword_call_)
			,*ky=l4_.keyword__(keyword_kaiyinhao_)
			,*by=l4_.keyword__(keyword_biyinhao_)
			,*d=l4_.keyword__(keyword_dunhao_)
			,*bs=l4_.keyword__(keyword_bianliangshi_)
			,*bz=l4_.keyword__(keyword_bianliangzhong_)
			,*c=l4_.keyword__(keyword_params_)
			,*j=l4_.keyword__(keyword_juhao_)
			,*cb=l4_.keyword__(keyword_callback_)
			,*zs=l4_.keyword__(keyword_zhujieshi_)
			,*zz=l4_.keyword__(keyword_zhujiezhong_)
			,*sj=l4_.keyword__(keyword_shangji_)
			;
		string s;
		s+=dy;
		s+=ky;s+="ASZ/";s+=l2x__((long)suidao__,buf);s+="/&-$11-&";s+=by;s+=d;
		s+=ky;s+=l2x__((long)this,buf);s+=by;s+=d;
		s+=bs;s+=zs;s+=sj;s+=zz;s+=cb;s+='1';s+=bz;s+=d;
		s+=bs;s+=c;s+=bz;s+=j;
		//让
		err=l4_.def_new__("使",s.c_str(),true,false,l4_main_qu_);
	}
	if(!err){
		err=l4_.jieshi__(l4_main_qu_);
		if(err==errinfo_src_file_){
			err=0;
		}
	}
	err__(err,"");
	if(err)
		return 255;

	{
		window___* w = windows_.main__();
		new_window0__(w, &main_window_flag_, this);
		show_window__(w);
	}
	gtk_main ();

	return l4_.exit_code__();
}

shell___::shell___() {
	switch_page_s1_->cb_ = G_CALLBACK(switch_page__);
}
