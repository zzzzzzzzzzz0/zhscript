/*
 * list_cmp.h
 *
 *  Created on: 2016年1月22日
 *      Author: zzzzzzzzzzz
 */

#ifndef LIST_CMP_H_
#define LIST_CMP_H_

#include "gjks.h"

class list_cmp___ {
private:
	size_t row_;

	int type_;
	void on_type_1(bool& ret) {
		if(type_ & 1)
			ret = !ret;
	}
	bool is_index(const string& s2, size_t& i);
	bool cmp_index(const string& s1, const string& s2, size_t i);
	bool on_type_2(const string& s1, const string& s2, bool& ret);
public:
	list_cmp___(size_t row, int type) {
		row_ = row;
		type_ = type;
	}
	bool operator() (vector<string>* i, vector<string>* j);
	list_cmp___(int type) {
		row_ = 0;
		type_ = type;
	}
	bool operator() (const string& s1, const string& s2);
};

#endif /* LIST_CMP_H_ */
