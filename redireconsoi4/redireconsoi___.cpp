#include "redireconsoi___.h"
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define maxlen 512
#define ctrl0_ '\xff'
#define ctrl1_ '\xff'
#define ctrl2_ '\xff'
#define ctrl3_ '\xff'

redireconsoi___::redireconsoi___()
{
}

redireconsoi___::~redireconsoi___()
{
}

void redireconsoi___::read__(char pResult[],int count,bool has_x_r,char* script){
	bool b=(!script||*script);
	int i_1;
	int err;
	if(char_){
		char s[]={0,0};
		for(int i=0;i<count;i++){
			if(has_x_r && get_x_r__(pResult,count,i,i_1))
				continue;
			if(b){
				s[0]=pResult[i];
				cb2_(jsq_,shangji_,&err,script,false,1,s);
			}
		}
	}else{
		std::string buf_non;
		int i_n=0;
		for(int i=0;i<count;i++){
			if(has_x_r && get_x_r__(pResult,count,i,i_1)){
				if(i_n<i_1){
					pResult[i_1+1]=0;
					cb2_(jsq_,shangji_,&err,script,false,1,pResult+i_n);
				}
				i_n=i+1;
				continue;
			}
			if(b){
				char c=pResult[i];
				if(c=='\n'||c=='\r'){
					pResult[i]=0;
					if(!buf_non.empty()){
						buf_non+=pResult+i_n;
						cb2_(jsq_,shangji_,&err,script,false,1,buf_non.c_str());
						buf_non.clear();
					}else{
						cb2_(jsq_,shangji_,&err,script,false,1,pResult+i_n);
					}
					i_n=i+1;
				}
			}
		}
		if(b){
			if(i_n<count){
				pResult[count]=0;
				buf_non=pResult+i_n;
			}
		}
		if(!buf_non.empty()){
			cb2_(jsq_,shangji_,&err,script,false,1,buf_non.c_str());
		}
	}
}

void redireconsoi___::read__(int fd[],int fd_1[],char pResult[]){
	int count;
	bool b=true;
    while ( b )
    {
    	if(( count = read( fd[0], pResult, maxlen ) )>0){
    		read__(pResult,count,true,script_);
    	}else
    		b=false;
    	if(( count = read( fd_1[0], pResult, maxlen ) )>0){
    		read__(pResult,count,true,script_e_);
    	}
    }
    close( fd[0] );
    close( fd_1[0] );
}

int redireconsoi___::my_system( const char * pCmd, int message )
{
	char pResult[maxlen];
	int fd[2], fd_1[2], fd_2[2];
	pid_t pid;
	int count;
	int i_exit = 0;

	if (message & 2) {
		if (pipe(fd_2))
			return -12;
	}
	if (message & 1) {
		if (pipe(fd))
			return -1;
		if (pipe(fd_1))
			return -1;
	}

	if ((pid = fork()) == -1)
		return -2;

	if (pid == 0) {
		if (message & 2) {
			close(fd_2[1]);
		}
		if (message & 1) {
			close(fd[0]);
			close(fd_1[0]);
		}
		if (message & 2) {
			if (dup2(fd_2[0], STDIN_FILENO) == -1)
				exit(-32);
		}
		if (message & 1) {
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(-3);
			if (dup2(fd_1[1], STDERR_FILENO) == -1)
				exit(-3);
		}
		if (message & 1) {
			bool b=true;
			while (b) {
				count = read(fd[0], pResult, maxlen);
				if (count > 0)
					write(fd[1], pResult, count);
				if (count != maxlen)
					b=false;
				count = read(fd_1[0], pResult, maxlen);
				if (count > 0)
					write(fd_1[1], pResult, count);
			}
		}
		if (message & 2) {
			close(fd_2[0]);
		}
		if (message & 1) {
			close(fd[1]);
			close(fd_1[1]);
		}
		i_exit = system(pCmd);
		if (message & 1) {
			if (script_r_) {
				write( /*fd[1]*/1, pResult,
						sprintf(pResult, "%cx%c%d%c%d%c", ctrl0_, ctrl1_,
								i_exit / 256, ctrl2_, i_exit % 256, ctrl3_));
			}
		}
		exit(i_exit);
	} else {
		// parent process
		if (message & 2) {
			close(fd_2[0]);
		}
		if (message & 1) {
			close(fd[1]);
			close(fd_1[1]);
			if (script_r_) {
				sprintf(pResult, "%d", pid);
				int err;
				cb2_r_(jsq_, shangji_, &err, script_r_, false, 3, pResult, NULL,"p");
			}
		}
		if (message & 2) {
			write(fd_2[1], out_, out_len_);
			close(fd_2[1]);

		}
		if (message & 1) {
			read__(fd, fd_1, pResult);
		}

		int status;
		/*int ret=*/waitpid(pid, &status, WNOHANG);
		if (WIFEXITED(status)) {
			i_exit = status; //ret是个乱数
		}
	}
	return i_exit;
}

bool redireconsoi___::get_x_r__(char* pResult,int count,int& i,int& i_1){
	if(pResult[i]==ctrl0_){
		int i2=i+2;
		if(i2<count && pResult[i2]==ctrl1_){
			i_1=i;
			int i1=++i;
			pResult[++i]=0;
			i2=++i;
			int i3;
			for(;;i++){
				if(i>=count){
					i=i_1;
					return false;
				}
				if(pResult[i]==ctrl2_){
					pResult[i]=0;
					i3=++i;
					break;
				}
			}
			for(;;i++){
				if(i>=count){
					i=i_1;
					return false;
				}
				if(pResult[i]==ctrl3_){
					pResult[i]=0;
					break;
				}
			}
			if(*script_r_){
				int err;
				cb2_r_(jsq_,shangji_,&err,script_r_,false,3,pResult+i2,pResult+i3,pResult+i1);
			}
			--i_1;
			return true;
		}
	}
	return false;
}
