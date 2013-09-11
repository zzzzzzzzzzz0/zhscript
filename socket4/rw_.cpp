#include "rw_.h"

#define MAXBUF 1024

rw_::rw_()
{
	buffer__=new char [MAXBUF + 1];
}

rw_::~rw_()
{
	delete buffer__;
}

char* rw_::get___(SOCKET sockfd){
	//bzero(buf, MAXBUF + 1);
	/* 接收客户端的消息 */
	/*len = recv(new_fd, buf, MAXBUF, 0);
	if(len > 0);
	else {
		printf("recv: %s\n", strerror(errno));
		return errno;
	}*/
	int len;
	/* 接收对方发过来的消息，最多接收 MAXBUF 个字节 */
	bzero(buffer__, MAXBUF + 1);
	/* 接收服务器来的消息 */
	len = recv(sockfd, buffer__, MAXBUF, 0);
	if(len < 0)
	{
		err___("recv");
		return 0;
	}
	if(len == 0)
	{
		return 0;
	}
	return buffer__;
}

char* rw_::get___(){
	bzero(buffer__, MAXBUF + 1);
	return fgets(buffer__, MAXBUF, stdin);
}

int rw_::put___(char* s,SOCKET sockfd){
	/*// 开始处理每个新连接上的数据收发
	bzero(buf, MAXBUF + 1);
	strcpy(buf, "这是在连接建立成功后向客户端发送的第一个消息\n只能向new_fd这个用accept函数新建立的socket发消息，不能向sockfd这个监听socket发送消息，监听socket不能用来接收或发送消息\n");
	// 发消息给客户端
	len = send(new_fd, buf, strlen(buf), 0);
	if(len < 0) {
		printf("send: %s\n", strerror(errno));
		return(errno);
	}*/
	int len;
	/*bzero(buffer__, MAXBUF + 1);
	strcpy(buffer__, s);*/
	/* 发消息给服务器 */
	len = send(sockfd, /*buffer__*/s, strlen(/*buffer__*/s), 0);
	if(len < 0) {
		return err___("send");
	}
	return 0;
}
