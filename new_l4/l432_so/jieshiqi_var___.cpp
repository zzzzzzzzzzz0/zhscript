/*
 * var_oper___.cpp
 *
 *  Created on: 2010-3-27
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include "util.h"
#include "file___.h"
#include"defi.h"
#include <stdarg.h>
#include "jieshiqi_callback.h"

static const char* callback0__(jieshiqi___* jsq,qu___* shangji,args___* args,int* err,bool bylib,call_ex___* ce){
	string& buf=cb_buf__();
	try{
		*err=jsq->jieshi2__(args,shangji,buf);
	}catch(int ex){
		switch(ex){
		case keyword_end_:
		case keyword_exit_:
		case keyword_break_:
		case keyword_continue_:
			*err=jieshiqi_go_+ex;
			break;
		default:
			*err=errinfo_ex_;
		}
	}
	catch(call_ex___* ex){
		if(ce){
			ce->kw__(ex->kw__());
			ce->s__(ex->s__());
		}
		*err=errinfo_ex_;
	}
	catch(...){
		*err=errinfo_ex_;
	}
	if(bylib)
		if(*err)
			*err+=jieshiqi_err_;
	return buf.c_str();
}
const char* callback1__(jieshiqi___* jsq,qu___* shangji,int* err,bool bylib,call_ex___* ce,
		const char* src,bool src_is_file,const char* src2,int argc,va_list& argv){
	if(!src||!jsq||!err){
		if(err)
			*err=errinfo_get_;
		return NULL;
	}
	args___ args;
	args.src_=src;
	args.src_is_file_=src_is_file;
	if(src2)
		args.src2_=src2;

    for(int i = 0; i < argc; ++i){
        char*s = va_arg(argv, char*);
        args.params_.push_back(s?s:jsq->syn_[keyword_null_]);
    }
    return callback0__(jsq,shangji,&args,err,bylib,ce);
}
const char* callback3__(jieshiqi___* jsq,qu___* shangji,int* err,bool bylib,call_ex___* ce,
		const char* src,bool src_is_file,const char* src2,int argc,const char**argv,int from){
	if(!src||!jsq||!err||(!argv&&argc-from>0)){
		if(err)
			*err=errinfo_get_;
		return NULL;
	}
	args___ args;
	args.src_=src;
	args.src_is_file_=src_is_file;
	if(src2)
		args.src2_=src2;

    for(int i = from; i < argc; ++i){
        const char*s = argv[i];
        args.params_.push_back(s?s:jsq->syn_[keyword_null_]);
    }
    return callback0__(jsq,shangji,&args,err,bylib,ce);
}
const char* o_callback_2__(jieshiqi___* jsq,qu___* shangji,int* err,call_ex___*ce,const char* src,bool src_is_file,const char* src2,int argc,...){
	va_list argv;
    va_start(argv, argc);
    const char* ret=callback1__(jsq,shangji,err,true,ce,src,src_is_file,src2,argc,argv);
    va_end(argv);
    return ret;
}
const char* o_callback_1__(jieshiqi___* jsq,qu___* shangji,int* err,const char* src,bool src_is_file,const char* src2,int argc,...){
	va_list argv;
    va_start(argv, argc);
    const char* ret=callback1__(jsq,shangji,err,true,NULL,src,src_is_file,src2,argc,argv);
    va_end(argv);
    return ret;
}
const char* o_callback__(jieshiqi___* jsq,qu___* shangji,int* err,const char* src,bool src_is_file,int argc,...){
	va_list argv;
    va_start(argv, argc);
    const char* ret=callback1__(jsq,shangji,err,true,NULL,src,src_is_file,NULL,argc,argv);
    va_end(argv);
    return ret;
}
const char* o_callback3_2__(jieshiqi___* jsq,qu___* shangji,int* err,call_ex___*ce,const char* src,bool src_is_file,const char* src2,int argc,const char**argv,int from){
    return callback3__(jsq,shangji,err,true,ce,src,src_is_file,src2,argc,argv,from);
}
const char* o_callback3_1__(jieshiqi___* jsq,qu___* shangji,int* err,const char* src,bool src_is_file,const char* src2,int argc,const char**argv,int from){
    return callback3__(jsq,shangji,err,true,NULL,src,src_is_file,src2,argc,argv,from);
}
const char* o_callback3__(jieshiqi___* jsq,qu___* shangji,int* err,const char* src,bool src_is_file,int argc,const char**argv,int from){
    return o_callback3_1__(jsq,shangji,err,src,src_is_file,NULL,argc,argv,from);
}

dlle___ int l4_var_new__(jieshiqi___* jsq,qu___* qu,
		const char* name,const char* val,
		bool readonly,
		int type,bool is_noparam)
{
	int err;
	if(!name||!val||!jsq/*||!qu*/)
		err=errinfo_get_;
	else{
		list<string> rems;
		qu___* qu2=qu;
		string buf2=name;
		bool is_code=false;
		bool is_yuanyang=false;
		bool is_lib=false;
		err=jsq->rems__(buf2,&rems,&qu2,&qu2,&qu2,&readonly,&is_noparam,&is_code,&is_yuanyang,&is_lib);
		if(!err)
			err=jsq->var_new__(qu2,buf2,val,readonly,type,is_noparam,is_lib,&rems);
	}
	if(err)
		err+=jieshiqi_err_;
	return err;
}

const char* o_var__(jieshiqi___* jsq,qu___* qu,const char* name){
	if(!name||!jsq||!qu)
		return NULL;
	string buf2=name;
	string& buf=cb_buf__();
	int err=jsq->var__(buf2,buf,qu,keyword_no_,NULL,NULL);
	if(err)
		return NULL;
	return buf.c_str();
}

int o_delete__(jieshiqi___* jsq,qu___* qu,const char* name){
	int err;
	if(!name||!jsq||!qu)
		err=errinfo_get_;
	else{
		string buf2=name;
		err=jsq->delete__(buf2,qu);
	}
	if(err)
		err+=jieshiqi_err_;
	return err;
}

void o_var_for_1__(qu___* qu,callback___ cb,int max){
	if(!qu||!cb)
		return;
	for(int i=0;qu;i++){
		if(max>=0&&i>=max)
			break;
		if(qu->args_){
			cb(3,"0",qu->args_->src_.c_str(),qu->args_->src_is_file_?has_true_:has_false_);
			for(size_t i=0;i<qu->args_->params_.size();i++)
				cb(2,"1",qu->args_->params_[i].c_str());
		}else
			cb(2,"0","");
		for(map<string,var___>::iterator mi=qu->vars_.begin();mi!=qu->vars_.end();mi++){
			var___* var=&mi->second;
			cb(5,"1",mi->first.c_str(),
					var->readonly_?has_true_:has_false_,
					l2s__(var->type_).c_str(),
					var->is_noparam_?has_true_:has_false_
					);
			for(map<int,var_val___>::iterator mi2=var->huashen_.begin();mi2!=var->huashen_.end();mi2++){
				var_val___*val=&mi2->second;
				cb(2,"2",val->name__().c_str());
				cb(2,"3",val->val__().c_str());
			}
		}
		qu=qu->shangji_;
	}
}
void o_var_for__(qu___* qu,callback___ cb){
	o_var_for_1__(qu,cb,-1);
}

void o_var_for_name__(jieshiqi___* jsq,qu___* qu2,int* err,void*ce,const char* src,callback3_2___ cb,qu___* qu1,int max){
	if(!qu1||!qu2||!cb||!jsq)
		return;
	qu___* qu=qu1;
	int argc=3;
	const char*argv[argc];
	for(int i=0;qu;i++){
		if(max>=0&&i>=max)
			break;
		int kw=jsq->kw_qu__(qu);
		for(map<string,var___>::iterator mi=qu->vars_.begin();mi!=qu->vars_.end();mi++){
			string zhujie,zhujie2;
			if(kw!=keyword_no_){
				zhujie+=jsq->syn_[keyword_zhujieshi_];
				zhujie+=jsq->syn_[kw];
				zhujie+=jsq->syn_[keyword_zhujiezhong_];
			}
			else {
				for(int i1=0;i1<i;i1++){
					zhujie+=jsq->syn_[keyword_zhujieshi_];
					zhujie+=jsq->syn_[keyword_shangji_];
					zhujie+=jsq->syn_[keyword_zhujiezhong_];
				}
			}
			var___* var=&mi->second;
			for(map<int,var_val___>::iterator mi2=var->huashen_.begin();mi2!=var->huashen_.end();mi2++){
				var_val___*val=&mi2->second;
				if(!val->name__().empty()){
					zhujie2+=jsq->syn_[keyword_zhujieshi_];
					zhujie2+=val->name__();
					zhujie2+=jsq->syn_[keyword_zhujiezhong_];
				}
			}
			argv[0]=mi->first.c_str();
			argv[1]=zhujie.c_str();
			argv[2]=zhujie2.c_str();
			cb(jsq,qu2,err,ce,src,false,NULL,argc,argv,0);
		}
		qu=qu->shangji_;
	}
}
dlle___ qu___* l4_new_qu__(qu___* shangji);
dlle___ void l4_delete_qu__(qu___* qu);
dlle___ const char* l4_err__(jieshiqi___* l4);
dlle___ void l4_err_clear__(jieshiqi___* l4);
dlle___ const char* l4_errinfo__(jieshiqi___* l4,int err);
dlle___ void l4_err_out__(jieshiqi___* l4, const char* ret, int err, int by);
dlle___ void l4_go__(jieshiqi___* l4, int kw);
string callbackx__(int num,jieshiqi___* jsq,qu___* qu){
	switch(num){
	case kwnum_no_:
		return l2x__((long)o_callback__);
	case 10: return l2x__((long)o_callback_1__);
	case 0:	return l2x__((long)jsq);
	//case 11:ce
	case 1:	return l2x__((long)qu);
	case 17:return l2x__((long)jsq->main_qu__(qu));
	case 2:	return l2x__((long)l4_var_new__);
	//case 12
	case 3:	return l2x__((long)o_var__);
	case 13:return l2x__((long)o_var_for_name__);
	case 4:	return l2x__((long)o_delete__);
	//case 14
	case 5:	return l2x__((long)o_var_for__);
	case 15:return l2x__((long)o_var_for_1__);
	case 6: return l2x__((long)o_callback3__);
	case 16:return l2x__((long)o_callback3_1__);
	case 7: return l2x__((long)l4_new_qu__);
	//case 17
	case 8:return l2x__((long)l4_delete_qu__);
	//case 18

	case 9: return l2x__((long)o_callback_2__);
	case 19:return l2x__((long)o_callback3_2__);

	case 20:return l2x__((long)l4_err__);
	case 21:return l2x__((long)l4_err_clear__);
	case 22:return l2x__((long)l4_errinfo__);
	case 23:return l2x__((long)l4_err_out__);

	case 24:return l2x__((long)l4_go__);
	}
	return "";
}

int jieshiqi___::rems__(list<string>* rems,qu___** top,qu___** main1,qu___** shangji,
		bool* lock,bool* is_noparam,bool* is_code,bool* is_yuanyang,bool* is_lib)
{
	bool top2=false,lock2=false,is_lib2=false;
	if(syn_.rem_kw__(rems,keyword_top_)>0){
		top2=true;
	}
	if(syn_.rem_kw__(rems,keyword_lock_)>0){
		lock2=true;
	}
	if(syn_.rem_kw__(rems,keyword_lib_)>0){
		is_lib2=true;
		if(is_lib)
			*is_lib=true;
	}
	if(top2||is_lib2){
		if(top)
			*top=&top_qu_;
	}
	if(lock2||is_lib2){
		if(lock)
			*lock=true;
	}

	if(syn_.rem_kw__(rems,keyword_main_)>0){
		if(main1)
			*main1=main_qu__(*main1);
	}
	for(int i=syn_.rem_kw__(rems,keyword_shangji_);i>0;i--){
		if(shangji){
			if(!(*shangji)->shangji_)
				return errinfo_var_find_;
			(*shangji)=(*shangji)->shangji_;
		}
	}
	if(syn_.rem_kw__(rems,keyword_noparam_)>0){
		if(is_noparam)
		*is_noparam=true;
	}
	if(syn_.rem_kw__(rems,keyword_code_)>0){
		if(is_code)
		*is_code=true;
	}
	if(syn_.rem_kw__(rems,keyword_yuanyang_)>0){
		if(is_yuanyang)
		*is_yuanyang=true;
	}
	return 0;
}

int jieshiqi___::rems__(string& buf2,list<string>* rems,qu___** top,qu___** main1,qu___** shangji,
		bool* lock,bool* is_noparam,bool* is_code,bool* is_yuanyang,bool* is_lib)
{
	int err;
	qu___ qu;
	qu.src_=buf2;
	buf2.clear();
	if((err=jieshi__(&qu,0,qu.src_.length(),buf2,NULL,NULL,keyword_no_,0,0,rems)))
		return err;
#ifdef debug_liucheng_
	for(list<string>::iterator li=rems->begin();li!=rems->end();++li)
		cout<<"\033[0;3"<<out_clr_k_<<";45m"<<*li<<"\033[0m";
#endif
	return rems__(rems,top,main1,shangji,lock,is_noparam,is_code,is_yuanyang,is_lib);
}

int jieshiqi___::var__(qu___* qu,size_t& offi,size_t to,string& buf,int kw,bool* push_p,deque<string>* p){
	size_t from2,to2,offi2;
	int kw2;
	string buf2;
	int err;
	unsigned long kwsm;
	switch(kw){
	case keyword_has_:
		kwsm=0;
		break;
	default:
		kwsm=kwsm_var_;
		break;
	}
	if((err=find__(qu,offi,to,kwsm,from2,to2,kw2,buf2)))
		return err;
	switch(kw2){
	case keyword_bianliangshi_:
		if(to2>from2)
			buf2+=qu->src_.substr(from2,to2-from2);
		for(;;){
			offi+=syn_[kw2].length();
			if((err=var__(qu,offi,to,buf2,kw,push_p,p)))
				return err;
			offi2=offi;
			if((err=find__(qu,offi,to,kwsm_var_,from2,to2,kw2,buf2)))
				return err;
			if(offi>offi2)
				buf2+=qu->src_.substr(offi2,offi-offi2);
			if(kw2==keyword_bianliangshi_)
				continue;
			if(kw2==keyword_bianliangzhong_)
				break;
			return errinfo_find_kw_;
		}
		break;
	case keyword_bianliangzhong_:
		if(to2>from2)
			buf2+=qu->src_.substr(from2,to2-from2);
		break;
	default:
		switch(kw){
		case keyword_has_:
			if((err=jieshi__(qu,from2,to2,buf2)))
				return err;
			break;
		default:
			err_<<syn_[keyword_bianliangshi_]<<syn_[keyword_bianliangzhong_];
			return errinfo_find_kw_;
		}
	}
	if(kw2>keyword_no_)
		offi+=syn_[kw2].length();
	return var__(buf2,buf,qu,kw,push_p,p);
}

int jieshiqi___::var__(string&buf2,string& buf,qu___* qu,int kw,bool* push_p,deque<string>* p){
	if(buf2==syn_[keyword_win_]){
		switch(kw){
		case keyword_has_:
			buf+=has_true_;
			break;
		default:
#ifdef ver_loongson_
			buf+="loongson";
#endif
#ifdef ver_dll_
			buf+="windows";
#endif
#ifdef ver_mac_mini_
			buf+="mac";
#endif
#ifdef ver_64_
			buf+="64";
#endif
			break;
		}
		return 0;
	}

	int num;
	switch(num=kw_num__(syn_[keyword_],-1,keywords_length_,buf2,&syn_[keyword_length_])){
	case kwnum_false_:
	case 0:
		break;
	case kwnum_no_:
		switch(kw){
		case keyword_has_:
			buf+=has_true_;
			break;
		default:
			buf+=syn_.path__();
			break;
		}
		return 0;
	case -1:
		switch(kw){
		case keyword_has_:
			buf+=has_true_;
			break;
		default:
			buf+=l2s__(keywords_length_);
			break;
		}
		return 0;
	default:
		switch(kw){
		case keyword_has_:
			buf+=has_true_;
			break;
		default:
			buf+=syn_[num-1];
			break;
		}
		return 0;
	}

	qu___* qu2=qu;
	list<string> rems;
	int err;
	if((err=rems__(buf2,&rems,&qu2,&qu2,&qu2))){
		if(err==errinfo_var_find_){
			if(kw==keyword_has_){
				buf+=has_false_;
				return 0;
			}
			err_<<buf2;
		}
		return err;
	}

	switch(num=kw_num__(syn_[keyword_callback_],kwnum_no_,callback_max_,buf2,NULL)){
	case kwnum_false_:
		break;
	default:
		switch(kw){
		case keyword_has_:
			buf+=has_true_;
			break;
		default:
			buf+=callbackx__(num,this,qu2);
			break;
		}
		return 0;
	}

	if(qu2->args_){
		switch(num=kw_num__(syn_[keyword_param_],-1,qu2->args_->params_.size(),buf2,&syn_[keyword_length_])){
		case kwnum_false_:
			break;
		case kwnum_no_:
			switch(kw){
			case keyword_has_:
				buf+=has_true_;
				break;
			default:
				for(deque<string>::iterator li=qu2->args_->params_.begin();li!=qu2->args_->params_.end();++li) {
					if(li!=qu2->args_->params_.begin())
						buf+=' ';
					string s=*li;
					bool yin=false;
					if(s.length()==0)
						yin=true;
					else{
						for(size_t i=0;i<s.length();i++){
							char c=s[i];
							if(!((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z')||c=='.'||c=='-')){
								yin=true;
								break;
							}
						}
					}
					if(yin)
						buf+='"';
					buf+=replace_all(s,"\"","\\\"");
					if(yin)
						buf+='"';
				}
				break;
			}
			return 0;
		case -1:
			switch(kw){
			case keyword_has_:
				buf+=has_true_;
				break;
			default:
				buf+=l2s__(qu2->args_->params_.size());
				break;
			}
			return 0;
		case 0:
			//同时也因为对于非文件得用解释而非加载
			switch(kw){
			case keyword_has_:
				buf+=has_true_;
				return 0;
			default:
				if(qu2->args_->src_is_file_){
					string s=qu2->args_->src_;
					file_.name__(s,s);
					for(;s.length()>1&&s[s.length()-1]=='-';)
						s=s.substr(0,s.length()-1);
					buf+=s;
				}else
					buf+=qu2->args_->src2_;
				return 0;
			}
			break;
		default:
			switch(kw){
			case keyword_has_:
				buf+=has_true_;
				break;
			default:
				buf+=qu2->args_->params_[num-1];
				break;
			}
			return 0;
		}

		switch(num=kw_num__(syn_[keyword_params_],1,qu2->args_->params_.size()+16,buf2,NULL)){
		case kwnum_false_:
			break;
		default:
			switch(kw){
			case keyword_has_:
				buf+=has_true_;
				return 0;
			default:
				if(push_p){
					size_t i=num==kwnum_no_?0:num-1;
					for(;i<qu2->args_->params_.size();i++){
						if(!buf.empty()){
							p->push_back(buf+qu2->args_->params_[i]);
							buf.clear();
							continue;
						}
						p->push_back(qu2->args_->params_[i]);
					}
					*push_p=true;
					return 0;
				}
				break;
			}
			break;
		}
	}

	for(;;){
		map<string,var___>::iterator mi=qu2->vars_.find(buf2);
		var___* var;
		if(mi==qu2->vars_.end()){
			var=NULL;
		}else{
			var=&mi->second;
			if(!var->has_huashen__(&rems))
				var=NULL;
		}
		if(!var){
			switch(kw){
			case keyword_has_:
				buf+=has_false_;
				return 0;
			}
			if(!qu2->shangji_){
				switch(kw){
				//keyword_has_放这里便不是仅设定区
				default:
					if(kw!=keyword_no_)
						err_<<buf2;
					return errinfo_var_find_;
				}
			}else{
				qu2=qu2->shangji_;
			}
		}else{
			if(var->type_==vartype_alias_){
				string buf3=var->val__(&rems);
				err=var__(buf3,buf,qu2,kw,push_p,p);
				if(err){
					if(kw==keyword_has_&&err==errinfo_var_find_){
						buf+=has_false_;
					}else{
						err_<<syn_[keyword_alias_]<<buf2;
						return err;
					}
				}
			}else{
				switch(kw){
				case keyword_has_:
					buf+=has_true_;
					break;
				default:
					buf+=var->val__(&rems);
					break;
				}
			}
			return 0;
		}
	}
}

int jieshiqi___::set_equ__(qu___* qu,size_t& offi,size_t to,int kw,string& buf,int kw0,deque<string>* eval_p){
	size_t from2,to2;
	int kw2;
	string buf2;
	int err;
	if((err=find__(qu,offi,to,kwsm_juhao_|kwsm_equ_,from2,to2,kw2,buf2)))
		return err;
	switch(kw2){
	case keyword_equ_:
		break;
	default:
		err_<<syn_[keyword_equ_];
		return errinfo_find_kw_;
	}
	list<string> rems;
	if((err=jieshi__(qu,from2,to2,buf2/*,NULL,NULL,keyword_no_,kwsm_1_,kwsm_1t_,&rems*/)))
		return err;

	qu___* qu2=qu;
	bool readonly=false;
	bool is_noparam=false;
	bool is_code=false;
	//原样还得保留回车等
	bool is_yuanyang=false;
	bool is_lib=false;
	if((err=rems__(buf2,&rems,&qu2,&qu2,&qu2,&readonly,&is_noparam,&is_code,&is_yuanyang,&is_lib))){
		err_add__(qu,from2,to2);
		return err;
	}
	int type;
	switch(kw){
	case keyword_define_:
		type=vartype_def_;
		break;
	case keyword_alias_:
		type=vartype_alias_;
		break;
	default:
		type=vartype_var_;
	}
	unsigned long maskt=kwsm_1t_;
	if(type==vartype_def_||is_code||is_yuanyang)
		maskt=0;

#ifdef debug_liucheng_
	out_kw__(syn_[kw2]);
#endif
	offi+=syn_[kw2].length();
	string buf3;
	err=find__(qu,offi,to,kwsm_juhao_,from2,to2,kw2,buf3,eval_p != NULL,NULL,NULL,keyword_no_,kwsm_1_,maskt,eval_p);
	if(err)
		return err;
	if(kw2>keyword_no_)
		offi+=syn_[kw2].length();

	if((err=jieshi__(qu,from2,to2,buf3,NULL,NULL,kw,kwsm_1_,maskt)))
		return err;

	if(rems.size() > 0) {
		qu___* qu3 = qu2;
		for(; qu3;) {
			map<string, var___>::iterator mi = qu3->vars_.find(buf2);
			if(mi != qu3->vars_.end()) {
				var___* var = &mi->second;
				if(var->has_huashen__(&rems)) {
					qu2 = qu3;
					break;
				}
			}
			qu3 = qu3->shangji_;
		}
	}

	if((err=var_new__(qu2,buf2,buf3,readonly,type,is_noparam,is_lib,&rems))){
		return err;
	}
	if(kw0!=keyword_no_)
		buf+=buf3;
	return 0;
}

int jieshiqi___::var_new__(qu___* qu2,const string& buf2,const string& buf3,
		bool readonly,
		int type,bool is_noparam,bool is_lib,
		list<string>* rems)
{
    if(!qu2)
   		qu2=&top_qu_;
	var___* var=&qu2->vars_[buf2];
	if(var->readonly_&&(!rems||rems->size()<1))
		return errinfo_var_readonly_;
	var->val__(buf3,rems);
	var->readonly_=readonly;
	var->type_=type;
	var->is_noparam_=is_noparam;
	var->is_lib_=is_lib;
	return 0;
}

int jieshiqi___::delete__(deque<string>* p,qu___* qu){
	for(deque<string>::iterator li=p->begin();li!=p->end();++li){
		string buf2=*li;
		int err=delete__(buf2,qu);
		if(err){
			err_<<buf2;
			return err;
		}
	}
	return 0;
}

int jieshiqi___::delete__(string& buf2,qu___* qu){
	qu___* qu2=qu;
	list<string> rems;
	int err;
	if((err=rems__(buf2,&rems,&qu2,&qu2,&qu2)))
		return err;
	map<string,var___>::iterator mi=qu2->vars_.find(buf2);
	if(mi==qu2->vars_.end())
		return errinfo_var_find_;
	if(mi->second.del__(&rems)){
		delete_lianzuo__(buf2,qu2);
		qu2->vars_.erase(mi);
	}
	return 0;
}

void jieshiqi___::lianzuo__(const string& name,qu___* qu){
	for(map<string,var___>::iterator mi=qu->vars_.begin();mi!=qu->vars_.end();mi++){
		var___* var=&mi->second;
		if(var->qianche__(name))
			lianzuo__(mi->first,qu);
	}
}

void jieshiqi___::delete_lianzuo__(const string& name,qu___* qu){
	lianzuo__(name,qu);
	for(map<string,var___>::iterator mi=qu->vars_.begin();mi!=qu->vars_.end();){
		var___* var=&mi->second;
		if(!var->qianche_rem_.empty()&&var->del__())
			qu->vars_.erase(mi++);
		else
			mi++;
	}
}

int jieshiqi___::use_def__(qu___* qu,size_t& offi,size_t to,string& buf,bool*use){
	deque<string> p;
	bool has=false,noparam,zheng;
	string src2;
	for(qu___* qu2=qu;;){
		for(map<string,var___>::iterator mi=qu2->vars_.begin();mi!=qu2->vars_.end();mi++){
			const string& name=mi->first;
			var___* var=&mi->second;
			switch(var->type_){
			case vartype_def_:
			case vartype_alias_:
				if(qu->src_.compare(offi,name.length(),name)==0){
					if(var->type_==vartype_alias_){
						const string& name2=var->val__();
						//为何不o_var__(this,qu2,name2.c_str())？因没返回var
						map<string,var___>::iterator mi2=qu2->vars_.find(name2);
						if(mi2==qu2->vars_.end())
							continue;
						var=&mi2->second;
						if(var->type_!=vartype_def_)
							continue;
					}
					has=true;
				}
			}
			if(has){
#ifdef debug_liucheng_
				cout<<"\033[0;3"<<out_clr_k_<<";4"<<out_clr_t_<<"m"<<name<<"\033[0m";
#endif
				noparam=var->is_noparam_;
				zheng=!var->is_lib_;
				offi+=mi->first.length();
				p.push_back(var->val__());
				src2=mi->first;
				break;
			}
		}
		if(has)
			break;
		if(qu2->shangji_)
			qu2=qu2->shangji_;
		else
			break;
	}
	if(!has)
		return 0;
	*use=true;
	return eval__(&p,src2.c_str(),!noparam,qu,offi,to,buf,false,zheng);
}
