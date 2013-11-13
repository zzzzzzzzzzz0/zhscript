/*
 * syn___.h
 *
 *  Created on: 2009-11-10
 *      Author: zzzzzzzzzzz
 */

#ifndef SYN____H_
#define SYN____H_
#include <string>
#include <iostream>
#include <list>
using namespace std;

#include"err___.h"
#include"errinfo.h"

#include"keyword.h"

#define kwsm_1ban_ 1
#define kwsm_1ban2_ 4
#define kwsm_1ban3_ 8
#define kwsm_1ban_text_ 0x400
#define kwsm_juhao_ 2
#define kwsm_dunhao_ 0x10
#define kwsm_then_else_ 0x40
#define kwsm_else_ 0x800
#define kwsm_then_ 0x1000
#define kwsm_douhao_ 0x4000
#define kwsm_if_ 0x2000
#define kwsm_and_or_ 0x80
#define kwsm_bijiaoyunsuanfu_ 0x20
#define kwsm_has_ 0x8000
#define kwsm_equ_ 0x100
#define kwsm_var_ 0x200
#define kwsm_jieheshi_ 0x10000

#define kwsm_1_ kwsm_1ban_|kwsm_1ban2_|kwsm_1ban3_|kwsm_juhao_
#define kwsm_1t_ kwsm_1ban_text_

#define has_true_	"1"
#define has_false_	"0"

#define tzj_text_		0
#define tzj_yuanyang_	1
#define tzj_code_		2

class syn___ {
private:
	string keywords_[keywords_length_];
	bool has_;
	string path_;
	int find_kw__(const string& text,size_t offi,int kws[]);
	int find__(const string& text,size_t& offi,unsigned long mask);
public:
	syn___();
	virtual ~syn___();
	int get_file__(const string& path);
	const string& operator[](int i){return keywords_[i];}
	bool has__(){return has_;}
	const string& path__(){return path_;}
	int find__(const string& text,size_t& offi,int& text_cnt,int&yuanyang_cnt,int&code_cnt,
			unsigned long mask,unsigned long mask_text,list<string>* rems=NULL,int* text_zhujie=NULL);

	bool kuoyinhao__(int kw);
	int kuoyin__(const string& text,size_t& offi,int& text_cnt,int&yuanyang_cnt,int&code_cnt,
			list<string>* rems=NULL,int* text_zhujie=NULL,bool tzj_res=false);

	int jiehe__(const string& text,size_t offi,size_t to);
	int jiehe__(const string& text,size_t& offi,size_t to,size_t& from2,size_t& to2,bool*jiehe2,err___&err1);
	int jiehe2__(int kw,const string& text,size_t& offi,size_t to,size_t&from2,size_t&to2,err___&err1);

	int yasuo__(string& src);

	int step__(const string& text,size_t offi);
	bool is_text__(char c,int len,int kw,int text_zhujie);

	int rem_kw__(list<string>* rems,int kw);

	err___ err_;
};

#endif /* SYN____H_ */
