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
#include "windows___.h"
#include "extern.h"
#include "extern2.h"
#include "toolbar2___.h"

#include "container/simple___.h"
#include "container/notebook___.h"
#include "container/table___.h"

bool bool__(deque<string>* p, size_t i, bool b) {
	if(p->size() > i) {
		bool b2 = bool__((*p)[i]);
		return b ? b2 : !b2;
	}
	return b;
}

static void not_block__() {
	while (gtk_events_pending ())
	  gtk_main_iteration ();
}

static bool file__(const char* path,const char* ext,const char* sp,string& cmdline){
	if(lstat__(path, ext)){
		cmdline+=sp;
		cmdline+=path;
		cmdline+=ext;
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

void get_xid__(GtkWidget* w, char* buf) {
	GdkWindow* w2=gtk_widget_get_window(w);
	//GDK_DRAWABLE(w2)
	sprintf(buf,"%lu",GDK_WINDOW_XID(w2));
	/*sprintf(buf,"%lu",
			gdk_x11_drawable_get_xid(
					gtk_widget_get_window(GTK_WIDGET(w->widget__()))));*/
}

static l4___ l4_;
static void* l4_main_qu_;
string null_;
static string code_, err_code_;
static window_flag___ main_window_flag_;
static container___* main_window_c_ = NULL;
static windows___ windows_;
static toolbar2___ toolbar2_;

void err__(const char* s,const char* s2,const char* s3){
	if(!err_code_.empty()) {
		int errerr;
		l4_.l4_callback_2__(l4_.l4__(), &errerr, NULL, err_code_.c_str(), false, NULL, l4_main_qu_,
				3, s, s2, s3);
		if(!errerr) return;
		cerr << endl << err_code_;
	}
	cerr<<endl;
	if(s)
		cerr<<s;
	if(s2)
		cerr<<s2;
	if(s3)
		cerr<<s3;
	cerr<<endl;
}
void err__(int err, const char* ret){
	if(err) {
		err__(ret, l4_.err__(), l4_.errinfo__(err));
		cerr<<l4_.err_<<endl;
		l4_.err_clear__();
	}
}
const char* call4__(int* err, void*ce, const char* code, const char* src2,void* shangji,
		int argc, const char**argv2, int from) {
	if(!shangji)
		shangji = l4_main_qu_;
	if(!code || !code[0]) {
		code=code_.c_str();
		if(!code[0])
			return "";
	}
	const char* ret=l4_.callback3__(err, ce, code, false, src2, shangji,
			argc, argv2, from);
	switch(*err){
	case 0:
	case jieshiqi_go_+keyword_break_:
	case jieshiqi_go_+keyword_continue_:
		break;
	case jieshiqi_go_+keyword_end_:
		windows_.main__()->destroy__();
	case jieshiqi_go_+keyword_exit_:
		*err = 0;
		break;
	default:
		err__(*err,ret);
		break;
	}
	return ret;
}

s1___* new_window_s1_ = new s1___("创建", "", 'w');
static s1___* show_window_s1_ = new s1___("显现", "", 'w');
s1___* window_destroy_s1_ = new s1___("销毁", "destroy", 'w');
s1___* window_state_event_s1_ = new s1___("状态", "window-state-event", 'w');
static s1___* switch_page_s1_ = new s1___("标签页切换", "switch-page", 'n');

static void show_window__(window___* w){
	gtk_widget_show_all (w->widget__());
	call4__(NULL,w,show_window_s1_,0);
}

static void destroy__(GtkWidget *widget,gpointer gdata) {
	window___* w=window___::from__(widget);
	if(w->is_destroy_)
		return;
	w->is_destroy_ = true;
	/*const char* ret=*/call4__(NULL,w,window_destroy_s1_,0);
	/*if(ret[0]=='x'&&!ret[1])
		return;*/
	if(w->is_main__()){
		gtk_main_quit();
	}
	windows_.erase__(w);
}

static gboolean window_state_event__(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
	GdkWindowState ws = ((GdkEventWindowState*)event)->new_window_state;
	string s1;
	if ((ws & GDK_WINDOW_STATE_FULLSCREEN))
		s1 += "全屏";
	if((ws & GDK_WINDOW_STATE_MAXIMIZED))
		s1 += "最大化";
	if((ws & GDK_WINDOW_STATE_ICONIFIED))
		s1 += "最小化";
	if((ws & GDK_WINDOW_STATE_ABOVE))
		s1 += "置顶";
	if((ws & GDK_WINDOW_STATE_BELOW))
		s1 += "置底";
	if((ws & GDK_WINDOW_STATE_STICKY))
		s1 += "总可见";
#ifdef ver_gtk3_
	if((ws & GDK_WINDOW_STATE_TILED))
		s1 += "平铺";
#endif
	call4__(NULL,window___::from__(widget),window_state_event_s1_,1,s1.c_str());
	return FALSE;
}

static void switch_page__(GtkNotebook *notebook, gpointer *page,gint page_num){
	window___* w=(window___*)notebook___::from__(notebook,page_num);
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

static void new_window0__(window___* w, window_flag___* flag, container___* c, shell___* sh){
	GtkWidget* w2 = w->new__(flag, c);
	if(w2)
		w->c__()->push__(sh->new_view__(w2, w));

	window_destroy_s1_->cb_ = G_CALLBACK(destroy__);
	window_state_event_s1_->cb_ = G_CALLBACK(window_state_event__);
	for(size_t i = 0; i < s1s_length__(); i++) {
		s1___* s1 = s1s__(i);
		if(s1->type__() == 'w' && s1->cb_) {
			g_signal_connect(w->window__(), s1->signal__(), s1->cb_, NULL);
		}
	}
	w->c__()->signal_connect__();
	call4__(NULL,w,new_window_s1_,0);
}

static shell___* sh_ = NULL;

view___* shell___::new_view__(GtkWidget* scrolled2, window___* window) {
	return new view___(scrolled2, window);
}

view___* shell___::new_page__(const char* name, bool to, window___* window) {
	view___* v = NULL;
	GtkWidget* scrolled2 = window->c__()->page_new__(name, to);
	if(scrolled2) {
		v = sh_->new_view__(scrolled2, window);
		window->c__()->push__(v);
		gtk_widget_show_all (scrolled2);
	}
	return v;
}

window___* shell___::new_window__(const char* name, window_flag___* flag, container___* c) {
	window___* w=windows_.get__(name);
	if(!w){
		w=new_window__(name, false);
		windows_.push__(w);
		new_window0__(w, flag, c, this);
	}
	return w;
}
window___* shell___::new_window__(const char* name, bool is_main) {
	return new window___(name, is_main);
}

window___* shell___::get_window__(const string& name,int& page_num,const string& help,
		bool chk_can, string* page_num2, bool show_err){
	if(name.empty()) {
		page_num = notebook_current_page_;
		return windows_.main__();
	}
	window___* w;
	size_t i=name.find('#');
	if(i==string::npos){
		w=windows_.get__(name.c_str());
		page_num=notebook_current_page_;
	}else{
		w=windows_.get__(name.substr(0,i).c_str());
		if(w) {
			if(w->c__()) {
				string num = name.substr(1+i);
				if(page_num2)
					*page_num2 = num;
				page_num = w->c__()->page_num__(num.c_str());
				if(page_num < 0) {
					page_num = s2i__(num, page_num);
					if(page_num > 0)
						--page_num;
				}
			} else
				w = NULL;
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
	return w->c__()->view__(page_num);
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
			if(!page_num2.empty() && w->c__()->page_check__(page_num) < 0)
				ret = "-1";
		} else
			ret = "0";
		cpy__(buf, ret, siz);
		return true;
	}
	if(api_page__(shangji, ce, p, buf, siz, addr_ret))
		return true;
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
	if(api_w__(shangji, ce, p, buf, siz, addr_ret))
		return true;
	if(p1=="显现"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		show_window__(w);
		return true;
	}
	if(toolbar2_.use_tag__(p1)){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		toolbar2_.with__(w, shangji, ce, p, addr_fmt_, buf);
		return true;
	}
	if(api_w2__(shangji, ce, p, buf, siz, addr_ret))
		return true;
	if(api_w3__(shangji, ce, p, buf, siz, addr_ret))
		return true;
	if(p1=="创建"){
		const char* name=p0.c_str();
		window___* w=windows_.get__(name);
		window_flag___ wf;
		window_flag___* wf2;
		container___* c = NULL;
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
			if(p2=="自绘") {
				wf2->is_app_paintable_ = true;
				continue;
			}
			if((c = notebook___::new__(p, i2, w)))
				break;
			if((c = table___::new__(p, i2, w)))
				break;
			buzhichi__(-1, p);
			return true;
		}
		if(!c)
			c = new simple___(w);
		if(w && w->is_main__()){
			main_window_c_ = c;
		}
		new_window__(name, wf2, c);
		return true;
	}
	if(p0=="代码"){
		code_=p1;
		return true;
	}
	if(p0=="错代码"){
		err_code_=p1;
		return true;
	}
	if(p1=="地址格式"){
		addr_fmt_ = s2i__(p0);
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

	if(p1 == "-") {
		for(size_t i = 2; i < p->size(); i++)
			cout << (*p)[i] << " ";
		cout << endl;
		return true;
	}
	if(p1 == "") return true;

	err_buzhichi__(p1);
	return false;
}

bool shell___::api_new_view__(const string& p0, const string& p1, deque<string>* p, s1___* s1, const char* arg_alias, view___**v2) {
	int page_num;
	string page_num2;
	window___*w=get_window__(p0,page_num,p1, true, &page_num2);if(!w)return true;
	view___*v=w->view__(page_num);
	if(v2) *v2 = v;
	bool to = true;
	string arg;
	for(size_t i = 2; i < p->size(); i++) {
		const string& p3 = (*p)[i];
		if(p3 == "不激活") {
			to = false;
			continue;
		}
		if(p3 == "参" || (arg_alias && p3 == arg_alias)) {
			if(++i < p->size()) {
				arg = (*p)[i];
				continue;
			}
		}
		err_buzhichi__(p3, p1.c_str());
		return true;
	}
	if(page_num2.empty() || !v){
		v = new_page__(page_num2.c_str(), to, w);
		if(v2) *v2 = v;
		if(v) {
			if(!arg.empty()) {
				call4__(v->scrolled__(), w, s1, 1, arg.c_str());
			} else {
				call4__(v->scrolled__(), w, s1, 0);
			}
		} else {
			err_wufa__(p1);
		}
	} else {
		if(to)
			w->c__()->set_page__(page_num);
	}
	return true;
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

static bool get_lnk_ok__(const char* path) {
	if(lstat__(path, ".zs"))
		return true;
	return false;
}

int shell___::with__(int argc, char *argv[], char* env[]) {
	if(!g_thread_supported())
		g_thread_init (NULL);
#ifdef ver_thread_
	gdk_threads_init();
#endif
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
		if(!file__(path,cmdline)&&get_lnk__(path,buf,true, get_lnk_ok__)){
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
		err=l4_.def_new__("使",s.c_str(),true,false,l4_main_qu_);
	}
	if(!err){
		err=l4_.jieshi__(l4_main_qu_);
		if(err==errinfo_src_file_){
			err=0;
		}
	}

	if(!l4_.is_end__()) {
		err__(err,"");
		if(err)
			return 255;
		{
			window___* w = windows_.main__();
			if(!main_window_c_)
				main_window_c_ = new simple___(w);
			new_window0__(w, &main_window_flag_, main_window_c_, this);
			show_window__(w);
		}
		gtk_main ();
	}
	return l4_.exit_code__();
}

shell___::shell___() {
	addr_fmt_ = 16;
	sh_ = this;
	switch_page_s1_->cb_ = G_CALLBACK(switch_page__);
}
