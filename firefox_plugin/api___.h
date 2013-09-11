#ifndef api____h_
#define api____h_
#include<string>
#include<iostream>
#include<deque>
using namespace std;
#include "l4/l4___.hh"

class api___{
public:
	api___();
	~api___();
	bool new__(int argc, char* argn[], char* argv[],void*cp);
	const char* cmd__(const char*s,void*spo);
	void api__(deque<string>* p,char*buf,long siz,char**addr_ret);
	void jieshi__(){l4_.jieshi__();}
private:
	int l4__(const char* so_dir,string& cmdline);
	void l4_err_show__(int err);
	void*cp_;

	string url_,url_query_;
	void get_url__();

	/*static*/ l4___ l4_;
	int set_suidao__();
};

#endif
