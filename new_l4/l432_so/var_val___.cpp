/*
 * var_val___.cpp
 *
 *  Created on: 2010-4-21
 *      Author: zzzzzzzzzzz
 */

#include "var_val___.h"
#include<algorithm>

//即使没有使用了也先留着做缓存
deque<string> var_val___::rems_;

var_val___::var_val___(const string& rem,const string& val){
	deque<string>::iterator di=find(rems_.begin(),rems_.end(),rem);
	if(di==rems_.end()){
		rems_.push_back(rem);
		i_=rems_.size()-1;
	}else
		i_=di-rems_.begin();
	val_=val;
}

bool var_val___::rfind__(const string& s,size_t n){
	if(i_<0){
	}
	string k=rems_[i_];
	if(k.size()<s.size()){
		return false;
	}
	size_t i=k.rfind(s);

	if(i==string::npos)
		return false;
	if(i>0&&k[i-1]!='/')
		return false;
	if(i!=k.size()-s.size())
		return false;
	if(n!=string::npos&&i>n)
		return false;
	return true;
}
