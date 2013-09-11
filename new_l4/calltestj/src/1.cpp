//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdarg.h>
#include "../../l432_so/call_func.h"

unsigned long l_z__(int argc,...){
	cout << "l_z__("<<argc<<"){";
    va_list argv;
    va_start(argv, argc);
    for (int i = 0; i < argc; ++i){
    	//unsigned long s = va_arg(argv, unsigned long);
    	void*s = va_arg(argv, void*);
		cout << s << ",";
    }
    va_end(argv);
	cout << "}//l_z__" << endl;
	return 1000+argc;
}

void switch__(int i){
	switch(i){
	default:
		if(i<0)
			break;
	case 3:
		cout<<"...";
	case 2:
		cout<<"c";
	case 1:
		cout<<"b";
	case 0:
		cout<<"a";
	}
	cout<<endl;
}
void v__(){
	cout<<"v__ "<<(void*)v__<<endl;
}
void call1_v__(){
	v__();
}
unsigned long l_v__(){
	cout<<"l_v__ "<<(void*)l_v__<<endl;
	return 1;
}
void call1_l_v__(){
	unsigned long l1=0;
	l1=l_v__();
	cout<<"l1="<<l1<<endl;
}
void call1_l_z0__(){
	unsigned long l1=0;
	l1=l_z__(0);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z1__(){
	unsigned long l1=0;
	l1=l_z__(1,1);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z2__(){
	unsigned long l1=0;
	l1=l_z__(2,1,2);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z3__(){
	unsigned long l1=0;
	l1=l_z__(3,1,2,3);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z4__(){
	unsigned long l1=0;
	l1=l_z__(4,1,2,3,4);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z5__(){
	unsigned long l1=0;
	l1=l_z__(5,1,2,3,4,5);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z6__(){
	unsigned long l1=0;
	l1=l_z__(6,1,2,3,4,5,6);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z7__(){
	unsigned long l1=0;
	l1=l_z__(7,1,2,3,4,5,6,7);
	cout<<"l1="<<l1<<endl;
}
void call1_l_z8__(int argc,unsigned long *l){
	l[0]=argc;
	unsigned long l1=0;
	l1=l_z__(l[0],l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8]);
	cout<<"l1="<<l1<<endl;
}
extern "C" char* ret_ca__(char*s){
	cout<<"ret_ca("<<s<<")"<<endl;
	return s;
}

void call_v__(){
	void* func=(void*)v__;
	__asm__ volatile ("callq *%0"::"m"( func ));
}
void call_l_v__(){
	void* func=(void*)l_v__;
	unsigned long l1=0;
	__asm__ volatile ("callq *%1" "\n" "mov %%rax,%0":"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
void call_l_z0__(){
	void* func=(void*)l_z__;
	unsigned long l1=0;
	__asm__ volatile (
			"mov $0x0,%%edi\n"
			"mov $0x0,%%al\n" "callq *%1\n" "mov %%rax,%0":"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
void call_l_z1__(){
	void* func=(void*)l_z__;
	unsigned long l1=0;
	__asm__ volatile ("mov $0x1,%%esi\n" "mov $0x1,%%edi\n"
			"mov $0x0,%%al\n" "callq *%1\n" "mov %%rax,%0":"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
void call_l_z2__(){
	void* func=(void*)l_z__;
	unsigned long l1=0;
	__asm__ volatile ("mov $0x2,%%edx\n" "mov $0x1,%%esi\n" "mov $0x2,%%edi\n"
			"mov $0x0,%%al\n" "callq *%1" "\n" "mov %%rax,%0":"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
void call_l_z3__(){
	void* func=(void*)l_z__;
	unsigned long l1=0;
	__asm__ volatile ("mov $0x3,%%ecx\n" "mov $0x2,%%edx\n" "mov $0x1,%%esi\n" "mov $0x3,%%edi\n"
			"mov $0x0,%%al\ncallq *%1\nmov %%rax,%0":"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
void call_l_z4__(){
	void* func=(void*)l_z__;
	unsigned long l1=0;
	__asm__ volatile (
			"mov $0x4,%%r8d\n"
			"mov $0x3,%%ecx\n" "mov $0x2,%%edx\n" "mov $0x1,%%esi\n" "mov $0x4,%%edi\n"
			"mov $0x0,%%al\n" "callq *%1\n" "mov %%rax,%0\n"
			:"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
void call_l_z5__(){
	void* func=(void*)l_z__;
	unsigned long l1=0;
	__asm__ volatile (
			"mov $0x5,%%r9d\n""mov $0x4,%%r8d\n"
			"mov $0x3,%%ecx\n""mov $0x2,%%edx\n""mov $0x1,%%esi\n""mov $0x5,%%edi\n"
			"mov $0x0,%%al\n""callq *%1\n""mov %%rax,%0\n"
			:"=m"( l1 ):"m"( func ));
	cout<<"l1="<<l1<<endl;
}
unsigned long call_l_z6__(void* func,unsigned long l1){
	/*

                  call1_l_z6__():
0000000000400df8:   push %rbp
0000000000400df9:   mov %rsp,%rbp
0000000000400dfc:   sub $0x20,%rsp
 91               	unsigned long l1=0;
0000000000400e00:   movq $0x0,-0x8(%rbp)
 92               	l1=l_z__(6,1,2,3,4,5,6);
0000000000400e08:   movl $0x6,(%rsp)
0000000000400e0f:   mov $0x5,%r9d
0000000000400e15:   mov $0x4,%r8d
0000000000400e1b:   mov $0x3,%ecx
0000000000400e20:   mov $0x2,%edx
0000000000400e25:   mov $0x1,%esi
0000000000400e2a:   mov $0x6,%edi
0000000000400e2f:   mov $0x0,%eax
0000000000400e34:   callq 0x400924 <l_z__(int, ...)>
0000000000400e39:   mov %rax,-0x8(%rbp)
 93               	cout<<"l1="<<l1<<endl;
0000000000400e3d:   mov $0x402357,%esi
0000000000400e42:   mov $0x603080,%edi
0000000000400e47:   callq 0x4007f0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
0000000000400e4c:   mov -0x8(%rbp),%rdx
0000000000400e50:   mov %rdx,%rsi
0000000000400e53:   mov %rax,%rdi
0000000000400e56:   callq 0x400810 <_ZNSolsEm@plt>
0000000000400e5b:   mov $0x400830,%esi
0000000000400e60:   mov %rax,%rdi
0000000000400e63:   callq 0x400820 <_ZNSolsEPFRSoS_E@plt>
 94               }
0000000000400e68:   leaveq
0000000000400e69:   retq
 	 */
	__asm__ volatile (
			"movl $0x6,(%%rsp)\n"
			"mov $0x5,%%r9d\n"
			"mov $0x4,%%r8d\n"
			"mov $0x3,%%ecx\n"
			"mov $0x2,%%edx\n"
			"mov $0x1,%%esi\n"
			"mov $0x6,%%edi\n"
			"mov $0x0,%%eax\n"
			"callq *%1\n"
			"mov %%rax,%0\n"
			:"=m"( l1 ):"m"( func ));
	return l1;
}
void call_l_z6__(){
	cout<<"l1="<<call_l_z6__((void*)l_z__,0)<<endl;
}
/*
0000000000400e72:   movq $0x0,-0x8(%rbp)
97               	l1=l_z__(7,1,2,3,4,5,6,7);
0000000000400e7a:   movl $0x7,0x8(%rsp)
0000000000400e82:   movl $0x6,(%rsp)
0000000000400e89:   mov $0x5,%r9d
0000000000400e8f:   mov $0x4,%r8d
0000000000400e95:   mov $0x3,%ecx
0000000000400e9a:   mov $0x2,%edx
0000000000400e9f:   mov $0x1,%esi
0000000000400ea4:   mov $0x7,%edi
0000000000400ea9:   mov $0x0,%eax
0000000000400eae:   callq 0x400924 <l_z__(int, ...)>
0000000000400eb3:   mov %rax,-0x8(%rbp)
 */
unsigned long call_l_z7__(void* func,unsigned long l1){
	__asm__ volatile (
			"sub $0x20,%%rsp\n"
			"movl $0x7,0x8(%%rsp)\n"
			"movl $0x6,(%%rsp)\n"
			"mov $0x5,%%r9d\n"
			"mov $0x4,%%r8d\n"
			"mov $0x3,%%ecx\n"
			"mov $0x2,%%edx\n"
			"mov $0x1,%%esi\n"
			"mov $0x7,%%edi\n"
			"mov $0x0,%%eax\n"
			"callq *%1\n"
			"mov %%rax,%0\n"
			"add $0x20,%%rsp\n"
			:"=m"( l1 ):"m"( func ));
	return l1;
}
void call_l_z7__(){
	cout<<"l1="<<call_l_z7__((void*)l_z__,0)<<endl;
}
void call_l_z8__(void* func,bool b,int argc,unsigned long *argv){
	unsigned long ax_qi4=0;
	cout<<"ax_qi4="<<ax_qi4<<endl;
}
void call_l_z8__(int argc,unsigned long *argv){
	argv[0]=argc;
	call_l_z8__((void*)l_z__,false,argc,argv);
}
void call_ret_ca__(){
	char**s1=new char*[1];
	s1[0]=(char*)"123";

	char*s=ret_ca__(s1[0]);
	cout<<"{"<<s<<"}"<<endl;

	void* func=(void*)ret_ca__;
	__asm__ volatile (
			"mov %2,%%rbx\n""mov (%%rbx),%%rdi\n"
			"callq *%1\n" "mov %%rax,%0":"=m"( s ):"m"( func ),"m"( s1 ));
	cout<<"{"<<s<<"}"<<endl;
	delete s1;
}
unsigned long int call_func2__(void*func,bool ret,int argc,
		call_data_type___ *argv,unsigned long int ax_qi4){

#include "../../l432_so/call_func-64.inc"
//#include "../../l432_so/call_func-mac-mini.inc"

	return ax_qi4;
}

int main() {
	#define len 123
	unsigned long l[len];
	for(int i=1;i<len;i++){
		l[i]=i;
	}

	/*for(int i=-1;i<=9;i++){
		l[0]=i;
		call_l_z8__((void*)l_z__,true,i,l);
	}*/
	call_func2__((void*)v__,false,0,0,0);
	for(int i=0;i<len;i++){
		l[0]=i;
		call_func2__((void*)l_z__,true,i,(call_data_type___ *)l,0);
	}

	//call_ret_ca__();

	//switch__(-1);

	//call1_l_z8__(8,l);
	/*call_l_z8__(-1,l);
	call_l_z8__(0,l);
	call_l_z8__(1,l);
	call_l_z8__(2,l);
	call_l_z8__(3,l);
	call_l_z8__(4,l);
	call_l_z8__(5,l);
	call_l_z8__(6,l);
	call_l_z8__(7,l);
	call_l_z8__(8,l);
	call_l_z8__(9,l);*/

	/*call1_l_z7__();
	call_l_z7__();

	call1_l_z6__();
	call_l_z6__();

	call1_l_z5__();
	call_l_z5__();

	call1_l_z4__();
	call_l_z4__();

	call1_l_z3__();
	call_l_z3__();

	call1_l_z2__();
	call_l_z2__();

	call1_l_z1__();
	call_l_z1__();

	call1_l_z0__();
	call_l_z0__();

	call1_l_v__();
	call_l_v__();

	call1_v__();
	call_v__();*/
	return 0;
}
