/*
 * dir_count.cpp
 *
 *  Created on: 2016年6月29日
 *      Author: zzzzzzzzzzz
 */

#include "doscmd.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define count_count_ 9
static unsigned long count_[count_count_];
static int depth_;

static void dir__(const char* dir, int depth) {
	if(depth_ >= 0 && depth_ <= depth)
		return;

    DIR *d;
    struct dirent *entry;
    struct stat statbuf;

    if((d = opendir(dir)) == NULL) {
    	count_[8]++;
        return;
    }

    char oldir[260];
	getcwd(oldir,sizeof(oldir));
    chdir(dir);
    while ((entry = readdir(d)) != NULL) {
    	const char* name=entry->d_name;
        lstat(name, &statbuf);
        mode_t mode = statbuf.st_mode;

        if(S_ISDIR(mode)) {
            if(name[0] == '.' && (!name[1] || (name[1] == '.' && !name[2])))
                continue;
            count_[1]++;
            dir__(name, depth + 1);
        } else {
            if(lstat(name, &statbuf) < 0) {
            	count_[8]++;
                continue;
            }
            mode = statbuf.st_mode;
            if(S_ISREG(mode))
                count_[0]++;
            else if(S_ISCHR(mode))
                count_[2]++;
            else if(S_ISBLK(mode))
                count_[3]++;
            else if(S_ISFIFO(mode))
                count_[4]++;
            else if(S_ISLNK(mode))
                count_[5]++;
            else if(S_ISSOCK(mode))
                count_[6]++;
            else
                count_[7]++;
        }
    }
    chdir(oldir);
    closedir(d);
}

dlle___ void dlln___(dir_count2__)(char* buf, const char* dir, int depth) {
	for(int i = 0; i < count_count_; i++)
		count_[i] = 0;
	depth_ = depth;
	dir__(dir, 0);
	sprintf(buf,
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s%s"
			"%s%lu%s"
			,
			kaiyinhao__(), count_[0], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[1], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[2], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[3], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[4], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[5], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[6], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[7], biyinhao__(), dunhao__(),
			kaiyinhao__(), count_[8], biyinhao__()
	);
}


