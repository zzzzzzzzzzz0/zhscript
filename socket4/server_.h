#ifndef SERVER__H_
#define SERVER__H_

#include"socket_.h"
#include"server_fd_.h"

class server_ : public socket_
{
private:
	struct sockaddr_in their_addr;
	SOCKET new_fd;
	server_fd_** ss__;
	unsigned int lisnum__;
	int sec__;
	int break___(string& s,server_fd_* fd,server_fd_** ss,int i);
	
public:
	int start___(unsigned int myport,unsigned int lisnum);
	void stop___();
	int while___();
	//int while2___(int sec);
	int while3___(int sec);
	SOCKET accept___();
	char* accept_addr___(){return inet_ntoa(their_addr.sin_addr);}
	int accept_port___(){return ntohs(their_addr.sin_port);}
	//int select___();
	void put___(char* s4);

	string scriptname_i__;
};

#endif /*SERVER__H_*/
