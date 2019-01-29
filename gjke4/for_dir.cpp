/*
 * for_dir.c
 *
 *  Created on: 2016年2月4日
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"

#define siz_ 512

static void cp__(const string& s, char* buf) {
	size_t n = s.length();
	if(n >= siz_)
		n = siz_ - 1;
	s.copy(buf, n);
	buf[n] = 0;
}
static void z__(int*err, void*ce, void* shangji, char* path, const char*code, int argc, long can_kong, long from) {
	string path2 = path;
	const char** argv = new const char*[argc];
	char buf0[siz_], buf[32] = "0", buf2[siz_] = "";
	argv[0] = buf0;
	argv[1] = buf;
	switch(argc) {
	case 3:
		argv[2] = buf2;
		break;
	}
	if(from <= 0) {
		cp__(path2, buf0);
		callback3_(jsq_,shangji,err,ce,code,false,NULL, argc, argv, 0);
		if(for_err__(err)) {
			delete argv;
			return;
		}
	}
	for(size_t i, i_old = path2.size(), i2 = 0;;) {
		i = path2.rfind('/', i_old);
		if(can_kong <= 0 && i == 0)
			break;
		if(++i2 >= (size_t)from) {
			i2s__(i2, buf);
			if(i == string::npos) {
				if(can_kong >= 2) {
					buf0[0] = 0;
					cp__(path2, buf2);
				} else
					break;
			} else {
				cp__(path2.substr(0, i), buf0);
				switch(argc) {
				case 3:
					cp__(path2.substr(i + 1), buf2);
					break;
				}
			}
			callback3_(jsq_,shangji,err,ce,code,false,NULL, argc, argv, 0);
			if(for_err__(err))
				break;
		}
		if(i == 0 || i == string::npos)
			break;
		i_old = i - 1;
	}
	delete argv;
}

dlle___ void for_path__(int*err, void*ce, void* shangji, char* path, const char*code) {
	z__(err, ce, shangji, path, code, 2, 0, 0);
}
dlle___ void for_path2__(int*err, void*ce, void* shangji, char* path, const char*code, long can_kong, long from) {
	z__(err, ce, shangji, path, code, 3, can_kong, from);
}

