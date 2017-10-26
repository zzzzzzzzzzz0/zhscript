/*
 * shm.cpp
 *
 *  Created on: 2013-2-12
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "for_arg_.h"

#define id_fmt_ "%p,%d,%d,%lu"

class id___ {
public:
	char *shm_addr;
	int shm_id;
	key_t shm_key;
	size_t shm_size;
	bool from__(char*id) {
		return sscanf(id, id_fmt_, &shm_addr, &shm_id, &shm_key, &shm_size) == 4;
	}
};

dlle___ void delete_shm__(int argc,...) {
	id___ id;
	_for_args( argc )
		if(!id.from__(s))
			continue;
		shmdt(id.shm_addr);
		shmctl(id.shm_id,IPC_RMID,0);
	_next_args
}

static void get__(key_t shm_key, size_t shm_size, int shm_flg, char *shm_addr, char* buf) {
	int shm_id = shmget(shm_key, shm_size, shm_flg);
	if(-1 == shm_id)
		return;
	shm_addr = (char*)shmat(shm_id, shm_addr, 0);
	if((char*)-1 == shm_addr)
		return;
	sprintf(buf, id_fmt_, shm_addr, shm_id, shm_key, shm_size);
}

#define shm_mode_    (SHM_R | SHM_W)

dlle___ void new_shm__(char* buf, const char*fname, int proj_id, size_t shm_size) {
	key_t shm_key = ftok(fname, proj_id);
	if(-1 == shm_key)
		return;
	get__(shm_key, shm_size, IPC_CREAT|shm_mode_, NULL, buf);
}

dlle___ void attach_shm__(char* buf, char*id) {
	id___ id2;
	if(!id2.from__(id))
		return;
	get__(id2.shm_key, 0, shm_mode_, id2.shm_addr, buf);
}

dlle___ char* get_shm__(char*id) {
	id___ id2;
	if(!id2.from__(id))
		return NULL;
	return id2.shm_addr;
}

dlle___ bool set_shm__(char*id, char* s2, int argc,...) {
	id___ id2;
	if(!id2.from__(id))
		return false;
	if(!s2)
		return false;
	string s3;
	_for_args( argc )
		s3 += kw_dunhao_;
		s3 += kw_yybegin_;
		s3 += s;
		s3 += kw_yyend_;
	_next_args
	if(s3.empty())
		s3 += s2;
	else {
		string s4;
		s4 += kw_eval_;
		s4 += kw_begin_;
		s4 += s2;
		s4 += kw_end_;
		s4 += s3;
		s3 = s4;
	}
	size_t i2 = 0;
	for(; i2 < id2.shm_size - 1 && i2 < s3.size(); i2++)
		id2.shm_addr[i2] = s3[i2];
	id2.shm_addr[i2] = 0;
	return true;
}
