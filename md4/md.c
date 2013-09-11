/*
 * md.c
 *
 *  Created on: 2011-2-8
 *      Author: zzzzzzzzzzz
 */

#include "md5.h"

#include <stdio.h>
#include <string.h>

void md5__(char* buf,char *s){
	if(!s)
		return;
    struct MD5Context md5c;
    unsigned char ss[16];
    int i;
    MD5Init( &md5c );
    MD5Update( &md5c, s, strlen(s) );
    MD5Final( ss, &md5c );
    for( i=0; i<16; i++ )
	  sprintf(buf+(i*2), "%02x", ss[i] );
}
