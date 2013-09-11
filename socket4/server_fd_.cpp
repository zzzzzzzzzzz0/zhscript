#include "server_fd_.h"

server_fd_::server_fd_(SOCKET new_fd,struct sockaddr_in their_addr)
{
				char s1[32];
				char* s2;
				char s3[32];
				sprintf(s1,"%d",new_fd);
				s2=inet_ntoa(their_addr.sin_addr);
				sprintf(s3,"%d",ntohs(their_addr.sin_port));
				s1__=s1;
				s2__=s2;
				s3__=s3;
				fd__=new_fd;
}

server_fd_::~server_fd_()
{
}
