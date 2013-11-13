#!/usr/bin/zhscript --。
加载lib/defi。
加载lib/gjk4。
加载lib/stdc。
赋予最大以（9）69（32）。
赋予sp-以$0x（20）200（100）。
显示下原样#define sp_sub "上原样‘sp-’下原样"
	__asm__ volatile (
			"sub "sp_sub",%%rsp\n"
			"mov %3,%%rbx\n"
			"mov %2,%%rax\n"
上原样。
赋予号以‘最大’。
循环先
	如果‘号’小于1那么跳出。
	赋予数以调用‘串格输出函数’-l、$0x%x、‘号’。
	显示换行制表符制表符制表符“"cmp ‘数’,%%rax\n""je case_‘号’\n"”。
	赋予号以算术‘号’-1。
了。
显示下原样
			"cmp $0x0,%%rax\n""jl case_0\n"
上原样。
赋予号以‘最大’。
循环先
	如果‘号’小于7那么跳出。
	赋予偏1以调用‘串格输出函数’-l、0x%x、算术(‘号’-1)*8。
	赋予偏2以调用‘串格输出函数’-l、0x%x、算术(‘号’-7)*8。
	显示换行制表符制表符制表符“"case_‘号’:\n""mov ‘偏1’(%%rbx),%%rax\n""mov %%rax,‘偏2’(%%rsp)\n"”。
	赋予号以算术‘号’-1。
了。
显示下原样
			"case_6:\n""mov 0x28(%%rbx),%%r9\n"
			"case_5:\n""mov 0x20(%%rbx),%%r8\n"
			"case_4:\n""mov 0x18(%%rbx),%%rcx\n"
			"case_3:\n""mov 0x10(%%rbx),%%rdx\n"
			"case_2:\n""mov  0x8(%%rbx),%%rsi\n"
			"case_1:\n""mov     (%%rbx),%%rdi\n"
			"case_0:\n"
			"mov $0x0,%%al\n""callq *%1\n"
			"mov %%rax,%0\n"
			"add "sp_sub",%%rsp\n"
			:"=m"( ax_qi4 ):"m"( func ),"m"( argc ),"m"( argv ));
上原样。