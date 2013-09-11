/*
 * item___.h
 *
 *  Created on: 2013-2-16
 *      Author: zzzzzzzzzzz
 */

#ifndef ITEM____H_
#define ITEM____H_

#include "arg___.h"
#include <string>
using namespace std;
#include <glib.h>

class item___ {
private:
	string name_;
	bool is_loop_;
	string code_;
	guint id_;
	bool pause_;
public:
	arg___ arg_;

	item___(char* name, bool is_loop) {
		name_ = name;
		is_loop_ = is_loop;
		pause_ = false;
		id_ = 0;
	}
	virtual ~item___();

	void code__(char* code) {code_ = code;}
	void id__(guint id) {id_ = id;}
	void pause__(bool b) {pause_ = b;}
	void on__();
	void stop__();
	const string& name__() {return name_;}
};

#endif /* ITEM____H_ */
