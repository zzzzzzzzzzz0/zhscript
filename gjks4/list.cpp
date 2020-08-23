/*
 * list.cpp
 *
 *  Created on: 2016年1月22日
 *      Author: zzzzzzzzzzz
 */
#include "list_cmp.h"
#include "strlen_sp.h"

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
	vector<string>* v = NULL;
	_for_args( argc )
		if(i1 >= colnum) {
			v = new vector<string>();
			p->push_back(v);
			i1 = 0;
		}
		v->push_back(s ? s : "NULL");
		i1++;
	_next_args
}

dlle___ void list_add_by_split__(vector<vector<string>*>* p, int colnum,
		const char* src0, const char* sep0, int argc, ...) {
	if(!ok__(p) || colnum <= 0 || !src0 || !sep0)
		return;

	bool can_empty = true;
	_for_args( argc )
		if(s && s[0] == 'n' && !s[1]) {
			can_empty = false;
		} else {
			return;
		}
	_next_args

	string src = src0, sep = sep0, s;
	if(src.empty() || sep.empty())
		return;
	string::size_type pos_begin = 0;
	int i1 = colnum;
	vector<string>* v = NULL;

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

		if(can_empty || (!can_empty && !s.empty())) {
			if(i1 >= colnum) {
				v = new vector<string>();
				p->push_back(v);
				i1 = 0;
			}
			v->push_back(s);
			i1++;
		}
	}
}

dlle___ void list_foreach__(int* err, char** addr_ret, void*ce, void* shangji,
		bool has_num, bool is_reverse, vector<vector<string>*>* p, char* code)
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
	string ret2;
	int i1 = is_reverse ? p->size() - 1 : 0;
	for(unsigned i11 = 0; i1 < (int)p->size() && i1 >= 0;) {
		vector<string>* v = (*p)[i1];
		argc = v->size();
		size_t add = 0;
		if(has_num) {
			sprintf(num, "%u", ++i11);
			argv[0] = num;
			add++;
		}
		for(size_t i = 0; i < argc; i++)
			argv[i + add] = (*v)[i].c_str();
		const char *ret = cb_(jsq_, shangji, err, ce, code, false, NULL, argc + add, argv, 0);
		if(addr_ret && ret)
			ret2 += ret;
		if(*err == jieshiqi_err_go_+keyword_continue_) {
			*err=0;
		}
		else if(*err == jieshiqi_err_go_+keyword_break_) {
			*err=0;
			break;
		}
		else if(*err)
			break;
		if(is_reverse)
			i1--;
		else
			i1++;
	}
	delete argv;
	if(addr_ret)
		*addr_ret = dup__(ret2.c_str());
}

dlle___ void list_foreach2__(int* err, char** addr_ret, void*ce, void* shangji,
		bool has_num, bool is_reverse, char* code, int argc, ...) {
	string ret2;
	_for_args1( argc )
		list_foreach__(err, addr_ret, ce, shangji, has_num, is_reverse, va_arg(argv, vector<vector<string>*>*), code);
		if(addr_ret) {
			ret2 += *addr_ret;
			delete *addr_ret;
		}
		if(*err) break;
	_next_args
	if(addr_ret)
		*addr_ret = dup__(ret2.c_str());
}

static vector<string>* list_get__(int* err, vector<vector<string>*>* p,
		char* i1i2, int* i1, int* i2) {
	if(!ok__(p) || !i1i2) {
		*err = 1;
		return NULL;
	}
	if(sscanf(i1i2, "%d,%d", i1, i2) != 2) {
		*err = 2;
		return NULL;
	}
	(*i1)--;
	(*i2)--;
	if(*i1 < 0 || (size_t)*i1 >= p->size()) {
		return NULL;
	}
	vector<string>* v = (*p)[*i1];
	if(*i2 < 0 || (size_t)*i2 >= v->size()) {
		return NULL;
	}
	return v;
}

dlle___ void list_get__(int* err, vector<string>* ret, vector<vector<string>*>* p, int argc, ...) {
	int i1, i2;
	_for_args( argc ) {
		vector<string>* v = list_get__(err, p, s, &i1, &i2);
		if(v)
			ret->push_back((*v)[i2]);
		else
			ret->push_back("");
	} _next_args
}

dlle___ void list_set__(int* err, vector<vector<string>*>* p, char* i1i2, char* s) {
	if(!s) {
		*err = 1;
		return;
	}
	int i1, i2;
	vector<string>* v = list_get__(err, p, i1i2, &i1, &i2);
	if(!v) {
		return;
	}
	(*v)[i2] = s;
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
						sprintf(buf, "%u,%u", (unsigned)i1, (unsigned)i + 1);
					else
						sprintf(buf, "%u", (unsigned)i1);
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

dlle___ void sort_list__(vector<vector<string>*>* p, int row, int type, int argc, ...) {
	if(!ok__(p))
		return;
	if(argc % 2 != 0)
		return;
	list_cmp___ lc(--row, type);
	{
		va_list argv;
		va_start(argv, argc);
		for(int i = 0; i < argc; i += 2) {
			int row2, type2;
			bool b1 = (sscanf(va_arg(argv, char*), "%d", &row2) == 1);
			bool b2 = (sscanf(va_arg(argv, char*), "%d", &type2) == 1);
			if(b1 && b2)
				lc.items_add__(--row2, type2);
			else
				return;
		}
		va_end(argv);
	}
	sort(p->begin(), p->end(), lc);
}

dlle___ void sort_list_col__(vector<string>* p, int type) {
	if(!ok__(p))
		return;
	list_cmp___* lc = new list_cmp___(type);
	sort(p->begin(), p->end(), *lc);
	delete lc;
}

void list_to_1_get_max__(vector<string>* v, size_t& max) {
	if(max < v->size())
		max = v->size();
}
void list_to_1_get_max_s__(vector<string>* v, size_t i, size_t& s) {
	if(i < v->size()) {
		size_t s2 = strlen_sp__((*v)[i]);
		if(s < s2) {
			s = s2;
		}
	}
}
void list_to_1_set_buf__(string* s, bool head, bool center, bool right, bool num_right, size_t max_s, string& buf) {
	size_t cnt = 0;
	if(s) {
		cnt = strlen_sp__(*s);
		if(!right && num_right) {
			for(size_t i2 = 0;; i2++) {
				if(i2 >= cnt) {
					right = true;
					break;
				}
				char c = (*s)[i2];
				if(!(c >= '0' && c <= '9'))
					break;
			}
		}
	}
	char c = head ? '-' : (s ? ' ' : '\\');
	if(center) {
		size_t i2 = (max_s - cnt) / 2;
		for(size_t i = 0; i < i2; i++)
			buf += c;
		if(s)
			buf += *s;
		i2 = max_s - cnt - i2;
		for(size_t i = 0; i < i2; i++)
			buf += c;
	} else {
		if(s && !right)
			buf += *s;
		for(; cnt < max_s; cnt++)
			buf += c;
		if(s && right)
			buf += *s;
	}
	buf += "|";
}
void list_to_1_set_buf__(vector<string>* v, bool head, bool center, bool right, bool num_right, size_t max, const vector<size_t>& max_s, string& buf) {
	for(size_t i = 0; i < max; i++) {
		list_to_1_set_buf__(i < v->size() ? &(*v)[i] : NULL, head, center, right, num_right, max_s[i], buf);
	}
	buf += "\n";
}
dlle___ void list_to_1__(char**addr_ret, vector<vector<string>*>* p, int argc, ...) {
	if(!ok__(p))
		return;

	vector<string> head;
	_for_args( argc )
		head.push_back(s ? s : "");
	_next_args

	size_t max = 0;
	list_to_1_get_max__(&head, max);
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		list_to_1_get_max__((*p)[i1], max);
	}

	vector<size_t> max_s;
	for(size_t i = 0; i < max; i++) {
		size_t s = 0;
		list_to_1_get_max_s__(&head, i, s);
		for(size_t i1 = 0; i1 < p->size(); i1++) {
			list_to_1_get_max_s__((*p)[i1], i, s);
		}
		max_s.push_back(s);
	}

	char num[16];
	sprintf(num, "%u", (unsigned)(p->size()));
	string num2 = num;
	size_t max_s2 = num2.size();

	string buf;
	list_to_1_set_buf__(NULL, true, false, false, false, max_s2, buf);
	list_to_1_set_buf__(&head, true, true, true, false, max, max_s, buf);
	for(size_t i1 = 0; i1 < p->size(); i1++) {
		sprintf(num, "%u", (unsigned)i1 + 1);
		num2 = num;
		list_to_1_set_buf__(&num2, false, false, false, true, max_s2, buf);
		list_to_1_set_buf__((*p)[i1], false, false, false, true, max, max_s, buf);
	}
	*addr_ret = dup__(buf.c_str());
}
