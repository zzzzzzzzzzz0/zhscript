/*
 * errinfo___.cpp
 *
 *  Created on: 2010-3-29
 *      Author: zzzzzzzzzzz
 */

#include "errinfo___.h"
#include "file___.h"
#include "util.h"
#include <sstream>

errinfo___::errinfo___() {
	has_=false;
}

errinfo___::~errinfo___() {
}


int errinfo___::get_file__(const string& path){
	string buf;
	int err=file_.get__(path,buf);
	if(err){
		err_<<file_.err_;
		return err;
	}
	istringstream is(buf);
	int i=0;
	for(;;i++){
		if(i<errinfos_length_)
			is>>errinfos_[i];
		else{
			string s;
			is>>s;
		}
		if(is.eof())
			break;
	}
	if(i!=errinfos_length_-1){
		err_<<l2s__(i)<<"/"<<l2s__(errinfos_length_);
		return errinfo_num_;
	}
	has_=true;
	return 0;
}

const char* errinfo___::operator[](int i){
	i--;
	if(!has_||i<0||i>=errinfos_length_){
		buf_.clear();
		buf_+="[";
		buf_+=l2s__(++i);
		buf_+="]";
		return buf_.c_str();
	}
	return errinfos_[i].c_str();
}
