/*
 * list_cmp.cpp
 *
 *  Created on: 2016年1月22日
 *      Author: zzzzzzzzzzz
 */

#include "list_cmp.h"

static void num_i__(size_t& i, const string& s) {
	for(size_t i1 = i; --i1 >= 0;) {
		if(s[i1] < '0' || s[i1] > '9')
			break;
		i = i1;
	}
}
static int cmp__(const string& s1, const string& s2, size_t i, int ret) {
	size_t i1, i2;
	i1 = i2 = i;
	num_i__(i1, s1);
	num_i__(i2, s2);
	double l1;
	if(sscanf(s1.c_str() + i1, "%lf", &l1) != 1)
		return ret;
	double l2;
	if(sscanf(s2.c_str() + i2, "%lf", &l2) != 1)
		return ret;
	//printf("{%lu %f %f}",i,l1,l2);
	if(l1 > l2)
		return 1;
	if(l1 < l2)
		return -1;
	return 0;
}
static int cmp__(const string& s1, const string& s2) {
	int ret = 0;
	for(size_t i = 0; ; i++) {
		if(i >= s1.length() && i >= s2.length())
			break;
		if(i >= s1.length()) {
			ret = -1;
			break;
		}
		if(i >= s2.length()) {
			ret = 1;
			break;
		}
		unsigned char c1 = s1[i], c2 = s2[i];
		if(c1 < c2) {
			ret = cmp__(s1, s2, i, -1);
			break;
		}
		if(c1 > c2) {
			ret = cmp__(s1, s2, i, 1);
			break;
		}
	}
	//printf("{%s %s %d}",s1.c_str(),s2.c_str(),ret);
	return ret;
}

bool list_cmp___::is_index(const string& s2, size_t& i) {
	i = s2.rfind("index.");
	if(i != string::npos) {
		//printf("{%s %u}",s2.c_str(),i);
		size_t i1 = s2.rfind("/");
		if(i1 != string::npos) {
			if(i1 > i)
				return false;
		}
	}
	return true;
}
bool list_cmp___::cmp_index(const string& s1, const string& s2, size_t i) {
	if(s1.length() <= i)
		return false;
	if(s2.compare(0, i, s1, 0, i) != 0)
		return false;
	size_t i1 = s1.rfind("/");
	if(i1 != string::npos) {
		if(i1 > i)
			return false;
	}
	//printf("{%s}",s1.c_str());
	return true;
}
bool list_cmp___::on_type_2(const string& s1, const string& s2, int type, bool& ret) {
	if(type & 2) {
		size_t i;
		if(is_index(s2, i)) {
			if(cmp_index(s1, s2, i)) {
				return true;
			}
		}
		if(is_index(s1, i)) {
			if(cmp_index(s2, s1, i)) {
				ret = true;
				return true;
			}
		}
	}
	return false;
}
bool list_cmp___::operator() (vector<string>* i, vector<string>* j) {
	bool ret = false;
	int type;
	for(size_t i2 = 0;; i2++) {
		if(i2 >= items_.size()) {
			type = 0;
			break;
		}
		list_cmp_item___* ci = items_[i2];
		size_t row = ci->row_;
		type = ci->type_;
		//printf("%ld %p %ld %d\n",i2,ci,row,type);
		if(row >= i->size()) {
			break;
		}
		if(row >= j->size()) {
			ret = true;
			break;
		}
		const string& s1 = (*i)[row];
		const string& s2 = (*j)[row];
		if(on_type_2(s1, s2, type, ret))
			return ret;
		int i3 = cmp__(s1, s2);
		if(i3 < 0) {
			ret = true;
			break;
		}
		if(i3 > 0) {
			break;
		}
	}
	on_type_1(type, ret);
	return ret;
}
bool list_cmp___::operator() (const string& s1, const string& s2) {
	bool ret = false;
	list_cmp_item___* ci = items_[0];
	if(on_type_2(s1, s2, ci->type_, ret))
		return ret;
	if(cmp__(s1, s2) < 0)
		ret = true;
	on_type_1(ci->type_, ret);
	return ret;
}

/*list_cmp___::~list_cmp___() {
	for(size_t i = 0; i < items_.size(); i++) {
		printf("%ld delete %p\n",i,items_[i]);
		delete items_[i];
	}
}*/
