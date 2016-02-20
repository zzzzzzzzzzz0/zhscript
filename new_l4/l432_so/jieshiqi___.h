/*
 * jieshiqi___.h
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#ifndef JIESHIQI____H_
#define JIESHIQI____H_
#include <string>
#include <list>
#include <iostream>
using namespace std;

#include "args___.h"
#include "syn___.h"
#include "qu___.h"
#include "err___.h"
#include "errinfo___.h"
#include "zhi___.h"

class jieshiqi___ {
private:
	int jieshi__(qu___* qu,size_t from,size_t to,string& buf,
			bool* push_p=NULL,deque<string>* p=NULL,
			int kw0=keyword_no_,
			unsigned long mask=kwsm_1_,unsigned long maskt=kwsm_1t_,
			list<string>* rems=NULL,
			deque<string>* eval_p=NULL);
	int find__(qu___* qu,size_t& offi,size_t to,
			unsigned long mask2,size_t& from2,size_t& to2,
			int& kw2,string& buf,bool jieshi=true,
			bool* push_p=NULL,deque<string>* p=NULL,
			int kw0=keyword_no_,
			unsigned long mask=kwsm_1_,unsigned long maskt=kwsm_1t_,
			deque<string>* eval_p=NULL);
	int jieshi_buf__(qu___* qu,size_t offi,size_t to,string& buf,string& buf2,
			unsigned long mask2=kwsm_juhao_,int kw0=keyword_no_,bool is_code=false,
			size_t* from2_ret=NULL,size_t* to2_ret=NULL,size_t* to4_ret=NULL);
	void err_add__(qu___* qu,size_t from,size_t to,bool qiangzhi=false,
			int kw=keyword_no_);

	int x__(int kw,qu___* qu,size_t& offi,size_t to,string& buf,int kw0);
	int echo__(deque<string>* p,string& buf,int kw0);
	int exec__(deque<string>* p,string& buf);
	int call__(deque<string>* p,string& buf,qu___* qu);

	int load__(deque<string>* p,const char*src2,string& buf,int kw,qu___* shangji,bool zheng);
	int eval__(deque<string>* p,const char*src2,bool param,qu___* qu,size_t& offi,size_t to,
			string& buf,bool chuan,bool zheng);
	int with__(qu___* qu,size_t& offi,size_t to,string& buf);

	int if_then_else__(int kw,qu___* qu,size_t& offi,size_t to,string& buf,
			zhi___& zuo,bool& result,deque<string>* eval_p);
	int and_or__(qu___* qu,size_t from,size_t to,bool& result,zhi___& zuo);
	int switch__(qu___* qu,size_t& offi,size_t to,string& buf,deque<string>* eval_p);
	int asc__(qu___* qu,size_t& offi,size_t to,string& buf);
	int for__(qu___* qu,size_t& offi,size_t to,string& buf,deque<string>* eval_p);
	int loop__(qu___* qu,size_t& offi,size_t to,string& buf,deque<string>* eval_p);
	int break2__(qu___* qu,size_t& offi,size_t to);
	int continue2__(qu___* qu,size_t& offi,size_t to);
	int end__(qu___* qu,size_t& offi,size_t to);

	int set_equ__(qu___* qu,size_t& offi,size_t to,int kw,string& buf,int kw0,deque<string>* eval_p);
	int var__(qu___* qu,size_t& offi,size_t to,string& buf,int kw,bool* push_p,deque<string>* p);
	int delete__(deque<string>* p,qu___* qu);
	void delete_lianzuo__(const string& name,qu___* qu);
	void lianzuo__(const string& name,qu___* qu);
	int use_def__(qu___* qu,size_t& offi,size_t to,string& buf,bool*use);

	int rems__(list<string>* rems,qu___** top,qu___** main1,qu___** shangji, bool* is_code,bool* is_yuanyang,var___* ret2);

	qu___ top_qu_;
public:
	jieshiqi___();
	virtual ~jieshiqi___();
	int jieshi__(qu___* shangji,string& buf);
	int jieshi2__(args___* args,qu___* shangji,string& buf);
	qu___* new_main_qu__();
	qu___* main_qu__(qu___* qu);
	int kw_qu__(qu___* qu);

	int var_new__(qu___* qu,const string& buf2,const string& buf3,var___* set2,list<string>* rems);
	int var__(string&buf2,string& buf,qu___* qu,int kw,bool* push_p,deque<string>* p);
	int delete__(string& buf2,qu___* qu);

	int rems__(string& buf2,list<string>* rems,
			qu___** top,qu___** main1,qu___** shangji,
			bool* is_code=NULL,bool* is_yuanyang=NULL,var___* ret2=NULL);

	syn___ syn_;
	err___ err_;
	errinfo___ errinfo_;
	args___ args_;
	int exit_code_;
};

#endif /* JIESHIQI____H_ */
