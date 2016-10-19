/*
 * args___.cpp
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#include "args___.h"
#include "file___.h"
#include "path.h"
#include "../../new_gg/l4/args_util.hh"

/*void free_d_s__(deque<s___>* p) {
	for(size_t i = 0; i < p->size(); i++) {
		delete &((*p)[i]);
	}
}*/

args___::args___() {
	src_is_file_=true;
	is_server_pages_ = false;
}

args___::~args___() {
	//free_d_s__(&params_);
}

void args___::add_arg__(int argc,char** argv,int from){
	if(from<0)
		return;
	for(int i=from;i<argc;i++){
		string s=argv[i];
		if(i==from){
			size_t i1=s.rfind(" --");
			if(i1!=string::npos){
				add_arg__(s.substr(0,i1));
				continue;
			}
		}
		args_.push_back(s);
	}
}

void args___::add_arg__(const string& cmdline){
	list<string>::iterator li;
	add_arg2__(cmdline,li,false);
}

void args___::add_arg2__(const string& cmdline,list<string>::iterator li,bool use_li){
	string buf;
	bool empty=true;
	for(size_t i=0;i<cmdline.length();i++){
		unsigned char c=cmdline[i];
		if(c<=' '){
			if(!empty){
				if(use_li){
					li=args_.insert(++li,buf);
				}else
					args_.push_back(buf);
				buf.clear();
				empty=true;
			}
			continue;
		}
		empty=false;
		if(get_arg_str__('"',c,cmdline,i,buf))
			continue;
		if(get_arg_str__('\'',c,cmdline,i,buf))
			continue;
		buf+=c;
	}
	if(!empty)
		args_.push_back(buf);
}

bool args___::get_arg_str__(unsigned char c1,unsigned char c,const string& s,size_t& i,string& buf){
	if(c==c1){
		for(;;){
			if(++i>=s.length()){
				break;
			}
			c=s[i];
			if(c==c1)
				break;
			buf+=c;
		}
		return true;
	}
	return false;
}

void args___::set_path__(const string& s){
	file_.add_path1__(s);
}

int args___::get_arg__(const string& s1,string& s2,list<string>::iterator& li){
	if(*li==s1){
		if(++li==args_.end()){
			err_<<s1;
			return 1;
		}
		s2=*li;
		return 2;
	}
	return 0;
}

int args___::get_ini_file__(list<string>::iterator& li){
	const string filename=*li;
	string buf;
	int err=file_.get__(filename, false,buf);
	if(err){
		err_<<file_.err_;
		return err;
	}
	file_.add_path__(filename);
	add_arg2__(buf,li,true);
	return 0;
}

int args___::parse_args__(){
	bool all_is_param=false;
	for(list<string>::iterator li=args_.begin();li!=args_.end();++li) {
		string s=*li;

		if(s=="----"){
			all_is_param=!all_is_param;
			continue;
		}
		if(all_is_param){
			params_.push_back(s);
			continue;
		}

		switch(get_arg__("-S",syn_file_,li)){
		case 1:	return errinfo_param_num_;
		case 2:	continue;
		}
		switch(get_arg__("-E",err_file_,li)){
		case 1:	return errinfo_param_num_;
		case 2:	continue;
		}
		if(s=="-I"){
			if(++li==args_.end())
				return errinfo_param_num_;
			int err=get_ini_file__(li);
			if(err)
				return err;
			continue;
		}
		if(s=="-P"){
			if(++li==args_.end())
				return errinfo_param_num_;
			params_.push_back(*li);
			continue;
		}
		if(s=="-SP"){
			is_server_pages_ = true;
			continue;
		}
		if(s.length()>0&&s[0]!='-'&&src_.empty()){
			src_=s;
			continue;
		}
		if(s==jieshiqi_args_del_)
			continue;
		if(s.length()>2&&s[0]=='-'&&s[1]=='-'){
			if((s[2]>='0'&&s[2]<='9')||(s[2]>='a'&&s[2]<='z')||(s[2]>='A'&&s[2]<='Z')||s[2]=='-')
				;
			else
				continue;
		}
		//极大灵活性地接收参数
		/*err_<<src_<<" "<<s;
		return errinfo_param_err_;*/
		params_.push_back(s);
	}
	return 0;
}
