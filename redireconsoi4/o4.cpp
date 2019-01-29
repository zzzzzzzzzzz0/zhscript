#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include "def1.h"
#include "for_arg_.h"
#include "l4/keyword.h"

int get_exit__(int status){
	if (WIFEXITED(status) || WIFSIGNALED(status)) {
		return WEXITSTATUS(status);
	}
	return 260;
}

int cb_err__(int* err) {
	if(*err == jieshiqi_err_go_+keyword_continue_) {
		*err=0;
		return -1;
	}
	if(*err == jieshiqi_err_go_+keyword_break_) {
		*err=0;
		return 2;
	}
	if(*err)
		return 3;
	return 0;
}

char ctrl0_ = '\xff';

dlle___ int o4__(int*err,callback2_2___ cb,void*jsq,void*shangji,void*ce,int argc,...){
	if(argc < 2)
		return 265;
	std::string no = "0";
	std::string script, script_err, script_info;
	char*cmd;
	_for_args( argc )
		switch(i) {
		case 0:
			if(s) script = s;
			break;
		case 1:
			if(argc == 2)
				cmd = s;
			else
				if(s) script_info = s;
			break;
		case 2:
			if(argc == 3)
				cmd = s;
			else
				if(s) script_err = s;
			break;
		case 3:
			cmd = s;
			break;
		}
	_next_args
	if(!cmd)
		return 265;
	if(script.empty())
		return 265;
	
	fflush(stdout);

	int fd[2], fd_err[2];
	if (pipe(fd))
		return 261;
	if(!script_err.empty())
		if (pipe(fd_err))
			return 261;
	pid_t pid;
	if ((pid = fork()) == -1)
		return 262;
	int ret = 0;
	if (pid == 0) {
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit(1);
		if(!script_err.empty()) {
			close(fd_err[0]);
			if (dup2(fd_err[1], STDERR_FILENO) == -1)
				exit(1);
		}
		ret = system(cmd);
		write(STDOUT_FILENO, &ctrl0_, sizeof(ctrl0_));
		write(STDOUT_FILENO, &ret, sizeof(ret));
		exit(0);
	}
	close(fd[1]);
	if(!script_err.empty())
		close(fd_err[1]);
	if(!script_info.empty()) {
		char buf[32];
		sprintf(buf, "%d", pid);
		cb(jsq,shangji,err,ce,script_info.c_str(),false,NULL,2,buf,"p");
		if(cb_err__(err) > 0){
			return 264;
		}
	}
	int err2 = 0;
	std::string buf2, buf2_err;
	for(;;)	{
		char c;
		int count = 0;
		if(script != no) {
			count = read( fd[0], &c, sizeof(c) );
			if(count > 0){
				if(c == '\n' || c == '\r') {
					cb(jsq,shangji,err,ce,script.c_str(),false,NULL,1,buf2.c_str());
					if(cb_err__(err) > 0){
						err2 = 263;
						break;
					}
					buf2.clear();
				} else if(c == ctrl0_) {
					read( fd[0], &ret, sizeof(ret) );
				} else
					buf2 += c;
			}
		}
		int count_err = 0;
		if(!script_err.empty() && script_err != no) {
			count_err = read( fd_err[0], &c, sizeof(c) );
			if(count_err > 0){
				if(c == '\n' || c == '\r') {
					cb(jsq,shangji,err,ce,script_err.c_str(),false,NULL,1,buf2_err.c_str());
					if(cb_err__(err) > 0){
						err2 = 263;
						break;
					}
					buf2_err.clear();
				} else
					buf2_err += c;
			}
		}
		if(count <= 0 && count_err <= 0)
			break;
	}
	close( fd[0] );
	if(!script_err.empty())
		close( fd_err[0] );
	if(err2)
		return err2;
	if(!buf2.empty()){
		cb(jsq,shangji,err,ce,script.c_str(),false,NULL,1,buf2.c_str());
	}
	if(!buf2_err.empty() && script_err != no){
		cb(jsq,shangji,err,ce,script_err.c_str(),false,NULL,1,buf2_err.c_str());
	}
	int status;
	pid = waitpid(pid/*-1*/, &status, WNOHANG);
	return get_exit__(ret);
}
