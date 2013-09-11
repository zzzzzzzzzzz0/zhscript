/*
 * =====================================================================================
 *
 *       Filename:  define.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年02月16日 16时08分04秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  lerosua@gmail.com
 *        Company:  cyclone
 *
 * =====================================================================================
 */

#ifndef __DEFINE_HH_



#define DLOG(fmt, ...) \
    /*{ \
        char buffer[36] = {0}; \
        time_t t = time(NULL); \
        strftime(buffer, 36, "%F %T ", localtime(&t)); \
        fprintf(stderr, "%s %s|%d| " fmt, \
                buffer, __FILE__, __LINE__, ##__VA_ARGS__); \
    }*/



#endif

