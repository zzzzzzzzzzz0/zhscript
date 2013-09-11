/*
 * jieshiqi_if_then___.cpp
 *
 *  Created on: 2010-3-28
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include "util.h"

int jieshiqi___::and_or__(qu___* qu,size_t from,size_t to,bool& result,zhi___& zuo){
#ifdef debug_liucheng_
	out_f_t__(qu->src_,from,to,out_clr_if_);
#endif
	const string& fei=syn_[keyword_fei_];
	int fei_len=fei.length();
	for(;from<to;){
		size_t from2,to2;
		int err;
		bool jiehe=false;
		err=syn_.jiehe__(qu->src_,from,to,from2,to2,&jiehe,err_);
		if(err)
			return err;
		if(jiehe){
			//这里还有先之前的一段的怎么处理
			if((err=and_or__(qu,from2,to2,result,zuo)))
				return err;
			from=to2+syn_[keyword_jiehezhong_].length();
			if(from>=to)
				break;
		}
		int kw2;
		string buf2;
		if((err=find__(qu,from,to,kwsm_and_or_,from2,to2,kw2,buf2)))
			return err;
		if(!jiehe){
			size_t from3,to3;
			int yunsuanfu;
			string buf3;
			int fei_cnt=0;
			if((err=find__(qu,from2,to2,kwsm_bijiaoyunsuanfu_,from3,to3,yunsuanfu,buf3)))
				return err;
			if(to3>from3){
				for(size_t i=from3;i<to3-fei_len;i+=fei_len){
					if(qu->src_.compare(i,fei_len,fei)==0){
						fei_cnt++;
					}else
						break;
				}
				if((err=jieshi__(qu,from3,to3,buf3,NULL,NULL,keyword_no_,kwsm_1_|kwsm_has_)))
					return err;
				zuo=buf3;
			}
#ifdef debug_liucheng_
			out_if__(zuo);
#endif
			switch(yunsuanfu){
			case keyword_dengyu_:
			case keyword_budengyu_:
			case keyword_xiaoyudengyu_:
			case keyword_xiaoyu_:
			case keyword_dayudengyu_:
			case keyword_dayu_:
				break;
			default:
				if(yunsuanfu>keyword_no_){
					to3+=syn_[yunsuanfu].length();
					yunsuanfu=keyword_no_;
				}
				break;
			}
			if(yunsuanfu>keyword_no_){
#ifdef debug_liucheng_
				out_kw__(syn_[yunsuanfu],out_clr_if_);
#endif
				to3+=syn_[yunsuanfu].length();
				string buf4;
				if((err=jieshi__(qu,to3,to2,buf4,NULL,NULL,keyword_no_,kwsm_1_|kwsm_has_)))
					return err;
				zhi___ you;
				you=buf4;
#ifdef debug_liucheng_
				out_if__(you);
#endif
				switch(yunsuanfu){
				case keyword_dengyu_:
					result = zuo==you;
					break;
				case keyword_budengyu_:
					result = zuo!=you;
					break;
				case keyword_xiaoyudengyu_:
					result = zuo<=you;
					break;
				case keyword_xiaoyu_:
					result = zuo<you;
					break;
				case keyword_dayudengyu_:
					result = zuo>=you;
					break;
				case keyword_dayu_:
					result = zuo>you;
					break;
				}
			}else
				result=zuo.bool__(syn_[keyword_null_],fei_cnt,fei_len);
		}
#ifdef debug_liucheng_
		out_if__(result?"正":"歪",out_clr_x_);
#endif
		if((!result&&kw2==keyword_and_)||(result&&kw2==keyword_or_))
			break;
		from=to2;
		if(kw2>keyword_no_){
#ifdef debug_liucheng_
			out_kw__(syn_[kw2],out_clr_if_);
#endif
			from+=syn_[kw2].length();
		}
	}
	return 0;
}

int jieshiqi___::if_then_else__(int kw,qu___* qu,size_t& offi,size_t to,string& buf,zhi___& zuo,bool& result,deque<string>* eval_p){
	size_t from2,to2;
	int kw2;
	int err;
	string buf2;
	size_t to3=offi;
	//|kwsm_if_
	if((err=find__(qu,to3,to,kwsm_juhao_,from2,to2,kw2,buf2,false)))
		return err;
	switch(kw){
	case keyword_if_:
	case keyword_switch_:
		if((err=find__(qu,offi,to3,
				kw==keyword_switch_?
						kwsm_juhao_|kwsm_then_else_ :
						kwsm_juhao_|kwsm_then_else_|kwsm_douhao_
				,from2,to2,kw2,buf2,false)))
			return err;
		if(kw==keyword_switch_){
			switch(kw2){
			case keyword_then_:
			case keyword_else_:
				result=true;
				if((err=and_or__(qu,from2,to2,result,zuo))){
					err_add__(qu,from2,to2);
					return err;
				}
				break;
			default:
				return jieshi__(qu,from2,to2,buf,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,NULL,eval_p);
			}
		}else{
			result=true;
			if((err=and_or__(qu,from2,to2,result,zuo))){
				err_add__(qu,from2,to2);
				return err;
			}
			switch(kw2){
			case keyword_then_:
			case keyword_else_:
				break;
			default:	//句号（尾）则认为赋值解释完，逗号？结果没错
				offi=to3;
			case keyword_douhao_:
#ifdef debug_liucheng_
				out_kw__(syn_[kw2],out_clr_if_);
#endif
				return 0;
			}
		}
		break;
	default:
		kw2=kw;
		offi-=syn_[kw2].length();
		break;
	}
	for(;;){
		unsigned long kwsm;
		int kw3;
		if(result){
			if(kw2==keyword_then_){
				kwsm=kwsm_else_|kwsm_juhao_|kwsm_douhao_;
				kw3=keyword_no_;
			}else{
				kwsm=kwsm_then_|kwsm_juhao_;
				kw3=keyword_then_;
			}
		}else{
			if(kw2==keyword_else_){
				kwsm=kwsm_juhao_|kwsm_douhao_;
				kw3=keyword_no_;
			}else{
				kwsm=kwsm_else_|kwsm_juhao_;
				kw3=keyword_else_;
			}
		}
		if(kw2>keyword_no_){
#ifdef debug_liucheng_
			out_kw__(syn_[kw2],out_clr_if_);
#endif
			offi+=syn_[kw2].length();
		}
		if((err=find__(qu,offi,to3,kwsm,from2,to2,kw2,buf2,false)))
			return err;
		if(kw3==keyword_no_){
			for(;;){
				/*size_t from4,to4;
				int kw4;
				if((err=find__(qu,from2,to2,0,from4,to4,kw4,buf)))
					return err;
				if((err=jieshi__(qu,from4,to4,buf)))
					return err;*/
				if((err=jieshi__(qu,from2,to2,buf,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,NULL,eval_p)))
					return err;

				if(kw2>keyword_no_){
#ifdef debug_liucheng_
					out_kw__(syn_[kw2],out_clr_if_);
#endif
					offi+=syn_[kw2].length();
				}
				if(kw2!=keyword_douhao_)
					break;
				if((err=find__(qu,offi,to3,kwsm,from2,to2,kw2,buf2,false)))
					return err;
			}
			break;
		}else{
			if(kw2!=kw3)
				break;
		}
	}
	offi=to3;
	return 0;
}

int jieshiqi___::switch__(qu___* qu,size_t& offi,size_t to,string& buf,deque<string>* eval_p){
	int err;
	size_t from2,to2,to4;
	string buf2;
	if((err=jieshi_buf__(qu,offi,to,buf,buf2,kwsm_jieheshi_|kwsm_bijiaoyunsuanfu_|kwsm_juhao_,
			keyword_switch_,false,&from2,&to2,&to4)))
		return err;
	zhi___ zuo;
	zuo=buf2;
	int kw2;
	try{
		for(;from2<to2;){
			size_t from3,to3;
			if((err=find__(qu,from2,to2,kwsm_juhao_,from3,to3,kw2,buf,false)))
				return err;
			bool luoji;
			if((err=if_then_else__(keyword_switch_,qu,from3,to3,buf,zuo,luoji,eval_p)))
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
	}catch(int ex){
		if(ex==keyword_break_){
		}else
			throw ex;
	}
	offi=to4;
	return 0;
}
