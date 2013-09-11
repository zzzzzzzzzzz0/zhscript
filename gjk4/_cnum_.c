/*
 * _cnum_.c
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

#define sizeof_c1_ 4
#define sizeof_c2_ 3

static char* _c1[]={"个","十","百","千",};
static char* _c2[]={"万","亿","兆",};
static char* _c3[]={"零","一","二","三","四","五","六","七","八","九"};

_dle char* cnum__(char* s){
	int len,i1,i2,i;
    boolean b;
    int i5;
    int qianyileixing;//前一类型
    char c;
    int i3;
    int i4;
    int i9;
    boolean houmianquanshi0;//后面全是零
    int i11;
    int i6;
    int i7;
    int i10;
    int i8;

	cpy4__("");
	if(s==NULL){
		return s___();
	}

	len=strlen(s);
    i1=len;
    i2=0;
    for(i=0;i<len;i++){
      if(s[i]=='.'){
        i1=i;
        i2=len-i-1;
        break;
      }
    }

    b=false;
    i5=0;
    qianyileixing=0;
    for(i=0;i<i1;i++){
      c=s[i];
      i3=i1-i-1;
      i4=i3%sizeof_c1_;
      i5=i3/sizeof_c1_;
      i9=c-'0';
      if(i9==0){
        b=true;
        if(i4!=0){
          continue;
        }
      }else{
        if(b){
          cat4__(_c3[0]);
          qianyileixing=3;
        }
        b=false;
        if(i9==1 && i4==1 && !(s___()[0])){
        }else{
          cat4__(_c3[i9]);
          qianyileixing=3;
        }
      }
      if(i4==0){
        if(i5>0){
		   houmianquanshi0=true;
          for(i11=i;i11<i1;i11++){
            if(s[i11]!='0'){
              houmianquanshi0=false;
              break;
            }
          }
          if(qianyileixing!=2){
            i6=i5 - 1;
            if(i6>=sizeof_c2_){
              i7=sizeof_c2_-1;
              i10=i6-i7+1;
              for(i8=0;i8<i10;i8++)
                cat4__(_c2[i7]);
            }else if(i6>=0){
              cat4__(_c2[i6]);
            }
          }
          qianyileixing=2;
          if(houmianquanshi0)
            break;
        }
      }else{
        cat4__(_c1[i4]);
        qianyileixing=1;
      }
    }
    if(b){
      if(!(s___()[0])){
        cat4__(_c3[0]);
      }
    }
    if(i2>0)
      cat4__("点");
    for(i=0;i<i2;i++){
      i3=i+i1+1;
      c=s[i3];
      cat4__(_c3[c-'0']);
    }
    return s___();
}
