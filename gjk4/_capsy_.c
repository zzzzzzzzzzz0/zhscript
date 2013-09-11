/*
 * _capsy_.c
 *
 *  Created on: 2009-6-7
 *      Author: zzzzzzzzzzz
 */
#include"1.h"

#ifndef _WINDOWS
#define boolean int
#endif
#define false 0
#define true 1

#define a_s1_length 5
#define a_s2_length 4
#define a_s3_length 3

static char* _a_s1[] = {"微", "毫", "厘", "分", "角", };
static char* _a_s2[] = {"元", "万", "亿", "兆",};
static char* _a_s3[] = {"拾", "佰", "仟", };
static char* _a_s4[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖", };

_dle void capsy__(int* c4w4,char*buf,long siz,char* s) {
	int i;
	boolean b4;
	int len;
	int i1;
	char c;
	int i6;
	int i7;
	boolean b2, b3;
	int i2;
	int i5;
	int i3;
	int i4;
	boolean b, b1;

	cpy4__("");
	if(s==NULL){
		return;
	}
	i = 0;
	b4 = true;
	len=strlen(s);
	for (i1 = len - 1; i1 >= 0; i1--) {
		c = s[i1];
		if (c == ' ' || c == ',' || c == '.') {
			if (b4) {
				if (i> a_s1_length) {
		            strcpy(buf,"'.' location > ");
		            strcat(buf,ret___(a_s1_length));
					*c4w4=1;
					return;
				}
				else {
					i = a_s1_length;
				}
				b4 = false;
			}
			else if ( (i - a_s1_length) % a_s3_length != 0) {
	            strcpy(buf,"',' error");
				*c4w4=2;
				return;
			}
			continue;
		}
		i6 = c - '0';
		if (i6 >= 0 && i6 <= 9) {
			i++;
		}
		else {
            buf[0]=c;
            buf[1]=0;
            strcat(buf," not in 0-9");
			*c4w4=3;
			return;
		}
	}
	i7 = 0;
	b2 = false;
	b3 = true;
	for (i1 = 0; i1 < len; i1++) {
		c = s[i1];
		if (c == ' ' || c == ',' || c == '.') {
			continue;
		}
		i2 = i - 1 - a_s1_length;
		i5 = a_s3_length + 1;
		i3 = i2 % i5;
		i4 = i2 / i5;
		b = true;
		b1 = true;
		if (c == '0') {
			b = false;
			if (! ( (i2 >= 0 && i3 == 0 && (!b2 || i4 == 0)))) {
				b1 = false;
			}
			i7++;
		}
		else {
			if (i7 >= 1) {
				cat4__(_a_s4[0]);
			}
			i7 = 0;
			b2 = false;
		}
		if (b) {
			cat4__(_a_s4[c - '0']);
		}
		if (b1 && s___()) {
			if (i2 < 0) {
				cat4__(_a_s1[i2 + a_s1_length]);
				b3 = false;
			}
			else if (i3 != 0) {
				cat4__(_a_s3[i3 - 1]);
			}
			else {
				if (i4 >= a_s2_length) {
					for (i6 = -2; i6 < i4 - a_s2_length; i6++) {
						cat4__(_a_s2[a_s2_length - 1]);
					}
				}
				else {
					cat4__(_a_s2[i4]);
				}
				b2 = true;
			}
		}
		i--;
	}
	if (b3) {
		cat4__("整");
	}
	__strcpyn(buf,s___(),siz);
}

