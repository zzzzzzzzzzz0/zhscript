/*
 * for_dir.c
 *
 *  Created on: 2016年2月4日
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "string.h"

dlle___ void for_path__(int*err, void*ce, void* shangji, char* path, const char*code) {
	int len = strlen(path);
	bool b = true;
	char buf[32];
	for(int i = len - 1, i2 = 0; i > 0; i--) {
		if(path[i] == '/') {
			path[i] = 0;
			b = true;
		}
		if(b) {
			b = false;
			callback_(jsq_,shangji,err,ce,code,false,NULL, 2, path, i2s__(i2++, buf));
			if(for_err__(err)) break;
		}
	}
}

