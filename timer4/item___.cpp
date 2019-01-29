/*
 * item___.cpp
 *
 *  Created on: 2015年3月11日
 *      Author: zzzzzzzzzzz
 */

#include "item___.h"

item___::~item___() {
	d_free__(d_len2_);
}

void item___::d_free__(int len2) {
	for(int i = 0; i <= len2; i++) {
		regfree(&d_[i]);
	}
}

void item___::init__() {
	pause_ = false;
	i_ = 0;
	d_len2_ = -1;
}

int item___::mk_time__(char* time) {
	switch(type_) {
	case 'd':
	{
		int i2 = -1;
		if(!time || !time[0]) {
			for(size_t i = 0; i < d_len_; i++, i2++)
				regcomp(&d_[i], ".*", REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
		} else {
			string time2 = time;
			string s;
			bool b = false;
			for(size_t i = 0; !b; i++) {
				if(i >= time2.size()) {
					b = true;
				} else {
					char c = time2[i];
					if(c != '-') {
						s += c;
						continue;
					}
				}
				i2++;
				if(i2 >= d_len_) {
					d_free__(d_len_ - 1);
					return 31;
				}
				if(s == "*")
					s = "." + s;
				else {
					regex_t re;
					int z = regcomp(&re, "([0-9]+)~([0-9]+)", REG_EXTENDED);
					#define nmatch 4
					regmatch_t pm[nmatch];
					int off = 0;
					string s2;
					char s3[16];
					for(;;) {
						z = regexec(&re, s.c_str() + off, nmatch, pm, 0);
						if(z != 0)
							break;
						int so1 = pm[1].rm_so;
						string ss = s.substr(so1 + off, pm[2].rm_eo - so1);
						int so, eo;
						sscanf(ss.c_str(), "%d~%d", &so, &eo);
						s2 += s.substr(off, so1);
						for(int i = so; i <= eo; i++) {
							if(i > so)
								s2 += "|";
							sprintf(s3, "%d", i);
							s2 += s3;
						}
						off += pm[2].rm_eo;
					}
					if(!s2.empty()) {
						s2 += s.substr(off);
						s = s2;
					}
					regfree(&re);

					s = "^(" + s + ")$";
				}

				int z = regcomp(&d_[i2], s.c_str(), REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
				if(z != 0) {
					d_free__(i2);
					return 32;
				}
				s.clear();
			}
		}
		if(i2 != d_len_ - 1) {
			d_free__(i2);
			return 31;
		}
		d_len2_ = d_len_ - 1;
		time_ = 1000;
		break;
	}
	default:
	{
		int x = 1;
		float time3;
		if(!time || !time[0]) {
			time3 = 1000;
		} else {
			string time2 = time;
			switch(time2[time2.size() - 1]) {
			case 'h':
				x *= 60;
			case 'm':
				x *= 60;
			case 's':
				x *= 1000;
				time2.erase(time2.size() - 1, 1);
				break;
			}
			if(sscanf(time2.c_str(), "%f", &time3) != 1) {
				return 2;
			}
		}
		time_ = time3 * x;
		break;
	}
	}
	if(time)
		time2_ = time;
	return 0;
}

bool item___::begin__(const char* argv[]) {
	if(pause_)
		return false;
	i_ += interval_;
	if(i_ < time_)
		return false;
	if(!is_loop_)
		pause_ = true;
	i_ = 0;
	switch(type_) {
	case 'd':
	{
		for(int i = 0; i < d_len_; i++) {
			int z = regexec(&d_[i], argv[i], 0, 0, 0);
			switch(z) {
			case 0:
				continue;
			case REG_NOMATCH:
				return false;
			}
		}
		break;
	}
	}
	return true;
}

void item___::end__() {
}
