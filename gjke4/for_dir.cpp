/*
 * for_dir.c
 *
 *  Created on: 2016年2月4日
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "for_err.h"
#include "rust.h"

#define siz_ 512

static void cp__(const string& s, char* buf) {
	size_t n = s.length();
	if(n >= siz_)
		n = siz_ - 1;
	s.copy(buf, n);
	buf[n] = 0;
}
static void z__(int*err, rust_cb___ cb, rust_cb_free___ f, void*ce, void* shangji,
		char* path, const char*code, int argc, long can_kong, long from, bool use_r) {
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
		if(cb)
			f(cb(ce, shangji, err, '0', code, argc, argv));
		else
			callback3_(jsq_,shangji,err,ce,code,false,NULL, argc, argv, 0);
		if(for_err__(err, cb)) {
			delete argv;
			return;
		}
	}
	for(size_t i, i_old = use_r ? path2.size() : 0, i2 = 0;;) {
		i = use_r ? path2.rfind('/', i_old) : path2.find('/', i_old);
		if(can_kong <= 0 && (use_r && i == 0))
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
			if(cb)
				f(cb(ce, shangji, err, '0', code, argc, argv));
			else
				callback3_(jsq_,shangji,err,ce,code,false,NULL, argc, argv, 0);
			if(for_err__(err, cb))
				break;
		}
		if((use_r && i == 0) || i == string::npos)
			break;
		i_old = i + (use_r ? -1 : 1);
	}
	delete argv;
}

dlle___ void for_path__(int*err, void*ce, void* shangji, char* path, const char*code) {
	z__(err, NULL, NULL, ce, shangji, path, code, 2, 0, 0, true);
}
dlle___ void for_path2__(int*err, void*ce, void* shangji, char* path, const char*code, long can_kong, long from) {
	z__(err, NULL, NULL, ce, shangji, path, code, 3, can_kong, from, true);
}
dlle___ void rust_for_path__(int*err, rust_cb___ cb, rust_cb_free___ f, void* env, void* ret,
		char* path, const char*code, int argc, long can_kong, long from, bool use_r) {
	z__(err, cb, f, env, ret, path, code, argc, can_kong, from, use_r);
}

