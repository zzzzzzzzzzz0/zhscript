/*
 * strcmp.cpp
 *
 *  Created on: 2021年9月10日
 *      Author: zzzzzzzzzzz
 */

#include "strcmp.h"
#include <stdlib.h>

static void f__(char& c1, const std::string& s1, std::string& s12, size_t& i1) {
	bool dian = false;
	for(;;) {
		if(c1 >= '0' && c1 <= '9') {} else {
			if(c1 == '.' && !dian) {
				dian = true;
			} else
				break;
		}
		s12 += c1;
		if(++i1 >= s1.size()) {
			c1 = 0;
			break;
		}
		c1 = s1[i1];
	}
}

int strcmp__(const std::string& s1, const std::string& s2, size_t i) {
	size_t i1 = i, i2 = i, j1 = 1;
	for(;;) {
		if(i1 >= s1.size()) {
			return i2 >= s2.size() ? 0 : -4;
		}
		if(i2 >= s2.size())
			return 4;
		char c1 = s1[i1];
		char c2 = s2[i2];
		std::string s12, s22;
		f__(c1, s1, s12, i1);
		f__(c2, s2, s22, i2);
		if(!s12.empty() && !s22.empty()) {
			if(j1 < 1000000000)
			j1 *= 10;
			//printf("%s\n%s\n", s12.c_str(), s22.c_str());
			double d1 = atof(s12.c_str()), d2 = atof(s22.c_str());
			if(d1 > d2)
				return j1;
			if(d1 < d2)
				return -j1;
		}
		//printf("%d\n%d\n", c1, c2);
		if(c1 > c2)
			return 1;
		if(c1 < c2)
			return -1;
		i1++, i2++;
	}
	return 0;
}

int strcmp2__(const std::string& s1, const std::string& s2) {
	int ret = 0;
	for(size_t i = 0; i < s1.length() && i < s2.length(); i++) {
		if(s1[i] != s2[i])
			break;
		ret++;
	}
	size_t i3 = ret;
	for(size_t i1 = s1.length(), i2 = s2.length();;) {
		if(i1 == i3 || i2 == i3)
			break;
		if(s1[--i1] != s2[--i2])
			break;
		ret++;
	}
	return ret;
}

