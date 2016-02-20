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
int s2i__(const char* s1,int i=0){
	int i1=i;
	char c=s1[0];
	if(c=='+')
		s1++;
	sscanf(s1,"%d",&i1);
	if(c=='+')
		i1+=i;
	return i1;
}
int s2i__(const string& s,int i=0){
	return s2i__(s.c_str(), i);
}
float s2f__(const char* s,float d=0.0){
	sscanf(s,"%f",&d);
	return d;
}
float s2f__(const string& s,float d=0.0){
	return s2f__(s.c_str() ,d);
}
long x2l__(const char* s,long i=0){
	long i1=i;
	sscanf(s,"%lx",&i1);
	return i1;
}

bool bool__(const string& s) {
	if(s == "" || s == "0" || s == "false")
		return false;
	return true;
}
