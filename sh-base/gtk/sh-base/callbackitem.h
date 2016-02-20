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
	callback_item___(const string& code) {
		code_ = code;
		argc_ = 1;
		init__();
	}
	callback_item___(const string& title, const string& code) {
		title_ = title;
		code_ = code;
		argc_ = 1;
		init__();
	}
	callback_item___(const string& title, const string& code, const string& arg, const string& tooltip) {
		title_ = title;
		code_ = code;
		arg_ = arg;
		tooltip_ = tooltip;
		argc_ = 3;
		init__();
	}
	virtual ~callback_item___();
	void call__(int i = 0, const char* arg2 = NULL);
private:
	void init__();
};

extern callback_item___* callback_item__(int id);
extern void call_item__(int id, int i = 0);

#endif /* SH_BASE_CALLBACK_ITEM____H_ */
