/*
 * strlen_sp.cpp
 *
 *  Created on: 2019年1月23日
 *      Author: zzzzzzzzzzz
 */

#include "strlen_sp.h"

size_t strlen_sp__(const std::string& s, size_t len, size_t len2) {
	if(len == std::string::npos)
		len = s.size();
	size_t i2 = 0;
	unsigned char c4 = 0x80, c4a = 0xc0;
	for(size_t i = 0; i < len;) {
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
			i2 += len2;
			if(i3 == 2) //2个长 外文字母、带声调
				i2 -= 1;
			continue;
		}
		i++;
		i2++;
	}
	return i2;
}

