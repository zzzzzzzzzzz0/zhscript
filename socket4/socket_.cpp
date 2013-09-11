#include "socket_.h"
#include "api.h"

socket_::socket_(void)
{
	rw__=new rw_;
	//callback__=0;
}

socket_::~socket_(void)
{
	delete rw__;
}

SOCKET socket_::sockfd___(){
	return sockfd;
}

int socket_::start___(){
#ifdef WIN32
	WORD werd;
	WSADATA wsd;
	werd= MAKEWORD(2,0);
	int i=WSAStartup(werd,&wsd);
	if(i!=0)
		return -(100+i);
#endif

	/* 创建一个 socket 用于 tcp 通信 */
	/*if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Socket");
		return(errno);
	}*/

	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
		return err___("socket");
	}
	return 0;
}

void socket_::stop___(){
	/* 关闭连接 */
	close(sockfd);
#ifdef WIN32
	WSACleanup();
#endif
}

string socket_::ret___(const char* s){
		if(!s)
			return err__;
		return s;
}

string socket_::callback___(string sn){
	if(!callback__ || sn.empty())
		return "";
	int err=0;
	return ret___(callback__(jsq_,shangji_,&err,sn.c_str(),false,0));
}
string socket_::callback___(string sn,string s0){
	if(!callback__ || sn.empty())
		return "";
	int err=0;
	return ret___(callback__(jsq_,shangji_,&err,sn.c_str(),false,1,s0.c_str()));
}
string socket_::callback___(string sn,string s0,string s1){
	if(!callback__ || sn.empty())
		return "";
	int err=0;
	return ret___(callback__(jsq_,shangji_,&err,sn.c_str(),false,2,s0.c_str(),s1.c_str()));
}
string socket_::callback___(string sn,string s0,string s1,string s2){
	if(!callback__ || sn.empty())
		return "";
	int err=0;
	return ret___(callback__(jsq_,shangji_,&err,sn.c_str(),false,3,s0.c_str(),s1.c_str(),s2.c_str()));
}
string socket_::callback___(string sn,string s0,string s1,string s2,string s3){
	if(!callback__ || sn.empty())
		return "";
	int err=0;
	return ret___(callback__(jsq_,shangji_,&err,sn.c_str(),false,4,s0.c_str(),s1.c_str(),s2.c_str(),s3.c_str()));
}
