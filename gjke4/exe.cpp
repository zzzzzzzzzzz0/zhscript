/*
 * exe.cpp
 *
 *  Created on: 2011-2-4
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include "for_arg_.h"

#include <sys/ipc.h>
#include <sys/shm.h>
#include<signal.h>
#include <stdio.h>
dlle___ void dlln___(end_fork_eval__)(char*id,char *shm_addr,char *shm2_addr){
	pid_t child_pid;
	int shm_id;
	int shm2_id;
	if(sscanf(id,"%d" " #%d,%d",&child_pid,&shm_id,&shm2_id)!=3)
		return;
	kill(child_pid,SIGKILL);
	shmdt(shm_addr);
	shmctl(shm_id,IPC_RMID,0);
	shmdt(shm2_addr);
	shmctl(shm2_id,IPC_RMID,0);
}
dlle___ int dlln___(fork_eval__)(int*err,char*buf,void*ce,void* shangji,
		const char*code,
		const char*shm_name,
		int shm_size,
		const char*shm2_name,
		int shm2_size,
		int argc,...)
{
	/*_for_args( argc )
	_next_args*/

	key_t key=IPC_PRIVATE;
	int shm_id;
	shm_id = shmget(key,shm_size,IPC_CREAT|0666);
	if(-1 == shm_id){
		//perror("\n");
		return -1;
	}

	char *shm_addr;
	shm_addr = (char*)shmat(shm_id,NULL,0);
	if(shm_addr == (char*)-1){
		//perror("\n");
		return -1;
	}
	char val[32];
	sprintf(val,"%lx",(long)shm_addr);

	int shm2_id;
	shm2_id = shmget(key,shm2_size,IPC_CREAT|0666);
	if(-1 == shm2_id){
		return -1;
	}

	char *shm2_addr;
	shm2_addr = (char*)shmat(shm2_id,NULL,0);
	if(shm2_addr == (char*)-1){
		return -1;
	}
	char val2[32];
	sprintf(val2,"%lx",(long)shm2_addr);

	var_new_(jsq_,shangji,shm_name,val,false,false,false);
	var_new_(jsq_,shangji,shm2_name,val2,false,false,false);
	pid_t child_pid;
	child_pid = fork();
	if(child_pid == 0){
		callback_(jsq_,shangji,err,ce,code,false,NULL,2,val,val2);
	}
	else if(child_pid > 0){
		//执行“kill ‘管道进程’”。
		sprintf(buf," #%d,%d",shm_id,shm2_id);
	}
	return child_pid;
}

int yinhao__(char c,char *cmdline,int& i,char **&argv2,int& argc2){
	int i2=i;
	for(int i1=i+1;;i1++){
		if(!cmdline[i1]||cmdline[i1]==c){
			i=i1;
			break;
		}
	}
	if(!cmdline[i])
		return 1;
	cmdline[i2]=0;
	argv2[argc2]++;
	cmdline[i]=0;
	return 0;
}

dlle___ int dlln___(fork_exec__)(char *cmdline){
	pid_t child_pid;
	child_pid = fork();
	if(child_pid == 0){
		if(cmdline){
			char **argv2=new char*[128];
			int argc2=-1;
			argv2[++argc2]=cmdline;
			for(int i=0;;i++){
				char c=cmdline[i];
				if(!c)
					break;
				if(c==' '){
					cmdline[i]=0;
					argv2[++argc2]=&cmdline[i+1];
					continue;
				}
				if(c=='\n'){
					cmdline[i]=0;
					continue;
				}
				if(c=='\''||c=='"'){
					if(yinhao__(c,cmdline,i,argv2,argc2)==1)
						break;
					continue;
				}
				if(c=='\\'){
					if(!cmdline[i+1])
						break;
					for(int i1=i;;i1++){
						cmdline[i1]=cmdline[i1+1];
						if(!cmdline[i1])
							break;
					}
					continue;
				}
			}
			argv2[++argc2]=NULL;
			/*for(int i=0;;i++){
				if(!argv2[i])
					break;
				cout<<i<<")"<<argv2[i]<<endl;
			}*/
			execvp(argv2[0], argv2);
			delete argv2;
		}
	}
	return child_pid;
}

#include <sys/wait.h>
dlle___ int dlln___(wait_exit_code__)(pid_t child_pid){
	int status;
	waitpid(child_pid,&status,0);
	return WEXITSTATUS(status);
}

#include <spawn.h>
#include <sys/wait.h>
#ifdef __APPLE__
#include <crt_externs.h>
#define environ (*_NSGetEnviron())
#endif
dlle___ void spawn__(char* buf, int argc, ...){
	const char** argv2=new const char*[argc + 1];
	_for_args( argc )
		argv2[i] = s;
	_next_args
	argv2[i] = NULL;

	posix_spawn_file_actions_t sfa;
	posix_spawnattr_t sa;
	posix_spawn_file_actions_init(&sfa);
	posix_spawnattr_init(&sa);

	pid_t pid;
	//int
	posix_spawnp(&pid,argv2[0],&sfa,&sa,(char*const*)argv2,environ);
	sprintf(buf, "%d", pid);

    /*int stat=0;
    waitpid(pid,&stat,0);*/

    delete argv2;
}
