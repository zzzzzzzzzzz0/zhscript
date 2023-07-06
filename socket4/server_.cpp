#include "server_.h"
//#include <pthread.h>
#include "api.h"

int server_::start___(unsigned int myport,unsigned int lisnum)
{
	{int i=socket_::start___();
	if(i!=0)
		return i;
	}

   {
#ifdef WIN32
  	char
#else
		unsigned long
#endif
  	ul = 1;
  	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &ul, sizeof(ul)))
  		err___("setsockopt");
  	}

	struct sockaddr_in my_addr;
	bzero(&my_addr, sizeof(my_addr));
	my_addr.sin_family = PF_INET;
	my_addr.sin_port = htons(myport);
	//if(argv[3]) my_addr.sin_addr.s_addr = inet_addr(argv[3]);
	my_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1) {
		return err___("bind");
	}

	lisnum__=lisnum;
	ss__=new server_fd_*[lisnum__];
	if (listen(sockfd, lisnum) == -1) {
		return err___("listen");
	}

	return 0;
}

void server_::stop___(){
	delete ss__;
	socket_::stop___();
}

SOCKET server_::accept___(){
	socklen_t len;
	len = sizeof(struct sockaddr);
	if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &len)) == -1) {
		err___("accept");
	}
	return new_fd;
}

int server_::while___(){
	while(1) {
		if(accept___()==-1)
			return err___(0);

		if(callback__){
			char s1[32];
			sprintf(s1,"%d",new_fd);
			char s3[32];
			sprintf(s3,"%d",ntohs(their_addr.sin_port));
			callback___(scriptname__
				,""
				,s1
				,inet_ntoa(their_addr.sin_addr)
				,s3
			);
		}else{
			//这是在连接建立成功后向客户端发送的第一个消息\n只能向new_fd这个用accept函数新建立的socket发消息，不能向sockfd这个监听socket发送消息，监听socket不能用来接收或发送消息\n
			int i=rw__->put___("hi",new_fd);
			if(i!=0)
				return i;
			rw__->get___(new_fd);
		}

		//误删除了一句？
		close(new_fd);

		/* 处理每个新连接上的数据收发结束 */
	}
	return 0;
}

int server_::while3___(int sec){
	fd_set rfds,wfds,efds;
	struct timeval tv;
	int retval, maxfd;
	server_fd_** ss=ss__;
	string s;
	unsigned int i;
	for(i=0;i<lisnum__;i++)
		ss[i]=0;
	while (1) {
		FD_ZERO(&rfds);
		FD_ZERO(&wfds);
		FD_ZERO(&efds);

#ifndef WIN32
		FD_SET(0, &rfds);
#endif
		maxfd = 0;
		FD_SET(sockfd, &rfds);
		if (sockfd > maxfd)
			maxfd = sockfd;
		for(i=0;i<lisnum__;i++){
			server_fd_* fd=ss[i];
			if(fd){
				if (fd->fd__ > maxfd)
					maxfd = fd->fd__;
				FD_SET(fd->fd__, &rfds);
				FD_SET(fd->fd__, &wfds);
			}
		}

		if(sec__>=0){
			tv.tv_sec = sec__;
			tv.tv_usec = 0;
		}
		retval = select(maxfd + 1, &rfds, &wfds, &efds, sec__>=0 ? &tv : NULL);
	 	if (retval == -1) {
			return err___("select");
		} else if (retval == 0) {
			s=callback___(scriptname_0__);
			if(break___(s,0,0,0))
					break;
			continue;
		} else {
			if (FD_ISSET(0, &rfds)) {
				put___(rw__->get___());
			}
			else if(FD_ISSET(sockfd, &rfds)){
				if(accept___()==-1)
					return err___(0);

				server_fd_* fd=new server_fd_(new_fd,their_addr);
				s=callback___(scriptname_i__,"",fd->s1__,fd->s2__,fd->s3__);
				if(break___(s,0,0,0)){
					close(new_fd);
					delete fd;
				}else{
					for(i=0;i<lisnum__;i++){
						if(ss[i] == 0){
							ss[i]=fd;
							break;
						}
					}
				}
			}
			else{
				for(i=0;i<lisnum__;i++){
					server_fd_* fd=ss[i];
					if(fd){
						if (FD_ISSET(fd->fd__, &rfds)) {
							s=callback___(scriptname_r__,"",fd->s1__,fd->s2__,fd->s3__);
							break___(s,fd,ss,i);
							s=callback___(scriptname__,"r",fd->s1__,fd->s2__,fd->s3__);
							break___(s,fd,ss,i);
						}
					}
				}
			}
		}
	}
	for(i=0;i<lisnum__;i++){
		server_fd_* fd=ss[i];
		if(fd){
			close(fd->fd__);
			delete fd;
			ss[i]=0;
		}
	}
	return 0;
}

int server_::break___(string& s,server_fd_* fd,server_fd_** ss,int i){
			if(s==end__ || s==err__){
				if(fd)
					close(fd->fd__);
				if(ss)
					ss[i]=0;
				if(s==err__)
					err___(s.c_str(),"调用返回空值",-1);
				return 1;
			}
			return 0;
}

void server_::put___(char* s4){
	string s;
	for(unsigned int i=0;i<lisnum__;i++){
		server_fd_* fd=ss__[i];
		if(fd){
			s=callback___(scriptname_w__,"",fd->s1__,s4);
			break___(s,fd,ss__,i);
			s=callback___(scriptname__,"w",fd->s1__,s4);
			break___(s,fd,ss__,i);
		}
	}
}

/*int server_::select___(){
    fd_set rfds;
    struct timeval tv;
    int retval, maxfd = -1;

					char s1[32];
					sprintf(s1,"%d",new_fd);
					//printf("new_fd=%s\n",s1);
					char* s2=inet_ntoa(their_addr.sin_addr);
					char s3[32];
					sprintf(s3,"%d",ntohs(their_addr.sin_port));

					if(callback___(scriptname_i__,"",s1,s2,s3)==end__){
						close(new_fd);
						return 0;
					}
        while (1) {
            //把集合清空
            FD_ZERO(&rfds);
            // 把标准输入句柄0加入到集合中
            FD_SET(0, &rfds);
            maxfd = 0;
            // 把当前连接句柄new_fd加入到集合中
            FD_SET(new_fd, &rfds);
            if (new_fd > maxfd)
                maxfd = new_fd;

            // 设置最大等待时间
            if(sec__>=0){
            	tv.tv_sec = sec__;
            	tv.tv_usec = 0;
            					}
           // 开始等待
            retval = select(maxfd + 1, &rfds, NULL, NULL, sec__>=0 ? &tv : NULL);
            if (retval == -1) {
            			return err___("select");
            } else if (retval == 0) {
                continue;
            } else {
               if (FD_ISSET(0, &rfds)) {
                   // 用户按键了，则读取用户输入的内容发送出去
       								char* s4=rw__->get___();
												if(callback___(scriptname_w__,"",s1,s4)==end__)
													break;
												if(callback___(scriptname__,"w",s1,s4)==end__)
													break;
                						}
	              if (FD_ISSET(new_fd, &rfds)) {
												if(callback___(scriptname_r__,"",s1,s2,s3)==end__)
														break;
												if(callback___(scriptname__,"r",s1,s2,s3)==end__)
														break;
                    					}
                				}
            		}
        close(new_fd);
        return 0;
}

static server_* s__;
static void* thread_prog___(void* arg){
	server_* s=s__;
	s->select___();
	return 0;
}

int server_::while2___(int sec){
			sec__=sec;
			while(1) {
					if(accept___()==-1)
						return err___(0);

 					pthread_t tA;
 					s__=this;
					int ret;
					ret=pthread_create(
						&tA,
						NULL,
						thread_prog___,
						NULL);
					if(ret!=0){
						printf ("pthread %d!\n",ret);
						//return ret;
					}
					//pthread_join(t,NULL);
					//select___(NULL);
			}
			return 0;
}*/
