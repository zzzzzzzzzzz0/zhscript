/*
 * util.cpp
 *
 *  Created on: 2013-2-11
 *      Author: zzzzzzzzzzz
 */
#include <stdio.h>
#include <string>
using namespace std;

char* l2x__(long num,char* buf){
	sprintf(buf,"%lx",num);
	return buf;
}
char* l2s__(long num,char* buf){
	sprintf(buf,"%ld",num);
	return buf;
}
int s2i__(const string& s,int i=0){
	int i1=i;
	const char* s1=s.c_str();
	char c=s1[0];
	if(c=='+')
		s1++;
	sscanf(s1,"%d",&i1);
	if(c=='+')
		i1+=i;
	return i1;
}
float s2f__(const string& s,float d=0.0){
	sscanf(s.c_str(),"%f",&d);
	return d;
}
