#include <string.h>

#include "api___.h"
#include<stdarg.h>
#include "call_util.cpp"
#include "def1.h"

api___::api___(){
}

api___::~api___(){
}

void suidao__(char**addr_ret,char*buf,long siz,api___* api,int argc,...) {
    va_list vl;
	deque<string> p;
    va_start(vl,argc);
    for(int i=0;i<argc;i++){
    	char*s=va_arg(vl,char*);
    	//cout<<s<<endl;
		p.push_back(s);
    }
    va_end(vl);
	api->api__(&p,buf,siz,addr_ret);
}

#include "plugin.h"

#include <nsDirectoryServiceUtils.h>
#include <nsStringAPI.h>

void api___::api__(deque<string>* p,char*buf,long siz,char**addr_ret){
	CPlugin* cp=(CPlugin*)cp_;

	if(p->size()==3&&(*p)[0]=="创建"){
		cp->create_element__((*p)[1].c_str(),(*p)[2].c_str());
		return;
	}
	if(p->size()==2&&(*p)[0]=="目录"){
		const char*prop=(*p)[1].c_str();
	    nsCOMPtr<nsIFile> dir;
	    NS_GetSpecialDirectory(prop, getter_AddRefs(dir));
	    cout<<"dir="<<dir<<endl;
	    if(dir){
			nsAutoString path;
			nsCAutoString cpath;
			dir->GetPath(path);
			CopyUTF16toUTF8(path, cpath);
			//cout<<cpath.get()<<endl;
			cpy__(buf,cpath.get(),siz);
	    }
		return;
	}
	if(p->size()==1&&(*p)[0]=="参数"){
		*addr_ret=dup__(url_query_.c_str());
		return;
	}
	/*if(p->size()==1&&(*p)[0]=="文件名"){
		*addr_ret=dup__(url_.c_str());
		return;
	}*/

	string buf2;
	for(size_t i=0;i<p->size();i++)
		buf2+=(*p)[i];
	if(buf2.length()<1)
		return;
	string buf3;
	const char* ret=cp->eval__(buf2.c_str(),buf3);
	if(!ret)
		ret=l4_.keyword__(keyword_null_);
	//cout<<ret<<endl;
	*addr_ret=dup__(ret);
}

const char* api___::cmd__(const char*s,void*spo){
	cout<<"d)cmd"<<"\t\t\t"<<cp_<<" C\t"<<spo<<" S\t"<<this<<" A\t"<<&l4_<<" L"<<endl;
	((CPlugin*)cp_)->debug__();
	if(!l4_.l4__())
		return NULL;
	int err;
	/*if((err=set_suidao__()))
		return NULL;*/
	err=0;
	const char* ret=l4_.l4_callback__(l4_.l4__(),&err,s,false,NULL,1,url_.c_str());
	switch(err){
	case 0:
	case jieshiqi_go_+keyword_end_:
	case jieshiqi_go_+keyword_exit_:
		break;
	default:
		l4_err_show__(err);
	}
	return ret;
}

void api___::l4_err_show__(int err){
	/*cerr*/cout<<l4_.err_<<l4_.err__()<<l4_.errinfo__(err)<<endl;
	l4_.err_clear__();
}

void api___::get_url__(){
	((CPlugin*)cp_)->eval__("decodeURI(document.location.href)",url_);
	string f="file://";
	size_t i=url_.find(f);
	if(i==0){
		url_=url_.substr(f.length());
	}
	i=url_.find('?');
	if(i!=string::npos){
		url_query_=url_.substr(i+1);
		url_=url_.substr(0,i);
	}
}

int api___::set_suidao__(){
	char buf[128];
	const char
		*dy=l4_.keyword__(keyword_call_)
		,*ky=l4_.keyword__(keyword_kaiyinhao_)
		,*by=l4_.keyword__(keyword_biyinhao_)
		,*d=l4_.keyword__(keyword_dunhao_)
		,*bs=l4_.keyword__(keyword_bianliangshi_)
		,*bz=l4_.keyword__(keyword_bianliangzhong_)
		,*c=l4_.keyword__(keyword_params_)
		,*j=l4_.keyword__(keyword_juhao_)
		;
	sprintf(buf,
		"%s" "%sASZ/%lx/&%s%s" "%s%lx%s%s" "%s%s%s%s",
		dy,
		ky,(long)suidao__,by,d,
		ky,(long)this,by,d,
		bs,c,bz,j);
	cout<<buf<<endl;
	return l4_.def_new__("隧道",buf);
}

bool api___::new__(int argc, char* argn[], char* argv[],void*cp) {
	cp_=cp;
	get_url__();

	const char *so_dir=0;
	string cmdline;
	for(int i=0;i<argc;i++){
		if(strcmp(argn[i],"src")==0){
			cmdline+=argv[i];
			continue;
		}
		if(strcmp(argn[i],"so_dir")==0){
			so_dir=argv[i];
			continue;
		}
		if(strcmp(argn[i],"id")==0){
			string s=argv[i];
			s+='_';
			//((CPlugin*)cp)->set_id__(s.c_str());
			continue;
		}
	}

	if(!so_dir){
		so_dir=url_.c_str();
	}

	int err;
	if((err=l4__(so_dir,cmdline))){
		l4_err_show__(err);
		return false;
	}

	return true;
}

int api___::l4__(const char* so_dir,string& cmdline){
	int err;

	cmdline="-S syn-zh -E err-zh "+cmdline;
	cout<<so_dir<<endl;
	cout<<cmdline<<endl;
	if((err=l4_.init__(so_dir,cmdline.c_str())))
		return err;
	l4_.add_path__(url_.c_str());
	if((err=set_suidao__()))
		return err;

	//((CPlugin*)cp_)->jieshi__();
	if((err=l4_.jieshi__()))
		return err;

	return 0;
}

//l4___ api___::l4_;

#include "l4/l4___.cc"
