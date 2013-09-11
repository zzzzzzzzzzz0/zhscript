/*
 * html2text.cpp
 *
 *  Created on: 2011-1-31
 *      Author: zzzzzzzzzzz
 */

#include"txtotxt.h"
#include<fstream>
#include<sstream>

#define duizhao_len_ 5
static string duizhao_[duizhao_len_][2]={
		{"nbsp"," "},
		{"amp","&"},
		{"quot","\""},
		{"lt","<"},
		{"gt",">"},
};

dlle___ void html2html__(char**addr_ret,char*src){
	if(!src)
		return;
	string buf;
	for(;;){
		char c=*src++;
		if(!c)
			break;
		switch(c){
		case'\n':
			buf+="<br/>";
		case'\r':
			continue;
		}
		bool b=true;
		for(int i=0;i<duizhao_len_;i++){
			if(duizhao_[i][1][0]==c){
				b=false;
				buf+='&';
				buf+=duizhao_[i][0];
				buf+=';';
				break;
			}
		}
		if(b){
			buf+=c;
		}
	}
	*addr_ret=dup__(buf.c_str());
}

dlle___ void html2text__(char**addr_ret,char*src,bool src_is_file,bool webuse){
	if(!src)
		return;
	string buf,tag;
	istream* is;
	ifstream* ifs=NULL;
	stringstream* ss=NULL;
	if(src_is_file){
		ifs=new ifstream(src);
		if(!*ifs){
			delete ifs;
			return;
		}
		is=ifs;
	}else{
		ss=new stringstream(src);
		is=ss;
	}
	bool hulve=false,head=false,script=false;
	int br=0,space=0;
	for(;;){
		int c=is->get();
		if(is->eof())
			break;
		switch(c){
		case'<':
			hulve=true;
			continue;
		case'>':
			hulve=false;
			if(tag=="head")
				head=true;
			else if(tag=="/head")
				head=false;
			else if(tag=="script"||tag.find("script ")==0)
				script=true;
			else if(tag=="/script")
				script=false;
			else if(tag=="br"||tag=="br/"||tag.find("br ")==0||tag=="p"){
				if(webuse)
					br++;
			}
			tag.clear();
			space=0;
			continue;
		case'&':
			if(!webuse){
				string buf2;
				int c2=0;
				for(;;){
					c2=is->get();
					if(c2==';'||is->eof())
						break;
					buf2+=c2;
				}
				bool b=true;
				for(int i=0;i<duizhao_len_;i++){
					if(duizhao_[i][0]==buf2){
						b=false;
						c=duizhao_[i][1][0];
						break;
					}
				}
				if(b){
					/*buf+=c;
					buf+=buf2;
					if(c2>0)
						buf+=c2;*/
					continue;
				}
			}
			break;
		case'\n':
			if(webuse){
				br++;
			}else
				buf+=c;
			continue;
		case'\r':
		case'\t':
			if(!webuse)
				buf+=c;
			continue;
		case' ':
			if(hulve)
				break;
			space++;
			continue;
		}
		if(c>=0&&c<' ')
			continue;
		if(hulve){
			if(c>='A'&&c<='Z')
				c=c-'A'+'a';
			tag+=c;
			continue;
		}
		if(head||script)
			continue;
		if(br > 0){
			if(!buf.empty()) {
				for(int i=0;i<br && i<2;i++) {
					buf+="<br/>";
				}
			}
			space=0;
			br=0;
		}
		if(space>0){
			for(int i=0;i<space;i++){
				if(webuse)
					buf+="&nbsp;";
				else
					buf+=" ";
			}
			space=0;
		}
		buf+=c;
	}
	if(ifs){
		ifs->close();
		delete ifs;
	}
	if(ss){
		delete ss;
	}
	*addr_ret=dup__(buf.c_str());
}
