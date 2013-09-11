#pragma once

#include"inc.h"
#include"rw_.h"

class socket_
{
protected:
	SOCKET sockfd;
	int start___();

public:
	socket_(void);
	~socket_(void);
	void stop___();
	rw_* rw__;
	SOCKET sockfd___();
	string callback___(string sn);
	string callback___(string sn,string s0);
	string callback___(string sn,string s0,string s1);
	string callback___(string sn,string s0,string s1,string s2);
	string callback___(string sn,string s0,string s1,string s2,string s3);

	string scriptname__;
	string scriptname_r__;
	string scriptname_w__;
	string scriptname_0__;
private:
	string ret___(const char* s);
};
