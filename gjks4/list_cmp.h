/*
 * list_cmp.h
 *
 *  Created on: 2016年1月22日
 *      Author: zzzzzzzzzzz
 */

#ifndef LIST_CMP_H_
#define LIST_CMP_H_

#include "gjks.h"

class list_cmp_item___ {
public:
	size_t row_;
	int type_;
	list_cmp_item___(size_t row, int type) : row_(row), type_(type) {}
};

class list_cmp___ {
private:
	vector<list_cmp_item___*> items_;
	bool is_index(const string& s2, size_t& i);
	bool cmp_index(const string& s1, const string& s2, size_t i);
	void on_type_1(int type, bool& ret) {
		if(type & 1)
			ret = !ret;
	}
	bool on_type_2(const string& s1, const string& s2, int type, bool& ret);
public:
	//~list_cmp___();
	void items_add__(size_t row, int type) {
		items_.push_back(new list_cmp_item___(row, type));
	}
	list_cmp___(size_t row, int type) {
		items_add__(row, type);
	}
	bool operator() (vector<string>* i, vector<string>* j);
	list_cmp___(int type) {
		items_add__(0, type);
	}
	bool operator() (const string& s1, const string& s2);
};

#endif /* LIST_CMP_H_ */
