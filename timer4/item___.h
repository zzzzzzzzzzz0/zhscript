/*
 * item___.h
 *
 *  Created on: 2015年3月11日
 *      Author: zzzzzzzzzzz
 */

#ifndef ITEM____H_
#define ITEM____H_

#include <stdio.h>
#include <regex.h>
#include <string>
#include <vector>

using namespace std;

#define d_len_ 7

#define interval_ 500

class item___ {
private:
	unsigned long i_;
	regex_t d_[d_len_];
	void d_free__(int len2);
	int d_len2_;
public:
	string name_;
	int is_loop_;
	string code_;
	char type_;
	bool pause_;
	unsigned long time_;
	string time2_;
	vector<string> args_;
	virtual ~item___();
	void init__();
	int mk_time__(char* time);
	bool begin__(const char* argv[]);
	void end__();
};

#endif /* ITEM____H_ */
