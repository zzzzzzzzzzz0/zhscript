/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * rptestj
 * Copyright (C) zzzzzzzzzzz 2010 <zzzzzzzzzzzgg@gmail.com>
 *
 * rptestj is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rptestj is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "shell.h"
#include"util.h"
#include"for_arg_.h"
#include"l4/keyword.h"
#include"plugin_def.h"
#include"def1.h"
#include "l4/args_util.hh"

shell___::shell___(){
	exit_=0;
	err_show_to_console_=false;
	err_view_=NULL;
	old_width_=old_height_=-1;
	firstevted_=false;
	main_quit_=false;
	l4_main_qu_=NULL;
}

shell___::~shell___(){
	plugin_uninit__();
	//delete main_;
	l4_.delete_qu__(l4_main_qu_);
}

static Glib::ustring log_no_="cwdmi";
static void
g_log__ (const gchar *log_domain, GLogLevelFlags log_level,const gchar *message,gpointer user_data){
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

int shell___::with__(int argc, char *argv[], char**env){
	{
		//-1
		GLogLevelFlags llf=(GLogLevelFlags)(G_LOG_LEVEL_MASK  | G_LOG_FLAG_FATAL | G_LOG_FLAG_RECURSION);
		g_log_set_handler (NULL, llf, g_log__, NULL);
		g_log_set_handler ("gtkmm", llf, g_log__, NULL);
		g_log_set_handler ("Gtk", llf, g_log__, NULL);
		g_log_set_handler ("Gdk", llf, g_log__, NULL);
		g_log_set_handler ("GLib", llf, g_log__, NULL);
	}

	//for(int i=0;i<argc;i++)cout<<i<<"="<<argv[i]<<";"<<endl;
	main_=new Gtk::Main(argc, argv);
	//for(int i=0;i<argc;i++)cout<<i<<"="<<argv[i]<<";"<<endl;

	prgname_=argv[0];
	ui_file_=NULL;
	int arg1=1;
	char*argv1=NULL;
	if(argc>arg1){
		Glib::ustring head,flag;
		size_t i1;

		head=argv[arg1];
		flag="--log-no-";
		i1=head.find(flag);
		if(i1==0){
			log_no_=head.substr(flag.length());
			//cout<<"log_no_"<<log_no_<<endl;
			if(arg1+1<argc)
				head=argv[++arg1];
			else
				head.clear();
		}

		flag=" --";
		i1=head.find(flag);
		if(i1!=string::npos){
			realprgname_=realpath__(prgname_);
			prgname_=realprgname_.c_str();
			argv[arg1][i1]=0;
			argv1=argv[arg1]+i1+1;
		}

		if(head=="--"||head=="---"){
		}else if(head.length()>0&&head[0]=='-'){
			ui_file_=default_ui_file_.c_str();
		}else{
			ui_file_=argv[arg1];
			if(!g_file_test(ui_file_, G_FILE_TEST_EXISTS)){
				default_ui_file_=prgname_;
				get_path__(default_ui_file_);
				default_ui_file_+=ui_file_;
				ui_file_=default_ui_file_.c_str();
				if(!g_file_test(ui_file_, G_FILE_TEST_EXISTS)){
					for(int i=arg1+1;i<argc;i++){
						if(argv[i][0]!='-'){
							string s=argv[i];
							get_path__(s);
							s+=argv[arg1];
							if(g_file_test(s.c_str(), G_FILE_TEST_EXISTS)){
								default_ui_file_=s;
								ui_file_=default_ui_file_.c_str();
							}
							break;
						}
					}
				}
			}
		}
	}
	/*for(int i=0;i<argc;i++)cout<<i<<(i<=arg1?"-":"")<<"="<<argv[i]<<";"<<endl;
	cout<<(argv1?argv1:"null")<<endl;
	cout<<(ui_file_?ui_file_:"null")<<endl;*/

	bool file=true;
	if(!ui_file_){
		default_ui_file_=prgname_;
		size_t i=default_ui_file_.find('.');
		if(i!=string::npos){
			size_t i1=default_ui_file_.find('/');
			if(i1==string::npos)
				i1=default_ui_file_.find('\\');
			if(i1==string::npos)
				i1=0;
			if(i>i1)
				default_ui_file_=default_ui_file_.substr(0,i);
		}
		Glib::ustring s;
		s=default_ui_file_+".ui";
		if(!g_file_test(s.c_str(), G_FILE_TEST_EXISTS))
			s=default_ui_file_+".glade";
		default_ui_file_=s;
		ui_file_=default_ui_file_.c_str();
	}
	//cout<<ui_file_<<endl;
	if(!g_file_test(ui_file_, G_FILE_TEST_EXISTS))
		file=false;
	for(;;){
		try{
			if(file)
				builder_ = Gtk::Builder::create_from_file(ui_file_);
			else
				builder_ = Gtk::Builder::create_from_string(
					"<interface>"
					"<requires lib=\"gtk+\" version=\"2.16\"/>"
					"<object class=\"GtkWindow\" id=\"main_window\">"
					//"<property name=\"resizable\">False</property>"
					"<property name=\"window_position\">center</property>"
					"<property name=\"width_request\">20</property>"
					"<property name=\"height_request\">0</property>"
					"<child><placeholder/></child>"
					"</object></interface>");
		}
		catch (const Glib::FileError & ex)
		{
			std::cerr << ex.what() << std::endl;
			return 255;
		}
		main_win_ = 0;
		const char*winame="main_window";
		builder_->get_widget(winame, main_win_);
		if(!main_win_)
			builder_->get_widget("window1", main_win_);
		if(main_win_){
			/*Gdk::Cursor cur(Gdk::WATCH);
			Glib::RefPtr <Gdk::Window> win;
			win=main_win_->get_window();
			win->set_cursor(cur);*/
			init__();
			pluginit__();
			int err=l4__(argv1,argc,argv,arg1+1,env);
			if(err){
				l4_err_show__(err);
				return 255;
			}
			if(main_quit_)
				break;
			//win->set_cursor();
#ifdef ver_thread_
			gdk_threads_enter();
#endif
			main_->run(*main_win_);
#ifdef ver_thread_
			gdk_threads_leave();
#endif
			break;
		}else{
			err_show__("须以",winame,"为界面主窗体名称");
			file=false;
		}
	}
	if(exit_)
		return exit_;
	return l4_.exit_code__();
}

void shell___::init__(){
	{
		Glib::ustring zs_file=ui_file_;
		zs_file+=".zs";
		if(g_file_test(zs_file.c_str(), G_FILE_TEST_EXISTS))
			file_get__(zs_file.c_str(),src_);
	}
	main_win_->signal_window_state_event().connect(sigc::mem_fun(*this, &shell___::main_win_state_evt__));
	main_win_->signal_delete_event().connect(sigc::mem_fun(*this, &shell___::main_win_delete_evt__));
	main_win_->signal_show().connect(sigc::mem_fun(*this, &shell___::main_win_new_evt__));
	main_win_->signal_size_allocate().connect(sigc::mem_fun(*this, &shell___::main_win_resize_evt__));
	main_win_->signal_configure_event().connect(sigc::mem_fun(*this, &shell___::main_win_config_evt__));
}

bool shell___::main_win_config_evt__(GdkEventConfigure* e){
	/*switch(e->type){

	}*/
	return false;
}

bool shell___::main_win_delete_evt__(GdkEventAny* event){
	//if(firstevted_)
		on__(NULL,NULL,2,"窗口","销毁");
	return false;
}

void shell___::main_win_resize_evt__(Gtk::Allocation& allo){
	if(!firstevted_)
		return;
	int w=allo.get_width(),h=allo.get_height();
	if(old_width_!=w||old_height_!=h){
		old_width_=w;
		old_height_=h;
		char w1[16],h1[16];
		l2s__(w,w1);
		l2s__(h,h1);
		on__(NULL,NULL,4,"窗口","大小改变",w1,h1);
	}
}

void shell___::main_win_new_evt__(){
	on__(NULL,NULL,2,"窗口","创建");
	firstevted_=true;
}

bool shell___::main_win_state_evt__(GdkEventWindowState*st){
	if(st->new_window_state & GDK_WINDOW_STATE_ICONIFIED)
		main_win_hide__();
	char i[16];
	l2s__(st->new_window_state,i);
	on__(NULL,NULL,3,"窗口","状态改变",i);
	return false;
}

bool shell___::main_win_is_visible__(){
	//return main_win_->is_visible();
	return !main_win_->get_skip_taskbar_hint();
}

void shell___::main_win_show__(){
	//main_win_->show();
	main_win_->present();
	plugin_on__(main_win_show_);
}

void shell___::main_win_hide__(){
	//main_win_->hide();
	main_win_->iconify();
	plugin_on__(main_win_hide_);
}

void shell___::main_quit__(){
	main_quit_=true;
	main_win_delete_evt__(0);
	main_->quit();
	//main_win_->hide();
}

void shell___::err_show__(const char* str,const char*str2,const char*str3){
	if(err_show_to_console_){
		cerr<<ui_file_<<"\t"<<str<<str2<<str3<<endl;
		return;
	}
	if(err_view_){
		Glib::ustring s=str;
		s+=str2;
		s+=str3;
		err_view_->get_buffer()->set_text(s);
		return;
	}
	GtkWidget* dialog = gtk_message_dialog_new (main_win_?main_win_->gobj():0,
		GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,
		"%s%s%s",str,str2,str3);
	gtk_window_set_title(GTK_WINDOW(dialog), ui_file_);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
void shell___::err_show_buzhichi__(std::deque<Glib::ustring>* p,int i){
	if(p->size()<=1)
		err_show__((*p)[0].c_str(),"不支持");
	else
		err_show__((*p)[0].c_str(),(*p)[i].c_str(),"不支持");
}
void shell___::err_show_buzu__(std::deque<Glib::ustring>* p){
	if(p->size()<1)
		err_show__("参数不足");
	else
		err_show__((*p)[0].c_str(),"参数不足");
}
void shell___::err_show_wufa__(std::deque<Glib::ustring>* p,int i,int i1){
	if(i<0)
		err_show__((*p)[i1].c_str(),"无法");
	else
		err_show__((*p)[i].c_str(),"无法",(*p)[i1].c_str());
}
void shell___::err_show_fei__(std::deque<Glib::ustring>* p){
	err_show__((*p)[1].c_str(),"非",(*p)[0].c_str());
}

void shell___::l4_err_show__(int err,const char*ret){
	Glib::ustring title;
	if(ret)
		title+=ret;
	title+=l4_.err_;
	title+=l4_.err__();
	title+=l4_.errinfo__(err);
	l4_.err_clear__();
	err_show__(title.c_str());
}

void shell___::l4_err_show__(int err){
	l4_err_show__(err,NULL);
}

const char* shell___::call4_1__(int* err,void*ce,const char*code,void* shangji,
		const char*zhao,const char*dong,const char* src2,int argc,const char*argv[],int from){
	if(zhao){
		if((*err=l4_.var_new__("肇事者",zhao,false,l4_main_qu_)))
			return NULL;
	}
	if(dong){
		if((*err=l4_.var_new__("动作",dong,false,l4_main_qu_)))
			return NULL;
	}
	if(!(code&&*code)){
		code=src_.c_str();
		if(!*code)
			return NULL;
	}
	if(!shangji)
		shangji=l4_main_qu_;
	return l4_.l4_callback3_2__(l4_.l4__(),err,ce,code,false,src2,shangji,argc,argv,from);
}

void shell___::call4_2__(int err){
	switch(err){
	case 0:
	case jieshiqi_go_+keyword_exit_://不能和下面一起？
		break;
	case jieshiqi_go_+keyword_end_:
		main_quit__();
		break;
	default:
		l4_err_show__(err/*,ret*/);
	}
}

const char* shell___::call4__(const char*code,void* shangji,
		const char*zhao,const char*dong,const char* src2,int argc,const char*argv[],int from){
	int err;
	const char*ret=call4_1__(&err,NULL,code,shangji,zhao,dong,src2,argc,argv,from);
	call4_2__(err);
	return ret;
}

#ifdef ver_thread_
void shell___::call4_0__(){
	//Glib::Mutex::Lock lock (mutex_);
	gdk_threads_enter();
	call4__(code_,argc_,argv_);
	gdk_threads_leave();
}
#endif

const char* shell___::on__(const char*code,void* shangji,int argc,...){
#ifdef ver_thread_
	code_=code;
	argc_=argc;
#else
	const char*zhao;
	const char*dong;
	const char*argv2[8];
#endif
	_for_args2( argc ){
#ifdef ver_thread_
		argv_[i]=s;
#else
		switch(i){
		case 0:
			zhao=s;
			break;
		case 1:
			dong=s;
			break;
		default:
			argv2[i-2]=s;
			break;
		}
#endif
	}_next_args
#ifdef ver_thread_
	Glib::Thread *const tr = Glib::Thread::create(
			sigc::mem_fun(*this, &shell___::call4_0__), false);//true
	//tr->join();
#else
	return call4__(code,shangji,zhao,dong,dong,argc-2,argv2,0);
#endif
}

Glib::ustring null_;
static void suidao__(char**addr_ret,char*buf,long siz,shell___* sh,void*ce,void* shangji,int argc,...) {
	std::deque<Glib::ustring> p;
	_for_args( argc )
		p.push_back(s?s:null_.c_str());
	_next_args
	try{
		sh->api__(shangji,ce,&p,buf,siz,addr_ret);
	}
	catch(int err){
		sh->l4_err_show__(err);
	}
}

int shell___::l4__(char*arg1,int argc, char *argv[],int from,char**env){
	int err;
	{
		Glib::ustring cmdline="-S syn-zh -E err-zh ";

		Glib::ustring zs_file=ui_file_;
		zs_file+="_init.zs";
		if(g_file_test(zs_file.c_str(), G_FILE_TEST_EXISTS))
			cmdline+=zs_file;

		if(arg1&&arg1[0]){
			cmdline+=' ';
			cmdline+=arg1;
		}

		//cout<<cmdline<<endl;
		if((err=l4_.init__(prgname_,cmdline.c_str(),argc,argv,from)))
			return err;
	}
	l4_main_qu_=l4_.new_main_qu__();
	{
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
		Glib::ustring s;
		s+=dy;
		s+=ky;s+="ASZ/";s+=l2x__((long)suidao__,buf);s+="/&-$11-&";s+=by;s+=d;
		s+=ky;s+=l2x__((long)this,buf);s+=by;s+=d;
		s+=bs;s+=zs;s+=sj;s+=zz;s+=cb;s+='1';s+=bz;s+=d;
		s+=bs;s+=c;s+=bz;s+=j;
		if((err=l4_.def_new__("隧道",s.c_str(),true,false,l4_main_qu_)))
			return err;
	}
	err=l4_.jieshi__(l4_main_qu_);
	if(err!=errinfo_src_file_)
		return err;
	return 0;
}

#include "l4/l4___.cc"
#include "l4/args_util.cc"
