#ifndef slave_h_
#define slave_h_

#ifdef ver_glibmmm_
#include "glibmmm.h"
#else
#include <glibmm.h>
#endif
#include <unistd.h>

class slave___ {
private:
	int sv_[2];
	sigc::slot<bool, Glib::IOCondition> loop_;
	sigc::connection in_, wait_;
	int pid_;
	bool is_run_;
	
	void wait__(GPid pid, int);
public:
	slave___():is_run_(false) {}
	ssize_t get__(char* buf, size_t len) {
		return read(sv_[0], buf, len);
	}
	void set_loop__(const sigc::slot<bool, Glib::IOCondition>& loop) {
		loop_ = loop;
	}
	void start__(const char* filename, const char* args);
	bool is_run__() {
		return is_run_;
	}
	void stop__();
	void send__(const char* s);
};

#endif
