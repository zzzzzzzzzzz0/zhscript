/*
 * rnd.cpp
 *
 *  Created on: 2011-4-16
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include <stdlib.h>
#include <time.h>

dlle___ void srand__(long l){
	unsigned int seed;
	if(l==-1)
        seed=time(0);
	else
		seed=l;
    srand(seed);
}

dlle___ long int rando__(long int min,long int max){
	return random()%(max-min+1)+min;
}

#define var_new__(name,val) var_new_(jsq_,qu,name.c_str(),val,false,false,false)

dlle___ int rand__(void* qu,char*head1,long int min,long int max){
	if(!head1)
		return -1;
	string head=head1;
	string name;
	char buf[32];
	int err;
	long int len=max-min+1;
	if(len>0){
		long int* num=new long int[len];
		if(!num)
			return -1;
		char buf2[32];
		for(long int i=0;i<len;i++){
			for(;;){
				num[i]=rando__(min, max);
				bool has=false;
				for(long int i1=0;i1<i;i1++){
					if(num[i1]==num[i]){
						has=true;
						break;
					}
				}
				if(!has)
					break;
			}
			name=head+kw_dian_+l2s__(i+1,buf);
			if((err=var_new__(name,l2s__(num[i],buf2))))
				return err;
		}
		delete num;
	}
	name=head+kw_length_;
	if((err=var_new__(name,l2s__(len,buf))))
		return err;
	name=head+kw_length_+"2";
	if((err=var_new__(name,l2s__(1,buf))))
		return err;
	return 0;
}
