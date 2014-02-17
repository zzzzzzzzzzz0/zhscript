/*
 * main.cpp
 *
 *  Created on: 2013-1-23
 *      Author: zzzzzzzzzzz
 */

#include <string>
#include <deque>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "def1.h"
#include "for_arg_.h"
#include "call_util.cpp"
using namespace std;

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
	float l1;
	if(sscanf(s1.c_str() + i1, "%f", &l1) != 1)
		return ret;
	float l2;
	if(sscanf(s2.c_str() + i2, "%f", &l2) != 1)
		return ret;
	//printf("{%u %.1f %.1f}",i,l1,l2);
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
		if(s1[i] < s2[i]) {
			ret = cmp__(s1, s2, i, -1);
			break;
		}
		if(s1[i] > s2[i]) {
			ret = cmp__(s1, s2, i, 1);
			break;
		}
	}
	//printf("{%s %s %d}",s1.c_str(),s2.c_str(),ret);
	return ret;
}

class list_cmp___ {
private:
	size_t row_;

	int type_;
	void on_type_1(bool& ret) {
		if(type_ & 1)
			ret = !ret;
	}
	bool is_index(const string& s2, size_t& i) {
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
	bool cmp_index(const string& s1, const string& s2, size_t i) {
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
	bool on_type_2(const string& s1, const string& s2, bool& ret) {
		if(type_ & 2) {
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
public:
	list_cmp___(size_t row, int type) {
		row_ = row;
		type_ = type;
	}
	bool operator() (vector<string>* i, vector<string>* j) {
		bool ret = false;
		for(;;) {
			if(row_ >= i->size()) {
				ret = false;
				break;
			}
			if(row_ >= j->size()) {
				ret = true;
				break;
			}
			const string& s1 = (*i)[row_];
			const string& s2 = (*j)[row_];
			if(on_type_2(s1, s2, ret))
				return ret;
			if(cmp__(s1, s2) < 0) {
				ret = true;
				break;
			}
			break;
		}
		on_type_1(ret);
		return ret;
	}
	list_cmp___(int type) {
		row_ = 0;
		type_ = type;
	}
	bool operator() (const string& s1, const string& s2) {
		bool ret = false;
		if(on_type_2(s1, s2, ret))
			return ret;
		if(cmp__(s1, s2) < 0)
			ret = true;
		on_type_1(ret);
		return ret;
	}
};

static callback3_2___ cb_;
static void* jsq_;

dlle___ void init__(void* jsq, callback3_2___ cb) {
	jsq_=jsq;
	cb_=cb;
}

static bool ok__(void* p) {
	return p != NULL;
}

dlle___ deque<string>* new_queue__() {
	return new deque<string>();
}

dlle___ void delete_queue__(deque<string>* p) {
	if(!ok__(p))
		return;
	delete p;
}

dlle___ void queue_push__(deque<string>* p, const char* s) {
	if(!ok__(p))
		return;
	p->push_back(s);
}

dlle___ void queue_pop__(char** addr_ret, deque<string>* p) {
	if(!ok__(p) || p->size() == 0)
		return;
	*addr_ret = dup__(p->front().c_str());
	p->pop_front();
}

dlle___ void queue_push_front__(deque<string>* p, const char* s) {
	if(!ok__(p))
		return;
	p->push_front(s);
}

dlle___ void queue_pop_back__(char** addr_ret, deque<string>* p) {
	if(!ok__(p) || p->size() == 0)
		return;
	*addr_ret = dup__(p->back().c_str());
	p->pop_back();
}

dlle___ vector<vector<string>*>* new_list__() {
	return new vector<vector<string>*>();
}

dlle___ void clear_list__(vector<vector<string>*>* p) {
	if(!ok__(p))
		return;
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		delete v;
	}
	p->clear();
}

dlle___ void delete_list__(vector<vector<string>*>* p) {
	clear_list__(p);
	if(!ok__(p))
		return;
	delete p;
}

dlle___ size_t list_length__(vector<vector<string>*>* p, int i1) {
	if(!ok__(p))
		return 0;
	i1--;
	if(i1 < 0)
		return p->size();
	if((size_t)i1 >= p->size())
		return 0;
	return (*p)[i1]->size();
}

dlle___ void list_add__(vector<vector<string>*>* p, int colnum, int argc, ...) {
	if(!ok__(p) || colnum <= 0)
		return;
	int i1 = colnum;
	vector<string>* v;
	_for_args( argc )
		if(i1 >= colnum) {
			v = new vector<string>();
			p->push_back(v);
			i1 = 0;
		}
		v->push_back(s);
		i1++;
	_next_args
}

dlle___ void list_add_by_split__(vector<vector<string>*>* p, int colnum,
		const char* src0, const char* sep0) {
	if(!ok__(p) || colnum <= 0 || !src0 || !sep0)
		return;
	string src = src0, sep = sep0, s;
	if(src.empty() || sep.empty())
		return;
	string::size_type pos_begin = 0;
	int i1 = colnum;
	vector<string>* v;

	while (pos_begin != string::npos)
	{
		string::size_type comma_pos = src.find(sep, pos_begin);
		if (comma_pos != string::npos)
		{
			s = src.substr(pos_begin, comma_pos - pos_begin);
			pos_begin = comma_pos + sep.length();
		}
		else
		{
			s = src.substr(pos_begin);
			pos_begin = comma_pos;
		}

		if(i1 >= colnum) {
			v = new vector<string>();
			p->push_back(v);
			i1 = 0;
		}
		v->push_back(s);
		i1++;
	}
}

dlle___ void list_foreach__(int* err, void*ce, void* shangji,
		bool has_num, vector<vector<string>*>* p, char* code)
{
	if(!ok__(p) || !code) {
		*err = 1;
		return;
	}
	size_t argc = 0;
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		if(argc < v->size())
			argc = v->size();
	}
	const char**argv = new const char*[argc + 1];
	char num[16];
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		argc = v->size();
		size_t add = 0;
		if(has_num) {
			sprintf(num, "%d", i1 + 1);
			argv[0] = num;
			add++;
		}
		for(size_t i = 0; i < argc; i++)
			argv[i + add] = (*v)[i].c_str();
		cb_(jsq_, shangji, err, ce, code, false, NULL, argc + add, argv, 0);
		if(*err)
			break;
	}
	delete argv;
}

dlle___ void list_get__(int* err, char** addr_ret, vector<vector<string>*>* p, char* i1i2) {
	if(!ok__(p)) {
		*err = 1;
		return;
	}
	int i1, i2;
	if(sscanf(i1i2, "%d,%d", &i1, &i2) != 2) {
		*err = 2;
		return;
	}
	i1--;
	i2--;
	if(i1 < 0 || (size_t)i1 >= p->size()) {
		return;
	}
	vector<string>* v = (*p)[i1];
	if(i2 < 0 || (size_t)i2 >= v->size()) {
		return;
	}
	*addr_ret = dup__((*v)[i2].c_str());
}

dlle___ void list_find__(char* buf, vector<vector<string>*>* p, char* s, int i_only) {
	if(!ok__(p) || !s)
		return;
	i_only--;
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		vector<string>* v = (*p)[i1];
		for(size_t i = 0; i < v->size(); i++) {
			if(i_only < 0 || i == (size_t)i_only) {
				if((*v)[i] == s) {
					i1++;
					if(i_only < 0)
						sprintf(buf, "%d,%d", i1, i + 1);
					else
						sprintf(buf, "%d", i1);
					return;
				}
			}
		}
	}
}

dlle___ vector<string>* list_col__(vector<vector<string>*>* p, size_t i) {
	if(!ok__(p))
		return NULL;
	if(--i >= p->size())
		return NULL;
	return (*p)[i];
}

dlle___ void sort_list__(vector<vector<string>*>* p, int row, int type) {
	if(!ok__(p))
		return;
	list_cmp___* lc = new list_cmp___(--row, type);
	sort(p->begin(), p->end(), *lc);
	delete lc;
}

dlle___ void sort_list_col__(vector<string>* p, int type) {
	if(!ok__(p))
		return;
	list_cmp___* lc = new list_cmp___(type);
	sort(p->begin(), p->end(), *lc);
	delete lc;
}
