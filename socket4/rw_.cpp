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
	/* ���տͻ��˵���Ϣ */
	/*len = recv(new_fd, buf, MAXBUF, 0);
	if(len > 0);
	else {
		printf("recv: %s\n", strerror(errno));
		return errno;
	}*/
	int len;
	/* ���նԷ�����������Ϣ�������� MAXBUF ���ֽ� */
	bzero(buffer__, MAXBUF + 1);
	/* ���շ�����������Ϣ */
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
	/*// ��ʼ����ÿ���������ϵ������շ�
	bzero(buf, MAXBUF + 1);
	strcpy(buf, "���������ӽ����ɹ�����ͻ��˷��͵ĵ�һ����Ϣ\nֻ����new_fd�����accept�����½�����socket����Ϣ��������sockfd�������socket������Ϣ������socket�����������ջ�����Ϣ\n");
	// ����Ϣ���ͻ���
	len = send(new_fd, buf, strlen(buf), 0);
	if(len < 0) {
		printf("send: %s\n", strerror(errno));
		return(errno);
	}*/
	int len;
	/*bzero(buffer__, MAXBUF + 1);
	strcpy(buffer__, s);*/
	/* ����Ϣ�������� */
	len = send(sockfd, /*buffer__*/s, strlen(/*buffer__*/s), 0);
	if(len < 0) {
		return err___("send");
	}
	return 0;
}
