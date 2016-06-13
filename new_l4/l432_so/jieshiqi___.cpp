/*
 * jieshiqi___.cpp
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include "file___.h"
#include "util.h"
#include<algorithm>
#include "call_ex___.h"

jieshiqi___::jieshiqi___() {
	exit_code_=0;
	is_end_ = false;
}

jieshiqi___::~jieshiqi___() {
}

int jieshiqi___::jieshi__(qu___* shangji,string& buf){
	int err;
	try{
		err=jieshi2__(&args_,shangji,buf);
	}
	catch(int ex){
		switch(ex){
		case keyword_end_:
			is_end_ = true;
		case keyword_exit_:
			err=0;
			break;
		default:
			err_<<syn_[ex];
			err=errinfo_ex_;
		}
	}
	catch(string ex){
		err_<<ex;
		err=errinfo_ex_;
	}
	catch(call_ex___* ex){
		err_<<ex->s__();
		delete ex;
		err=errinfo_ex_;
	}
	catch(...){
		err=errinfo_ex_;
	}
	return err;
}

int jieshiqi___::jieshi2__(args___* args,qu___* shangji,string& buf){
	int err;
	if(!syn_.has__())
		return errinfo_syn_file_;
	if(args->src_is_file_&&args->src_.empty())
		return errinfo_src_file_;
	qu___ qu;
    if(!shangji)
    	shangji=&top_qu_;
	qu.shangji_=shangji;
	qu.args_=args;
	if(args->src_is_file_){
		err=file_.get__(args->src_,qu.src_);
		if(err){
			err_<<file_.err_;
			return err;
		}
		if(args_.is_server_pages_) {
			if(args->src_.rfind("sp") == args->src_.length() - 2) {
				qu.src_ = syn_[keyword_yuanyangshi_] + qu.src_;
			}
		}
	}else
		qu.src_=args->src_;

	syn_.yasuo__(qu.src_);
	bool has_add_path = false;
	if(args->src_is_file_)
		has_add_path = file_.add_path2__(args->src_);
	try{
		err=jieshi__(&qu,0,qu.src_.length(),buf);
	}catch(...){
		if(has_add_path)
			file_.del_path2__();
		throw;
	}
	if(has_add_path)
		file_.del_path2__();
	return err;
}

qu___* jieshiqi___::new_main_qu__(){
	qu___* qu=new qu___();
	qu->shangji_=&top_qu_;
	qu->args_=&args_;
	return qu;
}

qu___* jieshiqi___::main_qu__(qu___* qu){
	for(;;){
		if(!qu->shangji_)
			return qu;
		if(qu->shangji_==&top_qu_)
			break;
		qu=qu->shangji_;
	}
	return qu;
}

int jieshiqi___::kw_qu__(qu___* qu){
	if(qu==&top_qu_)
		return keyword_top_;
	if(qu==main_qu__(qu))
		return keyword_main_;
	return keyword_no_;
}

int jieshiqi___::find__(qu___* qu,size_t& offi,size_t to,
		unsigned long mask2,size_t& from2,size_t& to2,
		int& kw2,string& buf,bool jieshi,bool* push_p,deque<string>* p,int kw0,
		unsigned long mask,unsigned long maskt,
		deque<string>* eval_p)
{
	from2=offi;
	kw2=keyword_no_;
	int text_cnt=0,yuanyang_cnt=0,code_cnt=0;
	for(to2=from2;;){
		kw2=syn_.find__(qu->src_,to2,text_cnt,yuanyang_cnt,code_cnt,mask2,0);
		if(kw2>keyword_no_&&!syn_.kuoyinhao__(kw2)){
			if(to2+syn_[kw2].length()>to){
				kw2=keyword_no_;
			}
			break;
		}
		if(text_cnt==0&&yuanyang_cnt==0&&code_cnt==0){
			size_t from3,to3;
			size_t to4=to2;
			bool jiehe=false;
			int err;
			err=syn_.jiehe__(qu->src_,to2,to,from3,to3,&jiehe,err_);
			if(err)
				return err;
			if(jiehe){
				if(jieshi){
					if((err=jieshi__(qu,from2,to4,buf,push_p,p,kw0,mask,maskt)))
						return err;
					if((err=jieshi__(qu,from3,to3,buf,push_p,p,kw0,mask,maskt,NULL,eval_p)))
						return err;
					from2=to2;
				}
				continue;
			}
		}
		if(to2>=to){
			to2=to;
			break;
		}
		to2+=syn_.step__(qu->src_,to2);
	}
	offi=to2;
	return 0;
}

int jieshiqi___::x__(int kw,qu___* qu,size_t& offi,size_t to,string& buf,int kw0){
	size_t from=offi;
	size_t from2,to2;
	int kw2;
	deque<string> p;
	int err;
	unsigned long mask;
	switch(kw){
	case keyword_echo_:
	case keyword_exec_:
		mask=kwsm_juhao_;
		break;
	default:
		mask=kwsm_juhao_|kwsm_dunhao_;
		break;
	}
	for(;;){
		string buf2;
		bool push_p=false;
		if((err=find__(qu,offi,to,mask,from2,to2,kw2,buf2,true,&push_p,&p,kw)))
			return err;
		if(p.size()==0&&kw==keyword_eval_)
			err=jieshi__(qu,from2,to2,buf2,&push_p,&p,kw,kwsm_1_,0);
		else
			err=jieshi__(qu,from2,to2,buf2,&push_p,&p,kw);
		if(err){
			err_add__(qu,from2,to2,false,kw);
			return err;
		}
		if(!push_p)
			p.push_back(buf2);
		/*//这句当初是因为什么加上？现在是有先了的话会导致没参数
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
	switch(kw){
	case keyword_echo_:
		if((err=echo__(&p,buf,kw0)))
			return err;
		break;
	case keyword_exec_:
		if((err=exec__(&p,buf)))
			return err;
		break;
	case keyword_call_:
		if((err=call__(&p,buf,qu)))
			return err;
		break;
	case keyword_load_:case keyword_eval_:
		if((err=load__(&p,NULL,buf,kw,qu,true))){
			err_add__(qu,from,to2,true,kw);
			return err;
		}
		break;
	case keyword_delete_:
		if((err=delete__(&p,qu)))
			return err;
		break;
	}
	return 0;
}

#ifdef ver_android_
extern void android_log__(const string& s);
#endif

int jieshiqi___::echo__(deque<string>* p,string& buf,int kw0){
	string s;
	for(deque<string>::iterator li=p->begin();li!=p->end();++li) {
		if(li != p->begin())
			s += ' ';
		s+=*li;
	}
	if(args_.is_server_pages_)
		buf += s;
	else {
#ifdef ver_android_
		android_log__(s);
#else
		cout<<s;
#endif
		if(kw0!=keyword_no_) {
			//不利于“解释”的调试
			buf+=s;
		}
	}
	return 0;
}

int jieshiqi___::asc__(qu___* qu,size_t& offi,size_t to,string& buf){
	string s;
	for(int i=0;offi<to&&i<5;offi++,i++){
		char c=qu->src_[offi];
		if(!(c>='0'&&c<='9'))
			break;
		s+=c;
	}
	if(s.empty())
		buf+=syn_[keyword_asc_];
	else
		buf+=s2i__(s);
	return 0;
}

void jieshiqi___::err_add__(qu___* qu,size_t from,size_t to,bool qiangzhi,int kw){
	if(err_.add1_&&!qiangzhi)
		return;
	err_.add1_=true;
	if(err_.has__())
		err_<<syn_[keyword_maohao_];
	err_<<syn_[keyword_kaiyinhao_];
	/*if(kw>keyword_no_)
		err_<<syn_[kw];*/
	for(size_t offi=from;offi<to;){
		int len=syn_.step__(qu->src_,offi);
		err_<<qu->src_.substr(offi,len);
		offi+=len;
	}
	err_<<syn_[keyword_biyinhao_];
	if(qu->args_->src_is_file_)
		err_<<qu->args_->src_;
}

int jieshiqi___::jieshi__(qu___* qu,size_t from,size_t to,string&buf,
		bool* push_p,deque<string>* p,
		int kw0,
		unsigned long mask,unsigned long maskt,
		list<string>* rems,
		deque<string>* eval_p)
{
#ifdef debug_liucheng_
	out_f_t__(qu->src_,from,to);
#endif
	int err;
	int text_cnt=0,yuanyang_cnt=0,code_cnt=0;
	zhi___ zuo;
	bool luoji=true;
	int text_zhujie=tzj_text_;
	for(size_t offi=from;offi<to;){
		unsigned long maskt2;
		if(text_zhujie==tzj_yuanyang_||text_zhujie==tzj_code_)
			maskt2=0;
		else
			maskt2=maskt;
		int kw=syn_.find__(qu->src_,offi,text_cnt,yuanyang_cnt,code_cnt,mask,maskt2,rems,&text_zhujie);
		size_t offi2=offi;
		switch(kw){
		case keyword_jieheshi_:
#ifdef debug_liucheng_
			out_kw__(syn_[kw]);
#endif
			{
				size_t from2,to2;
				if((err=syn_.jiehe2__(kw,qu->src_,offi,to,from2,to2,err_))){
					err_add__(qu,offi2,to2);
					return err;
				}
				if((err=jieshi__(qu,from2,to2,buf,push_p,p,kw0,mask,maskt2,rems)))
					return err;
			}
#ifdef debug_liucheng_
			out_kw__(syn_[keyword_jiehezhong_]);
#endif
			continue;
		case keyword_no_:
		case keyword_echo_:
		case keyword_exec_:
			{
				bool use=false;
				err=use_def__(qu,offi,to,buf,&use);
				if(use){
					if(err){
						err_add__(qu,/*from*/offi2,/*to*/offi);
						return err;
					}
					continue;
				}
			}
			break;
		case -(keyword_is_t_+keyword_is_text_):
		case -(keyword_is_t_+keyword_is_yuanyang_):
		case -(keyword_is_t_+keyword_is_code_):
			if(eval_p){
				err=eval__(eval_p,NULL,true,qu,offi,to,buf,true,false);
				if(err){
					err_add__(qu,offi2,offi);
					return err;
				}
				continue;
			}
			break;
		}
		if(kw>keyword_no_){
#ifdef debug_liucheng_
			out_kw__(syn_[kw]);
#endif
			offi+=syn_[kw].length();
			if(offi>to)
				break;
			switch(kw){
			case keyword_echo_:
			case keyword_exec_:
			case keyword_call_:
			case keyword_load_:
			case keyword_eval_:
			case keyword_delete_:
				//这里不能加eval_p，他会对文本也调用
				if(!(err=x__(kw,qu,offi,to,buf,kw0)))
					continue;
				/*//出现关键字重复
				err_add__(qu,from,to,false,kw);
				return err;*/
				break;
			case keyword_if_:
			case keyword_then_:
			case keyword_else_:
				//这里加eval_p在调用已有定义时逻辑是否混乱
				if(!(err=if_then_else__(kw,qu,offi,to,buf,zuo,luoji,eval_p)))
					continue;
				break;
			case keyword_switch_:
				if(!(err=switch__(qu,offi,to,buf,eval_p)))
					continue;
				if(err==errinfo_find_kw_)
					err=0;
				break;
			case keyword_with_:
				if(!(err=with__(qu,offi,to,buf)))
					continue;
				if(err==errinfo_find_kw_)
					err=0;
				break;
			case keyword_set_:
			case keyword_define_:
			case keyword_alias_:
				if(!(err=set_equ__(qu,offi,to,kw,buf,kw0,eval_p)))
					continue;
				break;
			case keyword_bianliangshi_:
			case keyword_has_:
				if(!(err=var__(qu,offi,to,buf,kw,push_p,p)))
					continue;
				//让上一层去显示的话可能全部源码
				return err;
				//break;
			case keyword_asc_:
				if(!(err=asc__(qu,offi,to,buf)))
					continue;
				if(err==errinfo_param_num_)
					err=0;
				break;
			case keyword_for_:
				if(!(err=for__(qu,offi,to,buf,eval_p)))
					continue;
				break;
			case keyword_loop_:
				if(!(err=loop__(qu,offi,to,buf,eval_p)))
					continue;
				break;
			case keyword_break2_:
				if(!(err=break2__(qu,offi,to)))
					continue;
				break;
			case keyword_continue2_:
				if(!(err=continue2__(qu,offi,to)))
					continue;
				break;
			case keyword_end_:
				if((err=end__(qu,offi,to)))
					break;
			case keyword_exit_:
			case keyword_break_:
			case keyword_continue_:
				throw kw;
			default:
				if(!(code_cnt>0&&(kw==keyword_yuanyangshi_||kw==keyword_yuanyangzhong_)))
				{
#ifdef debug_liucheng_
					out_kw__(syn_[kw],out_clr_x_);
#endif
					continue;
				}
			case keyword_jiehezhong_:
				err=0;
				break;
			}
			if(err){
				err_add__(qu,/*from*/offi2,/*to*/offi);
				return err;
			}
			err_.del__();
			buf+=syn_[kw];
			continue;
		}
		if(offi>=to)
			break;
		if(eval_p){
			err=eval__(eval_p,NULL,true,qu,offi,to,buf,true,false);
			if(err){
				err_add__(qu,/*from*/offi2,/*to*/offi);
				return err;
			}
			continue;
		}
		int len=syn_.step__(qu->src_,offi);
		if(syn_.is_text__(qu->src_[offi],len,kw,text_zhujie))
			buf+=qu->src_.substr(offi,len);
		offi+=len;
	}
	if(push_p&&*push_p&&!buf.empty()){
		p->push_back(buf);
		buf.clear();
	}
	return 0;
}
