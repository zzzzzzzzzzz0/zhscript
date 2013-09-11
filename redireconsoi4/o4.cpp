#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include "def1.h"
#include "for_arg_.h"

int get_exit__(int status){
	if (WIFEXITED(status) || WIFSIGNALED(status)) {
		return WEXITSTATUS(status);
	}
	return 260;
}

char ctrl0_ = '\xff';

dlle___ int o4__(int*err,callback2_2___ cb,void*jsq,void*shangji,void*ce,int argc,...){
	if(argc < 2)
		return 265;
	char*script;
	char*script2 = NULL;
	char*cmd;
	_for_args( argc )
		switch(i) {
		case 0:
			script = s;
			break;
		case 1:
			if(argc == 2)
				cmd = s;
			else
				script2 = s;
			break;
		case 2:
			cmd = s;
			break;
		}
	_next_args
	
	fflush(stdout);

	int fd[2];
	pid_t pid;
	if (pipe(fd))
		return 261;
	if ((pid = fork()) == -1)
		return 262;
	int ret = 0;
	if (pid == 0) {
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit(1);
		ret = system(cmd);
		write(STDOUT_FILENO, &ctrl0_, sizeof(ctrl0_));
		write(STDOUT_FILENO, &ret, sizeof(ret));
		exit(0);
	}
	close(fd[1]);
	if(script2) {
		char buf[32];
		sprintf(buf, "%d", pid);
		cb(jsq,shangji,err,ce,script2,false,NULL,2,buf,"p");
		if(*err){
			return 264;
		}
	}
	int err2 = 0;
	std::string buf2;
	for(;;)	{
		char c;
		int count = read( fd[0], &c, sizeof(c) );
		if(count > 0){
			if(c == '\n' || c == '\r') {
				cb(jsq,shangji,err,ce,script,false,NULL,1,buf2.c_str());
				if(*err){
					err2 = 263;
					break;
				}
				buf2.clear();
				continue;
			}
			if(c == ctrl0_) {
				read( fd[0], &ret, sizeof(ret) );
				continue;
			}
			buf2 += c;
			continue;
		}
		break;
	}
	close( fd[0] );
	if(err2)
		return err2;
	if(!buf2.empty()){
		cb(jsq,shangji,err,ce,script,false,NULL,1,buf2.c_str());
	}
	int status;
	pid = waitpid(pid/*-1*/, &status, WNOHANG);
	return get_exit__(ret);
}

/*
dlle___ int o4__(int*err,char*buf,long bufsiz,callback2_2___ cb,void*jsq,void*shangji,void*ce,char*script,char*cmd){
	fflush(stdout);
	int ret=0;
	FILE*f=popen(cmd,"r");
	if(!f)
		ret=261;
	else{
		char*s;
		for(;(s=fgets(buf,bufsiz,f));){
			for(;*s;s++){
				if(*s=='\n'||*s=='\r'){
					*s=0;
					break;
				}
			}
			cb(jsq,shangji,err,ce,script,false,NULL,1,buf);
			if(*err){
				ret=262;
				break;
			}
		}
		int ret2=pclose(f);
		if(ret==0){
			buf[0]=0;
			ret=ret2/256;
		}
	}
	return ret;
}
*/

