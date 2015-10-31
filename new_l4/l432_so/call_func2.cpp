/*
 * call_util.cpp
 *
 *  Created on: 2010-8-22
 *      Author: zzzzzzzzzzz
 */
#include "call_func2.h"
#include "call_func.h"
#include "jieshiqi_call.h"
#include "jieshiqi_callback.h"
#include "errinfo.h"
#include "util.h"
#include<iostream>
#include"defi.h"

unsigned long call_type__(const string& s,err___* err,size_t* i1,int step,
		int* ret2,string* ret3,unsigned long* ret4){
	unsigned long type=calltype_void_;
	if(s.length()<1)
		return calltype_err_type_;
	size_t i;
	if(!i1){
		switch(s[0]){
		case'L':
			return calltype_loadlibrary_;
		case'F':
			return calltype_freelibrary_;
		case'G':
			i=1;
			type|=calltype_getprocaddr_;
			type|=calltype_cdecl_;
			break;
		default:
			i=0;
			break;
		}
	}else
		i=*i1;
	for(;;){
		if(i>=s.length())
			break;
		char c=s[i];
		if(c==funcfmt_func_fengefu_)
			break;
		switch(c){
		case'c':
			type|=calltype_char_;
			break;
		case'i':
			type|=calltype_int_;
			break;
		case'v':
			break;
		case'u':
			type|=calltype_unsigned_;
			break;
		case'l':
			type|=calltype_long_;
			break;
		case'*':
			type|=calltype_zhizhen_;
			break;
		case'&':
			type|=calltype_addr_;
			break;
		case'.':
			break;
		//所谓pascal调用约定
		case'p':
			type&=~calltype_cdecl_;
			break;
		case'Z':
			type|=calltype_args_;
			break;
		case'B':
			type|=calltype_buf_;
			break;
		case'S':
			type|=calltype_buf_siz_;
			break;
		case'E':
			type|=calltype_ret_err_;
			break;
		case'A':
			type|=calltype_ret_addr_;
			break;
		case'@':
			type|=calltype_memory_;
			break;
		case'$':
			type|=calltype_var_;
			if(ret2)
				*ret2=kwnum_no_;
			{
				size_t i2=i+1;
				if(i2<s.length()){
					if(s[i2]>='0'&&s[i2]<='9'){
						int ret2_x=s[i2]-'0';
						size_t i2_x=i2;
						for(;;){
							if(++i2_x>=s.length())
								break;
							if(!(s[i2_x]>='0'&&s[i2_x]<='9'))
								break;
							i2=i2_x;
							ret2_x*=10;
							ret2_x+=s[i2]-'0';
						}
						if(ret2_x>=0&&ret2_x<=callback_max_){
							i=i2;
							if(ret2)
								*ret2=ret2_x;
						}
					}
					else if(s[i2]=='{'){
						int i_save=i;
						if(ret2)
							*ret2=kwnum_false_;
						if((i+=2)>=s.length()){
							*err<<&s[i_save];
							return calltype_err_type_;
						}
						if(ret4){
							switch(s[i]){
							case'l':
								*ret4=calltype_long_;
								break;
							case'u':
								*ret4=calltype_unsigned_|calltype_long_;
								break;
							case'*':
								*ret4=calltype_char_|calltype_zhizhen_;
								break;
							default:
								*err<<&s[i_save];
								return calltype_err_type_;
							}
							(*ret3).clear();
						}
						for(;;){
							if(++i>=s.length()){
								*err<<&s[i_save];
								return calltype_err_type_;
							}
							c=s[i];
							if(c=='}')
								break;
							if(ret3)
								*ret3+=c;
						}
					}
				}
			}
			break;
		case' ':
		case funcfmt_param_fengefu_:
			if(i1){
				*i1=i+step;
				return type;
			}
			break;
		default:
			*err<<s;
			return type|=calltype_err_type_;
		}
		i+=step;
	}
	if(i1)
		*i1=string::npos;
	return type;
}

bool zhizhen__(unsigned long int ax_qi4,string& buf0,err___* err0,const string& null){
	if(!ax_qi4)
		buf0+=null;
	else{
		if(ax_qi4>0&&ax_qi4<=65535){
			*err0<<ax_qi4;
			return false;
		}else
			buf0+=(char*)ax_qi4;
	}
	return true;
}

int err_free__(int err,call_data_type___ *ul,char* c){
	if(ul)
		delete ul;
	if(c)
		delete c;
	return err;
}

unsigned long int call_func2__(void*func,bool ret,int argc,call_data_type___ *argv);
int call_func__(deque<string>* p,string& buf0,err___* err0,const string& null,
		jieshiqi___* jsq,qu___* qu,call_ex___* ce){
	string func_fmt=(*p)[0];
	size_t i=func_fmt.find(funcfmt_func_fengefu_);
	if(i==string::npos){
		*err0<<func_fmt;
		return errinfo_func_fmt_;
	}
	unsigned long ret_type=call_type__(func_fmt,err0);
	if(ret_type & calltype_err_type_)
		return errinfo_func_type_;
	size_t i1=func_fmt.find(funcfmt_func_fengefu_,++i);
	if(i1==string::npos){
		*err0<<func_fmt;
		return errinfo_func_fmt_;
	}
	string s=func_fmt.substr(i,i1-i);
	void*func=(void*)x2l__(s);
	unsigned long ret_typex=ret_type & 0xf0000fffL;

	//calltype_memory_
	if(func_fmt.substr(i1+1)=="@"){
		switch(ret_typex){
		case calltype_char_:
		case calltype_unsigned_|calltype_char_:
			{
				char*c=(char*)func;
				buf0+=*c;
			}
			break;
		case calltype_int_:
			{
				int*i=(int*)func;
				buf0+=l2s__(*i);
			}
			break;
		case calltype_long_:
		case calltype_long_|calltype_int_:
			{
				long*l=(long*)func;
				buf0+=l2s__(*l);
			}
			break;
		case calltype_unsigned_:
		case calltype_unsigned_|calltype_int_:
			{
				unsigned int*ui=(unsigned int*)func;
				buf0+=lu2s__(*ui);
			}
			break;
		case calltype_unsigned_|calltype_long_:
		case calltype_unsigned_|calltype_long_|calltype_int_:
			{
				unsigned long int*lu=(unsigned long int*)func;
				buf0+=lu2s__(*lu);
			}
			break;
		case calltype_char_|calltype_zhizhen_:
		case calltype_unsigned_|calltype_char_|calltype_zhizhen_:
			{
				char**s=(char**)func;
				if(!func||!*s)
					buf0+=null;
				else
					buf0+=*s;
			}
			break;
		default:
			*err0<<func_fmt;
			return errinfo_func_type_allow_;
		}
		return 0;
	}else{
		if(ret_type & calltype_args_){
			int i2,i2b=0;
			if(i1==func_fmt.size()-1)
				i2=0;
			else{
				i2=1;
				for(size_t i=i1+1;i<func_fmt.size();i++){
					char c=func_fmt[i];
					switch(c){
					case funcfmt_param_fengefu_:
						i2++;
						break;
					case '$':
					{
						size_t i4=i+1;
						if(i4<func_fmt.size()&&func_fmt[i4]=='{'){
							for(++i;++i<func_fmt.size();)
								if(func_fmt[i]=='}')
									break;
						}
					}
					case'B':
					case'S':
					case'E':
					case'A':
					//case'Z':
						i2--;
						i2b++;
						break;
					}
				}
			}
			int i3=p->size()-1-i2;
			if(i3<0)
				return errinfo_param_num_;
			if(i2>0||i2b>0)
				func_fmt+=funcfmt_param_fengefu_;
			func_fmt+="i";
			for(int i=0;i<i3;i++){
				func_fmt+=funcfmt_param_fengefu_;
				func_fmt+="c*";
			}
			p->insert(p->begin()+1+i2,l2s__(i3));
		}
		call_data_type___ *argv=new call_data_type___[p->size()+16];//S、E、A也占名额
		int argc=0;

		int err_ret=0;
		#define bufsiz 1024
		char* buf=0;
		if(ret_type & (calltype_buf_siz_|calltype_buf_)){
			buf=new char[bufsiz];
			buf[0]=0;
		}
		char* addr_ret=0;

		if(!(ret_type & calltype_niyazhan_)){
			if(ret_type & calltype_ret_err_)
				argv[argc++]=(call_data_type___)&err_ret;
			if(ret_type & calltype_ret_addr_)
				argv[argc++]=(call_data_type___)&addr_ret;
			if(ret_type & (calltype_buf_siz_|calltype_buf_))
				argv[argc++]=(call_data_type___)buf;
			if(ret_type & calltype_buf_siz_)
				argv[argc++]=(call_data_type___)bufsiz;
		}
		if(!(i1==func_fmt.length()-1&&p->size()==1)){
			int step;
			size_t i2;
			if(ret_type & calltype_niyazhan_){
				i1=func_fmt.length()-1;
				i2=p->size()-1;
				step=-1;
			}else{
				++i1;
				i2=1;
				step=1;
			}
			int ret2;
			string ret3;
			unsigned long ret4;
			for(;;){
				unsigned long type=call_type__(func_fmt,err0,&i1,step,&ret2,&ret3,&ret4);
				if(type & calltype_err_type_)
					return err_free__(errinfo_func_type_,argv,buf);
				switch(type){
				case calltype_buf_:
				case calltype_buf_siz_:
					buf=new char[bufsiz];
					buf[0]=0;
					argv[argc++]=(call_data_type___)buf;
					if(type==calltype_buf_siz_)
						argv[argc++]=(call_data_type___)bufsiz;
					break;
				case calltype_ret_addr_:
					argv[argc++]=(call_data_type___)&addr_ret;
					break;
				case calltype_ret_err_:
					argv[argc++]=(call_data_type___)&err_ret;
					break;
				case calltype_var_:
				{
					switch(ret2){
					case kwnum_false_:
						switch(ret4){
						case calltype_long_:
							argv[argc++]=(call_data_type___)s2l__(ret3);
							break;
						case calltype_unsigned_|calltype_long_:
							argv[argc++]=(call_data_type___)s2lu__(ret3);
							break;
						case calltype_char_|calltype_zhizhen_:
							string& cbuf=cb_buf__();
							cbuf=ret3;
							argv[argc++]=(call_data_type___)cbuf.c_str();
							break;
						}
						break;
					case 11:
						argv[argc++]=(call_data_type___)ce;
						break;
					default:
						string& cbuf=cb_buf__();
						cbuf=callbackx__(ret2,jsq,qu);
						argv[argc++]=(call_data_type___)x2l__(cbuf);
						break;
					}
					break;
				}
				default:
					{
						if(i2<1||i2>=p->size())
							return err_free__(errinfo_param_num_,argv,buf);
						string arg=(*p)[i2];
						switch(type){
						case calltype_char_:
						case calltype_unsigned_|calltype_char_:
							{
								unsigned char c=arg[0];
								argv[argc++]=(call_data_type___)c;
							}
							break;
						case calltype_int_:
						case calltype_long_:
						case calltype_long_|calltype_int_:
						case calltype_unsigned_:
						case calltype_unsigned_|calltype_int_:
						case calltype_unsigned_|calltype_long_:
						case calltype_unsigned_|calltype_long_|calltype_int_:
							{
								long i=type&calltype_unsigned_?s2lu__(arg):s2l__(arg);
								//转换错误的判断
								argv[argc++]=(call_data_type___)i;
							}
							break;
						case calltype_char_|calltype_zhizhen_:
						case calltype_unsigned_|calltype_char_|calltype_zhizhen_:
							{
								const char* s=arg==null?NULL:(*p)[i2].c_str();
								argv[argc++]=(call_data_type___)s;
							}
							break;
						case calltype_char_|calltype_addr_:
						case calltype_unsigned_|calltype_char_|calltype_addr_:
						case calltype_addr_:
							{
								char* s=arg==null?NULL:(char*)x2l__(arg);
								//转换错误的判断
								argv[argc++]=(call_data_type___)s;
							}
							break;
						case calltype_void_:
							break;
						default:
							*err0<<func_fmt;
							return err_free__(errinfo_func_type_allow_,argv,buf);
						}
						if(i1==string::npos)
							break;
						i2+=step;
						continue;
					}
				}
				if(i1==string::npos){
					if((i2>1&&step<0)||(i2<p->size()-1&&step>0))
						return err_free__(errinfo_param_over_,argv,buf);
					break;
				}
			}
		}
		if(ret_type & calltype_niyazhan_){
			if(ret_type & calltype_buf_siz_)
				argv[argc++]=(call_data_type___)bufsiz;
			if(ret_type & (calltype_buf_siz_|calltype_buf_))
				argv[argc++]=(call_data_type___)buf;
			if(ret_type & calltype_ret_addr_)
				argv[argc++]=(call_data_type___)&addr_ret;
			if(ret_type & calltype_ret_err_)
				argv[argc++]=(call_data_type___)&err_ret;
		}
		if(
#if defined( ver_loongson_ ) || defined( ver_64_ )
				argc>128
#elif ver_no_asm_16_
				argc>16
#elif ver_no_asm_32_
				argc>32
#elif ver_mac_mini_
				argc>69
#else
					false
#endif
					)
			return err_free__(errinfo_param_over_,argv,buf);
		unsigned long int ax_qi4=call_func2__(func,ret_typex!=calltype_void_,argc,argv);

		if(err_ret){
			if(buf)
				*err0<<buf;
			if(err_ret<jieshiqi_err_){
				*err0<<"["<<l2s__(err_ret)<<"]";
				err_ret=errinfo_func_err_ret_;
			}else{
				err_ret-=jieshiqi_err_;
			}
			return err_free__(err_ret,argv,buf);
		}

		switch(ret_typex){
		case calltype_char_:
		case calltype_unsigned_|calltype_char_:
			buf0+=(char)ax_qi4;
			break;
		case calltype_int_:
			ax_qi4=(int)ax_qi4;
		case calltype_long_:
		case calltype_long_|calltype_int_:
			buf0+=l2s__(ax_qi4);
			break;
		case calltype_unsigned_:
		case calltype_unsigned_|calltype_int_:
			ax_qi4=(unsigned int)ax_qi4;
		case calltype_unsigned_|calltype_long_:
		case calltype_unsigned_|calltype_long_|calltype_int_:
			buf0+=lu2s__(ax_qi4);
			break;
		case calltype_char_|calltype_zhizhen_:
		case calltype_unsigned_|calltype_char_|calltype_zhizhen_:
			if(!zhizhen__(ax_qi4,buf0,err0,null))
				return err_free__(errinfo_bad_val_,argv,buf);
			break;
		case calltype_char_|calltype_addr_:
		case calltype_unsigned_|calltype_char_|calltype_addr_:
		case calltype_addr_:
			if(!ax_qi4)
				buf0+=null;
			else
				buf0+=l2x__(ax_qi4);
			break;
		case calltype_void_:
			break;
		default:
			*err0<<func_fmt;
#ifdef ver_mac_mini_
			cout<<"("<<hex<<ret_typex<<" "<<ret_type<<")";
#endif
			return err_free__(errinfo_func_type_allow_,argv,buf);
		}
		//ret_type & calltype_ret_addr_不能多途径返回
		if(addr_ret){
			if(!zhizhen__((unsigned long)addr_ret,buf0,err0,null)){
				delete addr_ret;
				return err_free__(errinfo_bad_val_,argv,buf);
			}
			delete addr_ret;
		}
		if(buf)
			buf0+=buf;
		return err_free__(0,argv,buf);
	}
}
