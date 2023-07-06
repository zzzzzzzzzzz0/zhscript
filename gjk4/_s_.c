/*
 * _s_.c
 *
 *  Created on: 2009-6-7
 *      Author: zzzzzzzzzzz
 */

#include"1.h"
#include "for_arg_.h"

static void int2stri_s3__(char* s3, int i, int i1, const char* a[], int x_a) {
	if(x_a == 1) {
		s3[i]=a[0][i1];
		s3[i + 1]=0;
	} else {
		const char* s2 = a[i1];
		for(int i2 = 0; (s3[i + i2] = s2[i2]); i2++);
	}
}
static char* int2stri__(long l,int i3, const char* a[], int x_a){
	int i1;
	long i2;
	char* s3;
	char* s4;
	int i4;

	i1 = (int)(l % i3);
	int len1 = 1;
	if(x_a > 1)
		len1=strlen(a[i1]);
    s3=(char*)malloc(len1 + 1);
    if(s3==NULL)
    	return NULL;
    int2stri_s3__(s3, 0, i1, a, x_a);
    i2 = l / i3;
    if (i2 > 0) {
    	s4=int2stri__(i2, i3, a, x_a);
        if(s4==NULL)
        	return s3;
        i4=strlen(s4);
        s3=(char*)realloc(s3,1+i4+len1);
        strcpy(s3,s4);
        free(s4);
        int2stri_s3__(s3, i4, i1, a, x_a);
    }
    return s3;
}

static const char*s1_="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char* s1__(const char* s1, int* i3) {
	if(s1) {
		if(!s1[0]) {
			return s1_;
		}
		if(!s1[1]) {
			switch(s1[0]) {
			case '1': return s1_;
			case '2': return s1_ + 10;
			case 'a': *i3 = 26; return s1_ + 10;
			case 'A': return s1_ + 36;
			}
		}
	}
	return s1;
}

static int jinzhi_ok__(int jinzhi, int len1, int*c4w4,char*buf) {
	if(jinzhi<2||jinzhi>len1){
		ltoa_(jinzhi,buf,10);
		strcat(buf," < 2 || > ");
		strcat(buf,ret___(len1));
		*c4w4=1;
		return 0;
	}
	return 1;
}

#define x_a2_ 128
static int args_get__(int i, char* s, const char** s1, int *jinzhi, const char** a, int* x_a, int*c4w4) {
	switch(i){
	case 1:
		*s1=s;
		break;
	case 0:
		*jinzhi=atoi(s);
		break;
	default:
		if(*x_a >= x_a2_) {
			*c4w4 = 10;
			return 0;
		}
		a[(*x_a)++] = s;
		break;
	}
	return 1;
}

_dle const char* int2str__(int*c4w4,char*buf,long siz,long l,int argc,...){
	const char* s1="";
	int i3=10;
	char* s3;
	int len1;
	const char* a[x_a2_];
	int x_a = 1;

	_for_args( argc )
		if(!args_get__(i, s, &s1, &i3, a, &x_a, c4w4)) return NULL;
	_next_args

	if(x_a == 1) {
		if((s1 = s1__(s1, &i3))==NULL)
			return NULL;
		len1=strlen(s1);
	} else
		len1 = x_a;
	if (i3 == -1)
		i3 = len1;
	else if(i3 < 0) {
		i3 = -i3;
		s1 += len1 - i3;
	}
	if(!jinzhi_ok__(i3, len1, c4w4,buf))
      return NULL;

	a[0] = s1;
    s3=int2stri__(l,i3, a, x_a);
    if(s3==NULL)
    	return NULL;
    cpy4__(s3);
    free(s3);
    return s___();
}


_dle long str2int__(int*c4w4,char*buf,long siz,char* s0,int argc,...) {
	if(!s0 || !s0[0])
		return 0;
	const char* s1="";
	long l = 0;
	int i0;
	int len,len1,jinzhi=10;
	const char* a[x_a2_];
	int x_a = 1;
	char c;
	int a_i3[16];
	int i3 = 0;
	int i2;
	int i1;
	char c1;
	long l1;
	_for_args( argc )
		if(!args_get__(i, s, &s1, &jinzhi, a, &x_a, c4w4)) return 0;
	_next_args

	if(x_a == 1) {
		if((s1 = s1__(s1, &jinzhi))==NULL)
			return 0;
		len1=strlen(s1);
	} else
		len1 = x_a;

	len=strlen(s0);
	if(jinzhi==-1)
		jinzhi=len1;
	if(!jinzhi_ok__(jinzhi, len1, c4w4,buf))
      return 0;
	a[0] = s1;
	for (i0 = 0; i0 < len;) {
		i2 = -1;
		if(x_a == 1) {
			c = s0[i0];
			for (i1 = 0; i1 < jinzhi; i1++) {
				c1 = s1[i1];
				if (c == c1) {
					i2 = i1;
					break;
				}
			}
			i0++;
		} else {
			for (i1 = 0; i1 < jinzhi && i2==-1; i1++) {
				for(int i4 = 0;; i4++) {
					c1 = a[i1][i4];
					if(!c1) {
						i2=i1;
						i0 += i4;
						break;
					}
					c = s0[i0 + i4];
					if(!c || c != c1)
						break;
				}
			}
		}
		//printf("%d %d %d\n",i0,i2,i3);
		if(i2==-1){
			buf[0]=c;
			buf[1]=' ';
			buf[2]=0;
			strcat(buf,s1);
			*c4w4=1;
			return 0;
		}
		a_i3[i3++] = i2;
	}
	for (i0 = 0; i0 < i3; i0++) {
		l1 = 1;
		for (i1 = 0; i1 < i3 - i0 - 1; i1++)
			l1 *= jinzhi;
		l += a_i3[i0] * l1;
	}
	return l;
}
