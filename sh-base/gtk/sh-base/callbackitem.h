/*
 * callback_item___.h
 *
 *  Created on: 2016年1月29日
 *      Author: zzzzzzzzzzz
 */

#ifndef SH_BASE_CALLBACK_ITEM____H_
#define SH_BASE_CALLBACK_ITEM____H_
#include <string>
#include <deque>
using namespace std;

class callback_item___ {
public:
	size_t id_;
	string title_, tooltip_;
	int argc_;
	int i_;
	callback_item___() {
		argc_ = 1;
		init__(false);
	}
	callback_item___(const string& code) {
		add_code__(code);
		argc_ = 1;
		init__(true);
	}
	callback_item___(const string& title, const string& code) {
		title_ = title;
		add_code__(code);
		argc_ = 1;
		init__(true);
	}
	callback_item___(const string& title, const string& code, const string& arg, const string& tooltip) {
		title_ = title;
		add_code__(code);
		add_arg__(arg);
		tooltip_ = tooltip;
		argc_ = 3;
		init__(true);
	}
	virtual ~callback_item___();
	void add_code__(const string& code) {codes_.push_back(code);}
	void add_arg__(const string& arg) {args_.push_back(arg);}
	void add_data__(void* data) {datas_.push_back(data);}
	const char* code__(int i) {return get__(codes_, i);}
	const char* arg__(int i) {return get__(args_, i);}
	void* data__(int i);
	void data__(int i, void* data);
	void call__(int i = 0, const char* arg2 = NULL, const char* code3 = NULL, void* shangji = NULL, void* ce = NULL);
private:
	deque<string> codes_, args_;
	deque<void*> datas_;
	void init__(bool has_id);
	const char* get__(const deque<string> &a, int i);
};

extern callback_item___* callback_item__(int id);
extern void call_item__(int id, int i = 0, const char* code3 = NULL, void* shangji = NULL, void* ce = NULL);

#endif /* SH_BASE_CALLBACK_ITEM____H_ */
