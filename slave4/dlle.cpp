#include "slave.h"
#include "def1.h"

slave___ slave_;
callback2___ cb_;
void* jsq_;
void* shangji_;
Glib::ustring script_;

static bool loop__(const Glib::IOCondition& condition) {
	char buf[1024];
	int buf_len = 1024;
	char* p = buf;
	for (; buf_len > 0;) {
		int len = slave_.get__(p, buf_len);
		if (len <= 0)
			break;
		p += len;
		buf_len -= len;
	}
	if (buf_len > 0) {
		*p = 0;
		int err;
		cb_(jsq_, shangji_, &err, script_.c_str(), false, 1, buf);
	}
	return true;
}

dlle___ void init__(callback2___ cb, void* jsq, void* shangji, const char* script) {
	cb_ = cb;
	jsq_ = jsq;
	shangji_ = shangji;
	script_ = script;
	slave_.set_loop__(sigc::ptr_fun(loop__));
}

dlle___ bool start__(const char* filename, const char* args) {
	if(slave_.is_run__())
		return false;
	slave_.start__(filename, args);
	return slave_.is_run__();
}

dlle___ void stop__() {
	slave_.stop__();
}

dlle___ void send__(const char* s) {
	slave_.send__(s);
	slave_.send__("\n");
}

