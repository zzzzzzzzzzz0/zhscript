#ifndef SERVER_FD__H_
#define SERVER_FD__H_
#include"inc.h"

class server_fd_
{
public:
	server_fd_(SOCKET new_fd,struct sockaddr_in their_addr);
	virtual ~server_fd_();
	string s1__;
	string s2__;
	string s3__;
	SOCKET fd__;
};

#endif /*SERVER_FD__H_*/
