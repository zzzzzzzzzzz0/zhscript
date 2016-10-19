/*
 * syn___.cpp
 *
 *  Created on: 2009-11-10
 *      Author: zzzzzzzzzzz
 */

#include "syn___.h"
#include "file___.h"
#include "util.h"
#include <sstream>
#include<algorithm>

/*
gtke4使用了“保留字”，kw修改可能需要对应修改，还有regexpr4
而gtkmmsh、zhscript_firefox_plugin可能就得重新编译了
jieshiqi_err_go_
*/

#define kwst_1to2_	1
#define kwst_len_	2
#define kwst_z_		3
#define kwst_ret_first_	0x100

int kws_1_[]={kwst_z_,
		keyword_bianliangshi_,
		keyword_no_};
int kws_4_[]={kwst_z_,
		//判断后的剩余，默认时不能成为文本
		keyword_jieheshi_,keyword_jiehezhong_,

		keyword_if_,keyword_then_,keyword_else_,keyword_switch_,
		keyword_for_,keyword_break_,keyword_continue_,
		keyword_loop_,keyword_break2_,keyword_continue2_,
		keyword_set_,keyword_delete_,keyword_define_,keyword_alias_,
		keyword_asc_,keyword_maohao_,
		keyword_no_};
int kws_8_[]={kwst_1to2_,keyword_echo_,keyword_exit_,};
int kws_400_[]={kwst_len_,2,keyword_bianliangshi_,keyword_asc_,};
int kws_2_[]={kwst_1to2_|kwst_ret_first_,keyword_juhao_,keyword_tanhao_,};
int kws_4000_[]={kwst_1to2_|kwst_ret_first_,keyword_douhao_,keyword_fenhao_,};
int kws_10_[]={kwst_z_|kwst_ret_first_,keyword_dunhao_,keyword_dunhao2_,keyword_no_};
int kws_40_[]={kwst_1to2_,keyword_then_,keyword_else_,};
int kws_800_[]={kwst_len_,1,keyword_else_,};
int kws_1000_[]={kwst_len_,1,keyword_then_,};
int kws_2000_[]={kwst_len_,1,keyword_if_,};
int kws_80_[]={kwst_1to2_,keyword_and_,keyword_or_,};
int kws_20_[]={kwst_1to2_,keyword_dengyu_,keyword_dayu_,};
int kws_8000_[]={kwst_z_,keyword_has_,keyword_no_};
int kws_100_[]={kwst_len_,1,keyword_equ_,};
int kws_200_[]={kwst_len_,2,keyword_bianliangshi_,keyword_bianliangzhong_,};
int kws_10000_[]={kwst_len_,1,keyword_jieheshi_,};
int *kws_a_[]={
		kws_1_,kws_2_,kws_4_,kws_8_,
		kws_10_,kws_20_,kws_40_,kws_80_,
		kws_100_,kws_200_,kws_400_,kws_800_,
		kws_1000_,kws_2000_,kws_4000_,kws_8000_,
		kws_10000_,
		};

int kws_kuohao_[]={kwst_len_,2,keyword_kaikuohao_,keyword_bikuohao_,};
int kws_yinhao_[]={kwst_len_,2,keyword_kaiyinhao_,keyword_biyinhao_,};
int kws_yuanyang_[]={kwst_len_,2,keyword_yuanyangshi_,keyword_yuanyangzhong_,};
int kws_code_[]={kwst_len_,2,keyword_codeshi_,keyword_codezhong_,};
int kws_zhujie_[]={kwst_z_,keyword_zhujieshi_,keyword_zhujiezhong_,keyword_no_};
int kws_jiehe_[]={kwst_len_,2,keyword_jieheshi_,keyword_jiehezhong_,};

syn___::syn___() {
	has_=false;
}

syn___::~syn___() {
}

int syn___::get_file__(const string& path){
	string buf;
	int err=file_.get__(path,path_, false,buf);
	if(err){
		err_<<file_.err_;
		return err;
	}
	istringstream is(buf);
	int i=0;
	for(;;i++){
		if(i<keywords_length_)
			is>>keywords_[i];
		else{
			string s;
			is>>s;
		}
		if(is.eof())
			break;
	}
	if(i!=keywords_length_){
		err_<<l2s__(i)<<"/"<<l2s__(keywords_length_);
		return errinfo_num_;
	}
	has_=true;
	return 0;
}

int syn___::find_kw__(const string& text,size_t offi,int kws[]){
	int ret=keyword_no_;
	switch(kws[0]&0xf){
	case kwst_1to2_:
		for(int i=kws[1];i<=kws[2];i++){
			if(text.compare(offi,keywords_[i].length(),keywords_[i])==0){
				ret= kws[0] & kwst_ret_first_ ? kws[1] : i;
				break;
			}
		}
		break;
	case kwst_z_:
		for(size_t i=1;;i++){
			int i1=kws[i];
			if(i1==keyword_no_)
				break;
			if(text.compare(offi,keywords_[i1].length(),keywords_[i1])==0){
				ret= kws[0] & kwst_ret_first_ ? kws[1] : i1;
				break;
			}
		}
		break;
	case kwst_len_:
		for(int i=0;i<kws[1];i++){
			int i1=kws[i+2];
			if(text.compare(offi,keywords_[i1].length(),keywords_[i1])==0){
				ret= kws[0] & kwst_ret_first_ ? kws[2] : i1;
				break;
			}
		}
		break;
	}
	return ret;
}

int syn___::jiehe__(const string& text,size_t offi,size_t to){
	if(offi<to){
		int kw=find_kw__(text,offi,kws_jiehe_);
		if(kw>keyword_no_&&offi+keywords_[kw].length()<=to)
			return kw;
	}
	return keyword_no_;
}

int syn___::jiehe__(const string& text,size_t& offi,size_t to,size_t&from2,size_t&to2,bool*jiehe2,err___&err1){
	int kw=jiehe__(text,offi,to);
	if(kw==keyword_jieheshi_){
		int err;
		if((err=jiehe2__(kw,text,offi,to,from2,to2,err1)))
			return err;
		*jiehe2=true;
	}
	return 0;
}

int syn___::jiehe2__(int kw,const string& text,size_t& offi,size_t to,size_t&from2,size_t&to2,err___&err1){
	int jiehe=1;
	int i;
	bool first=true;
	to2=offi;
	int text_cnt=0,yuanyang_cnt=0,code_cnt=0;
	for(;;){
		i= kw>keyword_no_ ? keywords_[kw].length() : step__(text,to2);
		if(to2+i>=to){
			err1<<keywords_[keyword_jieheshi_];
			err1<<keywords_[keyword_jiehezhong_];
			return errinfo_find_kw_;
		}
		to2+=i;
		if(first){
			first=false;
			from2=to2;
			//cout<<"["<<from2<<"}";
		}
		kw=kuoyin__(text,to2,text_cnt,yuanyang_cnt,code_cnt);
		if(kw!=keyword_no_)
			continue;
		kw=find_kw__(text,to2,kws_jiehe_);
		if(kw==keyword_jieheshi_)
			jiehe++;
		else if(kw==keyword_jiehezhong_)
			jiehe--;
		if(jiehe==0){
			offi=to2+keywords_[kw].length();
			//cout<<"{"<<to2<<"]";
			break;
		}
		/*else if(jiehe<0){
			return errinfo_find_kw_;
		}*/
	}
	return 0;
}

bool syn___::kuoyinhao__(int kw){
	switch(kw){
	case keyword_kaikuohao_:
	case keyword_bikuohao_:
	case keyword_kaiyinhao_:
	case keyword_biyinhao_:
	case keyword_yuanyangshi_:
	case keyword_yuanyangzhong_:
	case keyword_codeshi_:
	case keyword_codezhong_:
		return true;
	}
	return false;
}

int syn___::kuoyin__(const string& text,size_t& offi,int&text_cnt,int&yuanyang_cnt,int&code_cnt,list<string>* rems,int* text_zhujie,bool tzj_res){
	int kw;

	//代码中的注释也去掉，但括号又在引号内……
	if((text_cnt==0/*||(text_zhujie&&*text_zhujie==tzj_code_)*/)&&code_cnt==0&&yuanyang_cnt==0){
		for(int rem_cnt=0;;){
			kw=find_kw__(text,offi,kws_kuohao_);
			for(;;){
				if(kw==keyword_kaikuohao_){
					rem_cnt++;
					offi+=keywords_[kw].length();
					break;
				}
				if(kw==keyword_bikuohao_){
					rem_cnt--;
					offi+=keywords_[kw].length();
					if(rem_cnt==0){
						kw=find_kw__(text,offi,kws_kuohao_);
						if(kw>keyword_no_)
							continue;
					}
					break;
				}
				break;
			}
			if(rem_cnt==0)
				break;
			if(kw==keyword_no_)
				offi+=step__(text,offi);
			if(offi>=text.length())
				return keyword_is_out_;
		}
	}

	if(text_cnt==0&&yuanyang_cnt==0&&code_cnt==0){
		if((rems||text_zhujie)&&(kw=find_kw__(text,offi,kws_zhujie_))==keyword_zhujieshi_){
			list<string> rems1;
			list<string>* rems2;
			if(rems)
				rems2=rems;
			else
				rems2=&rems1;
			size_t offi2=offi;
			string rem;
			for(int rem_cnt=0;;){
				for(;;){
					if(kw==keyword_zhujieshi_){
						rem_cnt++;
						offi+=keywords_[kw].length();
						break;
					}
					if(kw==keyword_zhujiezhong_){
						rem_cnt--;
						offi+=keywords_[kw].length();
						rems2->push_back(rem);
						rem.clear();
						if(rem_cnt==0){
							kw=find_kw__(text,offi,kws_zhujie_);
							if(kw>keyword_no_)
								continue;
							if(!rems){
								kw=find_kw__(text,offi,kws_yinhao_);
								bool res=true;
								if(kw==keyword_kaiyinhao_){
									if(rem_kw__(rems2,keyword_yuanyang_)>0){
										*text_zhujie=tzj_yuanyang_;
										res=tzj_res;
									}else if(rem_kw__(rems2,keyword_code_)>0){
										*text_zhujie=tzj_code_;
										res=tzj_res;
									}
								}
								if(res)
									offi=offi2;
							}
						}
						break;
					}
					break;
				}
				if(rem_cnt==0)
					break;
				if(kw==keyword_no_){
					int len=step__(text,offi);
					rem+=text.substr(offi,len);
					offi+=len;
				}
				if(offi>=text.length())
					return keyword_is_out_;
				kw=find_kw__(text,offi,kws_zhujie_);
			}
		}
	}

	if(yuanyang_cnt==0&&code_cnt==0){
		kw=find_kw__(text,offi,kws_yinhao_);
		switch(kw){
		case keyword_kaiyinhao_:
			if(++text_cnt==1){
				return kw;
			}
			break;
		case keyword_biyinhao_:
			if(--text_cnt==0){
				if(text_zhujie)
					*text_zhujie=tzj_text_;
				return kw;
			}
			break;
		}
		if(text_cnt>0)
			return keyword_is_text_;
	}

	//代码内嵌原样
	if(text_cnt==0/*&&code_cnt==0*/){
		kw=find_kw__(text,offi,kws_yuanyang_);
		switch(kw){
		case keyword_yuanyangshi_:
			if(++yuanyang_cnt==1)
				return kw;
			break;
		case keyword_yuanyangzhong_:
			if(--yuanyang_cnt==0)
				return kw;
			break;
		}
		if(yuanyang_cnt>0)
			return keyword_is_yuanyang_;
	}

	if(text_cnt==0&&yuanyang_cnt==0){
		kw=find_kw__(text,offi,kws_code_);
		switch(kw){
		case keyword_codeshi_:
			if(++code_cnt==1)
				return kw;
			break;
		case keyword_codezhong_:
			if(--code_cnt==0)
				return kw;
			break;
		}
		if(code_cnt>0)
			return keyword_is_code_;
	}

	return keyword_no_;
}

int syn___::find__(const string& text,size_t& offi,unsigned long mask){
	for(;;){
		int* kws=0;
		for(size_t i=0;i<sizeof(kws_a_)/sizeof(int*);i++){
			unsigned long i1=1<<i;
			if(mask&i1){
				kws=kws_a_[i];
				mask-=i1;
				break;
			}
		}
		if(!kws)
			return keyword_no_;
		int kw=find_kw__(text,offi,kws);
		if(kw!=keyword_no_)
			return kw;
	}
}

int syn___::find__(const string& text,size_t& offi,int& text_cnt,int&yuanyang_cnt,int&code_cnt,unsigned long mask,unsigned long mask_text,list<string>* rems,int* text_zhujie){
	int kw=kuoyin__(text,offi,text_cnt,yuanyang_cnt,code_cnt,rems,text_zhujie);
	if(kw==keyword_no_)
		kw=find__(text,offi,mask);
	else if(kw==keyword_is_text_){
		int kw2=find__(text,offi,mask_text);
		if(kw2!=keyword_no_)
			kw=kw2;
	}
	return kw;
}

int syn___::yasuo__(string& src){
	string buf;
	int text_cnt=0,yuanyang_cnt=0,code_cnt=0;
	int text_zhujie=tzj_text_;
	size_t to=src.length();
	for(size_t offi=0;offi<to;){
		int kw=kuoyin__(src,offi,text_cnt,yuanyang_cnt,code_cnt,NULL,&text_zhujie,true);
		if(kw>keyword_no_){
			offi+=keywords_[kw].length();
			buf+=keywords_[kw];
			continue;
		}
		if(offi>=to)
			break;
		int len=step__(src,offi);
		if(is_text__(src[offi],len,kw,text_zhujie))
			buf+=src.substr(offi,len);
		offi+=len;
	}
	src=buf;
	return 0;
}

int syn___::rem_kw__(list<string>* rems,int kw){
	list<string>::iterator li2;
	int i=0;
	for(;;){
		li2=find(rems->begin(),rems->end(),keywords_[kw]);
		if(li2==rems->end()){
			break;
		}
		rems->erase(li2);
		i++;
	}
	return i;
}

bool syn___::is_text__(char c,int len,int kw,int text_zhujie){
	if(kw==keyword_is_yuanyang_||(kw==keyword_is_text_&&text_zhujie==tzj_yuanyang_))
		return true;
	bool b=true;
	if(len==1&&c>=0&&c<=' '){
		switch(kw){
		case keyword_is_text_:
		case keyword_is_code_:
			if(c==' ');
			else
				b=false;
			break;
		default:
			b=false;
			break;
		}
	}
	return b;
}

int syn___::step__(const string& text,size_t offi){
	int i=1;
	for(;;++i){
		size_t i1=offi+i;
		if(i1>=text.length())
			break;
		unsigned char c=text[i1];
		if(!c)
			break;
		c&=0xc0;
		if(c!=0x80)
			break;
	}
	return i;
}
