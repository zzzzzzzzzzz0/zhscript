#ifndef inc_h_
#define inc_h_

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#ifdef WIN32
#define socklen_t int
#define close(s) closesocket(s);
#include <winsock2.h>
#include <windows.h>
#else
#include <resolv.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define SOCKET int
#endif
#include<string>
using namespace std;

#include<string.h>
#define bzero(dest,size) memset(dest,0,size)

int err___(char* s);
int err___(const char* s,const char* s1,int i);

#define end__ "q"
#define err__ "x"

#endif
