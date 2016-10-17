/*
 * callback_item___.h
 *
 *  Created on: 2016年1月29日
 *      Author: zzzzzzzzzzz
 */

#ifndef SH_BASE_CALLBACK_ITEM____H_
#define SH_BASE_CALLBACK_ITEM____H_
#include <string>
using namespace std;

class callback_item___ {
public:
	size_t id_;
	string title_, tooltip_;
	string code_, arg_;
	string code2_, arg2_;
	int argc_;
	void *data_, *data2_;
	int i_;
	callback_item___() {
		argc_ = 1;
		init__(false);
	}
	callback_item___(const string& code) {
		code_ = code;
		argc_ = 1;
		init__(true);
	}
	callback_item___(const string& title, const string& code) {
		title_ = title;
		code_ = code;
		argc_ = 1;
		init__(true);
	}
	callback_item___(const string& title, const string& code, const string& arg, const string& tooltip) {
		title_ = title;
		code_ = code;
		arg_ = arg;
		tooltip_ = tooltip;
		argc_ = 3;
		init__(true);
	}
	virtual ~callback_item___();
	void call__(int i = 0, const char* arg2 = NULL, const char* code3 = NULL, void* shangji = NULL, void* ce = NULL);
private:
	void init__(bool has_id);
};

extern callback_item___* callback_item__(int id);
extern void call_item__(int id, int i = 0, const char* code3 = NULL, void* shangji = NULL, void* ce = NULL);

#endif /* SH_BASE_CALLBACK_ITEM____H_ */
