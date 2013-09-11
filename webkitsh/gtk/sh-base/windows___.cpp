/*
 * windows___.cpp
 *
 *  Created on: 2013-2-9
 *      Author: zzzzzzzzzzz
 */

#include "windows___.h"
#include <algorithm>

class window_find___ {
private:
	const char* name_;
	window___* w_;
	char type_;
public:
	window_find___() {
		type_ = 'm';
	}
	window_find___(const char* name) {
		name_ = name;
		type_ = 'n';
	}
	window_find___(window___* w) {
		w_ = w;
		type_ = 'w';
	}
    bool operator () (window___* w) {
    	switch(type_) {
    	case 'w':
    		return w->name__() == w_->name__();
    	case 'm':
    		return w->is_main__();
    	}
        return w->name__() == name_;
    }
};

void windows___::push__(window___* w) {
	windows_.push_back(w);
}

void windows___::erase__(window___* w) {
	deque<window___*>::iterator i = find_if(windows_.begin(), windows_.end(), window_find___(w));
	if(i == windows_.end())
		return;
	windows_.erase(i);
}

window___* windows___::get__(const char* name){
	deque<window___*>::iterator i = find_if(windows_.begin(), windows_.end(), window_find___(name));
	if(i == windows_.end())
		return NULL;
	return *i;
}

window___* windows___::main__() {
	deque<window___*>::iterator i = find_if(windows_.begin(), windows_.end(), window_find___());
	if(i == windows_.end())
		return NULL;
	return *i;
}
