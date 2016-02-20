/*
 * util.h
 *
 *  Created on: 2013-2-11
 *      Author: zzzzzzzzzzz
 */

#ifndef EXTERN2_H_
#define EXTERN2_H_

extern char* l2s__(long num,char* buf);
extern char* l2x__(long num,char* buf);
extern int s2i__(const char* s1,int i=0);
extern int s2i__(const string& s,int i=0);
extern float s2f__(const char* s,float d=0.0);
extern float s2f__(const string& s,float d=0.0);
extern long x2l__(const char* s, long i=0);
extern bool bool__(const string& s);

#endif /* EXTERN2_H_ */
