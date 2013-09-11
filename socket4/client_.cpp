#include "client_.h"

int client_::start___(int argv2,char* argv1)
{
	{int i=socket_::start___();
	if(i!=0)
		return i;
	}

	struct sockaddr_in dest;
	/* ��ʼ���������ˣ��Է����ĵ�ַ�Ͷ˿���Ϣ */
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(argv2);
	struct hostent *host=gethostbyname(argv1);
	if(host!=NULL){
		dest.sin_addr = *((struct in_addr *)host->h_addr);
	}else{
#ifdef WIN32
	if ((dest.sin_addr.s_addr = inet_addr(argv1)) == -1) {
		return -1;
	}
#else
	if (inet_aton(argv1, (struct in_addr *) &dest.sin_addr.s_addr) == 0) {
		return err___(argv1);
	}
#endif
	}
	//printf("%s:%d\n",inet_ntoa(dest.sin_addr),ntohs(dest.sin_port));

	/* ���ӷ����� */
	if (connect(sockfd, (struct sockaddr *) &dest, sizeof(dest)) != 0) {
		return err___("Connect");
	}

	return 0;
}

int client_::while___(int sec){
    fd_set rfds;
    struct timeval tv;
    int retval, maxfd = -1;
	string s;
	char* s1;
    while (1) {
        /* �Ѽ������ */
        FD_ZERO(&rfds);
        /* �ѱ�׼������0���뵽������ */
#ifndef WIN32
        FD_SET(0, &rfds);
#endif
        maxfd = 0;
        /* �ѵ�ǰ���Ӿ��sockfd���뵽������ */
        FD_SET(sockfd, &rfds);
        if (sockfd > maxfd)
            maxfd = sockfd;
        /* �������ȴ�ʱ�� */
        if(sec>=0){
        	tv.tv_sec = sec;
        	tv.tv_usec = 0;
        			}
        /* ��ʼ�ȴ� */
    			//printf("sec=%d\n",sec);
        retval = select(maxfd + 1, &rfds, NULL, NULL, sec>=0 ? &tv : NULL);
        if (retval == -1) {
            return err___("select");
        } else if (retval == 0) {
			s=callback___(scriptname_0__);
			if(s==end__ || s==err__)
					break;
            continue;
        } else {
            if (FD_ISSET(sockfd, &rfds)) {
                /* ���ӵ�socket������Ϣ��������նԷ�����������Ϣ����ʾ */
				s=callback___(scriptname_r__);
				if(s==end__ || s==err__)
						break;
				s=callback___(scriptname__,"r");
				if(s==end__ || s==err__)
						break;
                				}
            if (FD_ISSET(0, &rfds)) {
                /* �û������ˣ����ȡ�û���������ݷ��ͳ�ȥ */
       			s1=rw__->get___();
       			//printf("s1=%s\n",s1);
				s=callback___(scriptname_w__,"",s1);
				if(s==end__ || s==err__)
						break;
				s=callback___(scriptname__,"w",s1);
				if(s==end__ || s==err__)
						break;
			}
		}
	}
	if(s==err__){
			return err___(s.c_str(),"���÷��ؿ�ֵ",-1);
	}
	return 0;
}

