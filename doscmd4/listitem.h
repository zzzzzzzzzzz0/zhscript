/*
 * listitem.h
 *
 *  Created on: 2017年12月24日
 *      Author: zzzzzzzzzzz
 */

#ifndef LISTITEM_H_
#define LISTITEM_H_

#include<string>
using namespace std;

class list_item___ {
public:
	list_item___(const string& path, const string& type, char typ2);
	virtual ~list_item___();

	string path_, type_;
	void get__(char c, char*buf,long siz);

	static int sort_;
	static bool comp__(list_item___* a, list_item___* b);
private:
	char typ2_;
	string dir_;
	bool range__(list_item___* b);
	bool begin__(list_item___* b);
	bool index_begin__(list_item___* b);
};

#endif /* LISTITEM_H_ */
