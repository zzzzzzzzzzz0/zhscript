/*
 * var___.cpp
 *
 *  Created on: 2010-3-19
 *      Author: zzzzzzzzzzz
 */

#include "var___.h"
#include "util.h"

var___::var___() {
	readonly_=false;//必须设置因为会先用于判断
}

var___::~var___() {
}

void var___::val__(const string& val,list<string>* rems){
	if(rems&&rems->size()>0){
		for(list<string>::iterator li=rems->begin();li!=rems->end();++li){
			replace_all(*li,"\\","/");
			huashen__(*li,val);
		}
	}else
		huashen__("",val);
}

bool var___::has_huashen__(list<string>* rems){
	if(!rems||rems->size()==0){
		return true;
	}
	for(list<string>::iterator li=rems->begin();li!=rems->end();++li){
		for(map<int,var_val___>::iterator mi=huashen_.begin();mi!=huashen_.end();mi++){
			if(mi->second.rfind__(*li,string::npos)){
				return true;
			}
		}
	}
	return false;
}

void var___::huashen__(const string& name,const string& val){
	size_t i;
	bool has=false;
	for(i=0;i<huashen_.size();i++){
		if(huashen_[i].is__(name)){
			has=true;
			break;
		}
	}
	if(has)
		huashen_[i].val__(val);
	else
		huashen_[i]=var_val___(name,val);
}

map<int,var_val___>::iterator var___::huashen__(const string& s1,char use,size_t n){
	string s=s1;
	replace_all(s,"\\","/");
	/*int i;
	for(i=huashen_.size();--i>=0;){
		if(huashen_[i].rfind__(s,n))
			break;
	}
	return i<0 ? huashen_.end() : huashen_.find(i);*/
	/*map<int,var_val___>::reverse_iterator mi;
	for(mi=huashen_.rbegin();mi!=huashen_.rend();mi--){
		if(mi->second.rfind__(s,n)){
			if(use=='x')
				--mi;
			return mi.base();
		}
	}
	return huashen_.end();*/
	map<int,var_val___>::iterator mi1=huashen_.end();
	for(map<int,var_val___>::iterator mi=huashen_.begin();mi!=huashen_.end();mi++){
		if(mi->second.rfind__(s,n))
			mi1=mi;
	}
	return mi1;
}

const string& var___::val__(list<string>* rems){
	if(rems){
		for(list<string>::iterator li=rems->begin();li!=rems->end();++li){
			map<int,var_val___>::iterator mi=huashen__(*li);
			if(mi!=huashen_.end())
				return mi->second.val__();
		}
	}
	return (--huashen_.end())->second.val__();
}

void var___::del__(map<int,var_val___>::iterator mi){
	if(mi!=huashen_.end()){
		//int i=mi->first,i1=huashen_.size()-1;
		huashen_.erase(mi);
		/*if(i!=i1){
			huashen_[i]=huashen_[i1];
			huashen_.erase(i1);
		}*/
	}
}

bool var___::del__(list<string>* rems){
	if(rems&&rems->size()>0){
		for(list<string>::iterator li=rems->begin();li!=rems->end();++li)
			del__(huashen__(*li,'x'));
	}else
		huashen_.clear();
	return huashen_.size()<=0;
}

bool var___::del__(){
	if(!qianche_rem_.empty()){
		del__(huashen__(qianche_rem_,'x'));
		qianche_rem_.clear();
	}
	return huashen_.size()<=0;
}

bool var___::qianche__(const string& rem){
	if(!qianche_rem_.empty())
		return false;
	if(huashen__(rem,0)==huashen_.end())
		return false;
	qianche_rem_=rem;
	return true;
}
