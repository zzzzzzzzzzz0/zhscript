/*
 * fileinfo.cpp
 *
 *  Created on: 2011-7-2
 *      Author: zzzzzzzzzzz
 */

#include "def1.h"
#include <sys/stat.h>
#include <stdio.h>
#ifndef __mode_t
#define __mode_t mode_t
#endif

#include "call_util.h"
#include<string>
using namespace std;

char*ltoa(long l,char*buf,char fmt1='d'){
	char fmt[]={'%',fmt1, 0, 0};
	if(fmt1 == 'l')
		fmt[2] = 'd';
	sprintf(buf,fmt,l);
	return buf;
}

static void mode__(string& s, bool b, char c) {
	s += (b ? c : '-');
}

dlle___ void dlln___(fileinfo__)(char*buf,int siz,char*filename,char*fmt){
	struct stat64 stt;
	if(stat64(filename,&stt)==-1)
		return;
	if(!fmt)
		return;
	string s;
	char s1[16];
	for(int i=0;fmt[i];){
		char c=fmt[i];
		if(c=='%'){
			switch(c=fmt[++i]){
			case 0:
				continue;
			case's':
				s+=ltoa(stt.st_size,s1, 'l');
				break;
			case'm':
				s+=ltoa(stt.st_mode,s1,'x');
				break;
			case'o':
				s+=ltoa(stt.st_mode & 0777,s1,'o');
				break;
			case 'M':
			{
				__mode_t m = stt.st_mode;
                if (S_ISREG(m))
                        ;
                else if (S_ISDIR(m))
                        s += 'd';
                else if (S_ISCHR(m))
                        s += 'c';
                else if (S_ISBLK(m))
                        s += 'b';
                else if (S_ISFIFO(m))
                        s += 'p';
                else if (S_ISLNK(m))
                        s += 'l';
                else if (S_ISSOCK(m))
                        s += 's';
#ifdef S_ISWHT
                else if (S_ISWHT(m))
                        s += 'w';
#endif
                mode__(s, S_IRUSR & m, 'r');
                mode__(s, S_IWUSR & m, 'w');
                mode__(s, S_IXUSR & m, 'x');
                mode__(s, S_IRGRP & m, 'r');
                mode__(s, S_IWGRP & m, 'w');
                mode__(s, S_IXGRP & m, 'x');
                mode__(s, S_IROTH & m, 'r');
                mode__(s, S_IWOTH & m, 'w');
                mode__(s, S_IXOTH & m, 'x');
				break;
			}
			case't':
				switch(c=fmt[++i]){
				case 0:
					continue;
				case'a':
					s+=ltoa(stt.st_atime,s1);
					break;
				case'm':
					s+=ltoa(stt.st_mtime,s1);
					break;
				case'c':
					s+=ltoa(stt.st_ctime,s1);
					break;
				}
				break;
			case'i':
				s+=ltoa(stt.st_ino,s1, 'l');
				break;
			case'B':
				s+=ltoa(stt.st_blksize,s1);
				break;
			case'b':
				s+=ltoa(stt.st_blocks,s1, 'l');
				break;
			case'r':
				s+=ltoa(stt.st_rdev,s1);
				break;
			case'u':
				s+=ltoa(stt.st_uid,s1);
				break;
			case'g':
				s+=ltoa(stt.st_gid,s1);
				break;
			case'n':
				s+=ltoa(stt.st_nlink,s1);
				break;
			case'd':
				s+=ltoa(stt.st_dev,s1);
				break;
			}
			i++;
			continue;
		}
		s+=c;
		i++;
	}
	cpy__(buf,s.c_str(),siz);
}
