/*
 * _s_.c
 *
 *  Created on: 2009-6-7
 *      Author: zzzzzzzzzzz
 */

#include"1.h"
#include "for_arg_.h"

static char* int2stri__(long l,int i3,char* s1){
	int i1;
	long i2;
	char* s3;
	char* s4;
	int i4;

	i1 = (int)(l % i3);
    s3=(char*)malloc(2);
    if(s3==NULL)
    	return NULL;
    s3[0]=s1[i1];
    s3[1]=0;
    i2 = l / i3;
    if (i2 > 0) {
    	s4=int2stri__(i2, i3, s1);
        if(s4==NULL)
        	return s3;
        i4=strlen(s4);
        s3=(char*)realloc(s3,1+i4+1);
        strcpy(s3,s4);
        free(s4);
        s3[i4]=s1[i1];
        s3[i4+1]=0;
    }
    return s3;
}

static char* s1_="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

_dle const char* int2str__(int*c4w4,char*buf,long siz,long l,int argc,...){
	char* s1=s1_;
	int i3=10;
	char* s3;
	int len1;

	_for_args( argc )
		switch(i){
		case 1:
			s1=s;
			break;
		case 0:
			i3=atoi(s);
			break;
		}
	_next_args

    if(s1==NULL)
      return NULL;
	len1=strlen(s1);
    if (i3 == -1)
      i3 = len1;
	if(i3<2||i3>len1){
		ltoa_(i3,buf,10);
		strcat(buf," < 2 || > ");
		strcat(buf,ret___(len1));
		*c4w4=1;
      return NULL;
	}

    s3=int2stri__(l,i3,s1);
    if(s3==NULL)
    	return NULL;
    cpy4__(s3);
    free(s3);
    return s___();
}


_dle long str2int__(int*c4w4,char*buf,long siz,char* s0,int argc,...) {
	char* s1=s1_;
	long l = 0;
	int i0;
	int len,len1,jinzhi=10;
	char c;
	int i3;
	int i2;
	int i1;
	char c1;
	long l1;
	_for_args( argc )
		switch(i){
		case 1:
			s1=s;
			break;
		case 0:
			jinzhi=atoi(s);
		}
	_next_args

    if(s1==NULL)
      return 0;

	len=strlen(s0);
	len1=strlen(s1);
	if(jinzhi==-1)
		jinzhi=len1;
	if(jinzhi<2||jinzhi>len1){
		ltoa_(jinzhi,buf,10);
		strcat(buf," < 2 || > ");
		strcat(buf,ret___(len1));
		*c4w4=1;
      return 0;
	}
	for (i0 = 0; i0 < len; i0++) {
		c = s0[i0];
		i3 = len - 1 - i0;
		i2 = -1;
		for (i1 = 0; i1 < jinzhi; i1++) {
			c1 = s1[i1];
			if (c == c1) {
				i2 = i1;
				break;
			}
		}
		if(i2==-1){
			buf[0]=c;
			buf[1]=' ';
			buf[2]=0;
			strcat(buf,s1);
			*c4w4=1;
			return 0;
		}
		l1 = 1;
		for (i1 = 0; i1 < i3; i1++)
			l1 *= jinzhi;
		l += i2 * l1;
	}
	return l;
}
