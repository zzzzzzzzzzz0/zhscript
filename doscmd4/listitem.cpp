/*
 * listitem.cpp
 *
 *  Created on: 2017年12月24日
 *      Author: zzzzzzzzzzz
 */

#include "listitem.h"
#include <stdio.h>

//#define ver_debug_
#ifdef ver_debug_
#include <iostream>
static void add__(char*buf, string s, size_t &end) {
	s.copy(buf + end, s.size());
	end += s.size();
	buf[end] = 0;
}
#endif

void list_item___::get__(char c, char*buf,long siz) {
	size_t end;
	switch(c) {
	case 't':
		end = type_.size();
		type_.copy(buf, end);
		break;
	default:
		end = path_.size();
		path_.copy(buf, end);
		break;
	}
	buf[end] = 0;

#ifdef ver_debug_
	add__(buf, " ", end);
	add__(buf, to_string(id_), end);
	buf[end++] = typ2_;
	buf[end] = 0;
	if(begin_ > 0) {
		add__(buf, " ", end);
		add__(buf, to_string(begin_), end);
		add__(buf, "----", end);
		add__(buf, to_string(end_), end);
	}
#endif
}

bool list_item___::range__(list_item___* b) {
	if(begin_ > 0) {
#ifdef ver_debug_
		/*size_t tid = 79;
		if(id_ == tid)*/ {
			cout << path_ << " " << b->path_ << " ";
			cout << begin_ << "<" << b->id_ << "<" << end_;
		}
#endif
		if(b->id_ >= begin_ && b->id_ <= end_) {
#ifdef ver_debug_
			/*if(id_ == tid)*/ {
				cout << endl;
			}
#endif
			return true;
		}
#ifdef ver_debug_
		/*if(id_ == tid)*/ {
			cout << " o" << endl;
		}
#endif
	}
	return false;
}
bool list_item___::begin__(list_item___* b) {
	if(typ2_ != 'e')
		return false;
	return range__(b);
}
bool list_item___::index_begin__(list_item___* b) {
	if(typ2_ != 'i')
		return false;
	return range__(b);
}

bool list_item___::comp__(list_item___* a, list_item___* b) {
	switch(sort_) {
	case 3:
		if(a->index_begin__(b)) {
			return true;
		}
		if(b->index_begin__(a)) {
			return false;
		}
		break;
	}

	int i = a->path_.compare(b->path_);
	if(i == 0)
		return a->begin_ == 0;
	if(a->begin__(b)) {
		return false;
	}
	if(b->begin__(a)) {
		return true;
	}
	{
		size_t i_a_p = a->path_.rfind("/"),  i_b_p = b->path_.rfind("/");
		if(i_a_p == string::npos)
			i_a_p = 0;
		if(i_b_p == string::npos)
			i_b_p = 0;
		for(size_t i2 = 0; i2 < a->path_.size() && i2 < b->path_.size(); i2++) {
			char c = a->path_[i2], c2 = b->path_[i2];
			if(i2 >= i_a_p && i2 >= i_b_p && c >= '0' && c <= '9' && c2 >= '0' && c2 <= '9') {
				float f, f2;
				sscanf(a->path_.c_str() + i2, "%f", &f);
				sscanf(b->path_.c_str() + i2, "%f", &f2);
				int i3;
				if(f < f2)
					i3 = -1;
				else if(f > f2)
					i3 = 1;
				else
					i3 = 0;
				//cout << a->path_ << " " << b->path_ << " " << f << "-" << f2 << "=" << i3 << endl;
				if(i3)
					return i3 == -1;
				break;
			}
			if(c != c2)
				break;
		}
	}
	return i < 0;
}

bool list_item___::index_up__(size_t end, size_t begin, bool out_dir_enter_) {
	if(id_ < begin || id_ > end)
		return false;
	if(typ2_ == 'i') {
		if(begin < begin_)
			return false;
		if(out_dir_enter_)
			begin_ = begin + 1;
		end_ = end;
	}
	return true;
}

list_item___::list_item___(const string& path, const string& type, size_t id, char typ2, size_t begin) {
	path_ = path;
	type_ = type;
	id_ = id;
	typ2_ = typ2;
	switch(typ2) {
	case 'e':
		begin_ = begin;
		end_ = id;
		break;
	default:
		begin_ = end_ = 0;
		break;
	}

	bool is_index = false;
	size_t i = path_.rfind("index");
	if(i != string::npos) {
		size_t i2 = path_.rfind("/");
		if(i2 == string::npos || i2 < i)
			is_index = true;
	}
	if(is_index) {
		begin_ = begin;
		typ2_ = 'i';
	}
}

list_item___::~list_item___() {
}

int list_item___::sort_ = -1;
