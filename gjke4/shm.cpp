/*
 * shm.cpp
 *
 *  Created on: 2013-2-12
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "for_arg_.h"

#define id_fmt_ "%p,%d,%d"

static bool shm_id__(char*id, char*& shm_addr, int& shm_id, key_t& shm_key) {
	return sscanf(id, id_fmt_, &shm_addr, &shm_id, &shm_key) == 3;
}

dlle___ void delete_shm__(int argc,...) {
	char *shm_addr;
	int shm_id;
	key_t shm_key;
	_for_args( argc )
		if(!shm_id__(s, shm_addr, shm_id, shm_key))
			continue;
		shmdt(shm_addr);
		shmctl(shm_id,IPC_RMID,0);
	_next_args
}

static void get__(key_t shm_key, size_t shm_size, int shm_flg, char *shm_addr, char* buf) {
	int shm_id = shmget(shm_key, shm_size, shm_flg);
	if(-1 == shm_id)
		return;
	shm_addr = (char*)shmat(shm_id, shm_addr, 0);
	if((char*)-1 == shm_addr)
		return;
	sprintf(buf, id_fmt_, shm_addr, shm_id, shm_key);
}

#define shm_mode_    (SHM_R | SHM_W)

dlle___ void new_shm__(char* buf, const char*fname, int proj_id, size_t shm_size) {
	key_t shm_key = ftok(fname, proj_id);
	if(-1 == shm_key)
		return;
	get__(shm_key, shm_size, IPC_CREAT|shm_mode_, NULL, buf);
}

dlle___ void attach_shm__(char* buf, char*id) {
	char *shm_addr;
	int shm_id;
	key_t shm_key;
	if(!shm_id__(id, shm_addr, shm_id, shm_key))
		return;
	get__(shm_key, 0, shm_mode_, shm_addr, buf);
}

dlle___ char* get_shm__(char*id) {
	char *shm_addr;
	int shm_id;
	key_t shm_key;
	if(!shm_id__(id, shm_addr, shm_id, shm_key))
		return NULL;
	return shm_addr;
}

dlle___ bool set_shm__(char*id, char* s) {
	char *shm_addr;
	int shm_id;
	key_t shm_key;
	if(!shm_id__(id, shm_addr, shm_id, shm_key))
		return false;
	strcpy(shm_addr, s);
	return true;
}
