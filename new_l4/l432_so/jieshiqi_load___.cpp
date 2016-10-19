/*
 * jieshiqi_load___.cpp
 *
 *  Created on: 2010-11-1
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include "util.h"

int jieshiqi___::load__(deque<s___>* p,const char*src2,string& buf,int kw,qu___* qu,bool zheng){
	args___ args;
	args.src_is_file_=kw==keyword_load_;
	for(deque<s___>::iterator li=p->begin();li!=p->end();++li){
		s___ s = *li;
		if(args.src_.empty())
			args.src_=s;
		else
			args.params_.push_back(s);
	}
	if(src2)
		args.src2_=src2;
	try{
		return jieshi2__(&args,qu,buf);
	}catch(int ex){
		if(zheng&&ex==keyword_exit_){
			return 0;
		}
		throw ex;
	}
}

int jieshiqi___::eval__(deque<s___>* p,const char*src2,bool param,qu___* qu,
		size_t& offi,size_t to,string& buf,bool chuan,bool zheng){
	p->erase(p->begin()+1,p->end());
	if(param){
		size_t from2,to2;
		int kw2;
		int err;
		deque<s___> d;
		deque<s___>* p2;
		if(chuan){
			d.push_back((*p)[0]);
			p2=&d;
		}else
			p2=NULL;
		for(;;){
			string buf2;
			bool push_p=false;
			if((err=find__(qu,offi,to,kwsm_juhao_|kwsm_dunhao_,from2,to2,kw2,buf2,
					true,&push_p,p,keyword_no_,kwsm_1_,kwsm_1t_,p2)))
				return err;
			if((err=jieshi__(qu,from2,to2,buf2,&push_p,p)))
				return err;
			if(!push_p)
				p->push_back(buf2);
			/*//这又是因为什么加上？
			if(from2>=to2)
				break;*/
			if(kw2>keyword_no_){
				offi+=syn_[kw2].length();
#ifdef debug_liucheng_
				out_kw__(syn_[kw2]);
#endif
			}
			if(kw2!=keyword_dunhao_)
				break;
			from2=offi;
		}
	}
	return load__(p,src2,buf,keyword_eval_,qu,zheng);
}

int jieshiqi___::with__(qu___* qu,size_t& offi,size_t to,string& buf){
	int err;
	size_t from2,to2,to4;
	string buf2;
	if((err=jieshi_buf__(qu,offi,to,buf,buf2,kwsm_jieheshi_|kwsm_juhao_,
			keyword_with_,true,&from2,&to2,&to4)))
		return err;
	deque<s___> p;
	p.push_back(buf2);
	int kw2;
	for(;from2<to2;){
		size_t from3,to3;
		if((err=find__(qu,from2,to2,kwsm_juhao_,from3,to3,kw2,buf,false)))
			return err;
		if((err=jieshi__(qu,from3,to3,buf,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,NULL,&p)))
			return err;
		if(kw2>keyword_no_){
#ifdef debug_liucheng_
			out_kw__(syn_[kw2]);
#endif
			from2+=syn_[kw2].length();
		}
		if(kw2!=keyword_juhao_)
			break;
	}
	offi=to4;
	return 0;
}
