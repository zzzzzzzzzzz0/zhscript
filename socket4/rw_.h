#ifndef RW__H_
#define RW__H_

#include"inc.h"

class rw_
{
public:
	rw_();
	virtual ~rw_();
	char* get___(SOCKET sockfd);
	char* get___();
	int put___(char* s,SOCKET sockfd);
	char* buffer__;
};

#endif /*RW__H_*/
