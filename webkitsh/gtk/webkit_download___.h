/*
 * webkit_download___.h
 *
 *  Created on: 2013-4-6
 *      Author: zzzzzzzzzzz
 */

#ifndef WEBKIT_DOWNLOAD____H_
#define WEBKIT_DOWNLOAD____H_

#include "webkit_view___.h"
#include <deque>

class webkit_download___ {
public:
	webkit_download___();
	virtual ~webkit_download___();
	int add__(WebKitWebView* wv, deque<string>* p);
	void signal__(WebKitWebView* wv);
	bool is_add__(WebKitWebView* wv);
};

#endif /* WEBKIT_DOWNLOAD____H_ */
