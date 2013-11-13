/*
 * call_func.cpp
 *
 *  Created on: 2010-4-14
 *      Author: zzzzzzzzzzz
 *
 *      独立出来是因为这个函数不能做优化
 */
#include"call_func.h"

#pragma GCC push_options
#pragma GCC optimize ("O0")
unsigned long int call_func2__(void*func,bool ret,int argc,call_data_type___ *argv){
	unsigned long int ax_qi4;
	//以下是汇编密集地方，不能乱插语句
#ifdef ver_no_asm_16_
#include "call_func-no-asm-16.inc"
#elif ver_no_asm_32_
#include "call_func-no-asm-32.inc"
#elif defined( ver_loongson_ )
#include"call_func-loongson.inc"
#elif defined( 	ver_mac_mini_ )
#include"call_func-mac-mini.inc"
//#elifdef ver_64_
#elif defined( ver_64_ )
#include"call_func-64.inc"
#else
	int i;
	unsigned long sp,sp0;
	__asm__ volatile ("mov %%esp,%0":"=m"( sp0 ));
	sp=sp0;
	for(i=argc-1;i>=0;i--,sp-=4)
		__asm__ volatile ("mov %0,%%esp\n\tmov %1,%%eax\n\tmov %%eax,(%%esp)"
				::"m"( sp ),"m"( argv[i] ) );
	__asm__ volatile ("call *%1\n\tmov %%eax,%0\n\tmov %2,%%esp"
			:"=m"( ax_qi4  ):"m"( func ),"m"( sp0 ));
#endif
	//以上是汇编密集地方，不能乱插语句
	return ax_qi4;

	/*if(!ret) {
		if(argc <= 0) {
			typedef void (*func_vv___)();
			((func_vv___)func)();
		} else {
			typedef void (*func_v___)(call_data_type___ *argv);
			((func_v___)func)(argv);
		}
		return 0;
	}
	typedef unsigned long int (*func___)(call_data_type___ *argv);
	return ((func___)func)(argv);*/
}
#pragma GCC pop_options

