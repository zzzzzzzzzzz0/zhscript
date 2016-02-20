/*
 * main.cpp
 *
 *  Created on: 2013-1-23
 *      Author: zzzzzzzzzzz
 */
#include "gjks.h"

bool ok__(void* p) {
	return p != NULL;
}

size_t space_size__(const string& s) {
	size_t i2 = 0;
	unsigned char c4 = 0x80, c4a = 0xc0;
	for(size_t i = 0; i < s.size();) {
		unsigned char c = s[i];
		int i3 = 1;
		bool b = false;
		for(; i3 <= 3 && !b; i3++) {
			unsigned char c3 = (i3 == 1 ? 0 : (i3 << 4)) + 0xc0,
							c3a = ((i3 + 1) << 4) + (i3 == 3 ? 0xb8 : 0xc0);
			if((c & c3a) == c3 && i + i3 <= s.size()) {
				b = true;
				for(int i4 = 1; i4 <= i3 && b; i4++) {
					unsigned char c5 = s[i + i4];
					if((c5 & c4a) == c4) {
					} else {
						b = false;
					}
				}
			}
		}
		if(b) {
			i += i3;
			i2 += 2;
			continue;
		}
		i++;
		i2++;
	}
	return i2;
}

callback3_2___ cb_;
void* jsq_;

dlle___ void init__(void* jsq, callback3_2___ cb) {
	jsq_=jsq;
	cb_=cb;
}

#include "call_util.cpp"
