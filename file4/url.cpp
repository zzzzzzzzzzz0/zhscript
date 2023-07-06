#include<stdio.h>
#include<string>
using namespace std;
#include"for_arg_.h"
#include"call_util.cpp"
#include "api1.cpp"

typedef void*add___(const char*,bool,void*);

void urldecode__(const char*url, const string& mask, string& out) {
	char buf[] = {0, 0, 0};
	unsigned int im=0, c2;
	for(;;url++){
		unsigned char c=*url;
		if(!c)
			break;
		switch(c){
		case'%':
			if(!(buf[0]=*++url))
				break;
			if(!(buf[1]=*++url))
				break;
			sscanf(buf,"%X",&c2);
			c = c2;
			break;
		case'+':
			c=' ';
			break;
		}
		if(mask.size()>0){
			c^=mask[im];
			if(++im>=mask.size())
				im=0;
		}
		out+=c;
	}
}
dlle___ void urldecode__(int*c4w4,char**addr_ret,char*url,int argc,...){
	if(!url)
		return;

	string mask;
	_for_args( argc )
	switch(i){
	case 0:
		mask+=s;
		break;
	}
	_next_args

	string out;
	urldecode__(url, mask, out);
	*addr_ret=dup__(out.c_str());
}
dlle___ void rust_urldecode__(add___ add, void* env, char*url,int argc,...){
	if(!url)
		return;

	string mask;
	_for_args( argc )
	switch(i){
	case 0:
		mask+=s;
		break;
	}
	_next_args

	string out;
	urldecode__(url, mask, out);
	add(out.c_str(), false, env);
}

void urlencode__(char*url,const string& unchr,const string& mask, string& out){
	if(!url)
		return;

	char buf[8];
	unsigned int im=0;
	for(;;url++){
		unsigned char c=*url;
		if(!c)
			break;
		if(mask.size()>0){
			c^=mask[im];
			if(++im>=mask.size())
				im=0;
		}
		bool b=false;
		if(unchr.find(c)!=string::npos)
			b=true;
		else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
			b=true;
		else{
			switch(c){
			case'.':
			case'-':
			case'_':
			/*
			case',':
			case';':
			case':':
			case'/':
			case'\\':
			case'[':
			case']':
			case'(':
			case')':
			case'{':
			case'}':
			case'\'':
			case'`':
			case'~':
			case'!':
			case'$':
			case'^':
			case'*':
			case'|':
			*/
				b=true;
				break;
			}
		}
		if(b){
			out+=c;
		}else{
			sprintf(buf,"%%%02X",c);
			out+=buf;
		}
	}
}
dlle___ void urlencode__(int*c4w4,char**addr_ret,char*url,int argc,...){
	string unchr, mask;
	_for_args( argc )
	switch(i){
	case 0:
		mask+=s;
		break;
	case 1:
		unchr+=s;
		break;
	}
	_next_args
	string out;
	urlencode__(url, unchr,mask, out);
	*addr_ret=dup__(out.c_str());
}
dlle___ void rust_urlencode__(add___ add, void* env, char*url,int argc,...){
	string unchr, mask;
	_for_args( argc )
	switch(i){
	case 0:
		mask+=s;
		break;
	case 1:
		unchr+=s;
		break;
	}
	_next_args
	string out;
	urlencode__(url, unchr,mask, out);
	add(out.c_str(), false, env);
}

static string xieyi_ge_ = "://";
dlle___ void url_parse__(int* err, void* qu, const char* url, const char* mao_name
		, const char* xieyi_name, const char* url_name, const char* path_name) {
	if(!qu || !url)
		return;
	string url1 = url, param, mao, xieyi, path;
	size_t i;
	i = url1.find(xieyi_ge_);
	if(i != string::npos) {
		xieyi = url1.substr(0, i + xieyi_ge_.size());
		url1 = url1.substr(i + xieyi_ge_.size());
	} else {
		i = url1.find(':');
		if(i != string::npos) {
			xieyi = url1.substr(0, i + 1);
			url1 = url1.substr(i + 1);
		}
	}
	i = url1.find('#');
	if(i != string::npos) {
		mao = url1.substr(i + 1);
		url1 = url1.substr(0, i);
	}
	i = url1.find('?');
	if(i != string::npos) {
		param = url1.substr(i + 1);
		url1 = url1.substr(0, i);
	}
	i = url1.find('/');
	if(i != string::npos) {
		path = url1.substr(i);
		url1 = url1.substr(0, i);
	}

	string mask;
	{
		string mao2;
		urldecode__(mao.c_str(), mask, mao2);
		if((*err=var_new_(jsq_, qu, mao_name, mao2.c_str(), false ,false , false)))
			return;
	}

	if((*err=var_new_(jsq_, qu, url_name, url1.c_str(), false ,false , false)))
		return;
	if((*err=var_new_(jsq_, qu, xieyi_name, xieyi.c_str(), false ,false , false)))
		return;
	if((*err=var_new_(jsq_, qu, path_name, path.c_str(), false ,false , false)))
		return;

	{
		string line, key, val;
		for(; !param.empty();) {
			i = param.find('&');
			if(i != string::npos) {
				line = param.substr(0, i);
				param = param.substr(i + 1);
			} else {
				line = param;
				param.clear();
			}
			i = line.find('=');
			if(i != string::npos) {
				key = line.substr(0, i);
				val = line.substr(i + 1);
			} else {
				key = line;
				val.clear();
			}
			string key2, val2;
			urldecode__(key.c_str(), mask, key2);
			urldecode__(val.c_str(), mask, val2);
			if((*err=var_new_(jsq_, qu, key2.c_str(), val2.c_str(), false ,false , false)))
				return;
		}
	}
}
