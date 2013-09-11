/*
 * redireconsoi.cpp
 *
 *  Created on: 2010-8-14
 *      Author: zzzzzzzzzzz
 */

#include "redireconsoi___.h"
#include "for_arg_.h"
#include "call_util.cpp"

dlle___ int i__(char*cmd,int argc,...){
	std::string out;
	_for_args( argc )
		out+=s;
	_next_args
	redireconsoi___ roi;
	roi.out_=out.c_str();
	roi.out_len_=out.size();
	return roi.my_system(cmd, 2);
}

void o0__(
	bool chr,
	callback2___		cb,
	void*	jsq,
	void*	shangji,
	char*	script,
	callback2___		cb_r,
	char*	script_r,
	int argc,va_list argv)
{
	fflush(stdout);
	redireconsoi___ roi;
	roi.char_=chr;

	roi.cb2_=cb;
	roi.jsq_=jsq;
	roi.shangji_=shangji;
	roi.script_e_=roi.script_=script;
	roi.cb2_r_=cb_r;
	roi.script_r_=script_r;

	std::string cmd;
	for (int i = 0; i < argc; ++i){
		char*s = va_arg(argv, char*);
		if(i==argc-1)
			cmd+=s;
		else{
			switch(i){
			case 0:
				roi.script_e_=s;
				break;
			}
		}
	}

	if(!cmd.empty())
		roi.my_system(cmd.c_str(), 1);
}

dlle___ void o3__(
	bool chr,
	callback2___		cb,
	void*	jsq,
	void*	shangji,
	char*	script,
	char*	script_r,
	int argc,...)
{
	std::string buf;
	va_list argv;
	va_start(argv, argc);
	o0__(chr,cb,jsq,shangji,script,cb,script_r,argc,argv);
	va_end(argv);
}

const char* callback2__(void* jsq,void* shangji,int* err,
		const char* src,bool src_is_file,int argc,...)
{
	std::string* buf=(std::string*)src;
	_for_args( argc )
		*buf+=s;
	_next_args
	return 0;
}

dlle___ void o__(char**addr_ret,
		void*jsq,void*shangji,callback2___ cb_r,char*script_r,
		int argc,...)
{
	std::string buf;
	va_list argv;
	va_start(argv, argc);
	o0__(true, callback2__,jsq,shangji,(char*)&buf,cb_r,script_r, argc,argv);
	va_end(argv);
	*addr_ret=dup__(buf.c_str());
}
