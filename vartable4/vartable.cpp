/*
 * vartable.cpp
 *
 *  Created on: 2010-7-19
 *      Author: zzzzzzzzzzz
 */

#include"def1.h"
#include<string>
#include<iostream>
using namespace std;
#include"for_arg_.h"
#include<stdio.h>

int callback__(int argc,...){
	_for_args(argc)
		switch(i){
		case 0:
		{
			int i1=0;
			sscanf(s,"%d",&i1);
			for(;--i1>=0;)
				cout<<"\t";
		}
			break;
		default:
			cout<<"{"<<s<<"}";
			break;
		}
	_next_args
	cout<<endl;
	return 0;
}

dlle___ void dlln___(vartable__)(void*qu,var_for_1___ var_for,int max){
	cout<<endl;
	var_for(qu,callback__,max);
}
