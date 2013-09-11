/*
 * jieshiqi_for___.cpp
 *
 *  Created on: 2012-1-26
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include "util.h"
#include "call_ex___.h"

int jieshiqi___::for__(qu___* qu,size_t& offi,size_t to,string& buf,deque<string>* eval_p){
	for(;;){
		size_t offi2=offi;
		size_t from2,to2;
		int kw2;
		int err;
		try{
			if((err=find__(qu,offi2,to,kwsm_juhao_,from2,to2,kw2,buf,true,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,eval_p)))
				return err;
			if((err=jieshi__(qu,from2,to2,buf,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,NULL,eval_p)))
				return err;
		}catch(int ex){
			if(ex==keyword_break_){
				offi=to2;
				break;
			}
			if(ex==keyword_continue_)
				continue;
			throw ex;
		}
	}
	return 0;
}

int jieshiqi___::loop__(qu___* qu,size_t& offi,size_t to,string& buf,deque<string>* eval_p){
	int err;
	size_t from2,to2,to4;
	string buf2;
	if((err=jieshi_buf__(qu,offi,to,buf,buf2,kwsm_jieheshi_|kwsm_juhao_,
			keyword_loop_,false,&from2,&to2,&to4)))
		return err;
	for(;;) {
		try{
			if((err=jieshi__(qu,from2,to2,buf,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,NULL,eval_p)))
				return err;
		}catch(call_ex___* ex){
			if(ex->s__().empty()||ex->s__()==buf2){
				int ex_kw = ex->kw__();
				delete ex;
				if(ex_kw == keyword_continue2_)
					continue;
				break;
			}
			throw ex;
		}
		break;
	}
	offi=to4;
	return 0;
}

int jieshiqi___::break2__(qu___* qu,size_t& offi,size_t to){
	string buf;
	int err;
	if((err=jieshi_buf__(qu,offi,to,buf,buf)))
		return err;
	throw new call_ex___(keyword_break2_, buf);
}

int jieshiqi___::continue2__(qu___* qu,size_t& offi,size_t to){
	string buf;
	int err;
	if((err=jieshi_buf__(qu,offi,to,buf,buf)))
		return err;
	throw new call_ex___(keyword_continue2_, buf);
}

int jieshiqi___::end__(qu___* qu,size_t& offi,size_t to){
	string buf;
	int err;
	if((err=jieshi_buf__(qu,offi,to,buf,buf)))
		return err;
	if(!buf.empty())
		exit_code_=s2i__(buf);
	return 0;
}

int jieshiqi___::jieshi_buf__(qu___* qu,size_t offi,size_t to,string& buf,string& buf2,
			unsigned long mask2,int kw0,bool is_code,
			size_t* from2_ret,size_t* to2_ret,size_t* to4_ret){
	size_t offi2=offi;
	size_t from2,to2;
	int kw2;
	int err;
	if((err=find__(qu,offi2,to,mask2,from2,to2,kw2,buf,false)))
		return err;
	if(kw0!=keyword_no_){
		if(kw2<=keyword_no_||kw2==keyword_juhao_){
			err_<<syn_[kw0];
			return errinfo_find_kw_;
		}
	}
	if(is_code){
		if((err=jieshi__(qu,from2,to2,buf2,NULL,NULL,keyword_no_,kwsm_1_,0)))
			return err;
	}else{
		if((err=jieshi__(qu,from2,to2,buf2,NULL,NULL,kw0)))
			return err;
	}
	if(kw0!=keyword_no_){
		if((err=find__(qu,offi2,to,kwsm_juhao_,from2,to2,kw2,buf,false)))
			return err;
		if(to4_ret)
			*to4_ret=to2;
		if(syn_.jiehe__(qu->src_,from2,to2)==keyword_jieheshi_)
			from2+=syn_[keyword_jieheshi_].length();
		if(syn_.jiehe__(qu->src_,to2-syn_[keyword_jiehezhong_].length(),to2)==keyword_jiehezhong_)
			to2-=syn_[keyword_jiehezhong_].length();
		if(from2_ret)
			*from2_ret=from2;
		if(to2_ret)
			*to2_ret=to2;
	}
	return 0;
}
