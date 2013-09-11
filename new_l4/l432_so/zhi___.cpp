/*
 * zhi___.cpp
 *
 *  Created on: 2010-3-13
 *      Author: zzzzzzzzzzz
 */

#include "zhi___.h"
#include "util.h"

zhi___::zhi___() {
	type_=0;
}

zhi___::~zhi___() {
}

void zhi___::set_type__(){
	type_='s';
	l_=0;
	d_=0;
	if(!s_.empty()){
		bool shu=true;
		int dian=0;
		for(size_t i=0;i<s_.length();i++){
			char c=s_[i];
			if(c=='.')
				dian++;
			if((c>='0'&&c<='9')||(c=='.'&&dian<=1)||((c=='-'||c=='+')&&i==0&&s_.length()>1)){
			}else{
				shu=false;
				break;
			}
		}
		if(shu){
			if(dian==0){
				type_='l';
				l_=s2l__(s_);
			}else{
				type_='d';
				d_=s2d__(s_);
			}
		}
	}
}

bool zhi___::bool__(const string& null,int fei_cnt,int fei_len){
	if(type_!='b'){
		if(fei_cnt>0){
			s_=s_.substr(fei_cnt*fei_len);
			set_type__();
		}
		bool b=true;
		if(type_=='l')
			b=l_!=0;
		else if(type_=='d')
			b=d_!=0.0;
		else if(s_.length()<1||s_==null||s_=="false")
			b=false;
		for(int i=0;i<fei_cnt;i++)
			b=!b;
		b_=b;
		type_='b';
	}
	return b_;
}
